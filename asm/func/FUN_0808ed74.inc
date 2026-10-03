	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_0808b82c
	ldr r1, [r4, #0x2c]
	movs r0, #0
	movs r2, #5
	bl Video_SetBGLayer
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _0808EDD4 @ =0x000034EC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0808EDD8 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	str r5, [sp]
	movs r2, #6
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #3
	bl TextBox_ShowLine
	ldr r0, _0808EDDC @ =0x000002C1
	bl PlaySound_082406e0
	ldr r1, _0808EDE0 @ =FUN_0808f01c
	adds r0, r4, #0
	bl FUN_0808a33c
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808EDD4: .4byte 0x000034EC
_0808EDD8: .4byte 0x000034E4
_0808EDDC: .4byte 0x000002C1
_0808EDE0: .4byte FUN_0808f01c
