	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _081CB294 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081CB298
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081CB29A
	.align 2, 0
_081CB294: .4byte 0x0000046C
_081CB298:
	movs r0, #0
_081CB29A:
	cmp r0, #0
	beq _081CB330
	movs r3, #0xd5
	lsls r3, r3, #3
	adds r2, r7, r3
	movs r1, #9
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r6, r4
	ldrh r1, [r2]
	movs r5, #0
	movs r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r3, _081CB35C @ =DogLink_StateFireBreathWindup
	movs r2, #0x24
	ldr r0, _081CB360 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081CB364 @ =0x0000046B
	adds r0, r6, r1
	strb r5, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r4, [r0]
	movs r4, #0xe6
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	movs r2, #2
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r1, r1, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r1, r6, r2
	ldrh r1, [r1]
	adds r3, #0x68
	adds r2, r6, r3
	ldrh r2, [r2]
	adds r4, #0x78
	adds r3, r6, r4
	ldr r3, [r3]
	str r3, [sp]
	subs r4, #0xc
	adds r3, r6, r4
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl Hitbox_SetAttack
	ldr r1, _081CB368 @ =0x000006D7
	adds r0, r7, r1
	strb r5, [r0]
_081CB330:
	ldr r2, _081CB364 @ =0x0000046B
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _081CB378
	ldr r3, _081CB36C @ =0x000006CE
	adds r0, r7, r3
	ldrh r1, [r0]
	ldr r4, _081CB370 @ =0x000006CA
	adds r0, r7, r4
	strh r1, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r0, _081CB374 @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r0, r6, #0
	bl FUN_081c7228
	b _081CB382
	.align 2, 0
_081CB35C: .4byte DogLink_StateFireBreathWindup
_081CB360: .4byte 0x0000046D
_081CB364: .4byte 0x0000046B
_081CB368: .4byte 0x000006D7
_081CB36C: .4byte 0x000006CE
_081CB370: .4byte 0x000006CA
_081CB374: .4byte 0xFFFFFEFF
_081CB378:
	ldr r2, _081CB38C @ =0x00000484
	adds r1, r6, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081CB382:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081CB38C: .4byte 0x00000484
