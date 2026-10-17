	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _080D33C0 @ =0x00000A68
	adds r2, r4, r0
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080D33C4 @ =0x00000A6A
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #0xe6
	movs r3, #0
	mov r8, r3
	strh r0, [r1]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	adds r2, #0x22
	adds r6, r4, r2
	strb r0, [r6]
	adds r0, r4, #0
	bl FUN_080d1b04
	adds r5, r0, #0
	ldr r3, _080D33C8 @ =0x000009F4
	adds r0, r4, r3
	movs r1, #0x2d
	bl Video_SetAuxSpritePltt
	movs r1, #0xa1
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r2, _080D33CC @ =0x00000A7C
	adds r1, r4, r2
	ldrh r2, [r1]
	mov r3, r8
	str r3, [sp]
	ldr r3, _080D33D0 @ =0x00000A7E
	adds r1, r4, r3
	ldrh r1, [r1]
	str r1, [sp, #4]
	adds r1, r5, #0
	movs r3, #8
	bl Hitbox_SetAttack
	ldrb r1, [r6]
	ldr r2, _080D33D4 @ =0x00000A52
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080D33D8 @ =0x00000A8A
	adds r4, r4, r3
	mov r0, r8
	strh r0, [r4]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D33C0: .4byte 0x00000A68
_080D33C4: .4byte 0x00000A6A
_080D33C8: .4byte 0x000009F4
_080D33CC: .4byte 0x00000A7C
_080D33D0: .4byte 0x00000A7E
_080D33D4: .4byte 0x00000A52
_080D33D8: .4byte 0x00000A8A
