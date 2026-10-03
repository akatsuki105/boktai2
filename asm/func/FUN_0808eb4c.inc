	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_0808b82c
	ldr r1, [r4, #0x2c]
	movs r0, #0
	movs r2, #3
	bl Video_SetBGLayer
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _0808EBD0 @ =0x000034EC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0808EBD4 @ =0x00003504
	adds r0, r4, r1
	strh r5, [r0]
	ldr r2, _0808EBD8 @ =0x00003506
	adds r0, r4, r2
	strh r5, [r0]
	subs r1, #0x20
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	str r5, [sp]
	movs r2, #7
	movs r3, #2
	bl MainSprite_SetAnim
	adds r0, r4, #0
	bl FUN_0808e53c
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0808b6fc
	ldr r2, _0808EBDC @ =0x00001524
	adds r0, r4, r2
	ldr r1, _0808EBE0 @ =0x0000FFF8
	strh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	movs r0, #1
	bl TextBox_ShowLine
	ldr r1, _0808EBE4 @ =FUN_0808eeac
	adds r0, r4, #0
	bl FUN_0808a33c
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808EBD0: .4byte 0x000034EC
_0808EBD4: .4byte 0x00003504
_0808EBD8: .4byte 0x00003506
_0808EBDC: .4byte 0x00001524
_0808EBE0: .4byte 0x0000FFF8
_0808EBE4: .4byte FUN_0808eeac
