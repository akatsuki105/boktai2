	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r5, r1, #0
	mov r8, r3
	ldr r7, [sp, #0x18]
	lsls r4, r5, #1
	adds r4, r4, r5
	lsls r4, r4, #5
	ldr r0, _08097FAC @ =0x000020A4
	adds r4, r4, r0
	adds r4, r6, r4
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	adds r1, r6, #0
	adds r1, #0xa0
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	movs r3, #1
	bl MainSprite_SetPose
	adds r0, r4, #0
	adds r0, #0x20
	mov r1, r8
	bl FUN_08097ca0
	lsls r5, r5, #3
	ldr r0, _08097FB0 @ =0x00003B68
	adds r5, r5, r0
	adds r6, r6, r5
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_08097ca0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0808ba0c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08097FAC: .4byte 0x000020A4
_08097FB0: .4byte 0x00003B68
