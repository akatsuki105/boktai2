	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _08082BF6
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	bl FUN_08080e0c
_08082BF6:
	adds r0, r4, #0
	movs r1, #0x1c
	bl FUN_08080ec8
	movs r2, #0x82
	lsls r2, r2, #2
	adds r3, r4, r2
	movs r5, #0
	ldrsh r1, [r3, r5]
	movs r2, #0x2c
	ldrsh r0, [r4, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _08082C14
	rsbs r0, r0, #0
_08082C14:
	adds r6, r0, #0
	movs r5, #0x83
	lsls r5, r5, #2
	adds r2, r4, r5
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r5, #0x30
	ldrsh r0, [r4, r5]
	subs r1, r1, r0
	cmp r1, #0
	bge _08082C2C
	rsbs r1, r1, #0
_08082C2C:
	adds r5, r1, #0
	cmp r6, #0x1f
	bgt _08082C84
	cmp r5, #0x1f
	bgt _08082C84
	ldr r0, _08082C78 @ =0x000003F2
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldrh r0, [r3]
	strh r0, [r4, #0x2c]
	ldrh r0, [r2]
	strh r0, [r4, #0x30]
	ldr r1, _08082C7C @ =0x000001A3
	adds r0, r4, #0
	movs r2, #0x20
	bl FUN_08080cac
	ldr r1, _08082C80 @ =0x00000471
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_08080c64
	movs r5, #0x8e
	lsls r5, r5, #3
	adds r0, r4, r5
	ldrb r1, [r0]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08080e0c
	b _08082DA0
	.align 2, 0
_08082C78: .4byte 0x000003F2
_08082C7C: .4byte 0x000001A3
_08082C80: .4byte 0x00000471
_08082C84:
	ldr r0, _08082CAC @ =0x0000095E
	adds r1, r4, r0
	ldr r0, _08082CB0 @ =0x00000127
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r4, r2
	movs r0, #0x18
	strh r0, [r1]
	cmp r6, #0xbf
	bgt _08082C9E
	cmp r5, #0xbf
	ble _08082CB8
_08082C9E:
	ldr r5, _08082CB4 @ =0x000003F2
	adds r1, r4, r5
	ldrb r0, [r1]
	cmp r0, #4
	bhi _08082CC6
	adds r0, #1
	b _08082CC4
	.align 2, 0
_08082CAC: .4byte 0x0000095E
_08082CB0: .4byte 0x00000127
_08082CB4: .4byte 0x000003F2
_08082CB8:
	ldr r0, _08082CDC @ =0x000003F2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08082CC6
	subs r0, #1
_08082CC4:
	strb r0, [r1]
_08082CC6:
	ldr r1, _08082CDC @ =0x000003F2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _08082CE0
	adds r0, r4, #0
	movs r1, #3
	bl FUN_08080ec8
	b _08082CEC
	.align 2, 0
_08082CDC: .4byte 0x000003F2
_08082CE0:
	cmp r0, #0
	beq _08082CEC
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08080ec8
_08082CEC:
	movs r2, #0x86
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r2, #0x2c
	ldrsh r0, [r4, r2]
	subs r6, r1, r0
	movs r5, #0x87
	lsls r5, r5, #2
	adds r0, r4, r5
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0x30
	ldrsh r0, [r4, r5]
	subs r5, r1, r0
	adds r0, r6, #0
	adds r1, r5, #0
	bl ArcTan2_8
	adds r3, r0, #0
	ldr r2, _08082D30 @ =0x085B0A08
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _08082D34
	asrs r0, r0, #0xc
	b _08082D3A
	.align 2, 0
_08082D30: .4byte 0x085B0A08
_08082D34:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08082D3A:
	strh r0, [r4, #0x34]
	ldr r0, _08082D54 @ =0x085B0A08
	movs r1, #0xff
	ands r1, r3
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #5
	cmp r0, #0
	blt _08082D58
	asrs r0, r0, #0xc
	b _08082D5E
	.align 2, 0
_08082D54: .4byte 0x085B0A08
_08082D58:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08082D5E:
	strh r0, [r4, #0x38]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_08235fd8
	cmp r0, #0
	beq _08082D96
	adds r0, r6, #0
	adds r1, r5, #0
	bl ArcTan2_8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_08080c64
_08082D96:
	ldr r1, _08082DA8 @ =0x000001A3
	adds r0, r4, #0
	movs r2, #0x20
	bl FUN_08080cac
_08082DA0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08082DA8: .4byte 0x000001A3
