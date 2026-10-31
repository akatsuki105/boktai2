	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r7, #0
	movs r4, #0
	adds r3, r5, #0
	adds r3, #0xce
	movs r0, #0x1c
	adds r0, r0, r5
	mov ip, r0
_081D2A76:
	ldr r1, _081D2A8C @ =0x000012AC
	adds r0, r5, r1
	movs r1, #1
	lsls r1, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D2A90
	movs r0, #1
	b _081D2A92
	.align 2, 0
_081D2A8C: .4byte 0x000012AC
_081D2A90:
	movs r0, #0
_081D2A92:
	cmp r0, #0
	beq _081D2B10
	movs r0, #0
	ldrsh r2, [r3, r0]
	cmp r2, #6
	beq _081D2B10
	ldrh r1, [r3, #0x24]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _081D2B10
	cmp r2, #1
	beq _081D2AE0
	ldr r1, _081D2AD4 @ =0x000012B4
	adds r4, r5, r1
	ldrb r0, [r4]
	cmp r0, #1
	beq _081D2AB8
	b _081D2BFC
_081D2AB8:
	movs r0, #0xa2
	lsls r0, r0, #2
	bl sound_08240740
	ldr r0, _081D2AD8 @ =0x0000028A
	bl sound_08240740
	ldr r0, _081D2ADC @ =0x00000289
	bl sound_08240740
	movs r0, #0
	strb r0, [r4]
	b _081D2BFC
	.align 2, 0
_081D2AD4: .4byte 0x000012B4
_081D2AD8: .4byte 0x0000028A
_081D2ADC: .4byte 0x00000289
_081D2AE0:
	ldr r1, _081D2B00 @ =0x000012B4
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081D2AEC
	b _081D2BFC
_081D2AEC:
	mov r0, ip
	adds r0, #0xe7
	ldrb r0, [r0]
	cmp r0, #0
	beq _081D2B08
	cmp r0, #3
	beq _081D2BC4
	ldr r0, _081D2B04 @ =0x00000289
	b _081D2BC8
	.align 2, 0
_081D2B00: .4byte 0x000012B4
_081D2B04: .4byte 0x00000289
_081D2B08:
	ldr r0, _081D2B0C @ =0x0000028A
	b _081D2BC8
	.align 2, 0
_081D2B0C: .4byte 0x0000028A
_081D2B10:
	movs r1, #0xc6
	lsls r1, r1, #1
	adds r3, r3, r1
	add ip, r1
	adds r4, #1
	cmp r4, #0xb
	ble _081D2A76
	ldr r4, _081D2B84 @ =0x03002BE0
	ldr r0, [r4]
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	beq _081D2B2E
	movs r7, #1
_081D2B2E:
	ldr r0, [r4]
	ldr r1, _081D2B88 @ =0x00000392
	adds r0, r0, r1
	ldrh r0, [r0]
	bl Elevator_FindByID
	adds r2, r0, #0
	cmp r2, #0
	beq _081D2BFC
	adds r0, #0xd6
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	cmp r6, #0
	bne _081D2BFC
	cmp r7, #0
	beq _081D2BDC
	adds r0, r2, #0
	adds r0, #0xb2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	beq _081D2B98
	ldr r0, _081D2B8C @ =0x000012B4
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #1
	bne _081D2BFC
	movs r0, #0xa2
	lsls r0, r0, #2
	bl sound_08240740
	ldr r0, _081D2B90 @ =0x0000028A
	bl sound_08240740
	ldr r0, _081D2B94 @ =0x00000289
	bl sound_08240740
	strb r6, [r4]
	b _081D2BFC
	.align 2, 0
_081D2B84: .4byte 0x03002BE0
_081D2B88: .4byte 0x00000392
_081D2B8C: .4byte 0x000012B4
_081D2B90: .4byte 0x0000028A
_081D2B94: .4byte 0x00000289
_081D2B98:
	ldr r1, _081D2BB4 @ =0x000012B4
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081D2BFC
	adds r0, r2, #0
	adds r0, #0xe7
	ldrb r0, [r0]
	cmp r0, #0
	beq _081D2BBC
	cmp r0, #3
	beq _081D2BC4
	ldr r0, _081D2BB8 @ =0x00000289
	b _081D2BC8
	.align 2, 0
_081D2BB4: .4byte 0x000012B4
_081D2BB8: .4byte 0x00000289
_081D2BBC:
	ldr r0, _081D2BC0 @ =0x0000028A
	b _081D2BC8
	.align 2, 0
_081D2BC0: .4byte 0x0000028A
_081D2BC4:
	movs r0, #0xa2
	lsls r0, r0, #2
_081D2BC8:
	bl PlaySound_082406e0
	ldr r0, _081D2BD8 @ =0x000012B4
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _081D2BFC
	.align 2, 0
_081D2BD8: .4byte 0x000012B4
_081D2BDC:
	ldr r1, _081D2C04 @ =0x000012B4
	adds r4, r5, r1
	ldrb r0, [r4]
	cmp r0, #1
	bne _081D2BFC
	movs r0, #0xa2
	lsls r0, r0, #2
	bl sound_08240740
	ldr r0, _081D2C08 @ =0x0000028A
	bl sound_08240740
	ldr r0, _081D2C0C @ =0x00000289
	bl sound_08240740
	strb r7, [r4]
_081D2BFC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D2C04: .4byte 0x000012B4
_081D2C08: .4byte 0x0000028A
_081D2C0C: .4byte 0x00000289
