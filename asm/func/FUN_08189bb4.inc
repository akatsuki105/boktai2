	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x48
	adds r7, r0, #0
	str r1, [sp, #0x44]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, _08189BE0 @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08189BE4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08189BE6
	.align 2, 0
_08189BE0: .4byte 0x0000046D
_08189BE4:
	movs r0, #0
_08189BE6:
	ldr r1, _08189C34 @ =0x00000F2C
	add r1, sb
	mov sl, r1
	cmp r0, #0
	bne _08189BF2
	b _08189D50
_08189BF2:
	ldrb r0, [r7, #5]
	add r2, sp, #0x18
	add r1, sp, #0x14
	bl Serpent_GetAnimVariant
	movs r2, #0xa1
	lsls r2, r2, #3
	adds r0, r7, r2
	ldrb r2, [r0]
	ldr r3, [sp, #0x14]
	ldr r4, [sp, #0x18]
	ldr r1, _08189C38 @ =0x0000025D
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08189C44
	ldr r1, _08189C3C @ =0x000004B7
	adds r0, r7, r1
	strb r2, [r0]
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl AuxAnim_SetAnim
	ldr r2, _08189C40 @ =0x0000046E
	adds r6, r7, r2
	b _08189CC6
	.align 2, 0
_08189C34: .4byte 0x00000F2C
_08189C38: .4byte 0x0000025D
_08189C3C: .4byte 0x000004B7
_08189C40: .4byte 0x0000046E
_08189C44:
	ldr r0, [r7, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r2, r2, r3
	ldr r1, _08189CB4 @ =0x000004B7
	adds r0, r7, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08189CB8 @ =0x0000046E
	adds r6, r7, r0
	cmp r1, r2
	bne _08189C7E
	ldrb r0, [r6]
	cmp r0, #0
	bne _08189C7E
	cmp r4, #1
	bne _08189C70
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08189CCA
_08189C70:
	cmp r4, #0
	bne _08189C7E
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08189CCA
_08189C7E:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _08189C90
	movs r3, #6
_08189C90:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _08189CBC
	ldr r0, [r5, #8]
	mov r2, r8
	orrs r0, r2
	b _08189CC4
	.align 2, 0
_08189CB4: .4byte 0x000004B7
_08189CB8: .4byte 0x0000046E
_08189CBC:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08189CC4:
	str r0, [r5, #8]
_08189CC6:
	movs r0, #0
	strb r0, [r6]
_08189CCA:
	ldr r1, _08189CF8 @ =0x000001A3
	movs r2, #0xd4
	lsls r2, r2, #1
	adds r0, r7, #0
	movs r3, #0x80
	bl FUN_08192fe4
	ldr r2, _08189CFC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08189D00 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08189D04 @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _08189D0C
	ldr r1, _08189D08 @ =0x00000E3F
	add r1, sb
	movs r0, #1
	b _08189D12
	.align 2, 0
_08189CF8: .4byte 0x000001A3
_08189CFC: .4byte 0x030046B8
_08189D00: .4byte 0x000003FF
_08189D04: .4byte 0x0203B400
_08189D08: .4byte 0x00000E3F
_08189D0C:
	ldr r1, _08189D64 @ =0x00000E3F
	add r1, sb
	movs r0, #0
_08189D12:
	strb r0, [r1]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, _08189D68 @ =0x00000546
	adds r0, r7, r2
	ldr r2, _08189D6C @ =0x00000F2C
	add r2, sb
	mov sl, r2
	ldrh r0, [r0]
	cmp r1, r0
	bgt _08189D4A
	ldrb r0, [r7, #5]
	adds r0, #0x30
	ldr r1, _08189D70 @ =0x00000E3D
	add r1, sb
	strb r0, [r1]
	ldr r1, _08189D74 @ =0x00000E3C
	add r1, sb
	movs r0, #0xa
	strb r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #7
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08189D4A:
	ldr r0, _08189D78 @ =0x000003DE
	bl PlaySound_082406e0
_08189D50:
	movs r1, #0x80
	lsls r1, r1, #7
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08189D7C
	movs r0, #1
	b _08189D7E
	.align 2, 0
_08189D64: .4byte 0x00000E3F
_08189D68: .4byte 0x00000546
_08189D6C: .4byte 0x00000F2C
_08189D70: .4byte 0x00000E3D
_08189D74: .4byte 0x00000E3C
_08189D78: .4byte 0x000003DE
_08189D7C:
	movs r0, #0
_08189D7E:
	cmp r0, #0
	bne _08189D84
	b _08189F5A
_08189D84:
	ldr r0, _08189D98 @ =0x00000E3D
	add r0, sb
	ldrb r1, [r0]
	ldrb r0, [r7, #5]
	subs r4, r1, r0
	cmp r4, #0x80
	ble _08189DA0
	ldr r0, _08189D9C @ =0xFFFFFF00
	adds r4, r4, r0
	b _08189DAE
	.align 2, 0
_08189D98: .4byte 0x00000E3D
_08189D9C: .4byte 0xFFFFFF00
_08189DA0:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r4, r0
	bge _08189DAE
	movs r1, #0x80
	lsls r1, r1, #1
	adds r4, r4, r1
_08189DAE:
	ldr r0, [sp, #0x44]
	movs r1, #2
	bl Mod
	cmp r0, #0
	bne _08189E1C
	adds r0, r4, #0
	cmp r4, #0
	bge _08189DC2
	rsbs r0, r4, #0
_08189DC2:
	cmp r0, #7
	bgt _08189DEC
	ldr r1, _08189DE4 @ =0x00000E3D
	add r1, sb
	ldrb r0, [r1]
	strb r0, [r7, #5]
	ldr r2, [sp, #0x44]
	cmp r2, #0x30
	bgt _08189DFC
	subs r0, #0x66
	strb r0, [r1]
	ldr r1, _08189DE8 @ =0x00000E3C
	add r1, sb
	movs r0, #0xa
	strb r0, [r1]
	b _08189DFC
	.align 2, 0
_08189DE4: .4byte 0x00000E3D
_08189DE8: .4byte 0x00000E3C
_08189DEC:
	cmp r4, #0
	bge _08189DF6
	ldrb r0, [r7, #5]
	subs r0, #2
	b _08189DFA
_08189DF6:
	ldrb r0, [r7, #5]
	adds r0, #2
_08189DFA:
	strb r0, [r7, #5]
_08189DFC:
	ldr r0, _08189E0C @ =0x00000E3C
	add r0, sb
	ldrb r0, [r0]
	cmp r0, #0
	blt _08189E10
	asrs r1, r0, #1
	b _08189E16
	.align 2, 0
_08189E0C: .4byte 0x00000E3C
_08189E10:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_08189E16:
	ldr r0, _08189E44 @ =0x00000E3C
	add r0, sb
	strb r1, [r0]
_08189E1C:
	ldr r0, _08189E44 @ =0x00000E3C
	add r0, sb
	add r3, sp, #0x1c
	ldrb r4, [r7, #5]
	ldrb r5, [r0]
	ldr r2, _08189E48 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	adds r6, r3, #0
	cmp r0, #0
	blt _08189E4C
	asrs r1, r0, #0xc
	b _08189E52
	.align 2, 0
_08189E44: .4byte 0x00000E3C
_08189E48: .4byte gSineTable
_08189E4C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08189E52:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08189E6A
	asrs r0, r0, #0xc
	b _08189E70
_08189E6A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08189E70:
	strh r0, [r3, #4]
	ldrh r0, [r6]
	ldrh r1, [r7, #8]
	adds r0, r0, r1
	strh r0, [r7, #8]
	add r0, sp, #0x1c
	ldrh r0, [r0, #4]
	ldrh r2, [r7, #0xc]
	adds r0, r0, r2
	strh r0, [r7, #0xc]
	ldrb r0, [r7, #5]
	add r1, sp, #0x24
	add r2, sp, #0x28
	bl Serpent_GetAnimVariant
	movs r1, #0xa1
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrb r2, [r0]
	ldr r3, [sp, #0x24]
	ldr r4, [sp, #0x28]
	ldr r1, _08189EC8 @ =0x0000025D
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08189ED4
	ldr r1, _08189ECC @ =0x000004B7
	adds r0, r7, r1
	strb r2, [r0]
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl AuxAnim_SetAnim
	ldr r2, _08189ED0 @ =0x0000046E
	adds r6, r7, r2
	b _08189F56
	.align 2, 0
_08189EC8: .4byte 0x0000025D
_08189ECC: .4byte 0x000004B7
_08189ED0: .4byte 0x0000046E
_08189ED4:
	ldr r0, [r7, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r2, r2, r3
	ldr r1, _08189F44 @ =0x000004B7
	adds r0, r7, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08189F48 @ =0x0000046E
	adds r6, r7, r0
	cmp r1, r2
	bne _08189F0E
	ldrb r0, [r6]
	cmp r0, #0
	bne _08189F0E
	cmp r4, #1
	bne _08189F00
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08189F5A
_08189F00:
	cmp r4, #0
	bne _08189F0E
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08189F5A
_08189F0E:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _08189F20
	movs r3, #6
_08189F20:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _08189F4C
	ldr r0, [r5, #8]
	mov r2, r8
	orrs r0, r2
	b _08189F54
	.align 2, 0
_08189F44: .4byte 0x000004B7
_08189F48: .4byte 0x0000046E
_08189F4C:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08189F54:
	str r0, [r5, #8]
_08189F56:
	movs r0, #0
	strb r0, [r6]
_08189F5A:
	ldrb r0, [r7, #5]
	add r1, sp, #0x2c
	add r2, sp, #0x30
	bl Serpent_GetAnimVariant
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [sp, #0x34]
	str r1, [sp, #0x38]
	ldr r0, [sp, #0x2c]
	cmp r0, #4
	bls _08189F74
	b _0818A0A4
_08189F74:
	lsls r0, r0, #2
	ldr r1, _08189F80 @ =_08189F84
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08189F80: .4byte _08189F84
_08189F84: @ jump table
	.4byte _08189F98 @ case 0
	.4byte _08189FB8 @ case 1
	.4byte _08189FF8 @ case 2
	.4byte _0818A03C @ case 3
	.4byte _0818A080 @ case 4
_08189F98:
	add r2, sp, #0x34
	ldrh r1, [r2]
	subs r1, #0x52
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _08189FB4 @ =0xFFFF0000
	ldr r0, [sp, #0x34]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x34]
	ldrh r0, [r2, #4]
	subs r0, #0x60
	b _0818A098
	.align 2, 0
_08189FB4: .4byte 0xFFFF0000
_08189FB8:
	ldr r0, [sp, #0x30]
	cmp r0, #0
	beq _08189FD8
	add r0, sp, #0x34
	ldrh r1, [r0]
	subs r1, #0x80
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08189FD4 @ =0xFFFF0000
	ldr r0, [sp, #0x34]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x34]
	b _0818A0A4
	.align 2, 0
_08189FD4: .4byte 0xFFFF0000
_08189FD8:
	add r2, sp, #0x34
	ldrh r1, [r2]
	adds r1, #0x20
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _08189FF4 @ =0xFFFF0000
	ldr r0, [sp, #0x34]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x34]
	ldrh r0, [r2, #4]
	subs r0, #0x84
	b _0818A098
	.align 2, 0
_08189FF4: .4byte 0xFFFF0000
_08189FF8:
	ldr r0, [sp, #0x30]
	cmp r0, #0
	beq _0818A01C
	add r2, sp, #0x34
	ldrh r1, [r2]
	subs r1, #0x64
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _0818A018 @ =0xFFFF0000
	ldr r0, [sp, #0x34]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x34]
	ldrh r0, [r2, #4]
	adds r0, #0x52
	b _0818A098
	.align 2, 0
_0818A018: .4byte 0xFFFF0000
_0818A01C:
	add r2, sp, #0x34
	ldrh r1, [r2]
	adds r1, #0x80
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _0818A038 @ =0xFFFF0000
	ldr r0, [sp, #0x34]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x34]
	ldrh r0, [r2, #4]
	subs r0, #0x40
	b _0818A098
	.align 2, 0
_0818A038: .4byte 0xFFFF0000
_0818A03C:
	ldr r0, [sp, #0x30]
	cmp r0, #0
	beq _0818A05C
	add r3, sp, #0x34
	ldrh r1, [r3, #4]
	adds r1, #0x60
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0818A058 @ =0xFFFF0000
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r3, #4]
	b _0818A0A4
	.align 2, 0
_0818A058: .4byte 0xFFFF0000
_0818A05C:
	add r2, sp, #0x34
	ldrh r1, [r2]
	adds r1, #0x80
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _0818A07C @ =0xFFFF0000
	ldr r0, [sp, #0x34]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x34]
	ldrh r1, [r2, #4]
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #4]
	b _0818A0A4
	.align 2, 0
_0818A07C: .4byte 0xFFFF0000
_0818A080:
	add r2, sp, #0x34
	ldrh r1, [r2]
	adds r1, #0x40
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _0818A110 @ =0xFFFF0000
	ldr r0, [sp, #0x34]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x34]
	ldrh r0, [r2, #4]
	adds r0, #0x40
_0818A098:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r2, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [r2, #4]
_0818A0A4:
	ldr r0, _0818A114 @ =0x00000E3F
	add r0, sb
	ldrb r0, [r0]
	cmp r0, #0
	bne _0818A0B0
	b _0818A260
_0818A0B0:
	ldr r1, _0818A118 @ =0x00000484
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #8
	bl Mod
	cmp r0, #0
	beq _0818A0C2
	b _0818A416
_0818A0C2:
	ldr r5, _0818A11C @ =0x0203B400
	ldr r4, _0818A120 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _0818A124 @ =0x000003FF
	ands r0, r3
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r2, [r1]
	ldrb r6, [r7, #5]
	movs r1, #0x3f
	ands r2, r1
	adds r0, #1
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	add r3, sp, #0x3c
	adds r6, r6, r2
	subs r6, #0x10
	adds r4, r1, #0
	adds r4, #8
	ldr r2, _0818A128 @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _0818A12C
	asrs r1, r0, #0xc
	b _0818A132
	.align 2, 0
_0818A110: .4byte 0xFFFF0000
_0818A114: .4byte 0x00000E3F
_0818A118: .4byte 0x00000484
_0818A11C: .4byte 0x0203B400
_0818A120: .4byte 0x030046B8
_0818A124: .4byte 0x000003FF
_0818A128: .4byte gSineTable
_0818A12C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0818A132:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _0818A150 @ =gSineTable
	movs r0, #0xff
	ands r6, r0
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0818A154
	asrs r0, r0, #0xc
	b _0818A15A
	.align 2, 0
_0818A150: .4byte gSineTable
_0818A154:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0818A15A:
	strh r0, [r3, #4]
	add r2, sp, #0x34
	mov r8, r2
	movs r3, #0xc8
	lsls r3, r3, #1
	movs r0, #0xc
	str r0, [sp]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r0, [r0]
	str r0, [sp, #4]
	movs r2, #0x8c
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrh r0, [r0]
	str r0, [sp, #8]
	adds r1, #0x1c
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0xc]
	adds r2, #8
	adds r0, r7, r2
	ldrh r0, [r0]
	str r0, [sp, #0x10]
	mov r0, r8
	add r1, sp, #0x3c
	movs r2, #4
	bl Entity080df420_Spawn
	ldr r5, _0818A1E8 @ =0x0203B400
	ldr r4, _0818A1EC @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _0818A1F0 @ =0x000003FF
	ands r0, r3
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r2, [r1]
	ldrb r6, [r7, #5]
	movs r1, #0x3f
	ands r2, r1
	adds r0, #1
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	add r4, sp, #0x3c
	adds r6, r6, r2
	subs r6, #0x10
	adds r3, r1, #0
	adds r3, #8
	ldr r2, _0818A1F4 @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	mov r2, r8
	cmp r0, #0
	blt _0818A1F8
	asrs r1, r0, #0xc
	b _0818A1FE
	.align 2, 0
_0818A1E8: .4byte 0x0203B400
_0818A1EC: .4byte 0x030046B8
_0818A1F0: .4byte 0x000003FF
_0818A1F4: .4byte gSineTable
_0818A1F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0818A1FE:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _0818A21C @ =gSineTable
	movs r0, #0xff
	ands r6, r0
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _0818A220
	asrs r0, r0, #0xc
	b _0818A226
	.align 2, 0
_0818A21C: .4byte gSineTable
_0818A220:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0818A226:
	strh r0, [r4, #4]
	movs r3, #0xc8
	lsls r3, r3, #1
	movs r0, #0xc
	str r0, [sp]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r1, #8
	adds r0, r7, r1
	ldrh r0, [r0]
	str r0, [sp, #8]
	adds r1, #0x14
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0xc]
	subs r1, #0xc
	adds r0, r7, r1
	ldrh r0, [r0]
	str r0, [sp, #0x10]
	adds r0, r2, #0
	add r1, sp, #0x3c
	movs r2, #4
	bl Entity080df420_Spawn
	movs r0, #0x10
	b _0818A40A
_0818A260:
	ldr r2, _0818A2BC @ =0x00000484
	adds r0, r7, r2
	ldr r0, [r0]
	movs r1, #0xa
	bl Mod
	cmp r0, #0
	bne _0818A33A
	ldr r5, _0818A2C0 @ =0x0203B400
	ldr r4, _0818A2C4 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _0818A2C8 @ =0x000003FF
	ands r0, r3
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r2, [r1]
	ldrb r6, [r7, #5]
	movs r1, #0x3f
	ands r2, r1
	adds r0, #1
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	add r3, sp, #0x3c
	adds r6, r6, r2
	subs r6, #0x20
	adds r4, r1, #4
	ldr r2, _0818A2CC @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0818A2D0
	asrs r1, r0, #0xc
	b _0818A2D6
	.align 2, 0
_0818A2BC: .4byte 0x00000484
_0818A2C0: .4byte 0x0203B400
_0818A2C4: .4byte 0x030046B8
_0818A2C8: .4byte 0x000003FF
_0818A2CC: .4byte gSineTable
_0818A2D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0818A2D6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r6, r0
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _0818A2F2
	asrs r0, r0, #0xc
	b _0818A2F8
_0818A2F2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0818A2F8:
	strh r0, [r3, #4]
	add r0, sp, #0x34
	movs r1, #0xc
	str r1, [sp]
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r1, r7, r2
	ldrh r1, [r1]
	str r1, [sp, #4]
	adds r2, #8
	adds r1, r7, r2
	ldrh r1, [r1]
	str r1, [sp, #8]
	adds r2, #0x14
	adds r1, r7, r2
	ldr r1, [r1]
	str r1, [sp, #0xc]
	subs r2, #0xc
	adds r1, r7, r2
	ldrh r1, [r1]
	str r1, [sp, #0x10]
	add r1, sp, #0x3c
	movs r2, #4
	movs r3, #0x3c
	bl Entity080df420_Spawn
	movs r0, #0x10
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0818A33A:
	ldr r2, _0818A398 @ =0x00000484
	adds r0, r7, r2
	ldr r0, [r0]
	movs r1, #0x20
	bl Mod
	cmp r0, #0
	bne _0818A416
	ldr r5, _0818A39C @ =0x0203B400
	ldr r4, _0818A3A0 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _0818A3A4 @ =0x000003FF
	ands r0, r3
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r2, [r1]
	ldrb r6, [r7, #5]
	movs r1, #0x3f
	ands r2, r1
	adds r0, #1
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	add r3, sp, #0x3c
	adds r6, r6, r2
	subs r6, #0x20
	adds r4, r1, #0
	adds r4, #8
	ldr r2, _0818A3A8 @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0818A3AC
	asrs r1, r0, #0xc
	b _0818A3B2
	.align 2, 0
_0818A398: .4byte 0x00000484
_0818A39C: .4byte 0x0203B400
_0818A3A0: .4byte 0x030046B8
_0818A3A4: .4byte 0x000003FF
_0818A3A8: .4byte gSineTable
_0818A3AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0818A3B2:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r6, r0
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _0818A3CE
	asrs r0, r0, #0xc
	b _0818A3D4
_0818A3CE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0818A3D4:
	strh r0, [r3, #4]
	add r0, sp, #0x34
	movs r3, #0xc8
	lsls r3, r3, #1
	movs r1, #0xc
	str r1, [sp]
	ldr r2, _0818A464 @ =0x0000022A
	adds r1, r7, r2
	ldrh r1, [r1]
	str r1, [sp, #4]
	adds r2, #8
	adds r1, r7, r2
	ldrh r1, [r1]
	str r1, [sp, #8]
	adds r2, #0x16
	adds r1, r7, r2
	ldr r1, [r1]
	str r1, [sp, #0xc]
	subs r2, #0xe
	adds r1, r7, r2
	ldrh r1, [r1]
	str r1, [sp, #0x10]
	add r1, sp, #0x3c
	movs r2, #8
	bl Entity080df420_Spawn
	movs r0, #0x20
_0818A40A:
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0818A416:
	ldr r0, _0818A468 @ =0x00000D78
	add r0, sb
	ldrh r4, [r0]
	cmp r4, #0
	bne _0818A452
	ldr r3, _0818A46C @ =FUN_0818a47c
	movs r2, #0x2a
	ldr r0, _0818A470 @ =0x0000046D
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0818A474 @ =0x0000046B
	adds r0, r7, r1
	strb r4, [r0]
	adds r1, #0xe8
	adds r0, r7, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	ldr r0, _0818A478 @ =0xFFFFAFFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_0818A452:
	add sp, #0x48
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818A464: .4byte 0x0000022A
_0818A468: .4byte 0x00000D78
_0818A46C: .4byte FUN_0818a47c
_0818A470: .4byte 0x0000046D
_0818A474: .4byte 0x0000046B
_0818A478: .4byte 0xFFFFAFFF
