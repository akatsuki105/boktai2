	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r4, r0, #0
	movs r1, #8
	bl FUN_08060c40
	ldr r1, _08078084 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bls _08078078
	b _08078424
_08078078:
	lsls r0, r0, #2
	ldr r1, _08078088 @ =_0807808C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08078084: .4byte 0x0000037D
_08078088: .4byte _0807808C
_0807808C: @ jump table
	.4byte _080780A4 @ case 0
	.4byte _080780DC @ case 1
	.4byte _08078190 @ case 2
	.4byte _080782F4 @ case 3
	.4byte _08078374 @ case 4
	.4byte _080783AC @ case 5
_080780A4:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080780D0
	b _08078424
_080780D0:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #1
	bl FUN_08060b84
	b _08078424
_080780DC:
	ldr r0, _08078170 @ =0x0000037E
	adds r5, r4, r0
	ldrh r2, [r5]
	cmp r2, #0
	bne _0807810A
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r4, r3
	movs r0, #4
	strb r0, [r1]
	ldr r0, _08078174 @ =0x000002E6
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08078178 @ =0x000002E7
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_08067f88
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_0807810A:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r5, #0
	movs r0, #0xf
	strh r0, [r1]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	movs r1, #8
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	bne _08078134
	b _08078424
_08078134:
	movs r0, #0xcb
	bl PlaySound_082406e0
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0807814E
	b _08078330
