	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	adds r4, r0, #0
	bl TextBox_Close
	bl FUN_08049e5c
	bl FUN_08049f84
	movs r0, #1
	movs r1, #1
	movs r2, #0x1c
	movs r3, #6
	bl TextBox_SetRect
	ldr r0, [r4, #0x54]
	bl TextBox_Start
	movs r0, #1
	bl TextBox_SetInstant
	ldr r1, [r4, #0x18]
	ldr r0, [r4, #0x30]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #2
	bl FUN_0808a3c4
	adds r0, r4, #0
	bl FUN_0808b82c
	ldr r0, _0808F2D4 @ =0x000034EC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _0808F2D8 @ =0x00003504
	adds r1, r4, r0
	movs r0, #0
	mov r8, r0
	ldr r0, _0808F2DC @ =0x0000FFA8
	strh r0, [r1]
	ldr r0, _0808F2E0 @ =0x00003506
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
	ldr r1, _0808F2E4 @ =0x000034E4
	adds r0, r4, r1
	adds r5, r4, #0
	adds r5, #0xc0
	mov r1, r8
	str r1, [sp]
	adds r1, r5, #0
	movs r2, #4
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, _0808F2E8 @ =0x00003604
	adds r6, r4, r0
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0x1d
	movs r3, #1
	bl MainSprite_SetPose
	mov r1, r8
	str r1, [sp]
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0xa
	movs r3, #1
	bl MainSprite_SetAnim
	movs r0, #0
	bl TextBox_ShowLine
	ldr r1, _0808F2EC @ =FUN_0808f520
	adds r0, r4, #0
	bl FUN_0808a33c
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808F2D4: .4byte 0x000034EC
_0808F2D8: .4byte 0x00003504
_0808F2DC: .4byte 0x0000FFA8
_0808F2E0: .4byte 0x00003506
_0808F2E4: .4byte 0x000034E4
_0808F2E8: .4byte 0x00003604
_0808F2EC: .4byte FUN_0808f520
