	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08003014
FUN_08003014: @ 0x08003014
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	mov sb, r0
	mov r8, r1
	ldr r3, _0800308C @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r2, #0x20
	orrs r0, r2
	ldr r1, _08003090 @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0xc]
	movs r7, #0
	add r4, sp, #0x10
	ldr r6, _08003094 @ =0x030046B8
	ldr r5, _08003098 @ =0x000003FF
_08003042:
	ldr r0, [r6]
	adds r2, r0, #1
	ands r2, r5
	str r2, [r6]
	mov r3, sb
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	movs r0, #1
	ands r0, r7
	cmp r0, #0
	bne _080030A0
	adds r2, #1
	ands r2, r5
	lsls r0, r2, #1
	ldr r1, _0800309C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	add r0, r8
	ldrh r3, [r4]
	adds r0, r0, r3
	add r1, sp, #0x10
	strh r0, [r1]
	adds r2, #1
	ands r2, r5
	str r2, [r6]
	lsls r2, r2, #1
	ldr r0, _0800309C @ =0x0203B400
	adds r2, r2, r0
	ldrh r0, [r4, #4]
	subs r0, #0x80
	ldrb r2, [r2]
	adds r0, r0, r2
	b _080030CC
	.align 2, 0
_0800308C: .4byte 0xFFFF0000
_08003090: .4byte 0x0000FFFF
_08003094: .4byte 0x030046B8
_08003098: .4byte 0x000003FF
_0800309C: .4byte 0x0203B400
_080030A0:
	adds r1, r2, #1
	ands r1, r5
	lsls r2, r1, #1
	ldr r3, _080030F8 @ =0x0203B400
	adds r2, r2, r3
	ldrh r0, [r4]
	subs r0, #0x80
	ldrb r2, [r2]
	adds r0, r0, r2
	add r2, sp, #0x10
	strh r0, [r2]
	adds r1, #1
	ands r1, r5
	str r1, [r6]
	lsls r1, r1, #1
	adds r1, r1, r3
	ldrh r0, [r1]
	movs r1, #0xf
	ands r0, r1
	add r0, r8
	ldrh r1, [r4, #4]
	adds r0, r0, r1
_080030CC:
	strh r0, [r4, #4]
	movs r0, #3
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r1, #0
	add r2, sp, #8
	movs r3, #1
	bl FUN_080dbcec
	adds r7, #1
	cmp r7, #9
	ble _08003042
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080030F8: .4byte 0x0203B400

	thumb_func_start FUN_080030fc
FUN_080030fc: @ 0x080030FC
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r5, #0xbc
	movs r0, #0
	cmp r2, #1
	beq _08003130
	cmp r2, #1
	bgt _08003112
	cmp r2, #0
	beq _0800311C
	b _08003148
_08003112:
	cmp r2, #2
	beq _08003134
	cmp r2, #3
	beq _08003144
	b _08003148
_0800311C:
	ldr r0, _0800312C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	rsbs r0, r0, #0
	b _08003148
	.align 2, 0
_0800312C: .4byte 0x030046A4
_08003130:
	movs r0, #1
	b _08003148
_08003134:
	ldr r0, _08003140 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	b _08003148
	.align 2, 0
_08003140: .4byte 0x030046A4
_08003144:
	movs r0, #1
	rsbs r0, r0, #0
_08003148:
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0800315A
	adds r4, r0, #4
	b _08003166
_0800315A:
	ldr r0, _0800318C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r4, r1, r0
_08003166:
	cmp r4, #0
	beq _0800319E
	ldrb r3, [r4]
	lsrs r0, r3, #4
	cmp r0, #0
	bne _08003190
	movs r0, #0xf
	ldrb r2, [r5]
	adds r1, r0, #0
	ands r1, r3
	ands r0, r2
	cmp r1, r0
	blo _0800319E
	ldrh r1, [r4, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0800319E
	b _080031A2
	.align 2, 0
_0800318C: .4byte 0x030046A4
_08003190:
	movs r0, #0xf
	ldrb r2, [r5]
	adds r1, r0, #0
	ands r1, r3
	ands r0, r2
	cmp r1, r0
	bhs _080031A2
_0800319E:
	movs r0, #0
	b _080031A4
_080031A2:
	movs r0, #1
_080031A4:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080031ac
FUN_080031ac: @ 0x080031AC
	push {lr}
	cmp r0, #5
	bne _080031C0
	ldr r0, _080031BC @ =0x00000151
	bl PlaySound_082406e0
	b _080031C6
	.align 2, 0
_080031BC: .4byte 0x00000151
_080031C0:
	ldr r0, _080031CC @ =0x00000151
	bl PlaySound_082406e0
_080031C6:
	pop {r0}
	bx r0
	.align 2, 0
_080031CC: .4byte 0x00000151

	thumb_func_start FUN_080031d0
FUN_080031d0: @ 0x080031D0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0xbc
	movs r0, #0
	cmp r2, #1
	beq _08003204
	cmp r2, #1
	bgt _080031E8
	cmp r2, #0
	beq _080031F2
	b _0800321C
_080031E8:
	cmp r2, #2
	beq _08003208
	cmp r2, #3
	beq _08003218
	b _0800321C
_080031F2:
	ldr r0, _08003200 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	rsbs r0, r0, #0
	b _0800321C
	.align 2, 0
_08003200: .4byte 0x030046A4
_08003204:
	movs r0, #1
	b _0800321C
_08003208:
	ldr r0, _08003214 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	b _0800321C
	.align 2, 0
_08003214: .4byte 0x030046A4
_08003218:
	movs r0, #1
	rsbs r0, r0, #0
_0800321C:
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0800322E
	adds r0, #4
	b _0800323A
_0800322E:
	ldr r0, _08003254 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0800323A:
	cmp r0, #0
	beq _08003262
	ldrb r2, [r0]
	movs r0, #0xf
	ldrb r3, [r6]
	adds r1, r0, #0
	ands r1, r2
	ands r0, r3
	cmp r1, r0
	blo _08003258
	movs r0, #1
	b _08003264
	.align 2, 0
_08003254: .4byte 0x030046A4
_08003258:
	ldrb r0, [r5]
	cmp r0, #5
	bne _08003262
	bl FUN_080031ac
_08003262:
	movs r0, #0
_08003264:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800326c
FUN_0800326c: @ 0x0800326C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0
	movs r4, #0
_08003274:
	adds r0, r5, #0
	adds r0, #0xba
	ldrh r1, [r0]
	adds r0, r5, #0
	adds r2, r4, #0
	bl FUN_080030fc
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0800328A
	adds r6, #1
_0800328A:
	adds r4, #1
	cmp r4, #3
	ble _08003274
	cmp r6, #2
	bgt _08003298
	movs r0, #0
	b _0800329A
_08003298:
	movs r0, #1
_0800329A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080032a0
FUN_080032a0: @ 0x080032A0
	push {r4, lr}
	sub sp, #0x24
	adds r4, r0, #0
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, _080032C0 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _080032C4 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080032C8
	movs r0, #1
	b _080032CA
	.align 2, 0
_080032C0: .4byte 0x030046A0
_080032C4: .4byte 0x00000934
_080032C8:
	movs r0, #0
_080032CA:
	cmp r0, #0
	beq _08003338
	ldr r0, _0800332C @ =0x00000145
	bl PlaySound_082406e0
	adds r0, r4, #0
	adds r0, #0xa8
	ldr r1, [r0, #4]
	ldr r0, [r0]
	adds r4, r0, #0
	asrs r2, r4, #0x10
	movs r3, #0xdd
	lsls r3, r3, #1
	adds r2, r2, r3
	lsls r2, r2, #0x10
	ldr r3, _08003330 @ =0x0000FFFF
	ands r4, r3
	adds r0, r4, #0
	orrs r0, r2
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	add r0, sp, #0x1c
	ldrh r1, [r0]
	adds r1, #0x80
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08003334 @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r0, sp, #0x1c
	ldrh r0, [r0, #4]
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x20]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x20]
	add r0, sp, #0x1c
	str r0, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #0x1e
	bl FUN_08016110
	b _080033A2
	.align 2, 0
_0800332C: .4byte 0x00000145
_08003330: .4byte 0x0000FFFF
_08003334: .4byte 0xFFFF0000
_08003338:
	ldrb r0, [r4]
	cmp r0, #1
	beq _0800334C
	cmp r0, #1
	bgt _08003348
	cmp r0, #0
	beq _0800334C
	b _08003358
_08003348:
	cmp r0, #6
	bgt _08003358
_0800334C:
	ldr r0, _08003354 @ =0x00000143
	bl PlaySound_082406e0
	b _0800335E
	.align 2, 0
_08003354: .4byte 0x00000143
_08003358:
	ldr r0, _08003394 @ =0x00000143
	bl PlaySound_082406e0
_0800335E:
	adds r0, r4, #0
	bl FUN_0800326c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08003398
	movs r0, #0
	str r0, [sp]
	movs r0, #0xff
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #4
	str r0, [sp, #0xc]
	movs r0, #6
	str r0, [sp, #0x10]
	str r0, [sp, #0x14]
	adds r0, r4, #0
	adds r0, #0xa8
	str r0, [sp, #0x18]
	movs r0, #4
	movs r1, #1
	movs r2, #1
	movs r3, #0x40
	bl FUN_08015ce0
	b _080033A2
	.align 2, 0
_08003394: .4byte 0x00000143
_08003398:
	adds r0, r4, #0
	adds r0, #0x34
	movs r1, #0x90
	bl FUN_08003014
_080033A2:
	add sp, #0x24
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080033ac
FUN_080033ac: @ 0x080033AC
	push {r4, lr}
	sub sp, #0x24
	adds r4, r0, #0
	adds r0, #0xba
	ldrh r1, [r0]
	ldrb r2, [r4, #0x10]
	adds r0, r4, #0
	bl FUN_080031d0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08003484
	adds r0, r4, #0
	adds r0, #0xa8
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	movs r1, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	beq _08003408
	cmp r0, #1
	bgt _080033E2
	cmp r0, #0
	beq _080033EC
	b _0800345A
_080033E2:
	cmp r0, #2
	beq _08003428
	cmp r0, #3
	beq _08003444
	b _0800345A
_080033EC:
	add r0, sp, #0x1c
	ldrh r1, [r0, #4]
	subs r1, #0x80
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08003404 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x20]
	movs r1, #0xb0
	b _0800345A
	.align 2, 0
_08003404: .4byte 0xFFFF0000
_08003408:
	add r0, sp, #0x1c
	ldrh r1, [r0]
	adds r1, #0x80
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08003424 @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x1c]
	movs r1, #0x10
	rsbs r1, r1, #0
	b _0800345A
	.align 2, 0
_08003424: .4byte 0xFFFF0000
_08003428:
	add r0, sp, #0x1c
	ldrh r1, [r0, #4]
	adds r1, #0x80
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08003440 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x20]
	movs r1, #0x30
	b _0800345A
	.align 2, 0
_08003440: .4byte 0xFFFF0000
_08003444:
	add r0, sp, #0x1c
	ldrh r1, [r0]
	subs r1, #0x80
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0800348C @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x1c]
	movs r1, #0x70
_0800345A:
	str r1, [sp]
	movs r0, #0x1f
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #4
	str r0, [sp, #0xc]
	movs r0, #6
	str r0, [sp, #0x10]
	str r0, [sp, #0x14]
	add r0, sp, #0x1c
	str r0, [sp, #0x18]
	movs r0, #2
	movs r1, #1
	movs r2, #1
	movs r3, #0x40
	bl FUN_08015ce0
	ldrb r0, [r4]
	bl FUN_080031ac
_08003484:
	add sp, #0x24
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800348C: .4byte 0xFFFF0000

	thumb_func_start FUN_08003490
FUN_08003490: @ 0x08003490
	push {lr}
	cmp r0, #1
	beq _080034AE
	cmp r0, #1
	bgt _080034A0
	cmp r0, #0
	beq _080034A4
	b _080034BC
_080034A0:
	cmp r0, #5
	bgt _080034BC
_080034A4:
	movs r0, #0xa1
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080034C4
_080034AE:
	ldr r0, _080034B8 @ =0x00000137
	bl PlaySound_082406e0
	b _080034C4
	.align 2, 0
_080034B8: .4byte 0x00000137
_080034BC:
	movs r0, #0xa1
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080034C4:
	pop {r0}
	bx r0

	thumb_func_start FUN_080034c8
FUN_080034c8: @ 0x080034C8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	adds r0, r2, #0
	movs r3, #0
	adds r4, r0, #0
	ldrb r2, [r4]
	cmp r2, #0
	bne _08003508
	movs r1, #7
	ldr r0, [r5, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _0800359A
	movs r1, #0x10
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _0800359A
	ldrh r0, [r4, #0x16]
	subs r0, #0x18
	strh r0, [r4, #0x16]
	movs r0, #0xa
	strb r0, [r4, #0x18]
	movs r0, #2
	strb r0, [r4, #0x1f]
	adds r0, r4, #0
	adds r0, #0x70
	ldrh r1, [r4, #0x1c]
	bl FUN_0822b20c
	b _0800359E
_08003508:
	cmp r2, #1
	bne _08003574
	movs r6, #4
	ldr r0, [r5, #0x38]
	ands r0, r6
	cmp r0, #0
	beq _0800359A
	ldr r0, _08003570 @ =0x00010007
	ldr r1, [r5, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _0800359A
	movs r0, #0x40
	ands r1, r0
	cmp r1, #0
	bne _0800359A
	ldrh r0, [r4, #0x16]
	subs r0, #0x18
	strh r0, [r4, #0x16]
	movs r7, #0xa
	strb r7, [r4, #0x18]
	movs r0, #2
	strb r0, [r4, #0x1f]
	adds r0, r4, #0
	adds r0, #0x70
	ldrh r1, [r4, #0x1c]
	bl FUN_0822b20c
	adds r1, r4, #0
	adds r1, #0x21
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800359E
	strb r7, [r1]
	movs r0, #0xae
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r4, #0
	adds r0, #0x34
	movs r1, #0xc
	str r1, [sp]
	str r1, [sp, #4]
	str r6, [sp, #8]
	str r6, [sp, #0xc]
	movs r1, #0
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015d3c
	b _0800359E
	.align 2, 0
_08003570: .4byte 0x00010007
_08003574:
	cmp r2, #2
	bne _0800359A
	movs r1, #4
	ldr r0, [r5, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _0800359A
	ldrh r0, [r4, #0x16]
	subs r0, #0x18
	strh r0, [r4, #0x16]
	movs r0, #0xa
	strb r0, [r4, #0x18]
	strb r2, [r4, #0x1f]
	adds r0, r4, #0
	adds r0, #0x70
	ldrh r1, [r4, #0x1c]
	bl FUN_0822b20c
	movs r3, #1
_0800359A:
	cmp r3, #0
	beq _080035D6
_0800359E:
	ldrh r0, [r4, #4]
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _080035B6
	movs r1, #0x16
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bgt _080035C4
	movs r0, #1
	strh r0, [r4, #0x16]
_080035B6:
	movs r1, #0x16
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bge _080035C4
	movs r0, #0
	strh r0, [r4, #0x16]
	b _080035D6
_080035C4:
	movs r1, #4
	ldr r0, [r5, #0x34]
	ands r0, r1
	cmp r0, #0
	bne _080035D6
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080035D6:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080035e0
FUN_080035e0: @ 0x080035E0
	bx lr
	.align 2, 0

	thumb_func_start FUN_080035e4
FUN_080035e4: @ 0x080035E4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov ip, r0
	ldr r0, _08003674 @ =0x03000020
	ldr r7, [r0]
	ldr r3, [r7, #0x70]
	movs r6, #0
	ldrh r0, [r7, #0x18]
	cmp r6, r0
	bge _08003690
	movs r1, #0xf
	mov r8, r1
	ldr r2, _08003678 @ =FUN_080040f0
	mov sl, r2
	movs r0, #0
	mov sb, r0
_0800360A:
	ldrb r0, [r3, #0x1e]
	cmp r0, #0
	beq _08003682
	cmp r3, ip
	beq _08003682
	adds r2, r3, #0
	adds r2, #0xbc
	mov r5, ip
	adds r5, #0xbc
	adds r0, r3, #0
	adds r0, #0xba
	mov r1, ip
	adds r1, #0xba
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _08003682
	ldrh r4, [r3, #4]
	cmp r4, #0
	bne _08003682
	ldrb r0, [r2]
	ldrb r2, [r5]
	mov r1, r8
	ands r1, r0
	mov r0, r8
	ands r0, r2
	cmp r1, r0
	bls _08003682
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r0, r3, r1
	mov r2, sl
	str r2, [r0]
	strh r4, [r3, #2]
	movs r0, #1
	strb r0, [r3, #0x11]
	movs r0, #2
	strh r0, [r3, #4]
	strh r4, [r3, #0xc]
	strh r4, [r3, #0xe]
	mov r0, sb
	strb r0, [r3, #0x10]
	ldrh r1, [r3, #0x36]
	strh r1, [r3, #0x12]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xff
	bls _08003680
	ldr r2, _0800367C @ =0xFFFFFF00
	adds r0, r1, r2
	strh r0, [r3, #0x12]
	b _08003682
	.align 2, 0
_08003674: .4byte 0x03000020
_08003678: .4byte FUN_080040f0
_0800367C: .4byte 0xFFFFFF00
_08003680:
	strh r4, [r3, #0x12]
_08003682:
	adds r6, #1
	movs r0, #0xce
	lsls r0, r0, #1
	adds r3, r3, r0
	ldrh r1, [r7, #0x18]
	cmp r6, r1
	blt _0800360A
_08003690:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080036a0
FUN_080036a0: @ 0x080036A0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	bl FUN_0822a4e0
	adds r0, r4, #0
	adds r0, #0xb8
	bl FUN_082342a8
	adds r0, r4, #0
	adds r0, #0xc8
	bl FUN_08236424
	ldrb r1, [r4, #1]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080036CC
	adds r0, r4, #0
	adds r0, #0x2c
	bl FUN_08002a58
_080036CC:
	adds r0, r4, #0
	adds r0, #0x2c
	bl FUN_0823b284
	movs r0, #0
	strb r0, [r4, #0x1e]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080036e0
FUN_080036e0: @ 0x080036E0
	push {r4, r5, r6, lr}
	ldr r0, _080036F0 @ =0x03000020
	ldr r6, [r0]
	cmp r6, #0
	bne _080036F4
	movs r0, #1
	rsbs r0, r0, #0
	b _08003716
	.align 2, 0
_080036F0: .4byte 0x03000020
_080036F4:
	ldr r4, [r6, #0x70]
	movs r5, #0
	b _0800370E
_080036FA:
	ldrb r0, [r4, #0x1e]
	cmp r0, #0
	beq _08003706
	adds r0, r4, #0
	bl FUN_080036a0
_08003706:
	movs r0, #0xce
	lsls r0, r0, #1
	adds r4, r4, r0
	adds r5, #1
_0800370E:
	ldrh r0, [r6, #0x18]
	cmp r5, r0
	blt _080036FA
	movs r0, #0
_08003716:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800371c
FUN_0800371c: @ 0x0800371C
	push {r4, r5, r6, r7, lr}
	ldr r0, _0800372C @ =0x03000020
	ldr r5, [r0]
	cmp r5, #0
	bne _08003730
	movs r0, #1
	rsbs r0, r0, #0
	b _08003772
	.align 2, 0
_0800372C: .4byte 0x03000020
_08003730:
	ldr r1, [r5, #0x70]
	movs r4, #0
	ldrh r0, [r5, #0x18]
	cmp r4, r0
	bge _08003770
	ldr r6, _08003778 @ =FUN_080041c4
_0800373C:
	ldrb r0, [r1, #0x1e]
	cmp r0, #0
	beq _08003762
	ldrb r3, [r1]
	cmp r3, #1
	bne _08003762
	movs r0, #0
	strh r0, [r1, #0x16]
	ldrh r2, [r1, #4]
	cmp r2, #0
	bne _08003762
	movs r7, #0xcc
	lsls r7, r7, #1
	adds r0, r1, r7
	str r6, [r0]
	strh r2, [r1, #2]
	strb r3, [r1, #0x11]
	movs r0, #3
	strh r0, [r1, #4]
_08003762:
	movs r0, #0xce
	lsls r0, r0, #1
	adds r1, r1, r0
	adds r4, #1
	ldrh r7, [r5, #0x18]
	cmp r4, r7
	blt _0800373C
_08003770:
	movs r0, #0
_08003772:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08003778: .4byte FUN_080041c4

	thumb_func_start FUN_0800377c
FUN_0800377c: @ 0x0800377C
	push {r4, r5, r6, r7, lr}
	ldr r0, _0800378C @ =0x03000020
	ldr r6, [r0]
	cmp r6, #0
	bne _08003790
	movs r0, #1
	rsbs r0, r0, #0
	b _080037C2
	.align 2, 0
_0800378C: .4byte 0x03000020
_08003790:
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r7, r0, #0
	ldr r4, [r6, #0x70]
	movs r5, #0
	b _080037BA
_080037A0:
	ldrb r0, [r4, #0x1e]
	cmp r0, #0
	beq _080037B2
	ldrh r0, [r4, #0x2c]
	cmp r0, r7
	bne _080037B2
	adds r0, r4, #0
	bl FUN_080036a0
_080037B2:
	movs r0, #0xce
	lsls r0, r0, #1
	adds r4, r4, r0
	adds r5, #1
_080037BA:
	ldrh r0, [r6, #0x18]
	cmp r5, r0
	blt _080037A0
	movs r0, #0
_080037C2:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080037c8
FUN_080037c8: @ 0x080037C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	adds r6, r0, #0
	ldr r0, _080038AC @ =0x0000015B
	bl PlaySound_082406e0
	adds r7, r6, #0
	adds r7, #0x34
	movs r0, #0x1e
	str r0, [sp]
	movs r5, #0x10
	str r5, [sp, #4]
	movs r4, #8
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r1, #0
	mov sl, r1
	str r1, [sp, #0x10]
	movs r2, #0x80
	lsls r2, r2, #1
	mov sb, r2
	str r2, [sp, #0x14]
	movs r0, #0x18
	mov r8, r0
	str r0, [sp, #0x18]
	str r5, [sp, #0x1c]
	movs r0, #3
	movs r1, #2
	adds r2, r7, #0
	movs r3, #0x3c
	bl FUN_08014da0
	movs r1, #0x1e
	str r1, [sp]
	movs r0, #0x16
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	mov r2, sl
	str r2, [sp, #0x10]
	mov r0, sb
	str r0, [sp, #0x14]
	mov r1, r8
	str r1, [sp, #0x18]
	str r5, [sp, #0x1c]
	movs r0, #8
	movs r1, #6
	adds r2, r7, #0
	movs r3, #0x3c
	bl FUN_08014da0
	ldr r2, _080038B0 @ =0xFFFF0000
	ldrh r1, [r6, #0x36]
	adds r1, #0x80
	lsls r1, r1, #0x10
	ldr r5, _080038B4 @ =0x0000FFFF
	ldrh r0, [r6, #0x34]
	orrs r0, r1
	str r0, [sp, #0x20]
	ldrh r1, [r6, #0x38]
	ldr r0, [sp, #0x24]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x28]
	ands r0, r2
	ldr r4, _080038B8 @ =0x0000FFF1
	orrs r0, r4
	ands r0, r5
	movs r1, #0x80
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [sp, #0x28]
	add r3, sp, #0x28
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r4
	str r0, [r3, #4]
	ldr r0, [sp, #0x30]
	ands r0, r2
	movs r1, #0x1e
	orrs r0, r1
	ands r0, r5
	movs r1, #0xb0
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #0x30]
	add r1, sp, #0x30
	ldr r0, [r1, #4]
	ands r0, r2
	movs r2, #0x1e
	orrs r0, r2
	str r0, [r1, #4]
	str r1, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r0, [sp, #8]
	movs r0, #8
	movs r1, #3
	add r2, sp, #0x20
	bl FUN_08014730
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080038AC: .4byte 0x0000015B
_080038B0: .4byte 0xFFFF0000
_080038B4: .4byte 0x0000FFFF
_080038B8: .4byte 0x0000FFF1

	thumb_func_start FUN_080038bc
FUN_080038bc: @ 0x080038BC
	push {r4, r5, r6, lr}
	sub sp, #0x38
	adds r4, r0, #0
	ldr r0, _08003960 @ =0x00000135
	bl PlaySound_082406e0
	adds r2, r4, #0
	adds r2, #0x34
	movs r5, #0x1e
	str r5, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	movs r0, #8
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	movs r0, #0
	str r0, [sp, #0x10]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [sp, #0x14]
	movs r0, #0x18
	str r0, [sp, #0x18]
	movs r0, #0x10
	str r0, [sp, #0x1c]
	movs r0, #4
	movs r1, #0
	movs r3, #0x3c
	bl FUN_08014da0
	ldr r2, _08003964 @ =0xFFFF0000
	ldrh r1, [r4, #0x36]
	adds r1, #0x80
	lsls r1, r1, #0x10
	ldr r6, _08003968 @ =0x0000FFFF
	ldrh r0, [r4, #0x34]
	orrs r0, r1
	str r0, [sp, #0x20]
	ldrh r1, [r4, #0x38]
	ldr r0, [sp, #0x24]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x28]
	ands r0, r2
	ldr r4, _0800396C @ =0x0000FFF1
	orrs r0, r4
	ands r0, r6
	movs r1, #0x80
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [sp, #0x28]
	add r3, sp, #0x28
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r4
	str r0, [r3, #4]
	ldr r0, [sp, #0x30]
	ands r0, r2
	orrs r0, r5
	ands r0, r6
	movs r1, #0xb0
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #0x30]
	add r1, sp, #0x30
	ldr r0, [r1, #4]
	ands r0, r2
	orrs r0, r5
	str r0, [r1, #4]
	str r1, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r0, [sp, #8]
	movs r0, #8
	movs r1, #2
	add r2, sp, #0x20
	bl FUN_08014730
	add sp, #0x38
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08003960: .4byte 0x00000135
_08003964: .4byte 0xFFFF0000
_08003968: .4byte 0x0000FFFF
_0800396C: .4byte 0x0000FFF1

	thumb_func_start FUN_08003970
FUN_08003970: @ 0x08003970
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r6, r0, #0
	movs r0, #0xa8
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r6, #0x34
	movs r7, #0x1e
	str r7, [sp]
	movs r5, #0x10
	str r5, [sp, #4]
	movs r4, #8
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #0
	mov sl, r0
	str r0, [sp, #0x10]
	movs r0, #0x80
	lsls r0, r0, #1
	mov sb, r0
	str r0, [sp, #0x14]
	movs r0, #0x18
	mov r8, r0
	str r0, [sp, #0x18]
	str r5, [sp, #0x1c]
	movs r0, #3
	movs r1, #1
	adds r2, r6, #0
	movs r3, #0x3c
	bl FUN_08014da0
	str r7, [sp]
	movs r0, #0x16
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	mov r0, sl
	str r0, [sp, #0x10]
	mov r0, sb
	str r0, [sp, #0x14]
	mov r0, r8
	str r0, [sp, #0x18]
	str r5, [sp, #0x1c]
	movs r0, #8
	movs r1, #5
	adds r2, r6, #0
	movs r3, #0x3c
	bl FUN_08014da0
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080039ec
FUN_080039ec: @ 0x080039EC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	str r0, [sp, #0x18]
	ldr r2, _08003A44 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	movs r3, #0x20
	orrs r0, r3
	ldr r1, _08003A48 @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0xc]
	add r5, sp, #0x10
	ldr r0, _08003A4C @ =0x0203B400
	mov sb, r0
	ldr r1, _08003A50 @ =0x030046B8
	mov r8, r1
	ldr r7, _08003A54 @ =0x000003FF
	adds r6, r2, #0
	movs r2, #2
	str r2, [sp, #0x1c]
	movs r3, #0xff
	mov sl, r3
	adds r4, r5, #0
_08003A2A:
	ldr r2, [sp, #0x18]
	ldr r0, [r2, #0x34]
	ldr r1, [r2, #0x38]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldrb r0, [r2, #0x10]
	cmp r0, #1
	beq _08003AA0
	cmp r0, #1
	bgt _08003A58
	cmp r0, #0
	beq _08003A62
	b _08003B40
	.align 2, 0
_08003A44: .4byte 0xFFFF0000
_08003A48: .4byte 0x0000FFFF
_08003A4C: .4byte 0x0203B400
_08003A50: .4byte 0x030046B8
_08003A54: .4byte 0x000003FF
_08003A58:
	cmp r0, #2
	beq _08003ABA
	cmp r0, #3
	beq _08003AF8
	b _08003B40
_08003A62:
	mov r3, r8
	ldr r2, [r3]
	adds r2, #1
	ands r2, r7
	lsls r0, r2, #1
	add r0, sb
	ldrh r0, [r0]
	ldrh r1, [r5]
	subs r1, #0x80
	mov r3, sl
	ands r0, r3
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x10]
	ands r0, r6
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r2, #1
	ands r2, r7
	mov r0, r8
	str r2, [r0]
	lsls r2, r2, #1
	add r2, sb
	ldrh r2, [r2]
	ldrh r1, [r4, #4]
	adds r1, #0x78
	movs r0, #0xf
	ands r2, r0
	adds r1, r1, r2
	b _08003B34
_08003AA0:
	mov r1, r8
	ldr r2, [r1]
	adds r2, #1
	ands r2, r7
	lsls r0, r2, #1
	add r0, sb
	ldrh r3, [r0]
	ldrh r1, [r5]
	subs r1, #0x78
	movs r0, #0xf
	ands r3, r0
	subs r1, r1, r3
	b _08003B10
_08003ABA:
	mov r3, r8
	ldr r2, [r3]
	adds r2, #1
	ands r2, r7
	lsls r0, r2, #1
	add r0, sb
	ldrh r0, [r0]
	ldrh r1, [r5]
	subs r1, #0x80
	mov r3, sl
	ands r0, r3
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x10]
	ands r0, r6
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r2, #1
	ands r2, r7
	mov r0, r8
	str r2, [r0]
	lsls r2, r2, #1
	add r2, sb
	ldrh r2, [r2]
	ldrh r1, [r4, #4]
	subs r1, #0x78
	movs r0, #0xf
	ands r2, r0
	subs r1, r1, r2
	b _08003B34
_08003AF8:
	mov r1, r8
	ldr r2, [r1]
	adds r2, #1
	ands r2, r7
	lsls r0, r2, #1
	add r0, sb
	ldrh r3, [r0]
	ldrh r1, [r5]
	adds r1, #0x78
	movs r0, #0xf
	ands r3, r0
	adds r1, r1, r3
_08003B10:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x10]
	ands r0, r6
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r2, #1
	ands r2, r7
	mov r3, r8
	str r2, [r3]
	lsls r2, r2, #1
	add r2, sb
	ldrh r0, [r2]
	ldrh r1, [r4, #4]
	subs r1, #0x80
	mov r2, sl
	ands r0, r2
	adds r1, r1, r0
_08003B34:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r4, #4]
	ands r0, r6
	orrs r0, r1
	str r0, [r4, #4]
_08003B40:
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #0
	add r2, sp, #8
	movs r3, #1
	bl FUN_080dbcec
	ldr r3, [sp, #0x1c]
	subs r3, #1
	str r3, [sp, #0x1c]
	cmp r3, #0
	blt _08003B60
	b _08003A2A
_08003B60:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08003b70
FUN_08003b70: @ 0x08003B70
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	adds r4, r1, #0
	mov r8, r2
	movs r0, #0xbc
	adds r0, r0, r5
	mov sl, r0
	movs r1, #0
	movs r2, #0
	str r2, [sp]
	movs r0, #0
	str r0, [sp, #4]
	ldr r0, _08003BB4 @ =0x03002B8C
	ldrh r0, [r0]
	cmp r0, #0
	beq _08003BA4
	ldr r0, _08003BB8 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #2
	bne _08003BA4
	movs r2, #1
_08003BA4:
	cmp r2, #0
	bne _08003BAE
	ldrb r0, [r5]
	cmp r0, #1
	bne _08003BBC
_08003BAE:
	movs r0, #0x10
	movs r2, #0x10
	b _08003BC0
	.align 2, 0
_08003BB4: .4byte 0x03002B8C
_08003BB8: .4byte 0x03002B60
_08003BBC:
	movs r0, #4
	movs r2, #0x40
_08003BC0:
	str r2, [sp, #8]
	mov r2, r8
	cmp r2, #1
	beq _08003BF4
	cmp r2, #1
	bgt _08003BD2
	cmp r2, #0
	beq _08003BDE
	b _08003C14
_08003BD2:
	mov r2, r8
	cmp r2, #2
	beq _08003BFA
	cmp r2, #3
	beq _08003C0C
	b _08003C14
_08003BDE:
	rsbs r0, r0, #0
	str r0, [sp, #4]
	ldr r0, _08003BF0 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	rsbs r1, r0, #0
	b _08003C14
	.align 2, 0
_08003BF0: .4byte 0x030046A4
_08003BF4:
	str r0, [sp]
	movs r1, #1
	b _08003C14
_08003BFA:
	str r0, [sp, #4]
	ldr r0, _08003C08 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	b _08003C14
	.align 2, 0
_08003C08: .4byte 0x030046A4
_08003C0C:
	rsbs r0, r0, #0
	str r0, [sp]
	movs r1, #1
	rsbs r1, r1, #0
_08003C14:
	adds r4, r4, r1
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	mov sb, r4
	cmp r0, #0
	beq _08003C28
	adds r6, r0, #4
	b _08003C36
_08003C28:
	ldr r0, _08003CA4 @ =0x030046A4
	ldr r1, [r0]
	mov r2, sb
	lsls r0, r2, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r6, r1, r0
_08003C36:
	cmp r6, #0
	beq _08003D06
	ldrb r1, [r6]
	movs r4, #0xf0
	lsrs r7, r1, #4
	cmp r7, #0
	bne _08003D04
	movs r0, #0xf
	mov ip, r0
	mov r2, sl
	ldrb r0, [r2]
	mov r3, ip
	ands r3, r1
	mov r2, ip
	ands r2, r0
	cmp r3, r2
	bhs _08003D06
	ldrh r1, [r6, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08003D06
	subs r0, r2, r3
	cmp r0, #1
	ble _08003CAC
	lsls r0, r3, #8
	strh r0, [r5, #0x12]
	mov r0, r8
	strb r0, [r5, #0x10]
	ldr r1, _08003CA8 @ =FUN_08003f80
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r0, r5, r2
	str r1, [r0]
	strh r7, [r5, #2]
	movs r0, #1
	strb r0, [r5, #0x11]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r5, #0xc]
	mov r1, sp
	ldrh r1, [r1, #4]
	strh r1, [r5, #0xe]
	movs r0, #2
	strh r0, [r5, #4]
	adds r0, r5, #0
	adds r0, #0xba
	mov r2, sb
	strh r2, [r0]
	mov r0, sp
	ldrh r0, [r0, #8]
	strh r0, [r5, #0x14]
	movs r0, #3
	b _08003D08
	.align 2, 0
_08003CA4: .4byte 0x030046A4
_08003CA8: .4byte FUN_08003f80
_08003CAC:
	lsls r0, r3, #8
	strh r0, [r5, #0x12]
	mov r2, sl
	ldrb r1, [r2]
	mov r0, ip
	ands r0, r1
	cmp r0, #0
	ble _08003CBE
	subs r0, #1
_08003CBE:
	ands r4, r1
	orrs r4, r0
	mov r0, sl
	strb r4, [r0]
	ldrb r0, [r6, #1]
	mov r1, sl
	strb r0, [r1, #1]
	mov r2, r8
	strb r2, [r5, #0x10]
	ldr r1, _08003D00 @ =FUN_08003f80
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r0, r5, r2
	str r1, [r0]
	strh r7, [r5, #2]
	movs r0, #1
	strb r0, [r5, #0x11]
	mov r1, sp
	ldrh r1, [r1]
	strh r1, [r5, #0xc]
	mov r2, sp
	ldrh r2, [r2, #4]
	strh r2, [r5, #0xe]
	strh r0, [r5, #4]
	adds r0, r5, #0
	adds r0, #0xba
	mov r1, sb
	strh r1, [r0]
	mov r2, sp
	ldrh r2, [r2, #8]
	strh r2, [r5, #0x14]
	movs r0, #1
	b _08003D08
	.align 2, 0
_08003D00: .4byte FUN_08003f80
_08003D04:
	subs r0, r7, #1
_08003D06:
	movs r0, #0
_08003D08:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08003d18
FUN_08003d18: @ 0x08003D18
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r5, r0, #0
	str r1, [sp]
	ldr r0, _08003D38 @ =0x03000020
	ldr r0, [r0]
	str r0, [sp, #0x10]
	cmp r0, #0
	bne _08003D3C
	movs r0, #1
	rsbs r0, r0, #0
	b _08003F14
	.align 2, 0
_08003D38: .4byte 0x03000020
_08003D3C:
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08003D60
	cmp r1, #0
	blt _08003D60
	ldr r0, _08003D64 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08003D60
	ldr r0, _08003D68 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08003D6C
_08003D60:
	movs r4, #0
	b _08003D7A
	.align 2, 0
_08003D64: .4byte 0x030046A8
_08003D68: .4byte 0x030046AC
_08003D6C:
	ldr r0, _08003D8C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08003D7A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08003D90
	adds r0, #4
	b _08003D9C
	.align 2, 0
_08003D8C: .4byte 0x030046A4
_08003D90:
	ldr r0, _08003DC8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08003D9C:
	str r0, [sp, #0xc]
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08003DC2
	cmp r1, #0
	blt _08003DC2
	ldr r0, _08003DCC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08003DC2
	ldr r0, _08003DD0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08003DD4
_08003DC2:
	movs r0, #0
	b _08003DE2
	.align 2, 0
_08003DC8: .4byte 0x030046A4
_08003DCC: .4byte 0x030046A8
_08003DD0: .4byte 0x030046AC
_08003DD4:
	ldr r0, _08003DF8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_08003DE2:
	str r0, [sp, #8]
	movs r1, #0
	str r1, [sp, #4]
	ldr r2, [sp]
	cmp r2, #1
	beq _08003E1C
	cmp r2, #1
	bgt _08003DFC
	cmp r2, #0
	beq _08003E08
	b _08003E3A
	.align 2, 0
_08003DF8: .4byte 0x030046A4
_08003DFC:
	ldr r0, [sp]
	cmp r0, #2
	beq _08003E22
	cmp r0, #3
	beq _08003E34
	b _08003E3A
_08003E08:
	ldr r0, _08003E18 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	rsbs r0, r0, #0
	b _08003E38
	.align 2, 0
_08003E18: .4byte 0x030046A4
_08003E1C:
	movs r2, #1
	str r2, [sp, #4]
	b _08003E3A
_08003E22:
	ldr r0, _08003E30 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	str r1, [sp, #4]
	b _08003E3A
	.align 2, 0
_08003E30: .4byte 0x030046A4
_08003E34:
	movs r0, #1
	rsbs r0, r0, #0
_08003E38:
	str r0, [sp, #4]
_08003E3A:
	ldr r1, [sp, #0x10]
	ldr r5, [r1, #0x70]
	movs r2, #0
	mov sb, r2
	ldrh r0, [r1, #0x18]
	cmp sb, r0
	bge _08003F12
	movs r3, #0xf
	adds r7, r5, #0
	adds r7, #0x25
	adds r6, r5, #0
	adds r6, #0xba
_08003E52:
	ldrb r0, [r5, #0x1e]
	cmp r0, #0
	beq _08003EFC
	ldrh r0, [r5, #4]
	cmp r0, #0
	bne _08003EFC
	movs r1, #0xbc
	adds r1, r1, r5
	mov r8, r1
	ldr r2, [sp, #8]
	ldr r0, [sp, #4]
	adds r4, r2, r0
	mov sl, r6
	ldrh r1, [r6]
	cmp r4, r1
	bne _08003EFC
	ldr r2, [sp, #0xc]
	ldrb r0, [r2]
	adds r1, r3, #0
	ands r1, r0
	adds r1, #1
	ldrb r2, [r6, #2]
	adds r0, r3, #0
	ands r0, r2
	cmp r1, r0
	bne _08003EFC
	adds r0, r4, #0
	movs r1, #1
	str r3, [sp, #0x14]
	bl FUN_08234224
	ldr r3, [sp, #0x14]
	cmp r0, #0
	beq _08003E9A
	adds r0, #4
	b _08003EA6
_08003E9A:
	ldr r0, _08003EF8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08003EA6:
	ldrb r0, [r0]
	adds r1, r3, #0
	ands r1, r0
	mov r0, r8
	ldrb r2, [r0]
	adds r0, r3, #0
	ands r0, r2
	cmp r1, r0
	bne _08003EFC
	adds r0, r5, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	beq _08003EC8
	ldrb r0, [r7]
	cmp r0, #0
	beq _08003F12
_08003EC8:
	mov r2, sl
	ldrh r1, [r2]
	adds r0, r5, #0
	ldr r2, [sp]
	bl FUN_08003b70
	adds r4, r0, #0
	cmp r4, #0
	ble _08003EF4
	ldrb r0, [r5]
	bl FUN_08003490
	ldrb r0, [r5]
	cmp r0, #1
	bne _08003EEA
	movs r4, #1
	rsbs r4, r4, #0
_08003EEA:
	ldrb r0, [r7]
	cmp r0, #0
	beq _08003EF4
	subs r0, #1
	strb r0, [r7]
_08003EF4:
	adds r0, r4, #0
	b _08003F14
	.align 2, 0
_08003EF8: .4byte 0x030046A4
_08003EFC:
	movs r0, #0xce
	lsls r0, r0, #1
	adds r7, r7, r0
	adds r6, r6, r0
	adds r5, r5, r0
	movs r1, #1
	add sb, r1
	ldr r2, [sp, #0x10]
	ldrh r2, [r2, #0x18]
	cmp sb, r2
	blt _08003E52
_08003F12:
	movs r0, #0
_08003F14:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08003f24
FUN_08003f24: @ 0x08003F24
	push {lr}
	ldr r2, _08003F34 @ =0x085AA650
	adds r1, r1, r2
	ldrb r1, [r1]
	bl FUN_08003d18
	pop {r1}
	bx r1
	.align 2, 0
_08003F34: .4byte 0x085AA650

	thumb_func_start FUN_08003f38
FUN_08003f38: @ 0x08003F38
	push {r4, lr}
	adds r2, r0, #0
	ldrb r3, [r2]
	cmp r3, #1
	bne _08003F64
	movs r1, #0x16
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bgt _08003F7A
	ldr r1, _08003F60 @ =FUN_080041c4
	movs r4, #0xcc
	lsls r4, r4, #1
	adds r0, r2, r4
	str r1, [r0]
	movs r0, #0
	strh r0, [r2, #2]
	strb r3, [r2, #0x11]
	movs r0, #3
	strh r0, [r2, #4]
	b _08003F7A
	.align 2, 0
_08003F60: .4byte FUN_080041c4
_08003F64:
	movs r1, #0x16
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bgt _08003F7A
	movs r0, #0
	movs r1, #3
	strb r1, [r2, #0x19]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r1, r2, r3
	str r0, [r1]
_08003F7A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08003f80
FUN_08003f80: @ 0x08003F80
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
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	ldrb r0, [r5]
	cmp r0, #1
	beq _08003FF4
	ldrh r1, [r5, #2]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _08003FF4
	adds r0, r5, #0
	bl FUN_080039ec
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
	ldr r1, _0800404C @ =FUN_080040f0
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
_0800404C: .4byte FUN_080040f0
_08004050:
	adds r0, r5, #0
	adds r0, #0xba
	ldrh r1, [r0]
	ldrb r2, [r5, #0x10]
	adds r0, r5, #0
	bl FUN_08003b70
	cmp r0, #0
	bne _080040DE
	adds r0, r5, #0
	bl FUN_080033ac
	ldr r1, _0800408C @ =FUN_08003f38
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
_0800408C: .4byte FUN_08003f38
_08004090: .4byte 0x0000FFFE
_08004094:
	ldrh r2, [r5, #4]
	cmp r2, #2
	bne _080040B4
	ldr r0, _080040B0 @ =FUN_080040f0
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
_080040B0: .4byte FUN_080040f0
_080040B4:
	adds r0, r5, #0
	bl FUN_080033ac
	ldr r1, _080040E8 @ =FUN_08003f38
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
_080040E8: .4byte FUN_08003f38
_080040EC: .4byte 0x0000FFFE

	thumb_func_start FUN_080040f0
FUN_080040f0: @ 0x080040F0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x2c
	adds r3, r4, #0
	adds r3, #0xbc
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	beq _0800413E
	movs r0, #0
	strb r0, [r4, #0x11]
	ldrh r0, [r4, #0x12]
	lsrs r0, r0, #8
	adds r2, r0, #1
	cmp r2, #0xf
	ble _0800411E
	ldrb r0, [r3]
	movs r1, #0xf0
	ands r1, r0
	movs r0, #0xf
	orrs r1, r0
	strb r1, [r3]
	b _08004128
_0800411E:
	ldrb r1, [r3]
	movs r0, #0xf0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_08004128:
	movs r1, #8
	ldrb r0, [r4, #1]
	ands r0, r1
	cmp r0, #0
	beq _0800413E
	adds r2, r4, #0
	adds r2, #0xbe
	ldrh r1, [r2]
	movs r0, #0x21
	orrs r0, r1
	strh r0, [r2]
_0800413E:
	ldrh r0, [r4, #0x12]
	ldrh r1, [r5, #0xa]
	subs r0, r0, r1
	strh r0, [r5, #0x12]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	movs r0, #0x10
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0800415C
	ldr r0, _08004158 @ =0x0000FFF0
	b _08004162
	.align 2, 0
_08004158: .4byte 0x0000FFF0
_0800415C:
	cmp r1, #0
	ble _08004164
	movs r0, #0
_08004162:
	strh r0, [r5, #0x12]
_08004164:
	movs r0, #0x12
	ldrsh r3, [r5, r0]
	cmp r3, #0
	bne _080041B4
	movs r1, #8
	ldrb r0, [r4, #1]
	ands r0, r1
	cmp r0, #0
	beq _08004186
	adds r2, r4, #0
	adds r2, #0xbe
	ldrh r1, [r2]
	movs r0, #0x21
	orrs r0, r1
	strh r0, [r2]
	strh r3, [r4, #0x16]
	b _08004198
_08004186:
	adds r2, r4, #0
	adds r2, #0xbe
	ldrh r1, [r2]
	ldr r0, _080041BC @ =0x0000FFDE
	ands r0, r1
	strh r0, [r2]
	adds r0, r4, #0
	bl FUN_080032a0
_08004198:
	ldr r1, _080041C0 @ =FUN_08003f38
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r0, r4, r2
	str r1, [r0]
	movs r2, #0
	movs r1, #0
	strh r1, [r4, #2]
	movs r0, #1
	strb r0, [r4, #0x11]
	strh r1, [r4, #0xc]
	strh r1, [r4, #0xe]
	strb r2, [r4, #0x10]
	strh r1, [r4, #4]
_080041B4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080041BC: .4byte 0x0000FFDE
_080041C0: .4byte FUN_08003f38

	thumb_func_start FUN_080041c4
FUN_080041c4: @ 0x080041C4
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	beq _0800422C
	movs r5, #0
	strb r5, [r4, #0x11]
	adds r0, r4, #0
	adds r0, #0x20
	strb r5, [r0]
	adds r0, #0x6c
	strh r5, [r0, #0x10]
	movs r0, #0x9b
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r2, r4, #0
	adds r2, #0xbe
	ldrh r1, [r2]
	movs r0, #0x21
	orrs r0, r1
	strh r0, [r2]
	ldr r2, [r4, #0x28]
	cmp r2, #0
	beq _0800422C
	ldrh r0, [r4, #0x2c]
	str r0, [sp]
	ldrb r0, [r4]
	str r0, [sp, #4]
	movs r1, #0x34
	ldrsh r0, [r4, r1]
	str r0, [sp, #8]
	movs r1, #0x36
	ldrsh r0, [r4, r1]
	str r0, [sp, #0xc]
	movs r1, #0x38
	ldrsh r0, [r4, r1]
	str r0, [sp, #0x10]
	ldr r1, _0800425C @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r1
	movs r1, #5
	orrs r0, r1
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	mov r0, sp
	str r0, [r1, #4]
	adds r0, r2, #0
	bl Script_ExecById
	str r5, [r4, #0x28]
_0800422C:
	adds r2, r4, #0
	adds r2, #0x20
	ldrb r0, [r2]
	adds r5, r2, #0
	cmp r0, #0
	bne _08004280
	ldrh r0, [r4, #2]
	movs r1, #2
	bl Mod
	adds r1, r0, #0
	cmp r1, #0
	bne _08004266
	adds r0, r4, #0
	adds r0, #0x9c
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _08004260
	adds r1, r4, #0
	adds r1, #0x8c
	movs r0, #1
	strh r0, [r1, #0x10]
	b _08004266
	.align 2, 0
_0800425C: .4byte 0xFFFF0000
_08004260:
	adds r0, r4, #0
	adds r0, #0x8c
	strh r1, [r0, #0x10]
_08004266:
	ldrh r0, [r4, #2]
	adds r1, r0, #1
	strh r1, [r4, #2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _080042AE
	movs r0, #0
	strh r0, [r4, #2]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _080042AE
_08004280:
	ldrh r0, [r4, #2]
	adds r1, r0, #1
	strh r1, [r4, #2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _080042AE
	movs r0, #0
	strh r0, [r4, #2]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _080042A6
	movs r0, #2
	strb r0, [r4, #0x19]
	b _080042AE
_080042A6:
	ldrb r1, [r2]
	adds r0, r4, #0
	adds r0, #0x8c
	strh r1, [r0, #0x10]
_080042AE:
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080042b8
FUN_080042b8: @ 0x080042B8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	beq _080042DA
	movs r0, #0
	strb r0, [r4, #0x11]
	adds r0, r4, #0
	adds r0, #0x20
	movs r1, #3
	strb r1, [r0]
	adds r0, #0x6c
	strh r1, [r0, #0x10]
	movs r0, #0x9b
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080042DA:
	adds r3, r4, #0
	adds r3, #0x20
	ldrb r2, [r3]
	cmp r2, #0
	beq _08004306
	ldrh r0, [r4, #2]
	adds r1, r0, #1
	strh r1, [r4, #2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _08004318
	movs r0, #0
	strh r0, [r4, #2]
	ldrb r0, [r3]
	subs r0, #1
	strb r0, [r3]
	ldrb r1, [r3]
	adds r0, r4, #0
	adds r0, #0x8c
	strh r1, [r0, #0x10]
	b _08004318
_08004306:
	ldr r0, _08004320 @ =FUN_08003f38
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r1, r4, r3
	str r0, [r1]
	strh r2, [r4, #2]
	movs r0, #1
	strb r0, [r4, #0x11]
	strh r2, [r4, #4]
_08004318:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08004320: .4byte FUN_08003f38

	thumb_func_start EntityD9AE_Update
EntityD9AE_Update: @ 0x08004324
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x20
	adds r6, r0, #0
	ldr r5, [r6, #0x70]
	movs r0, #0
	mov r8, r0
	ldrh r1, [r6, #0x18]
	cmp r8, r1
	blt _0800433E
	b _080044E8
_0800433E:
	adds r7, r5, #0
	adds r7, #0xce
	mov sb, r0
	adds r4, r5, #0
	adds r4, #0x18
_08004348:
	ldrb r0, [r4, #6]
	cmp r0, #0
	bne _08004350
	b _080044D2
_08004350:
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _080043C0
	cmp r0, #3
	bne _0800436E
	ldr r1, _080043B8 @ =0x085AA658
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0800436E
	adds r0, r5, #0
	bl _call_via_r1
_0800436E:
	ldr r0, [r4, #0x10]
	cmp r0, #0
	beq _080043AA
	ldrh r0, [r4, #0x14]
	str r0, [sp, #4]
	ldrb r0, [r5]
	str r0, [sp, #8]
	movs r2, #0x1c
	ldrsh r0, [r4, r2]
	str r0, [sp, #0xc]
	movs r1, #0x1e
	ldrsh r0, [r4, r1]
	str r0, [sp, #0x10]
	movs r2, #0x20
	ldrsh r0, [r4, r2]
	str r0, [sp, #0x14]
	ldr r1, _080043BC @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r1
	movs r1, #5
	orrs r0, r1
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	add r0, sp, #4
	str r0, [r1, #4]
	ldr r0, [r4, #0x10]
	bl Script_ExecById
	mov r1, sb
	str r1, [r4, #0x10]
_080043AA:
	adds r0, r5, #0
	bl FUN_080035e4
	adds r0, r5, #0
	bl FUN_080036a0
	b _080044D2
	.align 2, 0
_080043B8: .4byte 0x085AA658
_080043BC: .4byte 0xFFFF0000
_080043C0:
	adds r0, r5, #0
	adds r0, #0x2c
	bl FUN_0823b4b8
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _080043DA
	adds r0, r5, #0
	bl _call_via_r1
_080043DA:
	ldrb r1, [r5, #1]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800440E
	ldrh r0, [r5, #4]
	cmp r0, #0
	bne _08004404
	ldrh r0, [r4, #0x16]
	ldr r2, _08004400 @ =0x0000FFFD
	adds r1, r2, #0
	ands r0, r1
	strh r0, [r4, #0x16]
	movs r1, #0xb4
	lsls r1, r1, #1
	adds r0, r5, r1
	bl FUN_08234660
	b _08004418
	.align 2, 0
_08004400: .4byte 0x0000FFFD
_08004404:
	ldrh r0, [r4, #0x16]
	movs r1, #2
	orrs r0, r1
	strh r0, [r4, #0x16]
	b _08004418
_0800440E:
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r0, r5, r2
	bl FUN_08234660
_08004418:
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08004422
	subs r0, #1
	strb r0, [r4, #9]
_08004422:
	ldr r1, [r5, #8]
	cmp r1, #0
	beq _08004446
	ldr r0, _0800443C @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r0, r1
	bne _08004440
	movs r0, #1
	b _08004442
	.align 2, 0
_0800443C: .4byte 0x030046A0
_08004440:
	movs r0, #0
_08004442:
	cmp r0, #0
	beq _08004450
_08004446:
	ldr r0, [r4, #0x74]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _08004456
_08004450:
	ldr r0, [r4, #0x74]
	movs r1, #1
	orrs r0, r1
_08004456:
	str r0, [r4, #0x74]
	ldrb r1, [r4]
	cmp r1, #0
	bne _08004466
	movs r2, #0x16
	ldrsh r0, [r5, r2]
	cmp r0, #0
	bgt _0800446C
_08004466:
	subs r0, r1, #1
	strb r0, [r4]
	b _080044B0
_0800446C:
	ldr r1, [r5, #8]
	cmp r1, #0
	beq _08004492
	ldr r0, _08004488 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r0, r1
	bne _0800448C
	movs r0, #1
	b _0800448E
	.align 2, 0
_08004488: .4byte 0x030046A0
_0800448C:
	movs r0, #0
_0800448E:
	cmp r0, #0
	beq _080044B0
_08004492:
	ldrh r0, [r7]
	ldr r2, _080044AC @ =0x0000FFFB
	adds r1, r2, #0
	ands r0, r1
	strh r0, [r7]
	adds r0, r5, #0
	adds r0, #0xc8
	adds r1, r5, #0
	adds r1, #0x34
	movs r2, #0
	bl FUN_082364c4
	b _080044B8
	.align 2, 0
_080044AC: .4byte 0x0000FFFB
_080044B0:
	ldrh r0, [r7]
	movs r1, #4
	orrs r0, r1
	strh r0, [r7]
_080044B8:
	ldrb r0, [r4, #7]
	cmp r0, #0
	beq _080044D2
	subs r0, #1
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080044D2
	adds r0, r5, #0
	adds r0, #0x70
	ldrh r1, [r4, #2]
	bl FUN_0822b20c
_080044D2:
	movs r0, #1
	add r8, r0
	movs r1, #0xce
	lsls r1, r1, #1
	adds r7, r7, r1
	adds r4, r4, r1
	adds r5, r5, r1
	ldrh r2, [r6, #0x18]
	cmp r8, r2
	bge _080044E8
	b _08004348
_080044E8:
	ldrb r0, [r6, #0x1e]
	cmp r0, #0
	beq _0800454E
	adds r0, r6, #0
	adds r0, #0x30
	ldr r1, [r6, #0x20]
	ldr r2, [r6, #0x28]
	movs r4, #0x1c
	ldrsh r3, [r6, r4]
	movs r4, #5
	str r4, [sp]
	bl rgb555_08237468
	adds r0, r6, #0
	adds r0, #0x50
	ldr r1, [r6, #0x24]
	ldr r2, [r6, #0x2c]
	movs r5, #0x1c
	ldrsh r3, [r6, r5]
	str r4, [sp]
	bl rgb555_08237468
	ldrb r0, [r6, #0x1b]
	cmp r0, #0
	bne _08004532
	ldrh r0, [r6, #0x1c]
	adds r0, #1
	strh r0, [r6, #0x1c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1f
	ble _0800454E
	movs r0, #0x20
	strh r0, [r6, #0x1c]
	movs r0, #1
	strb r0, [r6, #0x1b]
	b _0800454E
_08004532:
	ldrh r0, [r6, #0x1c]
	subs r0, #1
	movs r1, #0
	strh r0, [r6, #0x1c]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0800454E
	movs r0, #0
	strh r0, [r6, #0x1c]
	strb r1, [r6, #0x1b]
	ldrb r0, [r6, #0x1f]
	cmp r0, #0
	beq _0800454E
	strb r1, [r6, #0x1f]
_0800454E:
	ldrb r1, [r6, #0x1a]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r6, #0x1a]
	movs r0, #0
	add sp, #0x20
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityD9AE_Destroy
EntityD9AE_Destroy: @ 0x08004568
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080036e0
	ldr r0, [r4, #0x70]
	bl Free
	ldr r1, _08004584 @ =0x03000020
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08004584: .4byte 0x03000020

	thumb_func_start EntityD9AE_Init
EntityD9AE_Init: @ 0x08004588
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080045F8 @ =0x03000020
	str r5, [r0]
	ldrh r0, [r5, #0x18]
	cmp r0, #0
	bne _0800459A
	movs r0, #8
	strh r0, [r5, #0x18]
_0800459A:
	ldrh r0, [r5, #0x18]
	movs r4, #0xce
	lsls r4, r4, #1
	muls r0, r4, r0
	bl Malloc
	adds r2, r0, #0
	str r2, [r5, #0x70]
	cmp r2, #0
	beq _08004604
	ldrh r0, [r5, #0x18]
	adds r1, r0, #0
	muls r1, r4, r1
	adds r0, r2, #0
	bl ClearMemory
	movs r0, #0
	strb r0, [r5, #0x1a]
	strb r0, [r5, #0x1e]
	strb r0, [r5, #0x1b]
	strh r0, [r5, #0x1c]
	ldr r0, _080045FC @ =0x03003584
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x40
	str r0, [r5, #0x20]
	adds r0, #0x20
	str r0, [r5, #0x24]
	adds r0, #0x20
	str r0, [r5, #0x28]
	adds r1, #0xa0
	str r1, [r5, #0x2c]
	adds r1, r5, #0
	adds r1, #0x30
	ldr r4, _08004600 @ =0x04000008
	adds r2, r4, #0
	bl CpuSet
	ldr r0, [r5, #0x2c]
	adds r1, r5, #0
	adds r1, #0x50
	adds r2, r4, #0
	bl CpuSet
	movs r0, #0
	b _08004608
	.align 2, 0
_080045F8: .4byte 0x03000020
_080045FC: .4byte 0x03003584
_08004600: .4byte 0x04000008
_08004604:
	movs r0, #1
	rsbs r0, r0, #0
_08004608:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityD9AE_Create
EntityD9AE_Create: @ 0x08004610
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08004654 @ =0x03000020
	ldr r0, [r0]
	cmp r0, #0
	bne _08004662
	movs r0, #8
	movs r1, #0x74
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08004660
	ldr r1, _08004658 @ =EntityD9AE_Update
	ldr r2, _0800465C @ =EntityD9AE_Destroy
	bl SetEntityRoutine
	movs r0, #0x6d
	movs r1, #8
	bl Script_GetKeywordValue
	strh r0, [r4, #0x18]
	adds r0, r4, #0
	adds r1, r5, #0
	bl EntityD9AE_Init
	cmp r0, #0
	bge _08004660
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08004662
	.align 2, 0
_08004654: .4byte 0x03000020
_08004658: .4byte EntityD9AE_Update
_0800465C: .4byte EntityD9AE_Destroy
_08004660:
	adds r0, r4, #0
_08004662:
	pop {r4, r5}
	pop {r1}
	bx r1
