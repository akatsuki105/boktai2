	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _0801C39C @ =0x00000B04
	adds r2, r4, r0
	adds r3, r4, #0
	adds r3, #0x3d
	ldrb r0, [r3]
	movs r1, #3
	ands r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	movs r6, #0
	strh r0, [r2, #0x20]
	ldrb r1, [r3]
	lsrs r1, r1, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r2, #0x22]
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	mov r8, r1
	ands r0, r1
	str r0, [r2, #8]
	adds r5, r4, #0
	adds r5, #0xf8
	str r6, [sp]
	adds r0, r2, #0
	adds r1, r5, #0
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetAnim
	ldr r0, _0801C3A0 @ =0x00000B64
	adds r2, r4, r0
	movs r0, #0x10
	strh r0, [r2, #0x20]
	movs r0, #0x28
	strh r0, [r2, #0x22]
	ldr r0, [r2, #8]
	mov r1, r8
	ands r0, r1
	str r0, [r2, #8]
	adds r0, r2, #0
	adds r1, r5, #0
	movs r2, #0x3c
	movs r3, #0
	bl MainSprite_SetPose
	ldr r0, _0801C3A4 @ =0x00000BC4
	adds r2, r4, r0
	strh r6, [r2, #0x20]
	strh r6, [r2, #0x22]
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	str r6, [sp]
	adds r0, r2, #0
	adds r1, r5, #0
	movs r2, #4
	movs r3, #1
	bl MainSprite_SetAnim
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801C39C: .4byte 0x00000B04
_0801C3A0: .4byte 0x00000B64
_0801C3A4: .4byte 0x00000BC4
