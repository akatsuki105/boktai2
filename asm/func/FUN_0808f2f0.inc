	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	bl TextBox_Close
	bl FUN_08049e5c
	bl FUN_08049f84
	movs r0, #1
	movs r1, #1
	movs r2, #0x1c
	movs r3, #4
	bl TextBox_SetRect
	ldr r0, [r5, #0x54]
	bl TextBox_Start
	movs r0, #1
	bl TextBox_SetInstant
	ldr r1, [r5, #0x18]
	ldr r0, [r5, #0x30]
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0
	movs r3, #2
	bl FUN_0808a3c4
	adds r0, r5, #0
	bl FUN_0808b82c
	ldr r0, _0808F3D0 @ =0x000034EC
	adds r1, r5, r0
	ldr r0, [r1]
	movs r4, #2
	rsbs r4, r4, #0
	ands r0, r4
	str r0, [r1]
	ldr r0, _0808F3D4 @ =0x00003504
	adds r1, r5, r0
	movs r7, #0
	ldr r0, _0808F3D8 @ =0x0000FFE4
	strh r0, [r1]
	ldr r0, _0808F3DC @ =0x00003506
	adds r1, r5, r0
	movs r0, #0x20
	strh r0, [r1]
	ldr r1, _0808F3E0 @ =0x000034E4
	adds r0, r5, r1
	adds r6, r5, #0
	adds r6, #0xc0
	str r7, [sp]
	adds r1, r6, #0
	movs r2, #7
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, _0808F3E4 @ =0x0000354C
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _0808F38C
	ldr r0, _0808F3E8 @ =0x000035AC
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
_0808F38C:
	ldr r0, _0808F3EC @ =0x0000360C
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	ldr r1, _0808F3F0 @ =0x00003604
	adds r4, r5, r1
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0x1d
	movs r3, #1
	bl MainSprite_SetPose
	str r7, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0xa
	movs r3, #1
	bl MainSprite_SetAnim
	adds r0, r5, #0
	bl FUN_0808f1bc
	movs r0, #7
	bl TextBox_ShowLine
	ldr r1, _0808F3F4 @ =FUN_0808f604
	adds r0, r5, #0
	bl FUN_0808a33c
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808F3D0: .4byte 0x000034EC
_0808F3D4: .4byte 0x00003504
_0808F3D8: .4byte 0x0000FFE4
_0808F3DC: .4byte 0x00003506
_0808F3E0: .4byte 0x000034E4
_0808F3E4: .4byte 0x0000354C
_0808F3E8: .4byte 0x000035AC
_0808F3EC: .4byte 0x0000360C
_0808F3F0: .4byte 0x00003604
_0808F3F4: .4byte FUN_0808f604
