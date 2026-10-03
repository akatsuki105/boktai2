	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	adds r6, r0, #0
	adds r5, r1, #0
	mov r8, r2
	mov sb, r3
	lsls r4, r5, #1
	adds r4, r4, r5
	lsls r4, r4, #5
	ldr r0, _08096D30 @ =0x000020A4
	adds r4, r4, r0
	adds r4, r6, r4
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	adds r1, r6, #0
	adds r1, #0xa0
	ldr r2, _08096D34 @ =0x00003FE0
	adds r0, r6, r2
	add r0, r8
	movs r2, #0
	ldrsb r2, [r0, r2]
	adds r2, #0x43
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	movs r3, #1
	bl MainSprite_SetPose
	adds r0, r4, #0
	adds r0, #0x20
	mov r1, r8
	bl FUN_08096af0
	lsls r5, r5, #3
	ldr r0, _08096D38 @ =0x00003B68
	adds r5, r5, r0
	adds r5, r6, r5
	adds r0, r5, #0
	mov r1, sb
	bl FUN_08096af0
	movs r1, #0x11
	add r8, r1
	mov r2, r8
	lsls r0, r2, #1
	add r0, r8
	lsls r0, r0, #5
	adds r6, r6, r0
	ldr r0, _08096D3C @ =0x00000F9E
	adds r6, r6, r0
	ldrh r1, [r6]
	adds r0, r4, #0
	bl FUN_0808ba0c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08096D30: .4byte 0x000020A4
_08096D34: .4byte 0x00003FE0
_08096D38: .4byte 0x00003B68
_08096D3C: .4byte 0x00000F9E
