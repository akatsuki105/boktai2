	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xf5
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081DC3F2
	ldr r2, _081DC42C @ =0x000003D1
	adds r1, r5, r2
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, [r5, #0x18]
	movs r0, #3
	movs r2, #7
	bl Video_SetBGLayer
	movs r0, #0
	str r0, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r4, #0
	movs r6, #3
_081DC3C4:
	adds r0, r4, #0
	adds r0, #0x19
	adds r1, r4, #0
	adds r1, #0x16
	str r1, [sp]
	str r6, [sp, #4]
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl FUN_080e1238
	adds r4, #1
	cmp r4, #4
	ble _081DC3C4
	ldr r3, _081DC430 @ =0x000003D6
	adds r1, r5, r3
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r4, #0xf5
	lsls r4, r4, #2
	adds r0, r5, r4
	strb r2, [r0]
_081DC3F2:
	bl Sio_GetMultiId
	movs r2, #0xf2
	lsls r2, r2, #2
	adds r1, r5, r2
	str r0, [r1]
	ldr r3, _081DC434 @ =0x03002C68
	ldr r0, [r3]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #0
	beq _081DC40C
	ldrh r2, [r0, #0x1a]
_081DC40C:
	movs r4, #0xf3
	lsls r4, r4, #2
	adds r0, r5, r4
	str r2, [r0]
	movs r4, #0
	adds r2, r1, #0
	movs r0, #0xeb
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r6, #0
_081DC420:
	ldr r0, [r2]
	cmp r0, #0
	bge _081DC438
	strb r6, [r1]
	b _081DC44A
	.align 2, 0
_081DC42C: .4byte 0x000003D1
_081DC430: .4byte 0x000003D6
_081DC434: .4byte 0x03002C68
_081DC438:
	ldr r0, [r3]
	cmp r0, #0
	bne _081DC442
	movs r0, #0
	b _081DC448
_081DC442:
	adds r0, #0x68
	adds r0, r0, r4
	ldrb r0, [r0]
_081DC448:
	strb r0, [r1]
_081DC44A:
	adds r1, #4
	adds r4, #1
	cmp r4, #3
	ble _081DC420
	adds r0, r5, #0
	bl FUN_081dbea0
	adds r0, r5, #0
	bl FUN_081dba78
	adds r0, r5, #0
	bl FUN_081dc100
	movs r1, #0xf3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r2, _081DC484 @ =0x000003D2
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _081DC488 @ =0x000003D6
	adds r1, r5, r3
	ldrh r0, [r1]
	cmp r0, #0x3b
	bhi _081DC48C
	adds r0, #1
	strh r0, [r1]
	b _081DC524
	.align 2, 0
_081DC484: .4byte 0x000003D2
_081DC488: .4byte 0x000003D6
_081DC48C:
	ldr r0, _081DC4A0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DC4A4
	adds r0, #0x2c
	ldrb r0, [r0]
	cmp r0, #1
	bne _081DC4A4
	movs r0, #1
	b _081DC4A6
	.align 2, 0
_081DC4A0: .4byte 0x03002C68
_081DC4A4:
	movs r0, #0
_081DC4A6:
	cmp r0, #0
	bne _081DC506
	ldr r0, _081DC4DC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081DC4E4
	ldr r1, _081DC4E0 @ =FUN_081dc350
	movs r2, #1
	movs r4, #0xef
	lsls r4, r4, #2
	adds r0, r5, r4
	str r1, [r0]
	movs r1, #0xf5
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r2, [r0]
	movs r3, #0xf4
	lsls r3, r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _081DC524
	.align 2, 0
_081DC4DC: .4byte 0x030044E0
_081DC4E0: .4byte FUN_081dc350
_081DC4E4:
	movs r4, #0
	movs r5, #3
_081DC4E8:
	adds r0, r4, #0
	adds r0, #0x19
	adds r1, r4, #0
	adds r1, #0x16
	str r1, [sp]
	str r5, [sp, #4]
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl FUN_080e1238
	adds r4, #1
	cmp r4, #4
	ble _081DC4E8
	b _081DC524
_081DC506:
	movs r4, #0
	movs r6, #1
	movs r5, #3
_081DC50C:
	adds r0, r4, #0
	adds r0, #0x19
	str r6, [sp]
	str r5, [sp, #4]
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl FUN_080e1238
	adds r4, #1
	cmp r4, #4
	ble _081DC50C
_081DC524:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