_0807814E:
	movs r1, #0x10
	ldr r0, [r4, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08078184
	movs r0, #0xb9
	lsls r0, r0, #2
	bl PlaySound_082406e0
	ldr r2, _0807817C @ =0x00000409
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	ldr r3, _08078180 @ =0x00000404
	adds r0, r4, r3
	b _08078358
	.align 2, 0
_08078170: .4byte 0x0000037E
_08078174: .4byte 0x000002E6
_08078178: .4byte 0x000002E7
_0807817C: .4byte 0x00000409
_08078180: .4byte 0x00000404
_08078184:
	ldr r1, _0807818C @ =0x00000404
	adds r0, r4, r1
	strh r5, [r0]
	b _08078282
	.align 2, 0
_0807818C: .4byte 0x00000404
_08078190:
	movs r1, #0xa0
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	ldr r2, _08078200 @ =0x00000404
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #4
	bhi _080781B4
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bne _080781B4
	ldr r0, _08078204 @ =0x00000239
	bl PlaySound_082406e0
_080781B4:
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	movs r1, #9
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0x1e
	strh r0, [r1]
	movs r2, #0x93
	lsls r2, r2, #4
	adds r1, r4, r2
	adds r0, r4, #0
	bl FUN_080620f0
	ldr r3, _08078208 @ =0x0000095E
	adds r1, r4, r3
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r1, _0807820C @ =0x0000037E
	adds r0, r4, r1
	ldrh r1, [r0]
	cmp r1, #0x1f
	bhi _08078210
	movs r2, #0x96
	lsls r2, r2, #4
	adds r0, r4, r2
	strh r1, [r0]
	b _0807821C
	.align 2, 0
_08078200: .4byte 0x00000404
_08078204: .4byte 0x00000239
_08078208: .4byte 0x0000095E
_0807820C: .4byte 0x0000037E
_08078210:
	movs r0, #0x40
	subs r0, r0, r1
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r4, r3
	strh r0, [r1]
_0807821C:
	ldr r0, _0807825C @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	movs r7, #0
	strh r0, [r1]
	ldr r3, _08078260 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x40
	bls _08078238
	movs r0, #0
	strh r0, [r1]
_08078238:
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _0807826C
	ldr r0, _08078264 @ =0x00000239
	bl sound_08240740
	ldr r2, _08078268 @ =0x00000409
	adds r0, r4, r2
	strb r7, [r0]
	b _08078330
	.align 2, 0
_0807825C: .4byte 0x0000037E
_08078260: .4byte 0x0000FFFF
_08078264: .4byte 0x00000239
_08078268: .4byte 0x00000409
_0807826C:
	movs r0, #0x10
	ldr r5, [r4, #0x20]
	ands r5, r0
	cmp r5, #0
	beq _08078298
	ldr r0, _08078290 @ =0x00000239
	bl sound_08240740
	ldr r3, _08078294 @ =0x00000409
	adds r0, r4, r3
	strb r7, [r0]
_08078282:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #3
	bl FUN_08060b84
	b _08078424
	.align 2, 0
_08078290: .4byte 0x00000239
_08078294: .4byte 0x00000409
_08078298:
	ldr r1, _080782E8 @ =0x00000436
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r1, #4
	strh r1, [r0]
	movs r3, #0x87
	lsls r3, r3, #3
	adds r0, r4, r3
	ands r1, r2
	ldrh r0, [r0]
	cmp r1, r0
	bhs _080782B2
	b _08078424
_080782B2:
	bl FUN_0809c58c
	ldr r0, _080782EC @ =0x0000037D
	adds r1, r4, r0
	movs r0, #5
	strb r0, [r1]
	movs r1, #0x96
	lsls r1, r1, #3
	adds r2, r4, r1
	ldr r3, [r2]
	cmp r3, #0
	bne _080782CC
	b _08078424
_080782CC:
	ldr r0, _080782F0 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r0
	orrs r1, r6
	str r1, [sp, #4]
	add r1, sp, #4
	mov r0, sp
	str r0, [r1, #4]
	str r6, [sp]
	str r5, [r2]
	adds r0, r3, #0
	bl FUN_082318ac
	b _08078424
	.align 2, 0
_080782E8: .4byte 0x00000436
_080782EC: .4byte 0x0000037D
_080782F0: .4byte 0xFFFF0000
_080782F4:
	movs r1, #0x80
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0xa
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0x1e
	strh r0, [r1]
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0807833C
_08078330:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #4
	bl FUN_08060b84
	b _08078424
_0807833C:
	movs r0, #0x10
	ldr r5, [r4, #0x20]
	ands r5, r0
	cmp r5, #0
	bne _08078424
	ldr r0, _08078368 @ =0x00000239
	bl PlaySound_082406e0
	ldr r0, _0807836C @ =0x00000409
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08078370 @ =0x00000404
	adds r0, r4, r1
_08078358:
	strh r5, [r0]
	adds r0, r4, #0
	movs r1, #7
	movs r2, #2
	bl FUN_08060b84
	b _08078424
	.align 2, 0
_08078368: .4byte 0x00000239
_0807836C: .4byte 0x00000409
_08078370: .4byte 0x00000404
_08078374:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0xf
	strh r0, [r1]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	movs r1, #0xb
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08078424
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	movs r1, #7
	movs r2, #0
	bl FUN_08060b84
	b _08078424
_080783AC:
	ldr r1, _080783CC @ =0x0000095E
	adds r0, r4, r1
	movs r1, #0x91
	lsls r1, r1, #1
	strh r1, [r0]
	ldr r2, _080783D0 @ =0x0000037E
	adds r0, r4, r2
	ldrh r1, [r0]
	cmp r1, #0x1f
	bhi _080783D4
	movs r3, #0x96
	lsls r3, r3, #4
	adds r0, r4, r3
	strh r1, [r0]
	b _080783E0
	.align 2, 0
_080783CC: .4byte 0x0000095E
_080783D0: .4byte 0x0000037E
_080783D4:
	movs r0, #0x40
	subs r0, r0, r1
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r4, r2
	strh r0, [r1]
_080783E0:
	ldr r3, _08078488 @ =0x0000037E
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x40
	bls _080783F6
	movs r0, #0
	strh r0, [r1]
_080783F6:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #9
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0x1e
	strh r0, [r1]
	movs r3, #0x93
	lsls r3, r3, #4
	adds r1, r4, r3
	adds r0, r4, #0
	bl FUN_080620f0
_08078424:
	ldr r1, _0807848C @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _0807847E
	ldr r2, _08078490 @ =0x00000434
	adds r1, r4, r2
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne _0807847E
	bl FUN_0809c58c
	ldr r0, _08078494 @ =0x00000239
	bl sound_08240740
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	bl FUN_08072620
	movs r3, #0x96
	lsls r3, r3, #3
	adds r2, r4, r3
	ldr r3, [r2]
	cmp r3, #0
	beq _0807847E
	ldr r1, _08078498 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #0x10]
	add r0, sp, #0xc
	add r1, sp, #0x10
	str r0, [r1, #4]
	str r5, [sp, #0xc]
	str r5, [r2]
	adds r0, r3, #0
	bl FUN_082318ac
_0807847E:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08078488: .4byte 0x0000037E
_0807848C: .4byte 0x0000037D
_08078490: .4byte 0x00000434
_08078494: .4byte 0x00000239
_08078498: .4byte 0xFFFF0000
