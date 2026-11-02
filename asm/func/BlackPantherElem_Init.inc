	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #0x1c
	mov sl, r0
	adds r4, r1, #0
	adds r1, r3, #0
	str r2, [r4]
	ldr r0, _0805491C @ =0x085AB748
	lsls r5, r2, #3
	subs r5, r5, r2
	lsls r5, r5, #3
	adds r5, r5, r0
	ldr r0, [r5]
	str r0, [r4, #4]
	movs r0, #0
	movs r2, #1
	mov r8, r2
	mov r2, r8
	strb r2, [r4, #8]
	strb r0, [r4, #0xa]
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	str r0, [r4, #0x1c]
	ldr r0, _08054920 @ =0x085AB740
	ldr r6, _08054924 @ =0xFFFF0000
	ldrh r0, [r0, #2]
	movs r2, #0x80
	lsls r2, r2, #0x11
	orrs r0, r2
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r6
	ldr r2, _08054928 @ =0x00001770
	orrs r0, r2
	str r0, [sp, #0x10]
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #0x10]
	str r2, [r4, #0x74]
	str r3, [r4, #0x78]
	movs r0, #0x30
	adds r0, r0, r4
	mov sb, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrb r3, [r4, #0xf]
	movs r0, #7
	str r0, [sp]
	str r4, [sp, #4]
	mov r0, sb
	add r2, sp, #0xc
	bl Mover_Init
	ldr r0, [sp, #0x14]
	ands r0, r6
	str r0, [sp, #0x14]
	ldr r1, _0805492C @ =0x085AB912
	ldr r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r6
	str r0, [r1, #4]
	mov r0, sb
	bl FUN_0823b47c
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r4, r1
	str r5, [r0]
	ldr r0, [r4, #4]
	ldr r1, [r5, #4]
	bl ActorManager_FindSpriteData
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r4, r2
	str r0, [r1]
	ldr r2, [r5, #8]
	ldr r3, [r4, #4]
	ldr r0, [r5, #0xc]
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	add r1, sp, #0xc
	str r1, [sp, #8]
	mov r0, sl
	adds r1, r4, #0
	bl BlackPantherElem_InitSprite
	movs r0, #0x40
	str r0, [r4, #0x14]
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805491C: .4byte 0x085AB748
_08054920: .4byte 0x085AB740
_08054924: .4byte 0xFFFF0000
_08054928: .4byte 0x00001770
_0805492C: .4byte 0x085AB912
