	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_0808b82c
	ldr r1, [r4, #0x2c]
	ldr r0, [r4, #0x3c]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #5
	bl FUN_0808a3c4
	ldr r0, _0808EE44 @ =0x000034EC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0808EE48 @ =0x00003504
	adds r0, r4, r1
	movs r2, #0
	strh r2, [r0]
	adds r1, #2
	adds r0, r4, r1
	strh r2, [r0]
	subs r1, #0x22
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	str r2, [sp]
	movs r2, #6
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #0xd
	bl TextBox_ShowLine
	ldr r1, _0808EE4C @ =FUN_0808f0d8
	adds r0, r4, #0
	bl FUN_0808a33c
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808EE44: .4byte 0x000034EC
_0808EE48: .4byte 0x00003504
_0808EE4C: .4byte FUN_0808f0d8
