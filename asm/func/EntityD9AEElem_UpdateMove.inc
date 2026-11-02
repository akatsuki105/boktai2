	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r2, r5, #0
	adds r2, #0x2c
	adds r6, r5, #0
	adds r6, #0xbc
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	beq _08003FA2
	movs r0, #0
	strb r0, [r5, #0x11]
	ldrh r1, [r6, #2]
	movs r0, #1
	orrs r0, r1
	strh r0, [r6, #2]
_08003FA2:
	ldrh r0, [r5, #0xc]
	strh r0, [r2, #0x10]
	ldrh r0, [r5, #0xe]
	strh r0, [r2, #0x14]
	ldrb r1, [r6]
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	strh r1, [r2, #0xa]
	ldrh r0, [r5, #4]
	cmp r0, #2
	bne _08003FC0
	ldr r3, _08004048 @ =0xFFFFFF00
	adds r0, r1, r3
	strh r0, [r2, #0xa]
_08003FC0:
	ldrh r0, [r2, #0xa]
	adds r1, r5, #0
	adds r1, #0xaa
	strh r0, [r1]
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r4, r5, r0
	subs r1, #0x76
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	ldrb r0, [r5]
	cmp r0, #1
	beq _08003FF4
	ldrh r1, [r5, #2]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _08003FF4
	adds r0, r5, #0
	bl EntityD9AEElem_SpawnMoveDust
_08003FF4:
	ldrh r0, [r5, #2]
	adds r0, #1
	movs r1, #0
	mov r8, r1
	movs r7, #0
	strh r0, [r5, #2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r2, [r5, #0x14]
	cmp r0, r2
	blo _080040DE
	ldrb r2, [r6]
	movs r1, #0xf
	ands r1, r2
	cmp r1, #0xe
	bgt _08004016
	adds r1, #1
_08004016:
	movs r0, #0xf0
	ands r0, r2
	orrs r0, r1
	strb r0, [r6]
	movs r0, #0xff
	strb r0, [r6, #1]
	ldrb r4, [r5]
	cmp r4, #1
	bne _08004094
	ldrh r2, [r5, #4]
	cmp r2, #2
	bne _08004050
	ldr r1, _0800404C @ =EntityD9AEElem_UpdateFall
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r0, r5, r3
	str r1, [r0]
	strh r7, [r5, #2]
	strb r4, [r5, #0x11]
	strh r2, [r5, #4]
	strh r7, [r5, #0xc]
	strh r7, [r5, #0xe]
	mov r0, r8
	strb r0, [r5, #0x10]
	b _080040DE
	.align 2, 0
_08004048: .4byte 0xFFFFFF00
_0800404C: .4byte EntityD9AEElem_UpdateFall
_08004050:
	adds r0, r5, #0
	adds r0, #0xba
	ldrh r1, [r0]
	ldrb r2, [r5, #0x10]
	adds r0, r5, #0
	bl EntityD9AEElem_TryMove
	cmp r0, #0
	bne _080040DE
	adds r0, r5, #0
	bl EntityD9AEElem_OnHitWall
	ldr r1, _0800408C @ =EntityD9AEElem_UpdateIdle
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r0, r5, r2
	str r1, [r0]
	strh r7, [r5, #2]
	strb r4, [r5, #0x11]
	strh r7, [r5, #4]
	strh r7, [r5, #0xc]
	strh r7, [r5, #0xe]
	mov r3, r8
	strb r3, [r5, #0x10]
	ldrh r1, [r6, #2]
	ldr r0, _08004090 @ =0x0000FFFE
	ands r0, r1
	strh r0, [r6, #2]
	b _080040DE
	.align 2, 0
_0800408C: .4byte EntityD9AEElem_UpdateIdle
_08004090: .4byte 0x0000FFFE
_08004094:
	ldrh r2, [r5, #4]
	cmp r2, #2
	bne _080040B4
	ldr r0, _080040B0 @ =EntityD9AEElem_UpdateFall
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r1, r5, r3
	str r0, [r1]
	strh r7, [r5, #2]
	movs r0, #1
	strb r0, [r5, #0x11]
	strh r2, [r5, #4]
	b _080040D4
	.align 2, 0
_080040B0: .4byte EntityD9AEElem_UpdateFall
_080040B4:
	adds r0, r5, #0
	bl EntityD9AEElem_OnHitWall
	ldr r1, _080040E8 @ =EntityD9AEElem_UpdateIdle
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r0, r5, r2
	str r1, [r0]
	strh r7, [r5, #2]
	movs r0, #1
	strb r0, [r5, #0x11]
	strh r7, [r5, #4]
	ldrh r1, [r6, #2]
	ldr r0, _080040EC @ =0x0000FFFE
	ands r0, r1
	strh r0, [r6, #2]
_080040D4:
	movs r1, #0
	movs r0, #0
	strh r0, [r5, #0xc]
	strh r0, [r5, #0xe]
	strb r1, [r5, #0x10]
_080040DE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080040E8: .4byte EntityD9AEElem_UpdateIdle
_080040EC: .4byte 0x0000FFFE
