	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08068D42
	cmp r1, #0
	blt _08068D42
	ldr r0, _08068D48 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08068D42
	ldr r0, _08068D4C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08068D50
_08068D42:
	movs r4, #0
	b _08068D5E
	.align 2, 0
_08068D48: .4byte 0x030046A8
_08068D4C: .4byte 0x030046AC
_08068D50:
	ldr r0, _08068D70 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08068D5E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08068D74
	adds r0, #4
	b _08068D80
	.align 2, 0
_08068D70: .4byte 0x030046A4
_08068D74:
	ldr r0, _08068DCC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08068D80:
	ldrh r5, [r0, #2]
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	bne _08068E38
	bl FUN_08086958
	cmp r0, #0
	bne _08068DA4
	adds r0, r5, #0
	bl FUN_08065ad0
	cmp r0, #0
	bne _08068E38
	movs r0, #0x40
	ands r0, r5
	cmp r0, #0
	bne _08068E38
_08068DA4:
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08068DC8
	cmp r1, #0
	blt _08068DC8
	ldr r0, _08068DD0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08068DC8
	ldr r0, _08068DD4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08068DD8
_08068DC8:
	movs r4, #0
	b _08068DE6
	.align 2, 0
_08068DCC: .4byte 0x030046A4
_08068DD0: .4byte 0x030046A8
_08068DD4: .4byte 0x030046AC
_08068DD8:
	ldr r0, _08068DF8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08068DE6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08068DFC
	adds r0, #4
	b _08068E08
	.align 2, 0
_08068DF8: .4byte 0x030046A4
_08068DFC:
	ldr r0, _08068E1C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08068E08:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08068E20
	cmp r2, #2
	beq _08068E24
	b _08068E28
	.align 2, 0
_08068E1C: .4byte 0x030046A4
_08068E20:
	ldrb r0, [r6, #4]
	b _08068E26
_08068E24:
	ldrb r0, [r6]
_08068E26:
	subs r1, r1, r0
_08068E28:
	movs r2, #0x2e
	ldrsh r0, [r7, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _08068E34
	rsbs r0, r0, #0
_08068E34:
	cmp r0, #0xff
	ble _08068E3C
_08068E38:
	movs r0, #0
	b _08068E8E
_08068E3C:
	movs r0, #0x80
	lsls r0, r0, #4
	ands r5, r0
	cmp r5, #0
	beq _08068E8C
	bl FUN_080865c0
	adds r4, r0, #0
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r2, #0x2c
	ldrsh r0, [r7, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _08068E5C
	rsbs r1, r1, #0
_08068E5C:
	cmp r1, #0xff
	bgt _08068E74
	movs r0, #4
	ldrsh r1, [r4, r0]
	movs r2, #0x30
	ldrsh r0, [r7, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _08068E70
	rsbs r1, r1, #0
_08068E70:
	cmp r1, #0xff
	ble _08068E84
_08068E74:
	movs r0, #0xda
	bl PlaySound_082406e0
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_08068E84:
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r6]
	str r1, [r6, #4]
_08068E8C:
	movs r0, #1
_08068E8E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
