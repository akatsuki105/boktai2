	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r5, _0822EF28 @ =0x030044A4
	ldr r0, [r5]
	cmp r0, #0
	bne _0822EF08
	b _0822F0AC
_0822EF08:
	bl FUN_0822ee74
	adds r7, r0, #0
	ldr r0, _0822EF2C @ =0x0400001C
	mov ip, r0
	ldr r0, _0822EF30 @ =0x030044A8
	ldr r0, [r0]
	cmp r0, #1
	beq _0822EFB8
	cmp r0, #1
	bgt _0822EF34
	cmp r0, #0
	beq _0822EF58
	mov sb, r5
	b _0822EFF4
	.align 2, 0
_0822EF28: .4byte 0x030044A4
_0822EF2C: .4byte 0x0400001C
_0822EF30: .4byte 0x030044A8
_0822EF34:
	cmp r0, #2
	beq _0822F018
	cmp r0, #3
	bne _0822EF3E
	b _0822F054
_0822EF3E:
	mov sb, r5
	ldr r0, _0822EF4C @ =0x03002CA0
	mov sl, r0
	ldr r1, _0822EF50 @ =0x03003510
	mov r8, r1
	ldr r6, _0822EF54 @ =0x03003514
	b _0822F094
	.align 2, 0
_0822EF4C: .4byte 0x03002CA0
_0822EF50: .4byte 0x03003510
_0822EF54: .4byte 0x03003514
_0822EF58:
	ldr r4, _0822EFA0 @ =0x030044A0
	ldr r0, [r4]
	bl FUN_0822ee7c
	mov ip, r0
	ldr r2, _0822EFA4 @ =0x03003ED0
	ldr r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r0, r2
	ldrh r0, [r0, #0x20]
	ldr r1, _0822EFA8 @ =0x000001FF
	adds r4, r1, #0
	ands r4, r0
	movs r3, #0
	adds r6, r1, #0
	mov sb, r5
	adds r2, r7, #0
_0822EF7E:
	lsls r0, r3, #1
	ldr r1, [r5]
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r4
	ands r0, r6
	strh r0, [r2]
	adds r2, #2
	adds r3, #1
	cmp r3, #0x9f
	ble _0822EF7E
	ldr r2, _0822EFAC @ =0x03002CA0
	mov sl, r2
	ldr r0, _0822EFB0 @ =0x03003510
	mov r8, r0
	ldr r6, _0822EFB4 @ =0x03003514
	b _0822F094
	.align 2, 0
_0822EFA0: .4byte 0x030044A0
_0822EFA4: .4byte 0x03003ED0
_0822EFA8: .4byte 0x000001FF
_0822EFAC: .4byte 0x03002CA0
_0822EFB0: .4byte 0x03003510
_0822EFB4: .4byte 0x03003514
_0822EFB8:
	ldr r4, _0822F000 @ =0x030044A0
	ldr r0, [r4]
	bl FUN_0822eeb8
	mov ip, r0
	ldr r2, _0822F004 @ =0x03003ED0
	ldr r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r0, r2
	ldrh r0, [r0, #0x22]
	ldr r1, _0822F008 @ =0x000001FF
	adds r4, r1, #0
	ands r4, r0
	movs r3, #0
	adds r6, r1, #0
	mov sb, r5
	adds r2, r7, #0
_0822EFDE:
	lsls r0, r3, #1
	ldr r1, [r5]
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r4
	ands r0, r6
	strh r0, [r2]
	adds r2, #2
	adds r3, #1
	cmp r3, #0x9f
	ble _0822EFDE
_0822EFF4:
	ldr r1, _0822F00C @ =0x03002CA0
	mov sl, r1
	ldr r2, _0822F010 @ =0x03003510
	mov r8, r2
	ldr r6, _0822F014 @ =0x03003514
	b _0822F094
	.align 2, 0
_0822F000: .4byte 0x030044A0
_0822F004: .4byte 0x03003ED0
_0822F008: .4byte 0x000001FF
_0822F00C: .4byte 0x03002CA0
_0822F010: .4byte 0x03003510
_0822F014: .4byte 0x03003514
_0822F018:
	ldr r0, _0822F044 @ =0x0400004C
	mov ip, r0
	movs r3, #0
	mov sb, r5
	ldr r1, _0822F048 @ =0x03002CA0
	mov sl, r1
	ldr r2, _0822F04C @ =0x03003510
	mov r8, r2
	ldr r6, _0822F050 @ =0x03003514
	mov r4, sb
	adds r2, r7, #0
_0822F02E:
	lsls r0, r3, #1
	ldr r1, [r4]
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r3, #1
	cmp r3, #0x9f
	ble _0822F02E
	b _0822F094
	.align 2, 0
_0822F044: .4byte 0x0400004C
_0822F048: .4byte 0x03002CA0
_0822F04C: .4byte 0x03003510
_0822F050: .4byte 0x03003514
_0822F054:
	ldr r1, _0822F0BC @ =0x04000052
	movs r2, #0x81
	lsls r2, r2, #4
	adds r0, r2, #0
	strh r0, [r1]
	subs r1, #2
	ldr r2, _0822F0C0 @ =0x00000EDE
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _0822F0C4 @ =0x04000054
	mov ip, r0
	movs r3, #0
	mov sb, r5
	ldr r1, _0822F0C8 @ =0x03002CA0
	mov sl, r1
	ldr r2, _0822F0CC @ =0x03003510
	mov r8, r2
	ldr r6, _0822F0D0 @ =0x03003514
	mov r4, sb
	movs r5, #0x1f
	adds r2, r7, #0
_0822F07E:
	lsls r0, r3, #1
	ldr r1, [r4]
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	ands r0, r1
	strh r0, [r2]
	adds r2, #2
	adds r3, #1
	cmp r3, #0x9f
	ble _0822F07E
_0822F094:
	ldr r0, _0822F0D4 @ =0x03003518
	str r7, [r0]
	mov r1, ip
	mov r2, sl
	str r1, [r2]
	movs r0, #1
	mov r1, r8
	strh r0, [r1]
	strh r0, [r6]
	movs r0, #0
	mov r2, sb
	str r0, [r2]
_0822F0AC:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822F0BC: .4byte 0x04000052
_0822F0C0: .4byte 0x00000EDE
_0822F0C4: .4byte 0x04000054
_0822F0C8: .4byte 0x03002CA0
_0822F0CC: .4byte 0x03003510
_0822F0D0: .4byte 0x03003514
_0822F0D4: .4byte 0x03003518
