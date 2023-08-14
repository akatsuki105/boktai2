	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080659e8
FUN_080659e8: @ 0x080659E8
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r6, r5, r0
	ldr r2, _08065A54 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x32
	orrs r0, r3
	ldr r1, _08065A58 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xfe
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r4, sp, #0x14
	ldr r0, [r4, #4]
	ands r0, r2
	str r0, [r4, #4]
	ldrh r1, [r5, #0x24]
	ldr r2, _08065A5C @ =0x00005001
	ldr r3, [r5, #0x18]
	movs r0, #0x80
	lsls r0, r0, #9
	lsls r0, r3
	lsrs r0, r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r4, [sp, #8]
	adds r0, r6, #0
	movs r3, #0
	bl FUN_0823646c
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08065A60
	adds r0, r6, #0
	movs r1, #0x14
	movs r2, #1
	movs r3, #2
	bl FUN_08236514
	b _08065A6C
	.align 2, 0
_08065A54: .4byte 0xFFFF0000
_08065A58: .4byte 0x0000FFFF
_08065A5C: .4byte 0x00005001
_08065A60:
	adds r0, r6, #0
	movs r1, #0x14
	movs r2, #2
	movs r3, #1
	bl FUN_08236514
_08065A6C:
	ldr r1, _08065A94 @ =FUN_0807e784
	adds r0, r6, #0
	adds r2, r5, #0
	bl FUN_0823651c
	movs r0, #0x82
	lsls r0, r0, #1
	adds r1, r5, r0
	adds r0, r6, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r6, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08065A94: .4byte FUN_0807e784

	thumb_func_start FUN_08065a98
FUN_08065a98: @ 0x08065A98
	push {lr}
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0
	beq _08065ACA
	movs r1, #0x18
	ldr r0, _08065AB8 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _08065ABC @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08065AC0
	movs r0, #1
	b _08065AC2
	.align 2, 0
_08065AB8: .4byte 0x030046A0
_08065ABC: .4byte 0x00000934
_08065AC0:
	movs r0, #0
_08065AC2:
	cmp r0, #0
	bne _08065ACA
	movs r0, #1
	b _08065ACC
_08065ACA:
	movs r0, #0
_08065ACC:
	pop {r1}
	bx r1

	thumb_func_start FUN_08065ad0
FUN_08065ad0: @ 0x08065AD0
	push {lr}
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0
	beq _08065B02
	movs r1, #0x10
	ldr r0, _08065AF0 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _08065AF4 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08065AF8
	movs r0, #1
	b _08065AFA
	.align 2, 0
_08065AF0: .4byte 0x030046A0
_08065AF4: .4byte 0x00000934
_08065AF8:
	movs r0, #0
_08065AFA:
	cmp r0, #0
	beq _08065B02
	movs r0, #1
	b _08065B04
_08065B02:
	movs r0, #0
_08065B04:
	pop {r1}
	bx r1
_08065B08:
	.byte 0x00, 0xB5, 0x80, 0x21, 0x01, 0x40, 0x00, 0x29
	.byte 0x15, 0xD0, 0x80, 0x21, 0x89, 0x01, 0x05, 0x48, 0x00, 0x68, 0x05, 0x4A, 0x80, 0x18, 0x00, 0x88
	.byte 0x08, 0x40, 0x00, 0x28, 0x06, 0xD0, 0x01, 0x20, 0x05, 0xE0, 0x00, 0x00, 0xA0, 0x46, 0x00, 0x03
	.byte 0x34, 0x09, 0x00, 0x00, 0x00, 0x20, 0x00, 0x28, 0x01, 0xD0, 0x01, 0x20, 0x00, 0xE0, 0x00, 0x20
	.byte 0x02, 0xBC, 0x08, 0x47

	thumb_func_start FUN_08065b44
FUN_08065b44: @ 0x08065B44
	push {lr}
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0
	beq _08065B76
	movs r1, #8
	ldr r0, _08065B64 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _08065B68 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08065B6C
	movs r0, #1
	b _08065B6E
	.align 2, 0
_08065B64: .4byte 0x030046A0
_08065B68: .4byte 0x00000934
_08065B6C:
	movs r0, #0
_08065B6E:
	cmp r0, #0
	beq _08065B76
	movs r0, #1
	b _08065B78
_08065B76:
	movs r0, #0
_08065B78:
	pop {r1}
	bx r1

	thumb_func_start FUN_08065b7c
FUN_08065b7c: @ 0x08065B7C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrh r0, [r7, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08065BA4
	cmp r1, #0
	blt _08065BA4
	ldr r0, _08065BA8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08065BA4
	ldr r0, _08065BAC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08065BB0
_08065BA4:
	movs r4, #0
	b _08065BBE
	.align 2, 0
_08065BA8: .4byte 0x030046A8
_08065BAC: .4byte 0x030046AC
_08065BB0:
	ldr r0, _08065BD0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08065BBE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08065BD4
	adds r0, #4
	b _08065BE0
	.align 2, 0
_08065BD0: .4byte 0x030046A4
_08065BD4:
	ldr r0, _08065C6C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08065BE0:
	ldrh r0, [r0, #2]
	bl FUN_08065ad0
	cmp r0, #0
	beq _08065CB0
	movs r1, #0xe4
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08065CB0
	ldr r2, _08065C70 @ =0x00000395
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08065CB0
	adds r0, r7, #0
	adds r0, #0x2c
	bl sub_081D2230
	cmp r0, #0
	bne _08065CB0
	movs r5, #0xe0
	lsls r5, r5, #1
	adds r6, r7, r5
	ldrh r0, [r6]
	ldr r5, _08065C6C @ =0x030046A4
	ldr r1, [r5]
	ldr r1, [r1, #4]
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl Mod
	adds r4, r0, #0
	ldrh r0, [r6]
	ldr r1, [r5]
	ldr r1, [r1, #4]
	movs r5, #4
	ldrsh r1, [r1, r5]
	bl Div
	lsls r4, r4, #8
	adds r1, r4, #0
	adds r1, #0x80
	movs r2, #0xe7
	lsls r2, r2, #2
	adds r3, r7, r2
	strh r1, [r3]
	lsls r0, r0, #8
	adds r2, r0, #0
	adds r2, #0x80
	movs r5, #0xe8
	lsls r5, r5, #2
	adds r1, r7, r5
	strh r2, [r1]
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r1, r7, r2
	str r3, [r1]
	adds r2, r4, #1
	adds r4, #0xff
	adds r3, r0, #1
	adds r0, #0xff
	movs r5, #0x2c
	ldrsh r1, [r7, r5]
	cmp r1, r2
	bge _08065C74
	strh r2, [r7, #0x2c]
	b _08065C7A
	.align 2, 0
_08065C6C: .4byte 0x030046A4
_08065C70: .4byte 0x00000395
_08065C74:
	cmp r1, r4
	ble _08065C7A
	strh r4, [r7, #0x2c]
_08065C7A:
	movs r2, #0x30
	ldrsh r1, [r7, r2]
	cmp r1, r3
	bge _08065C86
	strh r3, [r7, #0x30]
	b _08065C8C
_08065C86:
	cmp r1, r0
	ble _08065C8C
	strh r0, [r7, #0x30]
_08065C8C:
	movs r5, #0x82
	lsls r5, r5, #1
	adds r2, r7, r5
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	adds r2, r7, #0
	adds r2, #0xa8
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0xe5
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
_08065CB0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08065cb8
FUN_08065cb8: @ 0x08065CB8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne _08065CD8
	movs r2, #0xe0
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r1, #1
	strb r1, [r0]
	ldr r3, _08065D5C @ =0x00000381
	adds r0, r4, r3
	strb r1, [r0]
_08065CD8:
	ldr r1, _08065D60 @ =0x00000395
	adds r0, r4, r1
	movs r2, #0
	movs r6, #1
	strb r6, [r0]
	movs r3, #0xd6
	lsls r3, r3, #1
	adds r1, r4, r3
	movs r5, #0
	movs r0, #0x32
	strh r0, [r1]
	movs r1, #0x3c
	adds r3, #4
	adds r0, r4, r3
	strh r1, [r0]
	ldr r1, _08065D64 @ =0x000003D2
	adds r0, r4, r1
	strb r5, [r0]
	ldr r3, _08065D68 @ =0x000003F6
	adds r0, r4, r3
	strh r2, [r0]
	movs r1, #0x2c
	ldrsh r0, [r4, r1]
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r1, r4, r2
	ldr r2, [r1]
	movs r3, #0
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	movs r3, #0x30
	ldrsh r1, [r4, r3]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	lsls r1, r1, #1
	adds r1, #1
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r4, r0
	strb r1, [r2]
	lsls r0, r1, #0x18
	cmp r1, #4
	bls _08065D74
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _08065D6C @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r3, _08065D70 @ =0x000002E7
	adds r0, r4, r3
	strb r6, [r0]
	b _08065D82
	.align 2, 0
_08065D5C: .4byte 0x00000381
_08065D60: .4byte 0x00000395
_08065D64: .4byte 0x000003D2
_08065D68: .4byte 0x000003F6
_08065D6C: .4byte 0x000002E6
_08065D70: .4byte 0x000002E7
_08065D74:
	lsrs r0, r0, #0x19
	ldr r2, _08065D9C @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r3, _08065DA0 @ =0x000002E7
	adds r0, r4, r3
	strb r5, [r0]
_08065D82:
	ldr r0, _08065DA4 @ =0x000003D6
	adds r1, r4, r0
	movs r2, #0
	ldr r0, _08065DA8 @ =0x00000191
	strh r0, [r1]
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #0xa
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08065D9C: .4byte 0x000002E6
_08065DA0: .4byte 0x000002E7
_08065DA4: .4byte 0x000003D6
_08065DA8: .4byte 0x00000191

	thumb_func_start FUN_08065dac
FUN_08065dac: @ 0x08065DAC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r0, #0x2c
	bl FUN_0809f658
	cmp r0, #0
	beq _08065E10
	ldr r1, _08065E18 @ =0x00000397
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08065E10
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r6, r7, r2
	ldrh r0, [r6]
	ldr r5, _08065E1C @ =0x030046A4
	ldr r1, [r5]
	ldr r1, [r1, #4]
	movs r3, #4
	ldrsh r1, [r1, r3]
	bl Mod
	adds r4, r0, #0
	ldrh r0, [r6]
	ldr r1, [r5]
	ldr r1, [r1, #4]
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl Div
	lsls r4, r4, #8
	adds r4, #0x80
	movs r3, #0xe7
	lsls r3, r3, #2
	adds r2, r7, r3
	strh r4, [r2]
	lsls r0, r0, #8
	adds r0, #0x80
	adds r3, #4
	adds r1, r7, r3
	strh r0, [r1]
	movs r1, #0xe6
	lsls r1, r1, #2
	adds r0, r7, r1
	str r2, [r0]
	ldr r2, _08065E20 @ =0x00000396
	adds r1, r7, r2
	movs r0, #1
	strb r0, [r1]
_08065E10:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08065E18: .4byte 0x00000397
_08065E1C: .4byte 0x030046A4
_08065E20: .4byte 0x00000396

	thumb_func_start FUN_08065e24
FUN_08065e24: @ 0x08065E24
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	ldr r1, _08065EDC @ =0x00000397
	adds r0, r6, r1
	movs r2, #0
	movs r3, #1
	mov sb, r3
	mov r1, sb
	strb r1, [r0]
	movs r3, #0xd6
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r0, #0
	mov r8, r0
	movs r0, #0x32
	strh r0, [r1]
	ldr r1, _08065EE0 @ =0x000003D2
	adds r0, r6, r1
	mov r3, r8
	strb r3, [r0]
	adds r1, #0x24
	adds r0, r6, r1
	strh r2, [r0]
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r7, r6, r2
	ldrh r0, [r7]
	ldr r5, _08065EE4 @ =0x030046A4
	ldr r1, [r5]
	ldr r1, [r1, #4]
	movs r3, #4
	ldrsh r1, [r1, r3]
	bl Mod
	adds r4, r0, #0
	ldrh r0, [r7]
	ldr r1, [r5]
	ldr r1, [r1, #4]
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl Div
	adds r1, r0, #0
	lsls r4, r4, #8
	movs r3, #0xe6
	lsls r3, r3, #2
	adds r0, r6, r3
	ldr r2, [r0]
	movs r3, #0
	ldrsh r0, [r2, r3]
	subs r0, #0x80
	subs r4, r4, r0
	lsls r1, r1, #8
	movs r3, #4
	ldrsh r0, [r2, r3]
	subs r0, #0x80
	subs r1, r1, r0
	adds r0, r4, #0
	bl FUN_0823785c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	lsls r1, r1, #1
	adds r1, #1
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r6, r0
	strb r1, [r2]
	lsls r0, r1, #0x18
	cmp r1, #4
	bls _08065EF0
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _08065EE8 @ =0x000002E6
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _08065EEC @ =0x000002E7
	adds r0, r6, r3
	mov r1, sb
	b _08065EFE
	.align 2, 0
_08065EDC: .4byte 0x00000397
_08065EE0: .4byte 0x000003D2
_08065EE4: .4byte 0x030046A4
_08065EE8: .4byte 0x000002E6
_08065EEC: .4byte 0x000002E7
_08065EF0:
	lsrs r0, r0, #0x19
	ldr r2, _08065F20 @ =0x000002E6
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _08065F24 @ =0x000002E7
	adds r0, r6, r3
	mov r1, r8
_08065EFE:
	strb r1, [r0]
	ldr r2, _08065F28 @ =0x000003D6
	adds r1, r6, r2
	movs r2, #0
	ldr r0, _08065F2C @ =0x00000191
	strh r0, [r1]
	ldr r3, _08065F30 @ =0x00000396
	adds r0, r6, r3
	strb r2, [r0]
	movs r0, #0xa
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08065F20: .4byte 0x000002E6
_08065F24: .4byte 0x000002E7
_08065F28: .4byte 0x000003D6
_08065F2C: .4byte 0x00000191
_08065F30: .4byte 0x00000396

	thumb_func_start FUN_08065f34
FUN_08065f34: @ 0x08065F34
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08065F5E
	cmp r1, #0
	blt _08065F5E
	ldr r0, _08065F64 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08065F5E
	ldr r0, _08065F68 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08065F6C
_08065F5E:
	movs r4, #0
	b _08065F7A
	.align 2, 0
_08065F64: .4byte 0x030046A8
_08065F68: .4byte 0x030046AC
_08065F6C:
	ldr r0, _08065F8C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08065F7A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08065F90
	adds r0, #4
	b _08065F9C
	.align 2, 0
_08065F8C: .4byte 0x030046A4
_08065F90:
	ldr r0, _08065FB0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08065F9C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08065FB4
	cmp r2, #2
	beq _08065FB8
	b _08065FBC
	.align 2, 0
_08065FB0: .4byte 0x030046A4
_08065FB4:
	ldrb r0, [r5, #4]
	b _08065FBA
_08065FB8:
	ldrb r0, [r5]
_08065FBA:
	subs r1, r1, r0
_08065FBC:
	movs r2, #0x2e
	ldrsh r0, [r6, r2]
	cmp r1, r0
	bne _08066038
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08065FE8
	cmp r1, #0
	blt _08065FE8
	ldr r0, _08065FEC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08065FE8
	ldr r0, _08065FF0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08065FF4
_08065FE8:
	movs r4, #0
	b _08066002
	.align 2, 0
_08065FEC: .4byte 0x030046A8
_08065FF0: .4byte 0x030046AC
_08065FF4:
	ldr r0, _08066014 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08066002:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08066018
	adds r0, #4
	b _08066024
	.align 2, 0
_08066014: .4byte 0x030046A4
_08066018:
	ldr r0, _08066034 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08066024:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08066038
	movs r0, #0
	b _0806603A
	.align 2, 0
_08066034: .4byte 0x030046A4
_08066038:
	movs r0, #1
_0806603A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08066040
FUN_08066040: @ 0x08066040
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r1, _0806605C @ =0x000003A7
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080660F8
	cmp r0, #2
	bgt _08066060
	cmp r0, #0
	beq _0806606E
	b _0806622E
	.align 2, 0
_0806605C: .4byte 0x000003A7
_08066060:
	cmp r0, #4
	bne _08066066
	b _0806615E
_08066066:
	cmp r0, #6
	bne _0806606C
	b _080661C4
_0806606C:
	b _0806622E
_0806606E:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x1e
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _080660F4 @ =0xFFFF0000
	ldr r3, [sp]
	ands r3, r2
	orrs r3, r0
	str r3, [sp]
	mov r4, sp
	ldrh r0, [r4, #4]
	subs r0, #0x1e
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x64
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r2, r3
	orrs r2, r0
	str r2, [sp]
	adds r0, r5, #0
	mov r1, sp
	bl FUN_08065f34
	cmp r0, #0
	bne _0806615A
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x64
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #4]
	subs r0, #0x64
	strh r0, [r4, #4]
	adds r0, r5, #0
	bl FUN_08065f34
	cmp r0, #0
	beq _080660D4
	b _0806622A
_080660D4:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x64
	mov r1, sp
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_08065f34
	cmp r0, #0
	bne _0806615A
	b _0806622A
	.align 2, 0
_080660F4: .4byte 0xFFFF0000
_080660F8:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x1e
	mov r1, sp
	strh r0, [r1]
	mov r4, sp
	ldrh r0, [r4, #4]
	subs r0, #0x1e
	strh r0, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x64
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_08065f34
	cmp r0, #0
	bne _0806615A
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x64
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #4]
	subs r0, #0x64
	strh r0, [r4, #4]
	adds r0, r5, #0
	bl FUN_08065f34
	cmp r0, #0
	bne _080661C0
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x64
	mov r1, sp
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_08065f34
	cmp r0, #0
	beq _080661C0
_0806615A:
	movs r0, #1
	b _08066232
_0806615E:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x1e
	mov r1, sp
	strh r0, [r1]
	mov r4, sp
	ldrh r0, [r4, #4]
	adds r0, #0x1e
	strh r0, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x64
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_08065f34
	cmp r0, #0
	bne _08066226
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x64
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #4]
	adds r0, #0x64
	strh r0, [r4, #4]
	adds r0, r5, #0
	bl FUN_08065f34
	cmp r0, #0
	bne _080661C0
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x64
	mov r1, sp
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_08065f34
	cmp r0, #0
	bne _08066226
_080661C0:
	movs r0, #3
	b _08066232
_080661C4:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x1e
	mov r1, sp
	strh r0, [r1]
	mov r4, sp
	ldrh r0, [r4, #4]
	adds r0, #0x1e
	strh r0, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x64
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_08065f34
	cmp r0, #0
	bne _08066226
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x64
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #4]
	adds r0, #0x64
	strh r0, [r4, #4]
	adds r0, r5, #0
	bl FUN_08065f34
	cmp r0, #0
	bne _0806622A
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x64
	mov r1, sp
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_08065f34
	cmp r0, #0
	beq _0806622A
_08066226:
	movs r0, #5
	b _08066232
_0806622A:
	movs r0, #7
	b _08066232
_0806622E:
	movs r0, #1
	rsbs r0, r0, #0
_08066232:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0806623c
FUN_0806623c: @ 0x0806623C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r0, #0xe9
	lsls r0, r0, #2
	adds r7, r5, r0
	ldrb r0, [r7]
	cmp r0, #0
	bne _0806624E
	b _08066356
_0806624E:
	movs r1, #0xe5
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	bl FUN_08065b44
	adds r1, r0, #0
	cmp r1, #0
	bne _08066274
	ldr r2, _0806626C @ =0x000003A5
	adds r0, r5, r2
	strb r1, [r0]
	ldr r4, _08066270 @ =0x000003A6
	adds r0, r5, r4
	b _080662A0
	.align 2, 0
_0806626C: .4byte 0x000003A5
_08066270: .4byte 0x000003A6
_08066274:
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _08066324
	ldr r2, _080662A8 @ =0x000003A7
	adds r4, r5, r2
	ldrb r1, [r4]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _080662B0
	ldr r4, _080662AC @ =0x000003A5
	adds r0, r5, r4
	movs r1, #0
	strb r1, [r0]
	subs r2, #1
	adds r0, r5, r2
_080662A0:
	strb r1, [r0]
	strb r1, [r7]
	b _08066402
	.align 2, 0
_080662A8: .4byte 0x000003A7
_080662AC: .4byte 0x000003A5
_080662B0:
	adds r0, r5, #0
	bl FUN_08066040
	strb r0, [r4]
	ldrb r0, [r4]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080662E4 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080662E8
	asrs r1, r0, #0xc
	b _080662EE
	.align 2, 0
_080662E4: .4byte 0x085B0A08
_080662E8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080662EE:
	movs r2, #0xea
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	ldr r1, _08066310 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _08066314
	asrs r1, r0, #0xc
	b _0806631A
	.align 2, 0
_08066310: .4byte 0x085B0A08
_08066314:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0806631A:
	movs r2, #0xeb
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	b _08066402
_08066324:
	ldr r0, _08066344 @ =0x000003A5
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	bne _08066402
	ldr r2, _08066348 @ =0x000003A6
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08066350
	ldr r0, _0806634C @ =0x00000335
	bl PlaySound_082406e0
	strb r6, [r4]
	b _08066402
	.align 2, 0
_08066344: .4byte 0x000003A5
_08066348: .4byte 0x000003A6
_0806634C: .4byte 0x00000335
_08066350:
	adds r0, #1
	strb r0, [r1]
	b _08066402
_08066356:
	movs r4, #0xe5
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	bl FUN_08065b44
	cmp r0, #0
	beq _08066402
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0806638A
	cmp r1, #6
	bne _08066402
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	blt _08066402
_0806638A:
	movs r0, #1
	strb r0, [r7]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r2, _080663C8 @ =0x000003A7
	adds r0, r5, r2
	strb r1, [r0]
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080663CC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080663D0
	asrs r1, r0, #0xc
	b _080663D6
	.align 2, 0
_080663C8: .4byte 0x000003A7
_080663CC: .4byte 0x085B0A08
_080663D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080663D6:
	movs r4, #0xea
	lsls r4, r4, #2
	adds r0, r5, r4
	strh r1, [r0]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080663F4
	asrs r2, r0, #0xc
	b _080663FA
_080663F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080663FA:
	movs r4, #0xeb
	lsls r4, r4, #2
	adds r0, r5, r4
	strh r2, [r0]
_08066402:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08066408
FUN_08066408: @ 0x08066408
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne _0806641E
	b _08066788
_0806641E:
	ldr r2, _08066484 @ =0x00000446
	adds r0, r7, r2
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _08066436
	ldr r5, _08066488 @ =0x00000442
	adds r0, r7, r5
	ldrh r0, [r0]
	cmp r0, #5
	bne _08066436
	movs r1, #1
_08066436:
	cmp r1, #0
	beq _0806643C
	b _08066788
_0806643C:
	movs r1, #0x10
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0806644E
	b _08066788
_0806644E:
	ldr r0, _0806648C @ =0x03002BAC
	ldr r1, _08066490 @ =0x03002B84
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _0806645C
	b _08066788
_0806645C:
	ldr r0, _08066494 @ =0x03002B90
	ldrh r0, [r0]
	adds r0, #0x70
	movs r1, #0xff
	ands r0, r1
	asrs r4, r0, #5
	movs r6, #0
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	bne _08066474
	b _0806657C
_08066474:
	cmp r4, #1
	bne _0806649C
	ldr r0, _08066498 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r5, #4
	ldrsh r6, [r0, r5]
	b _080664C2
	.align 2, 0
_08066484: .4byte 0x00000446
_08066488: .4byte 0x00000442
_0806648C: .4byte 0x03002BAC
_08066490: .4byte 0x03002B84
_08066494: .4byte 0x03002B90
_08066498: .4byte 0x030046A4
_0806649C:
	cmp r4, #3
	bne _080664A6
	movs r6, #1
	rsbs r6, r6, #0
	b _080664C2
_080664A6:
	cmp r4, #5
	bne _080664BC
	ldr r0, _080664B8 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	rsbs r6, r0, #0
	b _080664C2
	.align 2, 0
_080664B8: .4byte 0x030046A4
_080664BC:
	cmp r4, #7
	bne _080664C2
	movs r6, #1
_080664C2:
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r5, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080664DA
	adds r0, #4
	b _080664E6
_080664DA:
	ldr r0, _0806650C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080664E6:
	ldrb r0, [r0]
	movs r5, #0xf
	mov r8, r5
	mov r1, r8
	ands r1, r0
	mov r8, r1
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	adds r5, r0, r6
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08066510
	adds r0, #4
	b _0806651C
	.align 2, 0
_0806650C: .4byte 0x030046A4
_08066510:
	ldr r0, _08066558 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0806651C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r8, r0
	bhs _08066528
	b _08066788
_08066528:
	adds r0, r4, #1
	lsls r4, r0, #5
	ldr r2, _0806655C @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r3, [r0, r5]
	ands r4, r1
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r4, [r0, r1]
	ldr r1, _08066560 @ =0x03002BAC
	ldrh r0, [r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _08066564
	asrs r2, r0, #0xc
	b _0806656A
	.align 2, 0
_08066558: .4byte 0x030046A4
_0806655C: .4byte 0x085B0A08
_08066560: .4byte 0x03002BAC
_08066564:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0806656A:
	ldrh r0, [r7, #0x34]
	subs r0, r0, r2
	strh r0, [r7, #0x34]
	ldrh r0, [r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0806657A
	b _08066778
_0806657A:
	b _0806677C
_0806657C:
	cmp r4, #0
	bne _08066590
	ldr r0, _0806658C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	b _080665D0
	.align 2, 0
_0806658C: .4byte 0x030046A4
_08066590:
	cmp r4, #2
	bne _080665A8
	ldr r0, _080665A4 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r5, #4
	ldrsh r0, [r0, r5]
	subs r6, r0, #1
	b _080665D2
	.align 2, 0
_080665A4: .4byte 0x030046A4
_080665A8:
	cmp r4, #4
	bne _080665C0
	ldr r0, _080665BC @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	mvns r6, r0
	b _080665D2
	.align 2, 0
_080665BC: .4byte 0x030046A4
_080665C0:
	cmp r4, #6
	bne _080665D2
	ldr r0, _080665EC @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	rsbs r0, r0, #0
_080665D0:
	adds r6, r0, #1
_080665D2:
	movs r5, #0xe1
	lsls r5, r5, #1
	adds r0, r7, r5
	ldrh r5, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080665F0
	adds r0, #4
	b _080665FC
	.align 2, 0
_080665EC: .4byte 0x030046A4
_080665F0:
	ldr r0, _08066624 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080665FC:
	ldrb r0, [r0]
	movs r1, #0xf
	mov r8, r1
	mov r2, r8
	ands r2, r0
	mov r8, r2
	movs r5, #0xe1
	lsls r5, r5, #1
	adds r0, r7, r5
	ldrh r0, [r0]
	adds r5, r0, r6
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08066628
	adds r0, #4
	b _08066634
	.align 2, 0
_08066624: .4byte 0x030046A4
_08066628:
	ldr r0, _08066660 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08066634:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r8, r0
	bhs _08066640
	b _08066788
_08066640:
	ldrh r0, [r7, #0x2c]
	movs r1, #0xff
	adds r2, r1, #0
	ands r2, r0
	ldrh r0, [r7, #0x30]
	ands r1, r0
	cmp r4, #0
	bne _08066664
	cmp r2, r1
	bgt _080666B0
	ldr r0, _08066660 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r6, [r0, r1]
	b _080666C0
	.align 2, 0
_08066660: .4byte 0x030046A4
_08066664:
	cmp r4, #2
	bne _08066684
	adds r1, r2, r1
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	ble _0806669C
	ldr r0, _08066680 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r6, [r0, r2]
	b _080666C0
	.align 2, 0
_08066680: .4byte 0x030046A4
_08066684:
	cmp r4, #4
	bne _080666A2
	cmp r2, r1
	ble _0806669C
	ldr r0, _08066698 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r5, #4
	ldrsh r0, [r0, r5]
	b _080666BE
	.align 2, 0
_08066698: .4byte 0x030046A4
_0806669C:
	movs r6, #1
	rsbs r6, r6, #0
	b _080666C0
_080666A2:
	cmp r4, #6
	bne _080666C0
	adds r1, r2, r1
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	ble _080666B4
_080666B0:
	movs r6, #1
	b _080666C0
_080666B4:
	ldr r0, _080666D8 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
_080666BE:
	rsbs r6, r0, #0
_080666C0:
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r5, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080666DC
	adds r0, #4
	b _080666E8
	.align 2, 0
_080666D8: .4byte 0x030046A4
_080666DC:
	ldr r0, _08066710 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080666E8:
	ldrb r0, [r0]
	movs r5, #0xf
	mov r8, r5
	mov r1, r8
	ands r1, r0
	mov r8, r1
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	adds r5, r0, r6
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08066714
	adds r0, #4
	b _08066720
	.align 2, 0
_08066710: .4byte 0x030046A4
_08066714:
	ldr r0, _08066758 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08066720:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r8, r0
	blo _08066788
	adds r0, r4, #1
	lsls r4, r0, #5
	ldr r2, _0806675C @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r3, [r0, r5]
	ands r4, r1
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r4, [r0, r1]
	ldr r1, _08066760 @ =0x03002BAC
	ldrh r0, [r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _08066764
	asrs r2, r0, #0xc
	b _0806676A
	.align 2, 0
_08066758: .4byte 0x030046A4
_0806675C: .4byte 0x085B0A08
_08066760: .4byte 0x03002BAC
_08066764:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0806676A:
	ldrh r0, [r7, #0x34]
	subs r0, r0, r2
	strh r0, [r7, #0x34]
	ldrh r0, [r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0806677C
_08066778:
	asrs r1, r0, #0xc
	b _08066782
_0806677C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08066782:
	ldrh r0, [r7, #0x38]
	subs r0, r0, r1
	strh r0, [r7, #0x38]
_08066788:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08066794
FUN_08066794: @ 0x08066794
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080612d8
	ldr r0, _080667AC @ =0x00000376
	adds r4, r4, r0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080667AC: .4byte 0x00000376

	thumb_func_start FUN_080667b0
FUN_080667b0: @ 0x080667B0
	push {r4, lr}
	adds r2, r0, #0
	ldr r3, _08066804 @ =0x0000043A
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _080667FC
	ldr r4, _08066808 @ =0x00000446
	adds r0, r2, r4
	ldrh r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _080667D6
	subs r4, #4
	adds r0, r2, r4
	ldrh r0, [r0]
	cmp r0, #7
	bne _080667D6
	movs r3, #1
_080667D6:
	cmp r3, #0
	bne _080667FC
	movs r0, #0xf7
	lsls r0, r0, #2
	adds r4, r2, r0
	adds r0, r1, #2
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x63
	bls _080667FC
	adds r0, r2, #0
	bl FUN_08066794
	ldrh r0, [r4]
	subs r0, #0x64
	strh r0, [r4]
_080667FC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08066804: .4byte 0x0000043A
_08066808: .4byte 0x00000446

	thumb_func_start FUN_0806680c
FUN_0806680c: @ 0x0806680C
	push {r4, lr}
	adds r3, r0, #0
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r1, _08066828 @ =0x030046A0
	ldr r0, [r1]
	ldr r4, _0806682C @ =0x00000934
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r2
	cmp r0, #0
	beq _08066830
	movs r0, #1
	b _08066832
	.align 2, 0
_08066828: .4byte 0x030046A0
_0806682C: .4byte 0x00000934
_08066830:
	movs r0, #0
_08066832:
	cmp r0, #0
	beq _0806686E
	movs r2, #0x99
	lsls r2, r2, #2
	adds r0, r3, r2
	ldrh r0, [r0]
	cmp r0, #0x12
	beq _0806686E
	movs r0, #2
	ldr r1, [r1]
	ldr r4, _08066858 @ =0x00000934
	adds r1, r1, r4
	ldrh r1, [r1]
	ands r1, r0
	cmp r1, #0
	beq _0806685C
	movs r0, #1
	b _0806685E
	.align 2, 0
_08066858: .4byte 0x00000934
_0806685C:
	movs r0, #0
_0806685E:
	cmp r0, #0
	bne _08066872
	adds r0, r3, #0
	adds r0, #0x2c
	bl FUN_0809df78
	cmp r0, #0
	bne _08066872
_0806686E:
	movs r0, #0
	b _08066874
_08066872:
	movs r0, #1
_08066874:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0806687c
FUN_0806687c: @ 0x0806687C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r0, _08066918 @ =0x0000038E
	adds r3, r4, r0
	ldrb r0, [r3]
	ldr r1, _0806691C @ =0x030046A0
	ldr r2, [r1]
	lsls r0, r0, #2
	adds r1, r0, r2
	movs r6, #0xb2
	lsls r6, r6, #2
	adds r0, r1, r6
	ldr r5, [r0]
	cmp r5, #0
	bne _080668CC
	movs r7, #0xb0
	lsls r7, r7, #2
	adds r0, r1, r7
	ldr r1, [r0]
	adds r1, #1
	str r1, [r0]
	ldr r0, _08066920 @ =0x00008C9F
	cmp r1, r0
	ble _080668CC
	ldrb r0, [r3]
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r1, r7, #0
	adds r0, r0, r1
	str r5, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r0, r0, r6
	ldr r1, _08066924 @ =0x0002BF20
	str r1, [r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08060e90
_080668CC:
	movs r1, #0x80
	lsls r1, r1, #0x10
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08066910
	ldr r5, _08066928 @ =0x0000038F
	adds r3, r4, r5
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xe
	bls _08066910
	movs r7, #0xda
	lsls r7, r7, #2
	adds r2, r4, r7
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	subs r5, #0x25
	adds r1, r4, r5
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	blo _0806690C
	strh r1, [r2]
_0806690C:
	movs r0, #0
	strb r0, [r3]
_08066910:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08066918: .4byte 0x0000038E
_0806691C: .4byte 0x030046A0
_08066920: .4byte 0x00008C9F
_08066924: .4byte 0x0002BF20
_08066928: .4byte 0x0000038F

	thumb_func_start FUN_0806692c
FUN_0806692c: @ 0x0806692C
	push {r4, r5, lr}
	sub sp, #0x20
	adds r5, r0, #0
	ldr r0, _08066980 @ =0x000003DE
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls _080669EC
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0806698C
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r3, _08066984 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r3
	movs r2, #0x20
	orrs r0, r2
	ldr r1, _08066988 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r3
	b _080669BE
	.align 2, 0
_08066980: .4byte 0x000003DE
_08066984: .4byte 0xFFFF0000
_08066988: .4byte 0x0000FFFF
_0806698C:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r2, [sp, #0x18]
	asrs r1, r2, #0x10
	adds r1, #0xa0
	lsls r1, r1, #0x10
	ldr r3, _080669F4 @ =0x0000FFFF
	adds r0, r3, #0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r4, _080669F8 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r4
	movs r2, #0x40
	orrs r0, r2
	ands r0, r3
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r4
_080669BE:
	orrs r0, r2
	str r0, [sp, #0x14]
	add r0, sp, #0x18
	movs r4, #0
	str r4, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	movs r1, #1
	add r2, sp, #0x10
	movs r3, #0
	bl FUN_080ddcc8
	ldr r0, _080669FC @ =0x00000376
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r1, _08066A00 @ =0x000003DE
	adds r0, r5, r1
	strh r4, [r0]
_080669EC:
	add sp, #0x20
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080669F4: .4byte 0x0000FFFF
_080669F8: .4byte 0xFFFF0000
_080669FC: .4byte 0x00000376
_08066A00: .4byte 0x000003DE

	thumb_func_start FUN_08066a04
FUN_08066a04: @ 0x08066A04
	push {r4, r5, r6, lr}
	mov ip, r0
	ldr r0, _08066A48 @ =0x000003CA
	add r0, ip
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	movs r1, #0xf2
	lsls r1, r1, #2
	add r1, ip
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r6, r0, r2
	movs r4, #0xf3
	lsls r4, r4, #2
	add r4, ip
	movs r3, #0
	ldrsh r0, [r4, r3]
	subs r5, r0, r2
	subs r3, r5, r6
	movs r0, #0xc8
	lsls r0, r0, #2
	cmp r3, r0
	ble _08066A50
	ldr r2, _08066A4C @ =0xFFFFFCE0
	adds r0, r3, r2
	asrs r2, r0, #1
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldrh r0, [r4]
	subs r0, r0, r2
	b _08066A64
	.align 2, 0
_08066A48: .4byte 0x000003CA
_08066A4C: .4byte 0xFFFFFCE0
_08066A50:
	ldr r0, _08066AB8 @ =0xFFFFFCE0
	cmp r3, r0
	bge _08066A66
	subs r0, r0, r3
	asrs r2, r0, #1
	ldrh r0, [r1]
	subs r0, r0, r2
	strh r0, [r1]
	ldrh r0, [r4]
	adds r0, r0, r2
_08066A64:
	strh r0, [r4]
_08066A66:
	adds r3, r5, r6
	movs r0, #0xc8
	lsls r0, r0, #2
	cmp r3, r0
	ble _08066A8E
	ldr r1, _08066AB8 @ =0xFFFFFCE0
	adds r0, r3, r1
	asrs r2, r0, #1
	movs r1, #0xf2
	lsls r1, r1, #2
	add r1, ip
	ldrh r0, [r1]
	subs r0, r0, r2
	strh r0, [r1]
	movs r1, #0xf3
	lsls r1, r1, #2
	add r1, ip
	ldrh r0, [r1]
	subs r0, r0, r2
	strh r0, [r1]
_08066A8E:
	ldr r0, _08066AB8 @ =0xFFFFFCE0
	cmp r3, r0
	bge _08066AB0
	subs r0, r0, r3
	asrs r2, r0, #1
	movs r1, #0xf2
	lsls r1, r1, #2
	add r1, ip
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r1, #0xf3
	lsls r1, r1, #2
	add r1, ip
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
_08066AB0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08066AB8: .4byte 0xFFFFFCE0

	thumb_func_start FUN_08066abc
FUN_08066abc: @ 0x08066ABC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08066B48 @ =0x000003CE
	adds r3, r4, r0
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	bne _08066B0C
	ldr r2, _08066B4C @ =0x03003540
	ldrh r0, [r2]
	ldrh r1, [r4, #0x2c]
	subs r0, r0, r1
	movs r5, #0xf2
	lsls r5, r5, #2
	adds r1, r4, r5
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #0x2e]
	subs r0, r0, r1
	subs r0, #0x96
	adds r5, #2
	adds r1, r4, r5
	strh r0, [r1]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #0x30]
	subs r0, r0, r1
	movs r2, #0xf3
	lsls r2, r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	movs r1, #1
	movs r0, #1
	strh r0, [r3]
	movs r3, #0xf4
	lsls r3, r3, #2
	adds r0, r4, r3
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_08066a04
_08066B0C:
	movs r5, #0xa4
	lsls r5, r5, #2
	adds r2, r4, r5
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08066B9E
	adds r0, r1, #0
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r5, r0, #5
	ldr r2, _08066B50 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _08066B54
	asrs r3, r0, #0xc
	b _08066B5A
	.align 2, 0
_08066B48: .4byte 0x000003CE
_08066B4C: .4byte 0x03003540
_08066B50: .4byte 0x085B0A08
_08066B54:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_08066B5A:
	movs r0, #0xf2
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, r0, r3
	strh r0, [r1]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _08066B7C
	asrs r2, r0, #0xc
	b _08066B82
_08066B7C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08066B82:
	movs r3, #0xf3
	lsls r3, r3, #2
	adds r1, r4, r3
	ldrh r0, [r1]
	subs r0, r0, r2
	movs r2, #0
	strh r0, [r1]
	movs r5, #0xf4
	lsls r5, r5, #2
	adds r0, r4, r5
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_08066a04
_08066B9E:
	movs r0, #0xf2
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bne _08066BBA
	movs r3, #0xf3
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	beq _08066C58
_08066BBA:
	ldr r2, _08066C20 @ =0x000003D1
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08066C58
	movs r3, #0
	ldrsh r0, [r1, r3]
	movs r5, #0xf3
	lsls r5, r5, #2
	adds r1, r4, r5
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	subs r5, #0xe4
	adds r0, r4, r5
	strb r1, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	bne _08066C44
	adds r0, r2, #0
	adds r0, #0x20
	ands r0, r3
	asrs r0, r0, #6
	adds r1, r0, #1
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	ble _08066C2C
	subs r0, r0, r1
	ldr r2, _08066C24 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r3, _08066C28 @ =0x000002E7
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	b _08066C58
	.align 2, 0
_08066C20: .4byte 0x000003D1
_08066C24: .4byte 0x000002E6
_08066C28: .4byte 0x000002E7
_08066C2C:
	ldr r5, _08066C3C @ =0x000002E6
	adds r0, r4, r5
	strb r1, [r0]
	ldr r0, _08066C40 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	b _08066C58
	.align 2, 0
_08066C3C: .4byte 0x000002E6
_08066C40: .4byte 0x000002E7
_08066C44:
	cmp r0, #4
	bne _08066C52
	ldr r1, _08066C60 @ =0x00000387
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _08066C58
_08066C52:
	adds r0, r4, #0
	bl FUN_080609dc
_08066C58:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08066C60: .4byte 0x00000387

	thumb_func_start FUN_08066c64
FUN_08066c64: @ 0x08066C64
	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r1, _08066CA8 @ =0x000003CE
	adds r0, r3, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _08066D04
	ldr r5, _08066CAC @ =0x000003BD
	adds r0, r3, r5
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldr r2, _08066CB0 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r5, r2, #0
	cmp r0, #0
	blt _08066CB4
	asrs r0, r0, #0xc
	b _08066CBA
	.align 2, 0
_08066CA8: .4byte 0x000003CE
_08066CAC: .4byte 0x000003BD
_08066CB0: .4byte 0x085B0A08
_08066CB4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08066CBA:
	rsbs r1, r0, #0
	movs r2, #0xf2
	lsls r2, r2, #2
	adds r0, r3, r2
	movs r2, #0
	strh r1, [r0]
	ldr r1, _08066CE8 @ =0x000003CA
	adds r0, r3, r1
	strh r2, [r0]
	lsls r0, r4, #1
	adds r0, r0, r5
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #5
	cmp r0, #0
	blt _08066CEC
	asrs r0, r0, #0xc
	b _08066CF2
	.align 2, 0
_08066CE8: .4byte 0x000003CA
_08066CEC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08066CF2:
	rsbs r1, r0, #0
	movs r5, #0xf3
	lsls r5, r5, #2
	adds r0, r3, r5
	strh r1, [r0]
	ldr r0, _08066D0C @ =0x000003CE
	adds r1, r3, r0
	movs r0, #1
	strh r0, [r1]
_08066D04:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08066D0C: .4byte 0x000003CE

	thumb_func_start FUN_08066d10
FUN_08066d10: @ 0x08066D10
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #8
	bl FUN_0823bca8
	ldr r0, _08066D28 @ =0x000003CE
	adds r4, r4, r0
	movs r0, #0
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08066D28: .4byte 0x000003CE

	thumb_func_start FUN_08066d2c
FUN_08066d2c: @ 0x08066D2C
	push {lr}
	adds r2, r0, #0
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #1
	bls _08066D40
	cmp r0, #5
	bne _08066D5E
_08066D40:
	cmp r1, #0
	beq _08066D70
	cmp r1, #3
	beq _08066D70
	cmp r1, #6
	beq _08066D70
	cmp r1, #4
	bne _08066D74
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08066D70
	b _08066D74
_08066D5E:
	cmp r0, #4
	bne _08066D68
	cmp r1, #0
	beq _08066D70
	b _08066D74
_08066D68:
	cmp r1, #0
	beq _08066D70
	cmp r1, #4
	bne _08066D74
_08066D70:
	movs r0, #1
	b _08066D76
_08066D74:
	movs r0, #0
_08066D76:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08066d7c
FUN_08066d7c: @ 0x08066D7C
	push {r4, lr}
	adds r4, r0, #0
	adds r2, r1, #0
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08066DCE
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_08066d2c
	cmp r0, #0
	beq _08066DCE
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	bls _08066DB2
	cmp r0, #5
	bne _08066DC6
_08066DB2:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne _08066DC6
	adds r0, r4, #0
	bl FUN_08066c64
	b _08066DE0
_08066DC6:
	adds r0, r4, #0
	bl FUN_08066abc
	b _08066DE0
_08066DCE:
	ldr r1, _08066DF0 @ =0x000003CE
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _08066DE0
	adds r0, r4, #0
	bl FUN_08066d10
_08066DE0:
	ldr r0, _08066DF4 @ =0x000003D1
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08066DF0: .4byte 0x000003CE
_08066DF4: .4byte 0x000003D1

	thumb_func_start FUN_08066df8
FUN_08066df8: @ 0x08066DF8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r1, #0x2c
	ldrsh r0, [r6, r1]
	movs r2, #0xf2
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	ldr r4, _08066E78 @ =0x03003540
	movs r2, #0
	ldrsh r1, [r4, r2]
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #5
	bl Div
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r5, r6, r1
	strh r0, [r5]
	movs r2, #0x2e
	ldrsh r0, [r6, r2]
	ldr r2, _08066E7C @ =0x000003CA
	adds r1, r6, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	movs r2, #2
	ldrsh r1, [r4, r2]
	lsls r1, r1, #2
	adds r1, #0x96
	adds r0, r0, r1
	movs r1, #5
	bl Div
	ldr r2, _08066E80 @ =0x000003C2
	adds r1, r6, r2
	strh r0, [r1]
	movs r1, #0x30
	ldrsh r0, [r6, r1]
	adds r2, #0xa
	adds r1, r6, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	movs r2, #4
	ldrsh r1, [r4, r2]
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #5
	bl Div
	movs r2, #0xf1
	lsls r2, r2, #2
	adds r1, r6, r2
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_0823bac8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08066E78: .4byte 0x03003540
_08066E7C: .4byte 0x000003CA
_08066E80: .4byte 0x000003C2

	thumb_func_start FUN_08066e84
FUN_08066e84: @ 0x08066E84
	push {lr}
	sub sp, #4
	movs r1, #6
	mov r0, sp
	strh r1, [r0]
	movs r0, #0x11
	mov r1, sp
	bl sub_080EC79C
	add sp, #4
	pop {r0}
	bx r0

	thumb_func_start FUN_08066e9c
FUN_08066e9c: @ 0x08066E9C
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r5, [sp, #0x1c]
	ldr r6, [sp, #0x24]
	movs r7, #0
	ldrsh r0, [r1, r7]
	movs r7, #4
	ldrsh r1, [r1, r7]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r3, [sp]
	ldrh r3, [r4, #0x24]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_08240cf0
	cmp r5, #0
	beq _08066ED0
	adds r0, r4, #0
	adds r1, r5, #0
	ldr r2, [sp, #0x20]
	bl FUN_080613ec
_08066ED0:
	cmp r6, #0
	beq _08066EDA
	adds r0, r6, #0
	bl PlaySound_082406e0
_08066EDA:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08066ee4
FUN_08066ee4: @ 0x08066EE4
	push {lr}
	cmp r0, #0
	bne _08066EF4
	ldr r0, _08066EF0 @ =0x085ABB2C
	b _08066F0A
	.align 2, 0
_08066EF0: .4byte 0x085ABB2C
_08066EF4:
	cmp r0, #1
	bne _08066F00
	ldr r0, _08066EFC @ =0x085ABB9E
	b _08066F0A
	.align 2, 0
_08066EFC: .4byte 0x085ABB9E
_08066F00:
	cmp r0, #5
	beq _08066F08
	movs r0, #0
	b _08066F10
_08066F08:
	ldr r0, _08066F14 @ =0x085ABC10
_08066F0A:
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r0, [r1]
_08066F10:
	pop {r1}
	bx r1
	.align 2, 0
_08066F14: .4byte 0x085ABC10

	thumb_func_start FUN_08066f18
FUN_08066f18: @ 0x08066F18
	push {r4, r5, r6, r7, lr}
	mov ip, r0
	ldr r0, _08066F38 @ =0x00000292
	add r0, ip
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r2, r1
	beq _08066F6C
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08066F3C
_08066F34:
	adds r0, r2, #0
	b _08066F74
	.align 2, 0
_08066F38: .4byte 0x00000292
_08066F3C:
	adds r4, r2, #1
	movs r0, #7
	ands r4, r0
	adds r3, r2, #7
	ands r3, r0
	movs r5, #2
	adds r6, r1, #0
	movs r1, #0xa5
	lsls r1, r1, #2
	add r1, ip
_08066F50:
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, r6
	beq _08066F64
	cmp r0, r4
	beq _08066F74
	cmp r0, r3
	beq _08066F74
	cmp r0, r2
	bne _08066F34
_08066F64:
	adds r1, #2
	adds r5, #1
	cmp r5, #9
	ble _08066F50
_08066F6C:
	movs r0, #0xba
	lsls r0, r0, #2
	add r0, ip
	ldrb r0, [r0]
_08066F74:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08066f7c
FUN_08066f7c: @ 0x08066F7C
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08066FAA
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	adds r0, r4, #0
	bl FUN_08066f18
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080609dc
_08066FAA:
	ldr r0, [r4, #0x20]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x20]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08066fd4
FUN_08066fd4: @ 0x08066FD4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0806701C @ =0x00000446
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _08066FF0
	ldr r2, _08067020 @ =0x00000442
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #1
	bne _08066FF0
	movs r1, #1
_08066FF0:
	cmp r1, #0
	bne _08067018
	ldr r1, _08067024 @ =0x00000362
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	subs r0, #0x64
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x64
	bl Div
	adds r1, r0, #0
	cmp r1, #0x10
	ble _08067028
_08067018:
	movs r1, #0x10
	b _0806702E
	.align 2, 0
_0806701C: .4byte 0x00000446
_08067020: .4byte 0x00000442
_08067024: .4byte 0x00000362
_08067028:
	cmp r1, #8
	bgt _0806702E
	movs r1, #9
_0806702E:
	ldr r2, _08067058 @ =0x000004C5
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #2
	bne _08067044
	adds r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08067044
	subs r1, #4
_08067044:
	ldr r0, _0806705C @ =0x00000402
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _08067050
	subs r1, r1, r0
_08067050:
	cmp r1, #1
	ble _08067060
	adds r0, r1, #0
	b _08067062
	.align 2, 0
_08067058: .4byte 0x000004C5
_0806705C: .4byte 0x00000402
_08067060:
	movs r0, #2
_08067062:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08067068
FUN_08067068: @ 0x08067068
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r2, r0, #0
	movs r0, #0xa4
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r3, #0
	ldrsh r4, [r1, r3]
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	bne _080670C2
	adds r5, r4, #1
	movs r0, #7
	ands r5, r0
	mov sb, r5
	adds r3, r4, #7
	ands r3, r0
	movs r6, #1
	mov r8, r1
	movs r7, #1
	rsbs r7, r7, #0
	mov ip, r7
	ldr r0, _080670D0 @ =0x00000292
	adds r1, r2, r0
_0806709E:
	movs r5, #0
	ldrsh r2, [r1, r5]
	cmp r2, ip
	beq _080670BA
	adds r0, r2, #0
	cmp r0, sb
	beq _080670C4
	cmp r0, r3
	beq _080670C4
	mov r5, r8
	movs r7, #0
	ldrsh r0, [r5, r7]
	cmp r2, r0
	bne _080670C2
_080670BA:
	adds r1, #2
	adds r6, #1
	cmp r6, #4
	ble _0806709E
_080670C2:
	adds r0, r4, #0
_080670C4:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080670D0: .4byte 0x00000292

	thumb_func_start FUN_080670d4
FUN_080670d4: @ 0x080670D4
	push {lr}
	adds r1, r0, #0
	cmp r1, #0xc
	bne _080670E0
	movs r0, #0x40
	b _080670F6
_080670E0:
	cmp r1, #0xb
	ble _080670EE
	subs r1, #0xc
	lsls r1, r1, #2
	movs r0, #0x40
	subs r0, r0, r1
	b _080670F6
_080670EE:
	movs r0, #0xc
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x40
_080670F6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080670fc
FUN_080670fc: @ 0x080670FC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	mov r8, r1
	adds r0, #0x9c
	ldrh r1, [r0]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _08067116
	b _080672A2
_08067116:
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	beq _08067122
	b _080672A2
_08067122:
	ldr r1, _08067164 @ =0x00000446
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r6, #0
	adds r7, r0, #0
	cmp r1, #0
	beq _0806713C
	ldr r2, _08067168 @ =0x00000442
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _0806713C
	movs r6, #1
_0806713C:
	cmp r6, #0
	beq _08067142
	b _080672A2
_08067142:
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	bl FUN_0809f658
	cmp r0, #0
	beq _0806717A
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _08067170
	str r4, [sp]
	str r6, [sp, #4]
	ldr r0, _0806716C @ =0x00000163
	b _080671C2
	.align 2, 0
_08067164: .4byte 0x00000446
_08067168: .4byte 0x00000442
_0806716C: .4byte 0x00000163
_08067170:
	str r4, [sp]
	str r6, [sp, #4]
	movs r0, #0xb1
	lsls r0, r0, #1
	b _080671C2
_0806717A:
	movs r1, #0xe5
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	bl FUN_08065a98
	cmp r0, #0
	beq _080671D8
	ldrh r0, [r7]
	movs r1, #0
	cmp r0, #0
	beq _0806719E
	ldr r2, _080671B8 @ =0x00000442
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #5
	bne _0806719E
	movs r1, #1
_0806719E:
	cmp r1, #0
	bne _080671D8
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _080671BC
	str r4, [sp]
	str r1, [sp, #4]
	movs r0, #0xca
	lsls r0, r0, #1
	b _080671C2
	.align 2, 0
_080671B8: .4byte 0x00000442
_080671BC:
	str r4, [sp]
	str r1, [sp, #4]
	ldr r0, _080671D4 @ =0x00000193
_080671C2:
	str r0, [sp, #8]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #1
	movs r3, #1
	bl FUN_08066e9c
	b _080672A2
	.align 2, 0
_080671D4: .4byte 0x00000193
_080671D8:
	mov r0, r8
	cmp r0, #0
	bne _08067266
	ldrh r0, [r7]
	movs r1, #0
	cmp r0, #0
	beq _080671F2
	ldr r2, _08067208 @ =0x00000442
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #5
	bne _080671F2
	movs r1, #1
_080671F2:
	cmp r1, #0
	beq _08067214
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _0806720C
	movs r0, #0xc8
	bl PlaySound_082406e0
	b _08067266
	.align 2, 0
_08067208: .4byte 0x00000442
_0806720C:
	movs r0, #0xc7
	bl PlaySound_082406e0
	b _08067266
_08067214:
	movs r1, #0xe4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0806722A
	ldr r2, _0806723C @ =0x000001C7
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08067248
_0806722A:
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _08067240
	movs r0, #0xca
	bl PlaySound_082406e0
	b _08067266
	.align 2, 0
_0806723C: .4byte 0x000001C7
_08067240:
	movs r0, #0xc9
	bl PlaySound_082406e0
	b _08067266
_08067248:
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _08067260
	ldr r0, _0806725C @ =0x0000028E
	bl PlaySound_082406e0
	b _08067266
	.align 2, 0
_0806725C: .4byte 0x0000028E
_08067260:
	ldr r0, _0806727C @ =0x0000028D
	bl PlaySound_082406e0
_08067266:
	movs r1, #1
	ldr r0, _08067280 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _08067284 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08067288
	movs r0, #1
	b _0806728A
	.align 2, 0
_0806727C: .4byte 0x0000028D
_08067280: .4byte 0x030046A0
_08067284: .4byte 0x00000934
_08067288:
	movs r0, #0
_0806728A:
	cmp r0, #0
	beq _080672A2
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #1
	movs r3, #2
	bl FUN_08066e9c
_080672A2:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080672b0
FUN_080672b0: @ 0x080672B0
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0xdf
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r4, #0x20]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x20]
	adds r0, r4, #0
	bl FUN_08067068
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0806731C
	adds r0, r4, #0
	bl FUN_08066fd4
	adds r5, r0, #0
	bl FUN_080670d4
	ldr r2, _08067348 @ =0x00000446
	adds r0, r4, r2
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _08067306
	subs r2, #4
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #5
	bne _08067306
	movs r1, #1
_08067306:
	cmp r1, #0
	beq _08067314
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	muls r0, r5, r0
	asrs r5, r0, #6
_08067314:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08060aa4
_0806731C:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080670fc
	adds r0, r4, #0
	bl FUN_080609dc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #1
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08067348: .4byte 0x00000446

	thumb_func_start FUN_0806734c
FUN_0806734c: @ 0x0806734C
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080673D2
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08064d6c
	cmp r0, #0
	beq _080673C0
	ldr r0, _080673B0 @ =0x00000392
	bl PlaySound_082406e0
	ldr r0, _080673B4 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _080673B8 @ =0x00000942
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #1
	adds r0, #0xe
	movs r2, #0xff
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x20
	bls _08067392
	movs r0, #0x20
	strb r0, [r1]
_08067392:
	movs r0, #0x80
	lsls r0, r0, #2
	ldrb r1, [r1]
	bl Div
	ldr r3, _080673BC @ =0x000003FD
	adds r1, r4, r3
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	bl FUN_08060b84
	b _080673D2
	.align 2, 0
_080673B0: .4byte 0x00000392
_080673B4: .4byte 0x030046A0
_080673B8: .4byte 0x00000942
_080673BC: .4byte 0x000003FD
_080673C0:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #2
	movs r2, #1
	bl FUN_08060b84
_080673D2:
	ldr r1, _080673E4 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080673E8
	cmp r0, #1
	beq _0806749C
	b _080674D0
	.align 2, 0
_080673E4: .4byte 0x0000037D
_080673E8:
	ldr r3, _0806740C @ =0x0000037E
	adds r2, r4, r3
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	adds r3, #0x7f
	adds r1, r4, r3
	ldrb r3, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r3
	blo _08067410
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	b _080674D0
	.align 2, 0
_0806740C: .4byte 0x0000037E
_08067410:
	ldrh r1, [r2]
	adds r0, r3, #0
	subs r0, #8
	cmp r1, r0
	bge _0806742C
	ldr r0, _08067490 @ =0x0000095E
	adds r1, r4, r0
	ldr r0, _08067494 @ =0x00000125
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r4, r2
	movs r0, #0x20
	strh r0, [r1]
_0806742C:
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08067458
	ldr r3, _08067498 @ =0x000003CE
	adds r0, r4, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _08067458
	adds r0, r4, #0
	bl FUN_08067068
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
_08067458:
	movs r3, #0xff
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_08060aa4
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080670fc
	adds r0, r4, #0
	bl FUN_080609dc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #1
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x20
	bl FUN_08060a24
	b _080674D0
	.align 2, 0
_08067490: .4byte 0x0000095E
_08067494: .4byte 0x00000125
_08067498: .4byte 0x000003CE
_0806749C:
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
	ldr r3, _080674D8 @ =0x0000037E
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080674D0
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_080674D0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080674D8: .4byte 0x0000037E

	thumb_func_start FUN_080674dc
FUN_080674dc: @ 0x080674DC
	push {lr}
	adds r1, r0, #0
	ldr r2, _080674F4 @ =0x000003BD
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _080674EE
	cmp r0, #5
	bne _080674F8
_080674EE:
	ldrh r1, [r1, #0x2c]
	b _080674FA
	.align 2, 0
_080674F4: .4byte 0x000003BD
_080674F8:
	ldrh r1, [r1, #0x30]
_080674FA:
	movs r0, #0xff
	ands r0, r1
	subs r0, #0x1f
	cmp r0, #0xc2
	bhi _08067508
	movs r0, #1
	b _0806750A
_08067508:
	movs r0, #0
_0806750A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08067510
FUN_08067510: @ 0x08067510
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x2c
	adds r7, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r1, #4
	strb r1, [r0]
	ldr r2, _08067560 @ =0x0000037D
	adds r0, r7, r2
	ldrb r1, [r0]
	cmp r1, #1
	bne _0806754A
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r7, r3
	ldr r0, [r0]
	ldrh r0, [r0, #2]
	ands r1, r0
	cmp r1, #0
	beq _0806754A
	adds r0, r7, #0
	movs r1, #4
	movs r2, #2
	bl FUN_08060b84
_0806754A:
	ldr r1, _08067560 @ =0x0000037D
	adds r0, r7, r1
	ldrb r4, [r0]
	cmp r4, #1
	beq _08067610
	cmp r4, #1
	bgt _08067564
	cmp r4, #0
	beq _0806756E
	bl _08067DD4
	.align 2, 0
_08067560: .4byte 0x0000037D
_08067564:
	cmp r4, #2
	bne _0806756A
	b _08067A96
_0806756A:
	bl _08067DD4
_0806756E:
	movs r1, #4
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrb r0, [r0]
	movs r1, #2
	bl FUN_08066ee4
	mov r8, r0
	movs r3, #0xb9
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r0, r8
	beq _080675E6
	movs r0, #0xd0
	bl PlaySound_082406e0
	ldr r0, _080675D0 @ =0x000003BD
	adds r2, r7, r0
	ldrb r0, [r2]
	adds r0, #4
	movs r1, #7
	ands r0, r1
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r7, r3
	strb r0, [r1]
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080675D8
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _080675D4 @ =0x000002E6
	adds r1, r7, r2
	strb r0, [r1]
	subs r3, #1
	adds r1, r7, r3
	movs r0, #1
	strb r0, [r1]
	b _080675E6
	.align 2, 0
_080675D0: .4byte 0x000003BD
_080675D4: .4byte 0x000002E6
_080675D8:
	lsrs r0, r1, #0x19
	ldr r2, _08067608 @ =0x000002E6
	adds r1, r7, r2
	strb r0, [r1]
	ldr r3, _0806760C @ =0x000002E7
	adds r0, r7, r3
	strb r4, [r0]
_080675E6:
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	bne _080675F8
	bl _08067DD4
_080675F8:
	adds r0, r7, #0
	movs r1, #4
	movs r2, #1
	bl FUN_08060b84
	bl _08067DD4
	.align 2, 0
_08067608: .4byte 0x000002E6
_0806760C: .4byte 0x000002E7
_08067610:
	movs r1, #8
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r7, r1
	strb r4, [r0]
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r7, r2
	movs r3, #0
	ldrsh r6, [r0, r3]
	adds r1, #1
	adds r0, r7, r1
	ldrb r1, [r0]
	adds r4, r1, #7
	movs r0, #7
	ands r4, r0
	adds r5, r1, #1
	ands r5, r0
	adds r2, #0xc8
	adds r0, r7, r2
	ldrb r0, [r0]
	movs r1, #3
	bl FUN_08066ee4
	mov r8, r0
	cmp r6, r4
	beq _080676B8
	cmp r6, r5
	beq _080676B8
	adds r0, r7, #0
	bl FUN_080674dc
	cmp r0, #0
	bne _0806765C
	b _08067A50
_0806765C:
	adds r0, r7, #0
	adds r0, #0x2c
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r7, r3
	ldrb r1, [r1]
	bl FUN_08003f24
	cmp r0, #0
	bgt _08067672
	b _08067A50
_08067672:
	ldr r1, _0806769C @ =0x00000446
	adds r0, r7, r1
	ldrh r0, [r0]
	movs r4, #0
	cmp r0, #0
	beq _0806768A
	ldr r2, _080676A0 @ =0x00000442
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #2
	bne _0806768A
	movs r4, #1
_0806768A:
	cmp r4, #0
	beq _080676A4
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	b _08067A50
	.align 2, 0
_0806769C: .4byte 0x00000446
_080676A0: .4byte 0x00000442
_080676A4:
	adds r0, r7, #0
	movs r1, #5
	movs r2, #0
	bl FUN_08060b84
	movs r3, #0xef
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r4, [r0]
	b _08067A50
_080676B8:
	ldr r1, _080676F8 @ =0x000003BD
	adds r0, r7, r1
	ldrb r1, [r0]
	subs r0, r6, r1
	lsls r0, r0, #1
	adds r0, #8
	adds r1, r1, r0
	movs r0, #7
	ands r1, r0
	adds r6, r1, #1
	ands r6, r0
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r2, _080676FC @ =0x085B0A08
	lsls r0, r6, #5
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x32
	muls r0, r1, r0
	mov ip, r2
	cmp r0, #0
	blt _08067700
	asrs r2, r0, #0xc
	b _08067706
	.align 2, 0
_080676F8: .4byte 0x000003BD
_080676FC: .4byte 0x085B0A08
_08067700:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08067706:
	add r0, sp, #0xc
	ldrh r1, [r0]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08067738 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	lsls r2, r6, #5
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #1
	add r0, ip
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x32
	muls r0, r1, r0
	mov sb, r2
	cmp r0, #0
	blt _0806773C
	asrs r0, r0, #0xc
	b _08067742
	.align 2, 0
_08067738: .4byte 0xFFFF0000
_0806773C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08067742:
	add r3, sp, #0xc
	ldrh r1, [r3, #4]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08067780 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r0, r3, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0806777C
	cmp r1, #0
	blt _0806777C
	ldr r0, _08067784 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0806777C
	ldr r0, _08067788 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0806778C
_0806777C:
	movs r6, #0
	b _0806779A
	.align 2, 0
_08067780: .4byte 0xFFFF0000
_08067784: .4byte 0x030046A8
_08067788: .4byte 0x030046AC
_0806778C:
	ldr r0, _080677C8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_0806779A:
	add r5, sp, #0xc
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080677C2
	cmp r1, #0
	blt _080677C2
	ldr r0, _080677CC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080677C2
	ldr r0, _080677D0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080677D4
_080677C2:
	movs r4, #0
	b _080677E2
	.align 2, 0
_080677C8: .4byte 0x030046A4
_080677CC: .4byte 0x030046A8
_080677D0: .4byte 0x030046AC
_080677D4:
	ldr r0, _080677F4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080677E2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080677F8
	adds r0, #4
	b _08067804
	.align 2, 0
_080677F4: .4byte 0x030046A4
_080677F8:
	ldr r0, _08067818 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08067804:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0806781C
	cmp r2, #2
	beq _08067820
	b _08067824
	.align 2, 0
_08067818: .4byte 0x030046A4
_0806781C:
	ldrb r0, [r5, #4]
	b _08067822
_08067820:
	ldrb r0, [r5]
_08067822:
	subs r1, r1, r0
_08067824:
	adds r5, r1, #0
	movs r0, #0x2e
	ldrsh r1, [r7, r0]
	adds r0, r1, #0
	subs r0, #0x80
	cmp r5, r0
	bgt _08067834
	b _08067A50
_08067834:
	adds r0, r1, #0
	adds r0, #0x80
	cmp r5, r0
	blt _0806783E
	b _08067A50
_0806783E:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0806784E
	adds r0, #4
	b _0806785A
_0806784E:
	ldr r0, _08067894 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0806785A:
	ldrh r0, [r0, #2]
	bl FUN_08065b44
	cmp r0, #0
	beq _08067866
	b _08067A50
_08067866:
	ldr r2, _08067898 @ =0x085B0A08
	ldr r1, _0806789C @ =0x000003BD
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x32
	muls r0, r1, r0
	mov ip, r2
	cmp r0, #0
	blt _080678A0
	asrs r1, r0, #0xc
	b _080678A6
	.align 2, 0
_08067894: .4byte 0x030046A4
_08067898: .4byte 0x085B0A08
_0806789C: .4byte 0x000003BD
_080678A0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080678A6:
	add r0, sp, #0xc
	ldrh r0, [r0]
	subs r0, r0, r1
	add r1, sp, #0xc
	strh r0, [r1]
	ldr r1, _080678D0 @ =0x000003BD
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #6
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _080678D4
	asrs r2, r0, #0xc
	b _080678DA
	.align 2, 0
_080678D0: .4byte 0x000003BD
_080678D4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080678DA:
	add r0, sp, #0xc
	ldrh r1, [r0, #4]
	subs r1, r1, r2
	strh r1, [r0, #4]
	adds r6, r0, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08067906
	cmp r1, #0
	blt _08067906
	ldr r0, _0806790C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08067906
	ldr r0, _08067910 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08067914
_08067906:
	movs r4, #0
	b _08067922
	.align 2, 0
_0806790C: .4byte 0x030046A8
_08067910: .4byte 0x030046AC
_08067914:
	ldr r0, _08067934 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08067922:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08067938
	adds r0, #4
	b _08067944
	.align 2, 0
_08067934: .4byte 0x030046A4
_08067938:
	ldr r0, _08067958 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08067944:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0806795C
	cmp r2, #2
	beq _08067960
	b _08067964
	.align 2, 0
_08067958: .4byte 0x030046A4
_0806795C:
	ldrb r0, [r6, #4]
	b _08067962
_08067960:
	ldrb r0, [r6]
_08067962:
	subs r1, r1, r0
_08067964:
	adds r0, r5, #0
	adds r0, #0xc8
	cmp r1, r0
	blt _08067A50
	add r1, sp, #0xc
	adds r0, r1, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08067994
	cmp r1, #0
	blt _08067994
	ldr r0, _08067998 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08067994
	ldr r0, _0806799C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080679A0
_08067994:
	movs r4, #0
	b _080679AE
	.align 2, 0
_08067998: .4byte 0x030046A8
_0806799C: .4byte 0x030046AC
_080679A0:
	ldr r0, _080679C0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080679AE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080679C4
	adds r0, #4
	b _080679D0
	.align 2, 0
_080679C0: .4byte 0x030046A4
_080679C4:
	ldr r0, _08067A1C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080679D0:
	ldrh r0, [r0, #2]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08067A50
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrb r0, [r0]
	bl FUN_08066ee4
	mov r8, r0
	adds r0, r7, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _080679FC
	movs r3, #3
	cmp r0, #2
	bne _080679FC
	movs r3, #6
_080679FC:
	ldr r2, _08067A20 @ =0x085B0A08
	mov r0, sb
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	mov ip, r2
	cmp r0, #0
	blt _08067A24
	asrs r0, r0, #0xc
	b _08067A2A
	.align 2, 0
_08067A1C: .4byte 0x030046A4
_08067A20: .4byte 0x085B0A08
_08067A24:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08067A2A:
	rsbs r0, r0, #0
	strh r0, [r7, #0x34]
	movs r0, #0xff
	mov r2, sb
	ands r0, r2
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _08067A46
	asrs r0, r0, #0xc
	b _08067A4C
_08067A46:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08067A4C:
	rsbs r0, r0, #0
	strh r0, [r7, #0x38]
_08067A50:
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrh r4, [r0]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrb r0, [r0]
	movs r1, #4
	bl FUN_08066ee4
	cmp r4, r0
	beq _08067A76
	b _08067DD4
_08067A76:
	adds r0, r7, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	beq _08067A82
	b _08067DD4
_08067A82:
	adds r0, r7, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #1
	beq _08067A8E
	b _08067DD4
_08067A8E:
	movs r0, #0xdb
	bl PlaySound_082406e0
	b _08067DD4
_08067A96:
	movs r1, #8
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	movs r1, #5
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	bne _08067ABC
	b _08067DD4
_08067ABC:
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	ldr r3, _08067B20 @ =0x000003BD
	adds r2, r7, r3
	ldrb r2, [r2]
	adds r6, r1, #0
	adds r5, r0, #0
	cmp r2, #1
	bne _08067B2C
	add r4, sp, #0x14
	ldrh r0, [r4]
	adds r0, #0x1c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _08067B24 @ =0xFFFF0000
	ldr r2, [sp, #0x14]
	ands r2, r3
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0x2c
	lsls r1, r1, #0x10
	ldr r0, _08067B28 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x14]
	ldrh r0, [r4, #4]
	subs r0, #0x4c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r4, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [r4, #4]
	add r2, sp, #0x1c
	ldrh r0, [r2]
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x1c]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x1c]
	ldrh r0, [r2, #4]
	subs r0, #0x80
	b _08067BC2
	.align 2, 0
_08067B20: .4byte 0x000003BD
_08067B24: .4byte 0xFFFF0000
_08067B28: .4byte 0x0000FFFF
_08067B2C:
	cmp r2, #3
	bne _08067B78
	add r4, sp, #0x14
	ldrh r0, [r4]
	subs r0, #0x34
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _08067B70 @ =0xFFFF0000
	ldr r1, [sp, #0x14]
	ands r1, r3
	orrs r1, r0
	lsrs r2, r1, #0x10
	lsls r2, r2, #0x10
	ldr r0, _08067B74 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x14]
	ldrh r1, [r4, #4]
	ldr r0, [r4, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r4, #4]
	add r2, sp, #0x1c
	ldrh r0, [r2]
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x1c]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x1c]
	ldrh r0, [r2, #4]
	adds r0, #0x40
	b _08067BC2
	.align 2, 0
_08067B70: .4byte 0xFFFF0000
_08067B74: .4byte 0x0000FFFF
_08067B78:
	cmp r2, #5
	bne _08067BDC
	add r4, sp, #0x14
	ldrh r0, [r4]
	adds r0, #0xc
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _08067BD4 @ =0xFFFF0000
	ldr r2, [sp, #0x14]
	ands r2, r3
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0x2c
	lsls r1, r1, #0x10
	ldr r0, _08067BD8 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x14]
	ldrh r0, [r4, #4]
	subs r0, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r4, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [r4, #4]
	add r2, sp, #0x1c
	ldrh r0, [r2]
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x1c]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x1c]
	ldrh r0, [r2, #4]
	adds r0, #0x80
_08067BC2:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r2, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [r2, #4]
	mov r8, r2
	b _08067C38
	.align 2, 0
_08067BD4: .4byte 0xFFFF0000
_08067BD8: .4byte 0x0000FFFF
_08067BDC:
	add r4, sp, #0x14
	add r0, sp, #0x1c
	mov r8, r0
	cmp r2, #7
	bne _08067C38
	ldrh r0, [r4]
	subs r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _08067C68 @ =0xFFFF0000
	ldr r2, [sp, #0x14]
	ands r2, r3
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0x44
	lsls r1, r1, #0x10
	ldr r0, _08067C6C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x14]
	ldrh r0, [r4, #4]
	adds r0, #0x2c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r4, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [r4, #4]
	mov r1, r8
	ldrh r0, [r1]
	subs r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x1c]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x1c]
	mov r2, r8
	ldrh r0, [r2, #4]
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r2, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [r2, #4]
_08067C38:
	str r5, [sp, #0x24]
	str r6, [sp, #0x28]
	ldr r2, _08067C70 @ =0x085B0A08
	ldr r3, _08067C74 @ =0x000003BD
	adds r0, r7, r3
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x32
	muls r0, r1, r0
	mov ip, r2
	cmp r0, #0
	blt _08067C78
	asrs r0, r0, #0xc
	b _08067C7E
	.align 2, 0
_08067C68: .4byte 0xFFFF0000
_08067C6C: .4byte 0x0000FFFF
_08067C70: .4byte 0x085B0A08
_08067C74: .4byte 0x000003BD
_08067C78:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08067C7E:
	add r3, sp, #0x24
	ldrh r1, [r3]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08067CB4 @ =0xFFFF0000
	ldr r0, [sp, #0x24]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x24]
	ldr r1, _08067CB8 @ =0x000003BD
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #6
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	adds r5, r3, #0
	cmp r0, #0
	blt _08067CBC
	asrs r0, r0, #0xc
	b _08067CC2
	.align 2, 0
_08067CB4: .4byte 0xFFFF0000
_08067CB8: .4byte 0x000003BD
_08067CBC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08067CC2:
	ldrh r1, [r5, #4]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08067D00 @ =0xFFFF0000
	ldr r0, [r5, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r5, #4]
	add r0, sp, #0x24
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _08067CFA
	cmp r1, #0
	blt _08067CFA
	ldr r0, _08067D04 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _08067CFA
	ldr r0, _08067D08 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08067D0C
_08067CFA:
	movs r5, #0
	b _08067D1A
	.align 2, 0
_08067D00: .4byte 0xFFFF0000
_08067D04: .4byte 0x030046A8
_08067D08: .4byte 0x030046AC
_08067D0C:
	ldr r0, _08067D2C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r3
_08067D1A:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08067D30
	adds r0, #4
	b _08067D3C
	.align 2, 0
_08067D2C: .4byte 0x030046A4
_08067D30:
	ldr r0, _08067D60 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08067D3C:
	ldrh r0, [r0, #2]
	movs r2, #0x80
	lsls r2, r2, #1
	ands r0, r2
	cmp r0, #0
	beq _08067D64
	adds r1, r7, #0
	adds r1, #0x2c
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #0xeb
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r3, #1
	bl FUN_08066e9c
	b _08067D78
	.align 2, 0
_08067D60: .4byte 0x030046A4
_08067D64:
	adds r1, r7, #0
	adds r1, #0x2c
	str r4, [sp]
	str r0, [sp, #4]
	movs r0, #0xec
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r3, #1
	bl FUN_08066e9c
_08067D78:
	add r0, sp, #0x1c
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r3, r8
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08067DA0
	cmp r1, #0
	blt _08067DA0
	ldr r0, _08067DA4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08067DA0
	ldr r0, _08067DA8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08067DAC
_08067DA0:
	movs r0, #0
	b _08067DBA
	.align 2, 0
_08067DA4: .4byte 0x030046A8
_08067DA8: .4byte 0x030046AC
_08067DAC:
	ldr r0, _08067DE4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_08067DBA:
	bl FUN_08020358
	cmp r0, #0
	beq _08067DCA
	movs r0, #0xc2
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08067DCA:
	adds r0, r7, #0
	movs r1, #4
	movs r2, #1
	bl FUN_08060b84
_08067DD4:
	add sp, #0x2c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08067DE4: .4byte 0x030046A4

	thumb_func_start FUN_08067de8
FUN_08067de8: @ 0x08067DE8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08067E00 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _08067E9C
	cmp r0, #1
	bgt _08067E04
	cmp r0, #0
	beq _08067E0C
	b _08067F50
	.align 2, 0
_08067E00: .4byte 0x0000037D
_08067E04:
	cmp r0, #2
	bne _08067E0A
	b _08067F20
_08067E0A:
	b _08067F50
_08067E0C:
	ldr r2, _08067E38 @ =0x000003BD
	adds r0, r4, r2
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08067E3C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	cmp r0, #0
	blt _08067E40
	asrs r0, r0, #0xc
	b _08067E46
	.align 2, 0
_08067E38: .4byte 0x000003BD
_08067E3C: .4byte 0x085B0A08
_08067E40:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08067E46:
	strh r0, [r4, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	cmp r0, #0
	blt _08067E5A
	asrs r0, r0, #0xc
	b _08067E60
_08067E5A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08067E60:
	strh r0, [r4, #0x38]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #6
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _08067E98 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bls _08067F50
	adds r0, r4, #0
	movs r1, #5
	movs r2, #1
	bl FUN_08060b84
	b _08067F50
	.align 2, 0
_08067E98: .4byte 0x0000037E
_08067E9C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #6
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, _08067EFC @ =0x000003BD
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r1, r0
	bne _08067F14
	adds r0, r4, #0
	adds r0, #0x2c
	subs r2, #0xd5
	adds r1, r4, r2
	ldrb r1, [r1]
	bl FUN_08003f24
	cmp r0, #0
	ble _08067F14
	ldr r1, _08067F00 @ =0x00000446
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _08067EF2
	ldr r2, _08067F04 @ =0x00000442
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #2
	bne _08067EF2
	movs r1, #1
_08067EF2:
	cmp r1, #0
	beq _08067F08
	adds r0, r4, #0
	movs r1, #0
	b _08067F0C
	.align 2, 0
_08067EFC: .4byte 0x000003BD
_08067F00: .4byte 0x00000446
_08067F04: .4byte 0x00000442
_08067F08:
	adds r0, r4, #0
	movs r1, #5
_08067F0C:
	movs r2, #0
	bl FUN_08060b84
	b _08067F50
_08067F14:
	adds r0, r4, #0
	movs r1, #5
	movs r2, #2
	bl FUN_08060b84
	b _08067F50
_08067F20:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #7
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08067F50
	adds r0, r4, #0
	movs r1, #4
	movs r2, #1
	bl FUN_08060b84
	movs r2, #0xef
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
_08067F50:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08067f58
FUN_08067f58: @ 0x08067F58
	push {lr}
	adds r2, r0, #0
	movs r1, #0x10
	ldr r0, [r2, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _08067F80
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r3, _08067F7C @ =0x0000036A
	adds r1, r2, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _08067F80
	movs r0, #1
	b _08067F82
	.align 2, 0
_08067F7C: .4byte 0x0000036A
_08067F80:
	movs r0, #0
_08067F82:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08067f88
FUN_08067f88: @ 0x08067F88
	push {lr}
	adds r3, r0, #0
	movs r0, #0x93
	lsls r0, r0, #4
	adds r2, r3, r0
	ldr r0, [r3, #0x2c]
	ldr r1, [r3, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne _08067FD0
	ldrh r0, [r2]
	subs r0, #0x14
	strh r0, [r2]
	ldr r2, _08067FC8 @ =0x00000932
	adds r1, r3, r2
	movs r2, #0xa5
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r0, _08067FCC @ =0x00000934
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r0, #0x3c
	b _08067FEE
	.align 2, 0
_08067FC8: .4byte 0x00000932
_08067FCC: .4byte 0x00000934
_08067FD0:
	ldrh r0, [r2]
	adds r0, #0x14
	strh r0, [r2]
	ldr r2, _08067FF4 @ =0x00000932
	adds r1, r3, r2
	movs r2, #0xa5
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r0, _08067FF8 @ =0x00000934
	adds r1, r3, r0
	ldrh r0, [r1]
	subs r0, #0x1e
_08067FEE:
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08067FF4: .4byte 0x00000932
_08067FF8: .4byte 0x00000934

	thumb_func_start FUN_08067ffc
FUN_08067ffc: @ 0x08067FFC
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #7
	beq _0806801E
	adds r0, r4, #0
	movs r1, #7
	movs r2, #0
	bl FUN_08060b84
	ldr r2, _08068034 @ =0x00000951
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
_0806801E:
	ldr r1, _08068038 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bls _0806802A
	b _080682D2
_0806802A:
	lsls r0, r0, #2
	ldr r1, _0806803C @ =_08068040
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08068034: .4byte 0x00000951
_08068038: .4byte 0x0000037D
_0806803C: .4byte _08068040
_08068040: @ jump table
	.4byte _08068054 @ case 0
	.4byte _08068078 @ case 1
	.4byte _0806814C @ case 2
	.4byte _08068210 @ case 3
	.4byte _0806828C @ case 4
_08068054:
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
	adds r0, r4, #0
	movs r1, #7
	movs r2, #1
	bl FUN_08060b84
	b _080682D2
_08068078:
	ldr r1, _080680A4 @ =0x0000037E
	adds r0, r4, r1
	ldrh r2, [r0]
	cmp r2, #0
	bne _080680CE
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _080680B0
	movs r0, #4
	strb r0, [r1]
	ldr r0, _080680A8 @ =0x000002E6
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080680AC @ =0x000002E7
	b _080680BA
	.align 2, 0
_080680A4: .4byte 0x0000037E
_080680A8: .4byte 0x000002E6
_080680AC: .4byte 0x000002E7
_080680B0:
	strb r2, [r1]
	ldr r1, _08068130 @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
_080680BA:
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_08067f88
	ldr r2, _08068134 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_080680CE:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #8
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	bne _080680F6
	b _080682D2
_080680F6:
	movs r0, #0xcb
	bl PlaySound_082406e0
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08068110
	b _0806824C
_08068110:
	adds r0, r4, #0
	bl FUN_08067f58
	adds r1, r0, #0
	cmp r1, #0
	beq _08068140
	movs r0, #0xd8
	bl PlaySound_082406e0
	ldr r0, _08068138 @ =0x00000409
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _0806813C @ =0x00000404
	adds r1, r4, r2
	b _08068274
	.align 2, 0
_08068130: .4byte 0x000002E6
_08068134: .4byte 0x0000037E
_08068138: .4byte 0x00000409
_0806813C: .4byte 0x00000404
_08068140:
	ldr r2, _08068148 @ =0x00000404
	adds r0, r4, r2
	strh r1, [r0]
	b _080681FE
	.align 2, 0
_08068148: .4byte 0x00000404
_0806814C:
	movs r1, #0xa0
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	ldr r0, _08068180 @ =0x00000404
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #4
	bhi _0806818C
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bne _0806818C
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _08068184
	movs r0, #0xc2
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _0806818C
	.align 2, 0
_08068180: .4byte 0x00000404
_08068184:
	movs r0, #0x94
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0806818C:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
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
	movs r5, #0
	movs r0, #0x1e
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_08067f88
	movs r2, #0x93
	lsls r2, r2, #4
	adds r1, r4, r2
	adds r0, r4, #0
	bl FUN_08061f6c
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080681E8
	movs r0, #0xd8
	bl sound_08240740
	ldr r2, _080681E4 @ =0x00000409
	adds r0, r4, r2
	strb r5, [r0]
	b _0806824C
	.align 2, 0
_080681E4: .4byte 0x00000409
_080681E8:
	adds r0, r4, #0
	bl FUN_08067f58
	cmp r0, #0
	bne _080682D2
	movs r0, #0xd8
	bl sound_08240740
	ldr r1, _0806820C @ =0x00000409
	adds r0, r4, r1
	strb r5, [r0]
_080681FE:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #3
	bl FUN_08060b84
	b _080682D2
	.align 2, 0
_0806820C: .4byte 0x00000409
_08068210:
	movs r1, #0x80
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0xa
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
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08068258
_0806824C:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #4
	bl FUN_08060b84
	b _080682D2
_08068258:
	adds r0, r4, #0
	bl FUN_08067f58
	cmp r0, #0
	beq _080682D2
	movs r0, #0xd8
	bl PlaySound_082406e0
	ldr r2, _08068284 @ =0x00000409
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _08068288 @ =0x00000404
	adds r1, r4, r0
_08068274:
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #7
	movs r2, #2
	bl FUN_08060b84
	b _080682D2
	.align 2, 0
_08068284: .4byte 0x00000409
_08068288: .4byte 0x00000404
_0806828C:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0xb
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _080682D2
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r1, [r0]
	subs r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _080682D8 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_080682D2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080682D8: .4byte 0x000002E7

	thumb_func_start FUN_080682dc
FUN_080682dc: @ 0x080682DC
	push {lr}
	adds r2, r0, #0
	movs r1, #0x10
	ldr r0, [r2, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08068304
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r3, _08068300 @ =0x0000036A
	adds r1, r2, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _08068304
	movs r0, #1
	b _08068306
	.align 2, 0
_08068300: .4byte 0x0000036A
_08068304:
	movs r0, #0
_08068306:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0806830c
FUN_0806830c: @ 0x0806830C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #7
	beq _08068326
	adds r0, r4, #0
	movs r1, #7
	movs r2, #0
	bl FUN_08060b84
_08068326:
	ldr r2, _0806833C @ =0x0000037D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #4
	bls _08068332
	b _0806861A
_08068332:
	lsls r0, r0, #2
	ldr r1, _08068340 @ =_08068344
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806833C: .4byte 0x0000037D
_08068340: .4byte _08068344
_08068344: @ jump table
	.4byte _08068358 @ case 0
	.4byte _0806837C @ case 1
	.4byte _08068454 @ case 2
	.4byte _08068554 @ case 3
	.4byte _080685D4 @ case 4
_08068358:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	adds r0, r4, #0
	movs r1, #7
	movs r2, #1
	bl FUN_08060b84
	b _0806861A
_0806837C:
	ldr r2, _080683A8 @ =0x0000037E
	adds r0, r4, r2
	ldrh r2, [r0]
	cmp r2, #0
	bne _080683D2
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _080683B4
	movs r0, #4
	strb r0, [r1]
	ldr r0, _080683AC @ =0x000002E6
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080683B0 @ =0x000002E7
	b _080683BE
	.align 2, 0
_080683A8: .4byte 0x0000037E
_080683AC: .4byte 0x000002E6
_080683B0: .4byte 0x000002E7
_080683B4:
	strb r2, [r1]
	ldr r1, _08068438 @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
_080683BE:
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_08067f88
	ldr r2, _0806843C @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_080683D2:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #8
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	bne _080683FA
	b _0806861A
_080683FA:
	movs r0, #0xcb
	bl PlaySound_082406e0
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08068414
	b _08068590
_08068414:
	adds r0, r4, #0
	bl FUN_080682dc
	adds r1, r0, #0
	cmp r1, #0
	beq _08068448
	movs r0, #0xb9
	lsls r0, r0, #2
	bl PlaySound_082406e0
	ldr r0, _08068440 @ =0x00000409
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _08068444 @ =0x00000404
	adds r1, r4, r2
	b _080685B8
	.align 2, 0
_08068438: .4byte 0x000002E6
_0806843C: .4byte 0x0000037E
_08068440: .4byte 0x00000409
_08068444: .4byte 0x00000404
_08068448:
	ldr r2, _08068450 @ =0x00000404
	adds r0, r4, r2
	strh r1, [r0]
	b _0806853E
	.align 2, 0
_08068450: .4byte 0x00000404
_08068454:
	movs r1, #0xa0
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	ldr r0, _080684C8 @ =0x00000404
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #4
	bhi _08068478
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bne _08068478
	ldr r0, _080684CC @ =0x00000239
	bl PlaySound_082406e0
_08068478:
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
	adds r0, r4, #0
	bl FUN_08067f88
	movs r0, #0x93
	lsls r0, r0, #4
	adds r1, r4, r0
	adds r0, r4, #0
	bl FUN_080620f0
	ldr r2, _080684D0 @ =0x0000095E
	adds r1, r4, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r1, _080684D4 @ =0x0000037E
	adds r0, r4, r1
	ldrh r1, [r0]
	cmp r1, #0x1f
	bhi _080684D8
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	b _080684E4
	.align 2, 0
_080684C8: .4byte 0x00000404
_080684CC: .4byte 0x00000239
_080684D0: .4byte 0x0000095E
_080684D4: .4byte 0x0000037E
_080684D8:
	movs r0, #0x40
	subs r0, r0, r1
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r4, r2
	strh r0, [r1]
_080684E4:
	ldr r0, _0806851C @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	movs r5, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x40
	bls _080684FC
	movs r0, #0
	strh r0, [r1]
_080684FC:
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08068528
	ldr r0, _08068520 @ =0x00000239
	bl sound_08240740
	ldr r2, _08068524 @ =0x00000409
	adds r0, r4, r2
	strb r5, [r0]
	b _08068590
	.align 2, 0
_0806851C: .4byte 0x0000037E
_08068520: .4byte 0x00000239
_08068524: .4byte 0x00000409
_08068528:
	adds r0, r4, #0
	bl FUN_080682dc
	cmp r0, #0
	bne _0806861A
	ldr r0, _0806854C @ =0x00000239
	bl sound_08240740
	ldr r1, _08068550 @ =0x00000409
	adds r0, r4, r1
	strb r5, [r0]
_0806853E:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #3
	bl FUN_08060b84
	b _0806861A
	.align 2, 0
_0806854C: .4byte 0x00000239
_08068550: .4byte 0x00000409
_08068554:
	movs r1, #0x80
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0xa
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
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0806859C
_08068590:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #4
	bl FUN_08060b84
	b _0806861A
_0806859C:
	adds r0, r4, #0
	bl FUN_080682dc
	cmp r0, #0
	beq _0806861A
	ldr r0, _080685C8 @ =0x00000239
	bl PlaySound_082406e0
	ldr r2, _080685CC @ =0x00000409
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080685D0 @ =0x00000404
	adds r1, r4, r0
_080685B8:
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #7
	movs r2, #2
	bl FUN_08060b84
	b _0806861A
	.align 2, 0
_080685C8: .4byte 0x00000239
_080685CC: .4byte 0x00000409
_080685D0: .4byte 0x00000404
_080685D4:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0xb
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806861A
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r1, [r0]
	subs r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _08068620 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806861A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08068620: .4byte 0x000002E7

	thumb_func_start FUN_08068624
FUN_08068624: @ 0x08068624
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r1, _08068640 @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #4
	bls _08068634
	b _0806893C
_08068634:
	lsls r0, r0, #2
	ldr r1, _08068644 @ =_08068648
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08068640: .4byte 0x0000037D
_08068644: .4byte _08068648
_08068648: @ jump table
	.4byte _0806865C @ case 0
	.4byte _080687A2 @ case 1
	.4byte _0806882C @ case 2
	.4byte _080688DA @ case 3
	.4byte _08068910 @ case 4
_0806865C:
	movs r2, #0xec
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #0x2c
	ldrsh r0, [r5, r2]
	subs r6, r1, r0
	movs r1, #0xed
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #0x30
	ldrsh r0, [r5, r2]
	subs r4, r1, r0
	adds r0, r5, #0
	bl FUN_08066fd4
	adds r7, r0, #0
	ldr r0, _080686E8 @ =0x00000951
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	adds r0, r6, #0
	muls r0, r6, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	adds r1, r7, #0
	muls r1, r7, r1
	cmp r0, r1
	bgt _08068714
	movs r7, #0
	strh r6, [r5, #0x34]
	strh r4, [r5, #0x38]
	movs r1, #0xee
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r4, r5, r2
	strb r0, [r4]
	adds r0, r5, #0
	bl FUN_080609dc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldrb r0, [r4]
	cmp r0, #4
	bls _080686F4
	ldr r2, _080686EC @ =0x000002E6
	adds r0, r5, r2
	strb r7, [r0]
	ldr r0, _080686F0 @ =0x000002E7
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _08068700
	.align 2, 0
_080686E8: .4byte 0x00000951
_080686EC: .4byte 0x000002E6
_080686F0: .4byte 0x000002E7
_080686F4:
	ldr r1, _0806870C @ =0x000002E6
	adds r0, r5, r1
	strb r7, [r0]
	ldr r2, _08068710 @ =0x000002E7
	adds r0, r5, r2
	strb r7, [r0]
_08068700:
	adds r0, r5, #0
	movs r1, #8
	movs r2, #1
	bl FUN_08060b84
	b _0806893C
	.align 2, 0
_0806870C: .4byte 0x000002E6
_08068710: .4byte 0x000002E7
_08068714:
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_0823785c
	adds r3, r0, #0
	ldr r2, _08068738 @ =0x085B0A08
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0806873C
	asrs r0, r0, #0xc
	b _08068742
	.align 2, 0
_08068738: .4byte 0x085B0A08
_0806873C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08068742:
	strh r0, [r5, #0x34]
	ldr r0, _0806875C @ =0x085B0A08
	movs r1, #0xff
	ands r1, r3
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _08068760
	asrs r0, r0, #0xc
	b _08068766
	.align 2, 0
_0806875C: .4byte 0x085B0A08
_08068760:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08068766:
	strh r0, [r5, #0x38]
	lsls r0, r3, #0x10
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
	adds r0, r5, r2
	strb r1, [r0]
	adds r0, r5, #0
	bl FUN_080609dc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #1
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	b _0806893C
_080687A2:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r4, r5, r2
	ldrb r0, [r4]
	movs r1, #0xc
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	bne _080687C0
	b _0806893C
_080687C0:
	movs r0, #0xcb
	bl PlaySound_082406e0
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080687DA
	b _08068904
_080687DA:
	ldrb r0, [r4]
	cmp r0, #5
	beq _080688B2
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r5, r2
	adds r2, #2
	adds r1, r5, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	blo _080687F8
	movs r0, #0x97
	lsls r0, r0, #1
	b _080688B6
_080687F8:
	ldr r0, _08068824 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	ble _080688B2
	movs r0, #0xd8
	bl PlaySound_082406e0
	ldr r2, _08068828 @ =0x00000409
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #8
	movs r2, #2
	bl FUN_08060b84
	b _0806893C
	.align 2, 0
_08068824: .4byte 0x030046A0
_08068828: .4byte 0x00000409
_0806882C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0xd
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r0, [r0]
	movs r4, #1
	ands r4, r0
	cmp r4, #0
	bne _08068868
	movs r0, #0xd8
	bl sound_08240740
	ldr r1, _08068864 @ =0x00000409
	adds r0, r5, r1
	strb r4, [r0]
	b _08068904
	.align 2, 0
_08068864: .4byte 0x00000409
_08068868:
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r5, r2
	adds r2, #2
	adds r1, r5, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	blo _08068894
	movs r0, #0xd8
	bl sound_08240740
	ldr r1, _08068890 @ =0x00000409
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	movs r0, #0x97
	lsls r0, r0, #1
	b _080688B6
	.align 2, 0
_08068890: .4byte 0x00000409
_08068894:
	ldr r0, _080688C8 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0xef
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r0, #0
	bgt _080688D0
	movs r0, #0xd8
	bl sound_08240740
	ldr r1, _080688CC @ =0x00000409
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
_080688B2:
	movs r0, #0x92
	lsls r0, r0, #1
_080688B6:
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #8
	movs r2, #3
	bl FUN_08060b84
	b _0806893C
	.align 2, 0
_080688C8: .4byte 0x030046A0
_080688CC: .4byte 0x00000409
_080688D0:
	movs r1, #0x40
	ldr r0, [r5, #0x20]
	orrs r0, r1
	str r0, [r5, #0x20]
	b _0806893C
_080688DA:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0xe
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0806893C
_08068904:
	adds r0, r5, #0
	movs r1, #8
	movs r2, #4
	bl FUN_08060b84
	b _0806893C
_08068910:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0xf
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806893C
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	adds r0, r5, #0
	bl FUN_080609dc
_0806893C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08068944
FUN_08068944: @ 0x08068944
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #9
	beq _0806899A
	ldr r2, _0806897C @ =0x00000951
	adds r0, r4, r2
	movs r1, #0
	strb r1, [r0]
	adds r0, r4, #0
	movs r1, #0x64
	bl FUN_08064d54
	cmp r0, #0
	beq _08068988
	ldr r0, _08068980 @ =0x03002BD0
	ldrh r0, [r0]
	cmp r0, #0
	bne _08068988
	ldr r3, _08068984 @ =0x000003FA
	adds r1, r4, r3
	movs r0, #1
	b _0806898E
	.align 2, 0
_0806897C: .4byte 0x00000951
_08068980: .4byte 0x03002BD0
_08068984: .4byte 0x000003FA
_08068988:
	ldr r0, _080689B0 @ =0x000003FA
	adds r1, r4, r0
	movs r0, #0
_0806898E:
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #9
	movs r2, #0
	bl FUN_08060b84
_0806899A:
	ldr r1, _080689B4 @ =0x0000037D
	adds r0, r4, r1
	ldrb r2, [r0]
	cmp r2, #1
	bne _080689A6
	b _08068B08
_080689A6:
	cmp r2, #1
	bgt _080689B8
	cmp r2, #0
	beq _080689C6
	b _08068C62
	.align 2, 0
_080689B0: .4byte 0x000003FA
_080689B4: .4byte 0x0000037D
_080689B8:
	cmp r2, #2
	bne _080689BE
	b _08068B9C
_080689BE:
	cmp r2, #3
	bne _080689C4
	b _08068C2C
_080689C4:
	b _08068C62
_080689C6:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r3, r4, r0
	ldrb r0, [r3]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _08068A28
	movs r1, #4
	strb r1, [r3]
	ldr r3, _08068A18 @ =0x000002E6
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _08068A1C @ =0x000002E7
	adds r0, r4, r1
	strb r2, [r0]
	movs r3, #0x93
	lsls r3, r3, #4
	adds r2, r4, r3
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	subs r0, #0x14
	strh r0, [r2]
	ldr r0, _08068A20 @ =0x00000932
	adds r1, r4, r0
	movs r2, #0xa5
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldr r0, _08068A24 @ =0x00000934
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0x3c
	b _08068A62
	.align 2, 0
_08068A18: .4byte 0x000002E6
_08068A1C: .4byte 0x000002E7
_08068A20: .4byte 0x00000932
_08068A24: .4byte 0x00000934
_08068A28:
	strb r2, [r3]
	ldr r1, _08068A90 @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	ldr r3, _08068A94 @ =0x000002E7
	adds r0, r4, r3
	strb r2, [r0]
	movs r0, #0x93
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	adds r0, #0x14
	strh r0, [r2]
	ldr r2, _08068A98 @ =0x00000932
	adds r1, r4, r2
	movs r3, #0xa5
	lsls r3, r3, #1
	adds r0, r3, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r3, _08068A9C @ =0x00000934
	adds r1, r4, r3
	ldrh r0, [r1]
	subs r0, #0x14
_08068A62:
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #4
	bne _08068AA0
	ldr r3, _08068A90 @ =0x000002E6
	adds r1, r4, r3
	movs r0, #1
	b _08068AA6
	.align 2, 0
_08068A90: .4byte 0x000002E6
_08068A94: .4byte 0x000002E7
_08068A98: .4byte 0x00000932
_08068A9C: .4byte 0x00000934
_08068AA0:
	ldr r0, _08068AF4 @ =0x000002E6
	adds r1, r4, r0
	movs r0, #0
_08068AA6:
	strb r0, [r1]
	ldr r1, _08068AF8 @ =0x000003FA
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08068AE6
	movs r0, #0x94
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r2, _08068AFC @ =0x0000095E
	adds r1, r4, r2
	ldr r0, _08068B00 @ =0x00000121
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r4, r3
	movs r0, #2
	strh r0, [r1]
	adds r1, r4, #0
	adds r1, #0x2c
	movs r0, #0x93
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r3, _08068B04 @ =0x000003BA
	adds r0, r4, r3
	ldrh r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_080abd14
_08068AE6:
	adds r0, r4, #0
	movs r1, #9
	movs r2, #1
	bl FUN_08060b84
	b _08068C62
	.align 2, 0
_08068AF4: .4byte 0x000002E6
_08068AF8: .4byte 0x000003FA
_08068AFC: .4byte 0x0000095E
_08068B00: .4byte 0x00000121
_08068B04: .4byte 0x000003BA
_08068B08:
	ldr r1, _08068B88 @ =0x000003FA
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08068B32
	ldr r2, _08068B8C @ =0x0000095E
	adds r1, r4, r2
	ldr r0, _08068B90 @ =0x00000121
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _08068B32
	movs r0, #0x20
	strh r0, [r1]
_08068B32:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #8
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	bne _08068B5A
	b _08068C62
_08068B5A:
	movs r0, #0xcb
	bl PlaySound_082406e0
	ldr r2, _08068B88 @ =0x000003FA
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08068B7A
	ldr r3, _08068B94 @ =0x000003BA
	adds r0, r4, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _08068B7A
	ldr r1, _08068B98 @ =0x03002BD0
	movs r0, #1
	strh r0, [r1]
_08068B7A:
	adds r0, r4, #0
	movs r1, #9
	movs r2, #2
	bl FUN_08060b84
	b _08068C62
	.align 2, 0
_08068B88: .4byte 0x000003FA
_08068B8C: .4byte 0x0000095E
_08068B90: .4byte 0x00000121
_08068B94: .4byte 0x000003BA
_08068B98: .4byte 0x03002BD0
_08068B9C:
	ldr r1, _08068BC8 @ =0x000003FA
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08068BD4
	ldr r2, _08068BCC @ =0x0000095E
	adds r1, r4, r2
	ldr r0, _08068BD0 @ =0x00000121
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _08068BE6
	movs r0, #0x20
	strh r0, [r1]
	b _08068BE6
	.align 2, 0
_08068BC8: .4byte 0x000003FA
_08068BCC: .4byte 0x0000095E
_08068BD0: .4byte 0x00000121
_08068BD4:
	ldr r1, _08068C28 @ =0x0000037E
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08068BE6
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08068BE6:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0x1e
	strh r0, [r1]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	movs r1, #0xa
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _08068C28 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x17
	bls _08068C62
	adds r0, r4, #0
	movs r1, #9
	movs r2, #3
	bl FUN_08060b84
	b _08068C62
	.align 2, 0
_08068C28: .4byte 0x0000037E
_08068C2C:
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
	beq _08068C62
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_08068C62:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08068c6c
FUN_08068c6c: @ 0x08068C6C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08068CC4 @ =0x00000446
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _08068C88
	ldr r2, _08068CC8 @ =0x00000442
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #2
	bne _08068C88
	movs r1, #1
_08068C88:
	cmp r1, #0
	bne _08068CC0
	ldr r3, _08068CCC @ =0x00000362
	adds r0, r4, r3
	ldrh r1, [r0]
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	subs r0, #0x64
	subs r3, #2
	adds r2, r4, r3
	subs r1, r1, r0
	ldrh r2, [r2]
	adds r1, r1, r2
	ldr r0, _08068CD0 @ =0x03002C00
	ldr r0, [r0]
	ldrh r0, [r0, #0x1e]
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x64
	bl Div
	adds r1, r0, #0
	cmp r1, #0x10
	ble _08068CD4
_08068CC0:
	movs r1, #0x10
	b _08068CDA
	.align 2, 0
_08068CC4: .4byte 0x00000446
_08068CC8: .4byte 0x00000442
_08068CCC: .4byte 0x00000362
_08068CD0: .4byte 0x03002C00
_08068CD4:
	cmp r1, #5
	bgt _08068CDA
	movs r1, #6
_08068CDA:
	ldr r2, _08068D0C @ =0x000004C5
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #2
	bne _08068CF0
	ldr r3, _08068D10 @ =0x000004C7
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08068CF0
	subs r1, #3
_08068CF0:
	ldr r0, _08068D14 @ =0x00000402
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _08068CFC
	subs r1, r1, r0
_08068CFC:
	cmp r1, #1
	bgt _08068D02
	movs r1, #2
_08068D02:
	adds r0, r1, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08068D0C: .4byte 0x000004C5
_08068D10: .4byte 0x000004C7
_08068D14: .4byte 0x00000402

	thumb_func_start FUN_08068d18
FUN_08068d18: @ 0x08068D18
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

	thumb_func_start FUN_08068e94
FUN_08068e94: @ 0x08068E94
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	adds r4, r3, #0
	movs r0, #0x46
	muls r0, r1, r0
	cmp r0, #0
	blt _08068EAC
	asrs r0, r0, #0xc
	b _08068EB2
_08068EAC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08068EB2:
	adds r7, r0, #0
	movs r0, #0x46
	muls r0, r2, r0
	cmp r0, #0
	blt _08068EC0
	asrs r0, r0, #0xc
	b _08068EC6
_08068EC0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08068EC6:
	mov r8, r0
	bl FUN_080865c0
	adds r5, r0, #0
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r2, #0x2c
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	subs r3, r0, r7
	movs r1, #4
	ldrsh r0, [r5, r1]
	movs r2, #0x30
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	mov r1, r8
	subs r2, r0, r1
	adds r0, r3, #0
	muls r0, r3, r0
	adds r1, r2, #0
	muls r1, r2, r1
	adds r0, r0, r1
	adds r1, r4, #0
	muls r1, r4, r1
	cmp r0, r1
	bgt _08068EFC
	b _0806920A
_08068EFC:
	adds r0, r3, #0
	adds r1, r2, #0
	bl FUN_0823785c
	adds r3, r0, #0
	ldr r2, _08068F20 @ =0x085B0A08
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _08068F24
	asrs r0, r0, #0xc
	b _08068F2A
	.align 2, 0
_08068F20: .4byte 0x085B0A08
_08068F24:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08068F2A:
	ldrh r1, [r6, #0x2c]
	adds r1, r1, r0
	adds r1, r1, r7
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08068F58 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldr r1, _08068F5C @ =0x085B0A08
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r4, r0
	cmp r0, #0
	blt _08068F60
	asrs r1, r0, #0xc
	b _08068F66
	.align 2, 0
_08068F58: .4byte 0xFFFF0000
_08068F5C: .4byte 0x085B0A08
_08068F60:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08068F66:
	ldrh r0, [r6, #0x30]
	adds r0, r0, r1
	add r0, r8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _08068FE8 @ =0xFFFF0000
	mov r4, sp
	ldr r3, [sp, #4]
	ands r3, r2
	orrs r3, r0
	str r3, [sp, #4]
	movs r1, #0
	ldrsh r0, [r5, r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	mov r0, sp
	movs r7, #0
	ldrsh r0, [r0, r7]
	adds r1, r1, r0
	lsls r1, r1, #0xe
	lsrs r1, r1, #0x10
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	movs r0, #4
	ldrsh r1, [r5, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	movs r5, #4
	ldrsh r1, [r4, r5]
	adds r0, r0, r1
	lsls r0, r0, #0xe
	lsrs r0, r0, #0x10
	ands r2, r3
	orrs r2, r0
	str r2, [sp, #4]
	adds r0, r6, #0
	mov r1, sp
	bl FUN_08068d18
	cmp r0, #0
	beq _08068FBE
	b _08069140
_08068FBE:
	ldrh r1, [r6, #0x2c]
	lsls r0, r1, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r6, #0x30]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	adds r4, r1, #0
	cmp r3, #0
	blt _08068FE4
	cmp r2, #0
	blt _08068FE4
	ldr r0, _08068FEC @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _08068FE4
	ldr r0, _08068FF0 @ =0x030046AC
	ldr r0, [r0]
	cmp r2, r0
	blo _08068FF4
_08068FE4:
	movs r3, #0
	b _08069002
	.align 2, 0
_08068FE8: .4byte 0xFFFF0000
_08068FEC: .4byte 0x030046A8
_08068FF0: .4byte 0x030046AC
_08068FF4:
	ldr r0, _08069030 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r2, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r3, r0, r3
_08069002:
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0806902A
	cmp r1, #0
	blt _0806902A
	ldr r0, _08069034 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0806902A
	ldr r0, _08069038 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0806903C
_0806902A:
	movs r2, #0
	b _0806904A
	.align 2, 0
_08069030: .4byte 0x030046A4
_08069034: .4byte 0x030046A8
_08069038: .4byte 0x030046AC
_0806903C:
	ldr r0, _0806905C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r2, r0, r2
_0806904A:
	adds r0, r2, #1
	cmp r3, r0
	bne _08069060
	lsls r0, r4, #0x10
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	adds r0, #2
	b _08069070
	.align 2, 0
_0806905C: .4byte 0x030046A4
_08069060:
	subs r0, r2, #1
	cmp r3, r0
	bne _08069076
	lsls r0, r4, #0x10
	asrs r0, r0, #0x18
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #2
_08069070:
	mov r1, sp
	strh r0, [r1]
	b _080690B8
_08069076:
	ldr r0, _08069094 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r7, #4
	ldrsh r1, [r0, r7]
	adds r0, r2, r1
	cmp r3, r0
	bne _08069098
	ldrh r0, [r6, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	adds r0, #2
	b _080690AA
	.align 2, 0
_08069094: .4byte 0x030046A4
_08069098:
	subs r0, r2, r1
	cmp r3, r0
	bne _080690B0
	ldrh r0, [r6, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #2
_080690AA:
	mov r1, sp
	strh r0, [r1, #4]
	b _080690B8
_080690B0:
	mov r0, sp
	strh r4, [r0]
	ldrh r1, [r6, #0x30]
	strh r1, [r0, #4]
_080690B8:
	bl FUN_08086958
	cmp r0, #0
	beq _080690C2
	b _080691D0
_080690C2:
	mov r5, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080690EA
	cmp r1, #0
	blt _080690EA
	ldr r0, _080690F0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080690EA
	ldr r0, _080690F4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080690F8
_080690EA:
	movs r4, #0
	b _08069106
	.align 2, 0
_080690F0: .4byte 0x030046A8
_080690F4: .4byte 0x030046AC
_080690F8:
	ldr r0, _08069118 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08069106:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0806911C
	adds r0, #4
	b _08069128
	.align 2, 0
_08069118: .4byte 0x030046A4
_0806911C:
	ldr r0, _0806913C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08069128:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	bne _080691BA
	ldrb r0, [r5, #4]
	b _080691CA
	.align 2, 0
_0806913C: .4byte 0x030046A4
_08069140:
	bl FUN_08086958
	cmp r0, #0
	bne _080691D0
	mov r5, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08069170
	cmp r1, #0
	blt _08069170
	ldr r0, _08069174 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08069170
	ldr r0, _08069178 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0806917C
_08069170:
	movs r4, #0
	b _0806918A
	.align 2, 0
_08069174: .4byte 0x030046A8
_08069178: .4byte 0x030046AC
_0806917C:
	ldr r0, _0806919C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0806918A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080691A0
	adds r0, #4
	b _080691AC
	.align 2, 0
_0806919C: .4byte 0x030046A4
_080691A0:
	ldr r0, _080691C0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080691AC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080691C4
_080691BA:
	cmp r2, #2
	beq _080691C8
	b _080691CC
	.align 2, 0
_080691C0: .4byte 0x030046A4
_080691C4:
	ldrb r0, [r5, #4]
	b _080691CA
_080691C8:
	ldrb r0, [r5]
_080691CA:
	subs r1, r1, r0
_080691CC:
	mov r0, sp
	strh r1, [r0, #2]
_080691D0:
	movs r0, #0x2c
	ldrsh r1, [r6, r0]
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r3, r1, r0
	movs r5, #0x30
	ldrsh r1, [r6, r5]
	mov r0, sp
	movs r7, #4
	ldrsh r0, [r0, r7]
	subs r2, r1, r0
	adds r0, r3, #0
	adds r1, r2, #0
	bl FUN_0823785c
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r1, #0x10
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #5
	adds r1, #3
	movs r0, #7
	ands r1, r0
	mov r0, sp
	bl FUN_08086590
_0806920A:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08069218
FUN_08069218: @ 0x08069218
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #6
	beq _0806923C
	adds r0, r5, #0
	movs r1, #6
	movs r2, #0
	bl FUN_08060b84
_0806923C:
	ldr r0, [r5, #0x20]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x20]
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	blt _08069260
	ldr r6, _08069284 @ =0x000003CE
	adds r0, r5, r6
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #0
	beq _080692CC
_08069260:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x10
	bl FUN_08066ee4
	str r0, [sp, #0x14]
	movs r2, #0xe9
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806928C
	ldr r4, _08069288 @ =0x000003A7
	adds r0, r5, r4
	b _08069292
	.align 2, 0
_08069284: .4byte 0x000003CE
_08069288: .4byte 0x000003A7
_0806928C:
	movs r6, #0xba
	lsls r6, r6, #2
	adds r0, r5, r6
_08069292:
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080692C8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r7, [r0, r4]
	mov sl, r7
	ands r3, r1
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r6, [r0, r7]
	mov sb, r6
	movs r0, #0
	str r0, [sp, #0x10]
	movs r1, #0x40
	str r1, [sp, #0xc]
	b _08069448
	.align 2, 0
_080692C8: .4byte 0x085B0A08
_080692CC:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x11
	bl FUN_08066ee4
	str r0, [sp, #0x14]
	adds r0, r5, #0
	bl FUN_08068c6c
	adds r4, r0, #0
	movs r6, #1
	str r6, [sp, #0x10]
	adds r0, r5, #0
	bl FUN_08067068
	movs r7, #0xba
	lsls r7, r7, #2
	adds r1, r5, r7
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_080609dc
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08069344
	movs r2, #0x20
	str r2, [sp, #0xc]
	ldr r4, _0806933C @ =0x000003A7
	adds r0, r5, r4
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08069340 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r6, [r0, r7]
	mov sl, r6
	ands r3, r1
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	mov sb, r1
	b _08069448
	.align 2, 0
_0806933C: .4byte 0x000003A7
_08069340: .4byte 0x085B0A08
_08069344:
	cmp r4, #8
	bne _0806934E
	movs r6, #0x40
	str r6, [sp, #0xc]
	b _0806936A
_0806934E:
	cmp r4, #7
	bgt _0806935E
	movs r0, #8
	subs r0, r0, r4
	lsls r0, r0, #3
	adds r0, #0x40
	str r0, [sp, #0xc]
	b _0806936A
_0806935E:
	adds r0, r4, #0
	subs r0, #8
	lsls r0, r0, #2
	movs r1, #0x40
	subs r1, r1, r0
	str r1, [sp, #0xc]
_0806936A:
	movs r7, #0xba
	lsls r7, r7, #2
	adds r0, r5, r7
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080693B4 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r6, [r0, r7]
	mov sl, r6
	ands r3, r1
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	mov sb, r1
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r1, [r0]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _08069448
	mov r0, sl
	muls r0, r4, r0
	cmp r0, #0
	blt _080693B8
	asrs r0, r0, #0xc
	b _080693BE
	.align 2, 0
_080693B4: .4byte 0x085B0A08
_080693B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080693BE:
	rsbs r0, r0, #0
	strh r0, [r5, #0x34]
	mov r0, sb
	muls r0, r4, r0
	cmp r0, #0
	blt _080693CE
	asrs r0, r0, #0xc
	b _080693D4
_080693CE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080693D4:
	rsbs r0, r0, #0
	strh r0, [r5, #0x38]
	ldr r4, _080693F8 @ =0x000001C7
	adds r1, r5, r4
	ldrb r1, [r1]
	cmp r1, #1
	bne _08069416
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _080693FC
	movs r6, #0x38
	ldrsh r1, [r5, r6]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _08069408
	b _0806940C
	.align 2, 0
_080693F8: .4byte 0x000001C7
_080693FC:
	movs r7, #0x38
	ldrsh r1, [r5, r7]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _0806940C
_08069408:
	asrs r0, r0, #6
	b _08069412
_0806940C:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08069412:
	strh r0, [r5, #0x38]
	b _08069448
_08069416:
	cmp r1, #2
	bne _08069448
	movs r1, #0x34
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bge _08069430
	adds r1, r0, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _0806943C
	b _08069440
_08069430:
	movs r4, #0x34
	ldrsh r1, [r5, r4]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _08069440
_0806943C:
	asrs r0, r0, #6
	b _08069446
_08069440:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08069446:
	strh r0, [r5, #0x34]
_08069448:
	ldr r6, [sp, #0x10]
	cmp r6, #0
	bne _08069450
	b _080695B2
_08069450:
	ldr r7, _080694B8 @ =0x00000292
	adds r0, r5, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _0806945E
	b _080695B2
_0806945E:
	adds r2, r5, #0
	adds r2, #0x9c
	ldrh r1, [r2]
	movs r0, #3
	ands r0, r1
	adds r7, r2, #0
	cmp r0, #0
	beq _08069470
	b _080695B2
_08069470:
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	beq _0806947C
	b _080695B2
_0806947C:
	ldr r2, _080694BC @ =0x00000446
	adds r0, r5, r2
	ldrh r1, [r0]
	movs r6, #0
	mov r8, r0
	cmp r1, #0
	beq _08069496
	ldr r4, _080694C0 @ =0x00000442
	adds r0, r5, r4
	ldrh r0, [r0]
	cmp r0, #0
	bne _08069496
	movs r6, #1
_08069496:
	cmp r6, #0
	beq _0806949C
	b _080695B2
_0806949C:
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	bl FUN_0809f658
	cmp r0, #0
	beq _080694D2
	ldrh r0, [r7]
	cmp r0, #0
	bne _080694C8
	str r4, [sp]
	str r6, [sp, #4]
	ldr r0, _080694C4 @ =0x00000163
	b _08069516
	.align 2, 0
_080694B8: .4byte 0x00000292
_080694BC: .4byte 0x00000446
_080694C0: .4byte 0x00000442
_080694C4: .4byte 0x00000163
_080694C8:
	str r4, [sp]
	str r6, [sp, #4]
	movs r0, #0xb1
	lsls r0, r0, #1
	b _08069516
_080694D2:
	movs r6, #0xe5
	lsls r6, r6, #1
	adds r0, r5, r6
	ldrh r0, [r0]
	bl FUN_08065a98
	cmp r0, #0
	beq _0806952C
	mov r1, r8
	ldrh r0, [r1]
	movs r1, #0
	cmp r0, #0
	beq _080694F8
	ldr r2, _0806950C @ =0x00000442
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #5
	bne _080694F8
	movs r1, #1
_080694F8:
	cmp r1, #0
	bne _0806952C
	ldrh r0, [r7]
	cmp r0, #0
	bne _08069510
	str r4, [sp]
	str r1, [sp, #4]
	movs r0, #0xca
	lsls r0, r0, #1
	b _08069516
	.align 2, 0
_0806950C: .4byte 0x00000442
_08069510:
	str r4, [sp]
	str r1, [sp, #4]
	ldr r0, _08069528 @ =0x00000193
_08069516:
	str r0, [sp, #8]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #1
	movs r3, #1
	bl FUN_08066e9c
	b _080695B2
	.align 2, 0
_08069528: .4byte 0x00000193
_0806952C:
	movs r6, #0xe4
	lsls r6, r6, #2
	adds r0, r5, r6
	ldrh r0, [r0]
	cmp r0, #0
	bne _08069542
	ldr r1, _08069550 @ =0x000001C7
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0806955C
_08069542:
	ldrh r0, [r7]
	cmp r0, #0
	bne _08069554
	movs r0, #0xca
	bl PlaySound_082406e0
	b _08069576
	.align 2, 0
_08069550: .4byte 0x000001C7
_08069554:
	movs r0, #0xc9
	bl PlaySound_082406e0
	b _08069576
_0806955C:
	ldrh r0, [r7]
	cmp r0, #0
	bne _08069570
	ldr r0, _0806956C @ =0x0000028E
	bl PlaySound_082406e0
	b _08069576
	.align 2, 0
_0806956C: .4byte 0x0000028E
_08069570:
	ldr r0, _0806958C @ =0x0000028D
	bl PlaySound_082406e0
_08069576:
	movs r1, #1
	ldr r0, _08069590 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _08069594 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08069598
	movs r0, #1
	b _0806959A
	.align 2, 0
_0806958C: .4byte 0x0000028D
_08069590: .4byte 0x030046A0
_08069594: .4byte 0x00000934
_08069598:
	movs r0, #0
_0806959A:
	cmp r0, #0
	beq _080695B2
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #1
	movs r3, #2
	bl FUN_08066e9c
_080695B2:
	adds r0, r5, #0
	ldr r1, [sp, #0x14]
	ldr r2, [sp, #0xc]
	bl FUN_08060a24
	ldr r4, [sp, #0x10]
	cmp r4, #0
	bne _080695CE
	movs r6, #0xe9
	lsls r6, r6, #2
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _080695DA
_080695CE:
	adds r0, r5, #0
	mov r1, sl
	mov r2, sb
	movs r3, #0x96
	bl FUN_08068e94
_080695DA:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080695ec
FUN_080695ec: @ 0x080695EC
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	beq _08069606
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0
	bl FUN_08060b84
_08069606:
	ldr r1, _08069618 @ =0x00000A98
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08069618: .4byte 0x00000A98

	thumb_func_start FUN_0806961c
FUN_0806961c: @ 0x0806961C
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x20]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #0x20]
	ldr r1, _08069644 @ =0x000004C7
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0806963E
	adds r0, r2, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806963E:
	pop {r0}
	bx r0
	.align 2, 0
_08069644: .4byte 0x000004C7

	thumb_func_start FUN_08069648
FUN_08069648: @ 0x08069648
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	movs r0, #0xa4
	lsls r0, r0, #2
	adds r2, r4, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	blt _080696CE
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r1, [r0]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r1, r0
	beq _080696CE
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080696B8
	lsrs r2, r1, #1
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _080696A2
	adds r1, r4, #0
	adds r1, #0x2c
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x8b
	lsls r0, r0, #1
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #1
	bl FUN_08066e9c
	b _080696B8
_080696A2:
	adds r1, r4, #0
	adds r1, #0x2c
	str r2, [sp]
	str r2, [sp, #4]
	ldr r0, _08069708 @ =0x00000117
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #1
	bl FUN_08066e9c
_080696B8:
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r1, [r0]
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r4, r3
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_080609dc
_080696CE:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _0806970C @ =0x000003FF
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _080696FE
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_080696FE:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08069708: .4byte 0x00000117
_0806970C: .4byte 0x000003FF

	thumb_func_start FUN_08069710
FUN_08069710: @ 0x08069710
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0xf
	beq _08069812
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08064d6c
	adds r1, r0, #0
	cmp r1, #0
	beq _080697FC
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08069768 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x96
	muls r0, r1, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _0806976C
	asrs r2, r0, #0xc
	b _08069772
	.align 2, 0
_08069768: .4byte 0x085B0A08
_0806976C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08069772:
	add r0, sp, #4
	ldrh r1, [r0]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0806979C @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	lsls r0, r3, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x96
	muls r0, r1, r0
	cmp r0, #0
	blt _080697A0
	asrs r2, r0, #0xc
	b _080697A6
	.align 2, 0
_0806979C: .4byte 0xFFFF0000
_080697A0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080697A6:
	add r0, sp, #4
	ldrh r1, [r0, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080697EC @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	ldr r0, _080697F0 @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _080697F4 @ =0x00000942
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r2, r0, #4
	subs r2, r2, r0
	lsls r2, r2, #2
	adds r2, #0x78
	adds r0, r5, #0
	adds r0, #0x28
	movs r4, #1
	adds r1, r4, #0
	ldrb r0, [r0]
	lsls r1, r0
	movs r0, #0x5a
	str r0, [sp]
	add r0, sp, #4
	bl FUN_080a8164
	ldr r2, _080697F8 @ =0x000003FA
	adds r0, r5, r2
	strb r4, [r0]
	b _08069802
	.align 2, 0
_080697EC: .4byte 0xFFFF0000
_080697F0: .4byte 0x030046A0
_080697F4: .4byte 0x00000942
_080697F8: .4byte 0x000003FA
_080697FC:
	ldr r4, _08069828 @ =0x000003FA
	adds r0, r5, r4
	strb r1, [r0]
_08069802:
	ldr r0, _0806982C @ =0x00000306
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #0xf
	movs r2, #0
	bl FUN_08060b84
_08069812:
	ldr r1, _08069830 @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _08069890
	cmp r0, #1
	bgt _08069834
	cmp r0, #0
	beq _0806983E
	b _08069920
	.align 2, 0
_08069828: .4byte 0x000003FA
_0806982C: .4byte 0x00000306
_08069830: .4byte 0x0000037D
_08069834:
	cmp r0, #2
	beq _080698CC
	cmp r0, #3
	beq _08069908
	b _08069920
_0806983E:
	ldr r2, _0806987C @ =0x000003FA
	adds r4, r5, r2
	ldrb r0, [r4]
	cmp r0, #0
	beq _0806985C
	ldr r0, _08069880 @ =0x0000095E
	adds r1, r5, r0
	movs r0, #0x92
	lsls r0, r0, #1
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r0, #0x20
	strh r0, [r1]
_0806985C:
	adds r0, r5, #0
	movs r1, #0xa4
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08069920
	ldrb r0, [r4]
	cmp r0, #0
	beq _08069884
	adds r0, r5, #0
	movs r1, #0xf
	movs r2, #1
	bl FUN_08060b84
	b _08069920
	.align 2, 0
_0806987C: .4byte 0x000003FA
_08069880: .4byte 0x0000095E
_08069884:
	adds r0, r5, #0
	movs r1, #0xf
	movs r2, #2
	bl FUN_08060b84
	b _08069920
_08069890:
	ldr r4, _080698C4 @ =0x0000095E
	adds r1, r5, r4
	movs r0, #0x92
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r5, r0
	movs r0, #0x20
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #0xae
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _080698C8 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _08069920
	b _080698F6
	.align 2, 0
_080698C4: .4byte 0x0000095E
_080698C8: .4byte 0x0000037E
_080698CC:
	ldr r0, _08069904 @ =0x0000037E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _080698DE
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080698DE:
	adds r0, r5, #0
	movs r1, #0xa9
	movs r2, #0x40
	bl FUN_08060a24
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _08069920
_080698F6:
	adds r0, r5, #0
	movs r1, #0xf
	movs r2, #3
	bl FUN_08060b84
	b _08069920
	.align 2, 0
_08069904: .4byte 0x0000037E
_08069908:
	adds r0, r5, #0
	movs r1, #0xa4
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08069920
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_08069920:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08069928
FUN_08069928: @ 0x08069928
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x10
	beq _08069A02
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08064d6c
	adds r1, r0, #0
	cmp r1, #0
	beq _080699EC
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08069980 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r0, #0x96
	muls r0, r1, r0
	adds r5, r2, #0
	cmp r0, #0
	blt _08069984
	asrs r2, r0, #0xc
	b _0806998A
	.align 2, 0
_08069980: .4byte 0x085B0A08
_08069984:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0806998A:
	mov r0, sp
	ldrh r1, [r0]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080699B4 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	lsls r0, r3, #1
	adds r0, r0, r5
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x96
	muls r0, r1, r0
	cmp r0, #0
	blt _080699B8
	asrs r2, r0, #0xc
	b _080699BE
	.align 2, 0
_080699B4: .4byte 0xFFFF0000
_080699B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080699BE:
	mov r0, sp
	ldrh r1, [r0, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080699E4 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	adds r0, r4, #0
	mov r1, sp
	bl FUN_080a9478
	ldr r5, _080699E8 @ =0x000003FA
	adds r1, r4, r5
	movs r0, #1
	strb r0, [r1]
	b _080699F2
	.align 2, 0
_080699E4: .4byte 0xFFFF0000
_080699E8: .4byte 0x000003FA
_080699EC:
	ldr r2, _08069A18 @ =0x000003FA
	adds r0, r4, r2
	strb r1, [r0]
_080699F2:
	ldr r0, _08069A1C @ =0x00000306
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #0
	bl FUN_08060b84
_08069A02:
	ldr r5, _08069A20 @ =0x0000037D
	adds r0, r4, r5
	ldrb r0, [r0]
	cmp r0, #1
	beq _08069A80
	cmp r0, #1
	bgt _08069A24
	cmp r0, #0
	beq _08069A2E
	b _08069B10
	.align 2, 0
_08069A18: .4byte 0x000003FA
_08069A1C: .4byte 0x00000306
_08069A20: .4byte 0x0000037D
_08069A24:
	cmp r0, #2
	beq _08069ABC
	cmp r0, #3
	beq _08069AF8
	b _08069B10
_08069A2E:
	ldr r0, _08069A6C @ =0x000003FA
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _08069A4C
	ldr r2, _08069A70 @ =0x0000095E
	adds r1, r4, r2
	movs r0, #0x93
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
_08069A4C:
	adds r0, r4, #0
	movs r1, #0xa4
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08069B10
	ldrb r0, [r5]
	cmp r0, #0
	beq _08069A74
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #1
	bl FUN_08060b84
	b _08069B10
	.align 2, 0
_08069A6C: .4byte 0x000003FA
_08069A70: .4byte 0x0000095E
_08069A74:
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #2
	bl FUN_08060b84
	b _08069B10
_08069A80:
	ldr r2, _08069AB4 @ =0x0000095E
	adds r1, r4, r2
	movs r0, #0x93
	lsls r0, r0, #1
	strh r0, [r1]
	movs r5, #0x96
	lsls r5, r5, #4
	adds r1, r4, r5
	movs r0, #0x20
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #0xae
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _08069AB8 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _08069B10
	b _08069AE6
	.align 2, 0
_08069AB4: .4byte 0x0000095E
_08069AB8: .4byte 0x0000037E
_08069ABC:
	ldr r1, _08069AF4 @ =0x0000037E
	adds r5, r4, r1
	ldrh r0, [r5]
	cmp r0, #0
	bne _08069ACE
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08069ACE:
	adds r0, r4, #0
	movs r1, #0xa9
	movs r2, #0x40
	bl FUN_08060a24
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _08069B10
_08069AE6:
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #3
	bl FUN_08060b84
	b _08069B10
	.align 2, 0
_08069AF4: .4byte 0x0000037E
_08069AF8:
	adds r0, r4, #0
	movs r1, #0xa4
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08069B10
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_08069B10:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08069b18
FUN_08069b18: @ 0x08069B18
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x11
	beq _08069B7C
	movs r2, #0xe4
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _08069B44
	ldr r0, _08069B40 @ =0x000003FA
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	b _08069B72
	.align 2, 0
_08069B40: .4byte 0x000003FA
_08069B44:
	adds r0, r4, #0
	movs r1, #3
	bl FUN_08064d6c
	adds r1, r0, #0
	cmp r1, #0
	beq _08069B6C
	ldr r1, _08069B68 @ =0x000003FA
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x2c
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080a8ff8
	b _08069B72
	.align 2, 0
_08069B68: .4byte 0x000003FA
_08069B6C:
	ldr r2, _08069B90 @ =0x000003FA
	adds r0, r4, r2
	strb r1, [r0]
_08069B72:
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #0
	bl FUN_08060b84
_08069B7C:
	ldr r1, _08069B94 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _08069BF8
	cmp r0, #1
	bgt _08069B98
	cmp r0, #0
	beq _08069BA2
	b _08069C84
	.align 2, 0
_08069B90: .4byte 0x000003FA
_08069B94: .4byte 0x0000037D
_08069B98:
	cmp r0, #2
	beq _08069C30
	cmp r0, #3
	beq _08069C6C
	b _08069C84
_08069BA2:
	ldr r2, _08069BE0 @ =0x000003FA
	adds r5, r4, r2
	ldrb r0, [r5]
	cmp r0, #0
	beq _08069BBE
	ldr r0, _08069BE4 @ =0x0000095E
	adds r1, r4, r0
	ldr r0, _08069BE8 @ =0x00000123
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r4, r2
	movs r0, #0x20
	strh r0, [r1]
_08069BBE:
	adds r0, r4, #0
	movs r1, #0xb8
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08069C84
	ldrb r0, [r5]
	cmp r0, #0
	beq _08069BEC
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #1
	bl FUN_08060b84
	b _08069C84
	.align 2, 0
_08069BE0: .4byte 0x000003FA
_08069BE4: .4byte 0x0000095E
_08069BE8: .4byte 0x00000123
_08069BEC:
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #2
	bl FUN_08060b84
	b _08069C84
_08069BF8:
	ldr r1, _08069C20 @ =0x000003FA
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08069C14
	ldr r2, _08069C24 @ =0x0000095E
	adds r1, r4, r2
	ldr r0, _08069C28 @ =0x00000123
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
_08069C14:
	ldr r2, _08069C2C @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _08069C52
	.align 2, 0
_08069C20: .4byte 0x000003FA
_08069C24: .4byte 0x0000095E
_08069C28: .4byte 0x00000123
_08069C2C: .4byte 0x0000037E
_08069C30:
	ldr r0, _08069C68 @ =0x0000037E
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _08069C42
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08069C42:
	adds r0, r4, #0
	movs r1, #0xc2
	movs r2, #0x40
	bl FUN_08060a24
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_08069C52:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bls _08069C84
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #3
	bl FUN_08060b84
	b _08069C84
	.align 2, 0
_08069C68: .4byte 0x0000037E
_08069C6C:
	adds r0, r4, #0
	movs r1, #0xbd
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08069C84
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	bl FUN_08060b84
_08069C84:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08069c8c
FUN_08069c8c: @ 0x08069C8C
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x12
	beq _08069CAC
	adds r0, r4, #0
	bl FUN_08060c60
	adds r0, r4, #0
	movs r1, #0x12
	movs r2, #0
	bl FUN_08060b84
_08069CAC:
	ldr r1, _08069CC0 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _08069CF2
	cmp r0, #1
	bgt _08069CC4
	cmp r0, #0
	beq _08069CCA
	b _08069D68
	.align 2, 0
_08069CC0: .4byte 0x0000037D
_08069CC4:
	cmp r0, #2
	beq _08069D42
	b _08069D68
_08069CCA:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x30
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08069D68
	adds r0, r4, #0
	movs r1, #0x12
	movs r2, #1
	bl FUN_08060b84
	b _08069D68
_08069CF2:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x31
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #1
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #0xf3
	ands r0, r1
	cmp r0, #0
	beq _08069D20
	movs r2, #2
_08069D20:
	movs r0, #0xfb
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, r2
	ble _08069D32
	subs r0, r0, r2
	strh r0, [r1]
	b _08069D68
_08069D32:
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #0x12
	movs r2, #2
	bl FUN_08060b84
	b _08069D68
_08069D42:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x32
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08069D68
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_08069D68:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08069d70
FUN_08069d70: @ 0x08069D70
	push {r4, r5, lr}
	sub sp, #0x14
	adds r4, r0, #0
	movs r1, #4
	bl FUN_08060c40
	ldr r1, _08069D94 @ =0x0000037D
	adds r0, r4, r1
	ldrb r5, [r0]
	cmp r5, #1
	bne _08069D88
	b _08069E94
_08069D88:
	cmp r5, #1
	bgt _08069D98
	cmp r5, #0
	beq _08069DA6
	b _08069F54
	.align 2, 0
_08069D94: .4byte 0x0000037D
_08069D98:
	cmp r5, #2
	bne _08069D9E
	b _08069ED0
_08069D9E:
	cmp r5, #3
	bne _08069DA4
	b _08069F44
_08069DA4:
	b _08069F54
_08069DA6:
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r2, [sp, #0xc]
	asrs r1, r2, #0x10
	adds r1, #0x96
	lsls r1, r1, #0x10
	ldr r0, _08069DEC @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	bl FUN_0823bac8
	movs r2, #0xfc
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08069DF4
	movs r0, #4
	str r0, [sp]
	ldr r0, _08069DF0 @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #0x10
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #3
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	b _08069E0C
	.align 2, 0
_08069DEC: .4byte 0x0000FFFF
_08069DF0: .4byte 0x00001FFF
_08069DF4:
	movs r0, #4
	str r0, [sp]
	ldr r0, _08069E3C @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #3
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_08069E0C:
	ldr r0, _08069E40 @ =0x000001AD
	bl PlaySound_082406e0
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _08069E4C
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _08069E44 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _08069E48 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _08069E5C
	.align 2, 0
_08069E3C: .4byte 0x00001FFF
_08069E40: .4byte 0x000001AD
_08069E44: .4byte 0x000002E6
_08069E48: .4byte 0x000002E7
_08069E4C:
	lsrs r1, r1, #0x19
	ldr r2, _08069E88 @ =0x000002E6
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r1, _08069E8C @ =0x000002E7
	adds r0, r4, r1
	strb r2, [r0]
_08069E5C:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	adds r0, r4, #0
	movs r1, #0x16
	movs r2, #1
	bl FUN_08060b84
	ldr r0, _08069E90 @ =0x000003F6
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	b _08069F54
	.align 2, 0
_08069E88: .4byte 0x000002E6
_08069E8C: .4byte 0x000002E7
_08069E90: .4byte 0x000003F6
_08069E94:
	ldr r2, _08069EC8 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _08069F54
	adds r0, r4, #0
	movs r1, #0x16
	movs r2, #2
	bl FUN_08060b84
	ldr r0, _08069ECC @ =0x000003F6
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xef
	strb r5, [r0]
	movs r0, #0xd7
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _08069F54
	.align 2, 0
_08069EC8: .4byte 0x0000037E
_08069ECC: .4byte 0x000003F6
_08069ED0:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r5, r4, r1
	ldrb r0, [r5]
	movs r1, #0x12
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _08069F0C @ =0x000003F6
	adds r1, r4, r2
	ldrh r0, [r1]
	subs r0, #0x3c
	strh r0, [r1]
	ldr r1, _08069F10 @ =0x0000037E
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #4
	bne _08069F1E
	ldrb r0, [r5]
	cmp r0, #5
	bne _08069F18
	ldr r0, _08069F14 @ =0x000002ED
	bl PlaySound_082406e0
	b _08069F1E
	.align 2, 0
_08069F0C: .4byte 0x000003F6
_08069F10: .4byte 0x0000037E
_08069F14: .4byte 0x000002ED
_08069F18:
	ldr r0, _08069F3C @ =0x00000305
	bl PlaySound_082406e0
_08069F1E:
	ldr r2, _08069F40 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _08069F54
	adds r0, r4, #0
	movs r1, #0x16
	movs r2, #3
	bl FUN_08060b84
	b _08069F54
	.align 2, 0
_08069F3C: .4byte 0x00000305
_08069F40: .4byte 0x0000037E
_08069F44:
	ldr r0, _08069F5C @ =0x000003F6
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08060c40
_08069F54:
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08069F5C: .4byte 0x000003F6

	thumb_func_start FUN_08069f60
FUN_08069f60: @ 0x08069F60
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #8
	bl FUN_08060c40
	ldr r1, _08069F7C @ =0x0000037D
	adds r0, r4, r1
	ldrb r3, [r0]
	cmp r3, #0
	beq _08069F80
	cmp r3, #1
	beq _0806A01E
	b _0806A04A
	.align 2, 0
_08069F7C: .4byte 0x0000037D
_08069F80:
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0x2c
	beq _08069FD2
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r0, [r2]
	movs r1, #1
	orrs r1, r0
	strb r1, [r2]
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _08069FC4
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _08069FBC @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _08069FC0 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _08069FD2
	.align 2, 0
_08069FBC: .4byte 0x000002E6
_08069FC0: .4byte 0x000002E7
_08069FC4:
	lsrs r0, r1, #0x19
	ldr r2, _0806A010 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r1, _0806A014 @ =0x000002E7
	adds r0, r4, r1
	strb r3, [r0]
_08069FD2:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0x12
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r0, #0xfe
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0x1e
	bhi _0806A018
	movs r0, #0
	strh r0, [r1]
	movs r0, #0xd8
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #0x17
	movs r2, #1
	bl FUN_08060b84
	b _0806A04A
	.align 2, 0
_0806A010: .4byte 0x000002E6
_0806A014: .4byte 0x000002E7
_0806A018:
	subs r0, #0x1e
	strh r0, [r1]
	b _0806A04A
_0806A01E:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x13
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806A04A
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806A04A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0806a050
FUN_0806a050: @ 0x0806A050
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0806A068 @ =0x000003FE
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806A06C
	adds r0, r4, #0
	movs r1, #0x1c
	bl FUN_08060c40
	b _0806A074
	.align 2, 0
_0806A068: .4byte 0x000003FE
_0806A06C:
	adds r0, r4, #0
	movs r1, #0x1d
	bl FUN_08060c40
_0806A074:
	movs r1, #0x88
	lsls r1, r1, #5
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0806a084
FUN_0806a084: @ 0x0806A084
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x18
	beq _0806A110
	adds r0, r5, #0
	movs r1, #0x18
	movs r2, #0
	bl FUN_08060b84
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r5, r3
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0806A0D0
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r6, _0806A0C8 @ =0x000002E6
	adds r1, r5, r6
	strb r0, [r1]
	ldr r0, _0806A0CC @ =0x000002E7
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _0806A0E0
	.align 2, 0
_0806A0C8: .4byte 0x000002E6
_0806A0CC: .4byte 0x000002E7
_0806A0D0:
	lsrs r1, r1, #0x19
	ldr r2, _0806A14C @ =0x000002E6
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r3, _0806A150 @ =0x000002E7
	adds r0, r5, r3
	strb r2, [r0]
_0806A0E0:
	movs r6, #0xd6
	lsls r6, r6, #2
	adds r0, r5, r6
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r1, _0806A154 @ =0x000003F6
	adds r0, r5, r1
	movs r6, #0
	strh r6, [r0]
	ldr r2, _0806A158 @ =0x000003D6
	adds r4, r5, r2
	ldrh r0, [r4]
	cmp r0, #0
	beq _0806A110
	bl PlaySound_082406e0
	strh r6, [r4]
_0806A110:
	movs r6, #0xd6
	lsls r6, r6, #1
	adds r3, r5, r6
	ldrh r0, [r3]
	cmp r0, #0
	bne _0806A11E
	b _0806A2B6
_0806A11E:
	ldr r1, _0806A15C @ =0x00000395
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806A1AC
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r2, [r0]
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r6, #0x2c
	ldrsh r0, [r5, r6]
	subs r3, r1, r0
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #0x30
	ldrsh r0, [r5, r2]
	subs r1, r1, r0
	cmp r3, #0
	blt _0806A160
	asrs r0, r3, #3
	b _0806A166
	.align 2, 0
_0806A14C: .4byte 0x000002E6
_0806A150: .4byte 0x000002E7
_0806A154: .4byte 0x000003F6
_0806A158: .4byte 0x000003D6
_0806A15C: .4byte 0x00000395
_0806A160:
	rsbs r0, r3, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_0806A166:
	strh r0, [r5, #0x34]
	cmp r1, #0
	blt _0806A170
	asrs r0, r1, #3
	b _0806A176
_0806A170:
	rsbs r0, r1, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_0806A176:
	strh r0, [r5, #0x38]
	ldr r3, _0806A1A4 @ =0x0000037E
	adds r4, r5, r3
	ldrh r1, [r4]
	cmp r1, #5
	bls _0806A184
	b _0806A29E
_0806A184:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0806A19A
	ldr r0, _0806A1A8 @ =0x00000191
	bl PlaySound_082406e0
	adds r0, r5, #0
	adds r0, #0x2c
	bl FUN_080acd98
_0806A19A:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _0806A29E
	.align 2, 0
_0806A1A4: .4byte 0x0000037E
_0806A1A8: .4byte 0x00000191
_0806A1AC:
	ldr r6, _0806A1DC @ =0x00000397
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806A23C
	movs r1, #0xe6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r2, [r0]
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r6, #0x2c
	ldrsh r0, [r5, r6]
	subs r3, r1, r0
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #0x30
	ldrsh r0, [r5, r2]
	subs r1, r1, r0
	cmp r3, #0
	blt _0806A1E0
	asrs r0, r3, #3
	b _0806A1E6
	.align 2, 0
_0806A1DC: .4byte 0x00000397
_0806A1E0:
	rsbs r0, r3, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_0806A1E6:
	strh r0, [r5, #0x34]
	cmp r1, #0
	blt _0806A1F0
	asrs r0, r1, #3
	b _0806A1F6
_0806A1F0:
	rsbs r0, r1, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_0806A1F6:
	strh r0, [r5, #0x38]
	ldr r3, _0806A234 @ =0x0000037E
	adds r6, r5, r3
	ldrh r0, [r6]
	cmp r0, #5
	bhi _0806A29E
	movs r4, #1
	ands r4, r0
	cmp r4, #0
	bne _0806A22A
	ldr r0, _0806A238 @ =0x00000191
	bl PlaySound_082406e0
	adds r0, r5, #0
	adds r0, #0x2c
	str r4, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl FUN_080ddcc8
_0806A22A:
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	b _0806A29E
	.align 2, 0
_0806A234: .4byte 0x0000037E
_0806A238: .4byte 0x00000191
_0806A23C:
	movs r6, #0xba
	lsls r6, r6, #2
	adds r0, r5, r6
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldr r2, _0806A26C @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldrh r0, [r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806A270
	asrs r0, r0, #0xc
	b _0806A276
	.align 2, 0
_0806A26C: .4byte 0x085B0A08
_0806A270:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806A276:
	rsbs r0, r0, #0
	strh r0, [r5, #0x34]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xd6
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806A294
	asrs r0, r0, #0xc
	b _0806A29A
_0806A294:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806A29A:
	rsbs r0, r0, #0
	strh r0, [r5, #0x38]
_0806A29E:
	movs r6, #0xd6
	lsls r6, r6, #1
	adds r4, r5, r6
	ldrh r0, [r4]
	bl FUN_0823b9cc
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r4]
	b _0806A324
_0806A2B6:
	movs r1, #0
	strh r0, [r3]
	ldr r2, _0806A2E8 @ =0x00000395
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _0806A2EC @ =0x00000397
	adds r0, r5, r3
	strb r1, [r0]
	ldr r6, _0806A2F0 @ =0x000004C5
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #3
	bne _0806A2F8
	ldr r1, _0806A2F4 @ =0x000004C7
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806A2F8
	adds r0, r5, #0
	movs r1, #0x13
	movs r2, #0
	bl FUN_08060b84
	b _0806A324
	.align 2, 0
_0806A2E8: .4byte 0x00000395
_0806A2EC: .4byte 0x00000397
_0806A2F0: .4byte 0x000004C5
_0806A2F4: .4byte 0x000004C7
_0806A2F8:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x2a
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806A324
	adds r0, r5, #0
	bl FUN_080609dc
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806A324:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0806a32c
FUN_0806a32c: @ 0x0806A32C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x19
	beq _0806A396
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #0
	bl FUN_08060b84
	movs r5, #0xba
	lsls r5, r5, #2
	adds r2, r4, r5
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0806A374
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _0806A370 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	subs r5, #1
	adds r1, r4, r5
	movs r0, #1
	strb r0, [r1]
	b _0806A384
	.align 2, 0
_0806A370: .4byte 0x000002E6
_0806A374:
	lsrs r1, r1, #0x19
	ldr r2, _0806A3AC @ =0x000002E6
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r5, _0806A3B0 @ =0x000002E7
	adds r0, r4, r5
	strb r2, [r0]
_0806A384:
	ldr r0, _0806A3B4 @ =0x000003D6
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	beq _0806A396
	bl PlaySound_082406e0
	movs r0, #0
	strh r0, [r5]
_0806A396:
	ldr r1, _0806A3B8 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bls _0806A3A2
	b _0806A61C
_0806A3A2:
	lsls r0, r0, #2
	ldr r1, _0806A3BC @ =_0806A3C0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806A3AC: .4byte 0x000002E6
_0806A3B0: .4byte 0x000002E7
_0806A3B4: .4byte 0x000003D6
_0806A3B8: .4byte 0x0000037D
_0806A3BC: .4byte _0806A3C0
_0806A3C0: @ jump table
	.4byte _0806A3D4 @ case 0
	.4byte _0806A410 @ case 1
	.4byte _0806A52C @ case 2
	.4byte _0806A5C4 @ case 3
	.4byte _0806A5E8 @ case 4
_0806A3D4:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r5, _0806A40C @ =0x0000037E
	adds r1, r4, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi _0806A400
	b _0806A61C
_0806A400:
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #1
	bl FUN_08060b84
	b _0806A61C
	.align 2, 0
_0806A40C: .4byte 0x0000037E
_0806A410:
	ldr r1, _0806A470 @ =0x0000037E
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0806A424
	ldr r2, _0806A474 @ =0x000003F6
	adds r1, r4, r2
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
_0806A424:
	movs r5, #0xd6
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrb r0, [r0]
	movs r1, #0x2b
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _0806A478 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806A47C
	asrs r0, r0, #0xc
	b _0806A482
	.align 2, 0
_0806A470: .4byte 0x0000037E
_0806A474: .4byte 0x000003F6
_0806A478: .4byte 0x085B0A08
_0806A47C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806A482:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	ldr r1, _0806A4A4 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806A4A8
	asrs r0, r0, #0xc
	b _0806A4AE
	.align 2, 0
_0806A4A4: .4byte 0x085B0A08
_0806A4A8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806A4AE:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	ldr r1, _0806A4DC @ =0x0000037E
	adds r3, r4, r1
	ldrh r0, [r3]
	cmp r0, #3
	bls _0806A4E8
	ldr r2, _0806A4E0 @ =0x000003F6
	adds r1, r4, r2
	ldrh r2, [r1]
	lsls r0, r0, #3
	cmp r2, r0
	blt _0806A4E4
	subs r0, r2, r0
	b _0806A4E6
	.align 2, 0
_0806A4DC: .4byte 0x0000037E
_0806A4E0: .4byte 0x000003F6
_0806A4E4:
	movs r0, #0
_0806A4E6:
	strh r0, [r1]
_0806A4E8:
	ldr r5, _0806A524 @ =0x0000037E
	adds r1, r4, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0x13
	bls _0806A500
	b _0806A61C
_0806A500:
	ldr r2, _0806A528 @ =0x000003F6
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0806A50C
	b _0806A61C
_0806A50C:
	strh r0, [r1]
	movs r0, #0xaa
	lsls r0, r0, #2
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #2
	bl FUN_08060b84
	b _0806A61C
	.align 2, 0
_0806A524: .4byte 0x0000037E
_0806A528: .4byte 0x000003F6
_0806A52C:
	movs r5, #0xba
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _0806A560 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806A564
	asrs r0, r0, #0xc
	b _0806A56A
	.align 2, 0
_0806A560: .4byte 0x085B0A08
_0806A564:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806A56A:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806A588
	asrs r0, r0, #0xc
	b _0806A58E
_0806A588:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806A58E:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x2c
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806A61C
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #3
	bl FUN_08060b84
	b _0806A61C
_0806A5C4:
	ldr r5, _0806A5E4 @ =0x0000037E
	adds r1, r4, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bls _0806A61C
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #4
	bl FUN_08060b84
	b _0806A61C
	.align 2, 0
_0806A5E4: .4byte 0x0000037E
_0806A5E8:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x2d
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806A61C
	ldr r2, _0806A624 @ =0x000003D2
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806A61C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806A624: .4byte 0x000003D2

	thumb_func_start FUN_0806a628
FUN_0806a628: @ 0x0806A628
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x1a
	beq _0806A6DE
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r5, #0xf5
	lsls r5, r5, #2
	adds r1, r4, r5
	movs r0, #0
	strh r0, [r1]
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0806A684
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _0806A680 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	subs r5, #0xed
	adds r1, r4, r5
	movs r0, #1
	b _0806A692
	.align 2, 0
_0806A680: .4byte 0x000002E6
_0806A684:
	lsrs r1, r1, #0x19
	ldr r2, _0806A6B4 @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r5, _0806A6B8 @ =0x000002E7
	adds r1, r4, r5
	movs r0, #0
_0806A692:
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0x1a
	movs r2, #0
	bl FUN_08060b84
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _0806A6C0
	ldr r0, _0806A6BC @ =0x000002EB
	bl PlaySound_082406e0
	b _0806A6C6
	.align 2, 0
_0806A6B4: .4byte 0x000002E6
_0806A6B8: .4byte 0x000002E7
_0806A6BC: .4byte 0x000002EB
_0806A6C0:
	movs r0, #0xe7
	bl PlaySound_082406e0
_0806A6C6:
	movs r0, #0xe6
	bl PlaySound_082406e0
	ldr r0, _0806A6F4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	beq _0806A6DE
	bl FUN_08050d10
_0806A6DE:
	ldr r2, _0806A6F8 @ =0x0000037D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #5
	bls _0806A6EA
	b _0806A884
_0806A6EA:
	lsls r0, r0, #2
	ldr r1, _0806A6FC @ =_0806A700
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806A6F4: .4byte 0x030047A4
_0806A6F8: .4byte 0x0000037D
_0806A6FC: .4byte _0806A700
_0806A700: @ jump table
	.4byte _0806A718 @ case 0
	.4byte _0806A79C @ case 1
	.4byte _0806A7F0 @ case 2
	.4byte _0806A820 @ case 3
	.4byte _0806A840 @ case 4
	.4byte _0806A87C @ case 5
_0806A718:
	movs r5, #0xba
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _0806A74C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806A750
	asrs r0, r0, #0xc
	b _0806A756
	.align 2, 0
_0806A74C: .4byte 0x085B0A08
_0806A750:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806A756:
	strh r0, [r4, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806A772
	asrs r0, r0, #0xc
	b _0806A778
_0806A772:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806A778:
	strh r0, [r4, #0x38]
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	cmp r0, #0
	beq _0806A790
	b _0806A884
_0806A790:
	adds r0, r4, #0
	movs r1, #0x1a
	movs r2, #1
	bl FUN_08060b84
	b _0806A884
_0806A79C:
	adds r0, r4, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #3
	bne _0806A7B6
	adds r0, r4, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _0806A7B6
	movs r0, #0xd1
	bl PlaySound_082406e0
_0806A7B6:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x2e
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806A884
	ldr r0, _0806A7EC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	bne _0806A80C
	adds r0, r4, #0
	movs r1, #0x1a
	movs r2, #2
	bl FUN_08060b84
	b _0806A884
	.align 2, 0
_0806A7EC: .4byte 0x030047A4
_0806A7F0:
	ldr r2, _0806A818 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0806A884
	ldr r0, _0806A81C @ =0x030047A4
	ldr r1, [r0]
	adds r2, #0x82
	orrs r1, r2
	str r1, [r0]
_0806A80C:
	adds r0, r4, #0
	movs r1, #0x1a
	movs r2, #3
	bl FUN_08060b84
	b _0806A884
	.align 2, 0
_0806A818: .4byte 0x0000037E
_0806A81C: .4byte 0x030047A4
_0806A820:
	ldr r5, _0806A83C @ =0x0000037E
	adds r1, r4, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0806A884
	adds r1, r4, #0
	adds r1, #0xa2
	movs r0, #1
	strb r0, [r1]
	b _0806A884
	.align 2, 0
_0806A83C: .4byte 0x0000037E
_0806A840:
	ldr r0, _0806A878 @ =0x0000037E
	adds r5, r4, r0
	ldrh r0, [r5]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #3
	subs r1, r1, r0
	cmp r2, r1
	blt _0806A85C
	adds r0, r4, #0
	movs r1, #5
	bl FUN_08060c40
_0806A85C:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x37
	bls _0806A884
	adds r0, r4, #0
	movs r1, #0x1a
	movs r2, #5
	bl FUN_08060b84
	b _0806A884
	.align 2, 0
_0806A878: .4byte 0x0000037E
_0806A87C:
	adds r0, r4, #0
	movs r1, #5
	bl FUN_08060c40
_0806A884:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0806a88c
FUN_0806a88c: @ 0x0806A88C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x1b
	beq _0806A922
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #0
	bl FUN_08060b84
	movs r5, #0xba
	lsls r5, r5, #2
	adds r2, r4, r5
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0806A8D4
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _0806A8D0 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	subs r5, #1
	adds r1, r4, r5
	movs r0, #1
	strb r0, [r1]
	b _0806A8E4
	.align 2, 0
_0806A8D0: .4byte 0x000002E6
_0806A8D4:
	lsrs r1, r1, #0x19
	ldr r2, _0806A8F8 @ =0x000002E6
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r5, _0806A8FC @ =0x000002E7
	adds r0, r4, r5
	strb r2, [r0]
_0806A8E4:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _0806A904
	ldr r0, _0806A900 @ =0x000002EB
	bl PlaySound_082406e0
	b _0806A90A
	.align 2, 0
_0806A8F8: .4byte 0x000002E6
_0806A8FC: .4byte 0x000002E7
_0806A900: .4byte 0x000002EB
_0806A904:
	movs r0, #0xe7
	bl PlaySound_082406e0
_0806A90A:
	movs r0, #0xe6
	bl PlaySound_082406e0
	ldr r0, _0806A938 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	beq _0806A922
	bl FUN_08050d10
_0806A922:
	ldr r2, _0806A93C @ =0x0000037D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #6
	bls _0806A92E
	b _0806ABCC
_0806A92E:
	lsls r0, r0, #2
	ldr r1, _0806A940 @ =_0806A944
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806A938: .4byte 0x030047A4
_0806A93C: .4byte 0x0000037D
_0806A940: .4byte _0806A944
_0806A944: @ jump table
	.4byte _0806A960 @ case 0
	.4byte _0806A9AC @ case 1
	.4byte _0806AA88 @ case 2
	.4byte _0806AB34 @ case 3
	.4byte _0806AB68 @ case 4
	.4byte _0806AB88 @ case 5
	.4byte _0806ABC4 @ case 6
_0806A960:
	movs r5, #0xd6
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _0806A9A4 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi _0806A98C
	b _0806ABCC
_0806A98C:
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #1
	bl FUN_08060b84
	ldr r2, _0806A9A8 @ =0x000003F6
	adds r1, r4, r2
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	b _0806ABCC
	.align 2, 0
_0806A9A4: .4byte 0x0000037E
_0806A9A8: .4byte 0x000003F6
_0806A9AC:
	movs r5, #0xd6
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrb r0, [r0]
	movs r1, #0x2b
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _0806A9F8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806A9FC
	asrs r0, r0, #0xc
	b _0806AA02
	.align 2, 0
_0806A9F8: .4byte 0x085B0A08
_0806A9FC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806AA02:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	ldr r1, _0806AA24 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806AA28
	asrs r0, r0, #0xc
	b _0806AA2E
	.align 2, 0
_0806AA24: .4byte 0x085B0A08
_0806AA28:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806AA2E:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	ldr r2, _0806AA50 @ =0x000003F6
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0xe
	bls _0806AA54
	subs r0, #0xf
	b _0806AA56
	.align 2, 0
_0806AA50: .4byte 0x000003F6
_0806AA54:
	movs r0, #0
_0806AA56:
	strh r0, [r1]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	cmp r0, #0x13
	bls _0806AA66
	b _0806ABCC
_0806AA66:
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #2
	bl FUN_08060b84
	ldr r1, _0806AA84 @ =0x000003F6
	adds r0, r4, r1
	movs r1, #0
	strh r1, [r0]
	movs r0, #0xaa
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _0806ABCC
	.align 2, 0
_0806AA84: .4byte 0x000003F6
_0806AA88:
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _0806AABC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806AAC0
	asrs r0, r0, #0xc
	b _0806AAC6
	.align 2, 0
_0806AABC: .4byte 0x085B0A08
_0806AAC0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806AAC6:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806AAE4
	asrs r0, r0, #0xc
	b _0806AAEA
_0806AAE4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806AAEA:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x2c
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806ABCC
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r0, #0
	strh r0, [r1]
	ldr r0, _0806AB30 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	bne _0806AB52
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #3
	bl FUN_08060b84
	b _0806ABCC
	.align 2, 0
_0806AB30: .4byte 0x030047A4
_0806AB34:
	ldr r5, _0806AB60 @ =0x0000037E
	adds r1, r4, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bls _0806ABCC
	ldr r0, _0806AB64 @ =0x030047A4
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #3
	orrs r1, r2
	str r1, [r0]
_0806AB52:
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #4
	bl FUN_08060b84
	b _0806ABCC
	.align 2, 0
_0806AB60: .4byte 0x0000037E
_0806AB64: .4byte 0x030047A4
_0806AB68:
	ldr r0, _0806AB84 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0806ABCC
	adds r1, r4, #0
	adds r1, #0xa2
	movs r0, #1
	strb r0, [r1]
	b _0806ABCC
	.align 2, 0
_0806AB84: .4byte 0x0000037E
_0806AB88:
	ldr r1, _0806ABC0 @ =0x0000037E
	adds r5, r4, r1
	ldrh r0, [r5]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #3
	subs r1, r1, r0
	cmp r2, r1
	blt _0806ABA4
	adds r0, r4, #0
	movs r1, #5
	bl FUN_08060c40
_0806ABA4:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x37
	bls _0806ABCC
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #6
	bl FUN_08060b84
	b _0806ABCC
	.align 2, 0
_0806ABC0: .4byte 0x0000037E
_0806ABC4:
	adds r0, r4, #0
	movs r1, #5
	bl FUN_08060c40
_0806ABCC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0806abd4
FUN_0806abd4: @ 0x0806ABD4
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r1, #4
	bl FUN_08060c40
	ldr r1, _0806ABF8 @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #5
	bls _0806ABEC
	b _0806ADC0
_0806ABEC:
	lsls r0, r0, #2
	ldr r1, _0806ABFC @ =_0806AC00
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806ABF8: .4byte 0x0000037D
_0806ABFC: .4byte _0806AC00
_0806AC00: @ jump table
	.4byte _0806AC18 @ case 0
	.4byte _0806AC5C @ case 1
	.4byte _0806ACA8 @ case 2
	.4byte _0806AD0C @ case 3
	.4byte _0806AD70 @ case 4
	.4byte _0806ADB8 @ case 5
_0806AC18:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _0806AC54 @ =0x000001AD
	bl PlaySound_082406e0
	adds r1, r5, #0
	adds r1, #0xef
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #0x1c
	movs r2, #1
	bl FUN_08060b84
	ldr r1, _0806AC58 @ =0x000003F6
	adds r0, r5, r1
	strh r4, [r0]
	str r4, [r5, #0x3c]
	b _0806ADC0
	.align 2, 0
_0806AC54: .4byte 0x000001AD
_0806AC58: .4byte 0x000003F6
_0806AC5C:
	ldr r0, _0806AC9C @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bhi _0806AC70
	b _0806ADC0
_0806AC70:
	movs r0, #4
	str r0, [sp]
	ldr r0, _0806ACA0 @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r0, _0806ACA4 @ =0x000003F6
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #0x1c
	movs r2, #2
	bl FUN_08060b84
	b _0806ADC0
	.align 2, 0
_0806AC9C: .4byte 0x0000037E
_0806ACA0: .4byte 0x00001FFF
_0806ACA4: .4byte 0x000003F6
_0806ACA8:
	ldr r1, _0806ACC8 @ =0x0000037E
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #9
	bne _0806ACD4
	subs r1, #0x26
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _0806ACCC
	movs r0, #0xbb
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _0806ACD4
	.align 2, 0
_0806ACC8: .4byte 0x0000037E
_0806ACCC:
	movs r0, #0xc1
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0806ACD4:
	ldr r0, _0806AD00 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls _0806ADC0
	adds r0, r5, #0
	movs r1, #0x1c
	movs r2, #3
	bl FUN_08060b84
	ldr r1, _0806AD04 @ =0x000003F6
	adds r0, r5, r1
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0806AD08 @ =0x000001AF
	bl PlaySound_082406e0
	b _0806ADC0
	.align 2, 0
_0806AD00: .4byte 0x0000037E
_0806AD04: .4byte 0x000003F6
_0806AD08: .4byte 0x000001AF
_0806AD0C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x12
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _0806AD58 @ =0x000003F6
	adds r1, r5, r0
	ldrh r0, [r1]
	subs r0, #0x1e
	strh r0, [r1]
	ldr r0, _0806AD5C @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x27
	bls _0806AD60
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #0x1c
	movs r2, #4
	bl FUN_08060b84
	b _0806ADC0
	.align 2, 0
_0806AD58: .4byte 0x000003F6
_0806AD5C: .4byte 0x0000037E
_0806AD60:
	adds r0, r5, #0
	adds r0, #0xe8
	ldrh r1, [r1]
	movs r2, #0xa
	movs r3, #0x14
	bl FUN_082375c8
	b _0806ADC0
_0806AD70:
	ldr r0, _0806ADAC @ =0x000003F6
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08060c40
	ldr r0, _0806ADB0 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _0806ADC0
	adds r0, r5, #0
	movs r1, #0x1c
	movs r2, #5
	bl FUN_08060b84
	ldr r0, _0806ADB4 @ =0x030047A4
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #3
	orrs r1, r2
	str r1, [r0]
	b _0806ADC0
	.align 2, 0
_0806ADAC: .4byte 0x000003F6
_0806ADB0: .4byte 0x0000037E
_0806ADB4: .4byte 0x030047A4
_0806ADB8:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08060c40
_0806ADC0:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0806adc8
FUN_0806adc8: @ 0x0806ADC8
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r1, #4
	bl FUN_08060c40
	ldr r1, _0806ADEC @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #5
	bls _0806ADE0
	b _0806AF68
_0806ADE0:
	lsls r0, r0, #2
	ldr r1, _0806ADF0 @ =_0806ADF4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806ADEC: .4byte 0x0000037D
_0806ADF0: .4byte _0806ADF4
_0806ADF4: @ jump table
	.4byte _0806AE0C @ case 0
	.4byte _0806AE50 @ case 1
	.4byte _0806AE84 @ case 2
	.4byte _0806AEDC @ case 3
	.4byte _0806AF24 @ case 4
	.4byte _0806AF60 @ case 5
_0806AE0C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _0806AE48 @ =0x000001AD
	bl PlaySound_082406e0
	adds r1, r5, #0
	adds r1, #0xef
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #0x1d
	movs r2, #1
	bl FUN_08060b84
	ldr r1, _0806AE4C @ =0x000003F6
	adds r0, r5, r1
	strh r4, [r0]
	str r4, [r5, #0x3c]
	b _0806AF68
	.align 2, 0
_0806AE48: .4byte 0x000001AD
_0806AE4C: .4byte 0x000003F6
_0806AE50:
	ldr r0, _0806AE80 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bhi _0806AE64
	b _0806AF68
_0806AE64:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08060c40
	movs r0, #0xd7
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #0x1d
	movs r2, #2
	bl FUN_08060b84
	b _0806AF68
	.align 2, 0
_0806AE80: .4byte 0x0000037E
_0806AE84:
	ldr r0, _0806AED0 @ =0x000003F6
	adds r1, r5, r0
	ldrh r0, [r1]
	subs r0, #0x1e
	strh r0, [r1]
	ldr r0, _0806AED4 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _0806AF68
	adds r0, r5, #0
	adds r0, #0x2c
	str r0, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #0x1e
	bl FUN_08016110
	ldr r0, _0806AED8 @ =0x00000145
	bl PlaySound_082406e0
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #0x1d
	movs r2, #3
	bl FUN_08060b84
	b _0806AF68
	.align 2, 0
_0806AED0: .4byte 0x000003F6
_0806AED4: .4byte 0x0000037E
_0806AED8: .4byte 0x00000145
_0806AEDC:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08060c40
	ldr r0, _0806AF1C @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _0806AF68
	movs r0, #4
	str r0, [sp]
	ldr r0, _0806AF20 @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	adds r0, r5, #0
	movs r1, #0x1d
	movs r2, #4
	bl FUN_08060b84
	b _0806AF68
	.align 2, 0
_0806AF1C: .4byte 0x0000037E
_0806AF20: .4byte 0x00001FFF
_0806AF24:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08060c40
	ldr r0, _0806AF58 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _0806AF68
	adds r0, r5, #0
	movs r1, #0x1d
	movs r2, #5
	bl FUN_08060b84
	ldr r0, _0806AF5C @ =0x030047A4
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #3
	orrs r1, r2
	str r1, [r0]
	b _0806AF68
	.align 2, 0
_0806AF58: .4byte 0x0000037E
_0806AF5C: .4byte 0x030047A4
_0806AF60:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08060c40
_0806AF68:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0806af70
FUN_0806af70: @ 0x0806AF70
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _0806AF88 @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _0806AFF8
	cmp r0, #1
	bgt _0806AF8C
	cmp r0, #0
	beq _0806AF92
	b _0806B062
	.align 2, 0
_0806AF88: .4byte 0x0000037D
_0806AF8C:
	cmp r0, #2
	beq _0806B03E
	b _0806B062
_0806AF92:
	ldr r1, _0806AFC4 @ =0x0000037E
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0806AFD2
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r4, r5, r0
	ldrb r0, [r4]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldrb r0, [r4]
	cmp r0, #5
	bne _0806AFCC
	ldr r0, _0806AFC8 @ =0x000002EE
	bl PlaySound_082406e0
	b _0806AFD2
	.align 2, 0
_0806AFC4: .4byte 0x0000037E
_0806AFC8: .4byte 0x000002EE
_0806AFCC:
	ldr r0, _0806AFF0 @ =0x00000301
	bl PlaySound_082406e0
_0806AFD2:
	ldr r0, _0806AFF4 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _0806B062
	adds r0, r5, #0
	movs r1, #0x1e
	movs r2, #1
	bl FUN_08060b84
	b _0806B062
	.align 2, 0
_0806AFF0: .4byte 0x00000301
_0806AFF4: .4byte 0x0000037E
_0806AFF8:
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r1, [r0]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _0806B016
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _0806B016
	movs r0, #0xd1
	bl PlaySound_082406e0
_0806B016:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x2e
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806B062
	adds r0, r5, #0
	movs r1, #0x1e
	movs r2, #2
	bl FUN_08060b84
	b _0806B062
_0806B03E:
	ldr r0, _0806B068 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0806B062
	adds r0, r5, #0
	movs r1, #0x1e
	movs r2, #3
	bl FUN_08060b84
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08060e90
_0806B062:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806B068: .4byte 0x0000037E

	thumb_func_start FUN_0806b06c
FUN_0806b06c: @ 0x0806B06C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x20
	beq _0806B086
	adds r0, r5, #0
	movs r1, #0x20
	movs r2, #0
	bl FUN_08060b84
_0806B086:
	ldr r2, _0806B09C @ =0x0000037D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #4
	bls _0806B092
	b _0806B35E
_0806B092:
	lsls r0, r0, #2
	ldr r1, _0806B0A0 @ =_0806B0A4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806B09C: .4byte 0x0000037D
_0806B0A0: .4byte _0806B0A4
_0806B0A4: @ jump table
	.4byte _0806B0B8 @ case 0
	.4byte _0806B20A @ case 1
	.4byte _0806B2A8 @ case 2
	.4byte _0806B308 @ case 3
	.4byte _0806B31C @ case 4
_0806B0B8:
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r2, #0
	movs r0, #7
	strb r0, [r1]
	ldr r1, _0806B128 @ =0x000002E6
	adds r0, r5, r1
	movs r1, #1
	strb r1, [r0]
	subs r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _0806B12C @ =0x0000042E
	adds r0, r5, r1
	strh r2, [r0]
	movs r1, #0x1f
	ldr r2, _0806B130 @ =0x0000040C
	adds r6, r5, r2
	adds r4, r0, #0
_0806B0E0:
	subs r3, r1, #1
	adds r2, r6, r3
	ldrb r0, [r2]
	cmp r0, #0
	beq _0806B0F0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_0806B0F0:
	adds r1, r6, r1
	ldrb r0, [r2]
	strb r0, [r1]
	adds r1, r3, #0
	cmp r1, #0
	bgt _0806B0E0
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	ldr r2, _0806B134 @ =0x0000042C
	adds r1, r5, r2
	ldrh r0, [r0, #2]
	ldrh r1, [r1]
	ands r1, r0
	cmp r1, #0
	beq _0806B138
	ldr r3, _0806B130 @ =0x0000040C
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0806B12C @ =0x0000042E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0806B13E
	.align 2, 0
_0806B128: .4byte 0x000002E6
_0806B12C: .4byte 0x0000042E
_0806B130: .4byte 0x0000040C
_0806B134: .4byte 0x0000042C
_0806B138:
	ldr r2, _0806B154 @ =0x0000040C
	adds r0, r5, r2
	strb r1, [r0]
_0806B13E:
	ldr r3, _0806B158 @ =0x0000042E
	adds r0, r5, r3
	ldrh r0, [r0]
	adds r1, r0, #0
	cmp r1, #0
	beq _0806B1E8
	cmp r1, #3
	bhi _0806B15C
	lsls r0, r0, #4
	movs r1, #0x80
	b _0806B17C
	.align 2, 0
_0806B154: .4byte 0x0000040C
_0806B158: .4byte 0x0000042E
_0806B15C:
	cmp r1, #5
	bhi _0806B172
	subs r0, #2
	lsls r0, r0, #3
	movs r1, #0x40
	subs r1, r1, r0
	movs r3, #0x86
	lsls r3, r3, #3
	adds r0, r5, r3
	strh r1, [r0]
	b _0806B192
_0806B172:
	cmp r1, #7
	bhi _0806B188
	subs r0, #4
	lsls r0, r0, #2
	movs r1, #0x20
_0806B17C:
	subs r1, r1, r0
	movs r2, #0x86
	lsls r2, r2, #3
	adds r0, r5, r2
	strh r1, [r0]
	b _0806B192
_0806B188:
	movs r3, #0x86
	lsls r3, r3, #3
	adds r1, r5, r3
	movs r0, #0x10
	strh r0, [r1]
_0806B192:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #1
	bl FUN_08066ee4
	adds r1, r0, #0
	movs r2, #0x86
	lsls r2, r2, #3
	adds r0, r5, r2
	ldrh r2, [r0]
	adds r0, r5, #0
	bl FUN_08060a24
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	beq _0806B1BC
	b _0806B35E
_0806B1BC:
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _0806B1D4
	ldr r0, _0806B1D0 @ =0x0000028E
	bl PlaySound_082406e0
	b _0806B35E
	.align 2, 0
_0806B1D0: .4byte 0x0000028E
_0806B1D4:
	cmp r0, #3
	beq _0806B1DA
	b _0806B35E
_0806B1DA:
	ldr r0, _0806B1E4 @ =0x0000028D
	bl PlaySound_082406e0
	b _0806B35E
	.align 2, 0
_0806B1E4: .4byte 0x0000028D
_0806B1E8:
	movs r3, #0x86
	lsls r3, r3, #3
	adds r4, r5, r3
	strh r1, [r4]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	ldrh r2, [r4]
	adds r0, r5, #0
	bl FUN_08060a24
	b _0806B35E
_0806B20A:
	ldr r2, _0806B284 @ =0x0000037E
	adds r6, r5, r2
	ldrh r4, [r6]
	cmp r4, #0
	bne _0806B24E
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r0, #7
	strb r0, [r1]
	ldr r1, _0806B288 @ =0x000002E6
	adds r0, r5, r1
	strb r4, [r0]
	subs r2, #0x97
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	adds r3, #0x70
	adds r0, r5, r3
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _0806B28C @ =0x000001AD
	bl PlaySound_082406e0
	ldr r1, _0806B290 @ =0x000003F6
	adds r0, r5, r1
	strh r4, [r0]
_0806B24E:
	adds r0, r5, #0
	movs r1, #4
	bl FUN_08060c40
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bhi _0806B266
	b _0806B35E
_0806B266:
	movs r0, #0xd7
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #5
	bne _0806B294
	movs r0, #0xbb
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _0806B29C
	.align 2, 0
_0806B284: .4byte 0x0000037E
_0806B288: .4byte 0x000002E6
_0806B28C: .4byte 0x000001AD
_0806B290: .4byte 0x000003F6
_0806B294:
	movs r0, #0xc1
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0806B29C:
	adds r0, r5, #0
	movs r1, #0x20
	movs r2, #2
	bl FUN_08060b84
	b _0806B35E
_0806B2A8:
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrb r0, [r0]
	movs r1, #0x12
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _0806B2FC @ =0x000003F6
	adds r4, r5, r0
	ldrh r0, [r4]
	subs r0, #0x3c
	strh r0, [r4]
	adds r0, r5, #0
	movs r1, #4
	bl FUN_08060c40
	ldr r2, _0806B300 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _0806B35E
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08060c40
	ldr r0, _0806B304 @ =0x000005DC
	strh r0, [r4]
	adds r0, r5, #0
	movs r1, #0x20
	movs r2, #3
	bl FUN_08060b84
	b _0806B35E
	.align 2, 0
_0806B2FC: .4byte 0x000003F6
_0806B300: .4byte 0x0000037E
_0806B304: .4byte 0x000005DC
_0806B308:
	adds r0, r5, #0
	movs r1, #5
	bl FUN_08060c40
	ldr r3, _0806B318 @ =0x0000037E
	adds r1, r5, r3
	b _0806B358
	.align 2, 0
_0806B318: .4byte 0x0000037E
_0806B31C:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r4, #0
	movs r0, #7
	strb r0, [r1]
	ldr r1, _0806B364 @ =0x000002E6
	adds r0, r5, r1
	movs r1, #1
	strb r1, [r0]
	ldr r2, _0806B368 @ =0x000002E7
	adds r0, r5, r2
	strb r1, [r0]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r1, _0806B36C @ =0x000003F6
	adds r0, r5, r1
	strh r4, [r0]
	ldr r2, _0806B370 @ =0x0000037E
	adds r1, r5, r2
_0806B358:
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0806B35E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806B364: .4byte 0x000002E6
_0806B368: .4byte 0x000002E7
_0806B36C: .4byte 0x000003F6
_0806B370: .4byte 0x0000037E

	thumb_func_start FUN_0806b374
FUN_0806b374: @ 0x0806B374
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _0806B396
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0xd1
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0806B396:
	adds r0, r4, #0
	movs r1, #8
	bl FUN_08060c40
	ldr r0, _0806B3BC @ =0x0000037E
	adds r5, r4, r0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0806B3C0
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	b _0806B428
	.align 2, 0
_0806B3BC: .4byte 0x0000037E
_0806B3C0:
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08060c40
	ldrh r0, [r5]
	subs r0, #5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0806B3DC
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08060c40
_0806B3DC:
	adds r0, r4, #0
	movs r1, #4
	bl FUN_08060c40
	ldr r0, _0806B430 @ =0x0000095E
	adds r1, r4, r0
	ldr r0, _0806B434 @ =0x00000127
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x18
	strh r0, [r1]
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0806B40A
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_08060aa4
_0806B40A:
	adds r0, r4, #0
	bl FUN_080609dc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #1
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
_0806B428:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806B430: .4byte 0x0000095E
_0806B434: .4byte 0x00000127

	thumb_func_start FUN_0806b438
FUN_0806b438: @ 0x0806B438
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #9
	beq _0806B48E
	ldr r2, _0806B470 @ =0x00000951
	adds r0, r4, r2
	movs r1, #0
	strb r1, [r0]
	adds r0, r4, #0
	movs r1, #0x64
	bl FUN_08064d54
	cmp r0, #0
	beq _0806B47C
	ldr r0, _0806B474 @ =0x03002BD0
	ldrh r0, [r0]
	cmp r0, #0
	bne _0806B47C
	ldr r3, _0806B478 @ =0x000003FA
	adds r1, r4, r3
	movs r0, #1
	b _0806B482
	.align 2, 0
_0806B470: .4byte 0x00000951
_0806B474: .4byte 0x03002BD0
_0806B478: .4byte 0x000003FA
_0806B47C:
	ldr r0, _0806B4A4 @ =0x000003FA
	adds r1, r4, r0
	movs r0, #0
_0806B482:
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #9
	movs r2, #0
	bl FUN_08060b84
_0806B48E:
	ldr r1, _0806B4A8 @ =0x0000037D
	adds r0, r4, r1
	ldrb r2, [r0]
	cmp r2, #1
	bne _0806B49A
	b _0806B5F8
_0806B49A:
	cmp r2, #1
	bgt _0806B4AC
	cmp r2, #0
	beq _0806B4BA
	b _0806B74E
	.align 2, 0
_0806B4A4: .4byte 0x000003FA
_0806B4A8: .4byte 0x0000037D
_0806B4AC:
	cmp r2, #2
	bne _0806B4B2
	b _0806B688
_0806B4B2:
	cmp r2, #3
	bne _0806B4B8
	b _0806B718
_0806B4B8:
	b _0806B74E
_0806B4BA:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r3, r4, r0
	ldrb r0, [r3]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _0806B51C
	movs r1, #4
	strb r1, [r3]
	ldr r3, _0806B50C @ =0x000002E6
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _0806B510 @ =0x000002E7
	adds r0, r4, r1
	strb r2, [r0]
	movs r3, #0x93
	lsls r3, r3, #4
	adds r2, r4, r3
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	subs r0, #0x14
	strh r0, [r2]
	ldr r0, _0806B514 @ =0x00000932
	adds r1, r4, r0
	movs r2, #0xa5
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldr r0, _0806B518 @ =0x00000934
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0x3c
	b _0806B556
	.align 2, 0
_0806B50C: .4byte 0x000002E6
_0806B510: .4byte 0x000002E7
_0806B514: .4byte 0x00000932
_0806B518: .4byte 0x00000934
_0806B51C:
	strb r2, [r3]
	ldr r1, _0806B584 @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	ldr r3, _0806B588 @ =0x000002E7
	adds r0, r4, r3
	strb r2, [r0]
	movs r0, #0x93
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	adds r0, #0x14
	strh r0, [r2]
	ldr r2, _0806B58C @ =0x00000932
	adds r1, r4, r2
	movs r3, #0xa5
	lsls r3, r3, #1
	adds r0, r3, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r3, _0806B590 @ =0x00000934
	adds r1, r4, r3
	ldrh r0, [r1]
	subs r0, #0x14
_0806B556:
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #4
	bne _0806B594
	ldr r3, _0806B584 @ =0x000002E6
	adds r1, r4, r3
	movs r0, #1
	b _0806B59A
	.align 2, 0
_0806B584: .4byte 0x000002E6
_0806B588: .4byte 0x000002E7
_0806B58C: .4byte 0x00000932
_0806B590: .4byte 0x00000934
_0806B594:
	ldr r0, _0806B5E8 @ =0x000002E6
	adds r1, r4, r0
	movs r0, #0
_0806B59A:
	strb r0, [r1]
	ldr r1, _0806B5EC @ =0x000003FA
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806B5DC
	movs r0, #0xb9
	lsls r0, r0, #2
	bl PlaySound_082406e0
	ldr r2, _0806B5F0 @ =0x0000095E
	adds r1, r4, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r4, r3
	movs r0, #2
	strh r0, [r1]
	adds r1, r4, #0
	adds r1, #0x2c
	movs r0, #0x93
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r3, _0806B5F4 @ =0x000003BA
	adds r0, r4, r3
	ldrh r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #1
	bl FUN_080abd14
_0806B5DC:
	adds r0, r4, #0
	movs r1, #9
	movs r2, #1
	bl FUN_08060b84
	b _0806B74E
	.align 2, 0
_0806B5E8: .4byte 0x000002E6
_0806B5EC: .4byte 0x000003FA
_0806B5F0: .4byte 0x0000095E
_0806B5F4: .4byte 0x000003BA
_0806B5F8:
	ldr r1, _0806B678 @ =0x000003FA
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806B624
	ldr r2, _0806B67C @ =0x0000095E
	adds r1, r4, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _0806B624
	movs r0, #0x20
	strh r0, [r1]
_0806B624:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #8
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	bne _0806B64C
	b _0806B74E
_0806B64C:
	movs r0, #0xcb
	bl PlaySound_082406e0
	ldr r2, _0806B678 @ =0x000003FA
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806B66C
	ldr r3, _0806B680 @ =0x000003BA
	adds r0, r4, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _0806B66C
	ldr r1, _0806B684 @ =0x03002BD0
	movs r0, #1
	strh r0, [r1]
_0806B66C:
	adds r0, r4, #0
	movs r1, #9
	movs r2, #2
	bl FUN_08060b84
	b _0806B74E
	.align 2, 0
_0806B678: .4byte 0x000003FA
_0806B67C: .4byte 0x0000095E
_0806B680: .4byte 0x000003BA
_0806B684: .4byte 0x03002BD0
_0806B688:
	ldr r1, _0806B6B8 @ =0x000003FA
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806B6C0
	ldr r2, _0806B6BC @ =0x0000095E
	adds r1, r4, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _0806B6D2
	movs r0, #0x20
	strh r0, [r1]
	b _0806B6D2
	.align 2, 0
_0806B6B8: .4byte 0x000003FA
_0806B6BC: .4byte 0x0000095E
_0806B6C0:
	ldr r1, _0806B714 @ =0x0000037E
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0806B6D2
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0806B6D2:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0xa
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r3, #0xc1
	lsls r3, r3, #3
	adds r1, r4, r3
	movs r0, #0x1e
	strh r0, [r1]
	ldr r0, _0806B714 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x17
	bls _0806B74E
	adds r0, r4, #0
	movs r1, #9
	movs r2, #3
	bl FUN_08060b84
	b _0806B74E
	.align 2, 0
_0806B714: .4byte 0x0000037E
_0806B718:
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
	beq _0806B74E
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806B74E:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0806b758
FUN_0806b758: @ 0x0806B758
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r1, _0806B774 @ =0x0000037D
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #5
	bls _0806B76A
	b _0806B924
_0806B76A:
	lsls r0, r0, #2
	ldr r1, _0806B778 @ =_0806B77C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806B774: .4byte 0x0000037D
_0806B778: .4byte _0806B77C
_0806B77C: @ jump table
	.4byte _0806B794 @ case 0
	.4byte _0806B86C @ case 1
	.4byte _0806B894 @ case 2
	.4byte _0806B924 @ case 3
	.4byte _0806B8E0 @ case 4
	.4byte _0806B91C @ case 5
_0806B794:
	ldr r2, _0806B85C @ =0x0000037E
	adds r0, r6, r2
	ldrh r5, [r0]
	cmp r5, #0
	bne _0806B81E
	movs r0, #0xe7
	bl PlaySound_082406e0
	movs r3, #0x99
	lsls r3, r3, #4
	adds r2, r6, r3
	strb r5, [r2]
	ldr r1, _0806B860 @ =0x00000992
	adds r0, r6, r1
	strh r5, [r0]
	subs r3, #4
	adds r4, r6, r3
	ldr r0, [r4]
	adds r1, r6, #0
	adds r1, #0x24
	ldrb r2, [r2]
	str r5, [sp]
	str r5, [sp, #4]
	str r5, [sp, #8]
	movs r3, #0x50
	str r3, [sp, #0xc]
	movs r3, #1
	bl FUN_080da9c4
	str r0, [r4]
	ldr r0, _0806B864 @ =0x000001B1
	bl PlaySound_082406e0
	ldr r0, _0806B868 @ =0x03002C00
	ldr r2, [r0]
	cmp r2, #0
	beq _0806B81E
	adds r0, r2, #0
	adds r0, #0x48
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #0x2c
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	adds r1, r2, #0
	adds r1, #0x4c
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r3, #0x30
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl FUN_0823785c
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
	adds r0, r6, r2
	strb r1, [r0]
	adds r0, r6, #0
	bl FUN_080609dc
_0806B81E:
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r6, r3
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r6, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _0806B85C @ =0x0000037E
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bls _0806B924
	movs r0, #0xd0
	bl PlaySound_082406e0
	adds r0, r6, #0
	movs r1, #0x1f
	movs r2, #1
	bl FUN_08060b84
	b _0806B924
	.align 2, 0
_0806B85C: .4byte 0x0000037E
_0806B860: .4byte 0x00000992
_0806B864: .4byte 0x000001B1
_0806B868: .4byte 0x03002C00
_0806B86C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, #0x30
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r6, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806B924
	adds r0, r6, #0
	movs r1, #0x1f
	movs r2, #2
	bl FUN_08060b84
	b _0806B924
_0806B894:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	movs r1, #0x31
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r6, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r3, _0806B8D8 @ =0x0000037E
	adds r1, r6, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0806B924
	adds r0, r6, #0
	movs r1, #0x1f
	movs r2, #3
	bl FUN_08060b84
	ldr r0, _0806B8DC @ =0x030047A4
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #3
	orrs r1, r2
	str r1, [r0]
	b _0806B924
	.align 2, 0
_0806B8D8: .4byte 0x0000037E
_0806B8DC: .4byte 0x030047A4
_0806B8E0:
	ldr r0, _0806B918 @ =0x0000037E
	adds r4, r6, r0
	ldrh r0, [r4]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #3
	subs r1, r1, r0
	cmp r2, r1
	blt _0806B8FC
	adds r0, r6, #0
	movs r1, #5
	bl FUN_08060c40
_0806B8FC:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x37
	bls _0806B924
	adds r0, r6, #0
	movs r1, #0x1f
	movs r2, #5
	bl FUN_08060b84
	b _0806B924
	.align 2, 0
_0806B918: .4byte 0x0000037E
_0806B91C:
	adds r0, r6, #0
	movs r1, #5
	bl FUN_08060c40
_0806B924:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0806b92c
FUN_0806b92c: @ 0x0806B92C
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0xa
	beq _0806B98A
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08064d54
	adds r1, r0, #0
	cmp r1, #0
	beq _0806B974
	ldr r2, _0806B968 @ =0x0000095E
	adds r1, r4, r2
	movs r2, #0
	ldr r0, _0806B96C @ =0x00000127
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r0, r4, r3
	strh r2, [r0]
	ldr r0, _0806B970 @ =0x000003FA
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _0806B97A
	.align 2, 0
_0806B968: .4byte 0x0000095E
_0806B96C: .4byte 0x00000127
_0806B970: .4byte 0x000003FA
_0806B974:
	ldr r2, _0806B9A0 @ =0x000003FA
	adds r0, r4, r2
	strb r1, [r0]
_0806B97A:
	ldr r0, _0806B9A4 @ =0x00000306
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0
	bl FUN_08060b84
_0806B98A:
	ldr r3, _0806B9A8 @ =0x0000037D
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #4
	bls _0806B996
	b _0806BC6A
_0806B996:
	lsls r0, r0, #2
	ldr r1, _0806B9AC @ =_0806B9B0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806B9A0: .4byte 0x000003FA
_0806B9A4: .4byte 0x00000306
_0806B9A8: .4byte 0x0000037D
_0806B9AC: .4byte _0806B9B0
_0806B9B0: @ jump table
	.4byte _0806B9C4 @ case 0
	.4byte _0806BA90 @ case 1
	.4byte _0806BB00 @ case 2
	.4byte _0806BBE0 @ case 3
	.4byte _0806BC34 @ case 4
_0806B9C4:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r3, r4, r0
	ldrb r0, [r3]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _0806B9F4
	movs r2, #0
	movs r1, #4
	strb r1, [r3]
	ldr r3, _0806B9EC @ =0x000002E6
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _0806B9F0 @ =0x000002E7
	adds r0, r4, r1
	strb r2, [r0]
	b _0806BA04
	.align 2, 0
_0806B9EC: .4byte 0x000002E6
_0806B9F0: .4byte 0x000002E7
_0806B9F4:
	movs r0, #0
	strb r0, [r3]
	ldr r2, _0806BA58 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r3, _0806BA5C @ =0x000002E7
	adds r1, r4, r3
	strb r0, [r1]
_0806BA04:
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r5, r4, r0
	ldrb r0, [r5]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _0806BA58 @ =0x000002E6
	adds r1, r4, r2
	ldrb r0, [r1]
	lsrs r0, r0, #2
	strb r0, [r1]
	ldr r3, _0806BA60 @ =0x000003FA
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806BA7E
	ldr r1, _0806BA64 @ =0xFFFF0000
	movs r0, #0
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	movs r1, #0xf
	orrs r0, r1
	str r0, [sp, #8]
	ldrb r0, [r5]
	cmp r0, #0
	bne _0806BA68
	movs r0, #0x45
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #7
	add r2, sp, #4
	movs r3, #0x32
	bl FUN_080ac374
	b _0806BA78
	.align 2, 0
_0806BA58: .4byte 0x000002E6
_0806BA5C: .4byte 0x000002E7
_0806BA60: .4byte 0x000003FA
_0806BA64: .4byte 0xFFFF0000
_0806BA68:
	movs r0, #0x45
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #7
	add r2, sp, #4
	movs r3, #0x32
	bl FUN_080ac374
_0806BA78:
	ldr r0, _0806BA8C @ =0x0000039B
	bl PlaySound_082406e0
_0806BA7E:
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #1
	bl FUN_08060b84
	b _0806BC6A
	.align 2, 0
_0806BA8C: .4byte 0x0000039B
_0806BA90:
	ldr r1, _0806BAF0 @ =0x000003FA
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806BAB2
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _0806BAB2
	movs r0, #0x20
	strh r0, [r1]
_0806BAB2:
	movs r3, #0xc1
	lsls r3, r3, #3
	adds r1, r4, r3
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #8
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	bne _0806BADA
	b _0806BC6A
_0806BADA:
	ldr r2, _0806BAF0 @ =0x000003FA
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806BAF4
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #2
	bl FUN_08060b84
	b _0806BC6A
	.align 2, 0
_0806BAF0: .4byte 0x000003FA
_0806BAF4:
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #3
	bl FUN_08060b84
	b _0806BC6A
_0806BB00:
	ldr r3, _0806BB20 @ =0x0000037E
	adds r0, r4, r3
	ldrh r0, [r0]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #2
	subs r1, r1, r0
	cmp r2, r1
	bge _0806BB24
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	b _0806BB32
	.align 2, 0
_0806BB20: .4byte 0x0000037E
_0806BB24:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0806BB44
	movs r0, #1
_0806BB32:
	movs r1, #0xa
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	b _0806BB56
_0806BB44:
	movs r0, #0
	movs r1, #0xa
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
_0806BB56:
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	ldr r3, _0806BB9C @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _0806BB72
	movs r0, #0x20
	strh r0, [r1]
_0806BB72:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0x1e
	strh r0, [r1]
	ldr r3, _0806BBA0 @ =0x0000037E
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ands r0, r2
	cmp r0, #0x1f
	bls _0806BC6A
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _0806BBA4
	movs r0, #1
	b _0806BBA6
	.align 2, 0
_0806BB9C: .4byte 0x0000FFFF
_0806BBA0: .4byte 0x0000037E
_0806BBA4:
	movs r0, #0
_0806BBA6:
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_08062c3c
	ldr r1, _0806BBD0 @ =0x0000094C
	adds r0, r4, r1
	ldr r1, _0806BBD4 @ =0x0000FFFF
	strh r1, [r0]
	ldr r2, _0806BBD8 @ =0x00000444
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #5
	beq _0806BC22
	cmp r0, #0x22
	beq _0806BC22
	ldr r3, _0806BBDC @ =0x00000446
	adds r1, r4, r3
	movs r0, #0
	strh r0, [r1]
	b _0806BC22
	.align 2, 0
_0806BBD0: .4byte 0x0000094C
_0806BBD4: .4byte 0x0000FFFF
_0806BBD8: .4byte 0x00000444
_0806BBDC: .4byte 0x00000446
_0806BBE0:
	ldr r0, _0806BC30 @ =0x0000037E
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _0806BBF2
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0806BBF2:
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
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0806BC6A
_0806BC22:
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #4
	bl FUN_08060b84
	b _0806BC6A
	.align 2, 0
_0806BC30: .4byte 0x0000037E
_0806BC34:
	movs r3, #0xc1
	lsls r3, r3, #3
	adds r1, r4, r3
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0xb
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806BC6A
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806BC6A:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0806bc74
FUN_0806bc74: @ 0x0806BC74
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0xc
	beq _0806BCBC
	adds r0, r5, #0
	movs r1, #0xc
	movs r2, #0
	bl FUN_08060b84
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r0, #0
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_08063220
	adds r0, r5, #0
	bl FUN_08066e84
	ldr r0, _0806BCFC @ =0x0000039A
	bl PlaySound_082406e0
	movs r0, #0x38
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #0
	movs r3, #0x20
	bl FUN_080ac374
_0806BCBC:
	ldr r0, _0806BD00 @ =0x0000037E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0x10
	bne _0806BCCE
	movs r0, #0xe8
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0806BCCE:
	ldrh r0, [r4]
	movs r4, #7
	adds r1, r4, #0
	ands r1, r0
	lsrs r0, r0, #2
	subs r0, r4, r0
	cmp r1, r0
	bge _0806BD24
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r2, [r0]
	cmp r2, #4
	bls _0806BD0C
	movs r0, #8
	subs r0, r0, r2
	ldr r2, _0806BD04 @ =0x000002E6
	adds r1, r5, r2
	strb r0, [r1]
	ldr r0, _0806BD08 @ =0x000002E7
	adds r1, r5, r0
	movs r0, #1
	b _0806BD8A
	.align 2, 0
_0806BCFC: .4byte 0x0000039A
_0806BD00: .4byte 0x0000037E
_0806BD04: .4byte 0x000002E6
_0806BD08: .4byte 0x000002E7
_0806BD0C:
	ldr r1, _0806BD1C @ =0x000002E6
	adds r0, r5, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _0806BD20 @ =0x000002E7
	adds r0, r5, r2
	strb r1, [r0]
	b _0806BD8C
	.align 2, 0
_0806BD1C: .4byte 0x000002E6
_0806BD20: .4byte 0x000002E7
_0806BD24:
	adds r0, r5, #0
	movs r1, #0x41
	bl FUN_08060c40
	movs r0, #0x82
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x83
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r0, _0806BD70 @ =0x00000382
	adds r1, r5, r0
	ldrh r0, [r2]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r2]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r2, r5, r1
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #3
	bls _0806BD7C
	ldrb r0, [r2]
	subs r0, r4, r0
	asrs r0, r0, #1
	ldr r2, _0806BD74 @ =0x000002E6
	adds r1, r5, r2
	strb r0, [r1]
	ldr r0, _0806BD78 @ =0x000002E7
	adds r1, r5, r0
	movs r0, #1
	b _0806BD8A
	.align 2, 0
_0806BD70: .4byte 0x00000382
_0806BD74: .4byte 0x000002E6
_0806BD78: .4byte 0x000002E7
_0806BD7C:
	lsrs r1, r1, #0x19
	ldr r2, _0806BE1C @ =0x000002E6
	adds r0, r5, r2
	strb r1, [r0]
	ldr r0, _0806BE20 @ =0x000002E7
	adds r1, r5, r0
	movs r0, #0
_0806BD8A:
	strb r0, [r1]
_0806BD8C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _0806BE24 @ =0x0000095E
	adds r1, r5, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _0806BDC6
	movs r0, #0x20
	strh r0, [r1]
_0806BDC6:
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r4, r5, r1
	movs r2, #0xd3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r1, [r0]
	subs r2, #0x66
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r6, r5, #0
	adds r6, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806BE28
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _0806BE30
	.align 2, 0
_0806BE1C: .4byte 0x000002E6
_0806BE20: .4byte 0x000002E7
_0806BE24: .4byte 0x0000095E
_0806BE28:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806BE30:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806BE54
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0806BE5C
_0806BE54:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806BE5C:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806BE94 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806BECC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806BE98
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806BE8C
	ldrb r0, [r4, #5]
_0806BE8C:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806BEA8
	.align 2, 0
_0806BE94: .4byte 0x0000FFFF
_0806BE98:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806BEA8
	strh r1, [r4, #8]
_0806BEA8:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806BECC
	movs r0, #1
	strb r0, [r4, #7]
_0806BECC:
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r1, _0806BF10 @ =0x0000026D
	bl FUN_0822b20c
	ldr r2, _0806BF14 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _0806BF08
	movs r0, #0xe0
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	adds r2, #3
	adds r1, r5, r2
	movs r0, #2
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806BF08:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806BF10: .4byte 0x0000026D
_0806BF14: .4byte 0x0000037E

	thumb_func_start FUN_0806bf18
FUN_0806bf18: @ 0x0806BF18
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0xd
	beq _0806BF60
	adds r0, r6, #0
	movs r1, #0xd
	movs r2, #0
	bl FUN_08060b84
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r6, r2
	movs r0, #0
	strh r0, [r1]
	adds r0, r6, #0
	bl FUN_08063220
	adds r0, r6, #0
	bl FUN_08066e84
	ldr r0, _0806C024 @ =0x0000039A
	bl PlaySound_082406e0
	movs r0, #0x38
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0
	movs r3, #0x20
	bl FUN_080ac374
_0806BF60:
	ldr r0, _0806C028 @ =0x0000037E
	adds r4, r6, r0
	ldrh r0, [r4]
	cmp r0, #0x10
	bne _0806BF70
	ldr r0, _0806C02C @ =0x000003A1
	bl PlaySound_082406e0
_0806BF70:
	ldrh r0, [r4]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #2
	subs r1, r1, r0
	cmp r2, r1
	blt _0806BF96
	adds r0, r6, #0
	movs r1, #0x41
	bl FUN_08060c40
	movs r1, #0x82
	lsls r1, r1, #1
	adds r2, r6, r1
	ldr r0, [r6, #0x2c]
	ldr r1, [r6, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
_0806BF96:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r6, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _0806C030 @ =0x0000095E
	adds r1, r6, r0
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _0806BFD0
	movs r0, #0x20
	strh r0, [r1]
_0806BFD0:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _0806C034 @ =0x000002E6
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806C038
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806C040
	.align 2, 0
_0806C024: .4byte 0x0000039A
_0806C028: .4byte 0x0000037E
_0806C02C: .4byte 0x000003A1
_0806C030: .4byte 0x0000095E
_0806C034: .4byte 0x000002E6
_0806C038:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806C040:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806C064
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806C06C
_0806C064:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806C06C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806C0A4 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806C0DC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806C0A8
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806C09C
	ldrb r0, [r4, #5]
_0806C09C:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806C0B8
	.align 2, 0
_0806C0A4: .4byte 0x0000FFFF
_0806C0A8:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806C0B8
	strh r1, [r4, #8]
_0806C0B8:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806C0DC
	movs r0, #1
	strb r0, [r4, #7]
_0806C0DC:
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	adds r1, #0xe
	bl FUN_0822b20c
	ldr r2, _0806C120 @ =0x0000037E
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _0806C118
	movs r0, #0xe0
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	adds r2, #3
	adds r1, r6, r2
	movs r0, #3
	strb r0, [r1]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806C118:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806C120: .4byte 0x0000037E

	thumb_func_start FUN_0806c124
FUN_0806c124: @ 0x0806C124
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0xe
	beq _0806C156
	bl GetPlayerCoffinID
	ldr r2, _0806C1D8 @ =0x00000387
	adds r1, r6, r2
	strb r0, [r1]
	adds r0, r6, #0
	bl FUN_08063220
	adds r0, r6, #0
	bl FUN_08066e84
	adds r0, r6, #0
	movs r1, #0xe
	movs r2, #0
	bl FUN_08060b84
_0806C156:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r6, #0
	movs r2, #0x40
	bl FUN_08060a24
	adds r0, r6, #0
	movs r1, #0x40
	bl FUN_08060c40
	movs r0, #0x82
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r0, [r6, #0x2c]
	ldr r1, [r6, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r4, r6, r1
	movs r2, #0xd5
	lsls r2, r2, #2
	adds r0, r6, r2
	ldr r1, [r0]
	adds r2, #0x33
	adds r0, r6, r2
	ldrb r2, [r0]
	adds r2, #0x18
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806C1DC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806C1E4
	.align 2, 0
_0806C1D8: .4byte 0x00000387
_0806C1DC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806C1E4:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806C208
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806C210
_0806C208:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806C210:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806C248 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806C280
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806C24C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806C240
	ldrb r0, [r4, #5]
_0806C240:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806C25C
	.align 2, 0
_0806C248: .4byte 0x0000FFFF
_0806C24C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806C25C
	strh r1, [r4, #8]
_0806C25C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806C280
	movs r0, #1
	strb r0, [r4, #7]
_0806C280:
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	ldr r2, _0806C2CC @ =0x00000387
	adds r1, r6, r2
	ldrb r1, [r1]
	ldr r2, _0806C2D0 @ =0x00000207
	adds r1, r1, r2
	bl FUN_0822b20c
	ldr r0, _0806C2D4 @ =0x0000037E
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _0806C2C4
	movs r2, #0xe0
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0806C2D8 @ =0x00000381
	adds r1, r6, r0
	movs r0, #4
	strb r0, [r1]
	adds r0, r6, #0
	movs r1, #4
	movs r2, #0
	bl FUN_08060b84
_0806C2C4:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806C2CC: .4byte 0x00000387
_0806C2D0: .4byte 0x00000207
_0806C2D4: .4byte 0x0000037E
_0806C2D8: .4byte 0x00000381

	thumb_func_start FUN_0806c2dc
FUN_0806c2dc: @ 0x0806C2DC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806C2F8
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806C2F8:
	ldr r0, [r5, #0x20]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x20]
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r4, r5, r2
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	subs r2, #0x56
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806C354
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806C35C
_0806C354:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806C35C:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806C380
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806C388
_0806C380:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806C388:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806C3C0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806C3F8
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806C3C4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806C3B8
	ldrb r0, [r4, #5]
_0806C3B8:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806C3D4
	.align 2, 0
_0806C3C0: .4byte 0x0000FFFF
_0806C3C4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806C3D4
	strh r1, [r4, #8]
_0806C3D4:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806C3F8
	movs r0, #1
	strb r0, [r4, #7]
_0806C3F8:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0806c400
FUN_0806c400: @ 0x0806C400
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _0806C424
	adds r0, r5, #0
	movs r1, #1
	movs r2, #0
	bl FUN_08060b84
	ldr r2, _0806C464 @ =0x00000385
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
_0806C424:
	ldr r0, [r5, #0x20]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x20]
	ldr r3, _0806C464 @ =0x00000385
	adds r4, r5, r3
	ldrb r0, [r4]
	adds r6, r0, #0
	cmp r6, #0
	beq _0806C43C
	b _0806C5CC
_0806C43C:
	adds r0, r5, #0
	bl FUN_08067068
	adds r3, r0, #0
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	beq _0806C500
	cmp r3, #4
	ble _0806C470
	movs r0, #8
	subs r0, r0, r3
	asrs r0, r0, #1
	ldr r4, _0806C468 @ =0x000002E6
	adds r1, r5, r4
	strb r0, [r1]
	ldr r1, _0806C46C @ =0x000002E7
	adds r0, r5, r1
	strb r2, [r0]
	b _0806C47E
	.align 2, 0
_0806C464: .4byte 0x00000385
_0806C468: .4byte 0x000002E6
_0806C46C: .4byte 0x000002E7
_0806C470:
	asrs r0, r3, #1
	ldr r2, _0806C4AC @ =0x000002E6
	adds r1, r5, r2
	strb r0, [r1]
	ldr r4, _0806C4B0 @ =0x000002E7
	adds r0, r5, r4
	strb r6, [r0]
_0806C47E:
	ldr r2, _0806C4B4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0806C4B8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0806C4BC @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	cmp r1, #5
	bgt _0806C4C4
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r5, r2
	strb r3, [r0]
	ldr r3, _0806C4C0 @ =0x00000385
	adds r1, r5, r3
	movs r0, #9
	strb r0, [r1]
	b _0806C5D0
	.align 2, 0
_0806C4AC: .4byte 0x000002E6
_0806C4B0: .4byte 0x000002E7
_0806C4B4: .4byte 0x030046B8
_0806C4B8: .4byte 0x000003FF
_0806C4BC: .4byte 0x0203B400
_0806C4C0: .4byte 0x00000385
_0806C4C4:
	cmp r1, #6
	bgt _0806C4E0
	adds r0, r3, #7
	movs r1, #7
	ands r0, r1
	movs r4, #0xba
	lsls r4, r4, #2
	adds r1, r5, r4
	strb r0, [r1]
	ldr r0, _0806C4DC @ =0x00000385
	adds r1, r5, r0
	b _0806C4F4
	.align 2, 0
_0806C4DC: .4byte 0x00000385
_0806C4E0:
	adds r0, r3, #0
	adds r0, #9
	movs r1, #7
	ands r0, r1
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r5, r2
	strb r0, [r1]
	ldr r3, _0806C4FC @ =0x00000385
	adds r1, r5, r3
_0806C4F4:
	movs r0, #3
	strb r0, [r1]
	b _0806C5D0
	.align 2, 0
_0806C4FC: .4byte 0x00000385
_0806C500:
	ldr r2, _0806C528 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0806C52C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0806C530 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	cmp r1, #5
	bgt _0806C534
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r3, [r0]
	movs r0, #9
	b _0806C54E
	.align 2, 0
_0806C528: .4byte 0x030046B8
_0806C52C: .4byte 0x000003FF
_0806C530: .4byte 0x0203B400
_0806C534:
	cmp r1, #6
	bgt _0806C53C
	adds r0, r3, #7
	b _0806C540
_0806C53C:
	adds r0, r3, #0
	adds r0, #9
_0806C540:
	movs r1, #7
	ands r0, r1
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r5, r3
	strb r0, [r1]
	movs r0, #3
_0806C54E:
	strb r0, [r4]
	movs r4, #0xba
	lsls r4, r4, #2
	adds r3, r5, r4
	ldrb r1, [r3]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _0806C58C
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0806C584 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0806C588 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrb r1, [r3]
	ands r0, r4
	lsls r0, r0, #1
	adds r0, #7
	adds r3, r1, r0
	movs r0, #7
	ands r3, r0
	b _0806C58E
	.align 2, 0
_0806C584: .4byte 0x000003FF
_0806C588: .4byte 0x0203B400
_0806C58C:
	ldrb r3, [r3]
_0806C58E:
	cmp r3, #4
	ble _0806C5B0
	movs r0, #8
	subs r0, r0, r3
	asrs r0, r0, #1
	ldr r2, _0806C5A8 @ =0x000002E6
	adds r1, r5, r2
	strb r0, [r1]
	ldr r3, _0806C5AC @ =0x000002E7
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _0806C5D0
	.align 2, 0
_0806C5A8: .4byte 0x000002E6
_0806C5AC: .4byte 0x000002E7
_0806C5B0:
	asrs r1, r3, #1
	ldr r4, _0806C5C4 @ =0x000002E6
	adds r0, r5, r4
	movs r2, #0
	strb r1, [r0]
	ldr r1, _0806C5C8 @ =0x000002E7
	adds r0, r5, r1
	strb r2, [r0]
	b _0806C5D0
	.align 2, 0
_0806C5C4: .4byte 0x000002E6
_0806C5C8: .4byte 0x000002E7
_0806C5CC:
	subs r0, #1
	strb r0, [r4]
_0806C5D0:
	adds r0, r5, #0
	movs r1, #9
	bl FUN_08060aa4
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r4, r5, r2
	movs r3, #0xd3
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r1, [r0]
	subs r2, #0x56
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806C62A
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806C632
_0806C62A:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806C632:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806C656
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806C65E
_0806C656:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806C65E:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _0806C694 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806C6CC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806C698
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806C68E
	ldrb r0, [r4, #5]
_0806C68E:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806C6A8
	.align 2, 0
_0806C694: .4byte 0x0000FFFF
_0806C698:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806C6A8
	strh r1, [r4, #8]
_0806C6A8:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806C6CC
	movs r0, #1
	strb r0, [r4, #7]
_0806C6CC:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0806c6d4
FUN_0806c6d4: @ 0x0806C6D4
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0x14
	beq _0806C6F0
	adds r0, r6, #0
	movs r1, #0x14
	movs r2, #0
	bl FUN_08060b84
_0806C6F0:
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrh r1, [r0]
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _0806C744
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r0, #0xfe
	ands r0, r1
	adds r0, #1
	strb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0806C734
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _0806C72C @ =0x000002E6
	adds r1, r6, r2
	strb r0, [r1]
	ldr r0, _0806C730 @ =0x000002E7
	adds r1, r6, r0
	movs r0, #1
	b _0806C742
	.align 2, 0
_0806C72C: .4byte 0x000002E6
_0806C730: .4byte 0x000002E7
_0806C734:
	lsrs r1, r1, #0x19
	ldr r2, _0806C798 @ =0x000002E6
	adds r0, r6, r2
	strb r1, [r0]
	ldr r0, _0806C79C @ =0x000002E7
	adds r1, r6, r0
	movs r0, #0
_0806C742:
	strb r0, [r1]
_0806C744:
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r4, r6, r1
	movs r2, #0xd3
	lsls r2, r2, #2
	adds r0, r6, r2
	ldr r1, [r0]
	subs r2, #0x66
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806C7A0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806C7A8
	.align 2, 0
_0806C798: .4byte 0x000002E6
_0806C79C: .4byte 0x000002E7
_0806C7A0:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806C7A8:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806C7CC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806C7D4
_0806C7CC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806C7D4:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806C80C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806C844
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806C810
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806C804
	ldrb r0, [r4, #5]
_0806C804:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806C820
	.align 2, 0
_0806C80C: .4byte 0x0000FFFF
_0806C810:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806C820
	strh r1, [r4, #8]
_0806C820:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806C844
	movs r0, #1
	strb r0, [r4, #7]
_0806C844:
	ldr r1, _0806C864 @ =0x000003FF
	adds r0, r6, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _0806C85C
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806C85C:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806C864: .4byte 0x000003FF

	thumb_func_start FUN_0806c868
FUN_0806c868: @ 0x0806C868
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0x13
	beq _0806C884
	adds r0, r7, #0
	movs r1, #0x13
	movs r2, #0
	bl FUN_08060b84
_0806C884:
	ldr r0, _0806C894 @ =0x00000382
	adds r2, r7, r0
	ldrb r0, [r2]
	cmp r0, #0x3b
	bls _0806C898
	subs r0, #0x3c
	b _0806C8A4
	.align 2, 0
_0806C894: .4byte 0x00000382
_0806C898:
	ldr r0, [r7, #0x20]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #0x20]
	movs r0, #0
_0806C8A4:
	strb r0, [r2]
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r4, r7, r1
	movs r2, #0xd3
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r1, [r0]
	subs r2, #0x66
	adds r0, r7, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r7, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_08236fac
	adds r5, r7, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806C8FA
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806C902
_0806C8FA:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806C902:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806C926
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806C92E
_0806C926:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806C92E:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806C964 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806C99C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806C968
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806C95E
	ldrb r0, [r4, #5]
_0806C95E:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806C978
	.align 2, 0
_0806C964: .4byte 0x0000FFFF
_0806C968:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806C978
	strh r1, [r4, #8]
_0806C978:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806C99C
	movs r0, #1
	strb r0, [r4, #7]
_0806C99C:
	ldr r1, _0806C9B8 @ =0x000004C7
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0806C9B0
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806C9B0:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806C9B8: .4byte 0x000004C7

	thumb_func_start FUN_0806c9bc
FUN_0806c9bc: @ 0x0806C9BC
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0x18
	beq _0806CA28
	movs r5, #0xba
	lsls r5, r5, #2
	adds r2, r6, r5
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0806C9FC
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _0806C9F8 @ =0x000002E6
	adds r1, r6, r2
	strb r0, [r1]
	subs r5, #1
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _0806CA0C
	.align 2, 0
_0806C9F8: .4byte 0x000002E6
_0806C9FC:
	lsrs r1, r1, #0x19
	ldr r2, _0806CA7C @ =0x000002E6
	adds r0, r6, r2
	movs r2, #0
	strb r1, [r0]
	ldr r5, _0806CA80 @ =0x000002E7
	adds r0, r6, r5
	strb r2, [r0]
_0806CA0C:
	ldr r0, _0806CA84 @ =0x000003D6
	adds r4, r6, r0
	ldrh r0, [r4]
	cmp r0, #0
	beq _0806CA1E
	bl PlaySound_082406e0
	movs r0, #0
	strh r0, [r4]
_0806CA1E:
	adds r0, r6, #0
	movs r1, #0x18
	movs r2, #0
	bl FUN_08060b84
_0806CA28:
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r4, r6, r1
	movs r2, #0xd3
	lsls r2, r2, #2
	adds r0, r6, r2
	ldr r1, [r0]
	ldr r5, _0806CA7C @ =0x000002E6
	adds r0, r6, r5
	ldrb r3, [r0]
	subs r2, #0x65
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806CA88
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806CA90
	.align 2, 0
_0806CA7C: .4byte 0x000002E6
_0806CA80: .4byte 0x000002E7
_0806CA84: .4byte 0x000003D6
_0806CA88:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806CA90:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806CAB4
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806CABC
_0806CAB4:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806CABC:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r5, _0806CAF4 @ =0x0000FFFF
	adds r2, r5, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806CB2C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806CAF8
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806CAEC
	ldrb r0, [r4, #5]
_0806CAEC:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806CB08
	.align 2, 0
_0806CAF4: .4byte 0x0000FFFF
_0806CAF8:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806CB08
	strh r1, [r4, #8]
_0806CB08:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806CB2C
	movs r0, #1
	strb r0, [r4, #7]
_0806CB2C:
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r3, r6, r5
	ldrh r0, [r3]
	cmp r0, #0
	beq _0806CBAC
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldr r2, _0806CB68 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	ldrh r0, [r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806CB6C
	asrs r0, r0, #0xc
	b _0806CB72
	.align 2, 0
_0806CB68: .4byte 0x085B0A08
_0806CB6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806CB72:
	rsbs r0, r0, #0
	strh r0, [r6, #0x34]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r6, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806CB90
	asrs r0, r0, #0xc
	b _0806CB96
_0806CB90:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806CB96:
	rsbs r0, r0, #0
	strh r0, [r6, #0x38]
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r2, r6, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	b _0806CBDE
_0806CBAC:
	ldr r1, _0806CBCC @ =0x000004C5
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #3
	bne _0806CBD4
	ldr r2, _0806CBD0 @ =0x000004C7
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806CBD4
	adds r0, r6, #0
	movs r1, #0x13
	movs r2, #0
	bl FUN_08060b84
	b _0806CBDE
	.align 2, 0
_0806CBCC: .4byte 0x000004C5
_0806CBD0: .4byte 0x000004C7
_0806CBD4:
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806CBDE:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806CBE8:
	.byte 0xF0, 0xB5, 0x81, 0xB0, 0x05, 0x1C, 0xDF, 0x21
	.byte 0x89, 0x00, 0x68, 0x18, 0x00, 0x78, 0x0C, 0x28, 0x04, 0xD1, 0x0D, 0x4A, 0xA8, 0x18, 0x00, 0x88
	.byte 0x00, 0x28, 0x3A, 0xD1, 0x28, 0x1C, 0x0C, 0x21, 0x00, 0x22, 0xF3, 0xF7, 0xBB, 0xFF, 0x09, 0x4B
	.byte 0xE8, 0x18, 0x00, 0x78, 0x00, 0x28, 0x11, 0xD0, 0x07, 0x49, 0x68, 0x18, 0x00, 0x78, 0x40, 0x00
	.byte 0x07, 0x21, 0x09, 0x1A, 0xBA, 0x22, 0x92, 0x00, 0xA8, 0x18, 0x01, 0x70, 0x0F, 0xE0, 0x00, 0x00
	.byte 0x7E, 0x03, 0x00, 0x00, 0xE7, 0x02, 0x00, 0x00, 0xE6, 0x02, 0x00, 0x00, 0x1A, 0x4B, 0xE8, 0x18
	.byte 0x00, 0x78, 0x40, 0x00, 0x01, 0x30, 0xBA, 0x22, 0x92, 0x00, 0xA9, 0x18, 0x08, 0x70, 0x96, 0x23
	.byte 0x1B, 0x01, 0xE9, 0x18, 0x00, 0x20, 0x08, 0x80, 0x28, 0x1C, 0xF6, 0xF7, 0xE1, 0xFA, 0x28, 0x1C
	.byte 0xFA, 0xF7, 0x10, 0xF9, 0x11, 0x48, 0xD3, 0xF1, 0x3B, 0xFD, 0x38, 0x20, 0x00, 0x90, 0x28, 0x1C
	.byte 0x01, 0x21, 0x00, 0x22, 0x20, 0x23, 0x3F, 0xF0, 0x7D, 0xFB, 0x0D, 0x49, 0x68, 0x18, 0x00, 0x88
	.byte 0x07, 0x23, 0x19, 0x1C, 0x01, 0x40, 0x80, 0x08, 0x18, 0x1A, 0x81, 0x42, 0x20, 0xDA, 0xBA, 0x20
	.byte 0x80, 0x00, 0x2A, 0x18, 0x10, 0x78, 0x01, 0x06, 0x08, 0x0E, 0x03, 0x28, 0x0A, 0xD9, 0x10, 0x78
	.byte 0x18, 0x1A, 0x40, 0x10, 0x26, 0xE0, 0x00, 0x00, 0xE6, 0x02, 0x00, 0x00, 0x9A, 0x03, 0x00, 0x00
	.byte 0x7E, 0x03, 0x00, 0x00, 0x49, 0x0E, 0x04, 0x4A, 0xA8, 0x18, 0x00, 0x22, 0x01, 0x70, 0x03, 0x4B
	.byte 0xE8, 0x18, 0x02, 0x70, 0x29, 0xE0, 0x00, 0x00, 0xE6, 0x02, 0x00, 0x00, 0xE7, 0x02, 0x00, 0x00
	.byte 0x28, 0x1C, 0x41, 0x21, 0xF3, 0xF7, 0xB4, 0xFF, 0x28, 0x1C, 0xA8, 0x30, 0xE9, 0x6A, 0x2A, 0x6B
	.byte 0x01, 0x60, 0x42, 0x60, 0xBA, 0x21, 0x89, 0x00, 0x68, 0x18, 0x02, 0x78, 0x04, 0x2A, 0x0D, 0xD9
	.byte 0x08, 0x20, 0x80, 0x1A, 0x03, 0x4A, 0xA9, 0x18, 0x08, 0x70, 0x03, 0x4B, 0xE9, 0x18, 0x01, 0x20
	.byte 0x08, 0x70, 0x0A, 0xE0, 0xE6, 0x02, 0x00, 0x00, 0xE7, 0x02, 0x00, 0x00, 0x20, 0x49, 0x68, 0x18
	.byte 0x00, 0x21, 0x02, 0x70, 0x1F, 0x4A, 0xA8, 0x18, 0x01, 0x70, 0x28, 0x1C, 0xC7, 0x21, 0x40, 0x22
	.byte 0xF3, 0xF7, 0x80, 0xFE, 0x28, 0x1C, 0xC2, 0x30, 0x91, 0x21, 0x49, 0x00, 0x01, 0x80, 0x2A, 0x1C
	.byte 0xD0, 0x32, 0x19, 0x48, 0x49, 0x01, 0x00, 0x68, 0x40, 0x18, 0x10, 0x60, 0xCF, 0x23, 0x9B, 0x00
	.byte 0xEC, 0x18, 0xD3, 0x21, 0x89, 0x00, 0x68, 0x18, 0x01, 0x68, 0x11, 0x4A, 0xA8, 0x18, 0x03, 0x78
	.byte 0x01, 0x32, 0xA8, 0x18, 0x00, 0x78, 0x00, 0x90, 0x20, 0x1C, 0x00, 0x22, 0xCA, 0xF1, 0x26, 0xF9
	.byte 0x2E, 0x1C, 0xE8, 0x36, 0x20, 0x89, 0x40, 0x00, 0x21, 0x68, 0x0F, 0x18, 0x38, 0x88, 0x80, 0x09
	.byte 0x30, 0x82, 0x20, 0x79, 0x01, 0x23, 0x19, 0x1C, 0x01, 0x40, 0x3A, 0x88, 0x30, 0x20, 0x10, 0x40
	.byte 0x00, 0x09, 0x18, 0x40, 0x81, 0x42, 0x09, 0xD0, 0x30, 0x68, 0x04, 0x21, 0x08, 0x43, 0x09, 0xE0
	.byte 0xE6, 0x02, 0x00, 0x00, 0xE7, 0x02, 0x00, 0x00, 0x84, 0x35, 0x00, 0x03, 0x30, 0x68, 0x05, 0x21
	.byte 0x49, 0x42, 0x08, 0x40, 0x30, 0x60, 0x20, 0x79, 0x02, 0x23, 0x19, 0x1C, 0x01, 0x40, 0x09, 0x06
	.byte 0x09, 0x0E, 0x3A, 0x88, 0x30, 0x20, 0x10, 0x40, 0x00, 0x09, 0x18, 0x40, 0x81, 0x42, 0x03, 0xD0
	.byte 0x30, 0x68, 0x08, 0x21, 0x08, 0x43, 0x03, 0xE0, 0x30, 0x68, 0x09, 0x21, 0x49, 0x42, 0x08, 0x40
	.byte 0x30, 0x60, 0xE0, 0x89, 0x01, 0x30, 0xE0, 0x81, 0x0B, 0x4B, 0x1A, 0x1C, 0x00, 0x04, 0x00, 0x0C
	.byte 0xE1, 0x79, 0x88, 0x42, 0x2C, 0xD3, 0x00, 0x20, 0xE0, 0x81, 0x21, 0x79, 0x04, 0x20, 0x08, 0x40
	.byte 0x00, 0x06, 0x01, 0x0E, 0x00, 0x29, 0x09, 0xD0, 0x20, 0x89, 0x00, 0x28, 0x00, 0xD1, 0x60, 0x79
	.byte 0x01, 0x38, 0x20, 0x81, 0x0A, 0xE0, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x20, 0x89, 0x01, 0x30
	.byte 0x20, 0x81, 0x10, 0x40, 0x62, 0x79, 0x90, 0x42, 0x00, 0xD3, 0x21, 0x81, 0x20, 0x89, 0x40, 0x00
	.byte 0x21, 0x68, 0x0F, 0x18, 0x39, 0x88, 0x0F, 0x20, 0x08, 0x40, 0xA0, 0x71, 0xA1, 0x79, 0xA0, 0x89
	.byte 0x48, 0x43, 0x80, 0x11, 0xE0, 0x71, 0x00, 0x06, 0x00, 0x28, 0x01, 0xD1, 0x01, 0x20, 0xE0, 0x71
	.byte 0x16, 0x4B, 0xE9, 0x18, 0x16, 0x48, 0x08, 0x80, 0x96, 0x20, 0x00, 0x01, 0x29, 0x18, 0x08, 0x88
	.byte 0x03, 0x30, 0x08, 0x80, 0x13, 0x4B, 0x1A, 0x1C, 0x00, 0x04, 0x00, 0x0C, 0x20, 0x28, 0x01, 0xD9
	.byte 0x20, 0x20, 0x08, 0x80, 0x10, 0x48, 0x29, 0x18, 0x08, 0x88, 0x01, 0x30, 0x08, 0x80, 0x10, 0x40
	.byte 0x1F, 0x28, 0x0F, 0xD9, 0xE0, 0x21, 0x89, 0x00, 0x68, 0x18, 0x01, 0x21, 0x01, 0x70, 0x0B, 0x4A
	.byte 0xA8, 0x18, 0x01, 0x70, 0x28, 0x1C, 0xF3, 0xF7, 0xA9, 0xFD, 0x28, 0x1C, 0x00, 0x21, 0x00, 0x22
	.byte 0xF3, 0xF7, 0x78, 0xFE, 0x01, 0xB0, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x5E, 0x09, 0x00, 0x00
	.byte 0x6D, 0x02, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x7E, 0x03, 0x00, 0x00, 0x81, 0x03, 0x00, 0x00

	thumb_func_start FUN_0806ceb0
FUN_0806ceb0: @ 0x0806CEB0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, [r5, #0x20]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x20]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806CED6
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806CED6:
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r4, r5, r2
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	subs r2, #0x56
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806CF28
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806CF30
_0806CF28:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806CF30:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806CF54
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806CF5C
_0806CF54:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806CF5C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806CF94 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806CFCC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806CF98
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806CF8C
	ldrb r0, [r4, #5]
_0806CF8C:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806CFA8
	.align 2, 0
_0806CF94: .4byte 0x0000FFFF
_0806CF98:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806CFA8
	strh r1, [r4, #8]
_0806CFA8:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806CFCC
	movs r0, #1
	strb r0, [r4, #7]
_0806CFCC:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0806cfd4
FUN_0806cfd4: @ 0x0806CFD4
	push {lr}
	adds r1, r0, #0
	movs r2, #0xc
	ldr r3, _0806D004 @ =0x000004C5
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #2
	bne _0806CFF0
	adds r3, #2
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806CFF0
	movs r2, #8
_0806CFF0:
	ldr r0, _0806D008 @ =0x00000402
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0806CFFC
	subs r2, r2, r0
_0806CFFC:
	cmp r2, #1
	ble _0806D00C
	adds r0, r2, #0
	b _0806D00E
	.align 2, 0
_0806D004: .4byte 0x000004C5
_0806D008: .4byte 0x00000402
_0806D00C:
	movs r0, #2
_0806D00E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0806d014
FUN_0806d014: @ 0x0806D014
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r6, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _0806D038
	ldr r2, _0806D0B8 @ =0x00000386
	adds r1, r6, r2
	movs r0, #0
	strb r0, [r1]
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0
	bl FUN_08060b84
_0806D038:
	ldr r0, [r6, #0x20]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x20]
	adds r0, r6, #0
	bl FUN_08067068
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r6, r2
	strb r0, [r1]
	adds r0, r6, #0
	bl FUN_0806cfd4
	adds r1, r0, #0
	adds r0, r6, #0
	bl FUN_08060aa4
	adds r0, r6, #0
	bl FUN_080609dc
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _0806D0BC @ =0x000002E6
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806D0C0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806D0C8
	.align 2, 0
_0806D0B8: .4byte 0x00000386
_0806D0BC: .4byte 0x000002E6
_0806D0C0:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806D0C8:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806D0EC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806D0F4
_0806D0EC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806D0F4:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806D12C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806D164
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806D130
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806D124
	ldrb r0, [r4, #5]
_0806D124:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806D140
	.align 2, 0
_0806D12C: .4byte 0x0000FFFF
_0806D130:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806D140
	strh r1, [r4, #8]
_0806D140:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806D164
	movs r0, #1
	strb r0, [r4, #7]
_0806D164:
	movs r1, #0xd1
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #2
	bne _0806D222
	ldr r2, _0806D1A0 @ =0x0000034A
	adds r0, r6, r2
	ldrh r5, [r0]
	cmp r5, #0
	bne _0806D222
	adds r4, r6, #0
	adds r4, #0x2c
	adds r0, r4, #0
	bl FUN_0809f658
	adds r2, r0, #0
	cmp r2, #0
	beq _0806D1C8
	ldr r0, _0806D1A4 @ =0x00000386
	adds r1, r6, r0
	ldrb r2, [r1]
	cmp r2, #0
	beq _0806D1AC
	strb r5, [r1]
	str r4, [sp]
	str r5, [sp, #4]
	ldr r0, _0806D1A8 @ =0x00000163
	b _0806D1B8
	.align 2, 0
_0806D1A0: .4byte 0x0000034A
_0806D1A4: .4byte 0x00000386
_0806D1A8: .4byte 0x00000163
_0806D1AC:
	movs r0, #1
	strb r0, [r1]
	str r4, [sp]
	str r2, [sp, #4]
	movs r0, #0xb1
	lsls r0, r0, #1
_0806D1B8:
	str r0, [sp, #8]
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #1
	movs r3, #1
	bl FUN_08066e9c
	b _0806D222
_0806D1C8:
	ldr r0, _0806D1DC @ =0x00000386
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0806D1E0
	strb r2, [r1]
	movs r0, #0xc7
	bl PlaySound_082406e0
	b _0806D1EA
	.align 2, 0
_0806D1DC: .4byte 0x00000386
_0806D1E0:
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xc8
	bl PlaySound_082406e0
_0806D1EA:
	movs r1, #1
	ldr r0, _0806D200 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _0806D204 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0806D208
	movs r0, #1
	b _0806D20A
	.align 2, 0
_0806D200: .4byte 0x030046A0
_0806D204: .4byte 0x00000934
_0806D208:
	movs r0, #0
_0806D20A:
	cmp r0, #0
	beq _0806D222
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #1
	movs r3, #2
	bl FUN_08066e9c
_0806D222:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0806d22c
FUN_0806d22c: @ 0x0806D22C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r7, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #4
	beq _0806D2F6
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _0806D274 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #6
	adds r4, r2, #0
	cmp r0, #0
	blt _0806D278
	asrs r1, r0, #0xc
	b _0806D27E
	.align 2, 0
_0806D274: .4byte 0x085B0A08
_0806D278:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0806D27E:
	add r0, sp, #0xc
	ldrh r0, [r0]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0806D2B0 @ =0xFFFF0000
	ldr r2, [sp, #0xc]
	ands r2, r1
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0x40
	lsls r1, r1, #0x10
	ldr r0, _0806D2B4 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	lsls r0, r3, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #6
	cmp r0, #0
	blt _0806D2B8
	asrs r2, r0, #0xc
	b _0806D2BE
	.align 2, 0
_0806D2B0: .4byte 0xFFFF0000
_0806D2B4: .4byte 0x0000FFFF
_0806D2B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0806D2BE:
	add r0, sp, #0xc
	ldrh r1, [r0, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0806D34C @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r0, r7, #0
	movs r1, #4
	movs r2, #0
	bl FUN_08060b84
	adds r1, r7, #0
	adds r1, #0x2c
	add r0, sp, #0xc
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	ldr r0, _0806D350 @ =0x000003A1
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r2, #1
	movs r3, #1
	bl FUN_08066e9c
_0806D2F6:
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r4, r7, r1
	movs r2, #0xd4
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r1, [r0]
	subs r2, #0x6a
	adds r0, r7, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r7, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r5, r7, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806D354
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806D35C
	.align 2, 0
_0806D34C: .4byte 0xFFFF0000
_0806D350: .4byte 0x000003A1
_0806D354:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806D35C:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806D380
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806D388
_0806D380:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806D388:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806D3C0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806D3F8
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806D3C4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806D3B8
	ldrb r0, [r4, #5]
_0806D3B8:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806D3D4
	.align 2, 0
_0806D3C0: .4byte 0x0000FFFF
_0806D3C4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806D3D4
	strh r1, [r4, #8]
_0806D3D4:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806D3F8
	movs r0, #1
	strb r0, [r4, #7]
_0806D3F8:
	ldr r0, _0806D41C @ =0x0000037E
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0806D414
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806D414:
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806D41C: .4byte 0x0000037E

	thumb_func_start FUN_0806d420
FUN_0806d420: @ 0x0806D420
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0x13
	beq _0806D47C
	adds r0, r6, #0
	movs r1, #0x13
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r6, r0
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0806D46C
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _0806D464 @ =0x000002E6
	adds r1, r6, r2
	strb r0, [r1]
	ldr r0, _0806D468 @ =0x000002E7
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	b _0806D47C
	.align 2, 0
_0806D464: .4byte 0x000002E6
_0806D468: .4byte 0x000002E7
_0806D46C:
	lsrs r1, r1, #0x19
	ldr r2, _0806D4DC @ =0x000002E6
	adds r0, r6, r2
	movs r2, #0
	strb r1, [r0]
	ldr r1, _0806D4E0 @ =0x000002E7
	adds r0, r6, r1
	strb r2, [r0]
_0806D47C:
	ldr r0, [r6, #0x20]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x20]
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r4, r6, r2
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	subs r2, #0x56
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806D4E4
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806D4EC
	.align 2, 0
_0806D4DC: .4byte 0x000002E6
_0806D4E0: .4byte 0x000002E7
_0806D4E4:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806D4EC:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806D510
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806D518
_0806D510:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806D518:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806D550 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806D588
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806D554
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806D548
	ldrb r0, [r4, #5]
_0806D548:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806D564
	.align 2, 0
_0806D550: .4byte 0x0000FFFF
_0806D554:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806D564
	strh r1, [r4, #8]
_0806D564:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806D588
	movs r0, #1
	strb r0, [r4, #7]
_0806D588:
	ldr r1, _0806D5AC @ =0x000004C7
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0806D5A2
	adds r0, r6, #0
	bl FUN_080609dc
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806D5A2:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806D5AC: .4byte 0x000004C7

	thumb_func_start FUN_0806d5b0
FUN_0806d5b0: @ 0x0806D5B0
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0x14
	beq _0806D5CC
	adds r0, r6, #0
	movs r1, #0x14
	movs r2, #0
	bl FUN_08060b84
_0806D5CC:
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrh r1, [r0]
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _0806D620
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r0, #0xfe
	ands r0, r1
	adds r0, #1
	strb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0806D610
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _0806D608 @ =0x000002E6
	adds r1, r6, r2
	strb r0, [r1]
	ldr r0, _0806D60C @ =0x000002E7
	adds r1, r6, r0
	movs r0, #1
	b _0806D61E
	.align 2, 0
_0806D608: .4byte 0x000002E6
_0806D60C: .4byte 0x000002E7
_0806D610:
	lsrs r1, r1, #0x19
	ldr r2, _0806D674 @ =0x000002E6
	adds r0, r6, r2
	strb r1, [r0]
	ldr r0, _0806D678 @ =0x000002E7
	adds r1, r6, r0
	movs r0, #0
_0806D61E:
	strb r0, [r1]
_0806D620:
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r4, r6, r1
	movs r2, #0xd4
	lsls r2, r2, #2
	adds r0, r6, r2
	ldr r1, [r0]
	subs r2, #0x6a
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806D67C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806D684
	.align 2, 0
_0806D674: .4byte 0x000002E6
_0806D678: .4byte 0x000002E7
_0806D67C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806D684:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806D6A8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806D6B0
_0806D6A8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806D6B0:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806D6E8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806D720
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806D6EC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806D6E0
	ldrb r0, [r4, #5]
_0806D6E0:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806D6FC
	.align 2, 0
_0806D6E8: .4byte 0x0000FFFF
_0806D6EC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806D6FC
	strh r1, [r4, #8]
_0806D6FC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806D720
	movs r0, #1
	strb r0, [r4, #7]
_0806D720:
	ldr r1, _0806D748 @ =0x000003FF
	adds r0, r6, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _0806D73E
	adds r0, r6, #0
	bl FUN_080609dc
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806D73E:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806D748: .4byte 0x000003FF

	thumb_func_start FUN_0806d74c
FUN_0806d74c: @ 0x0806D74C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	movs r1, #8
	bl FUN_08060c40
	ldr r1, _0806D770 @ =0x0000037D
	adds r0, r7, r1
	ldrb r0, [r0]
	mov r8, r0
	cmp r0, #0
	beq _0806D774
	cmp r0, #1
	bne _0806D76E
	b _0806D8EA
_0806D76E:
	b _0806DA0C
	.align 2, 0
_0806D770: .4byte 0x0000037D
_0806D774:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r7, r0
	ldrb r0, [r2]
	movs r1, #1
	orrs r1, r0
	strb r1, [r2]
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0806D7AC
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _0806D7A4 @ =0x000002E6
	adds r1, r7, r2
	strb r0, [r1]
	ldr r0, _0806D7A8 @ =0x000002E7
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	b _0806D7BC
	.align 2, 0
_0806D7A4: .4byte 0x000002E6
_0806D7A8: .4byte 0x000002E7
_0806D7AC:
	lsrs r0, r1, #0x19
	ldr r2, _0806D810 @ =0x000002E6
	adds r1, r7, r2
	strb r0, [r1]
	ldr r1, _0806D814 @ =0x000002E7
	adds r0, r7, r1
	mov r2, r8
	strb r2, [r0]
_0806D7BC:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r7, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0]
	ldr r2, _0806D810 @ =0x000002E6
	adds r0, r7, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r7, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_08236fac
	adds r5, r7, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806D818
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806D820
	.align 2, 0
_0806D810: .4byte 0x000002E6
_0806D814: .4byte 0x000002E7
_0806D818:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806D820:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806D844
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806D84C
_0806D844:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806D84C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806D884 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806D8BC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806D888
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806D87C
	ldrb r0, [r4, #5]
_0806D87C:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806D898
	.align 2, 0
_0806D884: .4byte 0x0000FFFF
_0806D888:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806D898
	strh r1, [r4, #8]
_0806D898:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806D8BC
	movs r0, #1
	strb r0, [r4, #7]
_0806D8BC:
	movs r0, #0xfe
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r0, [r1]
	cmp r0, #0x1e
	bhi _0806D8E4
	movs r0, #0
	strh r0, [r1]
	movs r0, #0xd8
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r2, _0806D8E0 @ =0x0000037D
	adds r1, r7, r2
	movs r0, #1
	strb r0, [r1]
	b _0806DA0C
	.align 2, 0
_0806D8E0: .4byte 0x0000037D
_0806D8E4:
	subs r0, #0x1e
	strh r0, [r1]
	b _0806DA0C
_0806D8EA:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r7, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0]
	ldr r2, _0806D940 @ =0x000002E6
	adds r0, r7, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r7, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #3
	bl FUN_08236fac
	adds r5, r7, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	mov r1, r8
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, r8
	ands r0, r2
	cmp r1, r0
	beq _0806D944
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806D94C
	.align 2, 0
_0806D940: .4byte 0x000002E6
_0806D944:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806D94C:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806D970
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806D978
_0806D970:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806D978:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806D9B0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806D9F6
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806D9BA
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806D9B4
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _0806D9D0
	.align 2, 0
_0806D9B0: .4byte 0x0000FFFF
_0806D9B4:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806D9CE
_0806D9BA:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806D9CE
	strh r1, [r4, #8]
	movs r2, #1
	b _0806D9D0
_0806D9CE:
	movs r2, #0
_0806D9D0:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806D9F8
	movs r0, #1
	strb r0, [r4, #7]
	b _0806D9F8
_0806D9F6:
	movs r2, #0
_0806D9F8:
	cmp r2, #0
	beq _0806DA0C
	adds r0, r7, #0
	bl FUN_080609dc
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806DA0C:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0806da18
FUN_0806da18: @ 0x0806DA18
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x18
	beq _0806DA88
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r5, r3
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0806DA5C
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r6, _0806DA54 @ =0x000002E6
	adds r1, r5, r6
	strb r0, [r1]
	ldr r0, _0806DA58 @ =0x000002E7
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _0806DA6C
	.align 2, 0
_0806DA54: .4byte 0x000002E6
_0806DA58: .4byte 0x000002E7
_0806DA5C:
	lsrs r1, r1, #0x19
	ldr r2, _0806DADC @ =0x000002E6
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r3, _0806DAE0 @ =0x000002E7
	adds r0, r5, r3
	strb r2, [r0]
_0806DA6C:
	ldr r6, _0806DAE4 @ =0x000003D6
	adds r4, r5, r6
	ldrh r0, [r4]
	cmp r0, #0
	beq _0806DA7E
	bl PlaySound_082406e0
	movs r0, #0
	strh r0, [r4]
_0806DA7E:
	adds r0, r5, #0
	movs r1, #0x18
	movs r2, #0
	bl FUN_08060b84
_0806DA88:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r5, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r2, _0806DADC @ =0x000002E6
	adds r0, r5, r2
	ldrb r3, [r0]
	ldr r6, _0806DAE0 @ =0x000002E7
	adds r0, r5, r6
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_08236fac
	adds r6, r5, #0
	adds r6, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806DAE8
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _0806DAF0
	.align 2, 0
_0806DADC: .4byte 0x000002E6
_0806DAE0: .4byte 0x000002E7
_0806DAE4: .4byte 0x000003D6
_0806DAE8:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806DAF0:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806DB14
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0806DB1C
_0806DB14:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806DB1C:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806DB54 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0806DB8C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806DB58
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806DB4C
	ldrb r0, [r4, #5]
_0806DB4C:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806DB68
	.align 2, 0
_0806DB54: .4byte 0x0000FFFF
_0806DB58:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r6, [r4, #5]
	cmp r0, r6
	blo _0806DB68
	strh r1, [r4, #8]
_0806DB68:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806DB8C
	movs r0, #1
	strb r0, [r4, #7]
_0806DB8C:
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r3, r5, r0
	ldrh r0, [r3]
	cmp r0, #0
	bne _0806DB9A
	b _0806DD22
_0806DB9A:
	ldr r1, _0806DBC8 @ =0x00000395
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806DC18
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r2, [r0]
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r6, #0x2c
	ldrsh r0, [r5, r6]
	subs r3, r1, r0
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #0x30
	ldrsh r0, [r5, r2]
	subs r1, r1, r0
	cmp r3, #0
	blt _0806DBCC
	asrs r0, r3, #3
	b _0806DBD2
	.align 2, 0
_0806DBC8: .4byte 0x00000395
_0806DBCC:
	rsbs r0, r3, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_0806DBD2:
	strh r0, [r5, #0x34]
	cmp r1, #0
	blt _0806DBDC
	asrs r0, r1, #3
	b _0806DBE2
_0806DBDC:
	rsbs r0, r1, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_0806DBE2:
	strh r0, [r5, #0x38]
	ldr r3, _0806DC10 @ =0x0000037E
	adds r4, r5, r3
	ldrh r1, [r4]
	cmp r1, #5
	bls _0806DBF0
	b _0806DD0A
_0806DBF0:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0806DC06
	ldr r0, _0806DC14 @ =0x00000191
	bl PlaySound_082406e0
	adds r0, r5, #0
	adds r0, #0x2c
	bl FUN_080acd98
_0806DC06:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _0806DD0A
	.align 2, 0
_0806DC10: .4byte 0x0000037E
_0806DC14: .4byte 0x00000191
_0806DC18:
	ldr r6, _0806DC48 @ =0x00000397
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806DCA8
	movs r1, #0xe6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r2, [r0]
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r6, #0x2c
	ldrsh r0, [r5, r6]
	subs r3, r1, r0
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #0x30
	ldrsh r0, [r5, r2]
	subs r1, r1, r0
	cmp r3, #0
	blt _0806DC4C
	asrs r0, r3, #3
	b _0806DC52
	.align 2, 0
_0806DC48: .4byte 0x00000397
_0806DC4C:
	rsbs r0, r3, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_0806DC52:
	strh r0, [r5, #0x34]
	cmp r1, #0
	blt _0806DC5C
	asrs r0, r1, #3
	b _0806DC62
_0806DC5C:
	rsbs r0, r1, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_0806DC62:
	strh r0, [r5, #0x38]
	ldr r3, _0806DCA0 @ =0x0000037E
	adds r6, r5, r3
	ldrh r0, [r6]
	cmp r0, #5
	bhi _0806DD0A
	movs r4, #1
	ands r4, r0
	cmp r4, #0
	bne _0806DC96
	ldr r0, _0806DCA4 @ =0x00000191
	bl PlaySound_082406e0
	adds r0, r5, #0
	adds r0, #0x2c
	str r4, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl FUN_080ddcc8
_0806DC96:
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	b _0806DD0A
	.align 2, 0
_0806DCA0: .4byte 0x0000037E
_0806DCA4: .4byte 0x00000191
_0806DCA8:
	movs r6, #0xba
	lsls r6, r6, #2
	adds r0, r5, r6
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldr r2, _0806DCD8 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldrh r0, [r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806DCDC
	asrs r0, r0, #0xc
	b _0806DCE2
	.align 2, 0
_0806DCD8: .4byte 0x085B0A08
_0806DCDC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806DCE2:
	rsbs r0, r0, #0
	strh r0, [r5, #0x34]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xd6
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806DD00
	asrs r0, r0, #0xc
	b _0806DD06
_0806DD00:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806DD06:
	rsbs r0, r0, #0
	strh r0, [r5, #0x38]
_0806DD0A:
	movs r6, #0xd6
	lsls r6, r6, #1
	adds r4, r5, r6
	ldrh r0, [r4]
	bl FUN_0823b9cc
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r4]
	b _0806DD74
_0806DD22:
	movs r1, #0
	strh r0, [r3]
	ldr r2, _0806DD54 @ =0x00000395
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _0806DD58 @ =0x00000397
	adds r0, r5, r3
	strb r1, [r0]
	ldr r6, _0806DD5C @ =0x000004C5
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #3
	bne _0806DD64
	ldr r1, _0806DD60 @ =0x000004C7
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806DD64
	adds r0, r5, #0
	movs r1, #0x13
	movs r2, #0
	bl FUN_08060b84
	b _0806DD74
	.align 2, 0
_0806DD54: .4byte 0x00000395
_0806DD58: .4byte 0x00000397
_0806DD5C: .4byte 0x000004C5
_0806DD60: .4byte 0x000004C7
_0806DD64:
	adds r0, r5, #0
	bl FUN_080609dc
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806DD74:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0806dd7c
FUN_0806dd7c: @ 0x0806DD7C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0xd
	bne _0806DD98
	ldr r2, _0806DE6C @ =0x0000037E
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _0806DDCE
_0806DD98:
	adds r0, r6, #0
	movs r1, #0xd
	movs r2, #0
	bl FUN_08060b84
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r6, r3
	movs r0, #0
	strh r0, [r1]
	adds r0, r6, #0
	bl FUN_08063220
	adds r0, r6, #0
	bl FUN_08066e84
	ldr r0, _0806DE70 @ =0x0000039A
	bl PlaySound_082406e0
	movs r0, #0x38
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0
	movs r3, #0x20
	bl FUN_080ac374
_0806DDCE:
	ldr r1, _0806DE6C @ =0x0000037E
	adds r0, r6, r1
	ldrh r0, [r0]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #2
	subs r1, r1, r0
	cmp r2, r1
	blt _0806DDF6
	adds r0, r6, #0
	movs r1, #0x41
	bl FUN_08060c40
	adds r2, r6, #0
	adds r2, #0xa8
	ldr r0, [r6, #0x2c]
	ldr r1, [r6, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
_0806DDF6:
	adds r0, r6, #0
	movs r1, #0xc7
	movs r2, #0x40
	bl FUN_08060a24
	adds r0, r6, #0
	adds r0, #0xc2
	movs r1, #0x91
	lsls r1, r1, #1
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0xd0
	ldr r0, _0806DE74 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2]
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r4, r6, r2
	movs r3, #0xd4
	lsls r3, r3, #2
	adds r0, r6, r3
	ldr r1, [r0]
	subs r2, #0x56
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806DE78
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806DE80
	.align 2, 0
_0806DE6C: .4byte 0x0000037E
_0806DE70: .4byte 0x0000039A
_0806DE74: .4byte 0x03003584
_0806DE78:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806DE80:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806DEA4
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806DEAC
_0806DEA4:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806DEAC:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _0806DEE4 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806DF1C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806DEE8
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806DEDC
	ldrb r0, [r4, #5]
_0806DEDC:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806DEF8
	.align 2, 0
_0806DEE4: .4byte 0x0000FFFF
_0806DEE8:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806DEF8
	strh r1, [r4, #8]
_0806DEF8:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806DF1C
	movs r0, #1
	strb r0, [r4, #7]
_0806DF1C:
	ldr r3, _0806DF74 @ =0x0000095E
	adds r1, r6, r3
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	ldr r3, _0806DF78 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _0806DF42
	movs r0, #0x20
	strh r0, [r1]
_0806DF42:
	ldr r0, _0806DF7C @ =0x0000037E
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ands r0, r2
	cmp r0, #0x1f
	bls _0806DF6C
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r1, #1
	strb r1, [r0]
	ldr r2, _0806DF80 @ =0x00000381
	adds r0, r6, r2
	strb r1, [r0]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806DF6C:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806DF74: .4byte 0x0000095E
_0806DF78: .4byte 0x0000FFFF
_0806DF7C: .4byte 0x0000037E
_0806DF80: .4byte 0x00000381

	thumb_func_start FUN_0806df84
FUN_0806df84: @ 0x0806DF84
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806DFA0
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806DFA0:
	ldr r1, [r6, #0x20]
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r6, #0x20]
	ldr r3, _0806E010 @ =0x00000387
	adds r2, r6, r3
	ldrb r0, [r2]
	cmp r0, #3
	bne _0806DFBC
	movs r0, #0x80
	lsls r0, r0, #0xa
	orrs r1, r0
	str r1, [r6, #0x20]
_0806DFBC:
	movs r5, #0xcf
	lsls r5, r5, #2
	adds r4, r6, r5
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldrb r2, [r2]
	ldr r3, _0806E014 @ =0x000002E6
	adds r0, r6, r3
	ldrb r3, [r0]
	subs r5, #0x55
	adds r0, r6, r5
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806E018
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806E020
	.align 2, 0
_0806E010: .4byte 0x00000387
_0806E014: .4byte 0x000002E6
_0806E018:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806E020:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806E044
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806E04C
_0806E044:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806E04C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806E084 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0806E0BC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806E088
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806E07C
	ldrb r0, [r4, #5]
_0806E07C:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806E098
	.align 2, 0
_0806E084: .4byte 0x0000FFFF
_0806E088:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r5, [r4, #5]
	cmp r0, r5
	blo _0806E098
	strh r1, [r4, #8]
_0806E098:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806E0BC
	movs r0, #1
	strb r0, [r4, #7]
_0806E0BC:
	movs r0, #0xda
	lsls r0, r0, #2
	adds r3, r6, r0
	ldr r2, _0806E144 @ =0x0000036A
	adds r1, r6, r2
	ldrh r0, [r3]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _0806E13A
	movs r4, #0xe3
	lsls r4, r4, #2
	adds r2, r6, r4
	ldr r1, _0806E148 @ =0x085ABC82
	ldr r5, _0806E14C @ =0x00000387
	adds r0, r6, r5
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r1, [r0]
	ldrh r0, [r2]
	adds r0, r0, r1
	movs r7, #0
	strh r0, [r2]
	ldr r4, _0806E150 @ =0x0000FFFF
	adds r1, r4, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x7f
	bls _0806E100
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	ldrh r0, [r2]
	subs r0, #0x80
	strh r0, [r2]
_0806E100:
	ldr r0, _0806E154 @ =0x0000037E
	adds r5, r6, r0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	ands r0, r1
	cmp r0, #0x45
	bls _0806E13A
	movs r2, #0x99
	lsls r2, r2, #4
	adds r1, r6, r2
	movs r0, #2
	strb r0, [r1]
	ldr r3, _0806E158 @ =0x0000098C
	adds r4, r6, r3
	ldr r0, [r4]
	adds r1, r6, #0
	adds r1, #0x24
	str r7, [sp]
	str r7, [sp, #4]
	movs r2, #0x80
	str r2, [sp, #8]
	str r7, [sp, #0xc]
	movs r2, #2
	movs r3, #0
	bl FUN_080da9c4
	str r0, [r4]
	strh r7, [r5]
_0806E13A:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806E144: .4byte 0x0000036A
_0806E148: .4byte 0x085ABC82
_0806E14C: .4byte 0x00000387
_0806E150: .4byte 0x0000FFFF
_0806E154: .4byte 0x0000037E
_0806E158: .4byte 0x0000098C

	thumb_func_start FUN_0806e15c
FUN_0806e15c: @ 0x0806E15C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	mov r8, r0
	movs r7, #1
	movs r0, #0xdf
	lsls r0, r0, #2
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #1
	beq _0806E1A8
	ldr r0, _0806E1D8 @ =0x0000026A
	bl PlaySound_082406e0
	ldr r2, _0806E1DC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0806E1E0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0806E1E4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x40
	movs r1, #0xe2
	lsls r1, r1, #2
	add r1, r8
	strh r0, [r1]
	mov r0, r8
	movs r1, #1
	movs r2, #0
	bl FUN_08060b84
	movs r7, #0
_0806E1A8:
	movs r4, #0xe2
	lsls r4, r4, #2
	add r4, r8
	ldrh r0, [r4]
	cmp r0, #0
	bne _0806E1E8
	ldr r0, _0806E1D8 @ =0x0000026A
	bl PlaySound_082406e0
	ldr r2, _0806E1DC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0806E1E0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0806E1E4 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x40
	b _0806E1EA
	.align 2, 0
_0806E1D8: .4byte 0x0000026A
_0806E1DC: .4byte 0x030046B8
_0806E1E0: .4byte 0x000003FF
_0806E1E4: .4byte 0x0203B400
_0806E1E8:
	subs r0, #1
_0806E1EA:
	strh r0, [r4]
	mov r0, r8
	bl FUN_08067068
	movs r1, #0xba
	lsls r1, r1, #2
	add r1, r8
	strb r0, [r1]
	mov r0, r8
	bl FUN_080609dc
	mov r0, r8
	movs r1, #6
	bl FUN_08060aa4
	movs r4, #0xcf
	lsls r4, r4, #2
	add r4, r8
	movs r0, #0xd5
	lsls r0, r0, #2
	add r0, r8
	ldr r1, [r0]
	ldr r0, _0806E25C @ =0x000002E6
	add r0, r8
	ldrb r3, [r0]
	ldr r0, _0806E260 @ =0x000002E7
	add r0, r8
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0x20
	bl FUN_08236fac
	mov r5, r8
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806E264
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806E26C
	.align 2, 0
_0806E25C: .4byte 0x000002E6
_0806E260: .4byte 0x000002E7
_0806E264:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806E26C:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806E290
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806E298
_0806E290:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806E298:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806E2D0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806E308
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806E2D4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806E2C8
	ldrb r0, [r4, #5]
_0806E2C8:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806E2E4
	.align 2, 0
_0806E2D0: .4byte 0x0000FFFF
_0806E2D4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806E2E4
	strh r1, [r4, #8]
_0806E2E4:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806E308
	movs r0, #1
	strb r0, [r4, #7]
_0806E308:
	cmp r7, #0
	beq _0806E3F6
	movs r7, #0xd1
	lsls r7, r7, #2
	add r7, r8
	ldrh r1, [r7]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0806E3F6
	ldr r0, _0806E344 @ =0x0000034A
	add r0, r8
	ldrh r5, [r0]
	cmp r5, #0
	bne _0806E3F6
	mov r4, r8
	adds r4, #0x2c
	adds r0, r4, #0
	bl FUN_0809f658
	adds r6, r0, #0
	cmp r6, #0
	beq _0806E35C
	ldrh r1, [r7]
	cmp r1, #0
	bne _0806E34C
	str r4, [sp]
	str r5, [sp, #4]
	ldr r0, _0806E348 @ =0x00000163
	b _0806E386
	.align 2, 0
_0806E344: .4byte 0x0000034A
_0806E348: .4byte 0x00000163
_0806E34C:
	cmp r1, #2
	bne _0806E3F6
	str r4, [sp]
	str r5, [sp, #4]
	ldr r0, _0806E358 @ =0x00000163
	b _0806E386
	.align 2, 0
_0806E358: .4byte 0x00000163
_0806E35C:
	movs r0, #0xe5
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	bl FUN_08065a98
	cmp r0, #0
	beq _0806E39C
	ldrh r1, [r7]
	cmp r1, #0
	bne _0806E37C
	str r4, [sp]
	str r6, [sp, #4]
	movs r0, #0xca
	lsls r0, r0, #1
	b _0806E386
_0806E37C:
	cmp r1, #2
	bne _0806E3F6
	str r4, [sp]
	str r6, [sp, #4]
	ldr r0, _0806E398 @ =0x00000193
_0806E386:
	str r0, [sp, #8]
	mov r0, r8
	adds r1, r4, #0
	movs r2, #1
	movs r3, #1
	bl FUN_08066e9c
	b _0806E3F6
	.align 2, 0
_0806E398: .4byte 0x00000193
_0806E39C:
	ldrh r1, [r7]
	cmp r1, #0
	bne _0806E3B0
	ldr r0, _0806E3AC @ =0x00000269
	bl PlaySound_082406e0
	b _0806E3BC
	.align 2, 0
_0806E3AC: .4byte 0x00000269
_0806E3B0:
	cmp r1, #2
	bne _0806E3BC
	movs r0, #0x9a
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0806E3BC:
	movs r1, #1
	ldr r0, _0806E3D4 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _0806E3D8 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0806E3DC
	movs r0, #1
	b _0806E3DE
	.align 2, 0
_0806E3D4: .4byte 0x030046A0
_0806E3D8: .4byte 0x00000934
_0806E3DC:
	movs r0, #0
_0806E3DE:
	cmp r0, #0
	beq _0806E3F6
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, r8
	adds r1, r4, #0
	movs r2, #1
	movs r3, #2
	bl FUN_08066e9c
_0806E3F6:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0806e404
FUN_0806e404: @ 0x0806E404
	push {r4, r5, lr}
	sub sp, #0x20
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	beq _0806E420
	adds r0, r4, #0
	movs r1, #3
	movs r2, #5
	bl FUN_08060b84
_0806E420:
	ldr r1, _0806E43C @ =0x0000037E
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0806E482
	subs r1, #0x16
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #9
	bhi _0806E440
	movs r0, #0xd5
	bl PlaySound_082406e0
	b _0806E482
	.align 2, 0
_0806E43C: .4byte 0x0000037E
_0806E440:
	ldr r0, _0806E4A8 @ =0x0000038A
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _0806E454
	ldr r0, _0806E4AC @ =0x0000026B
	bl PlaySound_082406e0
	movs r0, #0x28
	strh r0, [r5]
_0806E454:
	movs r0, #0xcd
	bl PlaySound_082406e0
	movs r1, #0x20
	str r1, [sp]
	movs r0, #0x2c
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r1, #1
	str r1, [sp, #0xc]
	movs r0, #0x14
	str r0, [sp, #0x10]
	movs r0, #3
	str r0, [sp, #0x14]
	movs r0, #0xa
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0xb4
	movs r3, #0
	bl FUN_08080be8
_0806E482:
	ldr r0, _0806E4B0 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _0806E49E
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806E49E:
	add sp, #0x20
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806E4A8: .4byte 0x0000038A
_0806E4AC: .4byte 0x0000026B
_0806E4B0: .4byte 0x0000037E

	thumb_func_start FUN_0806e4b4
FUN_0806e4b4: @ 0x0806E4B4
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #4
	beq _0806E4D0
	adds r0, r7, #0
	movs r1, #4
	movs r2, #0
	bl FUN_08060b84
_0806E4D0:
	ldr r2, _0806E53C @ =0x0000037E
	adds r4, r7, r2
	ldrh r0, [r4]
	cmp r0, #0
	bne _0806E4E0
	ldr r0, _0806E540 @ =0x000001EB
	bl PlaySound_082406e0
_0806E4E0:
	ldrh r0, [r4]
	cmp r0, #9
	bls _0806E4E8
	b _0806E5EE
_0806E4E8:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r7, r0
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0]
	ldr r2, _0806E544 @ =0x00000387
	adds r0, r7, r2
	ldrb r2, [r0]
	adds r2, #0x10
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_08236fac
	adds r5, r7, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806E548
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806E550
	.align 2, 0
_0806E53C: .4byte 0x0000037E
_0806E540: .4byte 0x000001EB
_0806E544: .4byte 0x00000387
_0806E548:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806E550:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806E574
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806E57C
_0806E574:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806E57C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806E5B4 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806E61A
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806E5B8
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806E5AC
	ldrb r0, [r4, #5]
_0806E5AC:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806E5C8
	.align 2, 0
_0806E5B4: .4byte 0x0000FFFF
_0806E5B8:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806E5C8
	strh r1, [r4, #8]
_0806E5C8:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806E61A
	movs r0, #1
	strb r0, [r4, #7]
	b _0806E61A
_0806E5EE:
	cmp r0, #0x11
	bhi _0806E61A
	ldr r2, _0806E660 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0806E664 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0806E668 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	subs r0, #7
	ldr r2, _0806E66C @ =0x000004BC
	adds r1, r7, r2
	strh r0, [r1]
	rsbs r0, r0, #0
	adds r2, #4
	adds r1, r7, r2
	strh r0, [r1]
_0806E61A:
	ldr r0, _0806E670 @ =0x0000037E
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	movs r2, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x17
	bls _0806E656
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r7, r1
	strb r2, [r0]
	subs r1, #2
	adds r0, r7, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r7, r1
	strb r2, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806E656:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806E660: .4byte 0x030046B8
_0806E664: .4byte 0x000003FF
_0806E668: .4byte 0x0203B400
_0806E66C: .4byte 0x000004BC
_0806E670: .4byte 0x0000037E

	thumb_func_start FUN_0806e674
FUN_0806e674: @ 0x0806E674
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0x14
	beq _0806E690
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #0
	bl FUN_08060b84
_0806E690:
	ldr r2, _0806E710 @ =0x00000387
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #5
	bne _0806E6B6
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrh r1, [r0]
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	blt _0806E6B6
	subs r2, #0x9f
	adds r0, r7, r2
	strb r1, [r0]
	adds r0, r7, #0
	bl FUN_080609dc
_0806E6B6:
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r4, r7, r3
	movs r5, #0xd5
	lsls r5, r5, #2
	adds r0, r7, r5
	ldr r1, [r0]
	ldr r2, _0806E710 @ =0x00000387
	adds r0, r7, r2
	ldrb r2, [r0]
	subs r3, #0x56
	adds r0, r7, r3
	ldrb r3, [r0]
	subs r5, #0x6d
	adds r0, r7, r5
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	bl FUN_08236fac
	adds r5, r7, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806E714
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806E71C
	.align 2, 0
_0806E710: .4byte 0x00000387
_0806E714:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806E71C:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806E740
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806E748
_0806E740:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806E748:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806E780 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0806E7B8
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806E784
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806E778
	ldrb r0, [r4, #5]
_0806E778:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806E794
	.align 2, 0
_0806E780: .4byte 0x0000FFFF
_0806E784:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r5, [r4, #5]
	cmp r0, r5
	blo _0806E794
	strh r1, [r4, #8]
_0806E794:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806E7B8
	movs r0, #1
	strb r0, [r4, #7]
_0806E7B8:
	ldr r1, _0806E7D8 @ =0x000003FF
	adds r0, r7, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _0806E7D0
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806E7D0:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806E7D8: .4byte 0x000003FF

	thumb_func_start FUN_0806e7dc
FUN_0806e7dc: @ 0x0806E7DC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0xe
	bne _0806E7FE
	ldr r2, _0806E858 @ =0x0000037E
	adds r0, r6, r2
	ldrh r0, [r0]
	adds r4, r6, #0
	adds r4, #0xc2
	cmp r0, #0
	beq _0806E7FE
	b _0806E8FA
_0806E7FE:
	adds r0, r6, #0
	movs r1, #0xe
	movs r2, #0
	bl FUN_08060b84
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r4, #0
	movs r0, #4
	strb r0, [r1]
	adds r0, r6, #0
	bl FUN_080609dc
	ldr r0, _0806E85C @ =0x0000098C
	adds r5, r6, r0
	ldr r0, [r5]
	adds r1, r6, #0
	adds r1, #0x24
	movs r3, #0x99
	lsls r3, r3, #4
	adds r2, r6, r3
	ldrb r2, [r2]
	str r4, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r3, #0x7f
	bl FUN_080da9c4
	str r0, [r5]
	movs r0, #0xf5
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _0806E860 @ =0x0000043E
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0806E864
	adds r1, r6, #0
	adds r1, #0xc2
	movs r0, #0x20
	b _0806E8F6
	.align 2, 0
_0806E858: .4byte 0x0000037E
_0806E85C: .4byte 0x0000098C
_0806E860: .4byte 0x0000043E
_0806E864:
	ldr r2, _0806E888 @ =0x0000038E
	adds r0, r6, r2
	ldrb r0, [r0]
	ldr r1, _0806E88C @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r3, #0xb2
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	cmp r0, #0
	ble _0806E890
	adds r1, r6, #0
	adds r1, #0xc2
	movs r0, #0x21
	b _0806E8F6
	.align 2, 0
_0806E888: .4byte 0x0000038E
_0806E88C: .4byte 0x030046A0
_0806E890:
	movs r0, #0x80
	lsls r0, r0, #0xd
	movs r2, #0xde
	lsls r2, r2, #2
	adds r1, r6, r2
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _0806E8AC
	adds r1, r6, #0
	adds r1, #0xc2
	movs r0, #0x94
	lsls r0, r0, #1
	b _0806E8F6
_0806E8AC:
	movs r0, #0x80
	lsls r0, r0, #0xe
	ands r0, r1
	cmp r0, #0
	beq _0806E8C4
	adds r1, r6, #0
	adds r1, #0xc2
	ldr r0, _0806E8C0 @ =0x00000129
	b _0806E8F6
	.align 2, 0
_0806E8C0: .4byte 0x00000129
_0806E8C4:
	movs r0, #0x80
	lsls r0, r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _0806E8D8
	adds r1, r6, #0
	adds r1, #0xc2
	movs r0, #0x95
	lsls r0, r0, #1
	b _0806E8F6
_0806E8D8:
	movs r0, #0x80
	lsls r0, r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _0806E8F0
	adds r1, r6, #0
	adds r1, #0xc2
	ldr r0, _0806E8EC @ =0x0000012B
	b _0806E8F6
	.align 2, 0
_0806E8EC: .4byte 0x0000012B
_0806E8F0:
	adds r1, r6, #0
	adds r1, #0xc2
	movs r0, #0x26
_0806E8F6:
	strh r0, [r1]
	adds r4, r1, #0
_0806E8FA:
	adds r0, r6, #0
	movs r1, #0x40
	bl FUN_08060c40
	adds r0, r6, #0
	movs r1, #0xc7
	movs r2, #0x40
	bl FUN_08060a24
	adds r2, r6, #0
	adds r2, #0xd0
	ldr r0, _0806E988 @ =0x03003584
	ldrh r1, [r4]
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2]
	subs r2, #0x28
	ldr r0, [r6, #0x2c]
	ldr r1, [r6, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r3, _0806E98C @ =0x0000037E
	adds r0, r6, r3
	ldrh r0, [r0]
	lsls r1, r0, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #9
	bls _0806E936
	b _0806EA3A
_0806E936:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _0806E990 @ =0x00000387
	adds r0, r6, r2
	ldrb r2, [r0]
	adds r2, #8
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806E994
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806E99C
	.align 2, 0
_0806E988: .4byte 0x03003584
_0806E98C: .4byte 0x0000037E
_0806E990: .4byte 0x00000387
_0806E994:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806E99C:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806E9C0
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806E9C8
_0806E9C0:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806E9C8:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _0806EA00 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806EA4C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806EA04
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806E9F8
	ldrb r0, [r4, #5]
_0806E9F8:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806EA14
	.align 2, 0
_0806EA00: .4byte 0x0000FFFF
_0806EA04:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806EA14
	strh r1, [r4, #8]
_0806EA14:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806EA4C
	movs r0, #1
	strb r0, [r4, #7]
	b _0806EA4C
_0806EA3A:
	lsrs r0, r1, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0806EA4C
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08060c40
_0806EA4C:
	ldr r3, _0806EA90 @ =0x0000037E
	adds r1, r6, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x27
	bls _0806EA86
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r1, #1
	strb r1, [r0]
	ldr r2, _0806EA94 @ =0x00000381
	adds r0, r6, r2
	strb r1, [r0]
	subs r3, #0x96
	adds r1, r6, r3
	movs r0, #4
	strb r0, [r1]
	adds r0, r6, #0
	bl FUN_080609dc
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806EA86:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806EA90: .4byte 0x0000037E
_0806EA94: .4byte 0x00000381

	thumb_func_start FUN_0806ea98
FUN_0806ea98: @ 0x0806EA98
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r3, #0x80
	lsls r3, r3, #0xb
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	mov sb, r0
	ldr r0, _0806EAC8 @ =0x03002BF8
	ldr r0, [r0]
	cmp r0, #0
	bne _0806EACC
	movs r0, #0
	b _0806EB2C
	.align 2, 0
_0806EAC8: .4byte 0x03002BF8
_0806EACC:
	ldr r6, [r0, #0x18]
	movs r2, #0
	mov r8, r2
	cmp r6, #0
	beq _0806EB2A
_0806EAD6:
	ldr r0, [r6, #4]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0806EB24
	ldr r2, [r6]
	movs r4, #8
	ldrsh r1, [r2, r4]
	movs r4, #0x2c
	ldrsh r0, [r7, r4]
	subs r5, r1, r0
	movs r0, #0xc
	ldrsh r1, [r2, r0]
	movs r2, #0x30
	ldrsh r0, [r7, r2]
	subs r4, r1, r0
	adds r0, r5, #0
	adds r1, r4, #0
	str r3, [sp]
	bl FUN_0823785c
	ldr r1, _0806EB3C @ =0xFFFFFF00
	add r1, sb
	subs r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	subs r0, #0x21
	ldr r3, [sp]
	cmp r0, #0xbe
	bls _0806EB24
	adds r1, r5, #0
	muls r1, r5, r1
	adds r0, r4, #0
	muls r0, r4, r0
	adds r0, r1, r0
	cmp r0, r3
	bge _0806EB24
	adds r3, r0, #0
	mov r8, r6
_0806EB24:
	ldr r6, [r6, #0xc]
	cmp r6, #0
	bne _0806EAD6
_0806EB2A:
	mov r0, r8
_0806EB2C:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0806EB3C: .4byte 0xFFFFFF00

	thumb_func_start FUN_0806eb40
FUN_0806eb40: @ 0x0806EB40
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0xb
	beq _0806EBC6
	ldr r0, _0806EB8C @ =0x03002B70
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0806EB90 @ =0x03002B88
	strh r1, [r0]
	ldr r0, _0806EB94 @ =0x03002BF4
	strh r1, [r0]
	movs r1, #0
	movs r2, #0xd8
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	adds r0, r5, #0
	bl FUN_0806ea98
	ldr r1, _0806EB98 @ =0x03002BA8
	str r0, [r1]
	cmp r0, #0
	bne _0806EB9C
	adds r0, r5, #0
	movs r1, #0xb
	movs r2, #3
	bl FUN_08060b84
	b _0806EBBA
	.align 2, 0
_0806EB8C: .4byte 0x03002B70
_0806EB90: .4byte 0x03002B88
_0806EB94: .4byte 0x03002BF4
_0806EB98: .4byte 0x03002BA8
_0806EB9C:
	ldr r3, _0806EBDC @ =0x0000095E
	adds r1, r5, r3
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r5, r0
	movs r0, #0x20
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #0xb
	movs r2, #1
	bl FUN_08060b84
_0806EBBA:
	adds r0, r5, #0
	bl FUN_08064be4
	ldr r0, _0806EBE0 @ =0x0000039E
	bl PlaySound_082406e0
_0806EBC6:
	ldr r1, _0806EBE4 @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #5
	bls _0806EBD2
	b _0806F1DE
_0806EBD2:
	lsls r0, r0, #2
	ldr r1, _0806EBE8 @ =_0806EBEC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806EBDC: .4byte 0x0000095E
_0806EBE0: .4byte 0x0000039E
_0806EBE4: .4byte 0x0000037D
_0806EBE8: .4byte _0806EBEC
_0806EBEC: @ jump table
	.4byte _0806EC04 @ case 0
	.4byte _0806EC7C @ case 1
	.4byte _0806EE6C @ case 2
	.4byte _0806F06C @ case 3
	.4byte _0806F0BC @ case 4
	.4byte _0806F1C4 @ case 5
_0806EC04:
	ldr r2, _0806EC34 @ =0x0000037E
	adds r0, r5, r2
	ldrh r0, [r0]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #3
	subs r1, r1, r0
	cmp r2, r1
	bge _0806EC38
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	b _0806EC42
	.align 2, 0
_0806EC34: .4byte 0x0000037E
_0806EC38:
	ldr r1, _0806EC70 @ =0x00000193
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
_0806EC42:
	ldr r0, _0806EC74 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x37
	bhi _0806EC56
	b _0806F1DE
_0806EC56:
	adds r0, r5, #0
	bl FUN_0806ea98
	ldr r1, _0806EC78 @ =0x03002BA8
	str r0, [r1]
	cmp r0, #0
	beq _0806ED0C
	adds r0, r5, #0
	movs r1, #0xb
	movs r2, #1
	bl FUN_08060b84
	b _0806F1DE
	.align 2, 0
_0806EC70: .4byte 0x00000193
_0806EC74: .4byte 0x0000037E
_0806EC78: .4byte 0x03002BA8
_0806EC7C:
	ldr r1, _0806ECEC @ =0x03002BA8
	mov r8, r1
	ldr r0, [r1]
	ldr r2, [r0]
	movs r3, #8
	ldrsh r1, [r2, r3]
	movs r3, #0x2c
	ldrsh r0, [r5, r3]
	subs r6, r1, r0
	movs r0, #0xc
	ldrsh r1, [r2, r0]
	movs r2, #0x30
	ldrsh r0, [r5, r2]
	subs r4, r1, r0
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_0823785c
	adds r7, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0]
	ldrb r0, [r0, #5]
	subs r0, r7, r0
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r2, #0xff
	mov sb, r2
	ands r0, r2
	subs r0, #0x21
	cmp r0, #0xbe
	bls _0806ECC6
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08060c40
_0806ECC6:
	adds r0, r6, #0
	muls r0, r6, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	ldr r1, _0806ECF0 @ =0x000008FF
	cmp r0, r1
	bgt _0806ED9C
	mov r3, r8
	ldr r1, [r3]
	ldr r4, [r1, #4]
	movs r6, #1
	ands r4, r6
	cmp r4, #0
	beq _0806ECF4
	movs r0, #0
	str r0, [r3]
	b _0806ED0C
	.align 2, 0
_0806ECEC: .4byte 0x03002BA8
_0806ECF0: .4byte 0x000008FF
_0806ECF4:
	ldr r0, [r1]
	ldr r3, [r1, #8]
	movs r1, #0
	movs r2, #0
	bl _call_via_r3
	ldr r1, _0806ED18 @ =0x03002BF4
	strh r6, [r1]
	cmp r0, #0
	bne _0806ED1C
	mov r0, r8
	str r4, [r0]
_0806ED0C:
	adds r0, r5, #0
	movs r1, #0xb
	movs r2, #3
	bl FUN_08060b84
	b _0806F1DE
	.align 2, 0
_0806ED18: .4byte 0x03002BF4
_0806ED1C:
	adds r0, r7, #0
	adds r0, #0x20
	mov r1, sb
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #1
	adds r0, #3
	movs r2, #7
	ands r0, r2
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r5, r3
	strb r0, [r1]
	mov r3, r8
	ldr r1, [r3]
	ldr r1, [r1]
	adds r0, #5
	ands r0, r2
	lsls r0, r0, #5
	strb r0, [r1, #5]
	adds r0, r7, #0
	adds r0, #0x60
	mov r1, sb
	ands r0, r1
	asrs r1, r0, #6
	cmp r1, #1
	ble _0806ED70
	movs r0, #3
	subs r0, r0, r1
	ldr r2, _0806ED68 @ =0x000002E6
	adds r1, r5, r2
	strb r0, [r1]
	ldr r3, _0806ED6C @ =0x000002E7
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _0806ED7C
	.align 2, 0
_0806ED68: .4byte 0x000002E6
_0806ED6C: .4byte 0x000002E7
_0806ED70:
	ldr r2, _0806ED94 @ =0x000002E6
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _0806ED98 @ =0x000002E7
	adds r0, r5, r3
	strb r4, [r0]
_0806ED7C:
	movs r1, #0xcd
	lsls r1, r1, #1
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	adds r0, r5, #0
	movs r1, #0xb
	movs r2, #2
	bl FUN_08060b84
	b _0806F1DE
	.align 2, 0
_0806ED94: .4byte 0x000002E6
_0806ED98: .4byte 0x000002E7
_0806ED9C:
	ldr r2, _0806EDBC @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	mov r1, sb
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0806EDC0
	asrs r0, r0, #0xc
	b _0806EDC6
	.align 2, 0
_0806EDBC: .4byte 0x085B0A08
_0806EDC0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806EDC6:
	strh r0, [r5, #0x34]
	movs r0, #0xff
	ands r0, r7
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0806EDE2
	asrs r0, r0, #0xc
	b _0806EDE8
_0806EDE2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806EDE8:
	strh r0, [r5, #0x38]
	adds r0, r7, #0
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	lsls r0, r0, #1
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r5, r3
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x60
	ands r0, r2
	asrs r1, r0, #6
	cmp r1, #1
	ble _0806EE28
	movs r0, #3
	subs r0, r0, r1
	ldr r2, _0806EE24 @ =0x000002E6
	adds r1, r5, r2
	strb r0, [r1]
	subs r3, #1
	adds r1, r5, r3
	movs r0, #1
	b _0806EE34
	.align 2, 0
_0806EE24: .4byte 0x000002E6
_0806EE28:
	ldr r2, _0806EE60 @ =0x000002E6
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _0806EE64 @ =0x000002E7
	adds r1, r5, r3
	movs r0, #0
_0806EE34:
	strb r0, [r1]
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080670fc
	ldr r0, _0806EE68 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bhi _0806EE5E
	b _0806F1DE
_0806EE5E:
	b _0806EF18
	.align 2, 0
_0806EE60: .4byte 0x000002E6
_0806EE64: .4byte 0x000002E7
_0806EE68: .4byte 0x0000037E
_0806EE6C:
	ldr r1, _0806EE90 @ =0x03002BA8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r4, #1
	ands r0, r4
	cmp r0, #0
	beq _0806EE98
	movs r0, #0
	str r0, [r1]
	adds r0, r5, #0
	bl FUN_080609dc
	ldr r1, _0806EE94 @ =0x00000193
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	b _0806EF18
	.align 2, 0
_0806EE90: .4byte 0x03002BA8
_0806EE94: .4byte 0x00000193
_0806EE98:
	ldr r0, _0806EF24 @ =0x03002B70
	ldrh r0, [r0]
	cmp r0, #3
	bhi _0806EEC2
	adds r0, r5, #0
	bl FUN_08064b90
	cmp r0, #0
	beq _0806EEC2
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0806EEC2
	ldr r0, _0806EF28 @ =0x03002B88
	strh r4, [r0]
_0806EEC2:
	movs r1, #0xcd
	lsls r1, r1, #1
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	adds r1, r0, #0
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #5
	beq _0806EEDC
	b _0806F018
_0806EEDC:
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	beq _0806EEE8
	b _0806F018
_0806EEE8:
	movs r2, #0xd7
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r0, [r0]
	movs r3, #0xd8
	lsls r3, r3, #2
	adds r1, r5, r3
	ldrh r1, [r1]
	adds r0, r0, r1
	asrs r6, r0, #1
	ldr r4, _0806EF2C @ =0x03002BA8
	ldr r1, [r4]
	ldr r0, [r1]
	ldr r3, [r1, #8]
	movs r1, #0
	adds r2, r6, #0
	bl _call_via_r3
	cmp r0, #0
	bne _0806EF30
	str r0, [r4]
	adds r0, r5, #0
	bl FUN_080609dc
_0806EF18:
	adds r0, r5, #0
	movs r1, #0xb
	movs r2, #4
	bl FUN_08060b84
	b _0806F1DE
	.align 2, 0
_0806EF24: .4byte 0x03002B70
_0806EF28: .4byte 0x03002B88
_0806EF2C: .4byte 0x03002BA8
_0806EF30:
	ldr r0, _0806EF64 @ =0x0000039F
	bl PlaySound_082406e0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _0806EF68 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #6
	cmp r0, #0
	blt _0806EF6C
	asrs r0, r0, #0xc
	b _0806EF72
	.align 2, 0
_0806EF64: .4byte 0x0000039F
_0806EF68: .4byte 0x085B0A08
_0806EF6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806EF72:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xe6
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #8]
	ldr r1, _0806EF94 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #6
	cmp r0, #0
	blt _0806EF98
	asrs r0, r0, #0xc
	b _0806EF9E
	.align 2, 0
_0806EF94: .4byte 0x085B0A08
_0806EF98:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806EF9E:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0806F00C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	adds r4, r5, #0
	adds r4, #0x2c
	movs r0, #1
	str r0, [sp]
	adds r0, r4, #0
	add r1, sp, #8
	movs r2, #0
	movs r3, #0
	bl FUN_080dc0b8
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r2, r5, r0
	ldrh r0, [r2]
	adds r0, r0, r6
	strh r0, [r2]
	ldr r3, _0806F010 @ =0x00000366
	adds r1, r5, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r3, [r1]
	cmp r0, r3
	blo _0806EFE2
	ldrh r1, [r1]
	ldrh r0, [r2]
	subs r6, r1, r0
	strh r1, [r2]
_0806EFE2:
	cmp r6, #0
	ble _0806F002
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0x97
	lsls r2, r2, #4
	adds r1, r5, r2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	adds r1, r6, #0
	movs r2, #1
	adds r3, r4, #0
	bl FUN_0805fe7c
_0806F002:
	ldr r1, _0806F014 @ =0x03002B70
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0806F1DE
	.align 2, 0
_0806F00C: .4byte 0xFFFF0000
_0806F010: .4byte 0x00000366
_0806F014: .4byte 0x03002B70
_0806F018:
	cmp r1, #0
	bne _0806F01E
	b _0806F1DE
_0806F01E:
	ldr r0, _0806F034 @ =0x03002B88
	ldrh r6, [r0]
	cmp r6, #0
	beq _0806F038
	adds r0, r5, #0
	movs r1, #0xb
	movs r2, #2
	bl FUN_08060b84
	b _0806F05C
	.align 2, 0
_0806F034: .4byte 0x03002B88
_0806F038:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08060c40
	ldr r4, _0806F064 @ =0x03002BA8
	ldr r1, [r4]
	ldr r0, [r1]
	ldr r3, [r1, #8]
	movs r1, #1
	movs r2, #0x3c
	bl _call_via_r3
	str r6, [r4]
	adds r0, r5, #0
	movs r1, #0xb
	movs r2, #4
	bl FUN_08060b84
_0806F05C:
	ldr r1, _0806F068 @ =0x03002B88
	movs r0, #0
	strh r0, [r1]
	b _0806F1DE
	.align 2, 0
_0806F064: .4byte 0x03002BA8
_0806F068: .4byte 0x03002B88
_0806F06C:
	ldr r3, _0806F0B0 @ =0x0000095E
	adds r1, r5, r3
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r5, r0
	movs r0, #0x20
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080609dc
	ldr r1, _0806F0B4 @ =0x00000193
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _0806F0B8 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bhi _0806F0A4
	b _0806F1DE
_0806F0A4:
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	b _0806F1DE
	.align 2, 0
_0806F0B0: .4byte 0x0000095E
_0806F0B4: .4byte 0x00000193
_0806F0B8: .4byte 0x0000037E
_0806F0BC:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08060c40
	ldr r3, _0806F120 @ =0x0000037E
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _0806F0E2
	ldr r0, _0806F124 @ =0x0000095E
	adds r1, r5, r0
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r0, #0x20
	strh r0, [r1]
_0806F0E2:
	adds r0, r5, #0
	bl FUN_080609dc
	ldr r1, _0806F128 @ =0x00000193
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _0806F12C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #4
	cmp r0, #0
	blt _0806F130
	asrs r0, r0, #0xc
	b _0806F136
	.align 2, 0
_0806F120: .4byte 0x0000037E
_0806F124: .4byte 0x0000095E
_0806F128: .4byte 0x00000193
_0806F12C: .4byte 0x085B0A08
_0806F130:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806F136:
	rsbs r0, r0, #0
	strh r0, [r5, #0x34]
	ldr r1, _0806F150 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #4
	adds r2, r1, #0
	cmp r0, #0
	blt _0806F154
	asrs r0, r0, #0xc
	b _0806F15A
	.align 2, 0
_0806F150: .4byte 0x085B0A08
_0806F154:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806F15A:
	rsbs r0, r0, #0
	strh r0, [r5, #0x38]
	ldr r3, _0806F180 @ =0x0000037E
	adds r0, r5, r3
	ldrh r0, [r0]
	adds r0, #4
	lsls r0, r0, #3
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #6
	cmp r0, #0
	blt _0806F184
	asrs r0, r0, #0xc
	b _0806F18A
	.align 2, 0
_0806F180: .4byte 0x0000037E
_0806F184:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806F18A:
	ldr r3, _0806F1BC @ =0x000003F6
	adds r2, r5, r3
	strh r0, [r2]
	ldr r0, _0806F1C0 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bls _0806F1DE
	movs r0, #0
	strh r0, [r2]
	movs r0, #0xd8
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #0xb
	movs r2, #5
	bl FUN_08060b84
	b _0806F1DE
	.align 2, 0
_0806F1BC: .4byte 0x000003F6
_0806F1C0: .4byte 0x0000037E
_0806F1C4:
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806F1DE
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806F1DE:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0806f1ec
FUN_0806f1ec: @ 0x0806F1EC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _0806F204 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _0806F27C
	cmp r0, #1
	bgt _0806F208
	cmp r0, #0
	beq _0806F212
	b _0806F27C
	.align 2, 0
_0806F204: .4byte 0x0000037D
_0806F208:
	cmp r0, #2
	beq _0806F238
	cmp r0, #3
	beq _0806F274
	b _0806F27C
_0806F212:
	ldr r0, _0806F230 @ =0x0000039E
	bl PlaySound_082406e0
	ldr r1, _0806F234 @ =0x00000193
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	adds r0, r4, #0
	movs r1, #0x1f
	movs r2, #1
	bl FUN_08060b84
	b _0806F27C
	.align 2, 0
_0806F230: .4byte 0x0000039E
_0806F234: .4byte 0x00000193
_0806F238:
	ldr r0, _0806F270 @ =0x0000037E
	adds r5, r4, r0
	ldrh r0, [r5]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #3
	subs r1, r1, r0
	cmp r2, r1
	blt _0806F254
	adds r0, r4, #0
	movs r1, #5
	bl FUN_08060c40
_0806F254:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x37
	bls _0806F27C
	adds r0, r4, #0
	movs r1, #0x1f
	movs r2, #3
	bl FUN_08060b84
	b _0806F27C
	.align 2, 0
_0806F270: .4byte 0x0000037E
_0806F274:
	adds r0, r4, #0
	movs r1, #5
	bl FUN_08060c40
_0806F27C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0806f284
FUN_0806f284: @ 0x0806F284
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _0806F2CE
	movs r0, #0xda
	lsls r0, r0, #2
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	beq _0806F2BC
	ldr r0, _0806F2B8 @ =0x00000392
	bl PlaySound_082406e0
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	bl FUN_08060b84
	b _0806F2CE
	.align 2, 0
_0806F2B8: .4byte 0x00000392
_0806F2BC:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #2
	movs r2, #1
	bl FUN_08060b84
_0806F2CE:
	ldr r1, _0806F2E0 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806F2E4
	cmp r0, #1
	beq _0806F360
	b _0806F394
	.align 2, 0
_0806F2E0: .4byte 0x0000037D
_0806F2E4:
	ldr r0, _0806F304 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r2, r0, #1
	strh r2, [r1]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0806F308
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	b _0806F394
	.align 2, 0
_0806F304: .4byte 0x0000037E
_0806F308:
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0806F322
	ldr r0, _0806F358 @ =0x0000095E
	adds r1, r4, r0
	ldr r0, _0806F35C @ =0x00000125
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
_0806F322:
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0806F336
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_08060aa4
_0806F336:
	adds r0, r4, #0
	bl FUN_080609dc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #1
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	b _0806F394
	.align 2, 0
_0806F358: .4byte 0x0000095E
_0806F35C: .4byte 0x00000125
_0806F360:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _0806F39C @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _0806F394
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806F394:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806F39C: .4byte 0x0000037E

	thumb_func_start FUN_0806f3a0
FUN_0806f3a0: @ 0x0806F3A0
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x10
	beq _0806F488
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrb r0, [r1]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _0806F3E4
	movs r2, #0
	movs r0, #4
	strb r0, [r1]
	ldr r3, _0806F3DC @ =0x000002E6
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0806F3E0 @ =0x000002E7
	adds r0, r4, r1
	strb r2, [r0]
	b _0806F3F4
	.align 2, 0
_0806F3DC: .4byte 0x000002E6
_0806F3E0: .4byte 0x000002E7
_0806F3E4:
	movs r0, #0
	strb r0, [r1]
	ldr r2, _0806F460 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r3, _0806F464 @ =0x000002E7
	adds r1, r4, r3
	strb r0, [r1]
_0806F3F4:
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #1
	bls _0806F470
	adds r7, r4, #0
	adds r7, #0x2c
	adds r0, r4, #0
	adds r1, r7, #0
	bl FUN_080a9478
	ldr r2, _0806F468 @ =0x000003FA
	adds r0, r4, r2
	movs r1, #1
	strb r1, [r0]
	movs r3, #0xd9
	lsls r3, r3, #2
	adds r6, r4, r3
	ldr r0, _0806F46C @ =0x00000366
	adds r2, r4, r0
	ldrh r0, [r6]
	ldrh r1, [r2]
	cmp r0, r1
	bhs _0806F452
	adds r1, r0, #0
	adds r5, r1, #0
	adds r5, #0x28
	ldrh r0, [r2]
	cmp r5, r0
	blt _0806F434
	adds r5, r0, #0
_0806F434:
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r4, r2
	subs r1, r5, r1
	movs r3, #0x97
	lsls r3, r3, #4
	adds r2, r4, r3
	str r2, [sp]
	movs r2, #0
	str r2, [sp, #4]
	movs r2, #1
	adds r3, r7, #0
	bl FUN_0805fe7c
	strh r5, [r6]
_0806F452:
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, #2
	strh r0, [r1]
	b _0806F478
	.align 2, 0
_0806F460: .4byte 0x000002E6
_0806F464: .4byte 0x000002E7
_0806F468: .4byte 0x000003FA
_0806F46C: .4byte 0x00000366
_0806F470:
	ldr r2, _0806F49C @ =0x000003FA
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
_0806F478:
	ldr r0, _0806F4A0 @ =0x00000306
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #0
	bl FUN_08060b84
_0806F488:
	ldr r3, _0806F4A4 @ =0x0000037D
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #1
	beq _0806F514
	cmp r0, #1
	bgt _0806F4A8
	cmp r0, #0
	beq _0806F4B2
	b _0806F5D0
	.align 2, 0
_0806F49C: .4byte 0x000003FA
_0806F4A0: .4byte 0x00000306
_0806F4A4: .4byte 0x0000037D
_0806F4A8:
	cmp r0, #2
	beq _0806F55C
	cmp r0, #3
	beq _0806F5A4
	b _0806F5D0
_0806F4B2:
	ldr r0, _0806F500 @ =0x000003FA
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0806F4D0
	ldr r2, _0806F504 @ =0x0000095E
	adds r1, r4, r2
	movs r0, #0x93
	lsls r0, r0, #1
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r4, r3
	movs r0, #0x20
	strh r0, [r1]
_0806F4D0:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #8
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806F5D0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0806F508
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #1
	bl FUN_08060b84
	b _0806F5D0
	.align 2, 0
_0806F500: .4byte 0x000003FA
_0806F504: .4byte 0x0000095E
_0806F508:
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #2
	bl FUN_08060b84
	b _0806F5D0
_0806F514:
	ldr r2, _0806F554 @ =0x0000095E
	adds r1, r4, r2
	movs r0, #0x93
	lsls r0, r0, #1
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r4, r3
	movs r0, #0x20
	strh r0, [r1]
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
	ldr r2, _0806F558 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x17
	bls _0806F5D0
	b _0806F594
	.align 2, 0
_0806F554: .4byte 0x0000095E
_0806F558: .4byte 0x0000037E
_0806F55C:
	ldr r3, _0806F5A0 @ =0x0000037E
	adds r5, r4, r3
	ldrh r0, [r5]
	cmp r0, #0
	bne _0806F56E
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0806F56E:
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
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0806F5D0
_0806F594:
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #3
	bl FUN_08060b84
	b _0806F5D0
	.align 2, 0
_0806F5A0: .4byte 0x0000037E
_0806F5A4:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0xb
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806F5D0
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806F5D0:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0806f5d8
FUN_0806f5d8: @ 0x0806F5D8
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x11
	beq _0806F626
	movs r0, #0xda
	lsls r0, r0, #2
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #1
	bls _0806F614
	ldr r0, _0806F610 @ =0x000003FA
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	adds r1, r4, #0
	adds r1, #0x2c
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080a8ff8
	ldrh r0, [r5]
	subs r0, #2
	strh r0, [r5]
	b _0806F61C
	.align 2, 0
_0806F610: .4byte 0x000003FA
_0806F614:
	ldr r0, _0806F63C @ =0x000003FA
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
_0806F61C:
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #0
	bl FUN_08060b84
_0806F626:
	ldr r1, _0806F640 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _0806F6A4
	cmp r0, #1
	bgt _0806F644
	cmp r0, #0
	beq _0806F64E
	b _0806F730
	.align 2, 0
_0806F63C: .4byte 0x000003FA
_0806F640: .4byte 0x0000037D
_0806F644:
	cmp r0, #2
	beq _0806F6DC
	cmp r0, #3
	beq _0806F718
	b _0806F730
_0806F64E:
	ldr r0, _0806F68C @ =0x000003FA
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0806F66A
	ldr r0, _0806F690 @ =0x0000095E
	adds r1, r4, r0
	ldr r0, _0806F694 @ =0x00000123
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
_0806F66A:
	adds r0, r4, #0
	movs r1, #0xb8
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806F730
	ldrb r0, [r5]
	cmp r0, #0
	beq _0806F698
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #1
	bl FUN_08060b84
	b _0806F730
	.align 2, 0
_0806F68C: .4byte 0x000003FA
_0806F690: .4byte 0x0000095E
_0806F694: .4byte 0x00000123
_0806F698:
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #2
	bl FUN_08060b84
	b _0806F730
_0806F6A4:
	ldr r1, _0806F6CC @ =0x000003FA
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806F6C0
	ldr r0, _0806F6D0 @ =0x0000095E
	adds r1, r4, r0
	ldr r0, _0806F6D4 @ =0x00000123
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
_0806F6C0:
	ldr r0, _0806F6D8 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0806F6FE
	.align 2, 0
_0806F6CC: .4byte 0x000003FA
_0806F6D0: .4byte 0x0000095E
_0806F6D4: .4byte 0x00000123
_0806F6D8: .4byte 0x0000037E
_0806F6DC:
	ldr r1, _0806F714 @ =0x0000037E
	adds r5, r4, r1
	ldrh r0, [r5]
	cmp r0, #0
	bne _0806F6EE
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0806F6EE:
	adds r0, r4, #0
	movs r1, #0xc2
	movs r2, #0x40
	bl FUN_08060a24
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_0806F6FE:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bls _0806F730
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #3
	bl FUN_08060b84
	b _0806F730
	.align 2, 0
_0806F714: .4byte 0x0000037E
_0806F718:
	adds r0, r4, #0
	movs r1, #0xbd
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806F730
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	bl FUN_08060b84
_0806F730:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0806f738
FUN_0806f738: @ 0x0806F738
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0806F76C
	ldr r1, _0806F77C @ =0x000003CE
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _0806F76C
	adds r0, r4, #0
	bl FUN_08067068
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	movs r5, #1
_0806F76C:
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0806F77C: .4byte 0x000003CE

	thumb_func_start FUN_0806f780
FUN_0806f780: @ 0x0806F780
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08064d04
	adds r1, r0, #0
	ldr r2, _0806F7A0 @ =0x00000A8D
	adds r0, r4, r2
	strb r1, [r0]
	lsls r0, r1, #0x18
	cmp r0, #0
	blt _0806F7A8
	adds r1, #1
	ldr r2, _0806F7A4 @ =0x00000951
	adds r0, r4, r2
	strb r1, [r0]
	b _0806F7B0
	.align 2, 0
_0806F7A0: .4byte 0x00000A8D
_0806F7A4: .4byte 0x00000951
_0806F7A8:
	ldr r0, _0806F7B8 @ =0x00000951
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
_0806F7B0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806F7B8: .4byte 0x00000951

	thumb_func_start FUN_0806f7bc
FUN_0806f7bc: @ 0x0806F7BC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0x99
	lsls r1, r1, #2
	adds r3, r5, r1
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrb r1, [r1]
	cmp r1, #0
	bne _0806F7E6
	movs r4, #0xd8
	lsls r4, r4, #2
	adds r1, r5, r4
	ldrh r1, [r1]
	ldrh r2, [r3, #0xc]
	adds r1, r1, r2
	movs r4, #0x14
	ldrsh r2, [r3, r4]
	adds r6, r1, r2
	b _0806F7F8
_0806F7E6:
	movs r2, #0xd8
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r1, [r1]
	ldrh r2, [r3, #0xc]
	adds r1, r1, r2
	movs r4, #0x14
	ldrsh r2, [r3, r4]
	subs r6, r1, r2
_0806F7F8:
	ldr r4, _0806F81C @ =0x030046A0
	ldr r1, [r4]
	adds r1, #0x40
	movs r2, #0
	ldrsh r3, [r1, r2]
	adds r1, r6, r3
	asrs r6, r1, #1
	ldr r2, _0806F820 @ =0x00000A75
	adds r1, r5, r2
	ldrb r2, [r1]
	cmp r2, #3
	beq _0806F874
	cmp r2, #3
	ble _0806F824
	cmp r2, #4
	beq _0806F8BC
	b _0806F8F4
	.align 2, 0
_0806F81C: .4byte 0x030046A0
_0806F820: .4byte 0x00000A75
_0806F824:
	cmp r2, #0
	blt _0806F8F4
	movs r1, #8
	movs r4, #0xde
	lsls r4, r4, #2
	adds r0, r5, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0806F850
	adds r4, r3, #0
	cmp r4, #0x3c
	ble _0806F840
	movs r4, #0x3c
_0806F840:
	adds r0, r4, #0
	muls r0, r2, r0
	movs r1, #6
	bl Div
	adds r0, #5
	adds r4, r4, r0
	b _0806F86C
_0806F850:
	ldr r0, _0806F870 @ =0x00000A78
	adds r1, r5, r0
	movs r2, #0xa7
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r1, [r1]
	adds r4, r0, r1
	cmp r4, #0
	bge _0806F86C
	movs r4, #0
_0806F86C:
	adds r0, r6, r4
	b _0806F8F4
	.align 2, 0
_0806F870: .4byte 0x00000A78
_0806F874:
	movs r0, #3
	bl FUN_0807a8c0
	ldr r1, [r4]
	adds r1, #0x40
	movs r4, #0
	ldrsh r1, [r1, r4]
	adds r0, r0, r1
	asrs r0, r0, #2
	adds r4, r6, r0
	movs r1, #0x80
	lsls r1, r1, #0x15
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0806F8B4
	ldr r1, _0806F8B8 @ =0x00000366
	adds r0, r5, r1
	ldrh r1, [r0]
	subs r2, #0x14
	adds r0, r5, r2
	ldrh r2, [r0]
	subs r2, r1, r2
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #2
	bl Div
	adds r4, r4, r0
_0806F8B4:
	adds r0, r4, #0
	b _0806F8F4
	.align 2, 0
_0806F8B8: .4byte 0x00000366
_0806F8BC:
	movs r0, #4
	bl FUN_0807a8c0
	cmp r0, #0x62
	ble _0806F8D8
	ldr r4, _0806F8D4 @ =0x00000A78
	adds r0, r5, r4
	ldrh r0, [r0]
	adds r0, #0xa
	lsls r0, r0, #1
	b _0806F8F4
	.align 2, 0
_0806F8D4: .4byte 0x00000A78
_0806F8D8:
	movs r0, #4
	bl FUN_0807a8c0
	movs r1, #0xa
	bl Div
	ldr r1, _0806F8FC @ =0x00000A78
	adds r2, r5, r1
	subs r0, #8
	lsls r1, r0, #2
	adds r1, r1, r0
	ldrh r2, [r2]
	adds r4, r1, r2
	lsls r0, r4, #1
_0806F8F4:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0806F8FC: .4byte 0x00000A78

	thumb_func_start FUN_0806f900
FUN_0806f900: @ 0x0806F900
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	bl FUN_0806f7bc
	adds r6, r0, #0
	movs r7, #0
	ldr r0, _0806F95C @ =0x00000A9C
	adds r4, r5, r0
_0806F910:
	ldr r1, [r4]
	cmp r1, #0
	beq _0806F91E
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r6, r0
_0806F91E:
	adds r4, #4
	adds r7, #1
	cmp r7, #2
	ble _0806F910
	movs r1, #0x80
	lsls r1, r1, #0xc
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0806F952
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r2, #0x12
	adds r1, r5, r2
	ldrh r1, [r1]
	bl Div
	adds r6, r6, r0
_0806F952:
	adds r0, r6, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0806F95C: .4byte 0x00000A9C

	thumb_func_start FUN_0806f960
FUN_0806f960: @ 0x0806F960
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r7, #0
	movs r6, #0
	ldr r0, _0806F98C @ =0x00000AA8
	adds r4, r5, r0
_0806F96C:
	ldr r1, [r4]
	cmp r1, #0
	beq _0806F97A
	adds r0, r5, #0
	bl _call_via_r1
	orrs r7, r0
_0806F97A:
	adds r4, #4
	adds r6, #1
	cmp r6, #2
	ble _0806F96C
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0806F98C: .4byte 0x00000AA8

	thumb_func_start dark_django_0806f990
dark_django_0806f990: @ 0x0806F990
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	movs r1, #0x10
	ldrh r0, [r5, #0xa]
	ands r0, r1
	cmp r0, #0
	bne _0806F9A2
	b _0806FAC6
_0806F9A2:
	ldr r6, [r7, #0x4c]
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_08236524
	movs r4, #0
_0806F9AE:
	lsls r1, r4, #2
	ldr r2, _0806FA80 @ =0x00000AB4
	adds r0, r6, r2
	adds r0, r0, r1
	ldr r3, [r0]
	cmp r3, #0
	beq _0806F9CC
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl _call_via_r3
	ldrh r1, [r5, #0x3e]
	adds r1, r1, r0
	strh r1, [r5, #0x3e]
_0806F9CC:
	adds r4, #1
	cmp r4, #2
	ble _0806F9AE
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0806FAC6
	ldr r2, _0806FA84 @ =0x00000A8D
	adds r0, r6, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _0806FA22
	adds r0, r6, #0
	bl FUN_08060e1c
	cmp r0, #0
	beq _0806FA22
	adds r2, r5, #0
	adds r2, #0x43
	ldrb r1, [r2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0806FA22
	ldrh r1, [r5, #0x3e]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsrs r0, r0, #1
	strh r0, [r5, #0x3e]
	ldrh r1, [r5, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0806FA22
	ldrb r1, [r2]
	movs r0, #8
	orrs r0, r1
	strb r0, [r2]
_0806FA22:
	movs r1, #0xf8
	lsls r1, r1, #4
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _0806FAC6
	movs r1, #0x89
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0806FAC6
	ldr r3, _0806FA88 @ =0x030046A0
	ldr r1, [r3]
	movs r2, #0xaa
	lsls r2, r2, #2
	adds r1, r1, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, [r3]
	adds r2, r0, r2
	movs r1, #0xab
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	ldr r2, [r2]
	cmp r2, r0
	bne _0806FA94
	ldr r0, _0806FA8C @ =0x00000302
	bl PlaySound_082406e0
	ldr r2, _0806FA90 @ =0x0000095E
	adds r1, r6, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r6, r0
	movs r2, #0x40
	movs r0, #0x40
	b _0806FAB4
	.align 2, 0
_0806FA80: .4byte 0x00000AB4
_0806FA84: .4byte 0x00000A8D
_0806FA88: .4byte 0x030046A0
_0806FA8C: .4byte 0x00000302
_0806FA90: .4byte 0x0000095E
_0806FA94:
	asrs r0, r1, #1
	cmp r2, r0
	bne _0806FABC
	ldr r0, _0806FACC @ =0x00000302
	bl PlaySound_082406e0
	ldr r2, _0806FAD0 @ =0x0000095E
	adds r1, r6, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r6, r0
	movs r2, #0x20
	movs r0, #0x20
_0806FAB4:
	strh r0, [r1]
	ldr r1, _0806FAD4 @ =0x0000044B
	adds r0, r6, r1
	strb r2, [r0]
_0806FABC:
	movs r2, #0x89
	lsls r2, r2, #3
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
_0806FAC6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806FACC: .4byte 0x00000302
_0806FAD0: .4byte 0x0000095E
_0806FAD4: .4byte 0x0000044B

	thumb_func_start FUN_0806fad8
FUN_0806fad8: @ 0x0806FAD8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _0806FB58 @ =0x000009C8
	adds r6, r4, r0
	ldr r1, _0806FB5C @ =0x00000A68
	adds r2, r4, r1
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _0806FB60 @ =0x00000A6A
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #0xe6
	strh r0, [r1]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	adds r2, #0x22
	adds r1, r4, r2
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_0806f900
	mov r8, r0
	adds r0, r4, #0
	bl FUN_0806f960
	adds r5, r0, #0
	ldr r1, _0806FB64 @ =0x00000A7E
	adds r0, r4, r1
	ldrh r7, [r0]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _0806FB70
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0xc
	strh r0, [r1]
	ldr r2, _0806FB68 @ =0x00000A84
	adds r1, r4, r2
	movs r0, #5
	strh r0, [r1]
	ldr r0, _0806FB6C @ =0x00000A88
	adds r1, r4, r0
	movs r0, #3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #0xb
	orrs r5, r0
	b _0806FBBC
	.align 2, 0
_0806FB58: .4byte 0x000009C8
_0806FB5C: .4byte 0x00000A68
_0806FB60: .4byte 0x00000A6A
_0806FB64: .4byte 0x00000A7E
_0806FB68: .4byte 0x00000A84
_0806FB6C: .4byte 0x00000A88
_0806FB70:
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0806FBA4
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0xc
	strh r0, [r1]
	ldr r2, _0806FB9C @ =0x00000A84
	adds r1, r4, r2
	movs r0, #5
	strh r0, [r1]
	ldr r0, _0806FBA0 @ =0x00000A88
	adds r1, r4, r0
	movs r0, #3
	b _0806FBBA
	.align 2, 0
_0806FB9C: .4byte 0x00000A84
_0806FBA0: .4byte 0x00000A88
_0806FBA4:
	movs r1, #0xa8
	lsls r1, r1, #4
	adds r0, r4, r1
	movs r1, #8
	strh r1, [r0]
	ldr r2, _0806FC18 @ =0x00000A84
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _0806FC1C @ =0x00000A88
	adds r1, r4, r0
	movs r0, #4
_0806FBBA:
	strh r0, [r1]
_0806FBBC:
	adds r1, r6, #0
	adds r1, #0xc5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _0806FBD6
	adds r1, r0, #0
	movs r0, #1
	lsls r0, r1
	orrs r5, r0
	adds r0, r4, #0
	bl FUN_08064be4
_0806FBD6:
	adds r0, r6, #0
	adds r0, #0x48
	adds r1, r6, #0
	adds r1, #0xb4
	ldrh r2, [r1]
	str r5, [sp]
	str r7, [sp, #4]
	mov r1, r8
	movs r3, #1
	bl FUN_082364f8
	adds r0, r6, #0
	adds r0, #0xc4
	ldrb r0, [r0]
	adds r1, r6, #0
	adds r1, #0x8a
	movs r2, #0
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xc2
	movs r1, #0
	strh r2, [r0]
	movs r2, #0x89
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r1, [r0]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806FC18: .4byte 0x00000A84
_0806FC1C: .4byte 0x00000A88

	thumb_func_start FUN_0806fc20
FUN_0806fc20: @ 0x0806FC20
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	mov ip, r0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r7, r3, #0
	ldr r2, _0806FC68 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0806FC6C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0806FC70 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	adds r3, r0, #0
	adds r3, #0x70
	ldr r2, _0806FC74 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	adds r6, r2, #0
	cmp r0, #0
	blt _0806FC78
	asrs r1, r0, #0xc
	b _0806FC7E
	.align 2, 0
_0806FC68: .4byte 0x030046B8
_0806FC6C: .4byte 0x000003FF
_0806FC70: .4byte 0x0203B400
_0806FC74: .4byte 0x085B0A08
_0806FC78:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0806FC7E:
	ldrh r0, [r4]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldrh r1, [r4, #2]
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp]
	movs r0, #0xff
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	cmp r0, #0
	blt _0806FCA4
	asrs r0, r0, #0xc
	b _0806FCAA
_0806FCA4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806FCAA:
	ldrh r1, [r4, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0806FCD8 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	movs r0, #0xff
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _0806FCDC
	asrs r0, r0, #0xc
	b _0806FCE2
	.align 2, 0
_0806FCD8: .4byte 0xFFFF0000
_0806FCDC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806FCE2:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _0806FD06
	asrs r0, r0, #0xc
	b _0806FD0C
_0806FD06:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806FD0C:
	rsbs r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _0806FD54 @ =0xFFFF0000
	add r2, sp, #8
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #4]
	cmp r7, #0
	beq _0806FD42
	ldrh r0, [r2]
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #8]
	ldrh r0, [r2, #4]
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r2, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [r2, #4]
_0806FD42:
	mov r0, ip
	mov r1, sp
	ldr r3, [sp, #0x24]
	bl FUN_08061d20
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806FD54: .4byte 0xFFFF0000

	thumb_func_start FUN_0806fd58
FUN_0806fd58: @ 0x0806FD58
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, _0806FD88 @ =0x000009C8
	adds r5, r7, r0
	ldr r1, _0806FD8C @ =0x00000A8A
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0806FD96
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0806FD90
	movs r0, #0xe3
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _0806FD96
	.align 2, 0
_0806FD88: .4byte 0x000009C8
_0806FD8C: .4byte 0x00000A8A
_0806FD90:
	ldr r0, _0806FDD8 @ =0x0000038B
	bl PlaySound_082406e0
_0806FD96:
	adds r0, r5, #0
	adds r0, #0xc2
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	adds r2, r5, #0
	adds r2, #0xbc
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r0
	ldrh r2, [r2]
	cmp r1, r2
	bls _0806FDB2
	b _0806FECC
_0806FDB2:
	ldr r4, _0806FDDC @ =0x000002E7
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806FDE0
	adds r0, r5, #0
	adds r0, #0xc4
	ldrb r1, [r0]
	mov r0, r8
	ldrh r2, [r0]
	adds r0, r5, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	muls r0, r2, r0
	subs r1, r1, r0
	movs r3, #0x90
	lsls r3, r3, #1
	adds r6, r1, r3
	b _0806FDFE
	.align 2, 0
_0806FDD8: .4byte 0x0000038B
_0806FDDC: .4byte 0x000002E7
_0806FDE0:
	adds r2, r5, #0
	adds r2, #0xc4
	mov r4, r8
	ldrh r1, [r4]
	adds r0, r5, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	muls r0, r1, r0
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r2, [r2]
	adds r0, r0, r2
	adds r6, r0, #0
	subs r6, #0x20
_0806FDFE:
	movs r0, #0xff
	ands r6, r0
	ldr r2, _0806FE24 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r4, r2, #0
	cmp r0, #0
	blt _0806FE28
	asrs r1, r0, #0xc
	b _0806FE2E
	.align 2, 0
_0806FE24: .4byte 0x085B0A08
_0806FE28:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0806FE2E:
	adds r3, r5, #0
	adds r3, #0xa0
	ldrh r0, [r3]
	adds r0, r0, r1
	adds r2, r5, #0
	adds r2, #0x98
	strh r0, [r2]
	adds r0, r5, #0
	adds r0, #0xa2
	ldrh r0, [r0]
	adds r1, r5, #0
	adds r1, #0x9a
	strh r0, [r1]
	lsls r0, r6, #1
	adds r0, r0, r4
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #5
	mov sb, r3
	adds r3, r2, #0
	cmp r0, #0
	blt _0806FE62
	asrs r2, r0, #0xc
	b _0806FE68
_0806FE62:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0806FE68:
	adds r0, r5, #0
	adds r0, #0xa4
	ldrh r0, [r0]
	adds r0, r0, r2
	adds r1, r5, #0
	adds r1, #0x9c
	strh r0, [r1]
	adds r4, r5, #0
	adds r4, #0x48
	adds r0, r4, #0
	adds r1, r3, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	adds r2, r5, #0
	adds r2, #0xc5
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _0806FEC2
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	mov r0, r8
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0806FEC2
	ldr r1, _0806FEC8 @ =0x000002E7
	adds r0, r7, r1
	ldrb r3, [r0]
	movs r0, #0
	ldrsb r0, [r2, r0]
	str r0, [sp]
	adds r0, r7, #0
	mov r1, sb
	adds r2, r6, #0
	bl FUN_0806fc20
_0806FEC2:
	movs r0, #0
	b _0806FECE
	.align 2, 0
_0806FEC8: .4byte 0x000002E7
_0806FECC:
	movs r0, #1
_0806FECE:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0806fedc
FUN_0806fedc: @ 0x0806FEDC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _0806FEFE
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0806FF02
_0806FEFE:
	movs r6, #0x30
	b _0806FF04
_0806FF02:
	movs r6, #0x40
_0806FF04:
	ldr r3, _0806FF18 @ =0x0000037D
	adds r4, r5, r3
	ldrb r0, [r4]
	cmp r0, #1
	beq _0806FF58
	cmp r0, #1
	bgt _0806FF1C
	cmp r0, #0
	beq _0806FF28
	b _08070096
	.align 2, 0
_0806FF18: .4byte 0x0000037D
_0806FF1C:
	cmp r0, #4
	beq _0806FFB0
	cmp r0, #6
	bne _0806FF26
	b _08070034
_0806FF26:
	b _08070096
_0806FF28:
	adds r0, r5, #0
	bl FUN_0806f780
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x15
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_08060a24
	cmp r0, #0
	bne _0806FF4C
	b _08070096
_0806FF4C:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	bl FUN_08060b84
	b _08070096
_0806FF58:
	adds r0, r5, #0
	bl FUN_0806f780
	adds r0, r5, #0
	bl FUN_0806f738
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x16
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0806FFA0
	adds r0, r5, #0
	bl FUN_0806fad8
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl FUN_08060b84
	b _08070096
_0806FFA0:
	ldr r0, _0806FFAC @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _08070096
	.align 2, 0
_0806FFAC: .4byte 0x0000037E
_0806FFB0:
	ldr r2, _0807002C @ =0x000003D1
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0806FFD2
	ldr r0, _08070030 @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_0806FFD2:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r4, r5, r1
	ldrb r0, [r4]
	movs r1, #0x17
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_08060a24
	ldrb r0, [r4]
	cmp r0, #1
	bne _08070016
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #2
	bne _08070016
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _08070016
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x2c
	adds r0, r5, #0
	bl FUN_0806185c
_08070016:
	adds r0, r5, #0
	bl FUN_0806fd58
	cmp r0, #0
	beq _08070096
	adds r0, r5, #0
	movs r1, #3
	movs r2, #6
	bl FUN_08060b84
	b _08070096
	.align 2, 0
_0807002C: .4byte 0x000003D1
_08070030: .4byte 0x00000A76
_08070034:
	ldr r3, _08070068 @ =0x000003D1
	adds r0, r5, r3
	movs r3, #0
	strb r3, [r0]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08070056
	ldr r2, _0807006C @ =0x00000A76
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
_08070056:
	ldr r0, _0807006C @ =0x00000A76
	adds r2, r5, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _08070070
	strb r3, [r2]
	strb r3, [r4]
	b _08070096
	.align 2, 0
_08070068: .4byte 0x000003D1
_0807006C: .4byte 0x00000A76
_08070070:
	ldr r1, _0807009C @ =0x0000037E
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	ldr r3, _080700A0 @ =0x00000A88
	adds r0, r5, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r0, [r0]
	cmp r1, r0
	blo _08070096
	movs r0, #0
	strb r0, [r2]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_08070096:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807009C: .4byte 0x0000037E
_080700A0: .4byte 0x00000A88

	thumb_func_start FUN_080700a4
FUN_080700a4: @ 0x080700A4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	ldr r2, _080700C8 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080700CC
	asrs r1, r0, #0xc
	b _080700D2
	.align 2, 0
_080700C8: .4byte 0x085B0A08
_080700CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080700D2:
	ldrh r0, [r4]
	adds r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r4, #2]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r0, r6
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080700F2
	asrs r1, r0, #0xc
	b _080700F8
_080700F2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080700F8:
	ldrh r0, [r4, #4]
	adds r0, r0, r1
	strh r0, [r5, #4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08070104
FUN_08070104: @ 0x08070104
	push {lr}
	adds r3, r1, #0
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	lsrs r1, r1, #4
	cmp r1, #1
	beq _0807011C
	cmp r1, #2
	beq _08070120
	b _08070124
_0807011C:
	ldrb r0, [r3, #4]
	b _08070122
_08070120:
	ldrb r0, [r3]
_08070122:
	subs r2, r2, r0
_08070124:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0807012c
FUN_0807012c: @ 0x0807012C
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r1, #0
	adds r3, r2, #0
	mov r6, sp
	mov r0, sp
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_080700a4
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _08070168
	cmp r1, #0
	blt _08070168
	ldr r0, _08070170 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _08070168
	ldr r0, _08070174 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0807017C
_08070168:
	movs r4, #0
	ldr r2, _08070178 @ =0x030046A4
	b _0807018A
	.align 2, 0
_08070170: .4byte 0x030046A8
_08070174: .4byte 0x030046AC
_08070178: .4byte 0x030046A4
_0807017C:
	ldr r2, _08070198 @ =0x030046A4
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_0807018A:
	ldr r0, [r2]
	ldr r2, [r0, #4]
	cmp r2, #0
	bne _0807019C
	movs r0, #0
	b _080701A2
	.align 2, 0
_08070198: .4byte 0x030046A4
_0807019C:
	lsls r0, r4, #2
	adds r0, #0xc
	adds r0, r2, r0
_080701A2:
	mov r5, sp
	mov r1, sp
	bl FUN_08070104
	movs r2, #2
	ldrsh r1, [r5, r2]
	cmp r0, r1
	ble _080701B6
	movs r0, #1
	b _080701D8
_080701B6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080701D6
	adds r0, #4
	mov r1, sp
	bl FUN_08070104
	movs r2, #2
	ldrsh r1, [r5, r2]
	cmp r0, r1
	ble _080701D6
	movs r0, #2
	b _080701D8
_080701D6:
	movs r0, #0
_080701D8:
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080701e0
FUN_080701e0: @ 0x080701E0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _08070240 @ =0x000009C8
	adds r4, r5, r0
	ldr r1, _08070244 @ =0x00000A68
	adds r2, r5, r1
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _08070248 @ =0x00000A6A
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #0x96
	strh r0, [r1]
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	ldr r6, _0807024C @ =0x00000A8C
	adds r1, r5, r6
	strb r0, [r1]
	ldr r2, _08070250 @ =0x085B0A08
	ldrb r0, [r1]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0xcc
	muls r0, r1, r0
	adds r6, r2, #0
	cmp r0, #0
	blt _08070254
	asrs r1, r0, #0xc
	b _0807025A
	.align 2, 0
_08070240: .4byte 0x000009C8
_08070244: .4byte 0x00000A68
_08070248: .4byte 0x00000A6A
_0807024C: .4byte 0x00000A8C
_08070250: .4byte 0x085B0A08
_08070254:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0807025A:
	adds r3, r4, #0
	adds r3, #0xa0
	ldrh r0, [r3]
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x98
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xa2
	ldrh r0, [r0]
	adds r1, #2
	strh r0, [r1]
	adds r2, r4, #0
	adds r2, #0xc4
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r6, #0
	ldrsh r1, [r0, r6]
	movs r0, #0xcc
	muls r0, r1, r0
	mov r8, r3
	mov sl, r2
	cmp r0, #0
	blt _08070290
	asrs r1, r0, #0xc
	b _08070296
_08070290:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08070296:
	adds r0, r4, #0
	adds r0, #0xa4
	ldrh r0, [r0]
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x9c
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_0806f900
	str r0, [sp, #8]
	adds r0, r5, #0
	bl FUN_0806f960
	mov sb, r0
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #1
	bne _080702CA
	movs r0, #0x80
	lsls r0, r0, #0xb
	mov r1, sb
	orrs r1, r0
	mov sb, r1
_080702CA:
	adds r0, r4, #0
	adds r0, #0xb4
	ldrh r0, [r0]
	str r0, [sp, #0xc]
	mov r2, sl
	ldrb r1, [r2]
	mov r0, r8
	movs r2, #0xe0
	bl FUN_0807012c
	adds r7, r0, #0
	cmp r7, #0
	beq _080703B2
	adds r0, r4, #0
	adds r0, #0xc5
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r3, r0, #0
	cmp r1, #2
	beq _080702F6
	cmp r1, #4
	bne _08070352
_080702F6:
	cmp r7, #2
	bne _08070352
	adds r1, r4, #0
	adds r1, #0xba
	movs r0, #0x1b
	strh r0, [r1]
	ldrb r0, [r6]
	cmp r0, #1
	beq _0807031A
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r6, #0xde
	lsls r6, r6, #2
	adds r0, r5, r6
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	beq _08070336
_0807031A:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r1, #4
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbe
	strh r7, [r0]
	adds r1, #4
	movs r0, #3
	strh r0, [r1]
	b _08070476
_08070336:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbc
	strh r2, [r0]
	adds r1, #6
	movs r0, #3
	strh r0, [r1]
	adds r1, #2
	movs r0, #6
	strh r0, [r1]
	b _08070476
_08070352:
	adds r1, r4, #0
	adds r1, #0xba
	movs r6, #0
	movs r0, #0x1a
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _0807037A
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	beq _08070396
_0807037A:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbc
	strh r6, [r0]
	adds r1, #6
	movs r0, #2
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xc0
	strh r6, [r0]
	b _08070476
_08070396:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbc
	strh r2, [r0]
	adds r1, #6
	movs r0, #3
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xc0
	strh r2, [r0]
	b _08070476
_080703B2:
	mov r3, sl
	ldrb r1, [r3]
	movs r2, #0xa8
	lsls r2, r2, #1
	mov r0, r8
	bl FUN_0807012c
	cmp r0, #0
	beq _0807041C
	adds r1, r4, #0
	adds r1, #0xba
	movs r0, #0x1b
	strh r0, [r1]
	ldrb r0, [r6]
	cmp r0, #1
	beq _080703E4
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r6, #0xde
	lsls r6, r6, #2
	adds r0, r5, r6
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	beq _08070400
_080703E4:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r1, #4
	movs r0, #2
	strh r0, [r1]
	adds r1, #2
	movs r0, #3
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xc0
	strh r7, [r0]
	b _08070472
_08070400:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r1, #4
	movs r0, #2
	strh r0, [r1]
	adds r1, #2
	movs r0, #7
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xc0
	strh r2, [r0]
	b _08070472
_0807041C:
	adds r1, r4, #0
	adds r1, #0xba
	movs r0, #0x1c
	strh r0, [r1]
	ldrb r0, [r6]
	cmp r0, #1
	beq _0807043C
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08070458
_0807043C:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbc
	movs r1, #4
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r1, r4, #0
	adds r1, #0xc0
	movs r0, #1
	b _08070470
_08070458:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r1, #4
	movs r0, #4
	strh r0, [r1]
	adds r1, #2
	movs r0, #7
	strh r0, [r1]
	adds r1, #2
	movs r0, #5
_08070470:
	strh r0, [r1]
_08070472:
	adds r3, r4, #0
	adds r3, #0xc5
_08070476:
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	blt _08070490
	adds r1, r0, #0
	movs r0, #1
	lsls r0, r1
	mov r3, sb
	orrs r3, r0
	mov sb, r3
	adds r0, r5, #0
	bl FUN_08064be4
_08070490:
	adds r0, r4, #0
	adds r0, #0x48
	mov r6, sb
	str r6, [sp]
	adds r1, r4, #0
	adds r1, #0xb6
	ldrh r1, [r1]
	str r1, [sp, #4]
	ldr r1, [sp, #8]
	ldr r2, [sp, #0xc]
	movs r3, #2
	bl FUN_082364f8
	mov r1, sl
	ldrb r0, [r1]
	adds r1, r4, #0
	adds r1, #0x8a
	movs r2, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xc2
	movs r1, #0
	strh r2, [r0]
	movs r2, #0x89
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r1, [r0]
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080704d8
FUN_080704d8: @ 0x080704D8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov ip, r0
	adds r7, r2, #0
	str r3, [sp, #0x10]
	ldr r0, _08070590 @ =0x0203B400
	mov sb, r0
	ldr r6, _08070594 @ =0x030046B8
	ldr r3, [r6]
	adds r3, #1
	ldr r2, _08070598 @ =0x000003FF
	mov r8, r2
	ands r3, r2
	str r3, [r6]
	lsls r0, r3, #1
	add r0, sb
	ldrh r0, [r0]
	movs r5, #0x1f
	ands r0, r5
	ldrh r2, [r1]
	adds r0, r0, r2
	subs r0, #0xf
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _0807059C @ =0xFFFF0000
	mov sl, r2
	ldr r4, [sp]
	ands r4, r2
	orrs r4, r0
	str r4, [sp]
	adds r3, #1
	mov r0, r8
	ands r3, r0
	str r3, [r6]
	lsls r0, r3, #1
	add r0, sb
	ldrh r0, [r0]
	ands r0, r5
	ldrh r2, [r1, #2]
	adds r0, r0, r2
	subs r0, #0xf
	lsls r0, r0, #0x10
	ldr r2, _080705A0 @ =0x0000FFFF
	ands r2, r4
	orrs r2, r0
	str r2, [sp]
	adds r3, #1
	mov r0, r8
	ands r3, r0
	str r3, [r6]
	lsls r0, r3, #1
	add r0, sb
	ldrh r0, [r0]
	ands r0, r5
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	subs r0, #0xf
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	mov r2, sl
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	adds r3, #1
	mov r0, r8
	ands r3, r0
	str r3, [r6]
	lsls r3, r3, #1
	add r3, sb
	ldrh r0, [r3]
	movs r1, #3
	ands r0, r1
	adds r3, r0, #3
	ldr r2, _080705A4 @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080705A8
	asrs r0, r0, #0xc
	b _080705AE
	.align 2, 0
_08070590: .4byte 0x0203B400
_08070594: .4byte 0x030046B8
_08070598: .4byte 0x000003FF
_0807059C: .4byte 0xFFFF0000
_080705A0: .4byte 0x0000FFFF
_080705A4: .4byte 0x085B0A08
_080705A8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080705AE:
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	movs r0, #0xff
	ands r0, r7
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	cmp r0, #0
	blt _080705CC
	asrs r0, r0, #0xc
	b _080705D2
_080705CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080705D2:
	rsbs r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _08070600 @ =0xFFFF0000
	add r2, sp, #8
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #4]
	mov r0, ip
	mov r1, sp
	ldr r3, [sp, #0x10]
	bl FUN_08061d20
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08070600: .4byte 0xFFFF0000

	thumb_func_start FUN_08070604
FUN_08070604: @ 0x08070604
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, _08070634 @ =0x000009C8
	adds r5, r7, r0
	ldr r1, _08070638 @ =0x00000A8A
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08070646
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08070640
	ldr r0, _0807063C @ =0x0000038F
	bl PlaySound_082406e0
	b _08070646
	.align 2, 0
_08070634: .4byte 0x000009C8
_08070638: .4byte 0x00000A8A
_0807063C: .4byte 0x0000038F
_08070640:
	ldr r0, _0807068C @ =0x0000038D
	bl PlaySound_082406e0
_08070646:
	adds r0, r5, #0
	adds r0, #0xc2
	adds r1, r5, #0
	adds r1, #0xbc
	ldrh r2, [r0]
	mov sb, r0
	mov sl, r1
	ldrh r3, [r1]
	cmp r2, r3
	bhs _08070726
	subs r0, #0xa
	ldrh r1, [r0]
	mov r2, sb
	ldrh r0, [r2]
	muls r0, r1, r0
	adds r4, r0, #0
	adds r4, #0xcc
	ldr r2, _08070690 @ =0x085B0A08
	adds r3, r5, #0
	adds r3, #0xc4
	ldrb r0, [r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	mov r8, r3
	cmp r0, #0
	blt _08070694
	asrs r1, r0, #0xc
	b _0807069A
	.align 2, 0
_0807068C: .4byte 0x0000038D
_08070690: .4byte 0x085B0A08
_08070694:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0807069A:
	adds r0, r5, #0
	adds r0, #0xa0
	ldrh r0, [r0]
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x98
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xa2
	ldrh r0, [r0]
	adds r3, r5, #0
	adds r3, #0x9a
	strh r0, [r3]
	mov r3, r8
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	adds r6, r1, #0
	cmp r0, #0
	blt _080706CC
	asrs r2, r0, #0xc
	b _080706D2
_080706CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080706D2:
	adds r0, r5, #0
	adds r0, #0xa4
	ldrh r0, [r0]
	adds r0, r0, r2
	adds r1, r5, #0
	adds r1, #0x9c
	strh r0, [r1]
	adds r4, r5, #0
	adds r4, #0x48
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	adds r3, r5, #0
	adds r3, #0xc5
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r1, r5, #0
	adds r1, #0xbe
	str r1, [sp]
	cmp r0, #0
	bge _08070708
	b _08070804
_08070708:
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	mov r0, r8
	ldrb r2, [r0]
	ldrb r3, [r3]
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	adds r0, r7, #0
	adds r1, r6, #0
	bl FUN_080704d8
	b _08070804
_08070726:
	mov r1, sb
	ldrh r2, [r1]
	mov r0, sl
	ldrh r3, [r0]
	adds r1, r5, #0
	adds r1, #0xbe
	ldrh r0, [r1]
	adds r0, r3, r0
	str r1, [sp]
	cmp r2, r0
	bge _08070804
	adds r0, r5, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	muls r0, r3, r0
	adds r4, r0, #0
	adds r4, #0xcc
	ldr r2, _0807076C @ =0x085B0A08
	adds r3, r5, #0
	adds r3, #0xc4
	ldrb r0, [r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	mov r8, r3
	cmp r0, #0
	blt _08070770
	asrs r1, r0, #0xc
	b _08070776
	.align 2, 0
_0807076C: .4byte 0x085B0A08
_08070770:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08070776:
	adds r0, r5, #0
	adds r0, #0xa0
	ldrh r0, [r0]
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x98
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xa2
	ldrh r0, [r0]
	adds r3, r5, #0
	adds r3, #0x9a
	strh r0, [r3]
	mov r3, r8
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	adds r6, r1, #0
	cmp r0, #0
	blt _080707A8
	asrs r2, r0, #0xc
	b _080707AE
_080707A8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080707AE:
	adds r0, r5, #0
	adds r0, #0xa4
	ldrh r0, [r0]
	adds r0, r0, r2
	adds r1, r5, #0
	adds r1, #0x9c
	strh r0, [r1]
	adds r4, r5, #0
	adds r4, #0x48
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	adds r3, r5, #0
	adds r3, #0xc5
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	blt _08070804
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	mov r0, sb
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08070804
	mov r1, r8
	ldrb r2, [r1]
	ldrb r3, [r3]
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	adds r0, r7, #0
	adds r1, r6, #0
	bl FUN_080704d8
_08070804:
	mov r2, sb
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r3, sl
	ldrh r1, [r3]
	ldr r3, [sp]
	ldrh r2, [r3]
	adds r3, r5, #0
	adds r3, #0xc0
	adds r1, r1, r2
	ldrh r3, [r3]
	adds r1, r1, r3
	cmp r0, r1
	bge _0807082A
	movs r0, #0
	b _08070832
_0807082A:
	movs r0, #0
	mov r1, sb
	strh r0, [r1]
	movs r0, #1
_08070832:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08070844
FUN_08070844: @ 0x08070844
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _08070866
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0807086A
_08070866:
	movs r7, #0x30
	b _0807086C
_0807086A:
	movs r7, #0x40
_0807086C:
	ldr r1, _08070884 @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #6
	bls _08070878
	b _08070AD4
_08070878:
	lsls r0, r0, #2
	ldr r1, _08070888 @ =_0807088C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08070884: .4byte 0x0000037D
_08070888: .4byte _0807088C
_0807088C: @ jump table
	.4byte _080708A8 @ case 0
	.4byte _080708D8 @ case 1
	.4byte _08070AD4 @ case 2
	.4byte _08070AD4 @ case 3
	.4byte _08070940 @ case 4
	.4byte _08070A14 @ case 5
	.4byte _08070A68 @ case 6
_080708A8:
	adds r0, r5, #0
	bl FUN_0806f780
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x18
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r7, #0
	bl FUN_08060a24
	cmp r0, #0
	bne _080708CC
	b _08070AD4
_080708CC:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	bl FUN_08060b84
	b _08070AD4
_080708D8:
	adds r0, r5, #0
	bl FUN_0806f780
	adds r0, r5, #0
	bl FUN_0806f738
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x19
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _0807092C @ =0x0000037E
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #6
	bls _08070930
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08070930
	adds r0, r5, #0
	bl FUN_080701e0
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl FUN_08060b84
	b _08070AD4
	.align 2, 0
_0807092C: .4byte 0x0000037E
_08070930:
	ldr r2, _0807093C @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _08070AD4
	.align 2, 0
_0807093C: .4byte 0x0000037E
_08070940:
	ldr r0, _0807099C @ =0x000003D1
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r4, r5, r1
	ldrb r0, [r4]
	ldr r2, _080709A0 @ =0x00000A82
	adds r6, r5, r2
	ldrh r1, [r6]
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r7, #0
	bl FUN_08060a24
	ldrb r0, [r4]
	cmp r0, #1
	bne _080709FE
	ldrh r0, [r6]
	cmp r0, #0x1c
	bne _080709A4
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #1
	bne _080709FE
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _080709FE
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x2c
	adds r0, r5, #0
	movs r3, #0
	bl FUN_08061970
	b _080709FE
	.align 2, 0
_0807099C: .4byte 0x000003D1
_080709A0: .4byte 0x00000A82
_080709A4:
	cmp r0, #0x1b
	bne _080709D2
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #1
	bne _080709FE
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _080709FE
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x2c
	adds r0, r5, #0
	movs r3, #1
	bl FUN_08061970
	b _080709FE
_080709D2:
	cmp r0, #0x1a
	bne _080709FE
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _080709FE
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #1
	bne _080709FE
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x2c
	adds r0, r5, #0
	movs r3, #2
	bl FUN_08061970
_080709FE:
	adds r0, r5, #0
	bl FUN_08070604
	cmp r0, #0
	beq _08070AD4
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl FUN_08060b84
	b _08070AD4
_08070A14:
	ldr r2, _08070A60 @ =0x000003D1
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08070A36
	ldr r2, _08070A64 @ =0x00000A76
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
_08070A36:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x18
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r7, #0
	bl FUN_08060a24
	cmp r0, #0
	beq _08070AD4
	adds r0, r5, #0
	movs r1, #3
	movs r2, #6
	bl FUN_08060b84
	b _08070AD4
	.align 2, 0
_08070A60: .4byte 0x000003D1
_08070A64: .4byte 0x00000A76
_08070A68:
	ldr r2, _08070AA0 @ =0x000003D1
	adds r0, r5, r2
	movs r2, #0
	strb r2, [r0]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08070A8A
	ldr r0, _08070AA4 @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_08070A8A:
	ldr r1, _08070AA4 @ =0x00000A76
	adds r4, r5, r1
	ldrb r6, [r4]
	cmp r6, #0
	beq _08070AAC
	strb r2, [r4]
	ldr r1, _08070AA8 @ =0x0000037D
	adds r0, r5, r1
	strb r2, [r0]
	b _08070AD4
	.align 2, 0
_08070AA0: .4byte 0x000003D1
_08070AA4: .4byte 0x00000A76
_08070AA8: .4byte 0x0000037D
_08070AAC:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x19
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r7, #0
	bl FUN_08060a24
	cmp r0, #0
	beq _08070AD4
	strb r6, [r4]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_08070AD4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08070adc
FUN_08070adc: @ 0x08070ADC
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _08070B58 @ =0x000009C8
	adds r5, r4, r0
	ldr r1, _08070B5C @ =0x00000A68
	adds r2, r4, r1
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _08070B60 @ =0x00000A6A
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #0xe6
	strh r0, [r1]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	adds r2, #0x22
	adds r1, r4, r2
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_0806f900
	adds r7, r0, #0
	adds r0, r4, #0
	bl FUN_0806f960
	adds r6, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _08070B6C
	movs r2, #0xa8
	lsls r2, r2, #4
	adds r1, r4, r2
	movs r0, #0x1d
	strh r0, [r1]
	ldr r0, _08070B64 @ =0x00000A88
	adds r1, r4, r0
	movs r0, #7
	strh r0, [r1]
	adds r2, #4
	adds r1, r4, r2
	movs r0, #4
	strh r0, [r1]
	ldr r0, _08070B68 @ =0x00000A86
	adds r1, r4, r0
	movs r0, #6
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #0xb
	orrs r6, r0
	b _08070BCA
	.align 2, 0
_08070B58: .4byte 0x000009C8
_08070B5C: .4byte 0x00000A68
_08070B60: .4byte 0x00000A6A
_08070B64: .4byte 0x00000A88
_08070B68: .4byte 0x00000A86
_08070B6C:
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08070BA8
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x1d
	strh r0, [r1]
	ldr r2, _08070BA0 @ =0x00000A88
	adds r1, r4, r2
	movs r0, #7
	strh r0, [r1]
	ldr r0, _08070BA4 @ =0x00000A84
	adds r1, r4, r0
	movs r0, #4
	strh r0, [r1]
	subs r2, #2
	adds r1, r4, r2
	movs r0, #6
	b _08070BC8
	.align 2, 0
_08070BA0: .4byte 0x00000A88
_08070BA4: .4byte 0x00000A84
_08070BA8:
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x13
	strh r0, [r1]
	ldr r2, _08070C24 @ =0x00000A88
	adds r1, r4, r2
	movs r0, #0xb
	strh r0, [r1]
	ldr r0, _08070C28 @ =0x00000A84
	adds r1, r4, r0
	movs r0, #6
	strh r0, [r1]
	subs r2, #2
	adds r1, r4, r2
	movs r0, #9
_08070BC8:
	strh r0, [r1]
_08070BCA:
	adds r1, r5, #0
	adds r1, #0xc5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _08070BE4
	adds r1, r0, #0
	movs r0, #1
	lsls r0, r1
	orrs r6, r0
	adds r0, r4, #0
	bl FUN_08064be4
_08070BE4:
	adds r0, r5, #0
	adds r0, #0x48
	adds r1, r5, #0
	adds r1, #0xb4
	ldrh r2, [r1]
	str r6, [sp]
	adds r1, #2
	ldrh r1, [r1]
	str r1, [sp, #4]
	adds r1, r7, #0
	movs r3, #4
	bl FUN_082364f8
	adds r0, r5, #0
	adds r0, #0xc4
	ldrb r0, [r0]
	adds r1, r5, #0
	adds r1, #0x8a
	movs r2, #0
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0xc2
	movs r1, #0
	strh r2, [r0]
	movs r2, #0x89
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r1, [r0]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08070C24: .4byte 0x00000A88
_08070C28: .4byte 0x00000A84

	thumb_func_start FUN_08070c2c
FUN_08070c2c: @ 0x08070C2C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	str r0, [sp, #0x10]
	adds r7, r2, #0
	mov ip, r3
	ldr r0, _08070CE8 @ =0x0203B400
	mov sb, r0
	ldr r6, _08070CEC @ =0x030046B8
	ldr r3, [r6]
	adds r3, #1
	ldr r2, _08070CF0 @ =0x000003FF
	mov r8, r2
	ands r3, r2
	str r3, [r6]
	lsls r0, r3, #1
	add r0, sb
	ldrh r0, [r0]
	movs r5, #0x1f
	ands r0, r5
	ldrh r2, [r1]
	adds r0, r0, r2
	subs r0, #0xf
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _08070CF4 @ =0xFFFF0000
	mov sl, r2
	ldr r4, [sp]
	ands r4, r2
	orrs r4, r0
	str r4, [sp]
	adds r3, #1
	mov r0, r8
	ands r3, r0
	str r3, [r6]
	lsls r0, r3, #1
	add r0, sb
	ldrh r0, [r0]
	ands r0, r5
	ldrh r2, [r1, #2]
	adds r0, r0, r2
	subs r0, #0xf
	lsls r0, r0, #0x10
	ldr r2, _08070CF8 @ =0x0000FFFF
	ands r2, r4
	orrs r2, r0
	str r2, [sp]
	adds r3, #1
	mov r0, r8
	ands r3, r0
	str r3, [r6]
	lsls r0, r3, #1
	add r0, sb
	ldrh r0, [r0]
	ands r0, r5
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	subs r0, #0xf
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	mov r2, sl
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	adds r3, #1
	mov r0, r8
	ands r3, r0
	str r3, [r6]
	lsls r3, r3, #1
	add r3, sb
	ldrh r0, [r3]
	movs r1, #3
	ands r0, r1
	adds r3, r0, #5
	ldr r2, _08070CFC @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _08070D00
	asrs r0, r0, #0xc
	b _08070D06
	.align 2, 0
_08070CE8: .4byte 0x0203B400
_08070CEC: .4byte 0x030046B8
_08070CF0: .4byte 0x000003FF
_08070CF4: .4byte 0xFFFF0000
_08070CF8: .4byte 0x0000FFFF
_08070CFC: .4byte 0x085B0A08
_08070D00:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08070D06:
	lsls r2, r0, #0x10
	ldr r1, _08070D28 @ =0x0000FFFF
	ldr r0, [sp, #8]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #8]
	movs r0, #0xff
	ands r0, r7
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	cmp r0, #0
	blt _08070D2C
	asrs r0, r0, #0xc
	b _08070D32
	.align 2, 0
_08070D28: .4byte 0x0000FFFF
_08070D2C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08070D32:
	rsbs r3, r0, #0
	mov r0, ip
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _08070D4E
	asrs r0, r0, #0xc
	b _08070D54
_08070D4E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08070D54:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08070D7C @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	movs r0, #0xff
	mov r2, ip
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _08070D80
	asrs r0, r0, #0xc
	b _08070D86
	.align 2, 0
_08070D7C: .4byte 0xFFFF0000
_08070D80:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08070D86:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _08070DB0 @ =0xFFFF0000
	add r2, sp, #8
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #4]
	ldr r0, [sp, #0x10]
	mov r1, sp
	ldr r3, [sp, #0x34]
	bl FUN_08061d20
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08070DB0: .4byte 0xFFFF0000

	thumb_func_start FUN_08070db4
FUN_08070db4: @ 0x08070DB4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r6, r0, #0
	ldr r0, _08070DE4 @ =0x000009C8
	adds r5, r6, r0
	ldr r1, _08070DE8 @ =0x00000A8A
	adds r3, r6, r1
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	ldr r2, _08070DEC @ =0x00000A88
	adds r1, r6, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r4, [r1]
	cmp r0, r4
	bhi _08070DF0
_08070DDE:
	movs r0, #0
	b _0807105A
	.align 2, 0
_08070DE4: .4byte 0x000009C8
_08070DE8: .4byte 0x00000A8A
_08070DEC: .4byte 0x00000A88
_08070DF0:
	ldrh r2, [r3]
	ldrh r0, [r1]
	ldr r7, _08070E1C @ =0x00000A84
	adds r1, r6, r7
	ldrh r1, [r1]
	adds r1, r0, r1
	cmp r2, r1
	ble _08070E02
	b _0807101C
_08070E02:
	cmp r2, r1
	bne _08070E26
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08070E20
	movs r0, #0xe4
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _08070E26
	.align 2, 0
_08070E1C: .4byte 0x00000A84
_08070E20:
	ldr r0, _08070E6C @ =0x0000038E
	bl PlaySound_082406e0
_08070E26:
	adds r4, r5, #0
	adds r4, #0xc2
	ldrh r1, [r4]
	adds r3, r5, #0
	adds r3, #0xc0
	ldrh r0, [r3]
	subs r1, r1, r0
	adds r0, r5, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	muls r1, r0, r1
	movs r0, #0xa8
	lsls r0, r0, #1
	subs r7, r0, r1
	movs r1, #0xff
	ands r7, r1
	ldr r2, _08070E70 @ =0x085B0A08
	adds r0, r7, #0
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r8, r0
	movs r0, #0xfa
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	mov sb, r4
	mov r8, r3
	mov ip, r2
	cmp r0, #0
	blt _08070E74
	asrs r1, r0, #0xc
	b _08070E7A
	.align 2, 0
_08070E6C: .4byte 0x0000038E
_08070E70: .4byte 0x085B0A08
_08070E74:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08070E7A:
	adds r2, r5, #0
	adds r2, #0xa2
	ldrh r0, [r2]
	adds r0, r0, r1
	adds r3, r5, #0
	adds r3, #0x9a
	strh r0, [r3]
	adds r0, r7, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, ip
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0xfa
	muls r0, r1, r0
	str r2, [sp, #0xc]
	cmp r0, #0
	blt _08070EA6
	asrs r0, r0, #0xc
	b _08070EAC
_08070EA6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08070EAC:
	mov sl, r0
	adds r2, r5, #0
	adds r2, #0xc4
	ldrb r0, [r2]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, ip
	movs r4, #0
	ldrsh r0, [r0, r4]
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	adds r4, r2, #0
	cmp r0, #0
	blt _08070ED2
	asrs r1, r0, #0xc
	b _08070ED8
_08070ED2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08070ED8:
	adds r2, r5, #0
	adds r2, #0xa0
	ldrh r0, [r2]
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x98
	strh r0, [r1]
	ldrb r0, [r4]
	lsls r0, r0, #1
	add r0, ip
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r3, sl
	muls r3, r0, r3
	adds r0, r3, #0
	mov sl, r2
	mov ip, r1
	cmp r0, #0
	blt _08070F02
	asrs r1, r0, #0xc
	b _08070F08
_08070F02:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08070F08:
	adds r2, r5, #0
	adds r2, #0xa4
	ldrh r0, [r2]
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x9c
	strh r0, [r1]
	mov r0, sb
	ldrh r1, [r0]
	mov r3, r8
	ldrh r0, [r3]
	adds r0, #2
	str r2, [sp, #0x10]
	cmp r1, r0
	ble _08070F40
	adds r1, r5, #0
	adds r1, #0xc5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _08070F40
	ldrb r3, [r4]
	str r0, [sp]
	adds r0, r6, #0
	mov r1, ip
	adds r2, r7, #0
	bl FUN_08070c2c
_08070F40:
	mov r7, sb
	ldrh r3, [r7]
	mov r1, r8
	ldrh r0, [r1]
	adds r2, r5, #0
	adds r2, #0xbc
	ldrh r1, [r2]
	adds r0, r0, r1
	subs r0, #2
	adds r7, r2, #0
	cmp r3, r0
	bgt _08070F5A
	b _08070DDE
_08070F5A:
	movs r3, #0xaa
	ldr r2, _08070F7C @ =0x085B0A08
	ldrb r0, [r4]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	mov ip, r2
	cmp r0, #0
	blt _08070F80
	asrs r0, r0, #0xc
	b _08070F86
	.align 2, 0
_08070F7C: .4byte 0x085B0A08
_08070F80:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08070F86:
	mov r1, sl
	ldrh r2, [r1]
	adds r2, r2, r0
	lsls r2, r2, #0x10
	mov r1, r8
	ldrh r0, [r1]
	ldrh r1, [r7]
	adds r0, r0, r1
	mov r7, sb
	ldrh r1, [r7]
	subs r0, r0, r1
	adds r0, #1
	movs r1, #0x5a
	muls r0, r1, r0
	ldr r1, [sp, #0xc]
	ldrh r1, [r1]
	adds r0, r0, r1
	ldr r7, _08070FC8 @ =0xFFFFFEFC
	adds r0, r0, r7
	lsls r0, r0, #0x10
	lsrs r2, r2, #0x10
	orrs r2, r0
	str r2, [sp, #4]
	ldrb r0, [r4]
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _08070FCC
	asrs r0, r0, #0xc
	b _08070FD2
	.align 2, 0
_08070FC8: .4byte 0xFFFFFEFC
_08070FCC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08070FD2:
	ldr r2, [sp, #0x10]
	ldrh r1, [r2]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08071018 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	adds r0, r5, #0
	adds r0, #0xc5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08070FFE
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r6, #0x20]
	orrs r0, r1
	str r0, [r6, #0x20]
_08070FFE:
	movs r3, #0xa1
	lsls r3, r3, #4
	adds r0, r6, r3
	add r1, sp, #4
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	adds r0, #0x48
	bl FUN_08236400
	b _08070DDE
	.align 2, 0
_08071018: .4byte 0xFFFF0000
_0807101C:
	ldr r4, _0807104C @ =0x00000A86
	adds r0, r6, r4
	ldrh r0, [r0]
	adds r0, r1, r0
	cmp r2, r0
	bgt _08071054
	ldr r7, _08071050 @ =0x00000A8D
	adds r0, r6, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08071040
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r6, #0x20]
	orrs r0, r1
	str r0, [r6, #0x20]
_08071040:
	movs r1, #0xa1
	lsls r1, r1, #4
	adds r0, r6, r1
	bl FUN_08236400
	b _08070DDE
	.align 2, 0
_0807104C: .4byte 0x00000A86
_08071050: .4byte 0x00000A8D
_08071054:
	movs r0, #0
	strh r0, [r3]
	movs r0, #1
_0807105A:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0807106c
FUN_0807106c: @ 0x0807106C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _0807108E
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08071092
_0807108E:
	movs r5, #0x30
	b _08071094
_08071092:
	movs r5, #0x40
_08071094:
	ldr r1, _080710A8 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080710DC
	cmp r0, #1
	bgt _080710AC
	cmp r0, #0
	beq _080710B6
	b _08071210
	.align 2, 0
_080710A8: .4byte 0x0000037D
_080710AC:
	cmp r0, #4
	beq _08071134
	cmp r0, #5
	beq _08071170
	b _08071210
_080710B6:
	adds r0, r4, #0
	bl FUN_0806f780
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0x1d
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_08060a24
	cmp r0, #0
	bne _080710DA
	b _08071210
_080710DA:
	b _080711EE
_080710DC:
	adds r0, r4, #0
	bl FUN_0806f780
	adds r0, r4, #0
	bl FUN_0806f738
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x1e
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_08060a24
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08071124
	adds r0, r4, #0
	bl FUN_08070adc
	adds r0, r4, #0
	movs r1, #3
	movs r2, #4
	bl FUN_08060b84
	b _08071210
_08071124:
	ldr r0, _08071130 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _08071210
	.align 2, 0
_08071130: .4byte 0x0000037E
_08071134:
	ldr r2, _0807116C @ =0x000003D1
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x1f
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_08060a24
	adds r0, r4, #0
	bl FUN_08070db4
	cmp r0, #0
	beq _08071210
	adds r0, r4, #0
	movs r1, #3
	movs r2, #5
	bl FUN_08060b84
	b _08071210
	.align 2, 0
_0807116C: .4byte 0x000003D1
_08071170:
	ldr r2, _080711FC @ =0x000003D1
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08071192
	ldr r2, _08071200 @ =0x00000A76
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
_08071192:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080711C4
	adds r0, r4, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #5
	bne _080711C4
	adds r0, r4, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _080711C4
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x2c
	adds r0, r4, #0
	bl FUN_08061a98
_080711C4:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x1f
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_08060a24
	cmp r0, #0
	beq _08071210
	ldr r2, _08071200 @ =0x00000A76
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08071204
	movs r0, #0
	strb r0, [r1]
_080711EE:
	adds r0, r4, #0
	movs r1, #3
	movs r2, #1
	bl FUN_08060b84
	b _08071210
	.align 2, 0
_080711FC: .4byte 0x000003D1
_08071200: .4byte 0x00000A76
_08071204:
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_08071210:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08071218
FUN_08071218: @ 0x08071218
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _080712B4 @ =0x00000A68
	adds r2, r4, r0
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080712B8 @ =0x00000A6A
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #0xe6
	movs r3, #0
	mov sb, r3
	movs r2, #0
	mov r8, r2
	strh r0, [r1]
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	ldr r1, _080712BC @ =0x00000A8C
	adds r6, r4, r1
	strb r0, [r6]
	adds r0, r4, #0
	bl FUN_0806f900
	adds r5, r0, #0
	ldr r2, _080712C0 @ =0x000009F4
	adds r0, r4, r2
	movs r1, #0x2d
	bl FUN_0822b20c
	movs r3, #0xa1
	lsls r3, r3, #4
	adds r0, r4, r3
	ldr r2, _080712C4 @ =0x00000A7C
	adds r1, r4, r2
	ldrh r2, [r1]
	mov r3, r8
	str r3, [sp]
	ldr r3, _080712C8 @ =0x00000A7E
	adds r1, r4, r3
	ldrh r1, [r1]
	str r1, [sp, #4]
	adds r1, r5, #0
	movs r3, #8
	bl FUN_082364f8
	ldrb r1, [r6]
	ldr r2, _080712CC @ =0x00000A52
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080712D0 @ =0x00000A8A
	adds r0, r4, r3
	mov r1, r8
	strh r1, [r0]
	movs r2, #0x89
	lsls r2, r2, #3
	adds r4, r4, r2
	mov r3, sb
	strb r3, [r4]
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080712B4: .4byte 0x00000A68
_080712B8: .4byte 0x00000A6A
_080712BC: .4byte 0x00000A8C
_080712C0: .4byte 0x000009F4
_080712C4: .4byte 0x00000A7C
_080712C8: .4byte 0x00000A7E
_080712CC: .4byte 0x00000A52
_080712D0: .4byte 0x00000A8A

	thumb_func_start FUN_080712d4
FUN_080712d4: @ 0x080712D4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _0807131C @ =0x000009C8
	adds r5, r6, r0
	ldr r1, _08071320 @ =0x00000A8A
	adds r4, r6, r1
	ldrh r0, [r4]
	cmp r0, #0
	bne _080712EC
	ldr r0, _08071324 @ =0x00000391
	bl PlaySound_082406e0
_080712EC:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bhi _0807139A
	ldr r2, _08071328 @ =0x085B0A08
	ldr r3, _0807132C @ =0x00000A8C
	adds r0, r6, r3
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x64
	muls r0, r1, r0
	cmp r0, #0
	blt _08071330
	asrs r1, r0, #0xc
	b _08071336
	.align 2, 0
_0807131C: .4byte 0x000009C8
_08071320: .4byte 0x00000A8A
_08071324: .4byte 0x00000391
_08071328: .4byte 0x085B0A08
_0807132C: .4byte 0x00000A8C
_08071330:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08071336:
	adds r0, r5, #0
	adds r0, #0xa0
	ldrh r0, [r0]
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x98
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xa2
	ldrh r0, [r0]
	adds r1, #2
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xc4
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x64
	muls r0, r1, r0
	cmp r0, #0
	blt _08071368
	asrs r1, r0, #0xc
	b _0807136E
_08071368:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0807136E:
	adds r0, r5, #0
	adds r0, #0xa4
	ldrh r0, [r0]
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x9c
	strh r0, [r1]
	movs r3, #0xa1
	lsls r3, r3, #4
	adds r4, r6, r3
	movs r0, #0xa6
	lsls r0, r0, #4
	adds r1, r6, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	movs r0, #0
	b _080713A0
_0807139A:
	movs r0, #0
	strh r0, [r4]
	movs r0, #1
_080713A0:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080713a8
FUN_080713a8: @ 0x080713A8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080713C4 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #6
	bls _080713B8
	b _08071590
_080713B8:
	lsls r0, r0, #2
	ldr r1, _080713C8 @ =_080713CC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080713C4: .4byte 0x0000037D
_080713C8: .4byte _080713CC
_080713CC: @ jump table
	.4byte _080713E8 @ case 0
	.4byte _08071424 @ case 1
	.4byte _08071590 @ case 2
	.4byte _08071590 @ case 3
	.4byte _08071478 @ case 4
	.4byte _080714D0 @ case 5
	.4byte _08071554 @ case 6
_080713E8:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x20
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	bne _08071406
	b _08071590
_08071406:
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08071454
	adds r0, r4, #0
	movs r1, #3
	movs r2, #1
	bl FUN_08060b84
	b _08071590
_08071424:
	adds r0, r4, #0
	bl FUN_0806f738
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x21
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08071466
_08071454:
	adds r0, r4, #0
	bl FUN_08071218
	adds r0, r4, #0
	movs r1, #3
	movs r2, #4
	bl FUN_08060b84
	b _08071590
_08071466:
	ldr r0, _08071474 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _08071590
	.align 2, 0
_08071474: .4byte 0x0000037E
_08071478:
	ldr r0, _080714C8 @ =0x000003D1
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x22
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080714B2
	ldr r0, _080714CC @ =0x00000A76
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_080714B2:
	adds r0, r4, #0
	bl FUN_080712d4
	cmp r0, #0
	beq _08071590
	adds r0, r4, #0
	movs r1, #3
	movs r2, #5
	bl FUN_08060b84
	b _08071590
	.align 2, 0
_080714C8: .4byte 0x000003D1
_080714CC: .4byte 0x00000A76
_080714D0:
	ldr r1, _08071520 @ =0x000003D1
	adds r0, r4, r1
	movs r5, #0
	strb r5, [r0]
	subs r1, #0x79
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x21
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08071508
	ldr r0, _08071524 @ =0x00000A76
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_08071508:
	ldr r1, _08071524 @ =0x00000A76
	adds r2, r4, r1
	ldrb r0, [r2]
	cmp r0, #0
	beq _0807152C
	strb r5, [r2]
	ldr r0, _08071528 @ =0x0000037D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _08071590
	.align 2, 0
_08071520: .4byte 0x000003D1
_08071524: .4byte 0x00000A76
_08071528: .4byte 0x0000037D
_0807152C:
	ldr r0, _08071550 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #9
	bls _08071590
	movs r0, #0
	strb r0, [r2]
	adds r0, r4, #0
	movs r1, #3
	movs r2, #6
	bl FUN_08060b84
	b _08071590
	.align 2, 0
_08071550: .4byte 0x0000037E
_08071554:
	ldr r0, _08071598 @ =0x000003D1
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x20
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _0807159C @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _08071590
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_08071590:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08071598: .4byte 0x000003D1
_0807159C: .4byte 0x0000037E

	thumb_func_start gun_080715a0
gun_080715a0: @ 0x080715A0
	push {r4, r5, r6, lr}
	sub sp, #0x30
	adds r5, r0, #0
	ldr r1, _080715BC @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #7
	bls _080715B2
	b _08071AD8
_080715B2:
	lsls r0, r0, #2
	ldr r1, _080715C0 @ =_080715C4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080715BC: .4byte 0x0000037D
_080715C0: .4byte _080715C4
_080715C4: @ jump table
	.4byte _080715E4 @ case 0
	.4byte _0807163E @ case 1
	.4byte _08071740 @ case 2
	.4byte _08071800 @ case 3
	.4byte _080718A8 @ case 4
	.4byte _080718FC @ case 5
	.4byte _08071A28 @ case 6
	.4byte _08071AA4 @ case 7
_080715E4:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x23
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	bne _08071602
	b _08071AD8
_08071602:
	movs r1, #0x80
	lsls r1, r1, #0x16
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0807161E
	movs r0, #0xa9
	lsls r0, r0, #4
	adds r1, r5, r0
	movs r0, #0x1e
	b _08071626
_0807161E:
	movs r2, #0xa9
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r0, #0x3c
_08071626:
	strh r0, [r1]
	movs r0, #0x89
	lsls r0, r0, #3
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	bl FUN_08060b84
	b _08071AD8
_0807163E:
	ldr r1, _080716B4 @ =0x0000037E
	adds r4, r5, r1
	ldrh r0, [r4]
	cmp r0, #0
	bne _0807164E
	ldr r0, _080716B8 @ =0x000001F7
	bl PlaySound_082406e0
_0807164E:
	adds r0, r5, #0
	bl FUN_0806f738
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #6
	bhi _0807167C
	b _08071AD8
_0807167C:
	ldr r0, _080716BC @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x95
	lsls r1, r1, #2
	adds r2, r0, r1
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r4, #0x32
	cmp r0, #0
	bne _08071692
	movs r4, #1
_08071692:
	ldr r0, _080716C0 @ =0x00000A8F
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	ldr r0, _080716C4 @ =0x000003E6
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, r4
	bge _080716C8
	movs r0, #0xd5
	b _080718E6
	.align 2, 0
_080716B4: .4byte 0x0000037E
_080716B8: .4byte 0x000001F7
_080716BC: .4byte 0x030046A0
_080716C0: .4byte 0x00000A8F
_080716C4: .4byte 0x000003E6
_080716C8:
	ldr r0, _080716F4 @ =0x00000A92
	adds r1, r5, r0
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080716F8
	movs r0, #0xcd
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl FUN_08060b84
	b _08071716
	.align 2, 0
_080716F4: .4byte 0x00000A92
_080716F8:
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bne _0807170C
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl FUN_08060b84
	b _08071716
_0807170C:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #2
	bl FUN_08060b84
_08071716:
	movs r1, #0x20
	str r1, [sp]
	movs r0, #0x2c
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	movs r0, #0x14
	str r0, [sp, #0x10]
	movs r0, #3
	str r0, [sp, #0x14]
	str r4, [sp, #0x18]
	movs r0, #0
	str r0, [sp, #0x1c]
	adds r0, r5, #0
	movs r1, #0xe6
	movs r2, #0xb4
	movs r3, #0
	bl FUN_08080be8
	b _08071AD8
_08071740:
	adds r0, r5, #0
	bl FUN_0806f738
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _080717E8 @ =0x00000A92
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r1, _080717EC @ =0x0000037E
	adds r4, r5, r1
	ldrh r0, [r4]
	cmp r0, #6
	bne _0807177A
	movs r0, #0xfc
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0807177A:
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0807178E
	b _080718E4
_0807178E:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	movs r2, #0xa9
	lsls r2, r2, #4
	adds r1, r5, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	bhs _080717A6
	b _08071AD8
_080717A6:
	ldr r0, _080717F0 @ =0x00000A8F
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _080717F4 @ =0x000003E6
	adds r1, r5, r2
	movs r0, #0x1e
	strh r0, [r1]
	ldr r0, _080717F8 @ =0x0000095E
	adds r1, r5, r0
	ldr r0, _080717FC @ =0x00000121
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r0, #0x24
	strh r0, [r1]
	movs r0, #4
	bl FUN_0807a8c0
	cmp r0, #0x62
	ble _08071878
	movs r0, #0xfc
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #3
	movs r2, #3
	bl FUN_08060b84
	b _08071AD8
	.align 2, 0
_080717E8: .4byte 0x00000A92
_080717EC: .4byte 0x0000037E
_080717F0: .4byte 0x00000A8F
_080717F4: .4byte 0x000003E6
_080717F8: .4byte 0x0000095E
_080717FC: .4byte 0x00000121
_08071800:
	adds r0, r5, #0
	bl FUN_0806f738
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _0807188C @ =0x00000A92
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080718E4
	ldr r2, _08071890 @ =0x0000037E
	adds r0, r5, r2
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	movs r2, #0xa9
	lsls r2, r2, #4
	adds r0, r5, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r0, [r0]
	cmp r1, r0
	bhs _08071856
	b _08071AD8
_08071856:
	ldr r0, _08071894 @ =0x00000A8F
	adds r1, r5, r0
	movs r0, #2
	strb r0, [r1]
	ldr r2, _08071898 @ =0x000003E6
	adds r1, r5, r2
	movs r0, #0x3c
	strh r0, [r1]
	ldr r0, _0807189C @ =0x0000095E
	adds r1, r5, r0
	ldr r0, _080718A0 @ =0x00000121
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r0, #0x24
	strh r0, [r1]
_08071878:
	ldr r0, _080718A4 @ =0x000001F9
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl FUN_08060b84
	b _08071AD8
	.align 2, 0
_0807188C: .4byte 0x00000A92
_08071890: .4byte 0x0000037E
_08071894: .4byte 0x00000A8F
_08071898: .4byte 0x000003E6
_0807189C: .4byte 0x0000095E
_080718A0: .4byte 0x00000121
_080718A4: .4byte 0x000001F9
_080718A8:
	adds r0, r5, #0
	bl FUN_0806f738
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _080718F8 @ =0x00000A92
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080718E4
	b _08071AD8
_080718E4:
	movs r0, #0xcd
_080718E6:
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl FUN_08060b84
	b _08071AD8
	.align 2, 0
_080718F8: .4byte 0x00000A92
_080718FC:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x25
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0807192E
	ldr r2, _080719A8 @ =0x00000A76
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
_0807192E:
	ldr r0, _080719AC @ =0x000003E6
	adds r6, r5, r0
	ldrh r0, [r6]
	cmp r0, #0
	beq _08071A04
	cmp r0, #5
	bls _0807197A
	ldr r3, _080719B0 @ =0xFFFF0000
	ldr r1, _080719B4 @ =0x0000FFFF
	movs r0, #0
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x24]
	ands r0, r3
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x28]
	ands r0, r3
	movs r4, #0x20
	orrs r0, r4
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x28]
	add r2, sp, #0x28
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r4
	str r0, [r2, #4]
	adds r0, r5, #0
	adds r0, #0x2c
	movs r1, #3
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	add r1, sp, #0x20
	movs r3, #1
	bl FUN_080dbd08
_0807197A:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldrh r3, [r6]
	ldr r2, _080719B8 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080719BC
	asrs r0, r0, #0xc
	b _080719C2
	.align 2, 0
_080719A8: .4byte 0x00000A76
_080719AC: .4byte 0x000003E6
_080719B0: .4byte 0xFFFF0000
_080719B4: .4byte 0x0000FFFF
_080719B8: .4byte 0x085B0A08
_080719BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080719C2:
	rsbs r0, r0, #0
	strh r0, [r5, #0x34]
	ldr r1, _080719E0 @ =0x000003E6
	adds r0, r5, r1
	ldrh r1, [r0]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080719E4
	asrs r0, r0, #0xc
	b _080719EA
	.align 2, 0
_080719E0: .4byte 0x000003E6
_080719E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080719EA:
	rsbs r0, r0, #0
	strh r0, [r5, #0x38]
	ldr r0, _08071A00 @ =0x000003E6
	adds r2, r5, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	b _08071AD8
	.align 2, 0
_08071A00: .4byte 0x000003E6
_08071A04:
	ldr r2, _08071A24 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _08071AD8
	adds r0, r5, #0
	movs r1, #3
	movs r2, #6
	bl FUN_08060b84
	b _08071AD8
	.align 2, 0
_08071A24: .4byte 0x0000037E
_08071A28:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08071A5A
	ldr r0, _08071A74 @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_08071A5A:
	ldr r1, _08071A74 @ =0x00000A76
	adds r2, r5, r1
	ldrb r0, [r2]
	cmp r0, #0
	beq _08071A7C
	movs r0, #0
	strb r0, [r2]
	ldr r2, _08071A78 @ =0x0000037D
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _08071AD8
	.align 2, 0
_08071A74: .4byte 0x00000A76
_08071A78: .4byte 0x0000037D
_08071A7C:
	ldr r0, _08071AA0 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls _08071AD8
	movs r0, #0
	strb r0, [r2]
	adds r0, r5, #0
	movs r1, #3
	movs r2, #7
	bl FUN_08060b84
	b _08071AD8
	.align 2, 0
_08071AA0: .4byte 0x0000037E
_08071AA4:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x23
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _08071B08 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _08071AD8
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_08071AD8:
	ldr r0, _08071B0C @ =0x00000A92
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0xe
	bls _08071AF8
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _08071AF4
	adds r0, r5, #0
	bl FUN_08066794
_08071AF4:
	movs r0, #0
	strh r0, [r4]
_08071AF8:
	ldr r2, _08071B10 @ =0x00000951
	adds r1, r5, r2
	movs r0, #8
	strb r0, [r1]
	add sp, #0x30
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08071B08: .4byte 0x0000037E
_08071B0C: .4byte 0x00000A92
_08071B10: .4byte 0x00000951

	thumb_func_start FUN_08071b14
FUN_08071b14: @ 0x08071B14
	push {r4, r5, r6, lr}
	sub sp, #0x30
	adds r5, r0, #0
	ldr r1, _08071B30 @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #7
	bls _08071B26
	b _08071FFC
_08071B26:
	lsls r0, r0, #2
	ldr r1, _08071B34 @ =_08071B38
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08071B30: .4byte 0x0000037D
_08071B34: .4byte _08071B38
_08071B38: @ jump table
	.4byte _08071B58 @ case 0
	.4byte _08071BB2 @ case 1
	.4byte _08071C96 @ case 2
	.4byte _08071D40 @ case 3
	.4byte _08071DD8 @ case 4
	.4byte _08071E1E @ case 5
	.4byte _08071F4C @ case 6
	.4byte _08071FC8 @ case 7
_08071B58:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x26
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	bne _08071B76
	b _08071FFC
_08071B76:
	movs r1, #0x80
	lsls r1, r1, #0x16
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08071B92
	movs r0, #0xa9
	lsls r0, r0, #4
	adds r1, r5, r0
	movs r0, #0x1e
	b _08071B9A
_08071B92:
	movs r2, #0xa9
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r0, #0x3c
_08071B9A:
	strh r0, [r1]
	movs r0, #0x89
	lsls r0, r0, #3
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	bl FUN_08060b84
	b _08071FFC
_08071BB2:
	ldr r1, _08071C10 @ =0x0000037E
	adds r4, r5, r1
	ldrh r0, [r4]
	cmp r0, #0
	bne _08071BC2
	ldr r0, _08071C14 @ =0x000001F7
	bl PlaySound_082406e0
_08071BC2:
	adds r0, r5, #0
	bl FUN_0806f738
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x27
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #6
	bhi _08071BF0
	b _08071FFC
_08071BF0:
	ldr r0, _08071C18 @ =0x00000A8F
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	ldr r2, _08071C1C @ =0x000003E6
	adds r1, r5, r2
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0x13
	bhi _08071C20
	movs r0, #0xd5
	b _08071E0E
	.align 2, 0
_08071C10: .4byte 0x0000037E
_08071C14: .4byte 0x000001F7
_08071C18: .4byte 0x00000A8F
_08071C1C: .4byte 0x000003E6
_08071C20:
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08071C46
	movs r0, #0xfb
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl FUN_08060b84
	b _08071C6E
_08071C46:
	movs r1, #0x80
	lsls r1, r1, #0xd
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08071C64
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl FUN_08060b84
	b _08071C6E
_08071C64:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #2
	bl FUN_08060b84
_08071C6E:
	movs r1, #0x20
	str r1, [sp]
	movs r0, #0x2e
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r2, #0
	str r2, [sp, #0xc]
	movs r1, #0x14
	str r1, [sp, #0x10]
	movs r0, #0x11
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	str r2, [sp, #0x1c]
	adds r0, r5, #0
	movs r1, #0xc8
	movs r2, #0xaa
	movs r3, #8
	bl FUN_08080be8
	b _08071FFC
_08071C96:
	adds r0, r5, #0
	bl FUN_0806f738
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x27
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _08071D2C @ =0x0000037E
	adds r4, r5, r2
	ldrh r0, [r4]
	cmp r0, #6
	bne _08071CC6
	movs r0, #0xfa
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08071CC6:
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08071CDA
	b _08071E0A
_08071CDA:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	movs r2, #0xa9
	lsls r2, r2, #4
	adds r1, r5, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	bhs _08071CF2
	b _08071FFC
_08071CF2:
	ldr r0, _08071D30 @ =0x00000A8F
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _08071D34 @ =0x000003E6
	adds r1, r5, r2
	movs r0, #0x1e
	strh r0, [r1]
	ldr r0, _08071D38 @ =0x0000095E
	adds r1, r5, r0
	ldr r0, _08071D3C @ =0x00000121
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r0, #0x24
	strh r0, [r1]
	movs r0, #4
	bl FUN_0807a8c0
	cmp r0, #0x62
	ble _08071DAE
	adds r0, r5, #0
	movs r1, #3
	movs r2, #3
	bl FUN_08060b84
	b _08071FFC
	.align 2, 0
_08071D2C: .4byte 0x0000037E
_08071D30: .4byte 0x00000A8F
_08071D34: .4byte 0x000003E6
_08071D38: .4byte 0x0000095E
_08071D3C: .4byte 0x00000121
_08071D40:
	adds r0, r5, #0
	bl FUN_0806f738
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x27
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08071E0A
	ldr r1, _08071DC0 @ =0x0000037E
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	movs r2, #0xa9
	lsls r2, r2, #4
	adds r0, r5, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r0, [r0]
	cmp r1, r0
	bhs _08071D8C
	b _08071FFC
_08071D8C:
	ldr r0, _08071DC4 @ =0x00000A8F
	adds r1, r5, r0
	movs r0, #2
	strb r0, [r1]
	ldr r2, _08071DC8 @ =0x000003E6
	adds r1, r5, r2
	movs r0, #0x3c
	strh r0, [r1]
	ldr r0, _08071DCC @ =0x0000095E
	adds r1, r5, r0
	ldr r0, _08071DD0 @ =0x00000121
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r0, #0x24
	strh r0, [r1]
_08071DAE:
	ldr r0, _08071DD4 @ =0x000001F5
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl FUN_08060b84
	b _08071FFC
	.align 2, 0
_08071DC0: .4byte 0x0000037E
_08071DC4: .4byte 0x00000A8F
_08071DC8: .4byte 0x000003E6
_08071DCC: .4byte 0x0000095E
_08071DD0: .4byte 0x00000121
_08071DD4: .4byte 0x000001F5
_08071DD8:
	adds r0, r5, #0
	bl FUN_0806f738
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x27
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08071E0A
	b _08071FFC
_08071E0A:
	movs r0, #0xfb
	lsls r0, r0, #1
_08071E0E:
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl FUN_08060b84
	b _08071FFC
_08071E1E:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x28
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08071E50
	ldr r0, _08071ECC @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_08071E50:
	ldr r1, _08071ED0 @ =0x000003E6
	adds r6, r5, r1
	ldrh r0, [r6]
	cmp r0, #0
	beq _08071F28
	cmp r0, #5
	bls _08071E9C
	ldr r3, _08071ED4 @ =0xFFFF0000
	ldr r1, _08071ED8 @ =0x0000FFFF
	movs r0, #0
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x24]
	ands r0, r3
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x28]
	ands r0, r3
	movs r4, #0x20
	orrs r0, r4
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x28]
	add r2, sp, #0x28
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r4
	str r0, [r2, #4]
	adds r0, r5, #0
	adds r0, #0x2c
	movs r1, #3
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	add r1, sp, #0x20
	movs r3, #1
	bl FUN_080dbd08
_08071E9C:
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldrh r3, [r6]
	ldr r2, _08071EDC @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _08071EE0
	asrs r0, r0, #0xc
	b _08071EE6
	.align 2, 0
_08071ECC: .4byte 0x00000A76
_08071ED0: .4byte 0x000003E6
_08071ED4: .4byte 0xFFFF0000
_08071ED8: .4byte 0x0000FFFF
_08071EDC: .4byte 0x085B0A08
_08071EE0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08071EE6:
	rsbs r0, r0, #0
	strh r0, [r5, #0x34]
	ldr r1, _08071F04 @ =0x000003E6
	adds r0, r5, r1
	ldrh r1, [r0]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _08071F08
	asrs r0, r0, #0xc
	b _08071F0E
	.align 2, 0
_08071F04: .4byte 0x000003E6
_08071F08:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08071F0E:
	rsbs r0, r0, #0
	strh r0, [r5, #0x38]
	ldr r0, _08071F24 @ =0x000003E6
	adds r2, r5, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	b _08071FFC
	.align 2, 0
_08071F24: .4byte 0x000003E6
_08071F28:
	ldr r2, _08071F48 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _08071FFC
	adds r0, r5, #0
	movs r1, #3
	movs r2, #6
	bl FUN_08060b84
	b _08071FFC
	.align 2, 0
_08071F48: .4byte 0x0000037E
_08071F4C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x27
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08071F7E
	ldr r0, _08071F98 @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_08071F7E:
	ldr r1, _08071F98 @ =0x00000A76
	adds r2, r5, r1
	ldrb r0, [r2]
	cmp r0, #0
	beq _08071FA0
	movs r0, #0
	strb r0, [r2]
	ldr r2, _08071F9C @ =0x0000037D
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _08071FFC
	.align 2, 0
_08071F98: .4byte 0x00000A76
_08071F9C: .4byte 0x0000037D
_08071FA0:
	ldr r0, _08071FC4 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls _08071FFC
	movs r0, #0
	strb r0, [r2]
	adds r0, r5, #0
	movs r1, #3
	movs r2, #7
	bl FUN_08060b84
	b _08071FFC
	.align 2, 0
_08071FC4: .4byte 0x0000037E
_08071FC8:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x26
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _0807200C @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _08071FFC
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_08071FFC:
	ldr r0, _08072010 @ =0x00000951
	adds r1, r5, r0
	movs r0, #4
	strb r0, [r1]
	add sp, #0x30
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807200C: .4byte 0x0000037E
_08072010: .4byte 0x00000951

	thumb_func_start FUN_08072014
FUN_08072014: @ 0x08072014
	push {r4, r5, r6, lr}
	sub sp, #0x38
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #3
	beq _08072030
	adds r0, r5, #0
	movs r1, #3
	movs r2, #0
	bl FUN_08060b84
_08072030:
	ldr r2, _08072048 @ =0x0000037D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #8
	bls _0807203C
	b _080725EE
_0807203C:
	lsls r0, r0, #2
	ldr r1, _0807204C @ =_08072050
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08072048: .4byte 0x0000037D
_0807204C: .4byte _08072050
_08072050: @ jump table
	.4byte _08072074 @ case 0
	.4byte _080720A8 @ case 1
	.4byte _08072168 @ case 2
	.4byte _08072214 @ case 3
	.4byte _080722A0 @ case 4
	.4byte _0807232C @ case 5
	.4byte _08072388 @ case 6
	.4byte _08072404 @ case 7
	.4byte _08072440 @ case 8
_08072074:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x23
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	bne _08072092
	b _080725EE
_08072092:
	movs r2, #0xa9
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r0, #0x1e
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	bl FUN_08060b84
	b _080725EE
_080720A8:
	ldr r0, _08072100 @ =0x0000037E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _080720B8
	ldr r0, _08072104 @ =0x000001F7
	bl PlaySound_082406e0
_080720B8:
	adds r0, r5, #0
	bl FUN_0806f738
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #6
	bhi _080720E6
	b _080725EE
_080720E6:
	ldr r2, _08072108 @ =0x00000A8F
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #4
	bhi _0807210C
	movs r0, #0xd5
	b _080721AC
	.align 2, 0
_08072100: .4byte 0x0000037E
_08072104: .4byte 0x000001F7
_08072108: .4byte 0x00000A8F
_0807210C:
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08072134
	ldr r0, _08072130 @ =0x00000203
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl FUN_08060b84
	b _0807213E
	.align 2, 0
_08072130: .4byte 0x00000203
_08072134:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #2
	bl FUN_08060b84
_0807213E:
	movs r1, #0x20
	str r1, [sp]
	movs r0, #0x32
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	movs r0, #0x14
	str r0, [sp, #0x10]
	movs r0, #5
	str r0, [sp, #0x14]
	str r0, [sp, #0x18]
	movs r0, #0
	str r0, [sp, #0x1c]
	adds r0, r5, #0
	movs r1, #0xe6
	movs r2, #0xaa
	movs r3, #0
	bl FUN_08080be8
	b _080725EE
_08072168:
	adds r0, r5, #0
	bl FUN_0806f738
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _080721BC @ =0x0000037E
	adds r4, r5, r2
	ldrh r0, [r4]
	cmp r0, #6
	bne _08072198
	movs r0, #0xfc
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08072198:
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080721C4
	ldr r0, _080721C0 @ =0x00000203
_080721AC:
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl FUN_08060b84
	b _080725EE
	.align 2, 0
_080721BC: .4byte 0x0000037E
_080721C0: .4byte 0x00000203
_080721C4:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	movs r2, #0xa9
	lsls r2, r2, #4
	adds r1, r5, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	bhs _080721DC
	b _080725EE
_080721DC:
	ldr r0, _0807220C @ =0x00000A8F
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _08072210 @ =0x0000095E
	adds r1, r5, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r5, r0
	movs r0, #0x24
	strh r0, [r1]
	movs r0, #0xfc
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #3
	movs r2, #3
	bl FUN_08060b84
	b _080725EE
	.align 2, 0
_0807220C: .4byte 0x00000A8F
_08072210: .4byte 0x0000095E
_08072214:
	adds r0, r5, #0
	bl FUN_0806f738
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r4, #2
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _080722D4
	ldr r1, _08072290 @ =0x0000037E
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	movs r2, #0xa9
	lsls r2, r2, #4
	adds r0, r5, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r0, [r0]
	cmp r1, r0
	bhs _08072262
	b _080725EE
_08072262:
	ldr r0, _08072294 @ =0x00000A8F
	adds r1, r5, r0
	movs r0, #2
	strb r0, [r1]
	ldr r2, _08072298 @ =0x0000095E
	adds r1, r5, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r5, r0
	movs r0, #0x24
	strh r0, [r1]
	ldr r0, _0807229C @ =0x000001F9
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl FUN_08060b84
	b _080725EE
	.align 2, 0
_08072290: .4byte 0x0000037E
_08072294: .4byte 0x00000A8F
_08072298: .4byte 0x0000095E
_0807229C: .4byte 0x000001F9
_080722A0:
	adds r0, r5, #0
	bl FUN_0806f738
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r4, #2
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _080722D4
	b _080725EE
_080722D4:
	ldr r0, _08072320 @ =0x000002E9
	bl PlaySound_082406e0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	movs r0, #8
	subs r0, r0, r1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	ldr r2, _08072324 @ =0x00000A8A
	adds r1, r5, r2
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_0806f900
	adds r1, r0, #0
	movs r2, #0xa1
	lsls r2, r2, #4
	adds r0, r5, r2
	str r4, [sp]
	movs r2, #0x14
	str r2, [sp, #4]
	movs r2, #0x20
	movs r3, #0x10
	bl FUN_082364f8
	ldr r0, _08072328 @ =0x00000202
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #3
	movs r2, #8
	bl FUN_08060b84
	b _080725EE
	.align 2, 0
_08072320: .4byte 0x000002E9
_08072324: .4byte 0x00000A8A
_08072328: .4byte 0x00000202
_0807232C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x25
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0807235E
	ldr r0, _08072380 @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_0807235E:
	ldr r2, _08072384 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _08072372
	b _080725EE
_08072372:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #6
	bl FUN_08060b84
	b _080725EE
	.align 2, 0
_08072380: .4byte 0x00000A76
_08072384: .4byte 0x0000037E
_08072388:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080723BA
	ldr r0, _080723D4 @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_080723BA:
	ldr r1, _080723D4 @ =0x00000A76
	adds r2, r5, r1
	ldrb r0, [r2]
	cmp r0, #0
	beq _080723DC
	movs r0, #0
	strb r0, [r2]
	ldr r2, _080723D8 @ =0x0000037D
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _080725EE
	.align 2, 0
_080723D4: .4byte 0x00000A76
_080723D8: .4byte 0x0000037D
_080723DC:
	ldr r0, _08072400 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bhi _080723F0
	b _080725EE
_080723F0:
	movs r0, #0
	strb r0, [r2]
	adds r0, r5, #0
	movs r1, #3
	movs r2, #7
	bl FUN_08060b84
	b _080725EE
	.align 2, 0
_08072400: .4byte 0x0000037E
_08072404:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x23
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _0807243C @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _08072430
	b _080725EE
_08072430:
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	b _080725EE
	.align 2, 0
_0807243C: .4byte 0x0000037E
_08072440:
	ldr r1, _080724E8 @ =0x000003D1
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	adds r0, r5, #0
	bl FUN_0806f738
	cmp r0, #0
	beq _0807245A
	adds r0, r5, #0
	movs r1, #6
	bl FUN_08060aa4
_0807245A:
	ldr r2, _080724EC @ =0x0000037E
	adds r0, r5, r2
	ldrh r0, [r0]
	movs r3, #3
	ands r3, r0
	adds r6, r5, #0
	adds r6, #0x2c
	cmp r3, #0
	bne _080724A0
	ldr r1, _080724F0 @ =0xFFFF0000
	ldr r2, _080724F4 @ =0x0000FFFF
	str r3, [sp, #0x20]
	ldr r0, [sp, #0x24]
	ands r0, r1
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x28]
	ands r0, r1
	movs r3, #0x20
	orrs r0, r3
	ands r0, r2
	str r0, [sp, #0x28]
	add r2, sp, #0x28
	ldr r0, [r2, #4]
	ands r0, r1
	orrs r0, r3
	str r0, [r2, #4]
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	add r1, sp, #0x20
	movs r3, #1
	bl FUN_080dbcec
_080724A0:
	ldr r0, _080724F8 @ =0x00000A8A
	adds r4, r5, r0
	ldrh r0, [r4]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	strh r0, [r4]
	ldrh r1, [r4]
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_08061b48
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp, #0x30]
	str r1, [sp, #0x34]
	ldrh r1, [r4]
	movs r0, #0xd0
	lsls r0, r0, #1
	subs r6, r0, r1
	movs r1, #0xff
	ands r6, r1
	ldr r2, _080724FC @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xaa
	muls r0, r1, r0
	cmp r0, #0
	blt _08072500
	asrs r1, r0, #0xc
	b _08072506
	.align 2, 0
_080724E8: .4byte 0x000003D1
_080724EC: .4byte 0x0000037E
_080724F0: .4byte 0xFFFF0000
_080724F4: .4byte 0x0000FFFF
_080724F8: .4byte 0x00000A8A
_080724FC: .4byte 0x085B0A08
_08072500:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08072506:
	add r3, sp, #0x30
	ldrh r0, [r3]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0807253C @ =0xFFFF0000
	ldr r2, [sp, #0x30]
	ands r2, r1
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0xe6
	lsls r1, r1, #0x10
	ldr r0, _08072540 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x30]
	ldr r1, _08072544 @ =0x085B0A08
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xaa
	muls r0, r1, r0
	cmp r0, #0
	blt _08072548
	asrs r0, r0, #0xc
	b _0807254E
	.align 2, 0
_0807253C: .4byte 0xFFFF0000
_08072540: .4byte 0x0000FFFF
_08072544: .4byte 0x085B0A08
_08072548:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0807254E:
	ldrh r1, [r3, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08072600 @ =0xFFFF0000
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r3, #4]
	movs r0, #0xa1
	lsls r0, r0, #4
	adds r4, r5, r0
	adds r0, r4, #0
	adds r1, r3, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _08072604 @ =0x00000A52
	adds r0, r5, r1
	strb r6, [r0]
	adds r0, r4, #0
	bl FUN_08236400
	ldr r2, _08072608 @ =0x00000A8A
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r0, _0807260C @ =0x0000010F
	subs r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r5, r2
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_080609dc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x25
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _08072610 @ =0x0000037E
	adds r4, r5, r2
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _080725C8
	movs r0, #0x81
	lsls r0, r0, #2
	bl PlaySound_082406e0
_080725C8:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _08072614 @ =0x00000A8F
	adds r1, r5, r2
	ldrb r1, [r1]
	lsls r1, r1, #5
	cmp r0, r1
	blt _080725EE
	ldr r0, _08072618 @ =0x00000202
	bl sound_08240740
	adds r0, r5, #0
	movs r1, #3
	movs r2, #6
	bl FUN_08060b84
_080725EE:
	ldr r0, _0807261C @ =0x00000951
	adds r1, r5, r0
	movs r0, #9
	strb r0, [r1]
	add sp, #0x38
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08072600: .4byte 0xFFFF0000
_08072604: .4byte 0x00000A52
_08072608: .4byte 0x00000A8A
_0807260C: .4byte 0x0000010F
_08072610: .4byte 0x0000037E
_08072614: .4byte 0x00000A8F
_08072618: .4byte 0x00000202
_0807261C: .4byte 0x00000951

	thumb_func_start FUN_08072620
FUN_08072620: @ 0x08072620
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r4, r4, r0
	ldr r0, _0807263C @ =FUN_08072724
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807263C: .4byte FUN_08072724

	thumb_func_start FUN_08072640
FUN_08072640: @ 0x08072640
	ldr r1, _0807264C @ =0x000004AA
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	bx lr
	.align 2, 0
_0807264C: .4byte 0x000004AA

	thumb_func_start FUN_08072650
FUN_08072650: @ 0x08072650
	push {lr}
	movs r2, #0x96
	lsls r2, r2, #3
	adds r1, r0, r2
	ldr r2, [r1]
	cmp r2, #0
	beq _0807266A
	movs r0, #0
	str r0, [r1]
	adds r0, r2, #0
	movs r1, #0
	bl FUN_082318ac
_0807266A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08072670
FUN_08072670: @ 0x08072670
	ldr r1, _08072684 @ =0x000004AA
	adds r2, r0, r1
	movs r1, #2
	strb r1, [r2]
	ldr r1, _08072688 @ =0x000004AB
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	bx lr
	.align 2, 0
_08072684: .4byte 0x000004AA
_08072688: .4byte 0x000004AB

	thumb_func_start FUN_0807268c
FUN_0807268c: @ 0x0807268C
	push {r4, lr}
	adds r1, r0, #0
	ldr r0, _080726B0 @ =0x000004AB
	adds r4, r1, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _080726AA
	movs r2, #0x8c
	lsls r2, r2, #2
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
	movs r0, #0
	strb r0, [r4]
_080726AA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080726B0: .4byte 0x000004AB

	thumb_func_start FUN_080726b4
FUN_080726b4: @ 0x080726B4
	push {lr}
	adds r1, r0, #0
	ldr r2, _080726CC @ =0x000004AA
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _080726D0
	adds r0, r1, #0
	bl FUN_08072650
	b _080726DA
	.align 2, 0
_080726CC: .4byte 0x000004AA
_080726D0:
	cmp r0, #2
	bne _080726DA
	adds r0, r1, #0
	bl FUN_0807268c
_080726DA:
	pop {r0}
	bx r0
	.align 2, 0
_080726E0:
	.byte 0x00, 0xB5, 0x05, 0x21, 0xEE, 0xF7, 0xAC, 0xFA, 0x01, 0xBC, 0x00, 0x47

	thumb_func_start FUN_080726ec
FUN_080726ec: @ 0x080726EC
	push {r4, lr}
	adds r1, r0, #0
	ldr r2, _0807271C @ =0x000004AD
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08072716
	ldr r0, _08072720 @ =0x000004AE
	adds r4, r1, r0
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _08072716
	adds r0, r1, #0
	bl FUN_080612d8
	movs r0, #0
	strb r0, [r4]
_08072716:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807271C: .4byte 0x000004AD
_08072720: .4byte 0x000004AE

	thumb_func_start FUN_08072724
FUN_08072724: @ 0x08072724
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _0807273C @ =0x0000037D
	adds r0, r4, r1
	ldrb r5, [r0]
	cmp r5, #1
	beq _0807278A
	cmp r5, #1
	bgt _08072740
	cmp r5, #0
	beq _08072746
	b _080727CC
	.align 2, 0
_0807273C: .4byte 0x0000037D
_08072740:
	cmp r5, #2
	beq _08072778
	b _080727CC
_08072746:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _08072774 @ =0x000004AF
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080727CC
	strb r5, [r1]
	adds r0, r4, #0
	bl FUN_080726b4
	b _080727CC
	.align 2, 0
_08072774: .4byte 0x000004AF
_08072778:
	ldr r0, _080727A4 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bhi _080727A8
_0807278A:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x2f
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	b _080727CC
	.align 2, 0
_080727A4: .4byte 0x0000037E
_080727A8:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	adds r0, r4, #0
	bl FUN_08072620
	adds r0, r4, #0
	bl FUN_080726b4
_080727CC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080727D4:
	.byte 0x10, 0xB5, 0x04, 0x1C, 0x0A, 0x48, 0x21, 0x18, 0x08, 0x88, 0x01, 0x28
	.byte 0x3E, 0xD9, 0x09, 0x49, 0x60, 0x18, 0x00, 0x21, 0x41, 0x56, 0xBA, 0x22, 0x92, 0x00, 0xA3, 0x18
	.byte 0x1A, 0x78, 0x10, 0x1C, 0x08, 0x38, 0x09, 0x1A, 0x07, 0x20, 0x01, 0x40, 0x04, 0x29, 0x05, 0xDD
	.byte 0xD0, 0x1D, 0x04, 0xE0, 0x7E, 0x03, 0x00, 0x00, 0xA9, 0x04, 0x00, 0x00, 0x50, 0x1C, 0x07, 0x21
	.byte 0x08, 0x40, 0x18, 0x70, 0xBA, 0x21, 0x89, 0x00, 0x60, 0x18, 0x02, 0x78, 0x04, 0x2A, 0x0D, 0xD9
	.byte 0x08, 0x20, 0x80, 0x1A, 0x03, 0x4A, 0xA1, 0x18, 0x08, 0x70, 0x03, 0x48, 0x21, 0x18, 0x01, 0x20
	.byte 0x08, 0x70, 0x0A, 0xE0, 0xE6, 0x02, 0x00, 0x00, 0xE7, 0x02, 0x00, 0x00, 0x05, 0x49, 0x60, 0x18
	.byte 0x00, 0x21, 0x02, 0x70, 0x04, 0x4A, 0xA0, 0x18, 0x01, 0x70, 0x04, 0x48, 0x21, 0x18, 0x00, 0x20
	.byte 0x07, 0xE0, 0x00, 0x00, 0xE6, 0x02, 0x00, 0x00, 0xE7, 0x02, 0x00, 0x00, 0x7E, 0x03, 0x00, 0x00
	.byte 0x01, 0x30, 0x08, 0x80, 0xD6, 0x21, 0x89, 0x00, 0x60, 0x18, 0x00, 0x78, 0x00, 0x21, 0xF4, 0xF7
	.byte 0x39, 0xFB, 0x01, 0x1C, 0x20, 0x1C, 0x40, 0x22, 0xEE, 0xF7, 0xD4, 0xF8, 0xBA, 0x22, 0x92, 0x00
	.byte 0xA0, 0x18, 0x01, 0x78, 0x07, 0x4A, 0xA0, 0x18, 0x00, 0x78, 0x00, 0x06, 0x00, 0x16, 0x81, 0x42
	.byte 0x05, 0xD1, 0x20, 0x1C, 0xFF, 0xF7, 0xC4, 0xFE, 0x20, 0x1C, 0xFF, 0xF7, 0x0B, 0xFF, 0x10, 0xBC
	.byte 0x01, 0xBC, 0x00, 0x47, 0xA9, 0x04, 0x00, 0x00

	thumb_func_start FUN_080728a8
FUN_080728a8: @ 0x080728A8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080728C4 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bls _080728B8
	b _080729CE
_080728B8:
	lsls r0, r0, #2
	ldr r1, _080728C8 @ =_080728CC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080728C4: .4byte 0x0000037D
_080728C8: .4byte _080728CC
_080728CC: @ jump table
	.4byte _080728E0 @ case 0
	.4byte _08072900 @ case 1
	.4byte _08072910 @ case 2
	.4byte _08072930 @ case 3
	.4byte _08072980 @ case 4
_080728E0:
	ldr r1, _080728F8 @ =0x00000211
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _080729CE
	ldr r0, _080728FC @ =0x0000037D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _0807296E
	.align 2, 0
_080728F8: .4byte 0x00000211
_080728FC: .4byte 0x0000037D
_08072900:
	ldr r1, _0807290C @ =0x00000212
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	b _080729CE
	.align 2, 0
_0807290C: .4byte 0x00000212
_08072910:
	ldr r1, _0807292C @ =0x00000211
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _080729CE
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	bl FUN_08072620
	b _0807296E
	.align 2, 0
_0807292C: .4byte 0x00000211
_08072930:
	ldr r1, _08072978 @ =0x00000212
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r1, _0807297C @ =0x0000037E
	adds r5, r4, r1
	ldrh r0, [r5]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #3
	subs r1, r1, r0
	cmp r2, r1
	bge _08072956
	adds r0, r4, #0
	movs r1, #5
	bl FUN_08060c40
_08072956:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x37
	bls _080729CE
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	bl FUN_08060b84
_0807296E:
	adds r0, r4, #0
	bl FUN_080726b4
	b _080729CE
	.align 2, 0
_08072978: .4byte 0x00000212
_0807297C: .4byte 0x0000037E
_08072980:
	ldr r1, _080729D4 @ =0x00000212
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _080729D8 @ =0x0000037E
	adds r5, r4, r0
	ldrh r0, [r5]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #3
	subs r1, r1, r0
	cmp r2, r1
	blt _080729A6
	adds r0, r4, #0
	movs r1, #5
	bl FUN_08060c40
_080729A6:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x37
	bls _080729CE
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _080729DC @ =0x080726E1
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_080726b4
_080729CE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080729D4: .4byte 0x00000212
_080729D8: .4byte 0x0000037E
_080729DC: .4byte 0x080726E1

	thumb_func_start FUN_080729e0
FUN_080729e0: @ 0x080729E0
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08072A08 @ =0x00000213
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08072A02
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	bl FUN_08072620
	adds r0, r4, #0
	bl FUN_080726b4
_08072A02:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08072A08: .4byte 0x00000213

	thumb_func_start FUN_08072a0c
FUN_08072a0c: @ 0x08072A0C
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x33
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	adds r0, r4, #0
	movs r1, #4
	bl FUN_08060c40
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08072A38:
	.byte 0xF0, 0xB5, 0x47, 0x46, 0x80, 0xB4, 0x04, 0x1C
	.byte 0x25, 0x49, 0x60, 0x18, 0x00, 0x22, 0x81, 0x5E, 0x2C, 0x23, 0xE0, 0x5E, 0x0E, 0x1A, 0x94, 0x21
	.byte 0xC9, 0x00, 0x60, 0x18, 0x00, 0x22, 0x81, 0x5E, 0x30, 0x23, 0xE0, 0x5E, 0x0D, 0x1A, 0x30, 0x1C
	.byte 0x29, 0x1C, 0xC4, 0xF1, 0xFB, 0xFE, 0x80, 0x46, 0x0C, 0x27, 0x0C, 0x20, 0xF4, 0xF7, 0x32, 0xFB
	.byte 0x1A, 0x49, 0x60, 0x18, 0x00, 0x88, 0x00, 0x21, 0x00, 0x28, 0x05, 0xD0, 0x18, 0x4A, 0xA0, 0x18
	.byte 0x00, 0x88, 0x05, 0x28, 0x00, 0xD1, 0x01, 0x21, 0x00, 0x29, 0x04, 0xD0, 0x20, 0x1C, 0xBC, 0x30
	.byte 0x00, 0x78, 0x78, 0x43, 0x87, 0x11, 0x30, 0x1C, 0x70, 0x43, 0x29, 0x1C, 0x69, 0x43, 0x40, 0x18
	.byte 0x39, 0x1C, 0x79, 0x43, 0x88, 0x42, 0x5D, 0xDC, 0x0B, 0x4B, 0xE0, 0x18, 0x00, 0x88, 0xA0, 0x85
	.byte 0x94, 0x21, 0xC9, 0x00, 0x60, 0x18, 0x00, 0x88, 0x20, 0x86, 0x0A, 0x4A, 0xA1, 0x18, 0x0A, 0x78
	.byte 0x00, 0x20, 0x08, 0x56, 0x00, 0x28, 0x0F, 0xDB, 0xBA, 0x23, 0x9B, 0x00, 0xE0, 0x18, 0x02, 0x70
	.byte 0xFF, 0x20, 0x08, 0x70, 0x16, 0xE0, 0x00, 0x00, 0x9C, 0x04, 0x00, 0x00, 0x46, 0x04, 0x00, 0x00
	.byte 0x42, 0x04, 0x00, 0x00, 0xA9, 0x04, 0x00, 0x00, 0x41, 0x46, 0x08, 0x04, 0x00, 0x0C, 0x10, 0x30
	.byte 0xFF, 0x21, 0x08, 0x40, 0x40, 0x11, 0x03, 0x30, 0x07, 0x21, 0x01, 0x40, 0xBA, 0x22, 0x92, 0x00
	.byte 0xA0, 0x18, 0x01, 0x70, 0xBA, 0x23, 0x9B, 0x00, 0xE0, 0x18, 0x02, 0x78, 0x04, 0x2A, 0x0B, 0xD9
	.byte 0x08, 0x20, 0x80, 0x1A, 0x03, 0x4A, 0xA1, 0x18, 0x08, 0x70, 0x01, 0x3B, 0xE1, 0x18, 0x01, 0x20
	.byte 0x08, 0x70, 0x08, 0xE0, 0xE6, 0x02, 0x00, 0x00, 0x0C, 0x49, 0x60, 0x18, 0x00, 0x21, 0x02, 0x70
	.byte 0x0B, 0x4A, 0xA0, 0x18, 0x01, 0x70, 0xD6, 0x23, 0x9B, 0x00, 0xE0, 0x18, 0x00, 0x78, 0x00, 0x21
	.byte 0xF4, 0xF7, 0xD0, 0xF9, 0x01, 0x1C, 0x20, 0x1C, 0x40, 0x22, 0xED, 0xF7, 0x6B, 0xFF, 0x20, 0x1C
	.byte 0xFF, 0xF7, 0x66, 0xFD, 0x20, 0x1C, 0xFF, 0xF7, 0xAD, 0xFD, 0xEE, 0xE0, 0xE6, 0x02, 0x00, 0x00
	.byte 0xE7, 0x02, 0x00, 0x00, 0x06, 0x4A, 0x40, 0x46, 0x40, 0x30, 0xFF, 0x21, 0x08, 0x40, 0x40, 0x00
	.byte 0x80, 0x18, 0x00, 0x21, 0x40, 0x5E, 0x78, 0x43, 0x00, 0x28, 0x03, 0xDB, 0x00, 0x13, 0x04, 0xE0
	.byte 0x08, 0x0A, 0x5B, 0x08, 0x40, 0x42, 0x00, 0x13, 0x40, 0x42, 0xA0, 0x86, 0xFF, 0x20, 0x43, 0x46
	.byte 0x18, 0x40, 0x40, 0x00, 0x80, 0x18, 0x00, 0x21, 0x40, 0x5E, 0x78, 0x43, 0x00, 0x28, 0x01, 0xDB
	.byte 0x00, 0x13, 0x02, 0xE0, 0x40, 0x42, 0x00, 0x13, 0x40, 0x42, 0x20, 0x87, 0x07, 0x4A, 0xA3, 0x18
	.byte 0x1B, 0x78, 0x01, 0x2B, 0x19, 0xD1, 0x00, 0x04, 0x00, 0x28, 0x09, 0xDA, 0x38, 0x23, 0xE1, 0x5E
	.byte 0x88, 0x00, 0x40, 0x18, 0xC0, 0x00, 0x00, 0x28, 0x08, 0xDA, 0x09, 0xE0, 0xC7, 0x01, 0x00, 0x00
	.byte 0x38, 0x20, 0x21, 0x5E, 0x34, 0x20, 0x48, 0x43, 0x00, 0x28, 0x01, 0xDB, 0x80, 0x11, 0x02, 0xE0
	.byte 0x40, 0x42, 0x80, 0x11, 0x40, 0x42, 0x20, 0x87, 0x18, 0xE0, 0x02, 0x2B, 0x16, 0xD1, 0x34, 0x21
	.byte 0x60, 0x5E, 0x00, 0x28, 0x06, 0xDA, 0x01, 0x1C, 0x88, 0x00, 0x40, 0x18, 0xC0, 0x00, 0x00, 0x28
	.byte 0x06, 0xDA, 0x07, 0xE0, 0x34, 0x23, 0xE1, 0x5E, 0x34, 0x20, 0x48, 0x43, 0x00, 0x28, 0x01, 0xDB
	.byte 0x80, 0x11, 0x02, 0xE0, 0x40, 0x42, 0x80, 0x11, 0x40, 0x42, 0xA0, 0x86, 0x40, 0x46, 0x10, 0x30
	.byte 0xFF, 0x21, 0x08, 0x40, 0x40, 0x11, 0xC1, 0x1C, 0x07, 0x20, 0x01, 0x40, 0xBA, 0x22, 0x92, 0x00
	.byte 0xA0, 0x18, 0x01, 0x70, 0x04, 0x29, 0x0D, 0xD9, 0x08, 0x20, 0x40, 0x1A, 0x03, 0x4B, 0xE1, 0x18
	.byte 0x08, 0x70, 0x03, 0x48, 0x21, 0x18, 0x01, 0x20, 0x0A, 0xE0, 0x00, 0x00, 0xE6, 0x02, 0x00, 0x00
	.byte 0xE7, 0x02, 0x00, 0x00, 0x1A, 0x4A, 0xA0, 0x18, 0x01, 0x70, 0x1A, 0x4B, 0xE1, 0x18, 0x00, 0x20
	.byte 0x08, 0x70, 0x22, 0x1C, 0x9C, 0x32, 0x11, 0x88, 0x03, 0x20, 0x08, 0x40, 0x00, 0x28, 0x58, 0xD1
	.byte 0x20, 0x1C, 0x94, 0x30, 0x00, 0x88, 0x00, 0x28, 0x53, 0xD1, 0x13, 0x49, 0x60, 0x18, 0x01, 0x88
	.byte 0x00, 0x25, 0x03, 0x1C, 0x00, 0x29, 0x05, 0xD0, 0x10, 0x49, 0x60, 0x18, 0x00, 0x88, 0x00, 0x28
	.byte 0x00, 0xD1, 0x01, 0x25, 0x00, 0x2D, 0x44, 0xD1, 0x18, 0x88, 0x00, 0x21, 0x00, 0x28, 0x05, 0xD0
	.byte 0x0A, 0x4B, 0xE0, 0x18, 0x00, 0x88, 0x05, 0x28, 0x00, 0xD1, 0x01, 0x21, 0x00, 0x29, 0x13, 0xD0
	.byte 0x10, 0x88, 0x00, 0x28, 0x0C, 0xD1, 0xC8, 0x20, 0xCD, 0xF1, 0x12, 0xFD, 0x31, 0xE0, 0x00, 0x00
	.byte 0xE6, 0x02, 0x00, 0x00, 0xE7, 0x02, 0x00, 0x00, 0x46, 0x04, 0x00, 0x00, 0x42, 0x04, 0x00, 0x00
	.byte 0xC7, 0x20, 0xCD, 0xF1, 0x05, 0xFD, 0x24, 0xE0, 0xE4, 0x21, 0x89, 0x00, 0x60, 0x18, 0x00, 0x88
	.byte 0x00, 0x28, 0x04, 0xD1, 0x05, 0x4B, 0xE0, 0x18, 0x00, 0x78, 0x00, 0x28, 0x0C, 0xD1, 0x10, 0x88
	.byte 0x00, 0x28, 0x05, 0xD1, 0xCA, 0x20, 0xCD, 0xF1, 0xF3, 0xFC, 0x12, 0xE0, 0xC7, 0x01, 0x00, 0x00
	.byte 0xC9, 0x20, 0xCD, 0xF1, 0xED, 0xFC, 0x0C, 0xE0, 0x10, 0x88, 0x00, 0x28, 0x06, 0xD1, 0x02, 0x48
	.byte 0xCD, 0xF1, 0xE6, 0xFC, 0x05, 0xE0, 0x00, 0x00, 0x8E, 0x02, 0x00, 0x00, 0x09, 0x48, 0xCD, 0xF1
	.byte 0xDF, 0xFC, 0xD6, 0x21, 0x89, 0x00, 0x60, 0x18, 0x00, 0x78, 0x01, 0x21, 0xF4, 0xF7, 0xDA, 0xF8
	.byte 0x01, 0x1C, 0x20, 0x1C, 0x40, 0x22, 0xED, 0xF7, 0x75, 0xFE, 0x08, 0xBC, 0x98, 0x46, 0xF0, 0xBC
	.byte 0x01, 0xBC, 0x00, 0x47, 0x8D, 0x02, 0x00, 0x00

	thumb_func_start FUN_08072d48
FUN_08072d48: @ 0x08072D48
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, _08072DD0 @ =0x0000049C
	adds r0, r4, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0x2c
	ldrsh r0, [r4, r5]
	subs r6, r1, r0
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0x30
	ldrsh r0, [r4, r5]
	subs r5, r1, r0
	adds r1, r6, #0
	muls r1, r6, r1
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r1, r0
	mov r8, r1
	movs r0, #0
	mov sl, r0
	mov sb, r0
	cmp r1, #0
	beq _08072D8C
	b _08072E8C
_08072D8C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x10
	bl FUN_08066ee4
	str r0, [sp]
	ldr r5, _08072DD4 @ =0x000004A9
	adds r2, r4, r5
	ldrb r3, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _08072DEE
	movs r6, #0xba
	lsls r6, r6, #2
	adds r1, r4, r6
	strb r3, [r1]
	movs r0, #0xff
	strb r0, [r2]
	ldrb r1, [r1]
	cmp r1, #4
	bls _08072DE0
	movs r0, #8
	subs r0, r0, r1
	ldr r2, _08072DD8 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r5, _08072DDC @ =0x000002E7
	adds r1, r4, r5
	movs r0, #1
	strb r0, [r1]
	b _08072DEE
	.align 2, 0
_08072DD0: .4byte 0x0000049C
_08072DD4: .4byte 0x000004A9
_08072DD8: .4byte 0x000002E6
_08072DDC: .4byte 0x000002E7
_08072DE0:
	ldr r6, _08072E44 @ =0x000002E6
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _08072E48 @ =0x000002E7
	adds r0, r4, r1
	mov r2, sb
	strb r2, [r0]
_08072DEE:
	ldr r5, _08072E4C @ =0x000004A6
	adds r6, r4, r5
	ldrb r0, [r6]
	cmp r0, #0
	beq _08072E72
	ldr r0, _08072E50 @ =0x000004A7
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _08072E58
	movs r7, #1
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08072E54 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	mov r8, r0
	movs r6, #0
	ldrsh r0, [r0, r6]
	mov sl, r0
	ands r3, r1
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	mov sb, r1
	ldrb r1, [r5]
	lsls r0, r1, #3
	subs r0, r0, r1
	asrs r0, r0, #3
	strb r0, [r5]
	b _08073016
	.align 2, 0
_08072E44: .4byte 0x000002E6
_08072E48: .4byte 0x000002E7
_08072E4C: .4byte 0x000004A6
_08072E50: .4byte 0x000004A7
_08072E54: .4byte 0x085B0A08
_08072E58:
	movs r7, #0
	movs r5, #0x96
	lsls r5, r5, #3
	adds r1, r4, r5
	ldr r0, [r1]
	cmp r0, #0
	beq _08072E6E
	str r7, [r1]
	movs r1, #0
	bl FUN_082318ac
_08072E6E:
	strb r7, [r6]
	b _08073016
_08072E72:
	movs r7, #0
	movs r6, #0x96
	lsls r6, r6, #3
	adds r1, r4, r6
	ldr r0, [r1]
	cmp r0, #0
	bne _08072E82
	b _08073016
_08072E82:
	str r7, [r1]
	movs r1, #0
	bl FUN_082318ac
	b _08073016
_08072E8C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x11
	bl FUN_08066ee4
	str r0, [sp]
	movs r7, #1
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_0823785c
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
	adds r2, r1, #0
	strb r1, [r0]
	cmp r2, #4
	bls _08072EE0
	movs r0, #8
	subs r0, r0, r2
	ldr r5, _08072ED8 @ =0x000002E6
	adds r1, r4, r5
	strb r0, [r1]
	ldr r6, _08072EDC @ =0x000002E7
	adds r0, r4, r6
	strb r7, [r0]
	b _08072EEE
	.align 2, 0
_08072ED8: .4byte 0x000002E6
_08072EDC: .4byte 0x000002E7
_08072EE0:
	ldr r2, _08072F48 @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r5, _08072F4C @ =0x000002E7
	adds r0, r4, r5
	mov r6, sb
	strb r6, [r0]
_08072EEE:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08072F50 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r5, [r0, r6]
	mov sl, r5
	ands r3, r1
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	mov sb, r1
	adds r0, r4, #0
	adds r0, #0x9c
	ldrh r1, [r0]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _08073016
	mov r5, r8
	cmp r5, #0x40
	bgt _08072F58
	ldr r6, _08072F54 @ =0x0000049C
	adds r0, r4, r6
	ldrh r0, [r0]
	strh r0, [r4, #0x2c]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r0, [r0]
	strh r0, [r4, #0x30]
	b _08072FF8
	.align 2, 0
_08072F48: .4byte 0x000002E6
_08072F4C: .4byte 0x000002E7
_08072F50: .4byte 0x085B0A08
_08072F54: .4byte 0x0000049C
_08072F58:
	mov r2, sl
	lsls r0, r2, #3
	cmp r0, #0
	blt _08072F64
	asrs r0, r0, #0xc
	b _08072F6A
_08072F64:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08072F6A:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	movs r0, #8
	mov r5, sb
	muls r5, r0, r5
	adds r0, r5, #0
	cmp r0, #0
	blt _08072F7E
	asrs r0, r0, #0xc
	b _08072F84
_08072F7E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08072F84:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
	ldr r6, _08072FA8 @ =0x000001C7
	adds r1, r4, r6
	ldrb r1, [r1]
	cmp r1, #1
	bne _08072FC6
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08072FAC
	movs r0, #0x38
	ldrsh r1, [r4, r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _08072FB8
	b _08072FBC
	.align 2, 0
_08072FA8: .4byte 0x000001C7
_08072FAC:
	movs r2, #0x38
	ldrsh r1, [r4, r2]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _08072FBC
_08072FB8:
	asrs r0, r0, #6
	b _08072FC2
_08072FBC:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08072FC2:
	strh r0, [r4, #0x38]
	b _08072FF8
_08072FC6:
	cmp r1, #2
	bne _08072FF8
	movs r5, #0x34
	ldrsh r0, [r4, r5]
	cmp r0, #0
	bge _08072FE0
	adds r1, r0, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _08072FEC
	b _08072FF0
_08072FE0:
	movs r0, #0x34
	ldrsh r1, [r4, r0]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _08072FF0
_08072FEC:
	asrs r0, r0, #6
	b _08072FF6
_08072FF0:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08072FF6:
	strh r0, [r4, #0x34]
_08072FF8:
	ldr r1, _08073044 @ =0x000004A6
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08073016
	ldr r5, _08073048 @ =0x000004A7
	adds r2, r4, r5
	ldrb r0, [r2]
	cmp r0, #0x95
	bhi _08073016
	adds r1, r0, #0
	lsls r0, r1, #4
	subs r0, r0, r1
	asrs r0, r0, #4
	strb r0, [r2]
_08073016:
	adds r0, r4, #0
	ldr r1, [sp]
	movs r2, #0x40
	bl FUN_08060a24
	cmp r7, #0
	beq _08073034
	ldr r6, _08073048 @ =0x000004A7
	adds r0, r4, r6
	ldrb r3, [r0]
	adds r0, r4, #0
	mov r1, sl
	mov r2, sb
	bl FUN_08068e94
_08073034:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08073044: .4byte 0x000004A6
_08073048: .4byte 0x000004A7

	thumb_func_start FUN_0807304c
FUN_0807304c: @ 0x0807304C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08073064 @ =0x0000037D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #1
	beq _080730CC
	cmp r0, #1
	bgt _08073068
	cmp r0, #0
	beq _08073072
	b _0807316E
	.align 2, 0
_08073064: .4byte 0x0000037D
_08073068:
	cmp r0, #2
	beq _080730E2
	cmp r0, #3
	beq _0807310C
	b _0807316E
_08073072:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #8
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0807316E
	movs r0, #0xcb
	bl PlaySound_082406e0
	ldr r2, _080730AC @ =0x000004A6
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080730B0
	movs r0, #1
	b _080730B2
	.align 2, 0
_080730AC: .4byte 0x000004A6
_080730B0:
	movs r0, #2
_080730B2:
	strb r0, [r5]
	ldr r1, _080730C4 @ =0x000004A6
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _080730C8 @ =0x0000037E
	adds r0, r4, r2
	strh r1, [r0]
	b _0807316E
	.align 2, 0
_080730C4: .4byte 0x000004A6
_080730C8: .4byte 0x0000037E
_080730CC:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0x1e
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #9
	b _080730F6
_080730E2:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0x1e
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0xa
_080730F6:
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	adds r0, r4, #0
	bl FUN_080726b4
	b _0807316E
_0807310C:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0xb
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0807316E
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r1, [r0]
	cmp r1, #4
	bls _08073154
	movs r0, #8
	subs r0, r0, r1
	subs r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _08073150 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	b _08073160
	.align 2, 0
_08073150: .4byte 0x000002E7
_08073154:
	ldr r2, _08073174 @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _08073178 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
_08073160:
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_08072620
	adds r0, r4, #0
	bl FUN_080726b4
_0807316E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08073174: .4byte 0x000002E6
_08073178: .4byte 0x000002E7

	thumb_func_start FUN_0807317c
FUN_0807317c: @ 0x0807317C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _08073198 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #8
	bls _0807318C
	b _08073562
_0807318C:
	lsls r0, r0, #2
	ldr r1, _0807319C @ =_080731A0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08073198: .4byte 0x0000037D
_0807319C: .4byte _080731A0
_080731A0: @ jump table
	.4byte _080731C4 @ case 0
	.4byte _080731F8 @ case 1
	.4byte _08073240 @ case 2
	.4byte _08073280 @ case 3
	.4byte _080732D0 @ case 4
	.4byte _08073364 @ case 5
	.4byte _0807340C @ case 6
	.4byte _08073460 @ case 7
	.4byte _08073500 @ case 8
_080731C4:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
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
	bne _080731EC
	b _08073562
_080731EC:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #1
	bl FUN_08060b84
	b _08073562
_080731F8:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0x1e
	strh r0, [r1]
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
	ldr r2, _0807323C @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _0807322E
	b _08073562
_0807322E:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #2
	bl FUN_08060b84
	b _08073562
	.align 2, 0
_0807323C: .4byte 0x0000037E
_08073240:
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #5
	bne _0807325C
	ldr r1, _08073278 @ =0x0000037E
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0807325C
	ldr r0, _0807327C @ =0x00000327
	bl PlaySound_082406e0
_0807325C:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0x1e
	strh r0, [r1]
	adds r2, r4, #0
	adds r2, #0x90
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	ldr r3, _08073278 @ =0x0000037E
	adds r5, r4, r3
	b _080734A4
	.align 2, 0
_08073278: .4byte 0x0000037E
_0807327C: .4byte 0x00000327
_08073280:
	adds r0, r4, #0
	movs r1, #4
	bl FUN_08060c40
	ldr r3, _080732C8 @ =0x0000037E
	adds r2, r4, r3
	ldrh r1, [r2]
	movs r0, #0xc8
	muls r0, r1, r0
	adds r0, #0xa0
	adds r3, #0x78
	adds r1, r4, r3
	strh r0, [r1]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _080732AA
	b _08073562
_080732AA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08060c40
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _080732CC @ =0x080726E1
	str r0, [r1]
	b _08073452
	.align 2, 0
_080732C8: .4byte 0x0000037E
_080732CC: .4byte 0x080726E1
_080732D0:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _080732EC
	ldr r2, _08073358 @ =0x0000037E
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _080732EC
	ldr r0, _0807335C @ =0x00000201
	bl PlaySound_082406e0
_080732EC:
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	adds r0, r4, #0
	movs r1, #4
	bl FUN_08060c40
	adds r2, r4, #0
	adds r2, #0x90
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	adds r1, r4, #0
	adds r1, #0xbc
	movs r0, #4
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x78
	strb r0, [r1]
	ldr r0, _08073358 @ =0x0000037E
	adds r2, r4, r0
	ldrh r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	movs r1, #0xc8
	muls r0, r1, r0
	adds r0, #0xa0
	ldr r3, _08073360 @ =0x000003F6
	adds r1, r4, r3
	strh r0, [r1]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0807334C
	b _08073562
_0807334C:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #5
	bl FUN_08060b84
	b _08073562
	.align 2, 0
_08073358: .4byte 0x0000037E
_0807335C: .4byte 0x00000201
_08073360: .4byte 0x000003F6
_08073364:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	adds r2, r4, #0
	adds r2, #0x90
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	ldr r2, _080733C4 @ =0x0000037E
	adds r3, r4, r2
	ldrb r1, [r3]
	movs r2, #0xf
	subs r1, r2, r1
	lsls r1, r1, #2
	movs r0, #0x40
	subs r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xbc
	strb r0, [r1]
	ldrh r0, [r3]
	cmp r0, #7
	bhi _080733CC
	subs r0, r2, r0
	lsls r0, r0, #3
	adds r2, r4, #0
	adds r2, #0xbd
	strb r0, [r2]
	ldrh r1, [r3]
	movs r0, #8
	subs r0, r0, r1
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r3, _080733C8 @ =0x000003F6
	adds r0, r4, r3
	strh r1, [r0]
	b _080733E4
	.align 2, 0
_080733C4: .4byte 0x0000037E
_080733C8: .4byte 0x000003F6
_080733CC:
	adds r1, r4, #0
	adds r1, #0xbd
	movs r0, #0x40
	strb r0, [r1]
	ldr r0, _08073404 @ =0x000003F6
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #4
	bl FUN_08060c40
_080733E4:
	ldr r2, _08073408 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _080733F8
	b _08073562
_080733F8:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #6
	bl FUN_08060b84
	b _08073562
	.align 2, 0
_08073404: .4byte 0x000003F6
_08073408: .4byte 0x0000037E
_0807340C:
	adds r2, r4, #0
	adds r2, #0x90
	ldr r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _0807345C @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi _08073446
	b _08073562
_08073446:
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	bl FUN_08072620
_08073452:
	adds r0, r4, #0
	bl FUN_080726b4
	b _08073562
	.align 2, 0
_0807345C: .4byte 0x0000037E
_08073460:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _0807347C
	ldr r2, _080734F4 @ =0x0000037E
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _0807347C
	ldr r0, _080734F8 @ =0x00000327
	bl PlaySound_082406e0
_0807347C:
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	adds r2, r4, #0
	adds r2, #0x90
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	ldr r0, _080734F4 @ =0x0000037E
	adds r5, r4, r0
_080734A4:
	ldrb r0, [r5]
	lsls r0, r0, #2
	movs r1, #0x40
	subs r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xbc
	strb r1, [r0]
	ldrh r0, [r5]
	cmp r0, #8
	bls _080734D8
	lsls r0, r0, #3
	adds r1, r4, #0
	adds r1, #0xbd
	strb r0, [r1]
	ldrh r0, [r5]
	subs r0, #8
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r2, _080734FC @ =0x000003F6
	adds r0, r4, r2
	strh r1, [r0]
	adds r0, r4, #0
	movs r1, #4
	bl FUN_08060c40
_080734D8:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _08073562
	adds r0, r4, #0
	movs r1, #7
	movs r2, #3
	bl FUN_08060b84
	b _08073562
	.align 2, 0
_080734F4: .4byte 0x0000037E
_080734F8: .4byte 0x00000327
_080734FC: .4byte 0x000003F6
_08073500:
	adds r0, r4, #0
	movs r1, #4
	bl FUN_08060c40
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _08073568 @ =0x0000037E
	adds r2, r4, r0
	ldrh r1, [r2]
	movs r0, #0xc8
	muls r0, r1, r0
	adds r0, #0xa0
	ldr r3, _0807356C @ =0x000003F6
	adds r1, r4, r3
	strh r0, [r1]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _08073562
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08060c40
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _08073570 @ =0x080726E1
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_080726b4
_08073562:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08073568: .4byte 0x0000037E
_0807356C: .4byte 0x000003F6
_08073570: .4byte 0x080726E1

	thumb_func_start FUN_08073574
FUN_08073574: @ 0x08073574
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _08073590 @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #5
	bls _08073584
	b _080736B0
_08073584:
	lsls r0, r0, #2
	ldr r1, _08073594 @ =_08073598
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08073590: .4byte 0x0000037D
_08073594: .4byte _08073598
_08073598: @ jump table
	.4byte _080735B0 @ case 0
	.4byte _08073600 @ case 1
	.4byte _0807362A @ case 2
	.4byte _0807360C @ case 3
	.4byte _0807366E @ case 4
	.4byte _080736A8 @ case 5
_080735B0:
	ldr r0, _080735FC @ =0x0000037E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _080735C0
	movs r0, #0xd0
	bl PlaySound_082406e0
_080735C0:
	ldrh r0, [r4]
	cmp r0, #8
	bne _080735CC
	movs r0, #0xdb
	bl PlaySound_082406e0
_080735CC:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x30
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _080736B0
	adds r0, r5, #0
	movs r1, #0x12
	movs r2, #1
	bl FUN_08060b84
	b _08073666
	.align 2, 0
_080735FC: .4byte 0x0000037E
_08073600:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x31
	b _08073634
_0807360C:
	ldr r0, _08073644 @ =0x0000037E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _0807361C
	movs r0, #0xd0
	bl PlaySound_082406e0
_0807361C:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _08073648
_0807362A:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x32
_08073634:
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	b _080736B0
	.align 2, 0
_08073644: .4byte 0x0000037E
_08073648:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	adds r0, r5, #0
	bl FUN_08072620
_08073666:
	adds r0, r5, #0
	bl FUN_080726b4
	b _080736B0
_0807366E:
	ldr r0, _080736A4 @ =0x0000037E
	adds r4, r5, r0
	ldrh r0, [r4]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #3
	subs r1, r1, r0
	cmp r2, r1
	blt _0807368A
	adds r0, r5, #0
	movs r1, #5
	bl FUN_08060c40
_0807368A:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x37
	bls _080736B0
	adds r0, r5, #0
	movs r1, #0x12
	movs r2, #5
	bl FUN_08060b84
	b _080736B0
	.align 2, 0
_080736A4: .4byte 0x0000037E
_080736A8:
	adds r0, r5, #0
	movs r1, #5
	bl FUN_08060c40
_080736B0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080736B8:
	.byte 0x30, 0xB5, 0x85, 0xB0, 0x05, 0x1C, 0x05, 0x49
	.byte 0x68, 0x18, 0x04, 0x78, 0x01, 0x2C, 0x00, 0xD1, 0x98, 0xE0, 0x01, 0x2C, 0x04, 0xDC, 0x00, 0x2C
	.byte 0x09, 0xD0, 0xEB, 0xE0, 0x7D, 0x03, 0x00, 0x00, 0x02, 0x2C, 0x00, 0xD1, 0xB0, 0xE0, 0x03, 0x2C
	.byte 0x00, 0xD1, 0xDF, 0xE0, 0xE2, 0xE0, 0x28, 0x1C, 0x04, 0x21, 0xED, 0xF7, 0xA9, 0xFA, 0xE8, 0x6A
	.byte 0x29, 0x6B, 0x03, 0x90, 0x04, 0x91, 0x03, 0x9A, 0x11, 0x14, 0x96, 0x31, 0x09, 0x04, 0x0E, 0x48
	.byte 0x10, 0x40, 0x08, 0x43, 0x03, 0x90, 0x03, 0xA8, 0xC8, 0xF1, 0xDE, 0xF9, 0xFC, 0x22, 0x92, 0x00
	.byte 0xA8, 0x18, 0x00, 0x78, 0x01, 0x28, 0x1F, 0xD8, 0x00, 0x28, 0x11, 0xD0, 0x04, 0x20, 0x00, 0x90
	.byte 0x06, 0x48, 0x01, 0x90, 0x10, 0x20, 0x02, 0x90, 0x03, 0x20, 0x03, 0x21, 0x04, 0x22, 0x04, 0x23
	.byte 0xC9, 0xF1, 0x9A, 0xFB, 0x10, 0xE0, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0x1F, 0x00, 0x00
	.byte 0x04, 0x20, 0x00, 0x90, 0x0E, 0x48, 0x01, 0x90, 0x01, 0x20, 0x02, 0x90, 0x03, 0x20, 0x03, 0x21
	.byte 0x04, 0x22, 0x04, 0x23, 0xC9, 0xF1, 0x88, 0xFB, 0xBA, 0x20, 0x80, 0x00, 0x2A, 0x18, 0x10, 0x78
	.byte 0x01, 0x06, 0x08, 0x0E, 0x04, 0x28, 0x11, 0xD9, 0x11, 0x78, 0x08, 0x20, 0x40, 0x1A, 0x40, 0x10
	.byte 0x04, 0x4A, 0xA9, 0x18, 0x08, 0x70, 0x04, 0x48, 0x29, 0x18, 0x01, 0x20, 0x08, 0x70, 0x0D, 0xE0
	.byte 0xFF, 0x1F, 0x00, 0x00, 0xE6, 0x02, 0x00, 0x00, 0xE7, 0x02, 0x00, 0x00, 0x49, 0x0E, 0x0E, 0x4A
	.byte 0xA8, 0x18, 0x00, 0x22, 0x01, 0x70, 0x0D, 0x49, 0x68, 0x18, 0x02, 0x70, 0xD6, 0x22, 0x92, 0x00
	.byte 0xAC, 0x18, 0x20, 0x78, 0x29, 0x21, 0xF3, 0xF7, 0x9D, 0xFB, 0x01, 0x1C, 0x28, 0x1C, 0x40, 0x22
	.byte 0xED, 0xF7, 0x38, 0xF9, 0x06, 0x48, 0xCC, 0xF1, 0x93, 0xFF, 0x20, 0x78, 0x05, 0x28, 0x0B, 0xD1
	.byte 0x04, 0x48, 0xCC, 0xF1, 0x8D, 0xFF, 0x0A, 0xE0, 0xE6, 0x02, 0x00, 0x00, 0xE7, 0x02, 0x00, 0x00
	.byte 0xAD, 0x01, 0x00, 0x00, 0xED, 0x02, 0x00, 0x00, 0x06, 0x48, 0xCC, 0xF1, 0x81, 0xFF, 0x06, 0x48
	.byte 0x29, 0x18, 0x00, 0x20, 0x08, 0x80, 0x28, 0x1C, 0x16, 0x21, 0x01, 0x22, 0xED, 0xF7, 0xCA, 0xF9
	.byte 0x5C, 0xE0, 0x00, 0x00, 0x05, 0x03, 0x00, 0x00, 0xF6, 0x03, 0x00, 0x00, 0x28, 0x1C, 0x04, 0x21
	.byte 0xED, 0xF7, 0x1E, 0xFA, 0x0C, 0x4A, 0xA9, 0x18, 0x08, 0x88, 0x01, 0x30, 0x08, 0x80, 0x00, 0x04
	.byte 0x00, 0x0C, 0x05, 0x28, 0x4A, 0xD9, 0x09, 0x49, 0x68, 0x18, 0x00, 0x21, 0x01, 0x80, 0x28, 0x1C
	.byte 0xA2, 0x30, 0x04, 0x70, 0xD7, 0x20, 0x40, 0x00, 0xCC, 0xF1, 0x5A, 0xFF, 0x28, 0x1C, 0x16, 0x21
	.byte 0x02, 0x22, 0xED, 0xF7, 0xA7, 0xF9, 0x39, 0xE0, 0x7E, 0x03, 0x00, 0x00, 0xF6, 0x03, 0x00, 0x00
	.byte 0x28, 0x1C, 0x04, 0x21, 0xED, 0xF7, 0xFC, 0xF9, 0xD6, 0x22, 0x92, 0x00, 0xA8, 0x18, 0x00, 0x78
	.byte 0x12, 0x21, 0xF3, 0xF7, 0x47, 0xFB, 0x01, 0x1C, 0x28, 0x1C, 0x40, 0x22, 0xED, 0xF7, 0xE2, 0xF8
	.byte 0x0E, 0x48, 0x2C, 0x18, 0x20, 0x88, 0x3C, 0x38, 0x20, 0x80, 0x0D, 0x4A, 0xA9, 0x18, 0x08, 0x88
	.byte 0x01, 0x30, 0x08, 0x80, 0x00, 0x04, 0x00, 0x0C, 0x1D, 0x28, 0x17, 0xD9, 0x28, 0x1C, 0x01, 0x21
	.byte 0xED, 0xF7, 0xDE, 0xF9, 0x00, 0x20, 0x20, 0x80, 0x28, 0x1C, 0x16, 0x21, 0x03, 0x22, 0xED, 0xF7
	.byte 0x79, 0xF9, 0x28, 0x1C, 0xFE, 0xF7, 0x0E, 0xFF, 0x08, 0xE0, 0x00, 0x00, 0xF6, 0x03, 0x00, 0x00
	.byte 0x7E, 0x03, 0x00, 0x00, 0x28, 0x1C, 0x05, 0x21, 0xED, 0xF7, 0xCA, 0xF9, 0x05, 0xB0, 0x30, 0xBC
	.byte 0x01, 0xBC, 0x00, 0x47

	thumb_func_start FUN_080738b4
FUN_080738b4: @ 0x080738B4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080738C8 @ =0x0000037D
	adds r0, r4, r1
	ldrb r5, [r0]
	cmp r5, #0
	beq _080738CC
	cmp r5, #1
	beq _08073974
	b _080739D2
	.align 2, 0
_080738C8: .4byte 0x0000037D
_080738CC:
	ldr r2, _08073900 @ =0x0000037E
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _08073924
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0807390C
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _08073904 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _08073908 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _0807391A
	.align 2, 0
_08073900: .4byte 0x0000037E
_08073904: .4byte 0x000002E6
_08073908: .4byte 0x000002E7
_0807390C:
	lsrs r0, r1, #0x19
	ldr r2, _0807394C @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r1, _08073950 @ =0x000002E7
	adds r0, r4, r1
	strb r5, [r0]
_0807391A:
	ldr r2, _08073954 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_08073924:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x12
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _08073958 @ =0x000003F6
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0x1e
	bls _0807395C
	subs r0, #0x1e
	strh r0, [r1]
	b _080739D2
	.align 2, 0
_0807394C: .4byte 0x000002E6
_08073950: .4byte 0x000002E7
_08073954: .4byte 0x0000037E
_08073958: .4byte 0x000003F6
_0807395C:
	movs r0, #0
	strh r0, [r1]
	movs r0, #0xd8
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #0x17
	movs r2, #1
	bl FUN_08060b84
	b _080739D2
_08073974:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x13
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _080739D2
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r2, [r0]
	cmp r2, #4
	bls _080739B8
	movs r0, #8
	subs r0, r0, r2
	ldr r2, _080739B0 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r1, _080739B4 @ =0x000002E7
	adds r0, r4, r1
	strb r5, [r0]
	b _080739C6
	.align 2, 0
_080739B0: .4byte 0x000002E6
_080739B4: .4byte 0x000002E7
_080739B8:
	ldr r1, _080739D8 @ =0x000002E6
	adds r0, r4, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _080739DC @ =0x000002E7
	adds r0, r4, r2
	strb r1, [r0]
_080739C6:
	adds r0, r4, #0
	bl FUN_08072620
	adds r0, r4, #0
	bl FUN_080726b4
_080739D2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080739D8: .4byte 0x000002E6
_080739DC: .4byte 0x000002E7

	thumb_func_start FUN_080739e0
FUN_080739e0: @ 0x080739E0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080739F8 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080739FC
	cmp r0, #1
	bne _080739F4
	b _08073B08
_080739F4:
	b _08073B36
	.align 2, 0
_080739F8: .4byte 0x0000037D
_080739FC:
	ldr r2, _08073A30 @ =0x0000037E
	adds r0, r4, r2
	ldrh r3, [r0]
	cmp r3, #0
	bne _08073A6E
	movs r5, #0xba
	lsls r5, r5, #2
	adds r2, r4, r5
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _08073A38
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _08073A34 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	subs r5, #1
	adds r1, r4, r5
	movs r0, #1
	strb r0, [r1]
	b _08073A46
	.align 2, 0
_08073A30: .4byte 0x0000037E
_08073A34: .4byte 0x000002E6
_08073A38:
	lsrs r0, r1, #0x19
	ldr r2, _08073AA0 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r5, _08073AA4 @ =0x000002E7
	adds r0, r4, r5
	strb r3, [r0]
_08073A46:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r0, #0xe6
	bl PlaySound_082406e0
	ldr r2, _08073AA8 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_08073A6E:
	movs r5, #0xba
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08073AAC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	ldr r5, _08073AB0 @ =0x000004A4
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _08073AB4
	asrs r0, r0, #0xc
	b _08073ABA
	.align 2, 0
_08073AA0: .4byte 0x000002E6
_08073AA4: .4byte 0x000002E7
_08073AA8: .4byte 0x0000037E
_08073AAC: .4byte 0x085B0A08
_08073AB0: .4byte 0x000004A4
_08073AB4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08073ABA:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r5, _08073AD8 @ =0x000004A4
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _08073ADC
	asrs r0, r0, #0xc
	b _08073AE2
	.align 2, 0
_08073AD8: .4byte 0x000004A4
_08073ADC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08073AE2:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
	ldr r0, _08073B04 @ =0x000004A4
	adds r2, r4, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	cmp r0, #0
	bne _08073B36
	adds r0, r4, #0
	movs r1, #0x18
	movs r2, #1
	bl FUN_08060b84
	b _08073B36
	.align 2, 0
_08073B04: .4byte 0x000004A4
_08073B08:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x2a
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08073B36
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	bl FUN_08072620
	adds r0, r4, #0
	bl FUN_080726b4
_08073B36:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08073b3c
FUN_08073b3c: @ 0x08073B3C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _08073B58 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bls _08073B4C
	b _08073E0E
_08073B4C:
	lsls r0, r0, #2
	ldr r1, _08073B5C @ =_08073B60
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08073B58: .4byte 0x0000037D
_08073B5C: .4byte _08073B60
_08073B60: @ jump table
	.4byte _08073B78 @ case 0
	.4byte _08073BB4 @ case 1
	.4byte _08073CD8 @ case 2
	.4byte _08073D7C @ case 3
	.4byte _08073DC4 @ case 4
	.4byte _08073E0E @ case 5
_08073B78:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r5, _08073BB0 @ =0x0000037E
	adds r1, r4, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi _08073BA4
	b _08073E0E
_08073BA4:
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #1
	bl FUN_08060b84
	b _08073E0E
	.align 2, 0
_08073BB0: .4byte 0x0000037E
_08073BB4:
	ldr r1, _08073C14 @ =0x0000037E
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08073BC8
	ldr r2, _08073C18 @ =0x000003F6
	adds r1, r4, r2
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
_08073BC8:
	movs r5, #0xd6
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrb r0, [r0]
	movs r1, #0x2b
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08073C1C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r5, _08073C20 @ =0x000004A4
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _08073C24
	asrs r0, r0, #0xc
	b _08073C2A
	.align 2, 0
_08073C14: .4byte 0x0000037E
_08073C18: .4byte 0x000003F6
_08073C1C: .4byte 0x085B0A08
_08073C20: .4byte 0x000004A4
_08073C24:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08073C2A:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	ldr r1, _08073C48 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r5, _08073C4C @ =0x000004A4
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _08073C50
	asrs r0, r0, #0xc
	b _08073C56
	.align 2, 0
_08073C48: .4byte 0x085B0A08
_08073C4C: .4byte 0x000004A4
_08073C50:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08073C56:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
	ldr r0, _08073C84 @ =0x000004A4
	adds r2, r4, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	ldr r1, _08073C88 @ =0x0000037E
	adds r3, r4, r1
	ldrh r0, [r3]
	cmp r0, #3
	bls _08073C94
	ldr r2, _08073C8C @ =0x000003F6
	adds r1, r4, r2
	ldrh r2, [r1]
	lsls r0, r0, #3
	cmp r2, r0
	blt _08073C90
	subs r0, r2, r0
	b _08073C92
	.align 2, 0
_08073C84: .4byte 0x000004A4
_08073C88: .4byte 0x0000037E
_08073C8C: .4byte 0x000003F6
_08073C90:
	movs r0, #0
_08073C92:
	strh r0, [r1]
_08073C94:
	ldr r5, _08073CCC @ =0x0000037E
	adds r1, r4, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r1, _08073CD0 @ =0x000004A4
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0x13
	bls _08073CAA
	b _08073E0E
_08073CAA:
	ldr r2, _08073CD4 @ =0x000003F6
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08073CB6
	b _08073E0E
_08073CB6:
	strh r0, [r1]
	movs r0, #0xaa
	lsls r0, r0, #2
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #2
	bl FUN_08060b84
	b _08073E0E
	.align 2, 0
_08073CCC: .4byte 0x0000037E
_08073CD0: .4byte 0x000004A4
_08073CD4: .4byte 0x000003F6
_08073CD8:
	movs r5, #0xba
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08073D0C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	ldr r5, _08073D10 @ =0x000004A4
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _08073D14
	asrs r0, r0, #0xc
	b _08073D1A
	.align 2, 0
_08073D0C: .4byte 0x085B0A08
_08073D10: .4byte 0x000004A4
_08073D14:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08073D1A:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r5, _08073D38 @ =0x000004A4
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _08073D3C
	asrs r0, r0, #0xc
	b _08073D42
	.align 2, 0
_08073D38: .4byte 0x000004A4
_08073D3C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08073D42:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x2c
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08073E0E
	ldr r2, _08073D78 @ =0x000004A4
	adds r1, r4, r2
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #3
	bl FUN_08060b84
	b _08073E0E
	.align 2, 0
_08073D78: .4byte 0x000004A4
_08073D7C:
	ldr r5, _08073DB0 @ =0x0000037E
	adds r1, r4, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bls _08073E0E
	ldr r0, _08073DB4 @ =0x000004A6
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08073DB8
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #5
	bl FUN_08060b84
	adds r0, r4, #0
	bl FUN_080726b4
	b _08073E0E
	.align 2, 0
_08073DB0: .4byte 0x0000037E
_08073DB4: .4byte 0x000004A6
_08073DB8:
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #4
	bl FUN_08060b84
	b _08073E0E
_08073DC4:
	ldr r1, _08073E14 @ =0x0000037E
	adds r5, r4, r1
	ldrh r0, [r5]
	cmp r0, #0
	bne _08073DDA
	movs r0, #0xdb
	bl PlaySound_082406e0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_08073DDA:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0x2d
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08073E0E
	movs r0, #0xd0
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	bl FUN_08072620
	adds r0, r4, #0
	bl FUN_080726b4
_08073E0E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08073E14: .4byte 0x0000037E

	thumb_func_start FUN_08073e18
FUN_08073e18: @ 0x08073E18
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _08073E68 @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _08073E28
	b _08073F3C
_08073E28:
	cmp r0, #1
	ble _08073E2E
	b _08073F82
_08073E2E:
	cmp r0, #0
	beq _08073E34
	b _08073F82
_08073E34:
	ldr r2, _08073E6C @ =0x0000037E
	adds r0, r5, r2
	ldrh r3, [r0]
	cmp r3, #0
	bne _08073EA6
	movs r4, #0xba
	lsls r4, r4, #2
	adds r2, r5, r4
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _08073E74
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _08073E70 @ =0x000002E6
	adds r1, r5, r2
	strb r0, [r1]
	subs r4, #1
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
	b _08073E82
	.align 2, 0
_08073E68: .4byte 0x0000037D
_08073E6C: .4byte 0x0000037E
_08073E70: .4byte 0x000002E6
_08073E74:
	lsrs r0, r1, #0x19
	ldr r2, _08073ED8 @ =0x000002E6
	adds r1, r5, r2
	strb r0, [r1]
	ldr r4, _08073EDC @ =0x000002E7
	adds r0, r5, r4
	strb r3, [r0]
_08073E82:
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r4, r5, r0
	ldrb r0, [r4]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldrb r0, [r4]
	cmp r0, #5
	beq _08073EA6
	movs r0, #0xe7
	bl PlaySound_082406e0
_08073EA6:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08073EE0 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	ldr r4, _08073EE4 @ =0x000004A4
	adds r0, r5, r4
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _08073EE8
	asrs r0, r0, #0xc
	b _08073EEE
	.align 2, 0
_08073ED8: .4byte 0x000002E6
_08073EDC: .4byte 0x000002E7
_08073EE0: .4byte 0x085B0A08
_08073EE4: .4byte 0x000004A4
_08073EE8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08073EEE:
	rsbs r0, r0, #0
	strh r0, [r5, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r4, _08073F0C @ =0x000004A4
	adds r0, r5, r4
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _08073F10
	asrs r0, r0, #0xc
	b _08073F16
	.align 2, 0
_08073F0C: .4byte 0x000004A4
_08073F10:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08073F16:
	rsbs r0, r0, #0
	strh r0, [r5, #0x38]
	ldr r0, _08073F38 @ =0x000004A4
	adds r2, r5, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	cmp r0, #0
	bne _08073F82
	adds r0, r5, #0
	movs r1, #0x18
	movs r2, #1
	bl FUN_08060b84
	b _08073F82
	.align 2, 0
_08073F38: .4byte 0x000004A4
_08073F3C:
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #3
	bne _08073F56
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _08073F56
	movs r0, #0xd1
	bl PlaySound_082406e0
_08073F56:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x2e
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08073F82
	adds r0, r5, #0
	movs r1, #0x18
	movs r2, #2
	bl FUN_08060b84
	adds r0, r5, #0
	bl FUN_080726b4
_08073F82:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08073f88
FUN_08073f88: @ 0x08073F88
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r1, r5, r0
	ldrb r2, [r1]
	movs r6, #0x40
	cmp r2, #1
	bne _08073F9C
	movs r6, #0x30
_08073F9C:
	ldr r3, _08073FB0 @ =0x0000037D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #1
	beq _08073FE6
	cmp r0, #1
	bgt _08073FB4
	cmp r0, #0
	beq _08073FBE
	b _080740A6
	.align 2, 0
_08073FB0: .4byte 0x0000037D
_08073FB4:
	cmp r0, #2
	beq _08073FFA
	cmp r0, #3
	beq _08074088
	b _080740A6
_08073FBE:
	ldrb r0, [r1]
	movs r1, #0x15
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_08060a24
	cmp r0, #0
	beq _080740A6
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	bl FUN_08060b84
	adds r0, r5, #0
	bl FUN_080726b4
	b _080740A6
_08073FE6:
	ldrb r0, [r1]
	movs r1, #0x16
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	b _080740A6
_08073FFA:
	ldr r1, _08074014 @ =0x0000037E
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08074028
	cmp r2, #0
	bne _08074018
	movs r0, #0xe3
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _0807401E
	.align 2, 0
_08074014: .4byte 0x0000037E
_08074018:
	ldr r0, _08074080 @ =0x0000038B
	bl PlaySound_082406e0
_0807401E:
	ldr r3, _08074084 @ =0x0000037E
	adds r1, r5, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_08074028:
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r4, r5, r0
	ldrb r0, [r4]
	movs r1, #0x17
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_08060a24
	adds r6, r0, #0
	ldrb r0, [r4]
	cmp r0, #1
	bne _0807406E
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #2
	bne _0807406E
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _0807406E
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x2c
	adds r0, r5, #0
	bl FUN_0806185c
_0807406E:
	cmp r6, #0
	beq _080740A6
	adds r0, r5, #0
	movs r1, #3
	movs r2, #3
	bl FUN_08060b84
	b _080740A6
	.align 2, 0
_08074080: .4byte 0x0000038B
_08074084: .4byte 0x0000037E
_08074088:
	ldr r3, _080740AC @ =0x0000037E
	adds r1, r5, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _080740A6
	adds r0, r5, #0
	bl FUN_08072620
	adds r0, r5, #0
	bl FUN_080726b4
_080740A6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080740AC: .4byte 0x0000037E

	thumb_func_start FUN_080740b0
FUN_080740b0: @ 0x080740B0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080740D2
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080740D6
_080740D2:
	movs r6, #0x30
	b _080740D8
_080740D6:
	movs r6, #0x40
_080740D8:
	ldr r1, _080740F0 @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #4
	bls _080740E4
	b _0807423C
_080740E4:
	lsls r0, r0, #2
	ldr r1, _080740F4 @ =_080740F8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080740F0: .4byte 0x0000037D
_080740F4: .4byte _080740F8
_080740F8: @ jump table
	.4byte _0807410C @ case 0
	.4byte _0807413C @ case 1
	.4byte _08074156 @ case 2
	.4byte _080741EC @ case 3
	.4byte _08074214 @ case 4
_0807410C:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x18
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_08060a24
	cmp r0, #0
	bne _0807412A
	b _0807423C
_0807412A:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	bl FUN_08060b84
	adds r0, r5, #0
	bl FUN_080726b4
	b _0807423C
_0807413C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x19
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	b _0807423C
_08074156:
	ldr r2, _08074174 @ =0x0000037E
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _0807418C
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0807417C
	ldr r0, _08074178 @ =0x0000038F
	bl PlaySound_082406e0
	b _08074182
	.align 2, 0
_08074174: .4byte 0x0000037E
_08074178: .4byte 0x0000038F
_0807417C:
	ldr r0, _080741E4 @ =0x0000038D
	bl PlaySound_082406e0
_08074182:
	ldr r2, _080741E8 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0807418C:
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r4, r5, r0
	ldrb r0, [r4]
	movs r1, #0x1c
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_08060a24
	adds r6, r0, #0
	ldrb r0, [r4]
	cmp r0, #1
	bne _080741D4
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #1
	bne _080741D4
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _080741D4
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x2c
	adds r0, r5, #0
	movs r3, #0
	bl FUN_08061970
_080741D4:
	cmp r6, #0
	beq _0807423C
	adds r0, r5, #0
	movs r1, #3
	movs r2, #3
	bl FUN_08060b84
	b _0807423C
	.align 2, 0
_080741E4: .4byte 0x0000038D
_080741E8: .4byte 0x0000037E
_080741EC:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x18
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_08060a24
	cmp r0, #0
	beq _0807423C
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl FUN_08060b84
	b _0807423C
_08074214:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x19
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_08060a24
	cmp r0, #0
	beq _0807423C
	adds r0, r5, #0
	bl FUN_08072620
	adds r0, r5, #0
	bl FUN_080726b4
_0807423C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08074244:
	.byte 0x70, 0xB5, 0x05, 0x1C, 0xD6, 0x20, 0x80, 0x00, 0x29, 0x18, 0x0A, 0x78
	.byte 0x40, 0x26, 0x01, 0x2A, 0x00, 0xD1, 0x30, 0x26, 0x04, 0x4B, 0xE8, 0x18, 0x00, 0x78, 0x01, 0x28
	.byte 0x1D, 0xD0, 0x01, 0x28, 0x04, 0xDC, 0x00, 0x28, 0x05, 0xD0, 0x69, 0xE0, 0x7D, 0x03, 0x00, 0x00
	.byte 0x02, 0x28, 0x1E, 0xD0, 0x64, 0xE0, 0x08, 0x78, 0x1D, 0x21, 0xF2, 0xF7, 0x33, 0xFE, 0x01, 0x1C
	.byte 0x28, 0x1C, 0x32, 0x1C, 0xEC, 0xF7, 0xCE, 0xFB, 0x00, 0x28, 0x59, 0xD0, 0x28, 0x1C, 0x03, 0x21
	.byte 0x01, 0x22, 0xEC, 0xF7, 0x77, 0xFC, 0x28, 0x1C, 0xFE, 0xF7, 0x0C, 0xFA, 0x50, 0xE0, 0x08, 0x78
	.byte 0x1E, 0x21, 0xF2, 0xF7, 0x1F, 0xFE, 0x01, 0x1C, 0x28, 0x1C, 0x32, 0x1C, 0xEC, 0xF7, 0xBA, 0xFB
	.byte 0x46, 0xE0, 0x00, 0x2A, 0x0C, 0xD1, 0x05, 0x49, 0x68, 0x18, 0x00, 0x88, 0x11, 0x28, 0x0F, 0xD1
	.byte 0xE4, 0x20, 0x80, 0x00, 0xCC, 0xF1, 0x0C, 0xFA, 0x0A, 0xE0, 0x00, 0x00, 0x7E, 0x03, 0x00, 0x00
	.byte 0x1D, 0x4B, 0xE8, 0x18, 0x00, 0x88, 0x0B, 0x28, 0x02, 0xD1, 0x1C, 0x48, 0xCC, 0xF1, 0x00, 0xFA
	.byte 0x19, 0x48, 0x29, 0x18, 0x08, 0x88, 0x01, 0x30, 0x08, 0x80, 0xD6, 0x21, 0x89, 0x00, 0x6C, 0x18
	.byte 0x20, 0x78, 0x1F, 0x21, 0xF2, 0xF7, 0xF6, 0xFD, 0x01, 0x1C, 0x28, 0x1C, 0x32, 0x1C, 0xEC, 0xF7
	.byte 0x91, 0xFB, 0x06, 0x1C, 0x20, 0x78, 0x01, 0x28, 0x12, 0xD1, 0x28, 0x1C, 0x9C, 0x30, 0x00, 0x88
	.byte 0x05, 0x28, 0x0D, 0xD1, 0x28, 0x1C, 0x94, 0x30, 0x00, 0x88, 0x00, 0x28, 0x08, 0xD1, 0xBA, 0x23
	.byte 0x9B, 0x00, 0xE8, 0x18, 0x01, 0x78, 0x2A, 0x1C, 0x2C, 0x32, 0x28, 0x1C, 0xED, 0xF7, 0xB4, 0xFB
	.byte 0x00, 0x2E, 0x05, 0xD0, 0x28, 0x1C, 0xFE, 0xF7, 0x73, 0xF9, 0x28, 0x1C, 0xFE, 0xF7, 0xBA, 0xF9
	.byte 0x70, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x7E, 0x03, 0x00, 0x00, 0x8E, 0x03, 0x00, 0x00

	thumb_func_start FUN_08074350
FUN_08074350: @ 0x08074350
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _0807436C
	ldr r0, _08074368 @ =0x00000951
	adds r1, r4, r0
	movs r0, #9
	b _08074372
	.align 2, 0
_08074368: .4byte 0x00000951
_0807436C:
	ldr r0, _0807438C @ =0x00000951
	adds r1, r4, r0
	movs r0, #8
_08074372:
	strb r0, [r1]
	ldr r1, _08074390 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bls _08074380
	b _080744B4
_08074380:
	lsls r0, r0, #2
	ldr r1, _08074394 @ =_08074398
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807438C: .4byte 0x00000951
_08074390: .4byte 0x0000037D
_08074394: .4byte _08074398
_08074398: @ jump table
	.4byte _080743B0 @ case 0
	.4byte _080743E8 @ case 1
	.4byte _08074402 @ case 2
	.4byte _0807442A @ case 3
	.4byte _08074452 @ case 4
	.4byte _0807448C @ case 5
_080743B0:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x23
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _080744B4
	ldr r0, _080743E4 @ =0x000001F7
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #3
	movs r2, #1
	bl FUN_08060b84
	adds r0, r4, #0
	bl FUN_080726b4
	b _080744B4
	.align 2, 0
_080743E4: .4byte 0x000001F7
_080743E8:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	b _080744B4
_08074402:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _080744B4
	adds r0, r4, #0
	movs r1, #3
	movs r2, #3
	bl FUN_08060b84
	b _080744B4
_0807442A:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x25
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _080744B4
	adds r0, r4, #0
	movs r1, #3
	movs r2, #4
	bl FUN_08060b84
	b _080744B4
_08074452:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _08074488 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls _080744B4
	adds r0, r4, #0
	movs r1, #3
	movs r2, #5
	bl FUN_08060b84
	b _080744B4
	.align 2, 0
_08074488: .4byte 0x0000037E
_0807448C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x23
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _080744B4
	adds r0, r4, #0
	bl FUN_08072620
	adds r0, r4, #0
	bl FUN_080726b4
_080744B4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080744BC:
	.byte 0x30, 0xB5, 0x04, 0x1C
	.byte 0x07, 0x49, 0x60, 0x18, 0x04, 0x21, 0x01, 0x70, 0x06, 0x49, 0x60, 0x18, 0x00, 0x78, 0x07, 0x28
	.byte 0x00, 0xD9, 0x07, 0xE1, 0x80, 0x00, 0x04, 0x49, 0x40, 0x18, 0x00, 0x68, 0x87, 0x46, 0x00, 0x00
	.byte 0x51, 0x09, 0x00, 0x00, 0x7D, 0x03, 0x00, 0x00, 0xEC, 0x44, 0x07, 0x08, 0x0C, 0x45, 0x07, 0x08
	.byte 0x3C, 0x45, 0x07, 0x08, 0x8C, 0x45, 0x07, 0x08, 0xE0, 0x45, 0x07, 0x08, 0x20, 0x46, 0x07, 0x08
	.byte 0x3A, 0x46, 0x07, 0x08, 0x80, 0x46, 0x07, 0x08, 0xBC, 0x46, 0x07, 0x08, 0xD6, 0x21, 0x89, 0x00
	.byte 0x60, 0x18, 0x00, 0x78, 0x26, 0x21, 0xF2, 0xF7, 0xE5, 0xFC, 0x01, 0x1C, 0x20, 0x1C, 0x40, 0x22
	.byte 0xEC, 0xF7, 0x80, 0xFA, 0x00, 0x28, 0x00, 0xD1, 0xDC, 0xE0, 0x03, 0x48, 0xCC, 0xF1, 0xD8, 0xF8
	.byte 0x20, 0x1C, 0x03, 0x21, 0x01, 0x22, 0x6B, 0xE0, 0xF7, 0x01, 0x00, 0x00, 0xD6, 0x21, 0x89, 0x00
	.byte 0x60, 0x18, 0x00, 0x78, 0x27, 0x21, 0xF2, 0xF7, 0xCD, 0xFC, 0x01, 0x1C, 0x20, 0x1C, 0x40, 0x22
	.byte 0xEC, 0xF7, 0x68, 0xFA, 0x0B, 0x48, 0x21, 0x18, 0x08, 0x88, 0x01, 0x30, 0x08, 0x80, 0x00, 0x04
	.byte 0x00, 0x0C, 0x05, 0x28, 0x00, 0xD8, 0xBD, 0xE0, 0x20, 0x1C, 0x03, 0x21, 0x02, 0x22, 0xEC, 0xF7
	.byte 0x09, 0xFB, 0x05, 0x49, 0x60, 0x18, 0x02, 0x78, 0x20, 0x1C, 0x20, 0x21, 0x4D, 0xF0, 0x9E, 0xFA
	.byte 0xB0, 0xE0, 0x00, 0x00, 0x7E, 0x03, 0x00, 0x00, 0xA7, 0x04, 0x00, 0x00, 0xD6, 0x21, 0x89, 0x00
	.byte 0x60, 0x18, 0x00, 0x78, 0x27, 0x21, 0xF2, 0xF7, 0xA5, 0xFC, 0x01, 0x1C, 0x20, 0x1C, 0x40, 0x22
	.byte 0xEC, 0xF7, 0x40, 0xFA, 0x0C, 0x48, 0x25, 0x18, 0x28, 0x88, 0x06, 0x28, 0x02, 0xD1, 0x0B, 0x48
	.byte 0xCC, 0xF1, 0x96, 0xF8, 0x28, 0x88, 0x01, 0x30, 0x28, 0x80, 0x00, 0x04, 0x00, 0x0C, 0x3B, 0x28
	.byte 0x00, 0xD8, 0x8F, 0xE0, 0x9E, 0x20, 0x80, 0x00, 0xCC, 0xF1, 0x8A, 0xF8, 0x20, 0x1C, 0x03, 0x21
	.byte 0x03, 0x22, 0xEC, 0xF7, 0xD7, 0xFA, 0x85, 0xE0, 0x7E, 0x03, 0x00, 0x00, 0x77, 0x02, 0x00, 0x00
	.byte 0xD6, 0x21, 0x89, 0x00, 0x60, 0x18, 0x00, 0x78, 0x27, 0x21, 0xF2, 0xF7, 0x7B, 0xFC, 0x01, 0x1C
	.byte 0x20, 0x1C, 0x40, 0x22, 0xEC, 0xF7, 0x16, 0xFA, 0x08, 0x48, 0x21, 0x18, 0x08, 0x88, 0x01, 0x30
	.byte 0x08, 0x80, 0x00, 0x04, 0x00, 0x0C, 0x07, 0x28, 0x6C, 0xD9, 0x20, 0x1C, 0x03, 0x21, 0x04, 0x22
	.byte 0xEC, 0xF7, 0xB8, 0xFA, 0x20, 0x1C, 0xFE, 0xF7, 0x4D, 0xF8, 0x63, 0xE0, 0x7E, 0x03, 0x00, 0x00
	.byte 0xD6, 0x21, 0x89, 0x00, 0x60, 0x18, 0x00, 0x78, 0x27, 0x21, 0xF2, 0xF7, 0x5B, 0xFC, 0x01, 0x1C
	.byte 0x20, 0x1C, 0x40, 0x22, 0xEC, 0xF7, 0xF6, 0xF9, 0x54, 0xE0, 0x10, 0x48, 0x25, 0x18, 0x28, 0x88
	.byte 0x00, 0x28, 0x06, 0xD1, 0xFB, 0x20, 0x40, 0x00, 0xCC, 0xF1, 0x4A, 0xF8, 0x28, 0x88, 0x01, 0x30
	.byte 0x28, 0x80, 0xD6, 0x21, 0x89, 0x00, 0x60, 0x18, 0x00, 0x78, 0x28, 0x21, 0xF2, 0xF7, 0x42, 0xFC
	.byte 0x01, 0x1C, 0x20, 0x1C, 0x40, 0x22, 0xEC, 0xF7, 0xDD, 0xF9, 0x00, 0x28, 0x3A, 0xD0, 0x20, 0x1C
	.byte 0x03, 0x21, 0x06, 0x22, 0xEC, 0xF7, 0x86, 0xFA, 0x34, 0xE0, 0x00, 0x00, 0x7E, 0x03, 0x00, 0x00
	.byte 0xD6, 0x21, 0x89, 0x00, 0x60, 0x18, 0x00, 0x78, 0x27, 0x21, 0xF2, 0xF7, 0x2B, 0xFC, 0x01, 0x1C
	.byte 0x20, 0x1C, 0x40, 0x22, 0xEC, 0xF7, 0xC6, 0xF9, 0x07, 0x48, 0x21, 0x18, 0x08, 0x88, 0x01, 0x30
	.byte 0x08, 0x80, 0x00, 0x04, 0x00, 0x0C, 0x0E, 0x28, 0x1C, 0xD9, 0x20, 0x1C, 0x03, 0x21, 0x07, 0x22
	.byte 0xEC, 0xF7, 0x68, 0xFA, 0x16, 0xE0, 0x00, 0x00, 0x7E, 0x03, 0x00, 0x00, 0xD6, 0x21, 0x89, 0x00
	.byte 0x60, 0x18, 0x00, 0x78, 0x26, 0x21, 0xF2, 0xF7, 0x0D, 0xFC, 0x01, 0x1C, 0x20, 0x1C, 0x40, 0x22
	.byte 0xEC, 0xF7, 0xA8, 0xF9, 0x00, 0x28, 0x05, 0xD0, 0x20, 0x1C, 0xFD, 0xF7, 0xA1, 0xFF, 0x20, 0x1C
	.byte 0xFD, 0xF7, 0xE8, 0xFF, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0xF0, 0xB5, 0x57, 0x46
	.byte 0x4E, 0x46, 0x45, 0x46, 0xE0, 0xB4, 0x06, 0x1C, 0x1D, 0x48, 0x80, 0x19, 0x81, 0x46, 0x00, 0x88
	.byte 0x00, 0x28, 0x03, 0xD1, 0xA6, 0x20, 0x80, 0x00, 0xCB, 0xF1, 0xEA, 0xFF, 0x19, 0x49, 0x89, 0x19
	.byte 0x88, 0x46, 0x00, 0x22, 0x8D, 0x5E, 0x2C, 0x23, 0xF0, 0x5E, 0x2D, 0x1A, 0x94, 0x20, 0xC0, 0x00
	.byte 0x37, 0x18, 0x00, 0x21, 0x7C, 0x5E, 0x30, 0x22, 0xB0, 0x5E, 0x24, 0x1A, 0x28, 0x1C, 0x21, 0x1C
	.byte 0xC3, 0xF1, 0x94, 0xF8, 0x82, 0x46, 0x29, 0x1C, 0x69, 0x43, 0x20, 0x1C, 0x60, 0x43, 0x0C, 0x18
	.byte 0x80, 0x20, 0xC0, 0x00, 0x84, 0x42, 0x57, 0xDC, 0x43, 0x46, 0x18, 0x88, 0xB0, 0x85, 0x38, 0x88
	.byte 0x30, 0x86, 0x09, 0x48, 0x31, 0x18, 0x0A, 0x78, 0x00, 0x20, 0x08, 0x56, 0x00, 0x28, 0x0D, 0xDB
	.byte 0xBA, 0x23, 0x9B, 0x00, 0xF0, 0x18, 0x02, 0x70, 0xFF, 0x20, 0x08, 0x70, 0x14, 0xE0, 0x00, 0x00
	.byte 0x7E, 0x03, 0x00, 0x00, 0x9C, 0x04, 0x00, 0x00, 0xA9, 0x04, 0x00, 0x00, 0x51, 0x46, 0x08, 0x04
	.byte 0x00, 0x0C, 0x10, 0x30, 0xFF, 0x21, 0x08, 0x40, 0x40, 0x11, 0x03, 0x30, 0x07, 0x21, 0x01, 0x40
	.byte 0xBA, 0x22, 0x92, 0x00, 0xB0, 0x18, 0x01, 0x70, 0xBA, 0x23, 0x9B, 0x00, 0xF0, 0x18, 0x02, 0x78
	.byte 0x04, 0x2A, 0x0B, 0xD9, 0x08, 0x20, 0x80, 0x1A, 0x03, 0x4A, 0xB1, 0x18, 0x08, 0x70, 0x01, 0x3B
	.byte 0xF1, 0x18, 0x01, 0x20, 0x08, 0x70, 0x08, 0xE0, 0xE6, 0x02, 0x00, 0x00, 0x0C, 0x49, 0x70, 0x18
	.byte 0x00, 0x21, 0x02, 0x70, 0x0B, 0x4A, 0xB0, 0x18, 0x01, 0x70, 0xD6, 0x23, 0x9B, 0x00, 0xF0, 0x18
	.byte 0x00, 0x78, 0x00, 0x21, 0xF2, 0xF7, 0x86, 0xFB, 0x01, 0x1C, 0x30, 0x1C, 0x40, 0x22, 0xEC, 0xF7
	.byte 0x21, 0xF9, 0x30, 0x1C, 0xFD, 0xF7, 0x1C, 0xFF, 0x30, 0x1C, 0xFD, 0xF7, 0x63, 0xFF, 0xC6, 0xE0
	.byte 0xE6, 0x02, 0x00, 0x00, 0xE7, 0x02, 0x00, 0x00, 0x30, 0x1C, 0x04, 0x21, 0xEC, 0xF7, 0x20, 0xFA
	.byte 0x49, 0x46, 0x08, 0x88, 0x03, 0x28, 0x0D, 0xD8, 0x04, 0x4A, 0xB1, 0x18, 0x04, 0x48, 0x08, 0x80
	.byte 0x96, 0x23, 0x1B, 0x01, 0xF1, 0x18, 0x18, 0x20, 0x08, 0x80, 0x07, 0xE0, 0x5E, 0x09, 0x00, 0x00
	.byte 0x27, 0x01, 0x00, 0x00, 0x80, 0x20, 0xC0, 0x01, 0x84, 0x42, 0x04, 0xDC, 0x30, 0x1C, 0x02, 0x21
	.byte 0xEC, 0xF7, 0x06, 0xFA, 0x0C, 0xE0, 0x10, 0x48, 0x31, 0x18, 0x10, 0x48, 0x08, 0x80, 0x96, 0x22
	.byte 0x12, 0x01, 0xB1, 0x18, 0x18, 0x20, 0x08, 0x80, 0x30, 0x1C, 0x01, 0x21, 0xEC, 0xF7, 0xF8, 0xF9
	.byte 0x0B, 0x4B, 0xF1, 0x18, 0x08, 0x88, 0x01, 0x30, 0x08, 0x80, 0x0A, 0x4A, 0x50, 0x46, 0x40, 0x30
	.byte 0xFF, 0x21, 0x08, 0x40, 0x40, 0x00, 0x80, 0x18, 0x00, 0x21, 0x40, 0x5E, 0x20, 0x23, 0x58, 0x43
	.byte 0x00, 0x28, 0x09, 0xDB, 0x00, 0x13, 0x0A, 0xE0, 0x5E, 0x09, 0x00, 0x00, 0x27, 0x01, 0x00, 0x00
	.byte 0x7E, 0x03, 0x00, 0x00, 0x08, 0x0A, 0x5B, 0x08, 0x40, 0x42, 0x00, 0x13, 0x40, 0x42, 0xB0, 0x86
	.byte 0xFF, 0x20, 0x51, 0x46, 0x08, 0x40, 0x40, 0x00, 0x80, 0x18, 0x00, 0x22, 0x80, 0x5E, 0x20, 0x23
	.byte 0x58, 0x43, 0x00, 0x28, 0x01, 0xDB, 0x00, 0x13, 0x02, 0xE0, 0x40, 0x42, 0x00, 0x13, 0x40, 0x42
	.byte 0x30, 0x87, 0x07, 0x4A, 0xB1, 0x18, 0x09, 0x78, 0x01, 0x29, 0x18, 0xD1, 0x00, 0x28, 0x09, 0xDA
	.byte 0x38, 0x23, 0xF1, 0x5E, 0x88, 0x00, 0x40, 0x18, 0xC0, 0x00, 0x00, 0x28, 0x08, 0xDA, 0x09, 0xE0
	.byte 0xC7, 0x01, 0x00, 0x00, 0x38, 0x20, 0x31, 0x5E, 0x34, 0x20, 0x48, 0x43, 0x00, 0x28, 0x01, 0xDB
	.byte 0x80, 0x11, 0x02, 0xE0, 0x40, 0x42, 0x80, 0x11, 0x40, 0x42, 0x30, 0x87, 0x18, 0xE0, 0x02, 0x29
	.byte 0x16, 0xD1, 0x34, 0x21, 0x70, 0x5E, 0x00, 0x28, 0x06, 0xDA, 0x01, 0x1C, 0x88, 0x00, 0x40, 0x18
	.byte 0xC0, 0x00, 0x00, 0x28, 0x06, 0xDA, 0x07, 0xE0, 0x34, 0x23, 0xF1, 0x5E, 0x34, 0x20, 0x48, 0x43
	.byte 0x00, 0x28, 0x01, 0xDB, 0x80, 0x11, 0x02, 0xE0, 0x40, 0x42, 0x80, 0x11, 0x40, 0x42, 0xB0, 0x86
	.byte 0x50, 0x46, 0x10, 0x30, 0xFF, 0x21, 0x08, 0x40, 0x40, 0x11, 0xC1, 0x1C, 0x07, 0x20, 0x01, 0x40
	.byte 0xBA, 0x22, 0x92, 0x00, 0xB0, 0x18, 0x01, 0x70, 0x04, 0x29, 0x0D, 0xD9, 0x08, 0x20, 0x40, 0x1A
	.byte 0x03, 0x4B, 0xF1, 0x18, 0x08, 0x70, 0x03, 0x48, 0x31, 0x18, 0x01, 0x20, 0x0A, 0xE0, 0x00, 0x00
	.byte 0xE6, 0x02, 0x00, 0x00, 0xE7, 0x02, 0x00, 0x00, 0x0C, 0x4A, 0xB0, 0x18, 0x01, 0x70, 0x0C, 0x4B
	.byte 0xF1, 0x18, 0x00, 0x20, 0x08, 0x70, 0xD6, 0x21, 0x89, 0x00, 0x70, 0x18, 0x00, 0x78, 0x01, 0x21
	.byte 0xF2, 0xF7, 0xB8, 0xFA, 0x01, 0x1C, 0x30, 0x1C, 0x20, 0x22, 0xEC, 0xF7, 0x53, 0xF8, 0x38, 0xBC
	.byte 0x98, 0x46, 0xA1, 0x46, 0xAA, 0x46, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0xE6, 0x02, 0x00, 0x00
	.byte 0xE7, 0x02, 0x00, 0x00, 0x04, 0x49, 0x42, 0x18, 0x04, 0x49, 0x11, 0x80, 0x96, 0x21, 0x09, 0x01
	.byte 0x40, 0x18, 0x18, 0x21, 0x01, 0x80, 0x70, 0x47, 0x5E, 0x09, 0x00, 0x00, 0x27, 0x01, 0x00, 0x00

	thumb_func_start FUN_080749b0
FUN_080749b0: @ 0x080749B0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _080749C8 @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080749EE
	cmp r0, #1
	bgt _080749CC
	cmp r0, #0
	beq _080749D2
	b _08074A3A
	.align 2, 0
_080749C8: .4byte 0x0000037D
_080749CC:
	cmp r0, #2
	beq _08074A18
	b _08074A3A
_080749D2:
	movs r1, #0x86
	lsls r1, r1, #2
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08074A3A
	adds r0, r5, #0
	movs r1, #0x10
	movs r2, #1
	bl FUN_08060b84
	b _08074A3A
_080749EE:
	ldr r1, _08074A10 @ =0x0000021A
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _08074A14 @ =0x0000037E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _08074A3A
	adds r0, r5, #0
	bl FUN_080726b4
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _08074A3A
	.align 2, 0
_08074A10: .4byte 0x0000021A
_08074A14: .4byte 0x0000037E
_08074A18:
	movs r1, #0x86
	lsls r1, r1, #2
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08074A3A
	adds r0, r5, #0
	bl FUN_080609dc
	adds r0, r5, #0
	bl FUN_08072620
	adds r0, r5, #0
	bl FUN_080726b4
_08074A3A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08074a40
FUN_08074a40: @ 0x08074A40
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r1, _08074A60 @ =0x0000037D
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #7
	bls _08074A54
	b _08074C9A
_08074A54:
	lsls r0, r0, #2
	ldr r1, _08074A64 @ =_08074A68
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08074A60: .4byte 0x0000037D
_08074A64: .4byte _08074A68
_08074A68: @ jump table
	.4byte _08074A88 @ case 0
	.4byte _08074B40 @ case 1
	.4byte _08074B80 @ case 2
	.4byte _08074BB0 @ case 3
	.4byte _08074BF8 @ case 4
	.4byte _08074C14 @ case 5
	.4byte _08074C68 @ case 6
	.4byte _08074C9A @ case 7
_08074A88:
	ldr r2, _08074AAC @ =0x0000037E
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #1
	bls _08074AE0
	ldr r3, _08074AB0 @ =0x000004A9
	adds r0, r6, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0xba
	lsls r1, r1, #2
	adds r2, r6, r1
	ldrb r1, [r2]
	cmp r0, r1
	bge _08074AB4
	subs r0, r1, #1
	b _08074AB6
	.align 2, 0
_08074AAC: .4byte 0x0000037E
_08074AB0: .4byte 0x000004A9
_08074AB4:
	adds r0, r1, #1
_08074AB6:
	movs r1, #7
	ands r0, r1
	strb r0, [r2]
	adds r0, r6, #0
	bl FUN_080609dc
	ldr r2, _08074AD8 @ =0x000002E6
	adds r1, r6, r2
	ldrb r0, [r1]
	subs r0, #1
	movs r2, #0
	strb r0, [r1]
	ldr r3, _08074ADC @ =0x0000037E
	adds r0, r6, r3
	strh r2, [r0]
	b _08074AE4
	.align 2, 0
_08074AD8: .4byte 0x000002E6
_08074ADC: .4byte 0x0000037E
_08074AE0:
	adds r0, #1
	strh r0, [r1]
_08074AE4:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, #0x36
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r6, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r1, [r0]
	ldr r3, _08074B20 @ =0x000004A9
	adds r0, r6, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	beq _08074B14
	b _08074C9A
_08074B14:
	cmp r1, #1
	bne _08074B24
	adds r2, #0x95
	adds r0, r6, r2
	strb r1, [r0]
	b _08074C9A
	.align 2, 0
_08074B20: .4byte 0x000004A9
_08074B24:
	cmp r1, #3
	bne _08074B34
	ldr r3, _08074B30 @ =0x0000037D
	adds r1, r6, r3
	movs r0, #6
	b _08074C98
	.align 2, 0
_08074B30: .4byte 0x0000037D
_08074B34:
	ldr r0, _08074B3C @ =0x0000037D
	adds r1, r6, r0
	movs r0, #4
	b _08074C98
	.align 2, 0
_08074B3C: .4byte 0x0000037D
_08074B40:
	ldr r1, _08074B74 @ =0x000002E6
	adds r0, r6, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _08074B78 @ =0x000002E7
	adds r0, r6, r2
	strb r1, [r0]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r6, r3
	ldrb r0, [r0]
	movs r1, #0x34
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r6, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	bne _08074B6C
	b _08074C9A
_08074B6C:
	ldr r0, _08074B7C @ =0x0000037D
	adds r1, r6, r0
	movs r0, #2
	b _08074C98
	.align 2, 0
_08074B74: .4byte 0x000002E6
_08074B78: .4byte 0x000002E7
_08074B7C: .4byte 0x0000037D
_08074B80:
	ldr r1, _08074BA8 @ =0x000002E6
	adds r0, r6, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _08074BAC @ =0x000002E7
	adds r0, r6, r2
	strb r1, [r0]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r6, r3
	ldrb r0, [r0]
	movs r1, #0x35
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r6, #0
	movs r2, #0x40
	bl FUN_08060a24
	b _08074C9A
	.align 2, 0
_08074BA8: .4byte 0x000002E6
_08074BAC: .4byte 0x000002E7
_08074BB0:
	ldr r0, _08074BE8 @ =0x000002E6
	adds r4, r6, r0
	movs r5, #0
	strb r5, [r4]
	ldr r1, _08074BEC @ =0x000002E7
	adds r0, r6, r1
	strb r5, [r0]
	subs r1, #0xe6
	adds r0, r6, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08074C9A
	adds r0, r6, #0
	bl FUN_080609dc
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	ldr r2, _08074BF0 @ =0x0000037D
	adds r0, r6, r2
	strb r5, [r0]
	ldr r3, _08074BF4 @ =0x0000037E
	adds r0, r6, r3
	strh r5, [r0]
	b _08074C9A
	.align 2, 0
_08074BE8: .4byte 0x000002E6
_08074BEC: .4byte 0x000002E7
_08074BF0: .4byte 0x0000037D
_08074BF4: .4byte 0x0000037E
_08074BF8:
	ldr r0, _08074C0C @ =0x000002E6
	adds r1, r6, r0
	movs r0, #0
	strb r0, [r1]
	ldr r2, _08074C10 @ =0x000002E7
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
	b _08074C76
	.align 2, 0
_08074C0C: .4byte 0x000002E6
_08074C10: .4byte 0x000002E7
_08074C14:
	ldr r2, _08074C58 @ =0x000002E6
	adds r1, r6, r2
	movs r0, #0
	strb r0, [r1]
	ldr r3, _08074C5C @ =0x000002E7
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, #0x38
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r6, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08074C9A
	ldr r2, _08074C60 @ =0x000004A7
	adds r1, r6, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08074C9A
	ldr r3, _08074C64 @ =0x0000037D
	adds r1, r6, r3
	b _08074C96
	.align 2, 0
_08074C58: .4byte 0x000002E6
_08074C5C: .4byte 0x000002E7
_08074C60: .4byte 0x000004A7
_08074C64: .4byte 0x0000037D
_08074C68:
	ldr r1, _08074CAC @ =0x000002E6
	adds r0, r6, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _08074CB0 @ =0x000002E7
	adds r0, r6, r2
	strb r1, [r0]
_08074C76:
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r6, r3
	ldrb r0, [r0]
	movs r1, #0x37
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r6, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08074C9A
	ldr r0, _08074CB4 @ =0x0000037D
	adds r1, r6, r0
_08074C96:
	movs r0, #7
_08074C98:
	strb r0, [r1]
_08074C9A:
	ldr r2, _08074CB8 @ =0x000004AC
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #7
	bhi _08074CBC
	adds r7, r0, #0
	movs r0, #8
	subs r5, r0, r7
	b _08074CC6
	.align 2, 0
_08074CAC: .4byte 0x000002E6
_08074CB0: .4byte 0x000002E7
_08074CB4: .4byte 0x0000037D
_08074CB8: .4byte 0x000004AC
_08074CBC:
	ldrb r1, [r1]
	movs r0, #0x10
	subs r7, r0, r1
	adds r5, r1, #0
	subs r5, #8
_08074CC6:
	lsls r1, r7, #4
	subs r1, r1, r7
	lsls r1, r1, #1
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #2
	subs r0, r0, r5
	adds r1, r1, r0
	asrs r3, r1, #3
	movs r0, #0xd
	mov r8, r0
	mov r0, r8
	muls r0, r7, r0
	lsls r2, r5, #1
	adds r2, r2, r5
	lsls r4, r2, #2
	adds r0, r0, r4
	asrs r0, r0, #3
	movs r1, #0xb0
	lsls r1, r1, #6
	mov ip, r1
	lsls r0, r0, #5
	orrs r0, r1
	orrs r0, r3
	ldr r3, _08074D74 @ =0x000002AE
	adds r1, r6, r3
	strh r0, [r1]
	lsls r0, r7, #5
	subs r0, r0, r7
	lsls r2, r2, #3
	adds r2, r2, r5
	adds r0, r0, r2
	asrs r3, r0, #3
	lsls r0, r7, #3
	adds r0, r0, r7
	lsls r0, r0, #1
	adds r0, r0, r4
	asrs r0, r0, #3
	lsls r0, r0, #5
	mov r1, ip
	orrs r0, r1
	orrs r0, r3
	movs r2, #0xac
	lsls r2, r2, #2
	adds r1, r6, r2
	strh r0, [r1]
	adds r1, r7, r5
	lsls r0, r1, #5
	subs r0, r0, r1
	asrs r3, r0, #3
	movs r0, #0x16
	muls r0, r7, r0
	mov r1, r8
	muls r1, r5, r1
	adds r0, r0, r1
	asrs r0, r0, #3
	lsls r0, r0, #5
	mov r1, ip
	orrs r0, r1
	orrs r0, r3
	adds r2, #0xe
	adds r1, r6, r2
	strh r0, [r1]
	ldr r3, _08074D78 @ =0x000004AC
	adds r1, r6, r3
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bls _08074D5A
	movs r0, #0
	strb r0, [r1]
_08074D5A:
	ldr r3, _08074D7C @ =0x03002B80
	ldrh r0, [r3]
	cmp r0, #0
	beq _08074D86
	ldr r2, _08074D80 @ =0x03002B78
	ldrh r0, [r2]
	adds r1, r0, #0
	cmp r1, #0
	beq _08074D84
	subs r0, #1
	strh r0, [r2]
	b _08074D86
	.align 2, 0
_08074D74: .4byte 0x000002AE
_08074D78: .4byte 0x000004AC
_08074D7C: .4byte 0x03002B80
_08074D80: .4byte 0x03002B78
_08074D84:
	strh r1, [r3]
_08074D86:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08074d90
FUN_08074d90: @ 0x08074D90
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r5, r4, r0
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r2, _08074DE8 @ =0x000002E6
	adds r0, r4, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r4, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_08236fac
	adds r4, #0xe8
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r4, #0x10]
	ldrb r0, [r5, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08074DEC
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	b _08074DF4
	.align 2, 0
_08074DE8: .4byte 0x000002E6
_08074DEC:
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08074DF4:
	str r0, [r4]
	ldrb r0, [r5, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08074E18
	ldr r0, [r4]
	movs r1, #8
	orrs r0, r1
	b _08074E20
_08074E18:
	ldr r0, [r4]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08074E20:
	str r0, [r4]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r1, _08074E58 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r5, #7]
	cmp r0, r1
	blo _08074E90
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08074E5C
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _08074E50
	ldrb r0, [r5, #5]
_08074E50:
	subs r0, #1
	strh r0, [r5, #8]
	b _08074E6C
	.align 2, 0
_08074E58: .4byte 0x0000FFFF
_08074E5C:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _08074E6C
	strh r1, [r5, #8]
_08074E6C:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r5, #6]
	ldrb r1, [r5, #6]
	ldrh r0, [r5, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r5, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08074E90
	movs r0, #1
	strb r0, [r5, #7]
_08074E90:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08074e98
FUN_08074e98: @ 0x08074E98
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _08074F00 @ =0x0000049C
	adds r0, r0, r6
	mov r8, r0
	movs r1, #0
	ldrsh r5, [r0, r1]
	movs r2, #0x2c
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0x94
	lsls r3, r3, #3
	adds r7, r6, r3
	movs r0, #0
	ldrsh r4, [r7, r0]
	movs r1, #0x30
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	adds r3, r0, #0
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	cmp r0, #0x51
	bgt _08074F8C
	mov r2, r8
	ldrh r0, [r2]
	strh r0, [r6, #0x2c]
	ldrh r0, [r7]
	strh r0, [r6, #0x30]
	ldr r4, _08074F04 @ =0x000004A9
	adds r1, r6, r4
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _08074F08
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r6, r3
	strb r2, [r0]
	movs r0, #0xff
	b _08074F22
	.align 2, 0
_08074F00: .4byte 0x0000049C
_08074F04: .4byte 0x000004A9
_08074F08:
	adds r0, r3, #0
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	movs r4, #0xba
	lsls r4, r4, #2
	adds r1, r6, r4
_08074F22:
	strb r0, [r1]
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r6, r0
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _08074F54
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _08074F4C @ =0x000002E6
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _08074F50 @ =0x000002E7
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	b _08074F64
	.align 2, 0
_08074F4C: .4byte 0x000002E6
_08074F50: .4byte 0x000002E7
_08074F54:
	lsrs r1, r1, #0x19
	ldr r4, _08074F80 @ =0x000002E6
	adds r0, r6, r4
	movs r2, #0
	strb r1, [r0]
	ldr r1, _08074F84 @ =0x000002E7
	adds r0, r6, r1
	strb r2, [r0]
_08074F64:
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r6, r2
	ldr r0, _08074F88 @ =FUN_08074d90
	str r0, [r1]
	adds r0, r6, #0
	bl FUN_080726b4
	b _08075028
	.align 2, 0
_08074F80: .4byte 0x000002E6
_08074F84: .4byte 0x000002E7
_08074F88: .4byte FUN_08074d90
_08074F8C:
	ldr r2, _08074FAC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #3
	adds r0, r0, r1
	cmp r0, #0
	blt _08074FB0
	asrs r0, r0, #0xc
	b _08074FB6
	.align 2, 0
_08074FAC: .4byte 0x085B0A08
_08074FB0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08074FB6:
	strh r0, [r6, #0x34]
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #3
	adds r0, r0, r1
	cmp r0, #0
	blt _08074FD0
	asrs r0, r0, #0xc
	b _08074FD6
_08074FD0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08074FD6:
	strh r0, [r6, #0x38]
	adds r0, r3, #0
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r6, r3
	strb r0, [r2]
	lsls r1, r0, #0x18
	cmp r0, #4
	bls _08075018
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r4, _08075010 @ =0x000002E6
	adds r1, r6, r4
	strb r0, [r1]
	ldr r0, _08075014 @ =0x000002E7
	adds r1, r6, r0
	movs r0, #1
	b _08075026
	.align 2, 0
_08075010: .4byte 0x000002E6
_08075014: .4byte 0x000002E7
_08075018:
	lsrs r1, r1, #0x19
	ldr r2, _0807507C @ =0x000002E6
	adds r0, r6, r2
	strb r1, [r0]
	ldr r3, _08075080 @ =0x000002E7
	adds r1, r6, r3
	movs r0, #0
_08075026:
	strb r0, [r1]
_08075028:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _0807507C @ =0x000002E6
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08075084
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0807508C
	.align 2, 0
_0807507C: .4byte 0x000002E6
_08075080: .4byte 0x000002E7
_08075084:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0807508C:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080750B0
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080750B8
_080750B0:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080750B8:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _080750F0 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08075128
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080750F4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080750E8
	ldrb r0, [r4, #5]
_080750E8:
	subs r0, #1
	strh r0, [r4, #8]
	b _08075104
	.align 2, 0
_080750F0: .4byte 0x0000FFFF
_080750F4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08075104
	strh r1, [r4, #8]
_08075104:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08075128
	movs r0, #1
	strb r0, [r4, #7]
_08075128:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08075134
FUN_08075134: @ 0x08075134
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r1, _08075154 @ =0x0000037D
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #5
	bls _08075148
	bl _08075970
_08075148:
	lsls r0, r0, #2
	ldr r1, _08075158 @ =_0807515C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08075154: .4byte 0x0000037D
_08075158: .4byte _0807515C
_0807515C: @ jump table
	.4byte _08075174 @ case 0
	.4byte _08075290 @ case 1
	.4byte _080753FC @ case 2
	.4byte _08075550 @ case 3
	.4byte _080756AC @ case 4
	.4byte _08075840 @ case 5
_08075174:
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r4, r6, r2
	movs r3, #0xd3
	lsls r3, r3, #2
	adds r0, r6, r3
	ldr r1, [r0]
	subs r2, #0x56
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080751C8
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080751D0
_080751C8:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080751D0:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080751F4
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080751FC
_080751F4:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080751FC:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _08075234 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0807526C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08075238
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0807522C
	ldrb r0, [r4, #5]
_0807522C:
	subs r0, #1
	strh r0, [r4, #8]
	b _08075248
	.align 2, 0
_08075234: .4byte 0x0000FFFF
_08075238:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08075248
	strh r1, [r4, #8]
_08075248:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807526C
	movs r0, #1
	strb r0, [r4, #7]
_0807526C:
	ldr r3, _0807528C @ =0x0000037E
	adds r1, r6, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1b
	bhi _08075280
	b _08075970
_08075280:
	adds r0, r6, #0
	movs r1, #7
	movs r2, #1
	bl FUN_08060b84
	b _08075970
	.align 2, 0
_0807528C: .4byte 0x0000037E
_08075290:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _080752E8 @ =0x000002E6
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	movs r3, #0xe8
	adds r3, r3, r6
	mov ip, r3
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r3, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov r7, ip
	cmp r1, r0
	beq _080752EC
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _080752F4
	.align 2, 0
_080752E8: .4byte 0x000002E6
_080752EC:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080752F4:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0807531E
	mov r1, ip
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	mov r2, ip
	str r0, [r2]
	b _0807532A
_0807531E:
	mov r3, ip
	ldr r0, [r3]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_0807532A:
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08075360 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _08075398
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08075364
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08075358
	ldrb r0, [r4, #5]
_08075358:
	subs r0, #1
	strh r0, [r4, #8]
	b _08075374
	.align 2, 0
_08075360: .4byte 0x0000FFFF
_08075364:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08075374
	strh r1, [r4, #8]
_08075374:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08075398
	movs r0, #1
	strb r0, [r4, #7]
_08075398:
	ldr r0, [r7]
	movs r1, #2
	orrs r0, r1
	str r0, [r7]
	ldr r3, _080753F4 @ =0x0000037E
	adds r4, r6, r3
	ldrb r0, [r4]
	lsls r0, r0, #2
	movs r1, #0x40
	subs r1, r1, r0
	adds r0, r6, #0
	adds r0, #0xf0
	strb r1, [r0]
	ldrh r0, [r4]
	cmp r0, #8
	bls _080753D8
	lsls r0, r0, #3
	adds r1, r6, #0
	adds r1, #0xf1
	strb r0, [r1]
	ldrh r0, [r4]
	subs r0, #8
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r2, _080753F8 @ =0x000003F6
	adds r0, r6, r2
	strh r1, [r0]
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08060c40
_080753D8:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _080753E8
	b _08075970
_080753E8:
	adds r0, r6, #0
	movs r1, #7
	movs r2, #2
	bl FUN_08060b84
	b _08075970
	.align 2, 0
_080753F4: .4byte 0x0000037E
_080753F8: .4byte 0x000003F6
_080753FC:
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08060c40
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r4, r6, r3
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _08075458 @ =0x000002E6
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0807545C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08075464
	.align 2, 0
_08075458: .4byte 0x000002E6
_0807545C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08075464:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08075488
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08075490
_08075488:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08075490:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _080754C8 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08075500
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080754CC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080754C0
	ldrb r0, [r4, #5]
_080754C0:
	subs r0, #1
	strh r0, [r4, #8]
	b _080754DC
	.align 2, 0
_080754C8: .4byte 0x0000FFFF
_080754CC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080754DC
	strh r1, [r4, #8]
_080754DC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08075500
	movs r0, #1
	strb r0, [r4, #7]
_08075500:
	ldr r3, _08075548 @ =0x0000037E
	adds r2, r6, r3
	ldrh r1, [r2]
	movs r0, #0xc8
	muls r0, r1, r0
	adds r0, #0xa0
	adds r3, #0x78
	adds r1, r6, r3
	strh r0, [r1]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _08075522
	b _08075970
_08075522:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08060c40
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r0, _0807554C @ =0x080726E1
	str r0, [r1]
	adds r0, r6, #0
	bl FUN_080726b4
	b _08075970
	.align 2, 0
_08075548: .4byte 0x0000037E
_0807554C: .4byte 0x080726E1
_08075550:
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r4, r6, r1
	movs r2, #0xd3
	lsls r2, r2, #2
	adds r0, r6, r2
	ldr r1, [r0]
	ldr r3, _080755A8 @ =0x000002E6
	adds r0, r6, r3
	ldrb r3, [r0]
	subs r2, #0x65
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	movs r3, #0xe8
	adds r3, r3, r6
	mov ip, r3
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r3, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov r7, ip
	cmp r1, r0
	beq _080755AC
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _080755B4
	.align 2, 0
_080755A8: .4byte 0x000002E6
_080755AC:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080755B4:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080755DE
	mov r1, ip
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	mov r2, ip
	str r0, [r2]
	b _080755EA
_080755DE:
	mov r3, ip
	ldr r0, [r3]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_080755EA:
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08075620 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _08075658
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08075624
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08075618
	ldrb r0, [r4, #5]
_08075618:
	subs r0, #1
	strh r0, [r4, #8]
	b _08075634
	.align 2, 0
_08075620: .4byte 0x0000FFFF
_08075624:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08075634
	strh r1, [r4, #8]
_08075634:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08075658
	movs r0, #1
	strb r0, [r4, #7]
_08075658:
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08060c40
	ldr r0, [r7]
	movs r1, #2
	orrs r0, r1
	str r0, [r7]
	adds r1, r6, #0
	adds r1, #0xf0
	movs r0, #4
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x78
	strb r0, [r1]
	ldr r3, _080756A8 @ =0x0000037E
	adds r2, r6, r3
	ldrh r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	movs r1, #0xc8
	muls r0, r1, r0
	adds r0, #0xa0
	adds r3, #0x78
	adds r1, r6, r3
	strh r0, [r1]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0807569C
	b _08075970
_0807569C:
	adds r0, r6, #0
	movs r1, #7
	movs r2, #4
	bl FUN_08060b84
	b _08075970
	.align 2, 0
_080756A8: .4byte 0x0000037E
_080756AC:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _08075704 @ =0x000002E6
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	movs r3, #0xe8
	adds r3, r3, r6
	mov ip, r3
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r3, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov r7, ip
	cmp r1, r0
	beq _08075708
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _08075710
	.align 2, 0
_08075704: .4byte 0x000002E6
_08075708:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08075710:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0807573A
	mov r1, ip
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	mov r2, ip
	str r0, [r2]
	b _08075746
_0807573A:
	mov r3, ip
	ldr r0, [r3]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_08075746:
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0807577C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _080757B4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08075780
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08075774
	ldrb r0, [r4, #5]
_08075774:
	subs r0, #1
	strh r0, [r4, #8]
	b _08075790
	.align 2, 0
_0807577C: .4byte 0x0000FFFF
_08075780:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08075790
	strh r1, [r4, #8]
_08075790:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080757B4
	movs r0, #1
	strb r0, [r4, #7]
_080757B4:
	ldr r0, [r7]
	movs r1, #2
	orrs r0, r1
	str r0, [r7]
	ldr r0, _080757F8 @ =0x0000037E
	adds r3, r6, r0
	ldrb r1, [r3]
	movs r2, #0xf
	subs r1, r2, r1
	lsls r1, r1, #2
	movs r0, #0x40
	subs r0, r0, r1
	adds r1, r6, #0
	adds r1, #0xf0
	strb r0, [r1]
	ldrh r0, [r3]
	cmp r0, #7
	bhi _08075800
	subs r0, r2, r0
	lsls r0, r0, #3
	adds r2, r6, #0
	adds r2, #0xf1
	strb r0, [r2]
	ldrh r1, [r3]
	movs r0, #8
	subs r0, r0, r1
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r2, _080757FC @ =0x000003F6
	adds r0, r6, r2
	strh r1, [r0]
	b _08075818
	.align 2, 0
_080757F8: .4byte 0x0000037E
_080757FC: .4byte 0x000003F6
_08075800:
	adds r1, r6, #0
	adds r1, #0xf1
	movs r0, #0x40
	strb r0, [r1]
	ldr r3, _08075838 @ =0x000003F6
	adds r1, r6, r3
	movs r0, #0
	strh r0, [r1]
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08060c40
_08075818:
	ldr r0, _0807583C @ =0x0000037E
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _0807582C
	b _08075970
_0807582C:
	adds r0, r6, #0
	movs r1, #7
	movs r2, #5
	bl FUN_08060b84
	b _08075970
	.align 2, 0
_08075838: .4byte 0x000003F6
_0807583C: .4byte 0x0000037E
_08075840:
	adds r4, r6, #0
	adds r4, #0xe8
	ldr r0, [r4]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r5, r6, r1
	movs r2, #0xd3
	lsls r2, r2, #2
	adds r0, r6, r2
	ldr r1, [r0]
	ldr r3, _080758A0 @ =0x000002E6
	adds r0, r6, r3
	ldrb r3, [r0]
	subs r2, #0x65
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_08236fac
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r4, #0x10]
	ldrb r0, [r5, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080758A4
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	b _080758AC
	.align 2, 0
_080758A0: .4byte 0x000002E6
_080758A4:
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080758AC:
	str r0, [r4]
	ldrb r0, [r5, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080758D0
	ldr r0, [r4]
	movs r1, #8
	orrs r0, r1
	b _080758D8
_080758D0:
	ldr r0, [r4]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080758D8:
	str r0, [r4]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r3, _08075910 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r5, #7]
	cmp r0, r1
	blo _08075948
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08075914
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _08075908
	ldrb r0, [r5, #5]
_08075908:
	subs r0, #1
	strh r0, [r5, #8]
	b _08075924
	.align 2, 0
_08075910: .4byte 0x0000FFFF
_08075914:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _08075924
	strh r1, [r5, #8]
_08075924:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r5, #6]
	ldrb r1, [r5, #6]
	ldrh r0, [r5, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r5, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08075948
	movs r0, #1
	strb r0, [r5, #7]
_08075948:
	ldr r3, _08075978 @ =0x0000037E
	adds r1, r6, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _08075970
	adds r0, r6, #0
	bl FUN_08072620
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r0, _0807597C @ =FUN_08074d90
	str r0, [r1]
	adds r0, r6, #0
	bl FUN_080726b4
_08075970:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08075978: .4byte 0x0000037E
_0807597C: .4byte FUN_08074d90

	thumb_func_start FUN_08075980
FUN_08075980: @ 0x08075980
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, _080759F0 @ =0x0000037E
	adds r4, r7, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _0807599C
	movs r0, #0xe6
	bl PlaySound_082406e0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_0807599C:
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r4, r7, r1
	movs r2, #0xd3
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r1, [r0]
	ldr r5, _080759F4 @ =0x000002E6
	adds r0, r7, r5
	ldrb r3, [r0]
	subs r2, #0x65
	adds r0, r7, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_08236fac
	adds r5, r7, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080759F8
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08075A00
	.align 2, 0
_080759F0: .4byte 0x0000037E
_080759F4: .4byte 0x000002E6
_080759F8:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08075A00:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08075A24
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08075A2C
_08075A24:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08075A2C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r5, _08075A64 @ =0x0000FFFF
	adds r2, r5, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08075A9C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08075A68
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08075A5C
	ldrb r0, [r4, #5]
_08075A5C:
	subs r0, #1
	strh r0, [r4, #8]
	b _08075A78
	.align 2, 0
_08075A64: .4byte 0x0000FFFF
_08075A68:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08075A78
	strh r1, [r4, #8]
_08075A78:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08075A9C
	movs r0, #1
	strb r0, [r4, #7]
_08075A9C:
	ldr r5, _08075AD4 @ =0x000004A4
	adds r3, r7, r5
	ldrh r0, [r3]
	cmp r0, #0
	beq _08075B24
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldr r2, _08075AD8 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	ldrh r0, [r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _08075ADC
	asrs r0, r0, #0xc
	b _08075AE2
	.align 2, 0
_08075AD4: .4byte 0x000004A4
_08075AD8: .4byte 0x085B0A08
_08075ADC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08075AE2:
	rsbs r0, r0, #0
	strh r0, [r7, #0x34]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r5, _08075B00 @ =0x000004A4
	adds r0, r7, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _08075B04
	asrs r0, r0, #0xc
	b _08075B0A
	.align 2, 0
_08075B00: .4byte 0x000004A4
_08075B04:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08075B0A:
	rsbs r0, r0, #0
	strh r0, [r7, #0x38]
	ldr r0, _08075B20 @ =0x000004A4
	adds r2, r7, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	b _08075B40
	.align 2, 0
_08075B20: .4byte 0x000004A4
_08075B24:
	strh r0, [r3]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r0, _08075B48 @ =FUN_08074d90
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_080726b4
_08075B40:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08075B48: .4byte FUN_08074d90

	thumb_func_start FUN_08075b4c
FUN_08075b4c: @ 0x08075B4C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, _08075B7C @ =0x0000037E
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08075BBA
	ldr r2, _08075B80 @ =0x000002E7
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08075B88
	ldr r3, _08075B84 @ =0x000002E6
	adds r0, r5, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	movs r1, #7
	subs r1, r1, r0
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	b _08075B9A
	.align 2, 0
_08075B7C: .4byte 0x0000037E
_08075B80: .4byte 0x000002E7
_08075B84: .4byte 0x000002E6
_08075B88:
	ldr r3, _08075BE8 @ =0x000002E6
	adds r0, r5, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, #1
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r5, r2
	strb r0, [r1]
_08075B9A:
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r5, r3
	movs r0, #0
	strh r0, [r1]
	ldr r0, _08075BEC @ =0x0000037F
	bl PlaySound_082406e0
	movs r0, #0x38
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #0
	movs r3, #0x20
	bl FUN_080ac374
_08075BBA:
	ldr r1, _08075BF0 @ =0x0000037E
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r3, #7
	adds r1, r3, #0
	ands r1, r0
	lsrs r0, r0, #2
	subs r0, r3, r0
	cmp r1, r0
	bge _08075C10
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r5, r0
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #3
	bls _08075BF4
	ldrb r0, [r2]
	subs r0, r3, r0
	asrs r0, r0, #1
	b _08075C34
	.align 2, 0
_08075BE8: .4byte 0x000002E6
_08075BEC: .4byte 0x0000037F
_08075BF0: .4byte 0x0000037E
_08075BF4:
	lsrs r1, r1, #0x19
	ldr r2, _08075C08 @ =0x000002E6
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r3, _08075C0C @ =0x000002E7
	adds r0, r5, r3
	strb r2, [r0]
	b _08075C5A
	.align 2, 0
_08075C08: .4byte 0x000002E6
_08075C0C: .4byte 0x000002E7
_08075C10:
	adds r0, r5, #0
	movs r1, #0x41
	bl FUN_08060c40
	adds r0, r5, #0
	adds r0, #0xa8
	ldr r1, [r5, #0x2c]
	ldr r2, [r5, #0x30]
	str r1, [r0]
	str r2, [r0, #4]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r2, [r0]
	cmp r2, #4
	bls _08075C4C
	movs r0, #8
	subs r0, r0, r2
_08075C34:
	ldr r2, _08075C44 @ =0x000002E6
	adds r1, r5, r2
	strb r0, [r1]
	ldr r3, _08075C48 @ =0x000002E7
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _08075C5A
	.align 2, 0
_08075C44: .4byte 0x000002E6
_08075C48: .4byte 0x000002E7
_08075C4C:
	ldr r1, _08075CD0 @ =0x000002E6
	adds r0, r5, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _08075CD4 @ =0x000002E7
	adds r0, r5, r2
	strb r1, [r0]
_08075C5A:
	adds r0, r5, #0
	movs r1, #0xc7
	movs r2, #0x40
	bl FUN_08060a24
	adds r0, r5, #0
	adds r0, #0xc2
	movs r1, #0x91
	lsls r1, r1, #1
	strh r1, [r0]
	adds r2, r5, #0
	adds r2, #0xd0
	ldr r0, _08075CD8 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2]
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r4, r5, r3
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r2, _08075CD0 @ =0x000002E6
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r6, r5, #0
	adds r6, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08075CDC
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _08075CE4
	.align 2, 0
_08075CD0: .4byte 0x000002E6
_08075CD4: .4byte 0x000002E7
_08075CD8: .4byte 0x03003584
_08075CDC:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08075CE4:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08075D08
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _08075D10
_08075D08:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08075D10:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _08075D48 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08075D80
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08075D4C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08075D40
	ldrb r0, [r4, #5]
_08075D40:
	subs r0, #1
	strh r0, [r4, #8]
	b _08075D5C
	.align 2, 0
_08075D48: .4byte 0x0000FFFF
_08075D4C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08075D5C
	strh r1, [r4, #8]
_08075D5C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08075D80
	movs r0, #1
	strb r0, [r4, #7]
_08075D80:
	ldr r3, _08075DE0 @ =0x0000095E
	adds r1, r5, r3
	ldr r0, _08075DE4 @ =0x0000026D
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	ldr r3, _08075DE8 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _08075DA4
	movs r0, #0x20
	strh r0, [r1]
_08075DA4:
	ldr r0, _08075DEC @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ands r0, r2
	cmp r0, #0x1f
	bls _08075DD6
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r4, #1
	strb r4, [r0]
	ldr r2, _08075DF0 @ =0x00000381
	adds r0, r5, r2
	strb r4, [r0]
	adds r0, r5, #0
	bl FUN_080609dc
	adds r0, r5, #0
	bl FUN_08072620
	ldr r3, _08075DF4 @ =0x000004AF
	adds r0, r5, r3
	strb r4, [r0]
_08075DD6:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08075DE0: .4byte 0x0000095E
_08075DE4: .4byte 0x0000026D
_08075DE8: .4byte 0x0000FFFF
_08075DEC: .4byte 0x0000037E
_08075DF0: .4byte 0x00000381
_08075DF4: .4byte 0x000004AF

	thumb_func_start FUN_08075df8
FUN_08075df8: @ 0x08075DF8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r5, r4, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r2, _08075E50 @ =0x000002E6
	adds r0, r4, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r4, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_08236fac
	adds r4, #0xe8
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r4, #0x10]
	ldrb r0, [r5, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08075E54
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	b _08075E5C
	.align 2, 0
_08075E50: .4byte 0x000002E6
_08075E54:
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08075E5C:
	str r0, [r4]
	ldrb r0, [r5, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08075E80
	ldr r0, [r4]
	movs r1, #8
	orrs r0, r1
	b _08075E88
_08075E80:
	ldr r0, [r4]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08075E88:
	str r0, [r4]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r1, _08075EC0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r5, #7]
	cmp r0, r1
	blo _08075EF8
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08075EC4
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _08075EB8
	ldrb r0, [r5, #5]
_08075EB8:
	subs r0, #1
	strh r0, [r5, #8]
	b _08075ED4
	.align 2, 0
_08075EC0: .4byte 0x0000FFFF
_08075EC4:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _08075ED4
	strh r1, [r5, #8]
_08075ED4:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r5, #6]
	ldrb r1, [r5, #6]
	ldrh r0, [r5, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r5, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08075EF8
	movs r0, #1
	strb r0, [r5, #7]
_08075EF8:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08075f00
FUN_08075f00: @ 0x08075F00
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _08075F6C @ =0x0000049C
	adds r0, r0, r6
	mov r8, r0
	movs r1, #0
	ldrsh r5, [r0, r1]
	movs r2, #0x2c
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0x94
	lsls r3, r3, #3
	adds r7, r6, r3
	movs r0, #0
	ldrsh r4, [r7, r0]
	movs r1, #0x30
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	adds r3, r0, #0
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	cmp r0, #0x90
	ble _08075F44
	b _080760E8
_08075F44:
	mov r2, r8
	ldrh r0, [r2]
	strh r0, [r6, #0x2c]
	ldrh r0, [r7]
	strh r0, [r6, #0x30]
	ldr r4, _08075F70 @ =0x000004A9
	adds r1, r6, r4
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _08075F74
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r6, r3
	strb r2, [r0]
	movs r0, #0xff
	strb r0, [r1]
	b _08075F8E
	.align 2, 0
_08075F6C: .4byte 0x0000049C
_08075F70: .4byte 0x000004A9
_08075F74:
	lsls r0, r3, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r6, r4
	strb r1, [r0]
_08075F8E:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r2, [r0]
	cmp r2, #4
	bls _08075FB8
	movs r0, #8
	subs r0, r0, r2
	ldr r2, _08075FB0 @ =0x000002E6
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _08075FB4 @ =0x000002E7
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	b _08075FC6
	.align 2, 0
_08075FB0: .4byte 0x000002E6
_08075FB4: .4byte 0x000002E7
_08075FB8:
	ldr r4, _0807601C @ =0x000002E6
	adds r0, r6, r4
	movs r1, #0
	strb r2, [r0]
	ldr r2, _08076020 @ =0x000002E7
	adds r0, r6, r2
	strb r1, [r0]
_08075FC6:
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r4, r6, r3
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _0807601C @ =0x000002E6
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08076024
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0807602C
	.align 2, 0
_0807601C: .4byte 0x000002E6
_08076020: .4byte 0x000002E7
_08076024:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0807602C:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08076050
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08076058
_08076050:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08076058:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _08076090 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080760C8
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08076094
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08076088
	ldrb r0, [r4, #5]
_08076088:
	subs r0, #1
	strh r0, [r4, #8]
	b _080760A4
	.align 2, 0
_08076090: .4byte 0x0000FFFF
_08076094:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080760A4
	strh r1, [r4, #8]
_080760A4:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080760C8
	movs r0, #1
	strb r0, [r4, #7]
_080760C8:
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	movs r3, #0x93
	lsls r3, r3, #3
	adds r1, r6, r3
	ldr r0, _080760E4 @ =FUN_08075df8
	str r0, [r1]
	adds r0, r6, #0
	bl FUN_080726b4
	b _080762F0
	.align 2, 0
_080760E4: .4byte FUN_08075df8
_080760E8:
	ldr r2, _08076108 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _0807610C
	asrs r0, r0, #0xc
	b _08076112
	.align 2, 0
_08076108: .4byte 0x085B0A08
_0807610C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08076112:
	strh r0, [r6, #0x34]
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _0807612E
	asrs r0, r0, #0xc
	b _08076134
_0807612E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08076134:
	strh r0, [r6, #0x38]
	ldr r4, _08076154 @ =0x000001C7
	adds r1, r6, r4
	ldrb r1, [r1]
	cmp r1, #1
	bne _08076172
	cmp r0, #0
	bge _08076158
	movs r0, #0x38
	ldrsh r1, [r6, r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _08076164
	b _08076168
	.align 2, 0
_08076154: .4byte 0x000001C7
_08076158:
	movs r2, #0x38
	ldrsh r1, [r6, r2]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _08076168
_08076164:
	asrs r0, r0, #6
	b _0807616E
_08076168:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0807616E:
	strh r0, [r6, #0x38]
	b _080761A4
_08076172:
	cmp r1, #2
	bne _080761A4
	movs r4, #0x34
	ldrsh r0, [r6, r4]
	cmp r0, #0
	bge _0807618C
	adds r1, r0, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _08076198
	b _0807619C
_0807618C:
	movs r2, #0x34
	ldrsh r1, [r6, r2]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _0807619C
_08076198:
	asrs r0, r0, #6
	b _080761A2
_0807619C:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_080761A2:
	strh r0, [r6, #0x34]
_080761A4:
	lsls r0, r3, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r6, r3
	adds r2, r1, #0
	strb r1, [r0]
	cmp r2, #4
	bls _080761E0
	movs r0, #8
	subs r0, r0, r2
	ldr r4, _080761D8 @ =0x000002E6
	adds r1, r6, r4
	strb r0, [r1]
	ldr r0, _080761DC @ =0x000002E7
	adds r1, r6, r0
	movs r0, #1
	b _080761EC
	.align 2, 0
_080761D8: .4byte 0x000002E6
_080761DC: .4byte 0x000002E7
_080761E0:
	ldr r2, _08076244 @ =0x000002E6
	adds r0, r6, r2
	strb r1, [r0]
	ldr r3, _08076248 @ =0x000002E7
	adds r1, r6, r3
	movs r0, #0
_080761EC:
	strb r0, [r1]
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _08076244 @ =0x000002E6
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0807624C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08076254
	.align 2, 0
_08076244: .4byte 0x000002E6
_08076248: .4byte 0x000002E7
_0807624C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08076254:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08076278
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08076280
_08076278:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08076280:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _080762B8 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080762F0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080762BC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080762B0
	ldrb r0, [r4, #5]
_080762B0:
	subs r0, #1
	strh r0, [r4, #8]
	b _080762CC
	.align 2, 0
_080762B8: .4byte 0x0000FFFF
_080762BC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080762CC
	strh r1, [r4, #8]
_080762CC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080762F0
	movs r0, #1
	strb r0, [r4, #7]
_080762F0:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080762fc
FUN_080762fc: @ 0x080762FC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r6, r0, #0
	ldr r1, _08076318 @ =0x0000037D
	adds r0, r6, r1
	ldrb r4, [r0]
	cmp r4, #1
	bne _0807630E
	b _08076504
_0807630E:
	cmp r4, #1
	bgt _0807631C
	cmp r4, #0
	beq _0807632A
	b _08076598
	.align 2, 0
_08076318: .4byte 0x0000037D
_0807631C:
	cmp r4, #2
	bne _08076322
	b _08076548
_08076322:
	cmp r4, #3
	bne _08076328
	b _08076590
_08076328:
	b _08076598
_0807632A:
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08060c40
	ldr r0, [r6, #0x2c]
	ldr r1, [r6, #0x30]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r2, [sp, #0xc]
	asrs r1, r2, #0x10
	adds r1, #0x96
	lsls r1, r1, #0x10
	ldr r0, _0807637C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	bl FUN_0823bac8
	movs r2, #0xfc
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #1
	bhi _0807639C
	cmp r0, #0
	beq _08076384
	movs r0, #4
	str r0, [sp]
	ldr r0, _08076380 @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #0x10
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #3
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	b _0807639C
	.align 2, 0
_0807637C: .4byte 0x0000FFFF
_08076380: .4byte 0x00001FFF
_08076384:
	movs r0, #4
	str r0, [sp]
	ldr r0, _080763C4 @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #3
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_0807639C:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r6, r0
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080763D0
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _080763C8 @ =0x000002E6
	adds r1, r6, r2
	strb r0, [r1]
	ldr r0, _080763CC @ =0x000002E7
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	b _080763E0
	.align 2, 0
_080763C4: .4byte 0x00001FFF
_080763C8: .4byte 0x000002E6
_080763CC: .4byte 0x000002E7
_080763D0:
	lsrs r1, r1, #0x19
	ldr r2, _08076434 @ =0x000002E6
	adds r0, r6, r2
	movs r2, #0
	strb r1, [r0]
	ldr r1, _08076438 @ =0x000002E7
	adds r0, r6, r1
	strb r2, [r0]
_080763E0:
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r4, r6, r2
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	subs r2, #0x56
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0807643C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08076444
	.align 2, 0
_08076434: .4byte 0x000002E6
_08076438: .4byte 0x000002E7
_0807643C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08076444:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08076468
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08076470
_08076468:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08076470:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080764A8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080764E0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080764AC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080764A0
	ldrb r0, [r4, #5]
_080764A0:
	subs r0, #1
	strh r0, [r4, #8]
	b _080764BC
	.align 2, 0
_080764A8: .4byte 0x0000FFFF
_080764AC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080764BC
	strh r1, [r4, #8]
_080764BC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080764E0
	movs r0, #1
	strb r0, [r4, #7]
_080764E0:
	ldr r0, _080764FC @ =0x000001AD
	bl PlaySound_082406e0
	adds r0, r6, #0
	movs r1, #0x16
	movs r2, #1
	bl FUN_08060b84
	ldr r0, _08076500 @ =0x000003F6
	adds r1, r6, r0
	movs r0, #0
	strh r0, [r1]
	b _08076598
	.align 2, 0
_080764FC: .4byte 0x000001AD
_08076500: .4byte 0x000003F6
_08076504:
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08060c40
	ldr r2, _08076540 @ =0x0000037E
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _08076598
	ldr r1, _08076544 @ =0x000003F6
	adds r0, r6, r1
	movs r1, #0
	strh r1, [r0]
	adds r0, r6, #0
	adds r0, #0xef
	strb r4, [r0]
	movs r0, #0xd7
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r6, #0
	movs r1, #0x16
	movs r2, #2
	bl FUN_08060b84
	b _08076598
	.align 2, 0
_08076540: .4byte 0x0000037E
_08076544: .4byte 0x000003F6
_08076548:
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08060c40
	ldr r2, _08076588 @ =0x000003F6
	adds r1, r6, r2
	ldrh r0, [r1]
	subs r0, #0x3c
	strh r0, [r1]
	ldr r0, _0807658C @ =0x0000037E
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _08076598
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08060c40
	adds r0, r6, #0
	movs r1, #0x16
	movs r2, #3
	bl FUN_08060b84
	adds r0, r6, #0
	bl FUN_080726b4
	b _08076598
	.align 2, 0
_08076588: .4byte 0x000003F6
_0807658C: .4byte 0x0000037E
_08076590:
	adds r0, r6, #0
	movs r1, #5
	bl FUN_08060c40
_08076598:
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080765a0
FUN_080765a0: @ 0x080765A0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r1, _080765C0 @ =0x0000037D
	adds r0, r7, r1
	ldrb r0, [r0]
	mov r8, r0
	cmp r0, #0
	beq _080765C4
	cmp r0, #1
	bne _080765BC
	b _08076750
_080765BC:
	b _0807687C
	.align 2, 0
_080765C0: .4byte 0x0000037D
_080765C4:
	ldr r2, _080765F8 @ =0x0000037E
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _0807661E
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r7, r0
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _08076604
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _080765FC @ =0x000002E6
	adds r1, r7, r2
	strb r0, [r1]
	ldr r0, _08076600 @ =0x000002E7
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	b _08076614
	.align 2, 0
_080765F8: .4byte 0x0000037E
_080765FC: .4byte 0x000002E6
_08076600: .4byte 0x000002E7
_08076604:
	lsrs r0, r1, #0x19
	ldr r2, _08076674 @ =0x000002E6
	adds r1, r7, r2
	strb r0, [r1]
	ldr r1, _08076678 @ =0x000002E7
	adds r0, r7, r1
	mov r2, r8
	strb r2, [r0]
_08076614:
	ldr r0, _0807667C @ =0x0000037E
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0807661E:
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r4, r7, r1
	movs r2, #0xd4
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r1, [r0]
	subs r2, #0x6a
	adds r0, r7, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r7, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_08236fac
	adds r5, r7, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08076680
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08076688
	.align 2, 0
_08076674: .4byte 0x000002E6
_08076678: .4byte 0x000002E7
_0807667C: .4byte 0x0000037E
_08076680:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08076688:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080766AC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080766B4
_080766AC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080766B4:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080766EC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08076724
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080766F0
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080766E4
	ldrb r0, [r4, #5]
_080766E4:
	subs r0, #1
	strh r0, [r4, #8]
	b _08076700
	.align 2, 0
_080766EC: .4byte 0x0000FFFF
_080766F0:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08076700
	strh r1, [r4, #8]
_08076700:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08076724
	movs r0, #1
	strb r0, [r4, #7]
_08076724:
	ldr r0, _08076734 @ =0x000003F6
	adds r1, r7, r0
	ldrh r0, [r1]
	cmp r0, #0x1e
	bls _08076738
	subs r0, #0x1e
	strh r0, [r1]
	b _0807687C
	.align 2, 0
_08076734: .4byte 0x000003F6
_08076738:
	movs r0, #0
	strh r0, [r1]
	movs r0, #0xd8
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r7, #0
	movs r1, #0x17
	movs r2, #1
	bl FUN_08060b84
	b _0807687C
_08076750:
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r4, r7, r1
	movs r2, #0xd4
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r1, [r0]
	subs r2, #0x6a
	adds r0, r7, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r7, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #3
	bl FUN_08236fac
	adds r5, r7, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	mov r1, r8
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, r8
	ands r0, r2
	cmp r1, r0
	beq _080767A4
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080767AC
_080767A4:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080767AC:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080767D0
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080767D8
_080767D0:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080767D8:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08076810 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08076856
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0807681A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08076814
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08076830
	.align 2, 0
_08076810: .4byte 0x0000FFFF
_08076814:
	subs r0, #1
	strh r0, [r4, #8]
	b _0807682E
_0807681A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0807682E
	strh r1, [r4, #8]
	movs r2, #1
	b _08076830
_0807682E:
	movs r2, #0
_08076830:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08076858
	movs r0, #1
	strb r0, [r4, #7]
	b _08076858
_08076856:
	movs r2, #0
_08076858:
	cmp r2, #0
	beq _0807687C
	adds r0, r7, #0
	bl FUN_080609dc
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _08076888 @ =FUN_08075df8
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_080726b4
_0807687C:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08076888: .4byte FUN_08075df8

	thumb_func_start FUN_0807688c
FUN_0807688c: @ 0x0807688C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r1, _080768AC @ =0x0000037D
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #5
	bls _080768A2
	b _08076F16
_080768A2:
	lsls r0, r0, #2
	ldr r1, _080768B0 @ =_080768B4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080768AC: .4byte 0x0000037D
_080768B0: .4byte _080768B4
_080768B4: @ jump table
	.4byte _080768CC @ case 0
	.4byte _08076A0C @ case 1
	.4byte _08076A74 @ case 2
	.4byte _08076ACC @ case 3
	.4byte _08076C4C @ case 4
	.4byte _08076DE0 @ case 5
_080768CC:
	ldr r2, _0807693C @ =0x0000037E
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _080768E6
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r0, #4
	strb r0, [r1]
	adds r0, r6, #0
	bl FUN_080609dc
_080768E6:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _08076940 @ =0x000002E6
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08076944
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0807694C
	.align 2, 0
_0807693C: .4byte 0x0000037E
_08076940: .4byte 0x000002E6
_08076944:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0807694C:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08076970
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08076978
_08076970:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08076978:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _080769B0 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080769E8
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080769B4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080769A8
	ldrb r0, [r4, #5]
_080769A8:
	subs r0, #1
	strh r0, [r4, #8]
	b _080769C4
	.align 2, 0
_080769B0: .4byte 0x0000FFFF
_080769B4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080769C4
	strh r1, [r4, #8]
_080769C4:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080769E8
	movs r0, #1
	strb r0, [r4, #7]
_080769E8:
	ldr r3, _08076A08 @ =0x0000037E
	adds r1, r6, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1b
	bhi _080769FC
	b _08076F16
_080769FC:
	adds r0, r6, #0
	movs r1, #7
	movs r2, #1
	bl FUN_08060b84
	b _08076F16
	.align 2, 0
_08076A08: .4byte 0x0000037E
_08076A0C:
	adds r2, r6, #0
	adds r2, #0xe8
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	ldr r0, _08076A6C @ =0x0000037E
	adds r4, r6, r0
	ldrb r0, [r4]
	lsls r0, r0, #2
	movs r1, #0x40
	subs r1, r1, r0
	adds r0, r6, #0
	adds r0, #0xf0
	strb r1, [r0]
	ldrh r0, [r4]
	cmp r0, #8
	bls _08076A50
	lsls r0, r0, #3
	adds r1, r6, #0
	adds r1, #0xf1
	strb r0, [r1]
	ldrh r0, [r4]
	subs r0, #8
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r2, _08076A70 @ =0x000003F6
	adds r0, r6, r2
	strh r1, [r0]
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08060c40
_08076A50:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _08076A60
	b _08076F16
_08076A60:
	adds r0, r6, #0
	movs r1, #7
	movs r2, #2
	bl FUN_08060b84
	b _08076F16
	.align 2, 0
_08076A6C: .4byte 0x0000037E
_08076A70: .4byte 0x000003F6
_08076A74:
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08060c40
	ldr r3, _08076AC4 @ =0x0000037E
	adds r2, r6, r3
	ldrh r1, [r2]
	movs r0, #0xc8
	muls r0, r1, r0
	adds r0, #0xa0
	adds r3, #0x78
	adds r1, r6, r3
	strh r0, [r1]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _08076A9E
	b _08076F16
_08076A9E:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08060c40
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r0, _08076AC8 @ =0x080726E1
	str r0, [r1]
	adds r0, r6, #0
	bl FUN_080726b4
	b _08076F16
	.align 2, 0
_08076AC4: .4byte 0x0000037E
_08076AC8: .4byte 0x080726E1
_08076ACC:
	ldr r1, _08076B40 @ =0x0000037E
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08076AE6
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r0, #4
	strb r0, [r1]
	adds r0, r6, #0
	bl FUN_080609dc
_08076AE6:
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r4, r6, r3
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _08076B44 @ =0x000002E6
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r7, r6, #0
	adds r7, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov r8, r7
	cmp r1, r0
	beq _08076B48
	mov r3, r8
	ldr r0, [r3]
	movs r1, #4
	orrs r0, r1
	str r0, [r3]
	b _08076B56
	.align 2, 0
_08076B40: .4byte 0x0000037E
_08076B44: .4byte 0x000002E6
_08076B48:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, r8
	str r0, [r2]
_08076B56:
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08076B78
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _08076B80
_08076B78:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08076B80:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _08076BB8 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08076BF0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08076BBC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08076BB0
	ldrb r0, [r4, #5]
_08076BB0:
	subs r0, #1
	strh r0, [r4, #8]
	b _08076BCC
	.align 2, 0
_08076BB8: .4byte 0x0000FFFF
_08076BBC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08076BCC
	strh r1, [r4, #8]
_08076BCC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08076BF0
	movs r0, #1
	strb r0, [r4, #7]
_08076BF0:
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08060c40
	mov r3, r8
	ldr r0, [r3]
	movs r1, #2
	orrs r0, r1
	str r0, [r3]
	adds r1, r6, #0
	adds r1, #0xf0
	movs r0, #4
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x78
	strb r0, [r1]
	ldr r0, _08076C44 @ =0x0000037E
	adds r2, r6, r0
	ldrh r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	movs r1, #0xc8
	muls r0, r1, r0
	adds r0, #0xa0
	ldr r3, _08076C48 @ =0x000003F6
	adds r1, r6, r3
	strh r0, [r1]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _08076C36
	b _08076F16
_08076C36:
	adds r0, r6, #0
	movs r1, #7
	movs r2, #4
	bl FUN_08060b84
	b _08076F16
	.align 2, 0
_08076C44: .4byte 0x0000037E
_08076C48: .4byte 0x000003F6
_08076C4C:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _08076CA8 @ =0x000002E6
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r7, r6, #0
	adds r7, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov r8, r7
	cmp r1, r0
	beq _08076CAC
	mov r3, r8
	ldr r0, [r3]
	movs r1, #4
	orrs r0, r1
	str r0, [r3]
	b _08076CBA
	.align 2, 0
_08076CA8: .4byte 0x000002E6
_08076CAC:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, r8
	str r0, [r2]
_08076CBA:
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08076CDC
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _08076CE4
_08076CDC:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08076CE4:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _08076D1C @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08076D54
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08076D20
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08076D14
	ldrb r0, [r4, #5]
_08076D14:
	subs r0, #1
	strh r0, [r4, #8]
	b _08076D30
	.align 2, 0
_08076D1C: .4byte 0x0000FFFF
_08076D20:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08076D30
	strh r1, [r4, #8]
_08076D30:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08076D54
	movs r0, #1
	strb r0, [r4, #7]
_08076D54:
	mov r3, r8
	ldr r0, [r3]
	movs r1, #2
	orrs r0, r1
	str r0, [r3]
	ldr r0, _08076D98 @ =0x0000037E
	adds r3, r6, r0
	ldrb r1, [r3]
	movs r2, #0xf
	subs r1, r2, r1
	lsls r1, r1, #2
	movs r0, #0x40
	subs r0, r0, r1
	adds r1, r6, #0
	adds r1, #0xf0
	strb r0, [r1]
	ldrh r0, [r3]
	cmp r0, #7
	bhi _08076DA0
	subs r0, r2, r0
	lsls r0, r0, #3
	adds r2, r6, #0
	adds r2, #0xf1
	strb r0, [r2]
	ldrh r1, [r3]
	movs r0, #8
	subs r0, r0, r1
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r2, _08076D9C @ =0x000003F6
	adds r0, r6, r2
	strh r1, [r0]
	b _08076DB8
	.align 2, 0
_08076D98: .4byte 0x0000037E
_08076D9C: .4byte 0x000003F6
_08076DA0:
	adds r1, r6, #0
	adds r1, #0xf1
	movs r0, #0x40
	strb r0, [r1]
	ldr r3, _08076DD8 @ =0x000003F6
	adds r1, r6, r3
	movs r0, #0
	strh r0, [r1]
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08060c40
_08076DB8:
	ldr r0, _08076DDC @ =0x0000037E
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _08076DCC
	b _08076F16
_08076DCC:
	adds r0, r6, #0
	movs r1, #7
	movs r2, #5
	bl FUN_08060b84
	b _08076F16
	.align 2, 0
_08076DD8: .4byte 0x000003F6
_08076DDC: .4byte 0x0000037E
_08076DE0:
	adds r4, r6, #0
	adds r4, #0xe8
	ldr r0, [r4]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r5, r6, r1
	movs r2, #0xd4
	lsls r2, r2, #2
	adds r0, r6, r2
	ldr r1, [r0]
	ldr r3, _08076E40 @ =0x000002E6
	adds r0, r6, r3
	ldrb r3, [r0]
	subs r2, #0x69
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_08236fac
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r4, #0x10]
	ldrb r0, [r5, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08076E44
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	b _08076E4C
	.align 2, 0
_08076E40: .4byte 0x000002E6
_08076E44:
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08076E4C:
	str r0, [r4]
	ldrb r0, [r5, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08076E70
	ldr r0, [r4]
	movs r1, #8
	orrs r0, r1
	b _08076E78
_08076E70:
	ldr r0, [r4]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08076E78:
	str r0, [r4]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r3, _08076EB0 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r5, #7]
	cmp r0, r1
	blo _08076EE8
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08076EB4
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _08076EA8
	ldrb r0, [r5, #5]
_08076EA8:
	subs r0, #1
	strh r0, [r5, #8]
	b _08076EC4
	.align 2, 0
_08076EB0: .4byte 0x0000FFFF
_08076EB4:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _08076EC4
	strh r1, [r5, #8]
_08076EC4:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r5, #6]
	ldrb r1, [r5, #6]
	ldrh r0, [r5, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r5, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08076EE8
	movs r0, #1
	strb r0, [r5, #7]
_08076EE8:
	ldr r3, _08076F24 @ =0x0000037E
	adds r1, r6, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _08076F16
	adds r0, r6, #0
	bl FUN_080609dc
	adds r0, r6, #0
	bl FUN_08072620
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r0, _08076F28 @ =FUN_08075df8
	str r0, [r1]
	adds r0, r6, #0
	bl FUN_080726b4
_08076F16:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08076F24: .4byte 0x0000037E
_08076F28: .4byte FUN_08075df8

	thumb_func_start FUN_08076f2c
FUN_08076f2c: @ 0x08076F2C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, _08076F9C @ =0x0000037E
	adds r4, r7, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _08076F48
	movs r0, #0xe6
	bl PlaySound_082406e0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_08076F48:
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r4, r7, r1
	movs r2, #0xd4
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r1, [r0]
	ldr r5, _08076FA0 @ =0x000002E6
	adds r0, r7, r5
	ldrb r3, [r0]
	subs r2, #0x69
	adds r0, r7, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_08236fac
	adds r5, r7, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08076FA4
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08076FAC
	.align 2, 0
_08076F9C: .4byte 0x0000037E
_08076FA0: .4byte 0x000002E6
_08076FA4:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08076FAC:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08076FD0
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08076FD8
_08076FD0:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08076FD8:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r5, _08077010 @ =0x0000FFFF
	adds r2, r5, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08077048
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08077014
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08077008
	ldrb r0, [r4, #5]
_08077008:
	subs r0, #1
	strh r0, [r4, #8]
	b _08077024
	.align 2, 0
_08077010: .4byte 0x0000FFFF
_08077014:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08077024
	strh r1, [r4, #8]
_08077024:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08077048
	movs r0, #1
	strb r0, [r4, #7]
_08077048:
	ldr r5, _08077080 @ =0x000004A4
	adds r3, r7, r5
	ldrh r0, [r3]
	cmp r0, #0
	beq _080770D0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldr r2, _08077084 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	ldrh r0, [r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _08077088
	asrs r0, r0, #0xc
	b _0807708E
	.align 2, 0
_08077080: .4byte 0x000004A4
_08077084: .4byte 0x085B0A08
_08077088:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0807708E:
	rsbs r0, r0, #0
	strh r0, [r7, #0x34]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r5, _080770AC @ =0x000004A4
	adds r0, r7, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080770B0
	asrs r0, r0, #0xc
	b _080770B6
	.align 2, 0
_080770AC: .4byte 0x000004A4
_080770B0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080770B6:
	rsbs r0, r0, #0
	strh r0, [r7, #0x38]
	ldr r0, _080770CC @ =0x000004A4
	adds r2, r7, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	b _080770F2
	.align 2, 0
_080770CC: .4byte 0x000004A4
_080770D0:
	strh r0, [r3]
	adds r0, r7, #0
	bl FUN_080609dc
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r0, _080770FC @ =FUN_08075df8
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_080726b4
_080770F2:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080770FC: .4byte FUN_08075df8

	thumb_func_start FUN_08077100
FUN_08077100: @ 0x08077100
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _080771C8 @ =0x0000037E
	adds r4, r6, r0
	ldrh r1, [r4]
	cmp r1, #0
	bne _0807712E
	movs r2, #0x96
	lsls r2, r2, #4
	adds r0, r6, r2
	strh r1, [r0]
	ldr r0, _080771CC @ =0x0000037F
	bl PlaySound_082406e0
	movs r0, #0x38
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0
	movs r3, #0x20
	bl FUN_080ac374
_0807712E:
	ldrh r0, [r4]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #2
	subs r1, r1, r0
	cmp r2, r1
	blt _08077152
	adds r0, r6, #0
	movs r1, #0x41
	bl FUN_08060c40
	adds r2, r6, #0
	adds r2, #0xa8
	ldr r0, [r6, #0x2c]
	ldr r1, [r6, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
_08077152:
	adds r0, r6, #0
	movs r1, #0xc7
	movs r2, #0x40
	bl FUN_08060a24
	adds r0, r6, #0
	adds r0, #0xc2
	movs r1, #0x91
	lsls r1, r1, #1
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0xd0
	ldr r0, _080771D0 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2]
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r4, r6, r3
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _080771D4 @ =0x000002E6
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080771D8
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080771E0
	.align 2, 0
_080771C8: .4byte 0x0000037E
_080771CC: .4byte 0x0000037F
_080771D0: .4byte 0x03003584
_080771D4: .4byte 0x000002E6
_080771D8:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080771E0:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08077204
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0807720C
_08077204:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0807720C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _08077244 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0807727C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08077248
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0807723C
	ldrb r0, [r4, #5]
_0807723C:
	subs r0, #1
	strh r0, [r4, #8]
	b _08077258
	.align 2, 0
_08077244: .4byte 0x0000FFFF
_08077248:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08077258
	strh r1, [r4, #8]
_08077258:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807727C
	movs r0, #1
	strb r0, [r4, #7]
_0807727C:
	ldr r3, _080772D8 @ =0x0000095E
	adds r1, r6, r3
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	ldr r3, _080772DC @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _080772A2
	movs r0, #0x20
	strh r0, [r1]
_080772A2:
	ldr r0, _080772E0 @ =0x0000037E
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ands r0, r2
	cmp r0, #0x1f
	bls _080772CE
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r4, #1
	strb r4, [r0]
	ldr r2, _080772E4 @ =0x00000381
	adds r0, r6, r2
	strb r4, [r0]
	adds r0, r6, #0
	bl FUN_08072620
	ldr r3, _080772E8 @ =0x000004AF
	adds r0, r6, r3
	strb r4, [r0]
_080772CE:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080772D8: .4byte 0x0000095E
_080772DC: .4byte 0x0000FFFF
_080772E0: .4byte 0x0000037E
_080772E4: .4byte 0x00000381
_080772E8: .4byte 0x000004AF

	thumb_func_start FUN_080772ec
FUN_080772ec: @ 0x080772EC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r5, r4, r0
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r2, _08077340 @ =0x00000387
	adds r0, r4, r2
	ldrb r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_08236fac
	adds r4, #0xe8
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r4, #0x10]
	ldrb r0, [r5, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08077344
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	b _0807734C
	.align 2, 0
_08077340: .4byte 0x00000387
_08077344:
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0807734C:
	str r0, [r4]
	ldrb r0, [r5, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08077370
	ldr r0, [r4]
	movs r1, #8
	orrs r0, r1
	b _08077378
_08077370:
	ldr r0, [r4]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08077378:
	str r0, [r4]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r1, _080773B0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r5, #7]
	cmp r0, r1
	blo _080773E8
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080773B4
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _080773A8
	ldrb r0, [r5, #5]
_080773A8:
	subs r0, #1
	strh r0, [r5, #8]
	b _080773C4
	.align 2, 0
_080773B0: .4byte 0x0000FFFF
_080773B4:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _080773C4
	strh r1, [r5, #8]
_080773C4:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r5, #6]
	ldrb r1, [r5, #6]
	ldrh r0, [r5, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r5, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080773E8
	movs r0, #1
	strb r0, [r5, #7]
_080773E8:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080773f0
FUN_080773f0: @ 0x080773F0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r1, _08077410 @ =0x0000037D
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #5
	bls _08077406
	b _08077A46
_08077406:
	lsls r0, r0, #2
	ldr r1, _08077414 @ =_08077418
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08077410: .4byte 0x0000037D
_08077414: .4byte _08077418
_08077418: @ jump table
	.4byte _08077430 @ case 0
	.4byte _08077548 @ case 1
	.4byte _080775B0 @ case 2
	.4byte _08077608 @ case 3
	.4byte _08077784 @ case 4
	.4byte _08077914 @ case 5
_08077430:
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r4, r6, r2
	movs r3, #0xd5
	lsls r3, r3, #2
	adds r0, r6, r3
	ldr r1, [r0]
	adds r2, #0x4b
	adds r0, r6, r2
	ldrb r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08077480
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08077488
_08077480:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08077488:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080774AC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080774B4
_080774AC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080774B4:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _080774EC @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08077524
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080774F0
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080774E4
	ldrb r0, [r4, #5]
_080774E4:
	subs r0, #1
	strh r0, [r4, #8]
	b _08077500
	.align 2, 0
_080774EC: .4byte 0x0000FFFF
_080774F0:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08077500
	strh r1, [r4, #8]
_08077500:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08077524
	movs r0, #1
	strb r0, [r4, #7]
_08077524:
	ldr r3, _08077544 @ =0x0000037E
	adds r1, r6, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1b
	bhi _08077538
	b _08077A46
_08077538:
	adds r0, r6, #0
	movs r1, #7
	movs r2, #1
	bl FUN_08060b84
	b _08077A46
	.align 2, 0
_08077544: .4byte 0x0000037E
_08077548:
	adds r2, r6, #0
	adds r2, #0xe8
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	ldr r0, _080775A8 @ =0x0000037E
	adds r4, r6, r0
	ldrb r0, [r4]
	lsls r0, r0, #2
	movs r1, #0x40
	subs r1, r1, r0
	adds r0, r6, #0
	adds r0, #0xf0
	strb r1, [r0]
	ldrh r0, [r4]
	cmp r0, #8
	bls _0807758C
	lsls r0, r0, #3
	adds r1, r6, #0
	adds r1, #0xf1
	strb r0, [r1]
	ldrh r0, [r4]
	subs r0, #8
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r2, _080775AC @ =0x000003F6
	adds r0, r6, r2
	strh r1, [r0]
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08060c40
_0807758C:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _0807759C
	b _08077A46
_0807759C:
	adds r0, r6, #0
	movs r1, #7
	movs r2, #2
	bl FUN_08060b84
	b _08077A46
	.align 2, 0
_080775A8: .4byte 0x0000037E
_080775AC: .4byte 0x000003F6
_080775B0:
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08060c40
	ldr r3, _08077600 @ =0x0000037E
	adds r2, r6, r3
	ldrh r1, [r2]
	movs r0, #0xc8
	muls r0, r1, r0
	adds r0, #0xa0
	adds r3, #0x78
	adds r1, r6, r3
	strh r0, [r1]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _080775DA
	b _08077A46
_080775DA:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08060c40
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r0, _08077604 @ =0x080726E1
	str r0, [r1]
	adds r0, r6, #0
	bl FUN_080726b4
	b _08077A46
	.align 2, 0
_08077600: .4byte 0x0000037E
_08077604: .4byte 0x080726E1
_08077608:
	ldr r1, _08077678 @ =0x0000037E
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08077622
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r0, #4
	strb r0, [r1]
	adds r0, r6, #0
	bl FUN_080609dc
_08077622:
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r4, r6, r3
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _0807767C @ =0x00000387
	adds r0, r6, r2
	ldrb r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_08236fac
	adds r7, r6, #0
	adds r7, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov r8, r7
	cmp r1, r0
	beq _08077680
	mov r3, r8
	ldr r0, [r3]
	movs r1, #4
	orrs r0, r1
	str r0, [r3]
	b _0807768E
	.align 2, 0
_08077678: .4byte 0x0000037E
_0807767C: .4byte 0x00000387
_08077680:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, r8
	str r0, [r2]
_0807768E:
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080776B0
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080776B8
_080776B0:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080776B8:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _080776F0 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08077728
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080776F4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080776E8
	ldrb r0, [r4, #5]
_080776E8:
	subs r0, #1
	strh r0, [r4, #8]
	b _08077704
	.align 2, 0
_080776F0: .4byte 0x0000FFFF
_080776F4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08077704
	strh r1, [r4, #8]
_08077704:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08077728
	movs r0, #1
	strb r0, [r4, #7]
_08077728:
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08060c40
	mov r3, r8
	ldr r0, [r3]
	movs r1, #2
	orrs r0, r1
	str r0, [r3]
	adds r1, r6, #0
	adds r1, #0xf0
	movs r0, #4
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x78
	strb r0, [r1]
	ldr r0, _0807777C @ =0x0000037E
	adds r2, r6, r0
	ldrh r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	movs r1, #0xc8
	muls r0, r1, r0
	adds r0, #0xa0
	ldr r3, _08077780 @ =0x000003F6
	adds r1, r6, r3
	strh r0, [r1]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0807776E
	b _08077A46
_0807776E:
	adds r0, r6, #0
	movs r1, #7
	movs r2, #4
	bl FUN_08060b84
	b _08077A46
	.align 2, 0
_0807777C: .4byte 0x0000037E
_08077780: .4byte 0x000003F6
_08077784:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _080777DC @ =0x00000387
	adds r0, r6, r2
	ldrb r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_08236fac
	adds r7, r6, #0
	adds r7, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov r8, r7
	cmp r1, r0
	beq _080777E0
	mov r3, r8
	ldr r0, [r3]
	movs r1, #4
	orrs r0, r1
	str r0, [r3]
	b _080777EE
	.align 2, 0
_080777DC: .4byte 0x00000387
_080777E0:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, r8
	str r0, [r2]
_080777EE:
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08077810
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _08077818
_08077810:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08077818:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _08077850 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08077888
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08077854
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08077848
	ldrb r0, [r4, #5]
_08077848:
	subs r0, #1
	strh r0, [r4, #8]
	b _08077864
	.align 2, 0
_08077850: .4byte 0x0000FFFF
_08077854:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08077864
	strh r1, [r4, #8]
_08077864:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08077888
	movs r0, #1
	strb r0, [r4, #7]
_08077888:
	mov r3, r8
	ldr r0, [r3]
	movs r1, #2
	orrs r0, r1
	str r0, [r3]
	ldr r0, _080778CC @ =0x0000037E
	adds r3, r6, r0
	ldrb r1, [r3]
	movs r2, #0xf
	subs r1, r2, r1
	lsls r1, r1, #2
	movs r0, #0x40
	subs r0, r0, r1
	adds r1, r6, #0
	adds r1, #0xf0
	strb r0, [r1]
	ldrh r0, [r3]
	cmp r0, #7
	bhi _080778D4
	subs r0, r2, r0
	lsls r0, r0, #3
	adds r2, r6, #0
	adds r2, #0xf1
	strb r0, [r2]
	ldrh r1, [r3]
	movs r0, #8
	subs r0, r0, r1
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r2, _080778D0 @ =0x000003F6
	adds r0, r6, r2
	strh r1, [r0]
	b _080778EC
	.align 2, 0
_080778CC: .4byte 0x0000037E
_080778D0: .4byte 0x000003F6
_080778D4:
	adds r1, r6, #0
	adds r1, #0xf1
	movs r0, #0x40
	strb r0, [r1]
	ldr r3, _0807790C @ =0x000003F6
	adds r1, r6, r3
	movs r0, #0
	strh r0, [r1]
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08060c40
_080778EC:
	ldr r0, _08077910 @ =0x0000037E
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _08077900
	b _08077A46
_08077900:
	adds r0, r6, #0
	movs r1, #7
	movs r2, #5
	bl FUN_08060b84
	b _08077A46
	.align 2, 0
_0807790C: .4byte 0x000003F6
_08077910: .4byte 0x0000037E
_08077914:
	adds r4, r6, #0
	adds r4, #0xe8
	ldr r0, [r4]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r5, r6, r1
	movs r2, #0xd5
	lsls r2, r2, #2
	adds r0, r6, r2
	ldr r1, [r0]
	ldr r3, _08077970 @ =0x00000387
	adds r0, r6, r3
	ldrb r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_08236fac
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r4, #0x10]
	ldrb r0, [r5, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08077974
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	b _0807797C
	.align 2, 0
_08077970: .4byte 0x00000387
_08077974:
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0807797C:
	str r0, [r4]
	ldrb r0, [r5, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080779A0
	ldr r0, [r4]
	movs r1, #8
	orrs r0, r1
	b _080779A8
_080779A0:
	ldr r0, [r4]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080779A8:
	str r0, [r4]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r1, _080779E0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r5, #7]
	cmp r0, r3
	blo _08077A18
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080779E4
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _080779D8
	ldrb r0, [r5, #5]
_080779D8:
	subs r0, #1
	strh r0, [r5, #8]
	b _080779F4
	.align 2, 0
_080779E0: .4byte 0x0000FFFF
_080779E4:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _080779F4
	strh r1, [r5, #8]
_080779F4:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r5, #6]
	ldrb r1, [r5, #6]
	ldrh r0, [r5, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r5, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08077A18
	movs r0, #1
	strb r0, [r5, #7]
_08077A18:
	ldr r3, _08077A54 @ =0x0000037E
	adds r1, r6, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _08077A46
	adds r0, r6, #0
	bl FUN_080609dc
	adds r0, r6, #0
	bl FUN_08072620
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r0, _08077A58 @ =FUN_080772ec
	str r0, [r1]
	adds r0, r6, #0
	bl FUN_080726b4
_08077A46:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08077A54: .4byte 0x0000037E
_08077A58: .4byte FUN_080772ec

	thumb_func_start FUN_08077a5c
FUN_08077a5c: @ 0x08077A5C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r1, _08077A88 @ =0x0000037E
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08077B24
	movs r0, #0xf5
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r2, _08077A8C @ =0x0000043E
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _08077A90
	adds r1, r6, #0
	adds r1, #0xc2
	movs r0, #0x20
	b _08077B22
	.align 2, 0
_08077A88: .4byte 0x0000037E
_08077A8C: .4byte 0x0000043E
_08077A90:
	ldr r1, _08077AB4 @ =0x0000038E
	adds r0, r6, r1
	ldrb r0, [r0]
	ldr r1, _08077AB8 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r2, #0xb2
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r0, #0
	ble _08077ABC
	adds r1, r6, #0
	adds r1, #0xc2
	movs r0, #0x21
	b _08077B22
	.align 2, 0
_08077AB4: .4byte 0x0000038E
_08077AB8: .4byte 0x030046A0
_08077ABC:
	movs r0, #0x80
	lsls r0, r0, #0xd
	movs r2, #0xde
	lsls r2, r2, #2
	adds r1, r6, r2
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _08077AD8
	adds r1, r6, #0
	adds r1, #0xc2
	movs r0, #0x94
	lsls r0, r0, #1
	b _08077B22
_08077AD8:
	movs r0, #0x80
	lsls r0, r0, #0xe
	ands r0, r1
	cmp r0, #0
	beq _08077AF0
	adds r1, r6, #0
	adds r1, #0xc2
	ldr r0, _08077AEC @ =0x00000129
	b _08077B22
	.align 2, 0
_08077AEC: .4byte 0x00000129
_08077AF0:
	movs r0, #0x80
	lsls r0, r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08077B04
	adds r1, r6, #0
	adds r1, #0xc2
	movs r0, #0x95
	lsls r0, r0, #1
	b _08077B22
_08077B04:
	movs r0, #0x80
	lsls r0, r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _08077B1C
	adds r1, r6, #0
	adds r1, #0xc2
	ldr r0, _08077B18 @ =0x0000012B
	b _08077B22
	.align 2, 0
_08077B18: .4byte 0x0000012B
_08077B1C:
	adds r1, r6, #0
	adds r1, #0xc2
	movs r0, #0x26
_08077B22:
	strh r0, [r1]
_08077B24:
	adds r0, r6, #0
	movs r1, #0x40
	bl FUN_08060c40
	adds r0, r6, #0
	movs r1, #0xc7
	movs r2, #0x40
	bl FUN_08060a24
	adds r2, r6, #0
	adds r2, #0xa8
	ldr r0, [r6, #0x2c]
	ldr r1, [r6, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	adds r2, #0x28
	ldr r0, _08077BB8 @ =0x03003584
	adds r1, r6, #0
	adds r1, #0xc2
	ldrh r1, [r1]
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2]
	ldr r1, _08077BBC @ =0x0000037E
	adds r0, r6, r1
	ldrh r0, [r0]
	lsls r1, r0, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #9
	bls _08077B64
	b _08077C66
_08077B64:
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r4, r6, r2
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	adds r2, #0x4b
	adds r0, r6, r2
	ldrb r2, [r0]
	adds r2, #8
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08077BC0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08077BC8
	.align 2, 0
_08077BB8: .4byte 0x03003584
_08077BBC: .4byte 0x0000037E
_08077BC0:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08077BC8:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08077BEC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08077BF4
_08077BEC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08077BF4:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08077C2C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08077C78
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08077C30
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08077C24
	ldrb r0, [r4, #5]
_08077C24:
	subs r0, #1
	strh r0, [r4, #8]
	b _08077C40
	.align 2, 0
_08077C2C: .4byte 0x0000FFFF
_08077C30:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08077C40
	strh r1, [r4, #8]
_08077C40:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08077C78
	movs r0, #1
	strb r0, [r4, #7]
	b _08077C78
_08077C66:
	lsrs r0, r1, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08077C78
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08060c40
_08077C78:
	ldr r0, _08077CB0 @ =0x0000037E
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x27
	bls _08077CA6
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r4, #1
	strb r4, [r0]
	ldr r2, _08077CB4 @ =0x00000381
	adds r0, r6, r2
	strb r4, [r0]
	adds r0, r6, #0
	bl FUN_08072620
	ldr r1, _08077CB8 @ =0x000004AF
	adds r0, r6, r1
	strb r4, [r0]
_08077CA6:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08077CB0: .4byte 0x0000037E
_08077CB4: .4byte 0x00000381
_08077CB8: .4byte 0x000004AF

	thumb_func_start FUN_08077cbc
FUN_08077cbc: @ 0x08077CBC
	push {r4, r5, r6, lr}
	sub sp, #0x18
	adds r4, r0, #0
	movs r1, #8
	bl FUN_08060c40
	ldr r1, _08077CE0 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bls _08077CD4
	b _08077FF2
_08077CD4:
	lsls r0, r0, #2
	ldr r1, _08077CE4 @ =_08077CE8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08077CE0: .4byte 0x0000037D
_08077CE4: .4byte _08077CE8
_08077CE8: @ jump table
	.4byte _08077D00 @ case 0
	.4byte _08077D38 @ case 1
	.4byte _08077DE8 @ case 2
	.4byte _08077F10 @ case 3
	.4byte _08077F8C @ case 4
	.4byte _08077FC4 @ case 5
_08077D00:
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
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08077D2C
	b _08077FF2
_08077D2C:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #1
	bl FUN_08060b84
	b _08077FF2
_08077D38:
	ldr r2, _08077DC8 @ =0x0000037E
	adds r5, r4, r2
	ldrh r2, [r5]
	cmp r2, #0
	bne _08077D66
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #4
	strb r0, [r1]
	ldr r0, _08077DCC @ =0x000002E6
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08077DD0 @ =0x000002E7
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_08067f88
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_08077D66:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #8
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	bne _08077D8E
	b _08077FF2
_08077D8E:
	movs r0, #0xcb
	bl PlaySound_082406e0
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08077DA8
	b _08077F4C
_08077DA8:
	movs r0, #0x10
	ldr r1, [r4, #0x20]
	ands r1, r0
	cmp r1, #0
	beq _08077DDC
	movs r0, #0xd8
	bl PlaySound_082406e0
	ldr r0, _08077DD4 @ =0x00000409
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _08077DD8 @ =0x00000404
	adds r1, r4, r2
	b _08077F74
	.align 2, 0
_08077DC8: .4byte 0x0000037E
_08077DCC: .4byte 0x000002E6
_08077DD0: .4byte 0x000002E7
_08077DD4: .4byte 0x00000409
_08077DD8: .4byte 0x00000404
_08077DDC:
	ldr r2, _08077DE4 @ =0x00000404
	adds r0, r4, r2
	strh r1, [r0]
	b _08077E8A
	.align 2, 0
_08077DE4: .4byte 0x00000404
_08077DE8:
	movs r1, #0xa0
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	ldr r0, _08077E6C @ =0x00000404
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #4
	bhi _08077E1A
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bne _08077E1A
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08077E1A
	movs r0, #0x94
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08077E1A:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
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
	movs r6, #0
	movs r0, #0x1e
	strh r0, [r1]
	movs r2, #0x93
	lsls r2, r2, #4
	adds r1, r4, r2
	adds r0, r4, #0
	bl FUN_08061f6c
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _08077E74
	movs r0, #0xd8
	bl sound_08240740
	ldr r2, _08077E70 @ =0x00000409
	adds r0, r4, r2
	strb r6, [r0]
	b _08077F4C
	.align 2, 0
_08077E6C: .4byte 0x00000404
_08077E70: .4byte 0x00000409
_08077E74:
	movs r1, #0x10
	ldr r0, [r4, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08077E9C
	movs r0, #0xd8
	bl sound_08240740
	ldr r1, _08077E98 @ =0x00000409
	adds r0, r4, r1
	strb r6, [r0]
_08077E8A:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #3
	bl FUN_08060b84
	b _08077FF2
	.align 2, 0
_08077E98: .4byte 0x00000409
_08077E9C:
	ldr r0, _08077F00 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _08077F04 @ =0x00000942
	adds r0, r0, r2
	ldr r2, _08077F08 @ =0x00000436
	adds r1, r4, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r2, #0x87
	lsls r2, r2, #3
	adds r1, r4, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	bhs _08077EC4
	b _08077FF2
_08077EC4:
	bl FUN_0809c58c
	adds r0, r4, #0
	movs r1, #7
	movs r2, #5
	bl FUN_08060b84
	movs r0, #0x96
	lsls r0, r0, #3
	adds r2, r4, r0
	ldr r3, [r2]
	cmp r3, #0
	bne _08077EE0
	b _08077FF2
_08077EE0:
	ldr r1, _08077F0C @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	orrs r0, r5
	str r0, [sp, #4]
	add r1, sp, #4
	mov r0, sp
	str r0, [r1, #4]
	str r5, [sp]
	movs r0, #0
	str r0, [r2]
	adds r0, r3, #0
	bl FUN_082318ac
	b _08077FF2
	.align 2, 0
_08077F00: .4byte 0x030046A0
_08077F04: .4byte 0x00000942
_08077F08: .4byte 0x00000436
_08077F0C: .4byte 0xFFFF0000
_08077F10:
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
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08077F58
_08077F4C:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #4
	bl FUN_08060b84
	b _08077FF2
_08077F58:
	movs r1, #0x10
	ldr r0, [r4, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _08077FF2
	movs r0, #0xd8
	bl PlaySound_082406e0
	ldr r2, _08077F84 @ =0x00000409
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _08077F88 @ =0x00000404
	adds r1, r4, r0
_08077F74:
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #7
	movs r2, #2
	bl FUN_08060b84
	b _08077FF2
	.align 2, 0
_08077F84: .4byte 0x00000409
_08077F88: .4byte 0x00000404
_08077F8C:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0xb
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08077FF2
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	movs r1, #7
	movs r2, #0
	bl FUN_08060b84
	b _08077FF2
_08077FC4:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
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
	bl FUN_08061f6c
_08077FF2:
	ldr r1, _08078054 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _0807804C
	ldr r2, _08078058 @ =0x00000434
	adds r1, r4, r2
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne _0807804C
	bl FUN_0809c58c
	movs r0, #0xd8
	bl sound_08240740
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	bl FUN_08072620
	movs r0, #0x96
	lsls r0, r0, #3
	adds r2, r4, r0
	ldr r3, [r2]
	cmp r3, #0
	beq _0807804C
	ldr r1, _0807805C @ =0xFFFF0000
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
_0807804C:
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08078054: .4byte 0x0000037D
_08078058: .4byte 0x00000434
_0807805C: .4byte 0xFFFF0000

	thumb_func_start FUN_08078060
FUN_08078060: @ 0x08078060
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

	thumb_func_start FUN_0807849c
FUN_0807849c: @ 0x0807849C
	push {lr}
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldrh r3, [r0]
	movs r0, #0x40
	ands r0, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	rsbs r0, r0, #0
	lsrs r2, r0, #0x1f
	movs r0, #0x80
	ands r0, r3
	cmp r0, #0
	beq _080784C0
	movs r0, #2
	orrs r2, r0
_080784C0:
	movs r0, #0x20
	ands r0, r3
	cmp r0, #0
	beq _080784D4
	movs r1, #4
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_080784D4:
	movs r0, #0x10
	ands r0, r3
	cmp r0, #0
	beq _080784E8
	movs r1, #8
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_080784E8:
	ldr r0, _080784F8 @ =0x085ABC8A
	lsls r1, r2, #0x10
	asrs r1, r1, #0xf
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	pop {r1}
	bx r1
	.align 2, 0
_080784F8: .4byte 0x085ABC8A

	thumb_func_start FUN_080784fc
FUN_080784fc: @ 0x080784FC
	push {r4, lr}
	adds r4, r0, #0
	movs r2, #9
	movs r0, #0xa8
	lsls r0, r0, #2
	adds r1, r4, r0
_08078508:
	ldrh r0, [r1]
	strh r0, [r1, #2]
	subs r1, #2
	subs r2, #1
	cmp r2, #0
	bgt _08078508
	adds r0, r4, #0
	bl FUN_0807849c
	adds r1, r0, #0
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r2, r4, r3
	strh r1, [r2]
	lsls r0, r1, #0x10
	cmp r0, #0
	blt _0807853E
	ldr r3, _08078544 @ =0x00000456
	adds r0, r4, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, r1, r0
	adds r0, #7
	movs r1, #7
	ands r0, r1
	strh r0, [r2]
_0807853E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08078544: .4byte 0x00000456

	thumb_func_start FUN_08078548
FUN_08078548: @ 0x08078548
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08060c60
	ldr r1, _08078568 @ =0x000003CE
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _08078562
	adds r0, r4, #0
	bl FUN_08066d10
_08078562:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08078568: .4byte 0x000003CE

	thumb_func_start FUN_0807856c
FUN_0807856c: @ 0x0807856C
	push {lr}
	adds r1, r0, #0
	ldr r2, _08078588 @ =0x000003CE
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _08078582
	adds r0, r1, #0
	bl FUN_08066d10
_08078582:
	pop {r0}
	bx r0
	.align 2, 0
_08078588: .4byte 0x000003CE

	thumb_func_start FUN_0807858c
FUN_0807858c: @ 0x0807858C
	push {r4, r5, lr}
	sub sp, #0x20
	adds r5, r0, #0
	ldr r0, _080785B8 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xdd
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	cmp r1, #0
	beq _0807867A
	ldr r0, _080785BC @ =0x000009C3
	cmp r1, r0
	bgt _080785C0
	movs r0, #0xf9
	lsls r0, r0, #2
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	b _080785CA
	.align 2, 0
_080785B8: .4byte 0x030046A0
_080785BC: .4byte 0x000009C3
_080785C0:
	movs r2, #0xf9
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #2
_080785CA:
	strh r0, [r1]
	movs r1, #0xf9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0xf
	bls _0807867A
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0807861C
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r3, _08078614 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r3
	movs r2, #0x20
	orrs r0, r2
	ldr r1, _08078618 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r3
	b _08078652
	.align 2, 0
_08078614: .4byte 0xFFFF0000
_08078618: .4byte 0x0000FFFF
_0807861C:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r2, [sp, #0x18]
	asrs r1, r2, #0x10
	movs r0, #0xb4
	lsls r0, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r3, _08078684 @ =0x0000FFFF
	adds r0, r3, #0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r4, _08078688 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r4
	movs r2, #0x20
	orrs r0, r2
	ands r0, r3
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r4
_08078652:
	orrs r0, r2
	str r0, [sp, #0x14]
	add r0, sp, #0x18
	movs r4, #0
	str r4, [sp]
	movs r1, #6
	str r1, [sp, #4]
	movs r1, #3
	str r1, [sp, #8]
	movs r1, #2
	str r1, [sp, #0xc]
	movs r1, #1
	add r2, sp, #0x10
	movs r3, #0
	bl FUN_080ddcc8
	movs r1, #0xf9
	lsls r1, r1, #2
	adds r0, r5, r1
	strh r4, [r0]
_0807867A:
	add sp, #0x20
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08078684: .4byte 0x0000FFFF
_08078688: .4byte 0xFFFF0000

	thumb_func_start FUN_0807868c
FUN_0807868c: @ 0x0807868C
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r1, _08078700 @ =0x000003F3
	adds r0, r5, r1
	ldrb r4, [r0]
	cmp r4, #0
	beq _0807869E
	b _080787EE
_0807869E:
	ldr r2, _08078704 @ =0x000003BD
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r2, r3, #7
	movs r0, #7
	ands r2, r0
	adds r1, r3, #0
	adds r1, #9
	ands r1, r0
	movs r6, #0xa4
	lsls r6, r6, #2
	adds r0, r5, r6
	movs r6, #0
	ldrsh r0, [r0, r6]
	cmp r0, r3
	beq _080786C8
	cmp r0, r2
	beq _080786C8
	cmp r0, r1
	beq _080786C8
	b _0807881C
_080786C8:
	ldr r1, _08078704 @ =0x000003BD
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, _08078708 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x32
	muls r0, r1, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _0807870C
	asrs r2, r0, #0xc
	b _08078712
	.align 2, 0
_08078700: .4byte 0x000003F3
_08078704: .4byte 0x000003BD
_08078708: .4byte 0x085B0A08
_0807870C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08078712:
	mov r0, sp
	ldrh r1, [r0]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0807873C @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	lsls r0, r3, #1
	adds r0, r0, r4
	movs r6, #0
	ldrsh r1, [r0, r6]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _08078740
	asrs r2, r0, #0xc
	b _08078746
	.align 2, 0
_0807873C: .4byte 0xFFFF0000
_08078740:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08078746:
	mov r0, sp
	ldrh r1, [r0, #4]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08078788 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	mov r6, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08078782
	cmp r1, #0
	blt _08078782
	ldr r0, _0807878C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08078782
	ldr r0, _08078790 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08078794
_08078782:
	movs r4, #0
	b _080787A2
	.align 2, 0
_08078788: .4byte 0xFFFF0000
_0807878C: .4byte 0x030046A8
_08078790: .4byte 0x030046AC
_08078794:
	ldr r0, _080787B4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080787A2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080787B8
	adds r0, #4
	b _080787C4
	.align 2, 0
_080787B4: .4byte 0x030046A4
_080787B8:
	ldr r0, _080787D8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080787C4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080787DC
	cmp r2, #2
	beq _080787E0
	b _080787E4
	.align 2, 0
_080787D8: .4byte 0x030046A4
_080787DC:
	ldrb r0, [r6, #4]
	b _080787E2
_080787E0:
	ldrb r0, [r6]
_080787E2:
	subs r1, r1, r0
_080787E4:
	movs r2, #0x2e
	ldrsh r0, [r5, r2]
	adds r0, #0xc8
	cmp r1, r0
	blo _080787F2
_080787EE:
	movs r0, #1
	b _0807883A
_080787F2:
	ldr r4, _08078818 @ =0x000003BD
	adds r0, r5, r4
	ldrb r0, [r0]
	adds r0, #4
	movs r1, #7
	ands r0, r1
	movs r6, #0xba
	lsls r6, r6, #2
	adds r1, r5, r6
	movs r4, #0
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_080609dc
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	b _08078836
	.align 2, 0
_08078818: .4byte 0x000003BD
_0807881C:
	adds r0, r3, #4
	movs r1, #7
	ands r0, r1
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r5, r2
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_080609dc
	movs r6, #0xdf
	lsls r6, r6, #2
	adds r0, r5, r6
_08078836:
	strb r4, [r0]
	movs r0, #0
_0807883A:
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08078844
FUN_08078844: @ 0x08078844
	push {r4, lr}
	adds r2, r0, #0
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080788A8
	ldr r0, _0807889C @ =0x03002C00
	ldr r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	beq _080788A8
	ldr r4, _080788A0 @ =0x000001F5
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, #1
	beq _08078872
	cmp r0, #0x10
	bne _080788A8
_08078872:
	ldr r1, _080788A4 @ =0x00000392
	adds r0, r2, r1
	ldrh r0, [r0]
	movs r4, #0xe4
	lsls r4, r4, #2
	adds r1, r2, r4
	ldrh r1, [r1]
	ldr r3, [r3]
	subs r4, #0xa
	adds r2, r3, r4
	ldrh r2, [r2]
	subs r4, #2
	adds r3, r3, r4
	ldrb r3, [r3]
	bl FUN_0808626c
	cmp r0, #0
	beq _080788A8
	movs r0, #1
	b _080788AA
	.align 2, 0
_0807889C: .4byte 0x03002C00
_080788A0: .4byte 0x000001F5
_080788A4: .4byte 0x00000392
_080788A8:
	movs r0, #0
_080788AA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080788b0
FUN_080788b0: @ 0x080788B0
	push {lr}
	adds r3, r0, #0
	adds r3, #0x2c
	ldr r2, _080788CC @ =0x00000392
	adds r1, r0, r2
	ldrh r1, [r1]
	subs r2, #2
	adds r0, r0, r2
	ldrh r2, [r0]
	adds r0, r3, #0
	bl FUN_08086294
	pop {r1}
	bx r1
	.align 2, 0
_080788CC: .4byte 0x00000392

	thumb_func_start FUN_080788d0
FUN_080788d0: @ 0x080788D0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x14
	beq _08078910
	ldr r2, _080789C0 @ =0x000003FF
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08078910
	movs r3, #0xf5
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	adds r3, #0x22
	adds r0, r5, r3
	strh r1, [r0]
	adds r0, r5, #0
	movs r1, #0x14
	movs r2, #0
	bl FUN_08060b84
_08078910:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #4
	beq _08078932
	ldr r2, _080789C4 @ =0x000003F3
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08078932
	ldr r3, _080789C8 @ =0x000003BD
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r0, r5, #0
	bl FUN_0807a44c
_08078932:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r4, [r0]
	ldr r2, _080789CC @ =0x00000446
	adds r0, r5, r2
	ldrh r1, [r0]
	movs r2, #0
	adds r6, r0, #0
	cmp r1, #0
	beq _08078954
	ldr r3, _080789D0 @ =0x00000442
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r0, #5
	bne _08078954
	movs r2, #1
_08078954:
	cmp r2, #0
	bne _08078974
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08078974
	adds r0, r5, #0
	bl FUN_08064db0
	adds r4, r0, #0
_08078974:
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _080789E0
	ldr r3, _080789D4 @ =0x000003D2
	adds r0, r5, r3
	ldrb r0, [r0]
	movs r4, #0x18
	cmp r0, #0
	beq _0807898E
	movs r4, #0x19
_0807898E:
	ldr r7, _080789D8 @ =0x03002BA8
	ldr r2, [r7]
	cmp r2, #0
	beq _080789B8
	ldr r6, _080789DC @ =0x03002BF4
	ldrh r0, [r6]
	cmp r0, #0
	beq _080789B8
	ldr r0, [r2, #4]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080789B2
	ldr r0, [r2]
	ldr r3, [r2, #8]
	movs r2, #0x3c
	bl _call_via_r3
_080789B2:
	movs r0, #0
	str r0, [r7]
	strh r0, [r6]
_080789B8:
	adds r0, r5, #0
	bl FUN_08078548
	b _08078BB6
	.align 2, 0
_080789C0: .4byte 0x000003FF
_080789C4: .4byte 0x000003F3
_080789C8: .4byte 0x000003BD
_080789CC: .4byte 0x00000446
_080789D0: .4byte 0x00000442
_080789D4: .4byte 0x000003D2
_080789D8: .4byte 0x03002BA8
_080789DC: .4byte 0x03002BF4
_080789E0:
	adds r0, r4, #0
	subs r0, #0x18
	cmp r0, #1
	bls _08078A0A
	cmp r4, #0x16
	beq _08078A0A
	cmp r4, #0x17
	beq _08078A0A
	cmp r4, #0x15
	beq _08078A0A
	cmp r4, #0x14
	beq _08078A0A
	cmp r4, #0x13
	beq _08078A0A
	movs r1, #0xfb
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08078A0A
	movs r4, #0x12
_08078A0A:
	subs r0, r4, #2
	cmp r0, #0x1e
	bhi _08078AC0
	lsls r0, r0, #2
	ldr r1, _08078A1C @ =_08078A20
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08078A1C: .4byte _08078A20
_08078A20: @ jump table
	.4byte _08078BB6 @ case 0
	.4byte _08078BB6 @ case 1
	.4byte _08078A9C @ case 2
	.4byte _08078BB6 @ case 3
	.4byte _08078AAC @ case 4
	.4byte _08078BB6 @ case 5
	.4byte _08078BB6 @ case 6
	.4byte _08078BB6 @ case 7
	.4byte _08078BB6 @ case 8
	.4byte _08078BB6 @ case 9
	.4byte _08078BB6 @ case 10
	.4byte _08078BB6 @ case 11
	.4byte _08078BB6 @ case 12
	.4byte _08078BB6 @ case 13
	.4byte _08078BB6 @ case 14
	.4byte _08078BB6 @ case 15
	.4byte _08078BB6 @ case 16
	.4byte _08078BB6 @ case 17
	.4byte _08078BB6 @ case 18
	.4byte _08078BB6 @ case 19
	.4byte _08078BB6 @ case 20
	.4byte _08078BB6 @ case 21
	.4byte _08078BB6 @ case 22
	.4byte _08078BB6 @ case 23
	.4byte _08078AC0 @ case 24
	.4byte _08078AC0 @ case 25
	.4byte _08078AC0 @ case 26
	.4byte _08078AC0 @ case 27
	.4byte _08078AC0 @ case 28
	.4byte _08078AC0 @ case 29
	.4byte _08078BB6 @ case 30
_08078A9C:
	adds r0, r5, #0
	bl FUN_0807868c
	cmp r0, #0
	beq _08078AA8
	b _08078BB6
_08078AA8:
	movs r4, #0
	b _08078BB6
_08078AAC:
	adds r0, r5, #0
	bl FUN_08078844
	cmp r0, #0
	beq _08078AB8
	b _08078BB6
_08078AB8:
	movs r0, #0xda
	bl PlaySound_082406e0
	b _08078AA8
_08078AC0:
	ldrh r0, [r6]
	movs r1, #0
	cmp r0, #0
	beq _08078AD4
	ldr r2, _08078B18 @ =0x00000442
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #5
	bne _08078AD4
	movs r1, #1
_08078AD4:
	cmp r1, #0
	beq _08078B1C
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08078AF8
	adds r0, r5, #0
	adds r0, #0x24
	bl FUN_08006194
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08078AA8
_08078AF8:
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08078AA8
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	ldrh r1, [r0]
	b _08078BA8
	.align 2, 0
_08078B18: .4byte 0x00000442
_08078B1C:
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r2, [r0]
	ldrh r1, [r2, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08078B64
	movs r1, #0x80
	lsls r1, r1, #7
	adds r0, r5, #0
	bl FUN_08060ed8
	cmp r0, #0
	bne _08078B52
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08060ed8
	cmp r0, #0
	beq _08078B60
	ldr r2, _08078B5C @ =0x00000A75
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #3
	beq _08078B60
_08078B52:
	movs r4, #0
	adds r0, r5, #0
	bl FUN_08060ee8
	b _08078BB6
	.align 2, 0
_08078B5C: .4byte 0x00000A75
_08078B60:
	movs r4, #3
	b _08078BB6
_08078B64:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08078B92
	adds r0, r5, #0
	bl FUN_080788b0
	cmp r0, #0
	beq _08078B80
	movs r0, #0xda
	bl PlaySound_082406e0
	movs r4, #6
	b _08078BB6
_08078B80:
	adds r0, r5, #0
	adds r0, #0x24
	bl FUN_08006194
	lsls r0, r0, #0x18
	movs r4, #7
	cmp r0, #0
	beq _08078BB6
	b _08078AA8
_08078B92:
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _08078BA6
	b _08078AA8
_08078BA6:
	ldrh r1, [r2]
_08078BA8:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08078BB4
	b _08078AA8
_08078BB4:
	movs r4, #1
_08078BB6:
	adds r0, r4, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08078bc0
FUN_08078bc0: @ 0x08078BC0
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xe4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r4, [r0]
	cmp r4, #0
	bne _08078BF4
	adds r0, r5, #0
	movs r1, #0x10
	bl FUN_08060c50
	cmp r0, #0
	bne _08078BF2
	ldr r0, [r5, #0x3c]
	cmp r0, #0
	bne _08078BF4
	movs r2, #0xde
	lsls r2, r2, #1
	adds r4, r5, r2
	adds r1, r5, #0
	adds r1, #0x2c
	adds r0, r4, #0
	bl FUN_0823280c
_08078BF2:
	str r4, [r5, #0x3c]
_08078BF4:
	adds r4, r5, #0
	adds r4, #0x24
	adds r0, r4, #0
	bl FUN_0823b4b8
	adds r0, r4, #0
	bl FUN_080417dc
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08060c50
	cmp r0, #0
	beq _08078C20
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	b _08078C3E
_08078C20:
	movs r1, #0xb9
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	ldr r0, _08078C58 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r1, r5, #0
	adds r1, #0x2c
	movs r2, #0
	bl FUN_082364c4
_08078C3E:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08060c50
	cmp r0, #0
	beq _08078C5C
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _08078C68
	.align 2, 0
_08078C58: .4byte 0x0000FFFB
_08078C5C:
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_08078C68:
	str r1, [r0]
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #2
	bl FUN_08060c50
	cmp r0, #0
	beq _08078C82
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	b _08078C88
_08078C82:
	ldr r0, [r4]
	ldr r1, _08078CA4 @ =0xFFFFFDFF
	ands r0, r1
_08078C88:
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0x40
	bl FUN_08060c50
	cmp r0, #0
	beq _08078CA8
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _08078CB2
	.align 2, 0
_08078CA4: .4byte 0xFFFFFDFF
_08078CA8:
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_08078CB2:
	str r1, [r0]
	adds r0, r5, #0
	movs r1, #4
	bl FUN_08060c50
	cmp r0, #0
	beq _08078CD0
	ldr r1, _08078CCC @ =0x0000060C
	adds r0, r5, r1
	bl FUN_080136b4
	b _08078CD8
	.align 2, 0
_08078CCC: .4byte 0x0000060C
_08078CD0:
	ldr r2, _08078D44 @ =0x0000060C
	adds r0, r5, r2
	bl FUN_08013698
_08078CD8:
	movs r1, #0xfe
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	ldrh r2, [r5, #0x2e]
	adds r0, r0, r2
	strh r0, [r5, #0x2e]
	adds r4, r5, #0
	adds r4, #0xa8
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [r4]
	str r1, [r4, #4]
	adds r1, r5, #0
	adds r1, #0xaa
	ldr r2, _08078D48 @ =0x000003F6
	adds r0, r5, r2
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r0, _08078D4C @ =0x0000044B
	adds r3, r5, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _08078D3C
	ldr r2, _08078D50 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08078D54 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08078D58 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0xf
	ands r1, r0
	subs r1, #7
	ldrh r0, [r4]
	adds r0, r0, r1
	strh r0, [r4]
	adds r2, r5, #0
	adds r2, #0xac
	ldrh r0, [r2]
	subs r0, r0, r1
	strh r0, [r2]
	ldrb r0, [r3]
	subs r0, #1
	strb r0, [r3]
_08078D3C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08078D44: .4byte 0x0000060C
_08078D48: .4byte 0x000003F6
_08078D4C: .4byte 0x0000044B
_08078D50: .4byte 0x030046B8
_08078D54: .4byte 0x000003FF
_08078D58: .4byte 0x0203B400

	thumb_func_start FUN_08078d5c
FUN_08078d5c: @ 0x08078D5C
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0x80
	lsls r0, r0, #7
	ldr r1, [r5, #0x20]
	orrs r1, r0
	str r1, [r5, #0x20]
	ldr r0, [r5, #0x1c]
	cmp r0, #2
	bne _08078D74
	b _08079104
_08078D74:
	cmp r0, #2
	bhi _08078D7E
	cmp r0, #1
	beq _08078D86
	b _0807912E
_08078D7E:
	cmp r0, #4
	bne _08078D84
	b _080790B0
_08078D84:
	b _0807912E
_08078D86:
	adds r0, r5, #0
	bl FUN_0807858c
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08078DAA
	adds r0, r5, #0
	bl FUN_0806680c
	cmp r0, #0
	beq _08078DDC
	adds r0, r5, #0
	bl FUN_0806687c
	b _08078DDC
_08078DAA:
	ldr r0, [r5, #0x20]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08078DC6
	ldr r0, _08078E1C @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _08078E20 @ =0x00000942
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl FUN_080667b0
_08078DC6:
	adds r0, r5, #0
	bl FUN_0806680c
	cmp r0, #0
	beq _08078DDC
	adds r0, r5, #0
	bl FUN_0806687c
	adds r0, r5, #0
	bl FUN_0806692c
_08078DDC:
	adds r0, r5, #0
	bl FUN_080784fc
	adds r0, r5, #0
	bl FUN_080788d0
	adds r4, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08066d7c
	ldr r1, _08078E24 @ =0x085ABCAC
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	movs r4, #0xe9
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _08078E28
	movs r1, #0xea
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x34]
	str r1, [r5, #0x38]
	b _08078E2E
	.align 2, 0
_08078E1C: .4byte 0x030046A0
_08078E20: .4byte 0x00000942
_08078E24: .4byte 0x085ABCAC
_08078E28:
	adds r0, r5, #0
	bl FUN_08066408
_08078E2E:
	adds r0, r5, #0
	bl FUN_08078bc0
	ldr r2, _08078F14 @ =0x000003CE
	adds r0, r5, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	beq _08078E46
	adds r0, r5, #0
	bl FUN_08066df8
_08078E46:
	adds r0, r5, #0
	bl FUN_08065b7c
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #1
	bne _08078E5E
	adds r0, r5, #0
	bl FUN_08065dac
_08078E5E:
	adds r0, r5, #0
	bl FUN_0806623c
	ldr r1, _08078F18 @ =0x00000446
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _08078E7C
	ldr r2, _08078F1C @ =0x00000442
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #5
	bne _08078E7C
	movs r1, #1
_08078E7C:
	cmp r1, #0
	beq _08078E82
	b _0807912E
_08078E82:
	movs r4, #0
	movs r3, #0xe5
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	bl FUN_08065b44
	cmp r0, #0
	bne _08078EC0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r2, [r0]
	cmp r2, #1
	bne _08078EC0
	movs r3, #0xde
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _08078EC0
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r1, [r0]
	ands r1, r2
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r4, r0, #0x1f
_08078EC0:
	cmp r4, #0
	bne _08078EC6
	b _080790A4
_08078EC6:
	ldr r0, _08078F20 @ =0x000003BE
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	beq _08078EDA
	b _0807912E
_08078EDA:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08078F24 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x32
	muls r0, r1, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _08078F28
	asrs r2, r0, #0xc
	b _08078F2E
	.align 2, 0
_08078F14: .4byte 0x000003CE
_08078F18: .4byte 0x00000446
_08078F1C: .4byte 0x00000442
_08078F20: .4byte 0x000003BE
_08078F24: .4byte 0x085B0A08
_08078F28:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08078F2E:
	mov r0, sp
	ldrh r1, [r0]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08078F58 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	lsls r0, r3, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _08078F5C
	asrs r2, r0, #0xc
	b _08078F62
	.align 2, 0
_08078F58: .4byte 0xFFFF0000
_08078F5C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08078F62:
	mov r0, sp
	ldrh r1, [r0, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08078FA4 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	mov r6, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08078F9E
	cmp r1, #0
	blt _08078F9E
	ldr r0, _08078FA8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08078F9E
	ldr r0, _08078FAC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08078FB0
_08078F9E:
	movs r4, #0
	b _08078FBE
	.align 2, 0
_08078FA4: .4byte 0xFFFF0000
_08078FA8: .4byte 0x030046A8
_08078FAC: .4byte 0x030046AC
_08078FB0:
	ldr r0, _08078FD0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08078FBE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08078FD4
	adds r0, #4
	b _08078FE0
	.align 2, 0
_08078FD0: .4byte 0x030046A4
_08078FD4:
	ldr r0, _08078FF4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08078FE0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08078FF8
	cmp r2, #2
	beq _08078FFC
	b _08079000
	.align 2, 0
_08078FF4: .4byte 0x030046A4
_08078FF8:
	ldrb r0, [r6, #4]
	b _08078FFE
_08078FFC:
	ldrb r0, [r6]
_08078FFE:
	subs r1, r1, r0
_08079000:
	movs r3, #0x2e
	ldrsh r0, [r5, r3]
	adds r0, #0xc8
	cmp r1, r0
	bhs _0807900C
	b _0807912E
_0807900C:
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08079034
	cmp r1, #0
	blt _08079034
	ldr r0, _08079038 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08079034
	ldr r0, _0807903C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08079040
_08079034:
	movs r4, #0
	b _0807904E
	.align 2, 0
_08079038: .4byte 0x030046A8
_0807903C: .4byte 0x030046AC
_08079040:
	ldr r0, _08079060 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0807904E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08079064
	adds r0, #4
	b _08079070
	.align 2, 0
_08079060: .4byte 0x030046A4
_08079064:
	ldr r0, _0807909C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08079070:
	ldrh r2, [r0, #2]
	movs r0, #4
	ands r2, r0
	cmp r2, #0
	bne _0807912E
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r1, [r0]
	ldr r3, _080790A0 @ =0x000003BD
	adds r0, r5, r3
	strb r1, [r0]
	adds r4, #0xd4
	adds r0, r5, r4
	strb r2, [r0]
	adds r0, r5, #0
	movs r1, #4
	movs r2, #0
	bl FUN_08060b84
	b _0807912E
	.align 2, 0
_0807909C: .4byte 0x030046A4
_080790A0: .4byte 0x000003BD
_080790A4:
	ldr r1, _080790AC @ =0x000003BE
	adds r0, r5, r1
	strh r4, [r0]
	b _0807912E
	.align 2, 0
_080790AC: .4byte 0x000003BE
_080790B0:
	movs r0, #0x80
	lsls r0, r0, #0xb
	orrs r1, r0
	str r1, [r5, #0x20]
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08060c40
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrb r0, [r1]
	subs r0, #0x1c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _080790D6
	ldrb r4, [r1]
	b _080790E4
_080790D6:
	ldr r3, _080790FC @ =0x000003D2
	adds r0, r5, r3
	ldrb r0, [r0]
	movs r4, #0x1a
	cmp r0, #0
	beq _080790E4
	movs r4, #0x1b
_080790E4:
	ldr r0, _08079100 @ =0x085ABCAC
	lsls r1, r4, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_08078bc0
	b _0807912E
	.align 2, 0
_080790FC: .4byte 0x000003D2
_08079100: .4byte 0x085ABCAC
_08079104:
	movs r0, #0x80
	lsls r0, r0, #0xb
	orrs r1, r0
	str r1, [r5, #0x20]
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08060c40
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_08078bc0
	adds r0, r5, #0
	bl FUN_080726ec
_0807912E:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08079138
FUN_08079138: @ 0x08079138
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0x80
	lsls r0, r0, #7
	ldr r1, [r5, #0x20]
	orrs r1, r0
	str r1, [r5, #0x20]
	ldr r0, [r5, #0x1c]
	cmp r0, #2
	bne _08079150
	b _080794AC
_08079150:
	cmp r0, #2
	bhi _0807915A
	cmp r0, #1
	beq _08079162
	b _080794D6
_0807915A:
	cmp r0, #4
	bne _08079160
	b _08079458
_08079160:
	b _080794D6
_08079162:
	adds r0, r5, #0
	bl FUN_0807858c
	ldr r0, [r5, #0x20]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08079186
	ldr r0, _080791D8 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080791DC @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	asrs r1, r1, #1
	adds r0, r5, #0
	bl FUN_080667b0
_08079186:
	adds r0, r5, #0
	bl FUN_0806680c
	cmp r0, #0
	beq _08079196
	adds r0, r5, #0
	bl FUN_0806687c
_08079196:
	adds r0, r5, #0
	bl FUN_080784fc
	adds r0, r5, #0
	bl FUN_080788d0
	adds r4, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08066d7c
	ldr r1, _080791E0 @ =0x085ABD30
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	movs r3, #0xe9
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _080791E4
	movs r4, #0xea
	lsls r4, r4, #2
	adds r0, r5, r4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x34]
	str r1, [r5, #0x38]
	b _080791EA
	.align 2, 0
_080791D8: .4byte 0x030046A0
_080791DC: .4byte 0x00000942
_080791E0: .4byte 0x085ABD30
_080791E4:
	adds r0, r5, #0
	bl FUN_08066408
_080791EA:
	adds r0, r5, #0
	bl FUN_08078bc0
	ldr r1, _080792BC @ =0x000003CE
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _08079202
	adds r0, r5, #0
	bl FUN_08066df8
_08079202:
	adds r0, r5, #0
	bl FUN_08065b7c
	adds r0, r5, #0
	bl FUN_0806623c
	ldr r3, _080792C0 @ =0x00000446
	adds r0, r5, r3
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _08079226
	ldr r4, _080792C4 @ =0x00000442
	adds r0, r5, r4
	ldrh r0, [r0]
	cmp r0, #5
	bne _08079226
	movs r1, #1
_08079226:
	cmp r1, #0
	beq _0807922C
	b _080794D6
_0807922C:
	movs r4, #0
	movs r1, #0xe5
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	bl FUN_08065b44
	cmp r0, #0
	bne _0807926A
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r2, [r0]
	cmp r2, #1
	bne _0807926A
	movs r3, #0xde
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0807926A
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r1, [r0]
	ands r1, r2
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r4, r0, #0x1f
_0807926A:
	cmp r4, #0
	bne _08079270
	b _0807944C
_08079270:
	ldr r0, _080792C8 @ =0x000003BE
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	beq _08079284
	b _080794D6
_08079284:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080792CC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x32
	muls r0, r1, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _080792D0
	asrs r2, r0, #0xc
	b _080792D6
	.align 2, 0
_080792BC: .4byte 0x000003CE
_080792C0: .4byte 0x00000446
_080792C4: .4byte 0x00000442
_080792C8: .4byte 0x000003BE
_080792CC: .4byte 0x085B0A08
_080792D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080792D6:
	mov r0, sp
	ldrh r1, [r0]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08079300 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	lsls r0, r3, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _08079304
	asrs r2, r0, #0xc
	b _0807930A
	.align 2, 0
_08079300: .4byte 0xFFFF0000
_08079304:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0807930A:
	mov r0, sp
	ldrh r1, [r0, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0807934C @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	mov r6, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08079346
	cmp r1, #0
	blt _08079346
	ldr r0, _08079350 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08079346
	ldr r0, _08079354 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08079358
_08079346:
	movs r4, #0
	b _08079366
	.align 2, 0
_0807934C: .4byte 0xFFFF0000
_08079350: .4byte 0x030046A8
_08079354: .4byte 0x030046AC
_08079358:
	ldr r0, _08079378 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08079366:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0807937C
	adds r0, #4
	b _08079388
	.align 2, 0
_08079378: .4byte 0x030046A4
_0807937C:
	ldr r0, _0807939C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08079388:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080793A0
	cmp r2, #2
	beq _080793A4
	b _080793A8
	.align 2, 0
_0807939C: .4byte 0x030046A4
_080793A0:
	ldrb r0, [r6, #4]
	b _080793A6
_080793A4:
	ldrb r0, [r6]
_080793A6:
	subs r1, r1, r0
_080793A8:
	movs r3, #0x2e
	ldrsh r0, [r5, r3]
	adds r0, #0xc8
	cmp r1, r0
	bhs _080793B4
	b _080794D6
_080793B4:
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080793DC
	cmp r1, #0
	blt _080793DC
	ldr r0, _080793E0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080793DC
	ldr r0, _080793E4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080793E8
_080793DC:
	movs r4, #0
	b _080793F6
	.align 2, 0
_080793E0: .4byte 0x030046A8
_080793E4: .4byte 0x030046AC
_080793E8:
	ldr r0, _08079408 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080793F6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0807940C
	adds r0, #4
	b _08079418
	.align 2, 0
_08079408: .4byte 0x030046A4
_0807940C:
	ldr r0, _08079444 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08079418:
	ldrh r2, [r0, #2]
	movs r0, #4
	ands r2, r0
	cmp r2, #0
	bne _080794D6
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r1, [r0]
	ldr r3, _08079448 @ =0x000003BD
	adds r0, r5, r3
	strb r1, [r0]
	adds r4, #0xd4
	adds r0, r5, r4
	strb r2, [r0]
	adds r0, r5, #0
	movs r1, #4
	movs r2, #0
	bl FUN_08060b84
	b _080794D6
	.align 2, 0
_08079444: .4byte 0x030046A4
_08079448: .4byte 0x000003BD
_0807944C:
	ldr r1, _08079454 @ =0x000003BE
	adds r0, r5, r1
	strh r4, [r0]
	b _080794D6
	.align 2, 0
_08079454: .4byte 0x000003BE
_08079458:
	movs r0, #0x80
	lsls r0, r0, #0xb
	orrs r1, r0
	str r1, [r5, #0x20]
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08060c40
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrb r0, [r1]
	subs r0, #0x1c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _0807947E
	ldrb r4, [r1]
	b _0807948C
_0807947E:
	ldr r3, _080794A4 @ =0x000003D2
	adds r0, r5, r3
	ldrb r0, [r0]
	movs r4, #0x1a
	cmp r0, #0
	beq _0807948C
	movs r4, #0x1b
_0807948C:
	ldr r0, _080794A8 @ =0x085ABD30
	lsls r1, r4, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_08078bc0
	b _080794D6
	.align 2, 0
_080794A4: .4byte 0x000003D2
_080794A8: .4byte 0x085ABD30
_080794AC:
	movs r0, #0x80
	lsls r0, r0, #0xb
	orrs r1, r0
	str r1, [r5, #0x20]
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08060c40
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_08078bc0
	adds r0, r5, #0
	bl FUN_080726ec
_080794D6:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080794e0
FUN_080794e0: @ 0x080794E0
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x14
	beq _0807951E
	ldr r2, _08079554 @ =0x000003FF
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0807951E
	adds r1, #0x58
	adds r0, r4, r1
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r1, [r0]
	ldr r2, _08079558 @ =0x000003F6
	adds r0, r4, r2
	strh r1, [r0]
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0
	bl FUN_08060b84
_0807951E:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r2, [r0]
	movs r0, #0xa3
	lsls r0, r0, #2
	adds r5, r4, r0
	ldr r0, [r5]
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08079542
	adds r0, r4, #0
	bl FUN_08064db0
	adds r2, r0, #0
_08079542:
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0807955C
	movs r2, #0x18
	b _080795B2
	.align 2, 0
_08079554: .4byte 0x000003FF
_08079558: .4byte 0x000003F6
_0807955C:
	cmp r2, #0x18
	beq _080795B2
	cmp r2, #0x14
	beq _080795B2
	cmp r2, #0x13
	beq _080795B2
	cmp r2, #0xc
	beq _080795B2
	ldr r0, [r5]
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08079586
	adds r0, r4, #0
	adds r0, #0x24
	bl FUN_08006194
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080795AC
_08079586:
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _080795AC
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080795B0
_080795AC:
	movs r2, #0
	b _080795B2
_080795B0:
	movs r2, #1
_080795B2:
	adds r0, r2, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080795bc
FUN_080795bc: @ 0x080795BC
	push {r4, lr}
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080795E2
	cmp r1, #0
	blt _080795E2
	ldr r0, _080795E8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080795E2
	ldr r0, _080795EC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080795F0
_080795E2:
	movs r4, #0
	b _080795FE
	.align 2, 0
_080795E8: .4byte 0x030046A8
_080795EC: .4byte 0x030046AC
_080795F0:
	ldr r0, _08079610 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080795FE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08079614
	adds r0, #4
	b _08079620
	.align 2, 0
_08079610: .4byte 0x030046A4
_08079614:
	ldr r0, _08079638 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08079620:
	ldrh r1, [r0, #2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	bne _0807963C
	adds r0, r1, #0
	bl FUN_08065ad0
	cmp r0, #0
	bne _0807963C
	movs r0, #0
	b _0807963E
	.align 2, 0
_08079638: .4byte 0x030046A4
_0807963C:
	movs r0, #1
_0807963E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08079644
FUN_08079644: @ 0x08079644
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrh r1, [r5, #0x34]
	ldrh r0, [r5, #0x2c]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r6, _080796A8 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r6
	orrs r0, r1
	str r0, [sp]
	ldrh r0, [r5, #0x38]
	ldrh r1, [r5, #0x30]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r6
	orrs r1, r0
	str r1, [sp, #4]
	movs r1, #0xe4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _08079714
	ldr r1, _080796AC @ =0x00000392
	adds r0, r5, r1
	ldrh r0, [r0]
	bl sub_081D553C
	adds r3, r0, #0
	mov r0, sp
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r0, #0
	ldrsh r1, [r3, r0]
	adds r0, r1, #0
	subs r0, #0x64
	cmp r2, r0
	bgt _080796B0
	ldrh r0, [r3]
	subs r0, #0x64
	b _080796BC
	.align 2, 0
_080796A8: .4byte 0xFFFF0000
_080796AC: .4byte 0x00000392
_080796B0:
	adds r0, r1, #0
	adds r0, #0x64
	cmp r2, r0
	blt _080796C8
	ldrh r0, [r3]
	adds r0, #0x64
_080796BC:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp]
	ands r1, r6
	orrs r1, r0
	str r1, [sp]
_080796C8:
	mov r0, sp
	movs r1, #4
	ldrsh r2, [r0, r1]
	movs r0, #4
	ldrsh r1, [r3, r0]
	adds r0, r1, #0
	subs r0, #0x64
	cmp r2, r0
	bgt _080796E0
	ldrh r0, [r3, #4]
	subs r0, #0x64
	b _080796EC
_080796E0:
	adds r0, r1, #0
	adds r0, #0x64
	cmp r2, r0
	blt _080796FA
	ldrh r0, [r3, #4]
	adds r0, #0x64
_080796EC:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _08079710 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
_080796FA:
	ldrh r1, [r5, #0x2c]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, r0, r1
	strh r0, [r5, #0x34]
	ldrh r1, [r5, #0x30]
	mov r0, sp
	ldrh r0, [r0, #4]
	subs r0, r0, r1
	strh r0, [r5, #0x38]
	b _08079722
	.align 2, 0
_08079710: .4byte 0xFFFF0000
_08079714:
	mov r0, sp
	bl FUN_080795bc
	cmp r0, #0
	beq _08079722
	strh r4, [r5, #0x34]
	strh r4, [r5, #0x38]
_08079722:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0807972c
FUN_0807972c: @ 0x0807972C
	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_08079644
	adds r4, r5, #0
	adds r4, #0x24
	adds r0, r4, #0
	bl FUN_0823b4b8
	adds r0, r4, #0
	bl FUN_080417dc
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bhi _080797C6
	movs r2, #0xe1
	lsls r2, r2, #2
	adds r4, r5, r2
	ldrb r0, [r4]
	cmp r0, #0
	bne _08079790
	ldr r2, _08079784 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	adds r1, #0x83
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08079788 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #0x64
	bl Mod
	subs r0, #0x74
	ldr r2, _0807978C @ =0x00000383
	adds r1, r5, r2
	strb r0, [r1]
	movs r0, #0x10
	b _08079792
	.align 2, 0
_08079784: .4byte 0x030046B8
_08079788: .4byte 0x0203B400
_0807978C: .4byte 0x00000383
_08079790:
	subs r0, #1
_08079792:
	strb r0, [r4]
	ldr r0, _080797AC @ =0x00000382
	adds r3, r5, r0
	ldrb r2, [r3]
	ldr r1, _080797B0 @ =0x00000383
	adds r0, r5, r1
	ldrb r1, [r0]
	subs r0, r1, #4
	cmp r2, r0
	bgt _080797B4
	adds r0, r2, #4
	strb r0, [r3]
	b _080797C6
	.align 2, 0
_080797AC: .4byte 0x00000382
_080797B0: .4byte 0x00000383
_080797B4:
	adds r0, r1, #0
	adds r0, #8
	cmp r2, r0
	blt _080797C4
	adds r0, r2, #0
	subs r0, #8
	strb r0, [r3]
	b _080797C6
_080797C4:
	strb r1, [r3]
_080797C6:
	ldr r2, _080797FC @ =0x00000382
	adds r0, r5, r2
	ldrb r2, [r0]
	ldrh r0, [r5, #0x2e]
	ldr r3, _08079800 @ =0x000003F6
	adds r1, r5, r3
	adds r0, r0, r2
	ldrh r1, [r1]
	adds r0, r0, r1
	movs r2, #0x83
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08060c50
	cmp r0, #0
	beq _08079804
	movs r3, #0xb9
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r0, [r2]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2]
	b _08079822
	.align 2, 0
_080797FC: .4byte 0x00000382
_08079800: .4byte 0x000003F6
_08079804:
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r1, [r2]
	ldr r0, _0807983C @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x2c
	movs r2, #0
	bl FUN_082364c4
_08079822:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08060c50
	cmp r0, #0
	beq _08079840
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _0807984C
	.align 2, 0
_0807983C: .4byte 0x0000FFFB
_08079840:
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_0807984C:
	str r1, [r0]
	adds r0, r5, #0
	movs r1, #0x40
	bl FUN_08060c50
	cmp r0, #0
	beq _08079868
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _08079872
_08079868:
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_08079872:
	str r1, [r0]
	adds r0, r5, #0
	movs r1, #4
	bl FUN_08060c50
	cmp r0, #0
	beq _08079890
	ldr r2, _0807988C @ =0x0000060C
	adds r0, r5, r2
	bl FUN_080136b4
	b _08079898
	.align 2, 0
_0807988C: .4byte 0x0000060C
_08079890:
	ldr r3, _080798A0 @ =0x0000060C
	adds r0, r5, r3
	bl FUN_08013698
_08079898:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080798A0: .4byte 0x0000060C

	thumb_func_start FUN_080798a4
FUN_080798a4: @ 0x080798A4
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r1, [r5, #0x20]
	orrs r1, r0
	str r1, [r5, #0x20]
	ldr r0, [r5, #0x1c]
	cmp r0, #1
	beq _080798BE
	cmp r0, #2
	beq _08079964
	b _08079986
_080798BE:
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _080798D8
	ldr r0, _08079954 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08079958 @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl FUN_080667b0
_080798D8:
	adds r0, r5, #0
	bl FUN_0806680c
	cmp r0, #0
	beq _080798EE
	adds r0, r5, #0
	bl FUN_0806687c
	adds r0, r5, #0
	bl FUN_0806692c
_080798EE:
	adds r0, r5, #0
	bl FUN_080784fc
	adds r0, r5, #0
	bl FUN_080794e0
	adds r4, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08066d7c
	ldr r0, _0807995C @ =0x085ABDB0
	lsls r4, r4, #2
	adds r4, r4, r0
	ldr r1, [r4]
	adds r0, r5, #0
	bl _call_via_r1
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807992C
	movs r2, #0xea
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x34]
	str r1, [r5, #0x38]
_0807992C:
	adds r0, r5, #0
	bl FUN_08066408
	adds r0, r5, #0
	bl FUN_0807972c
	ldr r1, _08079960 @ =0x000003CE
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _0807994A
	adds r0, r5, #0
	bl FUN_08066df8
_0807994A:
	adds r0, r5, #0
	bl FUN_0806623c
	b _08079986
	.align 2, 0
_08079954: .4byte 0x030046A0
_08079958: .4byte 0x00000942
_0807995C: .4byte 0x085ABDB0
_08079960: .4byte 0x000003CE
_08079964:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08060c40
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_0807972c
	adds r0, r5, #0
	bl FUN_080726ec
_08079986:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0807998c
FUN_0807998c: @ 0x0807998C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x14
	beq _080799CC
	ldr r2, _08079A00 @ =0x000003FF
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _080799CC
	movs r3, #0xf5
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r1, [r0]
	adds r3, #0x22
	adds r0, r4, r3
	strh r1, [r0]
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0
	bl FUN_08060b84
_080799CC:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r2, [r0]
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r5, r4, r3
	ldr r0, [r5]
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080799F0
	adds r0, r4, #0
	bl FUN_08064db0
	adds r2, r0, #0
_080799F0:
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08079A04
	movs r2, #0x18
	b _08079A5C
	.align 2, 0
_08079A00: .4byte 0x000003FF
_08079A04:
	cmp r2, #0x18
	beq _08079A5C
	cmp r2, #0x14
	beq _08079A5C
	cmp r2, #0x13
	beq _08079A5C
	cmp r2, #0x17
	beq _08079A5C
	cmp r2, #4
	beq _08079A5C
	cmp r2, #0xd
	beq _08079A5C
	ldr r2, [r5]
	ldrh r1, [r2, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08079A3C
	adds r0, r4, #0
	adds r0, #0x24
	bl FUN_08006194
	lsls r0, r0, #0x18
	movs r2, #4
	cmp r0, #0
	beq _08079A5C
_08079A38:
	movs r2, #0
	b _08079A5C
_08079A3C:
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08079A38
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08079A38
	movs r2, #1
_08079A5C:
	adds r0, r2, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08079a64
FUN_08079a64: @ 0x08079A64
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x24
	adds r0, r4, #0
	bl FUN_0823b4b8
	adds r0, r4, #0
	bl FUN_080417dc
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08060c50
	cmp r0, #0
	beq _08079A94
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	b _08079AB2
_08079A94:
	movs r1, #0xb9
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	ldr r0, _08079ACC @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r1, r5, #0
	adds r1, #0x2c
	movs r2, #0
	bl FUN_082364c4
_08079AB2:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08060c50
	cmp r0, #0
	beq _08079AD0
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _08079ADC
	.align 2, 0
_08079ACC: .4byte 0x0000FFFB
_08079AD0:
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_08079ADC:
	str r1, [r0]
	adds r0, r5, #0
	movs r1, #0x40
	bl FUN_08060c50
	cmp r0, #0
	beq _08079AF8
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _08079B02
_08079AF8:
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_08079B02:
	str r1, [r0]
	adds r0, r5, #0
	movs r1, #4
	bl FUN_08060c50
	cmp r0, #0
	beq _08079B20
	ldr r1, _08079B1C @ =0x0000060C
	adds r0, r5, r1
	bl FUN_080136b4
	b _08079B28
	.align 2, 0
_08079B1C: .4byte 0x0000060C
_08079B20:
	ldr r2, _08079B5C @ =0x0000060C
	adds r0, r5, r2
	bl FUN_08013698
_08079B28:
	movs r1, #0xfe
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	ldrh r2, [r5, #0x2e]
	adds r0, r0, r2
	strh r0, [r5, #0x2e]
	movs r0, #0x82
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	movs r2, #0x83
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r2, _08079B60 @ =0x000003F6
	adds r0, r5, r2
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08079B5C: .4byte 0x0000060C
_08079B60: .4byte 0x000003F6

	thumb_func_start FUN_08079b64
FUN_08079b64: @ 0x08079B64
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xa8
	lsls r0, r0, #0xb
	ldr r1, [r5, #0x20]
	orrs r1, r0
	str r1, [r5, #0x20]
	ldr r0, [r5, #0x1c]
	cmp r0, #1
	beq _08079B7E
	cmp r0, #2
	beq _08079C28
	b _08079C4A
_08079B7E:
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _08079B98
	ldr r0, _08079C18 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08079C1C @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl FUN_080667b0
_08079B98:
	adds r0, r5, #0
	bl FUN_0806680c
	cmp r0, #0
	beq _08079BAE
	adds r0, r5, #0
	bl FUN_0806687c
	adds r0, r5, #0
	bl FUN_0806692c
_08079BAE:
	adds r0, r5, #0
	bl FUN_080784fc
	adds r0, r5, #0
	bl FUN_0807998c
	adds r4, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08066d7c
	ldr r0, _08079C20 @ =0x085ABE1C
	lsls r4, r4, #2
	adds r4, r4, r0
	ldr r1, [r4]
	adds r0, r5, #0
	bl _call_via_r1
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08079BEC
	movs r2, #0xea
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x34]
	str r1, [r5, #0x38]
_08079BEC:
	adds r0, r5, #0
	bl FUN_08079a64
	ldr r1, _08079C24 @ =0x000003CE
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _08079C04
	adds r0, r5, #0
	bl FUN_08066df8
_08079C04:
	adds r0, r5, #0
	bl FUN_08065b7c
	adds r0, r5, #0
	bl FUN_08065dac
	adds r0, r5, #0
	bl FUN_0806623c
	b _08079C4A
	.align 2, 0
_08079C18: .4byte 0x030046A0
_08079C1C: .4byte 0x00000942
_08079C20: .4byte 0x085ABE1C
_08079C24: .4byte 0x000003CE
_08079C28:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08060c40
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_08079a64
	adds r0, r5, #0
	bl FUN_080726ec
_08079C4A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08079c50
FUN_08079c50: @ 0x08079C50
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x14
	beq _08079C8E
	ldr r2, _08079CD0 @ =0x000003FF
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08079C8E
	adds r1, #0x58
	adds r0, r5, r1
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	ldr r2, _08079CD4 @ =0x000003F6
	adds r0, r5, r2
	strh r1, [r0]
	adds r0, r5, #0
	movs r1, #0x14
	movs r2, #0
	bl FUN_08060b84
_08079C8E:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r4, [r0]
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r6, r5, r2
	ldr r0, [r6]
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08079CB2
	adds r0, r5, #0
	bl FUN_08064db0
	adds r4, r0, #0
_08079CB2:
	ldr r1, _08079CD8 @ =0x00000387
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _08079D20
	cmp r4, #1
	bhi _08079D38
	ldr r0, [r6]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08079CDC
	movs r4, #3
	b _08079D38
	.align 2, 0
_08079CD0: .4byte 0x000003FF
_08079CD4: .4byte 0x000003F6
_08079CD8: .4byte 0x00000387
_08079CDC:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08079CF2
	adds r0, r5, #0
	adds r0, #0x24
	bl FUN_08006194
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08079D18
_08079CF2:
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08079D18
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08079D1C
_08079D18:
	movs r4, #0
	b _08079D38
_08079D1C:
	movs r4, #1
	b _08079D38
_08079D20:
	cmp r4, #0
	bne _08079D38
	ldr r0, [r6]
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08079D38
	adds r0, r5, #0
	adds r0, #0x24
	bl FUN_08006194
_08079D38:
	adds r0, r4, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08079d40
FUN_08079d40: @ 0x08079D40
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x24
	adds r0, r4, #0
	bl FUN_0823b4b8
	adds r0, r4, #0
	bl FUN_080417dc
	movs r0, #0x82
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r2, _08079DA4 @ =0x000004BC
	adds r0, r5, r2
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0x83
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r2, _08079DA8 @ =0x000003F6
	adds r0, r5, r2
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0x84
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r2, #0x98
	lsls r2, r2, #3
	adds r0, r5, r2
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08060c50
	cmp r0, #0
	beq _08079DAC
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _08079DB8
	.align 2, 0
_08079DA4: .4byte 0x000004BC
_08079DA8: .4byte 0x000003F6
_08079DAC:
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_08079DB8:
	str r1, [r0]
	adds r0, r5, #0
	movs r1, #0x40
	bl FUN_08060c50
	cmp r0, #0
	beq _08079DD4
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _08079DDE
_08079DD4:
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_08079DDE:
	str r1, [r0]
	adds r0, r5, #0
	movs r1, #4
	bl FUN_08060c50
	cmp r0, #0
	beq _08079DFC
	ldr r1, _08079DF8 @ =0x0000060C
	adds r0, r5, r1
	bl FUN_080136b4
	b _08079E04
	.align 2, 0
_08079DF8: .4byte 0x0000060C
_08079DFC:
	ldr r2, _08079E20 @ =0x0000060C
	adds r0, r5, r2
	bl FUN_08013698
_08079E04:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08060c50
	cmp r0, #0
	beq _08079E24
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	b _08079E42
	.align 2, 0
_08079E20: .4byte 0x0000060C
_08079E24:
	movs r1, #0xb9
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	ldr r0, _08079E48 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r1, r5, #0
	adds r1, #0x2c
	movs r2, #0
	bl FUN_082364c4
_08079E42:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08079E48: .4byte 0x0000FFFB

	thumb_func_start FUN_08079e4c
FUN_08079e4c: @ 0x08079E4C
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x88
	lsls r1, r1, #0xb
	ldr r0, [r5, #0x20]
	orrs r0, r1
	str r0, [r5, #0x20]
	ldr r1, _08079E84 @ =0x000004BC
	adds r0, r5, r1
	movs r1, #0
	strh r1, [r0]
	movs r2, #0x98
	lsls r2, r2, #3
	adds r0, r5, r2
	strh r1, [r0]
	ldr r0, _08079E88 @ =0x0000038A
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08079E78
	subs r0, #1
	strh r0, [r1]
_08079E78:
	ldr r0, [r5, #0x1c]
	cmp r0, #1
	beq _08079E8C
	cmp r0, #2
	beq _08079EF8
	b _08079F14
	.align 2, 0
_08079E84: .4byte 0x000004BC
_08079E88: .4byte 0x0000038A
_08079E8C:
	adds r0, r5, #0
	bl FUN_080784fc
	adds r0, r5, #0
	bl FUN_08079c50
	adds r4, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08066d7c
	ldr r0, _08079EF0 @ =0x085ABE88
	lsls r4, r4, #2
	adds r4, r4, r0
	ldr r1, [r4]
	adds r0, r5, #0
	bl _call_via_r1
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08079ECA
	movs r2, #0xea
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x34]
	str r1, [r5, #0x38]
_08079ECA:
	adds r0, r5, #0
	bl FUN_08079d40
	ldr r1, _08079EF4 @ =0x000003CE
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _08079EE2
	adds r0, r5, #0
	bl FUN_08066df8
_08079EE2:
	adds r0, r5, #0
	bl FUN_08065b7c
	adds r0, r5, #0
	bl FUN_0806623c
	b _08079F14
	.align 2, 0
_08079EF0: .4byte 0x085ABE88
_08079EF4: .4byte 0x000003CE
_08079EF8:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08060c40
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_08079d40
_08079F14:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08079F1C:
	.byte 0x70, 0xB5, 0x82, 0xB0
	.byte 0x05, 0x1C, 0x80, 0x21, 0xC9, 0x01, 0x28, 0x6A, 0x08, 0x43, 0x28, 0x62, 0xE8, 0x69, 0x02, 0x28
	.byte 0x00, 0xD1, 0x8B, 0xE1, 0x02, 0x28, 0x02, 0xD8, 0x01, 0x28, 0x04, 0xD0, 0x94, 0xE1, 0x04, 0x28
	.byte 0x00, 0xD1, 0x5D, 0xE1, 0x90, 0xE1, 0x28, 0x1C, 0xFE, 0xF7, 0xD8, 0xFA, 0x28, 0x1C, 0xFE, 0xF7
	.byte 0xBF, 0xFC, 0x04, 0x1C, 0x28, 0x1C, 0x21, 0x1C, 0xEC, 0xF7, 0x10, 0xFF, 0x0A, 0x49, 0xA0, 0x00
	.byte 0x40, 0x18, 0x01, 0x68, 0x28, 0x1C, 0xD2, 0xF1, 0x7D, 0xFF, 0xE9, 0x21, 0x89, 0x00, 0x68, 0x18
	.byte 0x00, 0x78, 0x00, 0x28, 0x0A, 0xD0, 0xEA, 0x22, 0x92, 0x00, 0xA8, 0x18, 0x41, 0x68, 0x00, 0x68
	.byte 0x68, 0x63, 0xA9, 0x63, 0x05, 0xE0, 0x00, 0x00, 0xDC, 0xBE, 0x5A, 0x08, 0x28, 0x1C, 0xEC, 0xF7
	.byte 0x3B, 0xFA, 0x28, 0x1C, 0xFE, 0xF7, 0x14, 0xFE, 0x32, 0x4B, 0xE8, 0x18, 0x00, 0x24, 0x00, 0x5F
	.byte 0x00, 0x28, 0x02, 0xD0, 0x28, 0x1C, 0xEC, 0xF7, 0x27, 0xFF, 0x28, 0x1C, 0xEB, 0xF7, 0xE6, 0xFD
	.byte 0x28, 0x1C, 0xEC, 0xF7, 0x43, 0xF9, 0x2C, 0x49, 0x68, 0x18, 0x00, 0x88, 0x00, 0x21, 0x00, 0x28
	.byte 0x05, 0xD0, 0x2A, 0x4A, 0xA8, 0x18, 0x00, 0x88, 0x05, 0x28, 0x00, 0xD1, 0x01, 0x21, 0x00, 0x29
	.byte 0x00, 0xD0, 0x49, 0xE1, 0x00, 0x24, 0xE5, 0x23, 0x5B, 0x00, 0xE8, 0x18, 0x00, 0x88, 0xEB, 0xF7
	.byte 0xB1, 0xFD, 0x00, 0x28, 0x15, 0xD1, 0xDF, 0x21, 0x89, 0x00, 0x68, 0x18, 0x02, 0x78, 0x01, 0x2A
	.byte 0x0F, 0xD1, 0xDE, 0x23, 0x5B, 0x00, 0xE8, 0x18, 0x01, 0x78, 0x10, 0x1C, 0x08, 0x40, 0x00, 0x28
	.byte 0x07, 0xD0, 0xBA, 0x24, 0xA4, 0x00, 0x28, 0x19, 0x01, 0x78, 0x11, 0x40, 0x48, 0x42, 0x08, 0x43
	.byte 0xC4, 0x0F, 0x00, 0x2C, 0x00, 0xD1, 0xED, 0xE0, 0x15, 0x48, 0x29, 0x18, 0x08, 0x88, 0x01, 0x30
	.byte 0x08, 0x80, 0x00, 0x04, 0x00, 0x0C, 0x05, 0x28, 0x00, 0xD0, 0x1D, 0xE1, 0xE8, 0x6A, 0x29, 0x6B
	.byte 0x00, 0x90, 0x01, 0x91, 0xBA, 0x21, 0x89, 0x00, 0x68, 0x18, 0x00, 0x78, 0x05, 0x30, 0x07, 0x21
	.byte 0x08, 0x40, 0x43, 0x01, 0x0B, 0x4A, 0x18, 0x1C, 0x40, 0x30, 0xFF, 0x21, 0x08, 0x40, 0x40, 0x00
	.byte 0x80, 0x18, 0x00, 0x24, 0x01, 0x5F, 0x32, 0x20, 0x48, 0x43, 0x14, 0x1C, 0x00, 0x28, 0x0B, 0xDB
	.byte 0x02, 0x13, 0x0C, 0xE0, 0xCE, 0x03, 0x00, 0x00, 0x46, 0x04, 0x00, 0x00, 0x42, 0x04, 0x00, 0x00
	.byte 0xBE, 0x03, 0x00, 0x00, 0x08, 0x0A, 0x5B, 0x08, 0x40, 0x42, 0x00, 0x13, 0x42, 0x42, 0x68, 0x46
	.byte 0x01, 0x88, 0x89, 0x18, 0x09, 0x04, 0x09, 0x0C, 0x07, 0x4A, 0x00, 0x98, 0x10, 0x40, 0x08, 0x43
	.byte 0x00, 0x90, 0x58, 0x00, 0x00, 0x19, 0x00, 0x22, 0x81, 0x5E, 0x32, 0x20, 0x48, 0x43, 0x00, 0x28
	.byte 0x04, 0xDB, 0x02, 0x13, 0x05, 0xE0, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x40, 0x42, 0x00, 0x13
	.byte 0x42, 0x42, 0x68, 0x46, 0x81, 0x88, 0x89, 0x18, 0x09, 0x04, 0x09, 0x0C, 0x0D, 0x4A, 0x01, 0x98
	.byte 0x10, 0x40, 0x08, 0x43, 0x01, 0x90, 0x6E, 0x46, 0x68, 0x46, 0x00, 0x88, 0x00, 0x04, 0x02, 0x16
	.byte 0xB0, 0x88, 0x00, 0x04, 0x01, 0x16, 0x00, 0x2A, 0x09, 0xDB, 0x00, 0x29, 0x07, 0xDB, 0x06, 0x48
	.byte 0x00, 0x68, 0x82, 0x42, 0x03, 0xD2, 0x05, 0x48, 0x00, 0x68, 0x81, 0x42, 0x08, 0xD3, 0x00, 0x24
	.byte 0x0D, 0xE0, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xA8, 0x46, 0x00, 0x03, 0xAC, 0x46, 0x00, 0x03
	.byte 0x07, 0x48, 0x00, 0x68, 0x49, 0x00, 0x24, 0x30, 0x40, 0x18, 0x00, 0x88, 0x84, 0x18, 0x20, 0x1C
	.byte 0x01, 0x21, 0xBA, 0xF1, 0x87, 0xF8, 0x00, 0x28, 0x04, 0xD0, 0x04, 0x30, 0x08, 0xE0, 0x00, 0x00
	.byte 0xA4, 0x46, 0x00, 0x03, 0x07, 0x48, 0x01, 0x68, 0xA0, 0x00, 0x0C, 0x30, 0x49, 0x68, 0x08, 0x18
	.byte 0x01, 0x78, 0x0A, 0x09, 0x0F, 0x20, 0x08, 0x40, 0x01, 0x02, 0x01, 0x2A, 0x04, 0xD0, 0x02, 0x2A
	.byte 0x04, 0xD0, 0x05, 0xE0, 0xA4, 0x46, 0x00, 0x03, 0x30, 0x79, 0x00, 0xE0, 0x30, 0x78, 0x09, 0x1A
	.byte 0x2E, 0x23, 0xE8, 0x5E, 0xC8, 0x30, 0x81, 0x42, 0x00, 0xD2, 0x85, 0xE0, 0x69, 0x46, 0x68, 0x46
	.byte 0x00, 0x88, 0x00, 0x04, 0x02, 0x16, 0x88, 0x88, 0x00, 0x04, 0x01, 0x16, 0x00, 0x2A, 0x09, 0xDB
	.byte 0x00, 0x29, 0x07, 0xDB, 0x04, 0x48, 0x00, 0x68, 0x82, 0x42, 0x03, 0xD2, 0x03, 0x48, 0x00, 0x68
	.byte 0x81, 0x42, 0x05, 0xD3, 0x00, 0x24, 0x0A, 0xE0, 0xA8, 0x46, 0x00, 0x03, 0xAC, 0x46, 0x00, 0x03
	.byte 0x07, 0x48, 0x00, 0x68, 0x49, 0x00, 0x24, 0x30, 0x40, 0x18, 0x00, 0x88, 0x84, 0x18, 0x20, 0x1C
	.byte 0x01, 0x21, 0xBA, 0xF1, 0x3F, 0xF8, 0x00, 0x28, 0x04, 0xD0, 0x04, 0x30, 0x08, 0xE0, 0x00, 0x00
	.byte 0xA4, 0x46, 0x00, 0x03, 0x0D, 0x48, 0x01, 0x68, 0xA0, 0x00, 0x0C, 0x30, 0x49, 0x68, 0x08, 0x18
	.byte 0x42, 0x88, 0x04, 0x20, 0x02, 0x40, 0x00, 0x2A, 0x4E, 0xD1, 0xBA, 0x24, 0xA4, 0x00, 0x28, 0x19
	.byte 0x01, 0x78, 0x07, 0x4B, 0xE8, 0x18, 0x01, 0x70, 0xD4, 0x34, 0x28, 0x19, 0x02, 0x70, 0x28, 0x1C
	.byte 0x04, 0x21, 0x00, 0x22, 0xE6, 0xF7, 0xCE, 0xFC, 0x3E, 0xE0, 0x00, 0x00, 0xA4, 0x46, 0x00, 0x03
	.byte 0xBD, 0x03, 0x00, 0x00, 0x01, 0x49, 0x68, 0x18, 0x04, 0x80, 0x35, 0xE0, 0xBE, 0x03, 0x00, 0x00
	.byte 0x28, 0x1C, 0x08, 0x21, 0xE6, 0xF7, 0x1C, 0xFD, 0xDF, 0x22, 0x92, 0x00, 0xA9, 0x18, 0x08, 0x78
	.byte 0x1C, 0x38, 0x00, 0x06, 0x00, 0x0E, 0x02, 0x28, 0x01, 0xD8, 0x0C, 0x78, 0x06, 0xE0, 0x09, 0x4B
	.byte 0xE8, 0x18, 0x00, 0x78, 0x1A, 0x24, 0x00, 0x28, 0x00, 0xD0, 0x1B, 0x24, 0x06, 0x48, 0xA1, 0x00
	.byte 0x09, 0x18, 0x09, 0x68, 0x28, 0x1C, 0xD2, 0xF1, 0x15, 0xFE, 0x28, 0x1C, 0xFE, 0xF7, 0xC0, 0xFC
	.byte 0x12, 0xE0, 0x00, 0x00, 0xD2, 0x03, 0x00, 0x00, 0xDC, 0xBE, 0x5A, 0x08, 0x28, 0x1C, 0x08, 0x21
	.byte 0xE6, 0xF7, 0xF6, 0xFC, 0x93, 0x24, 0xE4, 0x00, 0x28, 0x19, 0x01, 0x68, 0x28, 0x1C, 0xD2, 0xF1
	.byte 0x01, 0xFE, 0x28, 0x1C, 0xFE, 0xF7, 0xAC, 0xFC, 0x02, 0xB0, 0x70, 0xBC, 0x01, 0xBC, 0x00, 0x47

	thumb_func_start FUN_0807a270
FUN_0807a270: @ 0x0807A270
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r1, _0807A2F4 @ =0x03002B98
	movs r0, #0
	strh r0, [r1]
	ldr r5, _0807A2F8 @ =0x03002B60
	ldr r6, _0807A2FC @ =0x03002B7C
	ldr r7, _0807A300 @ =0x03002B8C
	ldr r0, _0807A304 @ =0x03002BF0
	mov ip, r0
	ldr r1, _0807A308 @ =0x03002BD0
	mov r8, r1
	ldr r0, _0807A30C @ =0x03002B80
	mov sb, r0
	ldr r1, _0807A310 @ =0x03002B78
	mov sl, r1
	movs r2, #0
	ldr r4, _0807A314 @ =0x03002BC0
	ldr r1, _0807A318 @ =0x03002B68
	ldr r3, _0807A31C @ =0x03002BE0
	movs r0, #3
_0807A2A0:
	stm r3!, {r2}
	strh r2, [r1]
	stm r4!, {r2}
	adds r1, #2
	subs r0, #1
	cmp r0, #0
	bge _0807A2A0
	movs r0, #0
	strh r0, [r5]
	strh r0, [r6]
	strh r0, [r7]
	mov r1, ip
	strh r0, [r1]
	mov r1, r8
	strh r0, [r1]
	mov r1, sb
	strh r0, [r1]
	mov r1, sl
	strh r0, [r1]
	ldr r1, _0807A320 @ =0x03002BA0
	movs r2, #0
	adds r0, r1, #4
_0807A2CC:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _0807A2CC
	movs r0, #0
	ldr r1, _0807A324 @ =0x03002B84
	strh r0, [r1]
	ldr r1, _0807A328 @ =0x03002BAC
	strh r0, [r1]
	ldr r1, _0807A32C @ =0x03002B90
	strh r0, [r1]
	ldr r1, _0807A330 @ =0x03002BB0
	strh r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807A2F4: .4byte 0x03002B98
_0807A2F8: .4byte 0x03002B60
_0807A2FC: .4byte 0x03002B7C
_0807A300: .4byte 0x03002B8C
_0807A304: .4byte 0x03002BF0
_0807A308: .4byte 0x03002BD0
_0807A30C: .4byte 0x03002B80
_0807A310: .4byte 0x03002B78
_0807A314: .4byte 0x03002BC0
_0807A318: .4byte 0x03002B68
_0807A31C: .4byte 0x03002BE0
_0807A320: .4byte 0x03002BA0
_0807A324: .4byte 0x03002B84
_0807A328: .4byte 0x03002BAC
_0807A32C: .4byte 0x03002B90
_0807A330: .4byte 0x03002BB0

	thumb_func_start FUN_0807a334
FUN_0807a334: @ 0x0807A334
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne _0807A354
	movs r2, #0xe0
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r1, #1
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
_0807A354:
	adds r0, r4, #0
	movs r1, #0x17
	movs r2, #0
	bl FUN_08060b84
	ldr r0, _0807A394 @ =0x000003F6
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	adds r6, r4, #0
	adds r6, #0x2c
	ldrh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0807A38E
	cmp r1, #0
	blt _0807A38E
	ldr r0, _0807A398 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0807A38E
	ldr r0, _0807A39C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0807A3A0
_0807A38E:
	movs r5, #0
	b _0807A3AE
	.align 2, 0
_0807A394: .4byte 0x000003F6
_0807A398: .4byte 0x030046A8
_0807A39C: .4byte 0x030046AC
_0807A3A0:
	ldr r0, _0807A3C0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0807A3AE:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0807A3C4
	adds r0, #4
	b _0807A3D0
	.align 2, 0
_0807A3C0: .4byte 0x030046A4
_0807A3C4:
	ldr r0, _0807A3E4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0807A3D0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0807A3E8
	cmp r2, #2
	beq _0807A3EC
	b _0807A3F0
	.align 2, 0
_0807A3E4: .4byte 0x030046A4
_0807A3E8:
	ldrb r0, [r6, #4]
	b _0807A3EE
_0807A3EC:
	ldrb r0, [r6]
_0807A3EE:
	subs r1, r1, r0
_0807A3F0:
	ldrh r0, [r4, #0x2e]
	subs r0, r0, r1
	movs r2, #0xfe
	lsls r2, r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r1, [r0]
	cmp r1, #4
	bls _0807A424
	movs r0, #8
	subs r0, r0, r1
	ldr r2, _0807A41C @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _0807A420 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	b _0807A430
	.align 2, 0
_0807A41C: .4byte 0x000002E6
_0807A420: .4byte 0x000002E7
_0807A424:
	ldr r2, _0807A444 @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _0807A448 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
_0807A430:
	strb r0, [r1]
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r0, #0
	strh r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807A444: .4byte 0x000002E6
_0807A448: .4byte 0x000002E7

	thumb_func_start FUN_0807a44c
FUN_0807a44c: @ 0x0807A44C
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r1, #4
	movs r2, #1
	bl FUN_08060b84
	ldr r0, _0807A490 @ =0x000003BD
	adds r2, r5, r0
	strb r4, [r2]
	adds r4, #4
	movs r0, #7
	ands r4, r0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r4, [r0]
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0807A49C
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _0807A494 @ =0x000002E6
	adds r1, r5, r2
	strb r0, [r1]
	ldr r0, _0807A498 @ =0x000002E7
	adds r1, r5, r0
	movs r0, #1
	b _0807A4AA
	.align 2, 0
_0807A490: .4byte 0x000003BD
_0807A494: .4byte 0x000002E6
_0807A498: .4byte 0x000002E7
_0807A49C:
	lsrs r1, r1, #0x19
	ldr r2, _0807A4BC @ =0x000002E6
	adds r0, r5, r2
	strb r1, [r0]
	ldr r0, _0807A4C0 @ =0x000002E7
	adds r1, r5, r0
	movs r0, #0
_0807A4AA:
	strb r0, [r1]
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #0
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807A4BC: .4byte 0x000002E6
_0807A4C0: .4byte 0x000002E7

	thumb_func_start FUN_0807a4c4
FUN_0807a4c4: @ 0x0807A4C4
	push {lr}
	ldr r1, _0807A4D8 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, [r1, #0x3c]
	cmp r0, #0
	beq _0807A4DC
	ldrh r0, [r0, #6]
	b _0807A51A
	.align 2, 0
_0807A4D8: .4byte 0x03002BE0
_0807A4DC:
	ldrh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0807A500
	cmp r1, #0
	blt _0807A500
	ldr r0, _0807A504 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0807A500
	ldr r0, _0807A508 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0807A50C
_0807A500:
	movs r0, #0
	b _0807A51A
	.align 2, 0
_0807A504: .4byte 0x030046A8
_0807A508: .4byte 0x030046AC
_0807A50C:
	ldr r0, _0807A520 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_0807A51A:
	pop {r1}
	bx r1
	.align 2, 0
_0807A520: .4byte 0x030046A4

	thumb_func_start FUN_0807a524
FUN_0807a524: @ 0x0807A524
	bx lr
	.align 2, 0

	thumb_func_start FUN_0807a528
FUN_0807a528: @ 0x0807A528
	push {r4, r5, r6, lr}
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r4, r0, r3
	movs r5, #0
	movs r3, #8
	strb r3, [r4]
	ldr r4, _0807A564 @ =0x0000037E
	adds r3, r0, r4
	movs r4, #0
	strh r5, [r3]
	ldr r6, _0807A568 @ =0x0000037D
	adds r3, r0, r6
	strb r4, [r3]
	ldr r4, _0807A56C @ =0x000003F6
	adds r3, r0, r4
	strh r5, [r3]
	adds r6, #0x33
	adds r5, r0, r6
	ldr r3, [r1]
	ldr r4, [r1, #4]
	str r3, [r5]
	str r4, [r5, #4]
	movs r1, #0xee
	lsls r1, r1, #2
	adds r0, r0, r1
	strh r2, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807A564: .4byte 0x0000037E
_0807A568: .4byte 0x0000037D
_0807A56C: .4byte 0x000003F6

	thumb_func_start FUN_0807a570
FUN_0807a570: @ 0x0807A570
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r2, r1, #0
	ldr r0, _0807A598 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0807A59C
	adds r0, r4, #0
	bl FUN_080d040c
	adds r0, r4, #0
	movs r1, #0x1c
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0
	b _0807A5D0
	.align 2, 0
_0807A598: .4byte 0x030047A4
_0807A59C:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #6
	bne _0807A5BC
	movs r5, #1
	subs r1, #0x94
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_0807bdc8
	b _0807A5CE
_0807A5BC:
	movs r5, #0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0807bdc8
_0807A5CE:
	adds r0, r5, #0
_0807A5D0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0807a5d8
FUN_0807a5d8: @ 0x0807A5D8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r2, r1, #0
	ldr r1, _0807A604 @ =0x030046A0
	ldr r3, [r1]
	movs r4, #0x94
	lsls r4, r4, #2
	adds r0, r3, r4
	movs r4, #0
	ldrsh r5, [r0, r4]
	mov r8, r1
	cmp r5, #5
	bne _0807A610
	ldr r0, _0807A608 @ =0x08DA9E68
	ldr r1, _0807A60C @ =0x00000874
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r0, #0xa
	lsls r0, r0, #1
	b _0807A6C0
	.align 2, 0
_0807A604: .4byte 0x030046A0
_0807A608: .4byte 0x08DA9E68
_0807A60C: .4byte 0x00000874
_0807A610:
	ldrb r0, [r6, #1]
	adds r7, r0, #0
	cmp r7, #4
	bne _0807A646
	movs r0, #4
	bl FUN_0807a8c0
	cmp r0, #0x62
	ble _0807A62A
	ldrb r0, [r6, #4]
	adds r0, #0xa
	lsls r0, r0, #1
	b _0807A6C0
_0807A62A:
	movs r0, #4
	bl FUN_0807a8c0
	movs r1, #0xa
	bl Div
	adds r1, r0, #0
	subs r1, #8
	lsls r0, r1, #2
	adds r0, r0, r1
	ldrb r6, [r6, #4]
	adds r0, r0, r6
	lsls r0, r0, #1
	b _0807A6C0
_0807A646:
	movs r4, #0x1c
	ldrsh r1, [r3, r4]
	movs r4, #0x24
	ldrsh r0, [r3, r4]
	adds r4, r1, r0
	cmp r2, #0
	beq _0807A67E
	ldrb r0, [r2, #3]
	cmp r0, #2
	beq _0807A670
	cmp r0, #2
	bgt _0807A664
	cmp r0, #1
	beq _0807A66A
	b _0807A67E
_0807A664:
	cmp r0, #3
	beq _0807A67A
	b _0807A67E
_0807A66A:
	cmp r5, #0
	beq _0807A67A
	b _0807A674
_0807A670:
	cmp r5, #0
	bne _0807A67A
_0807A674:
	ldrb r0, [r2, #4]
	subs r4, r4, r0
	b _0807A67E
_0807A67A:
	ldrb r0, [r2, #4]
	adds r4, r4, r0
_0807A67E:
	cmp r4, #0x63
	ble _0807A684
	movs r4, #0x63
_0807A684:
	mov r1, r8
	ldr r0, [r1]
	adds r0, #0x40
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r0, r4, r0
	asrs r4, r0, #1
	lsls r0, r7, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _0807A6B0
	movs r0, #3
	bl FUN_0807a8c0
	mov r2, r8
	ldr r1, [r2]
	adds r1, #0x40
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	asrs r0, r0, #2
	b _0807A6BE
_0807A6B0:
	movs r1, #8
	ldrsh r0, [r6, r1]
	ldrb r6, [r6, #4]
	adds r0, r0, r6
	cmp r0, #0
	bge _0807A6BE
	movs r0, #0
_0807A6BE:
	adds r0, r4, r0
_0807A6C0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0807a6cc
FUN_0807a6cc: @ 0x0807A6CC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0807A6F4 @ =0x030046A0
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x5c
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	blt _0807A6FC
	bl GetInventoryArmor
	adds r1, r0, #0
	lsls r1, r1, #3
	ldr r0, _0807A6F8 @ =0x08DAA7B0
	adds r1, r1, r0
	adds r0, r4, #0
	bl FUN_0807a5d8
	b _0807A704
	.align 2, 0
_0807A6F4: .4byte 0x030046A0
_0807A6F8: .4byte 0x08DAA7B0
_0807A6FC:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0807a5d8
_0807A704:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0807a70c
FUN_0807a70c: @ 0x0807A70C
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	ldr r1, _0807A72C @ =0x030046A0
	ldr r2, [r1]
	movs r4, #0x94
	lsls r4, r4, #2
	adds r0, r2, r4
	movs r5, #0
	ldrsh r4, [r0, r5]
	adds r5, r1, #0
	cmp r4, #5
	bne _0807A734
	ldr r0, _0807A730 @ =0x03002B74
	ldrh r0, [r0]
	b _0807A790
	.align 2, 0
_0807A72C: .4byte 0x030046A0
_0807A730: .4byte 0x03002B74
_0807A734:
	movs r6, #0x1e
	ldrsh r1, [r2, r6]
	movs r6, #0x26
	ldrsh r0, [r2, r6]
	adds r1, r1, r0
	cmp r3, #0
	bne _0807A750
	adds r0, r2, #0
	adds r0, #0x40
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r0, r1, r0
	asrs r0, r0, #1
	b _0807A790
_0807A750:
	ldrb r0, [r3, #3]
	cmp r0, #2
	beq _0807A76C
	cmp r0, #2
	bgt _0807A760
	cmp r0, #1
	beq _0807A766
	b _0807A77A
_0807A760:
	cmp r0, #0x1a
	beq _0807A776
	b _0807A77A
_0807A766:
	cmp r4, #0
	beq _0807A776
	b _0807A770
_0807A76C:
	cmp r4, #0
	bne _0807A776
_0807A770:
	ldrb r0, [r3, #4]
	subs r1, r1, r0
	b _0807A77A
_0807A776:
	ldrb r0, [r3, #4]
	adds r1, r1, r0
_0807A77A:
	cmp r1, #0x63
	ble _0807A780
	movs r1, #0x63
_0807A780:
	ldr r0, [r5]
	adds r0, #0x40
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r0, r1, r0
	asrs r0, r0, #1
	ldrb r3, [r3, #1]
	adds r0, r0, r3
_0807A790:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0807a798
FUN_0807a798: @ 0x0807A798
	push {r4, lr}
	adds r2, r0, #0
	ldr r0, _0807A7EC @ =0x030046A0
	ldr r1, [r0]
	movs r3, #0x94
	lsls r3, r3, #2
	adds r1, r1, r3
	movs r4, #0
	ldrsh r1, [r1, r4]
	adds r3, r0, #0
	cmp r1, #5
	beq _0807A7E4
	ldr r0, _0807A7F0 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _0807A7D0
	movs r1, #0x80
	lsls r1, r1, #4
	movs r4, #0xde
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0807A7D0
	lsls r0, r2, #1
	adds r0, r0, r2
	asrs r2, r0, #1
_0807A7D0:
	ldr r0, [r3]
	ldr r1, [r0, #0x50]
	adds r1, r1, r2
	str r1, [r0, #0x50]
	ldr r0, _0807A7F4 @ =0x000F423E
	cmp r1, r0
	ble _0807A7E4
	ldr r1, [r3]
	adds r0, #1
	str r0, [r1, #0x50]
_0807A7E4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807A7EC: .4byte 0x030046A0
_0807A7F0: .4byte 0x03002BE0
_0807A7F4: .4byte 0x000F423E

	thumb_func_start FUN_0807a7f8
FUN_0807a7f8: @ 0x0807A7F8
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _0807A834 @ =0x030046A0
	ldr r2, [r0]
	movs r4, #0x94
	lsls r4, r4, #2
	adds r0, r2, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #5
	beq _0807A82E
	cmp r3, #4
	bgt _0807A82E
	lsls r0, r3, #1
	adds r0, r0, r2
	adds r2, r0, #0
	adds r2, #0x46
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	lsls r0, r0, #0x10
	ldr r1, _0807A838 @ =0x26AB0000
	cmp r0, r1
	ble _0807A82E
	ldr r1, _0807A83C @ =0x000026AC
	adds r0, r1, #0
	strh r0, [r2]
_0807A82E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807A834: .4byte 0x030046A0
_0807A838: .4byte 0x26AB0000
_0807A83C: .4byte 0x000026AC

	thumb_func_start FUN_0807a840
FUN_0807a840: @ 0x0807A840
	push {lr}
	adds r2, r0, #0
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0807A854
	movs r0, #0
	bl FUN_0807a7f8
	b _0807A898
_0807A854:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0807A864
	movs r0, #1
	bl FUN_0807a7f8
	b _0807A898
_0807A864:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0807A874
	movs r0, #2
	bl FUN_0807a7f8
	b _0807A898
_0807A874:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0807A884
	movs r0, #3
	bl FUN_0807a7f8
	b _0807A892
_0807A884:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0807A892
	movs r0, #4
	bl FUN_0807a7f8
_0807A892:
	movs r0, #0
	cmp r0, #0
	beq _0807A8A4
_0807A898:
	ldr r0, _0807A8A8 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _0807A8A4
	bl FUN_08064058
_0807A8A4:
	pop {r0}
	bx r0
	.align 2, 0
_0807A8A8: .4byte 0x03002BE0

	thumb_func_start FUN_0807a8ac
FUN_0807a8ac: @ 0x0807A8AC
	ldr r1, _0807A8BC @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0x46
	movs r1, #0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_0807A8BC: .4byte 0x030046A0

	thumb_func_start FUN_0807a8c0
FUN_0807a8c0: @ 0x0807A8C0
	push {lr}
	ldr r1, _0807A8DC @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0x46
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0x64
	bl Div
	pop {r1}
	bx r1
	.align 2, 0
_0807A8DC: .4byte 0x030046A0

	thumb_func_start FUN_0807a8e0
FUN_0807a8e0: @ 0x0807A8E0
	ldr r1, _0807A8FC @ =0x0000038E
	adds r0, r0, r1
	ldrb r0, [r0]
	ldr r1, _0807A900 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
	bx lr
	.align 2, 0
_0807A8FC: .4byte 0x0000038E
_0807A900: .4byte 0x030046A0

	thumb_func_start FUN_0807a904
FUN_0807a904: @ 0x0807A904
	push {lr}
	cmp r1, #0
	bne _0807A914
	ldr r2, _0807A918 @ =0x00000402
	adds r1, r0, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0807A914:
	pop {r0}
	bx r0
	.align 2, 0
_0807A918: .4byte 0x00000402

	thumb_func_start FUN_0807a91c
FUN_0807a91c: @ 0x0807A91C
	push {r4, r5, lr}
	ldr r2, [r1]
	ldr r3, [r1, #4]
	str r2, [r0, #0x2c]
	str r3, [r0, #0x30]
	movs r5, #0x82
	lsls r5, r5, #1
	adds r4, r0, r5
	str r2, [r4]
	str r3, [r4, #4]
	adds r0, #0xa8
	str r2, [r0]
	str r3, [r0, #4]
	ldr r2, _0807A950 @ =0x030046A0
	ldr r3, [r2]
	ldrh r0, [r1]
	strh r0, [r3, #0x30]
	ldr r3, [r2]
	ldrh r0, [r1, #2]
	strh r0, [r3, #0x32]
	ldr r2, [r2]
	ldrh r0, [r1, #4]
	strh r0, [r2, #0x34]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807A950: .4byte 0x030046A0

	thumb_func_start FUN_0807a954
FUN_0807a954: @ 0x0807A954
	push {lr}
	movs r2, #0xe4
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0807A968
	movs r0, #0
	b _0807A96A
_0807A968:
	movs r0, #1
_0807A96A:
	pop {r1}
	bx r1
	.align 2, 0
_0807A970:
	.byte 0x01, 0x49, 0x40, 0x18, 0x00, 0x88, 0x70, 0x47, 0x92, 0x03, 0x00, 0x00

	thumb_func_start FUN_0807a97c
FUN_0807a97c: @ 0x0807A97C
	push {r4, lr}
	movs r3, #0xe4
	lsls r3, r3, #2
	adds r4, r0, r3
	ldrh r3, [r4]
	orrs r1, r3
	strh r1, [r4]
	ldr r1, _0807A998 @ =0x00000392
	adds r0, r0, r1
	strh r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807A998: .4byte 0x00000392

	thumb_func_start FUN_0807a99c
FUN_0807a99c: @ 0x0807A99C
	movs r2, #0xe4
	lsls r2, r2, #2
	adds r3, r0, r2
	ldrh r2, [r3]
	bics r2, r1
	movs r1, #0
	strh r2, [r3]
	ldr r2, _0807A9B4 @ =0x00000392
	adds r0, r0, r2
	strh r1, [r0]
	bx lr
	.align 2, 0
_0807A9B4: .4byte 0x00000392

	thumb_func_start FUN_0807a9b8
FUN_0807a9b8: @ 0x0807A9B8
	adds r2, r0, #0
	movs r3, #0xe6
	lsls r3, r3, #2
	adds r0, r2, r3
	str r1, [r0]
	movs r0, #0xe5
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0807a9d0
FUN_0807a9d0: @ 0x0807A9D0
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x1c]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0807A9F4
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r1, [r0]
	cmp r1, #1
	bls _0807A9F8
	cmp r1, #3
	beq _0807A9F8
	ldrh r0, [r0]
	cmp r0, #7
	beq _0807A9F8
_0807A9F4:
	movs r0, #0
	b _0807A9FA
_0807A9F8:
	movs r0, #1
_0807A9FA:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0807aa00
FUN_0807aa00: @ 0x0807AA00
	push {r4, lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x1c]
	cmp r0, #1
	bne _0807AA26
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r3, r2, r0
	ldrh r0, [r3]
	adds r0, r0, r1
	strh r0, [r3]
	ldr r4, _0807AA2C @ =0x00000366
	adds r1, r2, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	blo _0807AA26
	strh r1, [r3]
_0807AA26:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807AA2C: .4byte 0x00000366

	thumb_func_start FUN_0807aa30
FUN_0807aa30: @ 0x0807AA30
	push {r4, lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x1c]
	cmp r0, #1
	bne _0807AA56
	movs r0, #0xda
	lsls r0, r0, #2
	adds r3, r2, r0
	ldrh r0, [r3]
	adds r0, r0, r1
	strh r0, [r3]
	ldr r4, _0807AA5C @ =0x0000036A
	adds r1, r2, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	blo _0807AA56
	strh r1, [r3]
_0807AA56:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807AA5C: .4byte 0x0000036A

	thumb_func_start FUN_0807aa60
FUN_0807aa60: @ 0x0807AA60
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x1c]
	cmp r0, #1
	bne _0807AA7E
	movs r0, #0xda
	lsls r0, r0, #2
	adds r2, r2, r0
	ldrh r0, [r2]
	cmp r0, r1
	bge _0807AA7A
	movs r0, #0
	b _0807AA7C
_0807AA7A:
	subs r0, r0, r1
_0807AA7C:
	strh r0, [r2]
_0807AA7E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0807aa84
FUN_0807aa84: @ 0x0807AA84
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	movs r1, #0x80
	movs r4, #0xde
	lsls r4, r4, #2
	adds r0, r2, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0807AAA4
	lsls r1, r3, #1
	adds r0, r2, #0
	bl FUN_0807aa00
	b _0807AAAC
_0807AAA4:
	adds r0, r2, #0
	adds r1, r3, #0
	bl FUN_0807aa00
_0807AAAC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0807aab4
FUN_0807aab4: @ 0x0807AAB4
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	movs r1, #0x80
	movs r4, #0xde
	lsls r4, r4, #2
	adds r0, r2, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0807AAD4
	lsls r1, r3, #1
	adds r0, r2, #0
	bl FUN_0807aa30
	b _0807AADC
_0807AAD4:
	adds r0, r2, #0
	adds r1, r3, #0
	bl FUN_0807aa30
_0807AADC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0807aae4
FUN_0807aae4: @ 0x0807AAE4
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	movs r1, #0x80
	movs r4, #0xde
	lsls r4, r4, #2
	adds r0, r2, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0807AB04
	lsls r1, r3, #1
	adds r0, r2, #0
	bl FUN_0807aa60
	b _0807AB0C
_0807AB04:
	adds r0, r2, #0
	adds r1, r3, #0
	bl FUN_0807aa60
_0807AB0C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0807ab14
FUN_0807ab14: @ 0x0807AB14
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r5, #0
	strb r5, [r0]
	subs r1, #0x9a
	adds r0, r4, r1
	strb r5, [r0]
	adds r0, r4, #0
	bl FUN_08063220
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r5, [r0]
	adds r1, #4
	adds r0, r4, r1
	strh r5, [r0]
	adds r0, r4, #0
	movs r1, #0x15
	movs r2, #0
	bl FUN_08060b84
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0807ab64
FUN_0807ab64: @ 0x0807AB64
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r4, r0, #0
	adds r7, r1, #0
	mov sb, r2
	mov r8, r3
	ldr r6, [r4, #0x1c]
	cmp r6, #1
	bne _0807AB88
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r5, [r4, #0x20]
	ands r5, r0
	cmp r5, #0
	beq _0807AB8E
_0807AB88:
	movs r0, #1
	rsbs r0, r0, #0
	b _0807AC66
_0807AB8E:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x15
	beq _0807ABA0
	adds r0, r4, #0
	bl FUN_0807ab14
_0807ABA0:
	ldr r0, [r7]
	ldr r1, [r7, #4]
	str r0, [r4, #0x2c]
	str r1, [r4, #0x30]
	adds r2, r4, #0
	adds r2, #0xa8
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, [sp, #0x2c]
	cmp r0, #0
	beq _0807ABCC
	adds r0, r4, #0
	adds r0, #0x90
	ldr r1, [r0]
	orrs r1, r6
	str r1, [r0]
	ldr r2, _0807ABC8 @ =0x000003FE
	adds r0, r4, r2
	strb r5, [r0]
	b _0807AC02
	.align 2, 0
_0807ABC8: .4byte 0x000003FE
_0807ABCC:
	adds r2, r4, #0
	adds r2, #0x90
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0807AC54 @ =0x000003FE
	adds r0, r4, r1
	strb r6, [r0]
	ldr r2, _0807AC58 @ =0x000002E7
	adds r1, r4, r2
	ldr r0, [sp, #0x24]
	strb r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x14
	bl FUN_08066ee4
	adds r1, r0, #0
	add r1, r8
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
_0807AC02:
	ldr r2, [sp, #0x28]
	cmp r2, #0
	ble _0807AC16
	ldr r1, _0807AC5C @ =0x0000095A
	adds r0, r4, r1
	strh r2, [r0]
	ldr r0, _0807AC60 @ =0x0000095C
	adds r1, r4, r0
	movs r0, #0x40
	strh r0, [r1]
_0807AC16:
	ldr r1, [sp, #0x30]
	cmp r1, #0
	ble _0807AC64
	movs r0, #0
	str r0, [sp]
	ldr r0, [sp, #0x34]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0807e7fc
	adds r3, r0, #0
	adds r0, r4, #0
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #0
	bne _0807AC50
	mov r2, sb
	cmp r2, #0
	beq _0807AC50
	movs r0, #0x97
	lsls r0, r0, #4
	adds r2, r4, r0
	mov r4, sb
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r2]
	str r1, [r2, #4]
_0807AC50:
	adds r0, r3, #0
	b _0807AC66
	.align 2, 0
_0807AC54: .4byte 0x000003FE
_0807AC58: .4byte 0x000002E7
_0807AC5C: .4byte 0x0000095A
_0807AC60: .4byte 0x0000095C
_0807AC64:
	movs r0, #0
_0807AC66:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0807ac74
FUN_0807ac74: @ 0x0807AC74
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r1, #0
	mov ip, r2
	ldr r6, [sp, #0x1c]
	ldr r1, [sp, #0x20]
	ldr r2, [r4, #0x1c]
	cmp r2, #1
	bne _0807AC94
	movs r7, #0xdf
	lsls r7, r7, #2
	adds r0, r4, r7
	ldrb r0, [r0]
	cmp r0, #0x15
	beq _0807AC9A
_0807AC94:
	movs r0, #1
	rsbs r0, r0, #0
	b _0807AD56
_0807AC9A:
	cmp r1, #0
	ble _0807ACAC
	ldr r7, _0807ACEC @ =0x0000095A
	adds r0, r4, r7
	strh r1, [r0]
	ldr r0, _0807ACF0 @ =0x0000095C
	adds r1, r4, r0
	movs r0, #0x40
	strh r0, [r1]
_0807ACAC:
	cmp r6, #0
	ble _0807ACB8
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r6, [r0]
_0807ACB8:
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r4, #0x2c]
	str r1, [r4, #0x30]
	adds r0, r3, #0
	adds r0, #0xe0
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #1
	adds r3, r0, #1
	movs r7, #0xba
	lsls r7, r7, #2
	adds r0, r4, r7
	strb r3, [r0]
	cmp r3, #4
	bls _0807ACF8
	movs r0, #8
	subs r0, r0, r3
	ldr r3, _0807ACF4 @ =0x000002E6
	adds r1, r4, r3
	strb r0, [r1]
	subs r7, #1
	adds r0, r4, r7
	strb r2, [r0]
	b _0807AD06
	.align 2, 0
_0807ACEC: .4byte 0x0000095A
_0807ACF0: .4byte 0x0000095C
_0807ACF4: .4byte 0x000002E6
_0807ACF8:
	ldr r1, _0807AD38 @ =0x000002E6
	adds r0, r4, r1
	strb r3, [r0]
	ldr r3, _0807AD3C @ =0x000002E7
	adds r1, r4, r3
	movs r0, #0
	strb r0, [r1]
_0807AD06:
	movs r7, #0xd6
	lsls r7, r7, #1
	adds r0, r4, r7
	movs r5, #0
	mov r1, ip
	strh r1, [r0]
	ldr r3, _0807AD40 @ =0x000003D2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xe6
	bl PlaySound_082406e0
	movs r7, #0xfb
	lsls r7, r7, #2
	adds r1, r4, r7
	ldrh r0, [r1]
	cmp r0, #0
	beq _0807AD2E
	strh r5, [r1]
_0807AD2E:
	ldr r0, [sp, #0x24]
	cmp r0, #0
	bgt _0807AD44
	movs r0, #0
	b _0807AD56
	.align 2, 0
_0807AD38: .4byte 0x000002E6
_0807AD3C: .4byte 0x000002E7
_0807AD40: .4byte 0x000003D2
_0807AD44:
	str r5, [sp]
	ldr r0, [sp, #0x28]
	str r0, [sp, #4]
	adds r0, r4, #0
	ldr r1, [sp, #0x24]
	movs r2, #0
	movs r3, #0
	bl FUN_0807e7fc
_0807AD56:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0807ad60
FUN_0807ad60: @ 0x0807AD60
	push {r4, r5, lr}
	adds r2, r0, #0
	adds r5, r1, #0
	ldr r3, [r2, #0x1c]
	cmp r3, #1
	bne _0807AD8A
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r1, [r0]
	cmp r1, #2
	beq _0807AD8A
	movs r0, #0xfb
	lsls r0, r0, #2
	adds r4, r2, r0
	ldrh r0, [r4]
	cmp r0, #0
	beq _0807AD94
	ldr r1, _0807AD90 @ =0x000003EA
	adds r0, r2, r1
	strh r3, [r0]
_0807AD8A:
	movs r0, #0
	b _0807ADB6
	.align 2, 0
_0807AD90: .4byte 0x000003EA
_0807AD94:
	subs r0, r1, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0807ADAC
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r2, r1
	strb r3, [r0]
	adds r1, #1
	adds r0, r2, r1
	strb r3, [r0]
_0807ADAC:
	strh r5, [r4]
	ldr r1, _0807ADBC @ =0x000003EA
	adds r0, r2, r1
	strh r3, [r0]
	movs r0, #1
_0807ADB6:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0807ADBC: .4byte 0x000003EA

	thumb_func_start FUN_0807adc0
FUN_0807adc0: @ 0x0807ADC0
	push {lr}
	adds r2, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r1, [r0]
	cmp r1, #0x1a
	bne _0807ADE4
	ldr r1, _0807ADE0 @ =0x0000037D
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #3
	bne _0807AE62
	adds r0, r2, #0
	movs r1, #0x1a
	b _0807AE22
	.align 2, 0
_0807ADE0: .4byte 0x0000037D
_0807ADE4:
	cmp r1, #0x1b
	bne _0807AE04
	ldr r1, _0807AE00 @ =0x0000037D
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne _0807AE62
	adds r0, r2, #0
	movs r1, #0x1b
	movs r2, #5
	bl FUN_08060b84
	b _0807AE62
	.align 2, 0
_0807AE00: .4byte 0x0000037D
_0807AE04:
	cmp r1, #0x1f
	bne _0807AE44
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _0807AE2A
	adds r1, #0x25
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #3
	bne _0807AE62
	adds r0, r2, #0
	movs r1, #0x1f
_0807AE22:
	movs r2, #4
	bl FUN_08060b84
	b _0807AE62
_0807AE2A:
	ldr r1, _0807AE40 @ =0x0000037D
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0807AE62
	adds r0, r2, #0
	movs r1, #0x1f
	movs r2, #2
	bl FUN_08060b84
	b _0807AE62
	.align 2, 0
_0807AE40: .4byte 0x0000037D
_0807AE44:
	ldr r0, [r2, #0x1c]
	cmp r0, #2
	bne _0807AE62
	cmp r1, #0x12
	bne _0807AE62
	ldr r1, _0807AE68 @ =0x0000037D
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0807AE62
	adds r0, r2, #0
	movs r1, #0x12
	movs r2, #4
	bl FUN_08060b84
_0807AE62:
	pop {r0}
	bx r0
	.align 2, 0
_0807AE68: .4byte 0x0000037D

	thumb_func_start FUN_0807ae6c
FUN_0807ae6c: @ 0x0807AE6C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	mov r8, r1
	mov sb, r2
	ldr r0, _0807AF4C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	bne _0807AE8C
	b _0807AFCC
_0807AE8C:
	ldr r0, _0807AF50 @ =0x000004C7
	adds r4, r7, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0807AEB2
	ldr r1, _0807AF54 @ =0x000004C5
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, r8
	beq _0807AEAC
	cmp r0, #3
	bne _0807AEA6
	b _0807AFCC
_0807AEA6:
	adds r0, r7, #0
	bl FUN_08063248
_0807AEAC:
	ldrb r0, [r4]
	cmp r0, #0
	bne _0807AEC8
_0807AEB2:
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r7, r2
	ldrb r1, [r0]
	adds r2, #1
	adds r0, r7, r2
	movs r2, #0
	strb r1, [r0]
	ldr r1, _0807AF58 @ =0x000003DA
	adds r0, r7, r1
	strh r2, [r0]
_0807AEC8:
	ldr r6, _0807AF5C @ =0x0203B400
	ldr r4, _0807AF60 @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r3, _0807AF64 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r2, #0xf
	ands r0, r2
	subs r0, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _0807AF68 @ =0xFFFF0000
	ldr r2, [sp]
	ands r2, r5
	orrs r2, r0
	str r2, [sp]
	adds r1, #1
	ands r1, r3
	str r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	movs r0, #0x1f
	ands r1, r0
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	ldr r0, _0807AF6C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	ands r0, r5
	str r0, [sp, #4]
	movs r5, #0
	cmp r5, sb
	bge _0807AF34
	mov r4, sb
_0807AF18:
	ldr r2, _0807AF70 @ =0x000004C4
	adds r0, r7, r2
	mov r1, r8
	movs r2, #0xe1
	lsls r2, r2, #4
	mov r3, sp
	bl FUN_082467d0
	cmp r0, #0
	blt _0807AF2E
	movs r5, #1
_0807AF2E:
	subs r4, #1
	cmp r4, #0
	bne _0807AF18
_0807AF34:
	cmp r5, #0
	beq _0807AFC4
	ldr r1, _0807AF54 @ =0x000004C5
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0807AF78
	ldr r0, _0807AF74 @ =0x00000191
	bl PlaySound_082406e0
	b _0807AFC4
	.align 2, 0
_0807AF4C: .4byte 0x030047A4
_0807AF50: .4byte 0x000004C7
_0807AF54: .4byte 0x000004C5
_0807AF58: .4byte 0x000003DA
_0807AF5C: .4byte 0x0203B400
_0807AF60: .4byte 0x030046B8
_0807AF64: .4byte 0x000003FF
_0807AF68: .4byte 0xFFFF0000
_0807AF6C: .4byte 0x0000FFFF
_0807AF70: .4byte 0x000004C4
_0807AF74: .4byte 0x00000191
_0807AF78:
	cmp r0, #2
	bne _0807AF98
	ldr r2, _0807AF90 @ =0x00000376
	adds r0, r7, r2
	ldrh r1, [r0]
	adds r1, #0xa
	strh r1, [r0]
	ldr r0, _0807AF94 @ =0x00000133
	bl PlaySound_082406e0
	b _0807AFC4
	.align 2, 0
_0807AF90: .4byte 0x00000376
_0807AF94: .4byte 0x00000133
_0807AF98:
	cmp r0, #3
	bne _0807AFC4
	ldr r0, _0807AFDC @ =0x00000133
	bl PlaySound_082406e0
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0xa
	strh r0, [r1]
	movs r2, #0xd8
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r0, [r1]
	cmp r0, #0
	bne _0807AFBC
	movs r0, #1
	strh r0, [r1]
_0807AFBC:
	ldr r0, _0807AFE0 @ =0x000003D2
	adds r1, r7, r0
	movs r0, #0
	strb r0, [r1]
_0807AFC4:
	ldr r2, _0807AFE4 @ =0x0000043E
	adds r1, r7, r2
	movs r0, #0
	strh r0, [r1]
_0807AFCC:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807AFDC: .4byte 0x00000133
_0807AFE0: .4byte 0x000003D2
_0807AFE4: .4byte 0x0000043E

	thumb_func_start FUN_0807afe8
FUN_0807afe8: @ 0x0807AFE8
	push {lr}
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	bne _0807AFF8
	movs r0, #0
	b _0807AFFC
_0807AFF8:
	bl fetch_082316e4
_0807AFFC:
	pop {r1}
	bx r1

	thumb_func_start FUN_0807b000
FUN_0807b000: @ 0x0807B000
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	bne _0807B012
	movs r0, #0
	b _0807B026
_0807B012:
	bl fetch_082316e4
	strh r0, [r4]
	bl fetch_082316e4
	strh r0, [r4, #2]
	bl fetch_082316e4
	strh r0, [r4, #4]
	movs r0, #1
_0807B026:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0807b02c
FUN_0807b02c: @ 0x0807B02C
	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807B080 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807B0B2
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	bl FUN_0807b000
	cmp r0, #0
	beq _0807B0B2
	movs r0, #0x64
	bl prepare_08231510
	cmp r0, #0
	beq _0807B096
	bl fetch_082316e4
	adds r1, r0, #0
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls _0807B088
	movs r0, #8
	subs r0, r0, r1
	subs r2, #2
	adds r1, r5, r2
	strb r0, [r1]
	ldr r0, _0807B084 @ =0x000002E7
	adds r1, r5, r0
	movs r0, #1
	b _0807B094
	.align 2, 0
_0807B080: .4byte 0x03002BE0
_0807B084: .4byte 0x000002E7
_0807B088:
	ldr r2, _0807B0B8 @ =0x000002E6
	adds r0, r5, r2
	strb r1, [r0]
	ldr r0, _0807B0BC @ =0x000002E7
	adds r1, r5, r0
	movs r0, #0
_0807B094:
	strb r0, [r1]
_0807B096:
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r4, #0
	bl FUN_0823280c
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	adds r0, r5, #0
	bl FUN_08060c60
_0807B0B2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807B0B8: .4byte 0x000002E6
_0807B0BC: .4byte 0x000002E7

	thumb_func_start FUN_0807b0c0
FUN_0807b0c0: @ 0x0807B0C0
	push {lr}
	bl FUN_0807afe8
	ldr r1, _0807B0E0 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r2, r1, #0
	cmp r1, #0
	bne _0807B0E8
	ldr r0, _0807B0E4 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x36
	ldrsh r0, [r0, r1]
	b _0807B110
	.align 2, 0
_0807B0E0: .4byte 0x03002BE0
_0807B0E4: .4byte 0x030046A0
_0807B0E8:
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r1, r3
	ldrb r0, [r0]
	subs r0, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0807B104
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	b _0807B110
_0807B104:
	ldr r3, _0807B114 @ =0x000003BD
	adds r0, r2, r3
	ldrb r0, [r0]
	adds r0, #4
	movs r1, #7
	ands r0, r1
_0807B110:
	pop {r1}
	bx r1
	.align 2, 0
_0807B114: .4byte 0x000003BD

	thumb_func_start FUN_0807b118
FUN_0807b118: @ 0x0807B118
	push {lr}
	ldr r0, _0807B12C @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _0807B128
	ldr r0, [r0, #0x1c]
	cmp r0, #4
	beq _0807B130
_0807B128:
	movs r0, #0
	b _0807B132
	.align 2, 0
_0807B12C: .4byte 0x03002BE0
_0807B130:
	movs r0, #1
_0807B132:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0807b138
FUN_0807b138: @ 0x0807B138
	push {lr}
	bl FUN_0807afe8
	ldr r1, _0807B150 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0807B154
	bl FUN_0807a9d0
	b _0807B156
	.align 2, 0
_0807B150: .4byte 0x03002BE0
_0807B154:
	movs r0, #0
_0807B156:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0807b15c
FUN_0807b15c: @ 0x0807B15C
	push {lr}
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _0807B170
	bl fetch_082316e4
	bl FUN_0807a798
_0807B170:
	pop {r0}
	bx r0

	thumb_func_start FUN_0807b174
FUN_0807b174: @ 0x0807B174
	push {r4, lr}
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _0807B19C
	bl fetch_082316e4
	adds r4, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0807B19C
	bl fetch_082316e4
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_0807a7f8
_0807B19C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0807b1a4
FUN_0807b1a4: @ 0x0807B1A4
	push {r4, lr}
	bl FUN_0807afe8
	ldr r1, _0807B1C8 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r4, r0, #0
	cmp r4, #0
	beq _0807B1C2
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	bne _0807B1CC
_0807B1C2:
	movs r0, #0
	b _0807B1DC
	.align 2, 0
_0807B1C8: .4byte 0x03002BE0
_0807B1CC:
	bl fetch_082316e4
	movs r2, #0xde
	lsls r2, r2, #2
	adds r1, r4, r2
	ldr r1, [r1]
	ands r1, r0
	adds r0, r1, #0
_0807B1DC:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start item_0807b1e4
item_0807b1e4: @ 0x0807B1E4
	push {r4, r5, r6, lr}
	sub sp, #8
	bl FUN_0807afe8
	ldr r1, _0807B228 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r6, [r0]
	cmp r6, #0
	beq _0807B2CA
	movs r0, #0x45
	bl prepare_08231510
	cmp r0, #0
	beq _0807B2CA
	bl fetch_082316e4
	adds r4, r0, #0
	ldr r1, _0807B22C @ =0x08DAA8D8
	lsls r0, r4, #4
	adds r5, r0, r1
	ldrh r0, [r5, #2]
	cmp r0, #5
	bne _0807B264
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _0807B230
	bl fetch_082316e4
	adds r2, r0, #0
	b _0807B238
	.align 2, 0
_0807B228: .4byte 0x03002BE0
_0807B22C: .4byte 0x08DAA8D8
_0807B230:
	ldrh r1, [r5, #8]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r2, r0, #2
_0807B238:
	ldr r1, _0807B254 @ =0x08DAA8D8
	lsls r0, r4, #4
	adds r0, r0, r1
	ldrh r1, [r0, #6]
	ldr r3, _0807B258 @ =0x00000442
	adds r0, r6, r3
	strh r1, [r0]
	ldr r1, _0807B25C @ =0x00000446
	adds r0, r6, r1
	strh r2, [r0]
	ldr r2, _0807B260 @ =0x00000444
	adds r0, r6, r2
	strh r4, [r0]
	b _0807B2B8
	.align 2, 0
_0807B254: .4byte 0x08DAA8D8
_0807B258: .4byte 0x00000442
_0807B25C: .4byte 0x00000446
_0807B260: .4byte 0x00000444
_0807B264:
	cmp r0, #1
	bne _0807B2CA
	ldr r1, _0807B290 @ =0x00000366
	adds r4, r6, r1
	ldrh r1, [r4]
	ldrh r0, [r5, #6]
	muls r0, r1, r0
	movs r1, #0x64
	bl Div
	adds r5, r0, #0
	movs r2, #0xd9
	lsls r2, r2, #2
	adds r1, r6, r2
	ldrh r3, [r1]
	adds r2, r3, r5
	ldrh r0, [r4]
	cmp r2, r0
	ble _0807B294
	subs r5, r0, r3
	strh r0, [r1]
	b _0807B296
	.align 2, 0
_0807B290: .4byte 0x00000366
_0807B294:
	strh r2, [r1]
_0807B296:
	cmp r5, #0
	ble _0807B2B8
	movs r3, #0xb6
	lsls r3, r3, #1
	adds r0, r6, r3
	adds r3, r6, #0
	adds r3, #0x2c
	movs r2, #0x97
	lsls r2, r2, #4
	adds r1, r6, r2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	adds r1, r5, #0
	movs r2, #1
	bl FUN_0805fe7c
_0807B2B8:
	ldr r3, _0807B2D4 @ =0x0000095E
	adds r1, r6, r3
	ldr r0, _0807B2D8 @ =0x00000121
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r6, r0
	movs r0, #0x30
	strh r0, [r1]
_0807B2CA:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807B2D4: .4byte 0x0000095E
_0807B2D8: .4byte 0x00000121

	thumb_func_start FUN_0807b2dc
FUN_0807b2dc: @ 0x0807B2DC
	push {lr}
	bl FUN_0807afe8
	ldr r1, _0807B304 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r0, #0
	cmp r1, #0
	beq _0807B30C
	ldr r2, _0807B308 @ =0x00000446
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _0807B30C
	subs r2, #4
	adds r0, r1, r2
	ldrh r0, [r0]
	b _0807B310
	.align 2, 0
_0807B304: .4byte 0x03002BE0
_0807B308: .4byte 0x00000446
_0807B30C:
	movs r0, #1
	rsbs r0, r0, #0
_0807B310:
	pop {r1}
	bx r1

	thumb_func_start FUN_0807b314
FUN_0807b314: @ 0x0807B314
	push {lr}
	bl FUN_0807afe8
	ldr r1, _0807B340 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _0807B33A
	ldr r1, _0807B344 @ =0x00000442
	adds r0, r2, r1
	movs r1, #0
	strh r1, [r0]
	ldr r3, _0807B348 @ =0x00000446
	adds r0, r2, r3
	strh r1, [r0]
	subs r3, #2
	adds r0, r2, r3
	strh r1, [r0]
_0807B33A:
	pop {r0}
	bx r0
	.align 2, 0
_0807B340: .4byte 0x03002BE0
_0807B344: .4byte 0x00000442
_0807B348: .4byte 0x00000446

	thumb_func_start FUN_0807b34c
FUN_0807b34c: @ 0x0807B34C
	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807B3B4 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	adds r5, r4, #0
	cmp r4, #0
	beq _0807B3AE
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _0807B3AE
	bl fetch_082316e4
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08060ec8
	ldr r1, _0807B3B8 @ =0x00003FFE
	adds r0, r4, #0
	bl FUN_08060ed8
	cmp r0, #0
	beq _0807B398
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r0, r4, #0
	bl FUN_08064c48
	ldr r2, _0807B3BC @ =0x00000282
	adds r1, r4, r2
	strb r0, [r1]
_0807B398:
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0807B3AE
	bl fetch_082316e4
	movs r2, #0x9c
	lsls r2, r2, #4
	adds r1, r5, r2
	str r0, [r1]
_0807B3AE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807B3B4: .4byte 0x03002BE0
_0807B3B8: .4byte 0x00003FFE
_0807B3BC: .4byte 0x00000282

	thumb_func_start FUN_0807b3c0
FUN_0807b3c0: @ 0x0807B3C0
	push {lr}
	bl FUN_0807afe8
	ldr r1, _0807B3DC @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0807B3D6
	bl FUN_08063220
_0807B3D6:
	pop {r0}
	bx r0
	.align 2, 0
_0807B3DC: .4byte 0x03002BE0

	thumb_func_start FUN_0807b3e0
FUN_0807b3e0: @ 0x0807B3E0
	push {r4, lr}
	bl FUN_0807afe8
	ldr r1, _0807B408 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0807B404
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _0807B404
	bl fetch_082316e4
	cmp r0, #2
	ble _0807B40C
_0807B404:
	movs r0, #0
	b _0807B41C
	.align 2, 0
_0807B408: .4byte 0x03002BE0
_0807B40C:
	lsls r0, r0, #1
	ldr r2, _0807B424 @ =0x0000043C
	adds r1, r4, r2
	adds r1, r1, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0807B404
	movs r0, #1
_0807B41C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0807B424: .4byte 0x0000043C

	thumb_func_start FUN_0807b428
FUN_0807b428: @ 0x0807B428
	push {r4, lr}
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _0807B478
	bl fetch_082316e4
	adds r4, r0, #0
	cmp r4, #2
	bgt _0807B478
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _0807B450
	bl fetch_082316e4
	adds r2, r0, #0
	b _0807B458
_0807B450:
	ldr r1, _0807B468 @ =0x085ABF4C
	lsls r0, r4, #1
	adds r0, r0, r1
	ldrh r2, [r0]
_0807B458:
	ldr r0, _0807B46C @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _0807B470
	adds r1, r4, #0
	bl FUN_08063574
	b _0807B478
	.align 2, 0
_0807B468: .4byte 0x085ABF4C
_0807B46C: .4byte 0x03002BE0
_0807B470:
	ldr r1, _0807B480 @ =0x03002BA0
	lsls r0, r4, #1
	adds r0, r0, r1
	strh r2, [r0]
_0807B478:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807B480: .4byte 0x03002BA0

	thumb_func_start FUN_0807b484
FUN_0807b484: @ 0x0807B484
	push {r4, lr}
	bl FUN_0807afe8
	ldr r1, _0807B4B4 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0807B4AC
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _0807B4AC
	bl fetch_082316e4
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08063634
_0807B4AC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807B4B4: .4byte 0x03002BE0

	thumb_func_start FUN_0807b4b8
FUN_0807b4b8: @ 0x0807B4B8
	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807B4E0 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807B4DA
	movs r4, #0
_0807B4CC:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08063634
	adds r4, #1
	cmp r4, #2
	ble _0807B4CC
_0807B4DA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807B4E0: .4byte 0x03002BE0

	thumb_func_start FUN_0807b4e4
FUN_0807b4e4: @ 0x0807B4E4
	push {lr}
	bl FUN_0807afe8
	ldr r1, _0807B514 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0807B510
	ldr r1, _0807B518 @ =0x0000038E
	adds r0, r0, r1
	ldrb r0, [r0]
	ldr r1, _0807B51C @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	bgt _0807B520
_0807B510:
	movs r0, #0
	b _0807B522
	.align 2, 0
_0807B514: .4byte 0x03002BE0
_0807B518: .4byte 0x0000038E
_0807B51C: .4byte 0x030046A0
_0807B520:
	movs r0, #1
_0807B522:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0807b528
FUN_0807b528: @ 0x0807B528
	push {lr}
	bl FUN_0807afe8
	ldr r1, _0807B558 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0807B552
	ldr r1, _0807B55C @ =0x0000038E
	adds r0, r0, r1
	ldrb r0, [r0]
	ldr r1, _0807B560 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
_0807B552:
	pop {r0}
	bx r0
	.align 2, 0
_0807B558: .4byte 0x03002BE0
_0807B55C: .4byte 0x0000038E
_0807B560: .4byte 0x030046A0
_0807B564:
	.byte 0x03, 0x48, 0x00, 0x21, 0x01, 0x80, 0x03, 0x48, 0x01, 0x80, 0x03, 0x48
	.byte 0x01, 0x80, 0x70, 0x47, 0xD0, 0x2B, 0x00, 0x03, 0x80, 0x2B, 0x00, 0x03, 0x78, 0x2B, 0x00, 0x03

	thumb_func_start FUN_0807b580
FUN_0807b580: @ 0x0807B580
	push {lr}
	bl FUN_0807afe8
	ldr r1, _0807B5A0 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0807B59A
	ldr r2, _0807B5A4 @ =0x0000043A
	adds r1, r0, r2
	movs r0, #1
	strh r0, [r1]
_0807B59A:
	pop {r0}
	bx r0
	.align 2, 0
_0807B5A0: .4byte 0x03002BE0
_0807B5A4: .4byte 0x0000043A

	thumb_func_start FUN_0807b5a8
FUN_0807b5a8: @ 0x0807B5A8
	push {lr}
	bl FUN_0807afe8
	ldr r1, _0807B5C8 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0807B5C2
	ldr r2, _0807B5CC @ =0x000003BA
	adds r1, r0, r2
	movs r0, #1
	strh r0, [r1]
_0807B5C2:
	pop {r0}
	bx r0
	.align 2, 0
_0807B5C8: .4byte 0x03002BE0
_0807B5CC: .4byte 0x000003BA

	thumb_func_start FUN_0807b5d0
FUN_0807b5d0: @ 0x0807B5D0
	push {lr}
	bl FUN_0807afe8
	ldr r1, _0807B5F0 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0807B5EA
	ldr r2, _0807B5F4 @ =0x00000285
	adds r1, r0, r2
	movs r0, #1
	strb r0, [r1]
_0807B5EA:
	pop {r0}
	bx r0
	.align 2, 0
_0807B5F0: .4byte 0x03002BE0
_0807B5F4: .4byte 0x00000285

	thumb_func_start FUN_0807b5f8
FUN_0807b5f8: @ 0x0807B5F8
	push {lr}
	bl FUN_0807afe8
	ldr r1, _0807B618 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0807B612
	ldr r2, _0807B61C @ =0x00000285
	adds r1, r0, r2
	movs r0, #0
	strb r0, [r1]
_0807B612:
	pop {r0}
	bx r0
	.align 2, 0
_0807B618: .4byte 0x03002BE0
_0807B61C: .4byte 0x00000285

	thumb_func_start FUN_0807b620
FUN_0807b620: @ 0x0807B620
	push {lr}
	bl FUN_0807afe8
	ldr r1, _0807B63C @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0807B644
	ldr r1, _0807B640 @ =0x00000A75
	adds r0, r0, r1
	ldrb r0, [r0]
	b _0807B646
	.align 2, 0
_0807B63C: .4byte 0x03002BE0
_0807B640: .4byte 0x00000A75
_0807B644:
	movs r0, #0
_0807B646:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0807b64c
FUN_0807b64c: @ 0x0807B64C
	push {lr}
	bl FUN_0807afe8
	ldr r1, _0807B668 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0807B662
	bl FUN_0807e854
_0807B662:
	pop {r0}
	bx r0
	.align 2, 0
_0807B668: .4byte 0x03002BE0

	thumb_func_start FUN_0807b66c
FUN_0807b66c: @ 0x0807B66C
	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807B6B4 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	adds r5, r4, #0
	cmp r4, #0
	beq _0807B6AC
	adds r0, r4, #0
	bl FUN_0807e854
	movs r0, #0x64
	bl prepare_08231510
	cmp r0, #0
	beq _0807B69C
	bl fetch_082316e4
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
_0807B69C:
	adds r0, r5, #0
	bl FUN_080609dc
	adds r0, r5, #0
	movs r1, #0x1f
	movs r2, #0
	bl FUN_08060b84
_0807B6AC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807B6B4: .4byte 0x03002BE0

	thumb_func_start FUN_0807b6b8
FUN_0807b6b8: @ 0x0807B6B8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	bl FUN_0807afe8
	ldr r1, _0807B784 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	mov r8, r0
	mov sb, r8
	cmp r0, #0
	beq _0807B794
	movs r0, #0xdf
	lsls r0, r0, #2
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0xb
	bne _0807B794
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0807B794
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _0807B788 @ =0xFFFF0000
	adds r4, r5, #0
	ands r4, r6
	orrs r4, r0
	bl fetch_082316e4
	lsls r0, r0, #0x10
	ldr r1, _0807B78C @ =0x0000FFFF
	ands r4, r1
	adds r6, r4, #0
	orrs r6, r0
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r7
	adds r7, r5, #0
	orrs r7, r0
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	mov r2, r8
	movs r3, #0x2c
	ldrsh r1, [r2, r3]
	subs r2, r0, r1
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	mov r4, r8
	movs r3, #0x30
	ldrsh r1, [r4, r3]
	subs r5, r0, r1
	adds r0, r2, #0
	muls r0, r2, r0
	adds r1, r5, #0
	muls r1, r5, r1
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xb
	cmp r0, r1
	bgt _0807B794
	movs r0, #0xba
	lsls r0, r0, #2
	add r0, sb
	ldrb r4, [r0]
	adds r4, #5
	movs r0, #7
	ands r4, r0
	lsls r4, r4, #5
	adds r0, r2, #0
	adds r1, r5, #0
	bl FUN_0823785c
	ldr r1, _0807B790 @ =0xFFFFFF00
	adds r4, r4, r1
	subs r0, r0, r4
	movs r5, #0xff
	ands r0, r5
	subs r0, #0x21
	cmp r0, #0xbe
	bls _0807B794
	movs r0, #0x64
	bl prepare_08231510
	cmp r0, #0
	beq _0807B794
	bl fetch_082316e4
	subs r0, r0, r4
	ands r0, r5
	subs r0, #0x21
	cmp r0, #0xbe
	bls _0807B794
	movs r0, #1
	b _0807B796
	.align 2, 0
_0807B784: .4byte 0x03002BE0
_0807B788: .4byte 0xFFFF0000
_0807B78C: .4byte 0x0000FFFF
_0807B790: .4byte 0xFFFFFF00
_0807B794:
	movs r0, #0
_0807B796:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0807b7a4
FUN_0807b7a4: @ 0x0807B7A4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, [r5, #0x1c]
	cmp r0, #2
	beq _0807B7DA
	ldr r1, _0807B878 @ =0x00000992
	adds r0, r5, r1
	movs r3, #0
	strh r3, [r0]
	ldr r6, _0807B87C @ =0x0000098C
	adds r4, r5, r6
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	adds r6, #4
	adds r2, r5, r6
	ldrb r2, [r2]
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	movs r3, #0x50
	str r3, [sp, #0xc]
	movs r3, #0x7f
	bl FUN_080da9c4
	str r0, [r4]
_0807B7DA:
	movs r0, #2
	str r0, [r5, #0x1c]
	ldr r1, _0807B880 @ =0x000004AA
	adds r0, r5, r1
	movs r4, #0
	strb r4, [r0]
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r5, r6
	movs r2, #1
	strb r2, [r0]
	subs r1, #0xb4
	adds r0, r5, r1
	strh r4, [r0]
	subs r6, #0xb0
	adds r0, r5, r6
	strh r4, [r0]
	ldr r7, _0807B884 @ =0x03002BA8
	ldr r1, [r7]
	cmp r1, #0
	beq _0807B824
	ldr r6, _0807B888 @ =0x03002BF4
	ldrh r0, [r6]
	cmp r0, #0
	beq _0807B824
	ldr r0, [r1, #4]
	ands r0, r2
	cmp r0, #0
	bne _0807B820
	ldr r0, [r1]
	ldr r3, [r1, #8]
	movs r1, #1
	movs r2, #0x3c
	bl _call_via_r3
_0807B820:
	str r4, [r7]
	strh r4, [r6]
_0807B824:
	adds r0, r5, #0
	bl FUN_08060c60
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	strh r2, [r0]
	movs r6, #0xb9
	lsls r6, r6, #1
	adds r3, r5, r6
	ldrh r1, [r3]
	movs r0, #4
	orrs r0, r1
	strh r0, [r3]
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	ldr r6, _0807B88C @ =0x000003CE
	adds r0, r5, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _0807B85C
	adds r0, r5, #0
	bl FUN_08066d10
_0807B85C:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08060c40
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r5, #0x20]
	orrs r0, r1
	str r0, [r5, #0x20]
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807B878: .4byte 0x00000992
_0807B87C: .4byte 0x0000098C
_0807B880: .4byte 0x000004AA
_0807B884: .4byte 0x03002BA8
_0807B888: .4byte 0x03002BF4
_0807B88C: .4byte 0x000003CE

	thumb_func_start FUN_0807b890
FUN_0807b890: @ 0x0807B890
	ldr r2, _0807B8A0 @ =0x0000096C
	adds r3, r0, r2
	movs r2, #1
	strh r2, [r3]
	ldr r2, _0807B8A4 @ =0x0000095E
	adds r0, r0, r2
	strh r1, [r0]
	bx lr
	.align 2, 0
_0807B8A0: .4byte 0x0000096C
_0807B8A4: .4byte 0x0000095E

	thumb_func_start FUN_0807b8a8
FUN_0807b8a8: @ 0x0807B8A8
	ldr r2, _0807B8B8 @ =0x0000096C
	adds r3, r0, r2
	movs r2, #2
	strh r2, [r3]
	ldr r2, _0807B8BC @ =0x0000095E
	adds r0, r0, r2
	strh r1, [r0]
	bx lr
	.align 2, 0
_0807B8B8: .4byte 0x0000096C
_0807B8BC: .4byte 0x0000095E

	thumb_func_start FUN_0807b8c0
FUN_0807b8c0: @ 0x0807B8C0
	ldr r1, _0807B8CC @ =0x0000096C
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_0807B8CC: .4byte 0x0000096C

	thumb_func_start FUN_0807b8d0
FUN_0807b8d0: @ 0x0807B8D0
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [r0, #0x2c]
	str r2, [r0, #0x30]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0807b8dc
FUN_0807b8dc: @ 0x0807B8DC
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	adds r2, r4, #0
	adds r2, #0x90
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0x93
	lsls r0, r0, #3
	adds r4, r4, r0
	ldr r0, _0807B90C @ =0x080726E1
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807B90C: .4byte 0x080726E1

	thumb_func_start FUN_0807b910
FUN_0807b910: @ 0x0807B910
	push {r4, r5, lr}
	adds r4, r0, #0
	cmp r1, #0
	blt _0807B920
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_0807B920:
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #2
	bne _0807B988
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r0, [r2]
	movs r1, #1
	orrs r1, r0
	strb r1, [r2]
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0807B960
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _0807B958 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _0807B95C @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	b _0807B96E
	.align 2, 0
_0807B958: .4byte 0x000002E6
_0807B95C: .4byte 0x000002E7
_0807B960:
	lsrs r1, r1, #0x19
	ldr r2, _0807B97C @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _0807B980 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
_0807B96E:
	strb r0, [r1]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807B984 @ =FUN_08074d90
	b _0807B9C0
	.align 2, 0
_0807B97C: .4byte 0x000002E6
_0807B980: .4byte 0x000002E7
_0807B984: .4byte FUN_08074d90
_0807B988:
	adds r0, r4, #0
	bl FUN_080609dc
	ldrb r0, [r5]
	cmp r0, #3
	bne _0807B9A4
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807B9A0 @ =FUN_08075df8
	b _0807B9C0
	.align 2, 0
_0807B9A0: .4byte FUN_08075df8
_0807B9A4:
	cmp r0, #4
	bne _0807B9B8
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807B9B4 @ =FUN_080772ec
	b _0807B9C0
	.align 2, 0
_0807B9B4: .4byte FUN_080772ec
_0807B9B8:
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807B9D8 @ =FUN_08072724
_0807B9C0:
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807B9D8: .4byte FUN_08072724

	thumb_func_start FUN_0807b9dc
FUN_0807b9dc: @ 0x0807B9DC
	push {r4, lr}
	adds r4, r0, #0
	ldr r3, _0807BA0C @ =0x000004A9
	adds r0, r4, r3
	strb r1, [r0]
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	subs r3, #0x11
	adds r1, r4, r3
	ldr r0, _0807BA10 @ =0x080727D5
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807BA0C: .4byte 0x000004A9
_0807BA10: .4byte 0x080727D5

	thumb_func_start FUN_0807ba14
FUN_0807ba14: @ 0x0807BA14
	push {r4, lr}
	adds r4, r0, #0
	cmp r1, #0
	blt _0807BA24
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_0807BA24:
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807BA4C @ =FUN_08072724
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807BA4C: .4byte FUN_08072724

	thumb_func_start FUN_0807ba50
FUN_0807ba50: @ 0x0807BA50
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	cmp r1, #0
	blt _0807BA62
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_0807BA62:
	adds r0, r4, #0
	bl FUN_080609dc
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r5, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0
	movs r2, #2
	bl FUN_08060b84
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807BA90 @ =FUN_08072724
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807BA90: .4byte FUN_08072724

	thumb_func_start FUN_0807ba94
FUN_0807ba94: @ 0x0807BA94
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r3, #0
	ldr r0, _0807BAD8 @ =0x0000049C
	adds r3, r4, r0
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r3]
	str r1, [r3, #4]
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	ldr r2, _0807BADC @ =0x000004A9
	adds r1, r4, r2
	strb r5, [r1]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #2
	bne _0807BAE4
	lsls r0, r5, #0x18
	cmp r0, #0
	blt _0807BACE
	asrs r0, r0, #0x19
	lsls r0, r0, #1
	adds r0, #1
	strb r0, [r1]
_0807BACE:
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807BAE0 @ =FUN_08074e98
	b _0807BB20
	.align 2, 0
_0807BAD8: .4byte 0x0000049C
_0807BADC: .4byte 0x000004A9
_0807BAE0: .4byte FUN_08074e98
_0807BAE4:
	cmp r0, #3
	bne _0807BAF8
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807BAF4 @ =FUN_08075f00
	b _0807BB20
	.align 2, 0
_0807BAF4: .4byte FUN_08075f00
_0807BAF8:
	cmp r0, #4
	bne _0807BB18
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	ldr r2, _0807BB14 @ =0x00000381
	adds r0, r4, r2
	strb r1, [r0]
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	b _0807BB1E
	.align 2, 0
_0807BB14: .4byte 0x00000381
_0807BB18:
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
_0807BB1E:
	ldr r0, _0807BB38 @ =0x08072A39
_0807BB20:
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0
	bl FUN_08060b84
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807BB38: .4byte 0x08072A39

	thumb_func_start FUN_0807bb3c
FUN_0807bb3c: @ 0x0807BB3C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	cmp r1, #0
	bne _0807BB54
	ldr r0, _0807BB50 @ =0x0000049C
	adds r2, r4, r0
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	b _0807BB5C
	.align 2, 0
_0807BB50: .4byte 0x0000049C
_0807BB54:
	ldr r0, _0807BBA0 @ =0x0000049C
	adds r2, r4, r0
	ldr r0, [r1]
	ldr r1, [r1, #4]
_0807BB5C:
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0x96
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, [sp, #0xc]
	str r0, [r1]
	ldr r1, _0807BBA4 @ =0x000004A6
	adds r0, r4, r1
	strb r3, [r0]
	adds r1, #3
	adds r0, r4, r1
	strb r5, [r0]
	ldr r0, _0807BBA8 @ =0x000004A7
	adds r1, r4, r0
	movs r0, #0x96
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #6
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807BBAC @ =FUN_08072d48
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807BBA0: .4byte 0x0000049C
_0807BBA4: .4byte 0x000004A6
_0807BBA8: .4byte 0x000004A7
_0807BBAC: .4byte FUN_08072d48

	thumb_func_start FUN_0807bbb0
FUN_0807bbb0: @ 0x0807BBB0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	movs r1, #4
	bl FUN_0807b910
	ldr r1, _0807BC04 @ =0x000004A6
	adds r0, r4, r1
	movs r2, #0
	strb r5, [r0]
	adds r1, #0xa
	adds r0, r4, r1
	str r6, [r0]
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #4
	strb r0, [r1]
	ldr r0, _0807BC08 @ =0x000002E6
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0807BC0C @ =0x000002E7
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #7
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r4, r4, r0
	ldr r0, _0807BC10 @ =FUN_0807304c
	str r0, [r4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807BC04: .4byte 0x000004A6
_0807BC08: .4byte 0x000002E6
_0807BC0C: .4byte 0x000002E7
_0807BC10: .4byte FUN_0807304c

	thumb_func_start FUN_0807bc14
FUN_0807bc14: @ 0x0807BC14
	push {r4, lr}
	adds r4, r0, #0
	ldr r3, _0807BC5C @ =0x000004A6
	adds r0, r4, r3
	movs r3, #0
	strb r1, [r0]
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r3, [r0]
	subs r1, #2
	adds r0, r4, r1
	strb r3, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r3, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #7
	movs r2, #0
	bl FUN_08060b84
	movs r3, #0x93
	lsls r3, r3, #3
	adds r4, r4, r3
	ldr r0, _0807BC60 @ =FUN_0807304c
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807BC5C: .4byte 0x000004A6
_0807BC60: .4byte FUN_0807304c

	thumb_func_start FUN_0807bc64
FUN_0807bc64: @ 0x0807BC64
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x1c]
	cmp r0, #2
	bne _0807BCA6
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #7
	bne _0807BCA6
	adds r2, #1
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807BCA6
	movs r2, #0x96
	lsls r2, r2, #3
	adds r0, r4, r2
	str r1, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #7
	movs r2, #3
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807BCAC @ =FUN_0807304c
	str r0, [r1]
_0807BCA6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807BCAC: .4byte FUN_0807304c

	thumb_func_start FUN_0807bcb0
FUN_0807bcb0: @ 0x0807BCB0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	bl FUN_0807b7a4
	cmp r5, #0
	blt _0807BCC8
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r5, [r0]
_0807BCC8:
	adds r0, r4, #0
	bl FUN_080609dc
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r6, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0x12
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807BCF8 @ =FUN_08073574
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807BCF8: .4byte FUN_08073574

	thumb_func_start FUN_0807bcfc
FUN_0807bcfc: @ 0x0807BCFC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl FUN_0807b7a4
	cmp r5, #0
	blt _0807BD12
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r5, [r0]
_0807BD12:
	adds r0, r4, #0
	bl FUN_080609dc
	movs r0, #0xc6
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0x12
	movs r2, #2
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807BD40 @ =FUN_08073574
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807BD40: .4byte FUN_08073574

	thumb_func_start FUN_0807bd44
FUN_0807bd44: @ 0x0807BD44
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl FUN_0807b7a4
	cmp r5, #0
	blt _0807BD5A
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r5, [r0]
_0807BD5A:
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0x12
	movs r2, #1
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807BD80 @ =FUN_08073574
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807BD80: .4byte FUN_08073574

	thumb_func_start FUN_0807bd84
FUN_0807bd84: @ 0x0807BD84
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	cmp r1, #0
	blt _0807BD96
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_0807BD96:
	adds r0, r4, #0
	bl FUN_080609dc
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r5, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0x12
	movs r2, #3
	bl FUN_08060b84
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807BDC4 @ =FUN_08073574
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807BDC4: .4byte FUN_08073574

	thumb_func_start FUN_0807bdc8
FUN_0807bdc8: @ 0x0807BDC8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	cmp r1, #0
	blt _0807BDDA
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_0807BDDA:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	ldr r2, _0807BE24 @ =0x000004A6
	adds r0, r4, r2
	strb r5, [r0]
	subs r1, #0xc0
	adds r0, r4, r1
	strb r5, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0x16
	movs r2, #0
	bl FUN_08060b84
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #3
	bne _0807BE2C
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807BE28 @ =FUN_080762fc
	b _0807BE48
	.align 2, 0
_0807BE24: .4byte 0x000004A6
_0807BE28: .4byte FUN_080762fc
_0807BE2C:
	cmp r0, #4
	bne _0807BE40
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	ldr r2, _0807BE50 @ =0x00000381
	adds r0, r4, r2
	strb r1, [r0]
_0807BE40:
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807BE54 @ =0x080736B9
_0807BE48:
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807BE50: .4byte 0x00000381
_0807BE54: .4byte 0x080736B9

	thumb_func_start FUN_0807be58
FUN_0807be58: @ 0x0807BE58
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	cmp r1, #0
	blt _0807BE6A
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_0807BE6A:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	ldr r2, _0807BEAC @ =0x000003F6
	adds r0, r4, r2
	strh r5, [r0]
	adds r0, r4, #0
	movs r1, #0x17
	movs r2, #0
	bl FUN_08060b84
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bne _0807BEB4
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807BEB0 @ =FUN_080765a0
	b _0807BED0
	.align 2, 0
_0807BEAC: .4byte 0x000003F6
_0807BEB0: .4byte FUN_080765a0
_0807BEB4:
	cmp r0, #4
	bne _0807BEC8
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	ldr r2, _0807BED8 @ =0x00000381
	adds r0, r4, r2
	strb r1, [r0]
_0807BEC8:
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807BEDC @ =FUN_080738b4
_0807BED0:
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807BED8: .4byte 0x00000381
_0807BEDC: .4byte FUN_080738b4

	thumb_func_start FUN_0807bee0
FUN_0807bee0: @ 0x0807BEE0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	cmp r1, #0
	blt _0807BEF2
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_0807BEF2:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r0, [r2]
	movs r1, #1
	orrs r1, r0
	strb r1, [r2]
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0807BF28
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _0807BF20 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _0807BF24 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	b _0807BF36
	.align 2, 0
_0807BF20: .4byte 0x000002E6
_0807BF24: .4byte 0x000002E7
_0807BF28:
	lsrs r1, r1, #0x19
	ldr r2, _0807BF6C @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _0807BF70 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
_0807BF36:
	strb r0, [r1]
	ldr r1, _0807BF74 @ =0x000004A4
	adds r0, r4, r1
	strh r5, [r0]
	movs r2, #0x96
	lsls r2, r2, #3
	adds r0, r4, r2
	str r3, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0x18
	movs r2, #0
	bl FUN_08060b84
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	bne _0807BF7C
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807BF78 @ =FUN_08075980
	b _0807BF98
	.align 2, 0
_0807BF6C: .4byte 0x000002E6
_0807BF70: .4byte 0x000002E7
_0807BF74: .4byte 0x000004A4
_0807BF78: .4byte FUN_08075980
_0807BF7C:
	cmp r0, #3
	bne _0807BF90
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807BF8C @ =FUN_08076f2c
	b _0807BF98
	.align 2, 0
_0807BF8C: .4byte FUN_08076f2c
_0807BF90:
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807BFA0 @ =FUN_080739e0
_0807BF98:
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807BFA0: .4byte FUN_080739e0

	thumb_func_start FUN_0807bfa4
FUN_0807bfa4: @ 0x0807BFA4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	cmp r1, #0
	blt _0807BFB6
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_0807BFB6:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r0, [r2]
	movs r1, #1
	orrs r1, r0
	strb r1, [r2]
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0807BFEC
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _0807BFE4 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _0807BFE8 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	b _0807BFFA
	.align 2, 0
_0807BFE4: .4byte 0x000002E6
_0807BFE8: .4byte 0x000002E7
_0807BFEC:
	lsrs r1, r1, #0x19
	ldr r2, _0807C034 @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _0807C038 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
_0807BFFA:
	strb r0, [r1]
	ldr r1, _0807C03C @ =0x000004A4
	adds r0, r4, r1
	strh r5, [r0]
	ldr r2, _0807C040 @ =0x000004A6
	adds r0, r4, r2
	strb r3, [r0]
	movs r0, #0x96
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, [sp, #0xc]
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #0
	bl FUN_08060b84
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807C044 @ =FUN_08073b3c
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807C034: .4byte 0x000002E6
_0807C038: .4byte 0x000002E7
_0807C03C: .4byte 0x000004A4
_0807C040: .4byte 0x000004A6
_0807C044: .4byte FUN_08073b3c

	thumb_func_start FUN_0807c048
FUN_0807c048: @ 0x0807C048
	push {lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldr r0, [r2, #0x1c]
	cmp r0, #2
	bne _0807C078
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrh r1, [r0]
	ldr r0, _0807C07C @ =0x00000519
	cmp r1, r0
	bne _0807C078
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r2, r1
	str r3, [r0]
	ldr r0, _0807C080 @ =0x0000037D
	adds r1, r2, r0
	movs r0, #4
	strb r0, [r1]
	adds r0, r2, #0
	bl FUN_0807b7a4
_0807C078:
	pop {r0}
	bx r0
	.align 2, 0
_0807C07C: .4byte 0x00000519
_0807C080: .4byte 0x0000037D

	thumb_func_start FUN_0807c084
FUN_0807c084: @ 0x0807C084
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	cmp r1, #0
	blt _0807C096
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_0807C096:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r0, [r2]
	movs r1, #1
	orrs r1, r0
	strb r1, [r2]
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0807C0CC
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _0807C0C4 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _0807C0C8 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	b _0807C0DA
	.align 2, 0
_0807C0C4: .4byte 0x000002E6
_0807C0C8: .4byte 0x000002E7
_0807C0CC:
	lsrs r1, r1, #0x19
	ldr r2, _0807C10C @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _0807C110 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
_0807C0DA:
	strb r0, [r1]
	ldr r1, _0807C114 @ =0x000004A4
	adds r0, r4, r1
	strh r5, [r0]
	movs r2, #0x96
	lsls r2, r2, #3
	adds r0, r4, r2
	str r3, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0x18
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807C118 @ =FUN_08073e18
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807C10C: .4byte 0x000002E6
_0807C110: .4byte 0x000002E7
_0807C114: .4byte 0x000004A4
_0807C118: .4byte FUN_08073e18

	thumb_func_start FUN_0807c11c
FUN_0807c11c: @ 0x0807C11C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	cmp r1, #0
	blt _0807C12E
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r6, r2
	strb r1, [r0]
_0807C12E:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r6, r0
	ldrb r0, [r2]
	movs r1, #1
	orrs r1, r0
	strb r1, [r2]
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0807C164
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _0807C15C @ =0x000002E6
	adds r1, r6, r2
	strb r0, [r1]
	ldr r0, _0807C160 @ =0x000002E7
	adds r1, r6, r0
	movs r0, #1
	b _0807C172
	.align 2, 0
_0807C15C: .4byte 0x000002E6
_0807C160: .4byte 0x000002E7
_0807C164:
	lsrs r1, r1, #0x19
	ldr r2, _0807C1C8 @ =0x000002E6
	adds r0, r6, r2
	strb r1, [r0]
	ldr r0, _0807C1CC @ =0x000002E7
	adds r1, r6, r0
	movs r0, #0
_0807C172:
	strb r0, [r1]
	adds r0, r6, #0
	bl FUN_0807b7a4
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, #0x2e
	bl FUN_08066ee4
	ldr r2, _0807C1C8 @ =0x000002E6
	adds r1, r6, r2
	ldrb r2, [r1]
	adds r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r4, r6, #0
	adds r4, #0x88
	adds r5, r6, #0
	adds r5, #0x68
	movs r0, #2
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl FUN_082370cc
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_082372cc
	ldr r1, _0807C1CC @ =0x000002E7
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807C1D0
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	b _0807C1DC
	.align 2, 0
_0807C1C8: .4byte 0x000002E6
_0807C1CC: .4byte 0x000002E7
_0807C1D0:
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_0807C1DC:
	str r1, [r0]
	adds r0, r6, #0
	movs r1, #0x18
	movs r2, #2
	bl FUN_08060b84
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r6, r2
	ldr r0, _0807C1FC @ =FUN_08073e18
	str r0, [r1]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807C1FC: .4byte FUN_08073e18

	thumb_func_start FUN_0807c200
FUN_0807c200: @ 0x0807C200
	push {r4, lr}
	adds r4, r0, #0
	cmp r1, #0
	blt _0807C210
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r4, r3
	strb r1, [r0]
_0807C210:
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #7
	movs r2, #0
	bl FUN_08060b84
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #2
	bne _0807C28C
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r4, r3
	ldrb r0, [r2]
	movs r1, #1
	orrs r1, r0
	strb r1, [r2]
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0807C264
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _0807C260 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	subs r3, #1
	adds r1, r4, r3
	movs r0, #1
	b _0807C272
	.align 2, 0
_0807C260: .4byte 0x000002E6
_0807C264:
	lsrs r1, r1, #0x19
	ldr r2, _0807C280 @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _0807C284 @ =0x000002E7
	adds r1, r4, r3
	movs r0, #0
_0807C272:
	strb r0, [r1]
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807C288 @ =FUN_08075134
	b _0807C2F6
	.align 2, 0
_0807C280: .4byte 0x000002E6
_0807C284: .4byte 0x000002E7
_0807C288: .4byte FUN_08075134
_0807C28C:
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrb r0, [r1]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _0807C2A2
	movs r0, #4
	b _0807C2A4
_0807C2A2:
	movs r0, #0
_0807C2A4:
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080609dc
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #3
	bne _0807C2C8
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807C2C4 @ =FUN_0807688c
	b _0807C2F6
	.align 2, 0
_0807C2C4: .4byte FUN_0807688c
_0807C2C8:
	cmp r0, #4
	bne _0807C2DC
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807C2D8 @ =FUN_080773f0
	b _0807C2F6
	.align 2, 0
_0807C2D8: .4byte FUN_080773f0
_0807C2DC:
	ldr r3, _0807C300 @ =0x000002E6
	adds r1, r4, r3
	ldrb r0, [r1]
	lsrs r0, r0, #2
	movs r2, #0
	strb r0, [r1]
	ldr r1, _0807C304 @ =0x000002E7
	adds r0, r4, r1
	strb r2, [r0]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807C308 @ =FUN_0807317c
_0807C2F6:
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807C300: .4byte 0x000002E6
_0807C304: .4byte 0x000002E7
_0807C308: .4byte FUN_0807317c

	thumb_func_start FUN_0807c30c
FUN_0807c30c: @ 0x0807C30C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _0807C32E
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0807c200
_0807C32E:
	cmp r5, #0
	blt _0807C33A
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r5, [r0]
_0807C33A:
	adds r0, r4, #0
	bl FUN_080609dc
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r6, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #7
	movs r2, #7
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807C368 @ =FUN_0807317c
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807C368: .4byte FUN_0807317c

	thumb_func_start FUN_0807c36c
FUN_0807c36c: @ 0x0807C36C
	push {r4, r5, lr}
	adds r4, r0, #0
	cmp r1, #0
	blt _0807C37C
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r4, r3
	strb r1, [r0]
_0807C37C:
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r5, r4, r2
	ldrb r0, [r5]
	cmp r0, #2
	bne _0807C3F8
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r4, r3
	ldrb r0, [r2]
	movs r1, #1
	orrs r1, r0
	strb r1, [r2]
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0807C3C8
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _0807C3C4 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	subs r3, #1
	adds r1, r4, r3
	movs r0, #1
	b _0807C3D6
	.align 2, 0
_0807C3C4: .4byte 0x000002E6
_0807C3C8:
	lsrs r1, r1, #0x19
	ldr r2, _0807C3EC @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _0807C3F0 @ =0x000002E7
	adds r1, r4, r3
	movs r0, #0
_0807C3D6:
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #7
	movs r2, #3
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807C3F4 @ =FUN_08075134
	b _0807C44A
	.align 2, 0
_0807C3EC: .4byte 0x000002E6
_0807C3F0: .4byte 0x000002E7
_0807C3F4: .4byte FUN_08075134
_0807C3F8:
	adds r0, r4, #0
	bl FUN_080609dc
	ldrb r0, [r5]
	cmp r0, #3
	bne _0807C41C
	adds r0, r4, #0
	movs r1, #7
	movs r2, #3
	bl FUN_08060b84
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807C418 @ =FUN_0807688c
	b _0807C44A
	.align 2, 0
_0807C418: .4byte FUN_0807688c
_0807C41C:
	cmp r0, #4
	bne _0807C438
	adds r0, r4, #0
	movs r1, #7
	movs r2, #3
	bl FUN_08060b84
	movs r3, #0x93
	lsls r3, r3, #3
	adds r1, r4, r3
	ldr r0, _0807C434 @ =FUN_080773f0
	b _0807C44A
	.align 2, 0
_0807C434: .4byte FUN_080773f0
_0807C438:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #4
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807C454 @ =FUN_0807317c
_0807C44A:
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807C454: .4byte FUN_0807317c

	thumb_func_start FUN_0807c458
FUN_0807c458: @ 0x0807C458
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	cmp r1, #0
	blt _0807C46A
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_0807C46A:
	adds r0, r4, #0
	bl FUN_080609dc
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r5, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0
	bl FUN_08060b84
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807C498 @ =FUN_08073f88
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807C498: .4byte FUN_08073f88

	thumb_func_start FUN_0807c49c
FUN_0807c49c: @ 0x0807C49C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	cmp r1, #0
	blt _0807C4AE
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_0807C4AE:
	adds r0, r4, #0
	bl FUN_080609dc
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r5, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #3
	movs r2, #2
	bl FUN_08060b84
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807C4DC @ =FUN_08073f88
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807C4DC: .4byte FUN_08073f88

	thumb_func_start FUN_0807c4e0
FUN_0807c4e0: @ 0x0807C4E0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	cmp r1, #0
	blt _0807C4F2
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_0807C4F2:
	adds r0, r4, #0
	bl FUN_080609dc
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r5, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0
	bl FUN_08060b84
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807C520 @ =FUN_080740b0
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807C520: .4byte FUN_080740b0

	thumb_func_start FUN_0807c524
FUN_0807c524: @ 0x0807C524
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	cmp r1, #0
	blt _0807C536
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_0807C536:
	adds r0, r4, #0
	bl FUN_080609dc
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r5, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #3
	movs r2, #2
	bl FUN_08060b84
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807C564 @ =FUN_080740b0
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807C564: .4byte FUN_080740b0

	thumb_func_start FUN_0807c568
FUN_0807c568: @ 0x0807C568
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	cmp r1, #0
	blt _0807C57A
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_0807C57A:
	adds r0, r4, #0
	bl FUN_080609dc
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r5, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0
	bl FUN_08060b84
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807C5A8 @ =0x08074245
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807C5A8: .4byte 0x08074245

	thumb_func_start FUN_0807c5ac
FUN_0807c5ac: @ 0x0807C5AC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	cmp r1, #0
	blt _0807C5BE
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_0807C5BE:
	adds r0, r4, #0
	bl FUN_080609dc
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r5, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #3
	movs r2, #2
	bl FUN_08060b84
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807C5EC @ =0x08074245
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807C5EC: .4byte 0x08074245

	thumb_func_start FUN_0807c5f0
FUN_0807c5f0: @ 0x0807C5F0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	cmp r1, #0
	blt _0807C602
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_0807C602:
	adds r0, r4, #0
	bl FUN_080609dc
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r5, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0
	bl FUN_08060b84
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807C630 @ =FUN_08074350
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807C630: .4byte FUN_08074350

	thumb_func_start FUN_0807c634
FUN_0807c634: @ 0x0807C634
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r4, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _0807C678 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r0, #0x96
	muls r0, r1, r0
	adds r5, r2, #0
	cmp r0, #0
	blt _0807C67C
	asrs r1, r0, #0xc
	b _0807C682
	.align 2, 0
_0807C678: .4byte 0x085B0A08
_0807C67C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0807C682:
	add r0, sp, #0xc
	ldrh r0, [r0]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0807C6B8 @ =0xFFFF0000
	ldr r2, [sp, #0xc]
	ands r2, r1
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0xe6
	lsls r1, r1, #0x10
	ldr r0, _0807C6BC @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	lsls r0, r3, #1
	adds r0, r0, r5
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x96
	muls r0, r1, r0
	cmp r0, #0
	blt _0807C6C0
	asrs r2, r0, #0xc
	b _0807C6C6
	.align 2, 0
_0807C6B8: .4byte 0xFFFF0000
_0807C6BC: .4byte 0x0000FFFF
_0807C6C0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0807C6C6:
	add r0, sp, #0xc
	ldrh r1, [r0, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0807C6F0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	movs r5, #0xd6
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrb r0, [r0]
	cmp r0, #5
	bne _0807C6F8
	ldr r0, _0807C6F4 @ =0x00000203
	bl PlaySound_082406e0
	movs r1, #0x32
	b _0807C700
	.align 2, 0
_0807C6F0: .4byte 0xFFFF0000
_0807C6F4: .4byte 0x00000203
_0807C6F8:
	movs r0, #0xcd
	bl PlaySound_082406e0
	movs r1, #0x2c
_0807C700:
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r3, [r0]
	movs r0, #0x20
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	str r6, [sp, #8]
	add r0, sp, #0xc
	movs r2, #0
	bl FUN_080c0fa0
	movs r5, #0x96
	lsls r5, r5, #3
	adds r0, r4, r5
	str r7, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #3
	movs r2, #2
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807C744 @ =FUN_08074350
	str r0, [r1]
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807C744: .4byte FUN_08074350

	thumb_func_start FUN_0807c748
FUN_0807c748: @ 0x0807C748
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r2, #0
	adds r5, r3, #0
	cmp r1, #0
	blt _0807C75C
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_0807C75C:
	adds r0, r4, #0
	bl FUN_080609dc
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r5, [r0]
	ldr r2, _0807C790 @ =0x000004A7
	adds r0, r4, r2
	strb r6, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807C794 @ =0x080744BD
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807C790: .4byte 0x000004A7
_0807C794: .4byte 0x080744BD

	thumb_func_start FUN_0807c798
FUN_0807c798: @ 0x0807C798
	push {r4, lr}
	adds r4, r0, #0
	movs r2, #0x96
	lsls r2, r2, #3
	adds r0, r4, r2
	str r1, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #3
	movs r2, #5
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r4, r4, r0
	ldr r0, _0807C7C4 @ =0x080744BD
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807C7C4: .4byte 0x080744BD

	thumb_func_start FUN_0807c7c8
FUN_0807c7c8: @ 0x0807C7C8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	cmp r6, #0
	bne _0807C800
	ldr r0, _0807C7F4 @ =0x000004A9
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_080609dc
	ldr r0, _0807C7F8 @ =0x000002E6
	adds r1, r5, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	ldr r1, _0807C7FC @ =0x0000037D
	adds r0, r5, r1
	strb r6, [r0]
	b _0807C856
	.align 2, 0
_0807C7F4: .4byte 0x000004A9
_0807C7F8: .4byte 0x000002E6
_0807C7FC: .4byte 0x0000037D
_0807C800:
	cmp r6, #1
	bne _0807C814
	ldr r0, _0807C810 @ =0x000004A9
	adds r1, r5, r0
	movs r4, #0
	movs r0, #5
	strb r0, [r1]
	b _0807C840
	.align 2, 0
_0807C810: .4byte 0x000004A9
_0807C814:
	cmp r6, #2
	bne _0807C834
	ldr r0, _0807C82C @ =0x000004A7
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	ldr r0, _0807C830 @ =0x0000037D
	adds r1, r5, r0
	movs r0, #5
	strb r0, [r1]
	b _0807C856
	.align 2, 0
_0807C82C: .4byte 0x000004A7
_0807C830: .4byte 0x0000037D
_0807C834:
	cmp r6, #3
	bne _0807C874
	ldr r1, _0807C87C @ =0x000004A9
	adds r0, r5, r1
	movs r4, #0
	strb r6, [r0]
_0807C840:
	adds r0, r5, #0
	bl FUN_080609dc
	ldr r0, _0807C880 @ =0x000002E6
	adds r1, r5, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	ldr r1, _0807C884 @ =0x0000037D
	adds r0, r5, r1
	strb r4, [r0]
_0807C856:
	adds r0, r5, #0
	bl FUN_0807b7a4
	ldr r1, _0807C884 @ =0x0000037D
	adds r0, r5, r1
	ldrb r2, [r0]
	adds r0, r5, #0
	movs r1, #7
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r5, r0
	ldr r0, _0807C888 @ =FUN_08074a40
	str r0, [r1]
_0807C874:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807C87C: .4byte 0x000004A9
_0807C880: .4byte 0x000002E6
_0807C884: .4byte 0x0000037D
_0807C888: .4byte FUN_08074a40

	thumb_func_start FUN_0807c88c
FUN_0807c88c: @ 0x0807C88C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _0807C8CC @ =0x0000049C
	adds r5, r4, r0
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r5]
	str r1, [r5, #4]
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	subs r1, #7
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r4, r4, r0
	ldr r0, _0807C8D0 @ =0x080746ED
	str r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807C8CC: .4byte 0x0000049C
_0807C8D0: .4byte 0x080746ED

	thumb_func_start FUN_0807c8d4
FUN_0807c8d4: @ 0x0807C8D4
	push {r4, lr}
	adds r4, r0, #0
	cmp r1, #0
	blt _0807C8E4
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_0807C8E4:
	adds r0, r4, #0
	bl FUN_080609dc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #1
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x20
	bl FUN_08060a24
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	bl FUN_08060b84
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807C924 @ =0x08074995
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807C924: .4byte 0x08074995

	thumb_func_start FUN_0807c928
FUN_0807c928: @ 0x0807C928
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0807b7a4
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0807C960 @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r4, r4, r0
	ldr r0, _0807C964 @ =FUN_080749b0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807C960: .4byte 0x000002E6
_0807C964: .4byte FUN_080749b0

	thumb_func_start FUN_0807c968
FUN_0807c968: @ 0x0807C968
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0807b7a4
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0807C9A4 @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #2
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r4, r4, r0
	ldr r0, _0807C9A8 @ =FUN_080749b0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807C9A4: .4byte 0x000002E6
_0807C9A8: .4byte FUN_080749b0

	thumb_func_start FUN_0807c9ac
FUN_0807c9ac: @ 0x0807C9AC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	adds r5, r2, #0
	cmp r3, #0
	beq _0807C9DC
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r2, #0
	movs r0, #5
	strb r0, [r1]
	ldr r1, _0807C9D4 @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	ldr r0, _0807C9D8 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _0807C9F2
	.align 2, 0
_0807C9D4: .4byte 0x000002E6
_0807C9D8: .4byte 0x000002E7
_0807C9DC:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #3
	strb r0, [r1]
	ldr r1, _0807CA1C @ =0x000002E6
	adds r0, r4, r1
	strb r3, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r3, [r0]
_0807C9F2:
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r5, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807CA20 @ =FUN_080728a8
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807CA1C: .4byte 0x000002E6
_0807CA20: .4byte FUN_080728a8

	thumb_func_start FUN_0807ca24
FUN_0807ca24: @ 0x0807CA24
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	adds r5, r2, #0
	cmp r3, #0
	beq _0807CA54
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r2, #0
	movs r0, #5
	strb r0, [r1]
	ldr r1, _0807CA4C @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	ldr r0, _0807CA50 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _0807CA6A
	.align 2, 0
_0807CA4C: .4byte 0x000002E6
_0807CA50: .4byte 0x000002E7
_0807CA54:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #3
	strb r0, [r1]
	ldr r1, _0807CA94 @ =0x000002E6
	adds r0, r4, r1
	strb r3, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r3, [r0]
_0807CA6A:
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r5, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0
	movs r2, #3
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807CA98 @ =FUN_080728a8
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807CA94: .4byte 0x000002E6
_0807CA98: .4byte FUN_080728a8

	thumb_func_start FUN_0807ca9c
FUN_0807ca9c: @ 0x0807CA9C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	adds r5, r2, #0
	cmp r3, #0
	beq _0807CACC
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r2, #0
	movs r0, #5
	strb r0, [r1]
	ldr r1, _0807CAC4 @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	ldr r0, _0807CAC8 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _0807CAE2
	.align 2, 0
_0807CAC4: .4byte 0x000002E6
_0807CAC8: .4byte 0x000002E7
_0807CACC:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #3
	strb r0, [r1]
	ldr r1, _0807CB0C @ =0x000002E6
	adds r0, r4, r1
	strb r3, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r3, [r0]
_0807CAE2:
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r5, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0
	movs r2, #4
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807CB10 @ =FUN_080728a8
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807CB0C: .4byte 0x000002E6
_0807CB10: .4byte FUN_080728a8

	thumb_func_start FUN_0807cb14
FUN_0807cb14: @ 0x0807CB14
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	adds r5, r2, #0
	cmp r3, #0
	beq _0807CB44
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r2, #0
	movs r0, #5
	strb r0, [r1]
	ldr r1, _0807CB3C @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	ldr r0, _0807CB40 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _0807CB5A
	.align 2, 0
_0807CB3C: .4byte 0x000002E6
_0807CB40: .4byte 0x000002E7
_0807CB44:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #3
	strb r0, [r1]
	ldr r1, _0807CB84 @ =0x000002E6
	adds r0, r4, r1
	strb r3, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r3, [r0]
_0807CB5A:
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r5, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0
	movs r2, #2
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807CB88 @ =FUN_080728a8
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807CB84: .4byte 0x000002E6
_0807CB88: .4byte FUN_080728a8

	thumb_func_start FUN_0807cb8c
FUN_0807cb8c: @ 0x0807CB8C
	push {r4, lr}
	adds r4, r0, #0
	cmp r1, #0
	blt _0807CB9C
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r4, r3
	strb r1, [r0]
_0807CB9C:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r3, r4, r0
	ldrb r0, [r3]
	movs r1, #1
	orrs r1, r0
	strb r1, [r3]
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0807CBD0
	ldrb r1, [r3]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r3, _0807CBC8 @ =0x000002E6
	adds r1, r4, r3
	strb r0, [r1]
	ldr r0, _0807CBCC @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	b _0807CBDE
	.align 2, 0
_0807CBC8: .4byte 0x000002E6
_0807CBCC: .4byte 0x000002E7
_0807CBD0:
	lsrs r1, r1, #0x19
	ldr r3, _0807CC08 @ =0x000002E6
	adds r0, r4, r3
	strb r1, [r0]
	ldr r0, _0807CC0C @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
_0807CBDE:
	strb r0, [r1]
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	movs r3, #0x93
	lsls r3, r3, #3
	adds r1, r4, r3
	ldr r0, _0807CC10 @ =FUN_080729e0
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807CC08: .4byte 0x000002E6
_0807CC0C: .4byte 0x000002E7
_0807CC10: .4byte FUN_080729e0

	thumb_func_start FUN_0807cc14
FUN_0807cc14: @ 0x0807CC14
	push {r4, lr}
	adds r4, r0, #0
	adds r2, r1, #0
	cmp r2, #0
	beq _0807CC44
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r2, #0
	movs r0, #5
	strb r0, [r1]
	ldr r1, _0807CC3C @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	ldr r0, _0807CC40 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _0807CC5A
	.align 2, 0
_0807CC3C: .4byte 0x000002E6
_0807CC40: .4byte 0x000002E7
_0807CC44:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #3
	strb r0, [r1]
	ldr r1, _0807CC7C @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r2, [r0]
_0807CC5A:
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807CC80 @ =FUN_08072a0c
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807CC7C: .4byte 0x000002E6
_0807CC80: .4byte FUN_08072a0c

	thumb_func_start FUN_0807cc84
FUN_0807cc84: @ 0x0807CC84
	push {r4, lr}
	adds r4, r0, #0
	movs r2, #0x96
	lsls r2, r2, #3
	adds r0, r4, r2
	str r1, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r1, [r0]
	cmp r1, #1
	bls _0807CCEC
	cmp r1, #5
	beq _0807CCEC
	cmp r1, #2
	bne _0807CCC4
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0xc
	movs r2, #0
	bl FUN_08060b84
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807CCC0 @ =FUN_08075b4c
	b _0807CD16
	.align 2, 0
_0807CCC0: .4byte FUN_08075b4c
_0807CCC4:
	cmp r1, #3
	bne _0807CCE8
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0xd
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807CCE4 @ =FUN_08077100
	b _0807CD16
	.align 2, 0
_0807CCE4: .4byte FUN_08077100
_0807CCE8:
	cmp r1, #4
	beq _0807CCF0
_0807CCEC:
	movs r0, #0
	b _0807CD1A
_0807CCF0:
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0xe
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807CD20 @ =FUN_08077a5c
_0807CD16:
	str r0, [r1]
	movs r0, #1
_0807CD1A:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0807CD20: .4byte FUN_08077a5c

	thumb_func_start FUN_0807cd24
FUN_0807cd24: @ 0x0807CD24
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	mov ip, r1
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #2
	bne _0807CD94
	ldr r0, _0807CD80 @ =0x0203B400
	mov r8, r0
	ldr r6, _0807CD84 @ =0x030046B8
	ldr r1, [r6]
	adds r1, #1
	ldr r3, _0807CD88 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	add r0, r8
	ldrh r0, [r0]
	movs r4, #7
	ands r0, r4
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _0807CD8C @ =0xFFFF0000
	ldr r2, [sp]
	ands r2, r5
	orrs r2, r0
	str r2, [sp]
	adds r1, #1
	ands r1, r3
	str r1, [r6]
	lsls r1, r1, #1
	add r1, r8
	ldrh r0, [r1]
	ands r0, r4
	subs r0, #5
	lsls r0, r0, #0x10
	ldr r1, _0807CD90 @ =0x0000FFFF
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	b _0807CE32
	.align 2, 0
_0807CD80: .4byte 0x0203B400
_0807CD84: .4byte 0x030046B8
_0807CD88: .4byte 0x000003FF
_0807CD8C: .4byte 0xFFFF0000
_0807CD90: .4byte 0x0000FFFF
_0807CD94:
	cmp r0, #3
	bne _0807CDF0
	ldr r1, _0807CDDC @ =0x0203B400
	mov r8, r1
	ldr r6, _0807CDE0 @ =0x030046B8
	ldr r1, [r6]
	adds r1, #1
	ldr r3, _0807CDE4 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	add r0, r8
	ldrh r0, [r0]
	movs r4, #7
	ands r0, r4
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _0807CDE8 @ =0xFFFF0000
	ldr r2, [sp]
	ands r2, r5
	orrs r2, r0
	str r2, [sp]
	adds r1, #1
	ands r1, r3
	str r1, [r6]
	lsls r1, r1, #1
	add r1, r8
	ldrh r0, [r1]
	ands r0, r4
	subs r0, #3
	lsls r0, r0, #0x10
	ldr r1, _0807CDEC @ =0x0000FFFF
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	b _0807CE32
	.align 2, 0
_0807CDDC: .4byte 0x0203B400
_0807CDE0: .4byte 0x030046B8
_0807CDE4: .4byte 0x000003FF
_0807CDE8: .4byte 0xFFFF0000
_0807CDEC: .4byte 0x0000FFFF
_0807CDF0:
	ldr r6, _0807CE60 @ =0x0203B400
	ldr r4, _0807CE64 @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r3, _0807CE68 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r2, #0xf
	ands r0, r2
	subs r0, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _0807CE6C @ =0xFFFF0000
	ldr r2, [sp]
	ands r2, r5
	orrs r2, r0
	str r2, [sp]
	adds r1, #1
	ands r1, r3
	str r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	movs r0, #0x1f
	ands r1, r0
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	ldr r0, _0807CE70 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
_0807CE32:
	ldr r0, [sp, #4]
	ands r0, r5
	str r0, [sp, #4]
	ldr r1, _0807CE74 @ =0x000004C4
	adds r0, r7, r1
	movs r2, #0xe1
	lsls r2, r2, #4
	mov r1, ip
	mov r3, sp
	bl FUN_082467d0
	cmp r0, #0
	blt _0807CE9A
	ldr r1, _0807CE78 @ =0x000004C5
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0807CE80
	ldr r0, _0807CE7C @ =0x00000191
	bl PlaySound_082406e0
	b _0807CE9A
	.align 2, 0
_0807CE60: .4byte 0x0203B400
_0807CE64: .4byte 0x030046B8
_0807CE68: .4byte 0x000003FF
_0807CE6C: .4byte 0xFFFF0000
_0807CE70: .4byte 0x0000FFFF
_0807CE74: .4byte 0x000004C4
_0807CE78: .4byte 0x000004C5
_0807CE7C: .4byte 0x00000191
_0807CE80:
	cmp r0, #2
	bne _0807CE90
	ldr r0, _0807CE8C @ =0x00000133
	bl PlaySound_082406e0
	b _0807CE9A
	.align 2, 0
_0807CE8C: .4byte 0x00000133
_0807CE90:
	cmp r0, #3
	bne _0807CE9A
	ldr r0, _0807CEB0 @ =0x00000133
	bl PlaySound_082406e0
_0807CE9A:
	ldr r0, _0807CEB4 @ =0x0000043E
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807CEB0: .4byte 0x00000133
_0807CEB4: .4byte 0x0000043E

	thumb_func_start FUN_0807ceb8
FUN_0807ceb8: @ 0x0807CEB8
	push {lr}
	bl FUN_08063220
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0807cec4
FUN_0807cec4: @ 0x0807CEC4
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	adds r4, r2, #0
	adds r6, r3, #0
	cmp r1, #8
	bls _0807CED4
	b _0807D106
_0807CED4:
	lsls r0, r1, #2
	ldr r1, _0807CEE0 @ =_0807CEE4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807CEE0: .4byte _0807CEE4
_0807CEE4: @ jump table
	.4byte _0807CF08 @ case 0
	.4byte _0807CF4C @ case 1
	.4byte _0807CF80 @ case 2
	.4byte _0807CFC0 @ case 3
	.4byte _0807D004 @ case 4
	.4byte _0807D03C @ case 5
	.4byte _0807D070 @ case 6
	.4byte _0807D0A4 @ case 7
	.4byte _0807D0DC @ case 8
_0807CF08:
	movs r0, #0x99
	lsls r0, r0, #4
	adds r2, r5, r0
	movs r3, #0
	strb r3, [r2]
	ldr r1, _0807CF40 @ =0x00000992
	adds r0, r5, r1
	strh r3, [r0]
	ldr r6, _0807CF44 @ =0x0000098C
	adds r4, r5, r6
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	ldrb r2, [r2]
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	movs r3, #0x50
	str r3, [sp, #0xc]
	movs r3, #1
	bl FUN_080da9c4
	str r0, [r4]
	ldr r0, _0807CF48 @ =0x000001B1
	bl PlaySound_082406e0
	b _0807D106
	.align 2, 0
_0807CF40: .4byte 0x00000992
_0807CF44: .4byte 0x0000098C
_0807CF48: .4byte 0x000001B1
_0807CF4C:
	movs r0, #0x99
	lsls r0, r0, #4
	adds r2, r5, r0
	movs r3, #0
	strb r3, [r2]
	ldr r1, _0807CF78 @ =0x00000992
	adds r0, r5, r1
	strh r3, [r0]
	ldr r6, _0807CF7C @ =0x0000098C
	adds r4, r5, r6
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	ldrb r2, [r2]
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	movs r3, #0x50
	str r3, [sp, #0xc]
	movs r3, #3
	b _0807CFA8
	.align 2, 0
_0807CF78: .4byte 0x00000992
_0807CF7C: .4byte 0x0000098C
_0807CF80:
	movs r0, #0x99
	lsls r0, r0, #4
	adds r2, r5, r0
	movs r3, #0
	strb r3, [r2]
	ldr r1, _0807CFB8 @ =0x00000992
	adds r0, r5, r1
	strh r3, [r0]
	ldr r6, _0807CFBC @ =0x0000098C
	adds r4, r5, r6
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	ldrb r2, [r2]
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	movs r3, #0x50
	str r3, [sp, #0xc]
	movs r3, #0
_0807CFA8:
	bl FUN_080da9c4
	str r0, [r4]
	movs r0, #0xf6
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0807D106
	.align 2, 0
_0807CFB8: .4byte 0x00000992
_0807CFBC: .4byte 0x0000098C
_0807CFC0:
	movs r0, #0x99
	lsls r0, r0, #4
	adds r2, r5, r0
	movs r3, #0
	strb r3, [r2]
	ldr r1, _0807CFF8 @ =0x00000992
	adds r0, r5, r1
	strh r3, [r0]
	ldr r6, _0807CFFC @ =0x0000098C
	adds r4, r5, r6
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	ldrb r2, [r2]
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	movs r3, #0x50
	str r3, [sp, #0xc]
	movs r3, #2
	bl FUN_080da9c4
	str r0, [r4]
	ldr r0, _0807D000 @ =0x000001ED
	bl PlaySound_082406e0
	b _0807D106
	.align 2, 0
_0807CFF8: .4byte 0x00000992
_0807CFFC: .4byte 0x0000098C
_0807D000: .4byte 0x000001ED
_0807D004:
	movs r0, #0x99
	lsls r0, r0, #4
	adds r2, r5, r0
	movs r0, #1
	strb r0, [r2]
	ldr r1, _0807D034 @ =0x00000992
	adds r3, r5, r1
	strh r4, [r3]
	ldr r0, _0807D038 @ =0x0000098C
	adds r4, r5, r0
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	ldrb r2, [r2]
	str r3, [sp]
	lsls r3, r6, #0x10
	asrs r3, r3, #0x10
	str r3, [sp, #4]
	movs r3, #0x96
	str r3, [sp, #8]
	movs r3, #0xe6
	str r3, [sp, #0xc]
	movs r3, #0
	b _0807D100
	.align 2, 0
_0807D034: .4byte 0x00000992
_0807D038: .4byte 0x0000098C
_0807D03C:
	movs r1, #0x99
	lsls r1, r1, #4
	adds r2, r5, r1
	movs r0, #3
	strb r0, [r2]
	ldr r0, _0807D06C @ =0x00000992
	adds r3, r5, r0
	strh r4, [r3]
	subs r1, #4
	adds r4, r5, r1
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	ldrb r2, [r2]
	str r3, [sp]
	lsls r3, r6, #0x10
	asrs r3, r3, #0x10
	str r3, [sp, #4]
	movs r3, #0x96
	str r3, [sp, #8]
	movs r3, #0xe6
	str r3, [sp, #0xc]
	movs r3, #0
	b _0807D100
	.align 2, 0
_0807D06C: .4byte 0x00000992
_0807D070:
	movs r6, #0x99
	lsls r6, r6, #4
	adds r2, r5, r6
	movs r3, #0
	movs r0, #5
	strb r0, [r2]
	ldr r1, _0807D0A0 @ =0x00000992
	adds r0, r5, r1
	strh r3, [r0]
	subs r6, #4
	adds r4, r5, r6
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	ldrb r2, [r2]
	str r3, [sp]
	str r3, [sp, #4]
	movs r3, #0x96
	str r3, [sp, #8]
	movs r3, #0xe6
	str r3, [sp, #0xc]
	movs r3, #0
	b _0807D100
	.align 2, 0
_0807D0A0: .4byte 0x00000992
_0807D0A4:
	movs r0, #0x99
	lsls r0, r0, #4
	adds r2, r5, r0
	movs r3, #0
	movs r0, #4
	strb r0, [r2]
	ldr r1, _0807D0D4 @ =0x00000992
	adds r0, r5, r1
	strh r3, [r0]
	ldr r6, _0807D0D8 @ =0x0000098C
	adds r4, r5, r6
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	ldrb r2, [r2]
	str r3, [sp]
	str r3, [sp, #4]
	movs r3, #0x96
	str r3, [sp, #8]
	movs r3, #0xe6
	str r3, [sp, #0xc]
	movs r3, #0
	b _0807D100
	.align 2, 0
_0807D0D4: .4byte 0x00000992
_0807D0D8: .4byte 0x0000098C
_0807D0DC:
	ldr r1, _0807D110 @ =0x00000992
	adds r0, r5, r1
	movs r3, #0
	strh r3, [r0]
	ldr r6, _0807D114 @ =0x0000098C
	adds r4, r5, r6
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	adds r6, #4
	adds r2, r5, r6
	ldrb r2, [r2]
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	movs r3, #0x50
	str r3, [sp, #0xc]
	movs r3, #0x7f
_0807D100:
	bl FUN_080da9c4
	str r0, [r4]
_0807D106:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807D110: .4byte 0x00000992
_0807D114: .4byte 0x0000098C

	thumb_func_start FUN_0807d118
FUN_0807d118: @ 0x0807D118
	push {lr}
	adds r2, r0, #0
	movs r0, #0xdf
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #6
	beq _0807D12C
	movs r0, #0
	strb r0, [r1]
_0807D12C:
	ldr r1, _0807D158 @ =0x0000037D
	adds r0, r2, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0807D15C @ =0x0000037E
	adds r0, r2, r3
	movs r3, #0
	strh r1, [r0]
	movs r0, #0x95
	lsls r0, r0, #3
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0807D14A
	strb r3, [r1]
_0807D14A:
	movs r0, #1
	str r0, [r2, #0x1c]
	ldr r1, _0807D160 @ =0x00000395
	adds r0, r2, r1
	strb r3, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0807D158: .4byte 0x0000037D
_0807D15C: .4byte 0x0000037E
_0807D160: .4byte 0x00000395

	thumb_func_start FUN_0807d164
FUN_0807d164: @ 0x0807D164
	push {lr}
	movs r0, #0x64
	bl prepare_08231510
	cmp r0, #0
	bne _0807D176
	movs r0, #1
	rsbs r0, r0, #0
	b _0807D17A
_0807D176:
	bl fetch_082316e4
_0807D17A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0807d180
FUN_0807d180: @ 0x0807D180
	push {lr}
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	bne _0807D190
	movs r0, #0
	b _0807D194
_0807D190:
	bl fetch_082316e4
_0807D194:
	pop {r1}
	bx r1

	thumb_func_start FUN_0807d198
FUN_0807d198: @ 0x0807D198
	push {r4, lr}
	bl FUN_0807afe8
	ldr r1, _0807D1BC @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0807D1B6
	adds r0, r4, #0
	bl FUN_0807b8dc
	adds r0, r4, #0
	bl FUN_08072640
_0807D1B6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807D1BC: .4byte 0x03002BE0

	thumb_func_start FUN_0807d1c0
FUN_0807d1c0: @ 0x0807D1C0
	push {r4, lr}
	bl FUN_0807afe8
	ldr r1, _0807D1F8 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0807D1F2
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0807D1F2
	bl fetch_082316e4
	adds r1, r0, #0
	ldr r0, _0807D1FC @ =0x00000121
	adds r1, r1, r0
	adds r0, r4, #0
	bl FUN_0807b890
	adds r0, r4, #0
	bl FUN_08072640
_0807D1F2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807D1F8: .4byte 0x03002BE0
_0807D1FC: .4byte 0x00000121

	thumb_func_start FUN_0807d200
FUN_0807d200: @ 0x0807D200
	push {r4, lr}
	bl FUN_0807afe8
	ldr r1, _0807D238 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0807D232
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0807D232
	bl fetch_082316e4
	adds r1, r0, #0
	ldr r0, _0807D23C @ =0x00000121
	adds r1, r1, r0
	adds r0, r4, #0
	bl FUN_0807b8a8
	adds r0, r4, #0
	bl FUN_08072640
_0807D232:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807D238: .4byte 0x03002BE0
_0807D23C: .4byte 0x00000121

	thumb_func_start FUN_0807d240
FUN_0807d240: @ 0x0807D240
	push {r4, lr}
	bl FUN_0807afe8
	ldr r1, _0807D264 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0807D25E
	adds r0, r4, #0
	bl FUN_0807b8c0
	adds r0, r4, #0
	bl FUN_08072640
_0807D25E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807D264: .4byte 0x03002BE0

	thumb_func_start FUN_0807d268
FUN_0807d268: @ 0x0807D268
	push {r4, lr}
	bl FUN_0807afe8
	ldr r1, _0807D294 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0807D28C
	bl FUN_0807d164
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_0807b910
	adds r0, r4, #0
	bl FUN_08072640
_0807D28C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807D294: .4byte 0x03002BE0

	thumb_func_start FUN_0807d298
FUN_0807d298: @ 0x0807D298
	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807D2CC @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807D2C4
	bl FUN_0807d164
	adds r4, r0, #0
	bl FUN_0807d180
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0807b9dc
	adds r0, r5, #0
	bl FUN_08072640
_0807D2C4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807D2CC: .4byte 0x03002BE0

	thumb_func_start FUN_0807d2d0
FUN_0807d2d0: @ 0x0807D2D0
	push {r4, lr}
	bl FUN_0807afe8
	ldr r1, _0807D2FC @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0807D2F4
	bl FUN_0807d164
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_0807ba14
	adds r0, r4, #0
	bl FUN_08072640
_0807D2F4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807D2FC: .4byte 0x03002BE0

	thumb_func_start FUN_0807d300
FUN_0807d300: @ 0x0807D300
	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807D334 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807D32C
	bl FUN_0807d164
	adds r4, r0, #0
	bl FUN_0807d180
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0807ba50
	adds r0, r5, #0
	bl FUN_08072640
_0807D32C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807D334: .4byte 0x03002BE0

	thumb_func_start FUN_0807d338
FUN_0807d338: @ 0x0807D338
	push {r4, r5, lr}
	sub sp, #8
	bl FUN_0807afe8
	ldr r1, _0807D3AC @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807D3A4
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0807D3A4
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0807D3B0 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	ldr r2, _0807D3B4 @ =0x0000FFFF
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl FUN_0807d164
	adds r4, r0, #0
	bl FUN_0807d180
	adds r2, r0, #0
	adds r0, r5, #0
	mov r1, sp
	adds r3, r4, #0
	bl FUN_0807ba94
	adds r0, r5, #0
	bl FUN_08072640
_0807D3A4:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807D3AC: .4byte 0x03002BE0
_0807D3B0: .4byte 0xFFFF0000
_0807D3B4: .4byte 0x0000FFFF

	thumb_func_start FUN_0807d3b8
FUN_0807d3b8: @ 0x0807D3B8
	push {r4, r5, lr}
	sub sp, #8
	bl FUN_0807afe8
	ldr r1, _0807D42C @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807D424
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0807D424
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0807D430 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	ldr r2, _0807D434 @ =0x0000FFFF
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl FUN_0807d164
	adds r4, r0, #0
	bl FUN_0807d180
	adds r3, r0, #0
	adds r0, r5, #0
	mov r1, sp
	adds r2, r4, #0
	bl FUN_0807c88c
	adds r0, r5, #0
	bl FUN_08072640
_0807D424:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807D42C: .4byte 0x03002BE0
_0807D430: .4byte 0xFFFF0000
_0807D434: .4byte 0x0000FFFF

	thumb_func_start FUN_0807d438
FUN_0807d438: @ 0x0807D438
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	bl FUN_0807afe8
	ldr r1, _0807D464 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r6, [r0]
	cmp r6, #0
	beq _0807D4E0
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _0807D468
	bl fetch_082316e4
	adds r5, r0, #0
	b _0807D46A
	.align 2, 0
_0807D464: .4byte 0x03002BE0
_0807D468:
	movs r5, #0
_0807D46A:
	bl FUN_0807d164
	mov r8, r0
	bl FUN_0807d180
	adds r7, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0807D4CC
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0807D4C4 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	ldr r2, _0807D4C8 @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	str r7, [sp]
	adds r0, r6, #0
	add r1, sp, #4
	mov r2, r8
	adds r3, r5, #0
	bl FUN_0807bb3c
	b _0807D4DA
	.align 2, 0
_0807D4C4: .4byte 0xFFFF0000
_0807D4C8: .4byte 0x0000FFFF
_0807D4CC:
	str r7, [sp]
	adds r0, r6, #0
	movs r1, #0
	mov r2, r8
	adds r3, r5, #0
	bl FUN_0807bb3c
_0807D4DA:
	adds r0, r6, #0
	bl FUN_08072640
_0807D4E0:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0807d4ec
FUN_0807d4ec: @ 0x0807D4EC
	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807D528 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0807D55A
	bl FUN_0807d180
	adds r5, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	bls _0807D514
	cmp r0, #5
	bne _0807D53E
_0807D514:
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _0807D52C
	bl fetch_082316e4
	adds r1, r0, #0
	b _0807D52E
	.align 2, 0
_0807D528: .4byte 0x03002BE0
_0807D52C:
	movs r1, #0
_0807D52E:
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0807bbb0
	adds r0, r4, #0
	bl FUN_08072640
	b _0807D55A
_0807D53E:
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r5, [r0]
	adds r0, r4, #0
	movs r1, #4
	bl FUN_0807b910
	adds r0, r4, #0
	bl FUN_08072640
	adds r0, r4, #0
	bl FUN_08072650
_0807D55A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0807d560
FUN_0807d560: @ 0x0807D560
	push {r4, lr}
	bl FUN_0807afe8
	ldr r1, _0807D58C @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0807D584
	bl FUN_0807d180
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_0807bc64
	adds r0, r4, #0
	bl FUN_08072640
_0807D584:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807D58C: .4byte 0x03002BE0

	thumb_func_start FUN_0807d590
FUN_0807d590: @ 0x0807D590
	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807D5C4 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807D5BC
	bl FUN_0807d164
	adds r4, r0, #0
	bl FUN_0807d180
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0807bcb0
	adds r0, r5, #0
	bl FUN_08072640
_0807D5BC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807D5C4: .4byte 0x03002BE0

	thumb_func_start FUN_0807d5c8
FUN_0807d5c8: @ 0x0807D5C8
	push {r4, lr}
	bl FUN_0807afe8
	ldr r1, _0807D5F4 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0807D5EC
	bl FUN_0807d164
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_0807bcfc
	adds r0, r4, #0
	bl FUN_08072640
_0807D5EC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807D5F4: .4byte 0x03002BE0

	thumb_func_start FUN_0807d5f8
FUN_0807d5f8: @ 0x0807D5F8
	push {r4, lr}
	bl FUN_0807afe8
	ldr r1, _0807D624 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0807D61C
	bl FUN_0807d164
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_0807bd44
	adds r0, r4, #0
	bl FUN_08072640
_0807D61C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807D624: .4byte 0x03002BE0

	thumb_func_start FUN_0807d628
FUN_0807d628: @ 0x0807D628
	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807D65C @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807D654
	bl FUN_0807d164
	adds r4, r0, #0
	bl FUN_0807d180
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0807bd84
	adds r0, r5, #0
	bl FUN_08072640
_0807D654:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807D65C: .4byte 0x03002BE0

	thumb_func_start FUN_0807d660
FUN_0807d660: @ 0x0807D660
	push {r4, r5, r6, lr}
	bl FUN_0807afe8
	ldr r1, _0807D690 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0807D6A0
	bl FUN_0807d164
	adds r5, r0, #0
	bl FUN_0807d180
	adds r6, r0, #0
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _0807D694
	bl fetch_082316e4
	adds r2, r0, #0
	b _0807D696
	.align 2, 0
_0807D690: .4byte 0x03002BE0
_0807D694:
	movs r2, #0
_0807D696:
	adds r0, r4, #0
	adds r1, r5, #0
	adds r3, r6, #0
	bl FUN_0807bdc8
_0807D6A0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0807d6a8
FUN_0807d6a8: @ 0x0807D6A8
	push {r4, r5, r6, lr}
	bl FUN_0807afe8
	ldr r1, _0807D6D8 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0807D6EE
	bl FUN_0807d164
	adds r5, r0, #0
	bl FUN_0807d180
	adds r6, r0, #0
	movs r0, #0x68
	bl prepare_08231510
	cmp r0, #0
	beq _0807D6DC
	bl fetch_082316e4
	adds r2, r0, #0
	b _0807D6DE
	.align 2, 0
_0807D6D8: .4byte 0x03002BE0
_0807D6DC:
	ldr r2, _0807D6F4 @ =0x000005DC
_0807D6DE:
	adds r0, r4, #0
	adds r1, r5, #0
	adds r3, r6, #0
	bl FUN_0807be58
	adds r0, r4, #0
	bl FUN_08072640
_0807D6EE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807D6F4: .4byte 0x000005DC

	thumb_func_start FUN_0807d6f8
FUN_0807d6f8: @ 0x0807D6F8
	push {r4, r5, r6, lr}
	bl FUN_0807afe8
	ldr r1, _0807D71C @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807D73E
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _0807D720
	bl fetch_082316e4
	adds r6, r0, #0
	b _0807D722
	.align 2, 0
_0807D71C: .4byte 0x03002BE0
_0807D720:
	movs r6, #0x1e
_0807D722:
	bl FUN_0807d164
	adds r4, r0, #0
	bl FUN_0807d180
	adds r3, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl FUN_0807bee0
	adds r0, r5, #0
	bl FUN_08072640
_0807D73E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0807d744
FUN_0807d744: @ 0x0807D744
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	bl FUN_0807afe8
	ldr r1, _0807D76C @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807D7A4
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _0807D770
	bl fetch_082316e4
	adds r7, r0, #0
	b _0807D772
	.align 2, 0
_0807D76C: .4byte 0x03002BE0
_0807D770:
	movs r7, #0x32
_0807D772:
	movs r0, #0x4c
	bl prepare_08231510
	cmp r0, #0
	beq _0807D784
	bl fetch_082316e4
	adds r6, r0, #0
	b _0807D786
_0807D784:
	movs r6, #0
_0807D786:
	bl FUN_0807d164
	adds r4, r0, #0
	bl FUN_0807d180
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r7, #0
	adds r3, r6, #0
	bl FUN_0807bfa4
	adds r0, r5, #0
	bl FUN_08072640
_0807D7A4:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0807d7ac
FUN_0807d7ac: @ 0x0807D7AC
	push {r4, lr}
	bl FUN_0807afe8
	ldr r1, _0807D7D8 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0807D7D0
	bl FUN_0807d180
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_0807c048
	adds r0, r4, #0
	bl FUN_08072640
_0807D7D0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807D7D8: .4byte 0x03002BE0

	thumb_func_start FUN_0807d7dc
FUN_0807d7dc: @ 0x0807D7DC
	push {r4, r5, r6, lr}
	bl FUN_0807afe8
	ldr r1, _0807D800 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807D822
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _0807D804
	bl fetch_082316e4
	adds r6, r0, #0
	b _0807D806
	.align 2, 0
_0807D800: .4byte 0x03002BE0
_0807D804:
	movs r6, #0x32
_0807D806:
	bl FUN_0807d164
	adds r4, r0, #0
	bl FUN_0807d180
	adds r3, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl FUN_0807c084
	adds r0, r5, #0
	bl FUN_08072640
_0807D822:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0807d828
FUN_0807d828: @ 0x0807D828
	push {r4, lr}
	bl FUN_0807afe8
	ldr r1, _0807D854 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0807D84C
	bl FUN_0807d164
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_0807c11c
	adds r0, r4, #0
	bl FUN_08072640
_0807D84C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807D854: .4byte 0x03002BE0

	thumb_func_start FUN_0807d858
FUN_0807d858: @ 0x0807D858
	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807D88C @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807D884
	bl FUN_0807d164
	adds r4, r0, #0
	bl FUN_0807d180
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0807c200
	adds r0, r5, #0
	bl FUN_08072640
_0807D884:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807D88C: .4byte 0x03002BE0

	thumb_func_start FUN_0807d890
FUN_0807d890: @ 0x0807D890
	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807D8C4 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807D8BC
	bl FUN_0807d164
	adds r4, r0, #0
	bl FUN_0807d180
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0807c36c
	adds r0, r5, #0
	bl FUN_08072640
_0807D8BC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807D8C4: .4byte 0x03002BE0

	thumb_func_start FUN_0807d8c8
FUN_0807d8c8: @ 0x0807D8C8
	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807D8FC @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807D8F4
	bl FUN_0807d164
	adds r4, r0, #0
	bl FUN_0807d180
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0807c458
	adds r0, r5, #0
	bl FUN_08072640
_0807D8F4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807D8FC: .4byte 0x03002BE0

	thumb_func_start FUN_0807d900
FUN_0807d900: @ 0x0807D900
	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807D934 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807D92C
	bl FUN_0807d164
	adds r4, r0, #0
	bl FUN_0807d180
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0807c49c
	adds r0, r5, #0
	bl FUN_08072640
_0807D92C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807D934: .4byte 0x03002BE0

	thumb_func_start FUN_0807d938
FUN_0807d938: @ 0x0807D938
	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807D96C @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807D964
	bl FUN_0807d164
	adds r4, r0, #0
	bl FUN_0807d180
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0807c4e0
	adds r0, r5, #0
	bl FUN_08072640
_0807D964:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807D96C: .4byte 0x03002BE0

	thumb_func_start FUN_0807d970
FUN_0807d970: @ 0x0807D970
	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807D9A4 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807D99C
	bl FUN_0807d164
	adds r4, r0, #0
	bl FUN_0807d180
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0807c524
	adds r0, r5, #0
	bl FUN_08072640
_0807D99C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807D9A4: .4byte 0x03002BE0

	thumb_func_start FUN_0807d9a8
FUN_0807d9a8: @ 0x0807D9A8
	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807D9DC @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807D9D4
	bl FUN_0807d164
	adds r4, r0, #0
	bl FUN_0807d180
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0807c568
	adds r0, r5, #0
	bl FUN_08072640
_0807D9D4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807D9DC: .4byte 0x03002BE0

	thumb_func_start FUN_0807d9e0
FUN_0807d9e0: @ 0x0807D9E0
	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807DA14 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807DA0C
	bl FUN_0807d164
	adds r4, r0, #0
	bl FUN_0807d180
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0807c5ac
	adds r0, r5, #0
	bl FUN_08072640
_0807DA0C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807DA14: .4byte 0x03002BE0

	thumb_func_start FUN_0807da18
FUN_0807da18: @ 0x0807DA18
	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807DA4C @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807DA44
	bl FUN_0807d164
	adds r4, r0, #0
	bl FUN_0807d180
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0807c5f0
	adds r0, r5, #0
	bl FUN_08072640
_0807DA44:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807DA4C: .4byte 0x03002BE0

	thumb_func_start FUN_0807da50
FUN_0807da50: @ 0x0807DA50
	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807DA74 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807DA8E
	movs r0, #0x6c
	bl prepare_08231510
	cmp r0, #0
	beq _0807DA78
	bl fetch_082316e4
	adds r4, r0, #0
	b _0807DA7A
	.align 2, 0
_0807DA74: .4byte 0x03002BE0
_0807DA78:
	movs r4, #0x20
_0807DA7A:
	bl FUN_0807d180
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0807c634
	adds r0, r5, #0
	bl FUN_08072640
_0807DA8E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0807da94
FUN_0807da94: @ 0x0807DA94
	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807DACC @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807DAC4
	bl FUN_0807d180
	adds r1, r0, #0
	adds r0, r5, #0
	bl FUN_0807cc84
	adds r4, r0, #0
	adds r0, r5, #0
	bl FUN_08072640
	cmp r4, #0
	bne _0807DAC4
	adds r0, r5, #0
	bl FUN_08072650
_0807DAC4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807DACC: .4byte 0x03002BE0

	thumb_func_start FUN_0807dad0
FUN_0807dad0: @ 0x0807DAD0
	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807DAF4 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807DB0E
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _0807DAF8
	bl fetch_082316e4
	adds r4, r0, #0
	b _0807DAFA
	.align 2, 0
_0807DAF4: .4byte 0x03002BE0
_0807DAF8:
	movs r4, #0
_0807DAFA:
	bl FUN_0807d180
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0807c9ac
	adds r0, r5, #0
	bl FUN_08072640
_0807DB0E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0807db14
FUN_0807db14: @ 0x0807DB14
	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807DB38 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807DB52
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _0807DB3C
	bl fetch_082316e4
	adds r4, r0, #0
	b _0807DB3E
	.align 2, 0
_0807DB38: .4byte 0x03002BE0
_0807DB3C:
	movs r4, #0
_0807DB3E:
	bl FUN_0807d180
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0807ca24
	adds r0, r5, #0
	bl FUN_08072640
_0807DB52:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0807db58
FUN_0807db58: @ 0x0807DB58
	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807DB7C @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807DB96
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _0807DB80
	bl fetch_082316e4
	adds r4, r0, #0
	b _0807DB82
	.align 2, 0
_0807DB7C: .4byte 0x03002BE0
_0807DB80:
	movs r4, #0
_0807DB82:
	bl FUN_0807d180
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0807ca9c
	adds r0, r5, #0
	bl FUN_08072640
_0807DB96:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0807db9c
FUN_0807db9c: @ 0x0807DB9C
	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807DBC0 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807DBDA
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _0807DBC4
	bl fetch_082316e4
	adds r4, r0, #0
	b _0807DBC6
	.align 2, 0
_0807DBC0: .4byte 0x03002BE0
_0807DBC4:
	movs r4, #0
_0807DBC6:
	bl FUN_0807d180
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0807cb14
	adds r0, r5, #0
	bl FUN_08072640
_0807DBDA:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0807dbe0
FUN_0807dbe0: @ 0x0807DBE0
	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807DC04 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807DC1E
	movs r0, #0x64
	bl prepare_08231510
	cmp r0, #0
	beq _0807DC08
	bl fetch_082316e4
	adds r4, r0, #0
	b _0807DC0A
	.align 2, 0
_0807DC04: .4byte 0x03002BE0
_0807DC08:
	movs r4, #0
_0807DC0A:
	bl FUN_0807d180
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0807cb8c
	adds r0, r5, #0
	bl FUN_08072640
_0807DC1E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0807dc24
FUN_0807dc24: @ 0x0807DC24
	push {r4, lr}
	bl FUN_0807afe8
	ldr r1, _0807DC48 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0807DC5A
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _0807DC4C
	bl fetch_082316e4
	adds r1, r0, #0
	b _0807DC4E
	.align 2, 0
_0807DC48: .4byte 0x03002BE0
_0807DC4C:
	movs r1, #0
_0807DC4E:
	adds r0, r4, #0
	bl FUN_0807cc14
	adds r0, r4, #0
	bl FUN_08072640
_0807DC5A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0807dc60
FUN_0807dc60: @ 0x0807DC60
	push {r4, r5, r6, lr}
	bl FUN_0807afe8
	ldr r1, _0807DC9C @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r6, [r0]
	cmp r6, #0
	beq _0807DCC6
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _0807DCC6
	bl fetch_082316e4
	adds r5, r0, #0
	subs r0, r5, #4
	cmp r0, #1
	bhi _0807DCB8
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	beq _0807DCA0
	bl fetch_082316e4
	adds r4, r0, #0
	b _0807DCA2
	.align 2, 0
_0807DC9C: .4byte 0x03002BE0
_0807DCA0:
	movs r4, #0x78
_0807DCA2:
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _0807DCB4
	bl fetch_082316e4
	adds r3, r0, #0
	b _0807DCBC
_0807DCB4:
	movs r3, #0x78
	b _0807DCBC
_0807DCB8:
	movs r3, #0
	movs r4, #0
_0807DCBC:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0807cec4
_0807DCC6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0807dccc
FUN_0807dccc: @ 0x0807DCCC
	push {lr}
	bl FUN_0807afe8
	ldr r1, _0807DCE8 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0807DCE2
	bl FUN_0807d118
_0807DCE2:
	pop {r0}
	bx r0
	.align 2, 0
_0807DCE8: .4byte 0x03002BE0

	thumb_func_start FUN_0807dcec
FUN_0807dcec: @ 0x0807DCEC
	push {r4, lr}
	bl FUN_0807afe8
	ldr r1, _0807DD14 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0807DDB2
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _0807DD1C
	bl fetch_082316e4
	ldr r2, _0807DD18 @ =0x00000434
	adds r1, r4, r2
	b _0807DD24
	.align 2, 0
_0807DD14: .4byte 0x03002BE0
_0807DD18: .4byte 0x00000434
_0807DD1C:
	ldr r0, _0807DD44 @ =0x00000434
	adds r1, r4, r0
	movs r0, #0x96
	lsls r0, r0, #2
_0807DD24:
	strh r0, [r1]
	ldr r1, _0807DD44 @ =0x00000434
	adds r0, r4, r1
	bl FUN_0809c544
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	beq _0807DD48
	bl fetch_082316e4
	movs r2, #0x87
	lsls r2, r2, #3
	adds r1, r4, r2
	b _0807DD52
	.align 2, 0
_0807DD44: .4byte 0x00000434
_0807DD48:
	movs r0, #0x87
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0xb4
	lsls r0, r0, #2
_0807DD52:
	strh r0, [r1]
	ldr r2, _0807DDA0 @ =0x00000436
	adds r1, r4, r2
	movs r0, #0
	strh r0, [r1]
	bl FUN_0807d180
	movs r2, #0x96
	lsls r2, r2, #3
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #4
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #7
	movs r2, #0
	bl FUN_08060b84
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _0807DDA8
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807DDA4 @ =FUN_08078060
	b _0807DDB0
	.align 2, 0
_0807DDA0: .4byte 0x00000436
_0807DDA4: .4byte FUN_08078060
_0807DDA8:
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807DDB8 @ =FUN_08077cbc
_0807DDB0:
	str r0, [r1]
_0807DDB2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807DDB8: .4byte FUN_08077cbc

	thumb_func_start FUN_0807ddbc
FUN_0807ddbc: @ 0x0807DDBC
	push {lr}
	movs r1, #0x8c
	lsls r1, r1, #2
	adds r2, r0, r1
	ldrh r1, [r0, #0x24]
	adds r0, r2, #0
	movs r2, #2
	bl FUN_080223f4
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0807ddd4
FUN_0807ddd4: @ 0x0807DDD4
	push {lr}
	movs r1, #0x8c
	lsls r1, r1, #2
	adds r0, r0, r1
	bl FUN_08022428
	pop {r0}
	bx r0

	thumb_func_start FUN_0807dde4
FUN_0807dde4: @ 0x0807DDE4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	movs r0, #0x8c
	lsls r0, r0, #2
	adds r7, r5, r0
	movs r6, #0
	ldr r0, _0807DE00 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	ldr r2, _0807DE04 @ =0x00000236
	adds r0, r5, r2
	b _0807E260
	.align 2, 0
_0807DE00: .4byte 0x03002B4C
_0807DE04: .4byte 0x00000236
_0807DE08:
	ldr r0, _0807DE38 @ =0x03002B4C
	ldr r0, [r0]
	lsls r1, r6, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r7, #0
	adds r0, #8
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_08022474
	ldrb r0, [r4, #6]
	cmp r0, #0x2c
	bls _0807DE2E
	b _0807E256
_0807DE2E:
	lsls r0, r0, #2
	ldr r1, _0807DE3C @ =_0807DE40
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807DE38: .4byte 0x03002B4C
_0807DE3C: .4byte _0807DE40
_0807DE40: @ jump table
	.4byte _0807DEF4 @ case 0
	.4byte _0807DEFC @ case 1
	.4byte _0807DF30 @ case 2
	.4byte _0807DF3C @ case 3
	.4byte _0807DF4A @ case 4
	.4byte _0807DF56 @ case 5
	.4byte _0807DF64 @ case 6
	.4byte _0807DFA0 @ case 7
	.4byte _0807DFAE @ case 8
	.4byte _0807DFBC @ case 9
	.4byte _0807DFC6 @ case 10
	.4byte _0807DFD4 @ case 11
	.4byte _0807DFE0 @ case 12
	.4byte _0807DFEC @ case 13
	.4byte _0807DFFA @ case 14
	.4byte _0807E00E @ case 15
	.4byte _0807E020 @ case 16
	.4byte _0807E038 @ case 17
	.4byte _0807E042 @ case 18
	.4byte _0807E054 @ case 19
	.4byte _0807E070 @ case 20
	.4byte _0807E062 @ case 21
	.4byte _0807E07E @ case 22
	.4byte _0807E08C @ case 23
	.4byte _0807E09A @ case 24
	.4byte _0807E0AC @ case 25
	.4byte _0807E15A @ case 26
	.4byte _0807E0B6 @ case 27
	.4byte _0807E1EC @ case 28
	.4byte _0807E0CE @ case 29
	.4byte _0807E108 @ case 30
	.4byte _0807E114 @ case 31
	.4byte _0807E13E @ case 32
	.4byte _0807E122 @ case 33
	.4byte _0807E130 @ case 34
	.4byte _0807E14C @ case 35
	.4byte _0807E166 @ case 36
	.4byte _0807E170 @ case 37
	.4byte _0807E180 @ case 38
	.4byte _0807E18A @ case 39
	.4byte _0807E1C4 @ case 40
	.4byte _0807E1D0 @ case 41
	.4byte _0807E1A8 @ case 42
	.4byte _0807E192 @ case 43
	.4byte _0807E1BC @ case 44
_0807DEF4:
	adds r0, r5, #0
	bl FUN_0807b8dc
	b _0807E1D8
_0807DEFC:
	ldrh r0, [r4, #8]
	ldr r3, _0807DF28 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #4]
	ldrh r2, [r4, #0xa]
	lsls r2, r2, #0x10
	ldr r0, _0807DF2C @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #4]
	ldrh r1, [r4, #0xc]
	ldr r0, [sp, #8]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #8]
	adds r0, r5, #0
	add r1, sp, #4
	bl FUN_0807b8d0
	b _0807E1D8
	.align 2, 0
_0807DF28: .4byte 0xFFFF0000
_0807DF2C: .4byte 0x0000FFFF
_0807DF30:
	movs r0, #8
	ldrsh r1, [r4, r0]
	adds r0, r5, #0
	bl FUN_0807b910
	b _0807E1D8
_0807DF3C:
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807b9dc
	b _0807E178
_0807DF4A:
	movs r0, #8
	ldrsh r1, [r4, r0]
	adds r0, r5, #0
	bl FUN_0807ba14
	b _0807E1D8
_0807DF56:
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807ba50
	b _0807E178
_0807DF64:
	ldrh r0, [r4, #8]
	ldr r3, _0807DF98 @ =0xFFFF0000
	ldr r1, [sp, #0xc]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0xc]
	ldrh r2, [r4, #0xa]
	lsls r2, r2, #0x10
	ldr r0, _0807DF9C @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0xc]
	ldrh r2, [r4, #0xc]
	add r1, sp, #0xc
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	movs r3, #1
	rsbs r3, r3, #0
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807ba94
	b _0807E178
	.align 2, 0
_0807DF98: .4byte 0xFFFF0000
_0807DF9C: .4byte 0x0000FFFF
_0807DFA0:
	movs r0, #8
	ldrsh r1, [r4, r0]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807bbb0
	b _0807E178
_0807DFAE:
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807bc14
	b _0807E178
_0807DFBC:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0807bc64
	b _0807E178
_0807DFC6:
	movs r0, #8
	ldrsh r1, [r4, r0]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807bcb0
	b _0807E178
_0807DFD4:
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r5, #0
	bl FUN_0807bd44
	b _0807E1D8
_0807DFE0:
	movs r0, #8
	ldrsh r1, [r4, r0]
	adds r0, r5, #0
	bl FUN_0807bcfc
	b _0807E1D8
_0807DFEC:
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807bd84
	b _0807E178
_0807DFFA:
	movs r0, #8
	ldrsh r2, [r4, r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0807bb3c
	b _0807E1D8
_0807E00E:
	movs r2, #8
	ldrsh r1, [r4, r2]
	movs r0, #0xa
	ldrsh r2, [r4, r0]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0807bee0
	b _0807E178
_0807E020:
	movs r2, #8
	ldrsh r1, [r4, r2]
	movs r0, #0xa
	ldrsh r2, [r4, r0]
	movs r0, #0xc
	ldrsh r3, [r4, r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	bl FUN_0807bfa4
	b _0807E178
_0807E038:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0807c048
	b _0807E178
_0807E042:
	movs r2, #8
	ldrsh r1, [r4, r2]
	movs r0, #0xa
	ldrsh r2, [r4, r0]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0807c084
	b _0807E178
_0807E054:
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807c200
	b _0807E178
_0807E062:
	movs r0, #8
	ldrsh r1, [r4, r0]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807c36c
	b _0807E178
_0807E070:
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807c30c
	b _0807E178
_0807E07E:
	movs r0, #8
	ldrsh r1, [r4, r0]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807c5f0
	b _0807E178
_0807E08C:
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807c634
	b _0807E178
_0807E09A:
	movs r0, #8
	ldrsh r1, [r4, r0]
	movs r0, #0xa
	ldrsh r2, [r4, r0]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0807c748
	b _0807E178
_0807E0AC:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0807c798
	b _0807E178
_0807E0B6:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0807cc84
	adds r4, r0, #0
	adds r0, r5, #0
	bl FUN_08072670
	cmp r4, #0
	beq _0807E0CC
	b _0807E256
_0807E0CC:
	b _0807E1DE
_0807E0CE:
	ldrh r0, [r4, #8]
	ldr r3, _0807E100 @ =0xFFFF0000
	ldr r1, [sp, #0x14]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x14]
	ldrh r2, [r4, #0xa]
	lsls r2, r2, #0x10
	ldr r0, _0807E104 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x14]
	ldrh r2, [r4, #0xc]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0807c88c
	b _0807E178
	.align 2, 0
_0807E100: .4byte 0xFFFF0000
_0807E104: .4byte 0x0000FFFF
_0807E108:
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r5, #0
	bl FUN_0807c8d4
	b _0807E1D8
_0807E114:
	movs r0, #8
	ldrsh r1, [r4, r0]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807c9ac
	b _0807E178
_0807E122:
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807ca24
	b _0807E178
_0807E130:
	movs r0, #8
	ldrsh r1, [r4, r0]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807ca9c
	b _0807E178
_0807E13E:
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807cb14
	b _0807E178
_0807E14C:
	movs r0, #8
	ldrsh r1, [r4, r0]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807cb8c
	b _0807E178
_0807E15A:
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r5, #0
	bl FUN_0807cc14
	b _0807E1D8
_0807E166:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0807c928
	b _0807E178
_0807E170:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0807c968
_0807E178:
	adds r0, r5, #0
	bl FUN_08072670
	b _0807E256
_0807E180:
	adds r0, r5, #0
	movs r1, #2
	bl FUN_0807cd24
	b _0807E1D8
_0807E18A:
	adds r0, r5, #0
	bl FUN_0807ceb8
	b _0807E1D8
_0807E192:
	movs r0, #8
	ldrsh r1, [r4, r0]
	ldr r2, _0807E1A4 @ =0x00000121
	adds r1, r1, r2
	adds r0, r5, #0
	bl FUN_0807b890
	b _0807E1D8
	.align 2, 0
_0807E1A4: .4byte 0x00000121
_0807E1A8:
	movs r0, #8
	ldrsh r1, [r4, r0]
	ldr r2, _0807E1B8 @ =0x00000121
	adds r1, r1, r2
	adds r0, r5, #0
	bl FUN_0807b8a8
	b _0807E1D8
	.align 2, 0
_0807E1B8: .4byte 0x00000121
_0807E1BC:
	adds r0, r5, #0
	bl FUN_0807b8c0
	b _0807E1D8
_0807E1C4:
	ldr r0, _0807E1CC @ =0x000004AD
	adds r1, r5, r0
	movs r0, #1
	b _0807E1D6
	.align 2, 0
_0807E1CC: .4byte 0x000004AD
_0807E1D0:
	ldr r2, _0807E1E8 @ =0x000004AD
	adds r1, r5, r2
	movs r0, #0
_0807E1D6:
	strb r0, [r1]
_0807E1D8:
	adds r0, r5, #0
	bl FUN_08072670
_0807E1DE:
	adds r0, r5, #0
	bl FUN_0807268c
	b _0807E256
	.align 2, 0
_0807E1E8: .4byte 0x000004AD
_0807E1EC:
	movs r1, #8
	ldrsh r0, [r4, r1]
	cmp r0, #8
	bhi _0807E24A
	lsls r0, r0, #2
	ldr r1, _0807E200 @ =_0807E204
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807E200: .4byte _0807E204
_0807E204: @ jump table
	.4byte _0807E228 @ case 0
	.4byte _0807E228 @ case 1
	.4byte _0807E228 @ case 2
	.4byte _0807E228 @ case 3
	.4byte _0807E238 @ case 4
	.4byte _0807E238 @ case 5
	.4byte _0807E228 @ case 6
	.4byte _0807E228 @ case 7
	.4byte _0807E228 @ case 8
_0807E228:
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r5, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0807cec4
	b _0807E24A
_0807E238:
	movs r0, #8
	ldrsh r1, [r4, r0]
	movs r0, #0xa
	ldrsh r2, [r4, r0]
	movs r0, #0xc
	ldrsh r3, [r4, r0]
	adds r0, r5, #0
	bl FUN_0807cec4
_0807E24A:
	adds r0, r5, #0
	bl FUN_08072670
	adds r0, r5, #0
	bl FUN_0807268c
_0807E256:
	adds r6, #1
	ldr r0, _0807E274 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r7, #6
_0807E260:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r6, r0
	bge _0807E26C
	b _0807DE08
_0807E26C:
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807E274: .4byte 0x03002B4C

	thumb_func_start FUN_0807e278
FUN_0807e278: @ 0x0807E278
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r5, r2, #0
	adds r7, r3, #0
	ldr r0, _0807E2C4 @ =0x00000994
	adds r4, r6, r0
	ldrh r0, [r6, #0x24]
	movs r2, #0
	movs r3, #0
	strh r0, [r4]
	movs r0, #2
	strb r0, [r4, #2]
	strb r2, [r4, #3]
	strh r3, [r4, #4]
	strb r1, [r4, #6]
	strb r5, [r4, #7]
	cmp r7, #0
	beq _0807E2B6
	cmp r5, #0
	ble _0807E2B6
	adds r3, r7, #0
	ldr r0, _0807E2C8 @ =0x0000099C
	adds r1, r6, r0
	adds r2, r5, #0
_0807E2A8:
	ldrh r0, [r3]
	strh r0, [r1]
	adds r3, #2
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bne _0807E2A8
_0807E2B6:
	adds r0, r4, #0
	bl FUN_080224f0
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807E2C4: .4byte 0x00000994
_0807E2C8: .4byte 0x0000099C

	thumb_func_start FUN_0807e2cc
FUN_0807e2cc: @ 0x0807E2CC
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	movs r0, #0xbb
	lsls r0, r0, #2
	adds r5, r4, r0
	ldr r2, _0807E374 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x78
	orrs r0, r3
	ldr r1, _0807E378 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	ldr r2, _0807E37C @ =0x00002001
	adds r1, r4, #0
	adds r1, #0x28
	movs r0, #0x80
	lsls r0, r0, #9
	ldrb r1, [r1]
	lsls r0, r1
	lsrs r0, r0, #0x10
	str r0, [sp]
	add r1, sp, #0xc
	str r1, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	movs r0, #0x80
	lsls r0, r0, #0xb
	str r0, [sp]
	movs r0, #0xa
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #0xa
	movs r2, #0x28
	movs r3, #0
	bl FUN_082364f8
	adds r0, r5, #0
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0823651c
	adds r1, r4, #0
	adds r1, #0x2c
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r0, _0807E380 @ =0x000002EB
	adds r1, r4, r0
	movs r0, #6
	strb r0, [r1]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	ldr r1, _0807E384 @ =0x0000032E
	adds r4, r4, r1
	strb r0, [r4]
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807E374: .4byte 0xFFFF0000
_0807E378: .4byte 0x0000FFFF
_0807E37C: .4byte 0x00002001
_0807E380: .4byte 0x000002EB
_0807E384: .4byte 0x0000032E

	thumb_func_start FUN_0807e388
FUN_0807e388: @ 0x0807E388
	push {r4, lr}
	adds r1, r0, #0
	ldr r0, _0807E3AC @ =0x000002EB
	adds r4, r1, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0807E3A6
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r0, r1, r2
	bl FUN_08236400
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
_0807E3A6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807E3AC: .4byte 0x000002EB

	thumb_func_start FUN_0807e3b0
FUN_0807e3b0: @ 0x0807E3B0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne _0807E3DC
	movs r2, #0xe0
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	ldr r4, _0807E3EC @ =0x00000381
	adds r0, r5, r4
	strb r1, [r0]
_0807E3DC:
	ldrh r0, [r6, #0x3c]
	cmp r0, #0
	ble _0807E3F0
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_08236524
	b _0807E3F4
	.align 2, 0
_0807E3EC: .4byte 0x00000381
_0807E3F0:
	movs r0, #0
	strh r0, [r7, #0x3e]
_0807E3F4:
	adds r0, r6, #0
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #0xe
	movs r0, #0xde
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	movs r2, #0
	mov r8, r2
	mov sb, r1
	cmp r0, #0
	beq _0807E41E
	movs r4, #1
	rsbs r4, r4, #0
	mov r8, r4
_0807E41E:
	adds r0, r6, #0
	adds r0, #0x40
	ldrh r1, [r0]
	cmp r1, #0
	bne _0807E43C
	ldr r2, _0807E434 @ =0x000003D6
	adds r0, r5, r2
	strh r1, [r0]
	ldr r0, _0807E438 @ =0x00000446
	adds r4, r5, r0
	b _0807E51A
	.align 2, 0
_0807E434: .4byte 0x000003D6
_0807E438: .4byte 0x00000446
_0807E43C:
	ldr r1, _0807E550 @ =0x000003D6
	adds r0, r5, r1
	movs r1, #0xe6
	strh r1, [r0]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r1, [r0]
	cmp r1, #2
	bne _0807E45C
	movs r4, #0xdf
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0xc
	beq _0807E46C
_0807E45C:
	cmp r1, #3
	bne _0807E47C
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0xd
	bne _0807E47C
_0807E46C:
	movs r2, #0xe0
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	ldr r4, _0807E554 @ =0x00000381
	adds r0, r5, r4
	strb r1, [r0]
_0807E47C:
	ldr r0, _0807E558 @ =0x000003FF
	adds r1, r5, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _0807E48C
	bl FUN_080dab9c
_0807E48C:
	ldr r1, _0807E55C @ =0x00000446
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r2, #0
	adds r4, r0, #0
	cmp r1, #0
	beq _0807E4A6
	ldr r1, _0807E560 @ =0x00000442
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #6
	bne _0807E4A6
	movs r2, #1
_0807E4A6:
	cmp r2, #0
	beq _0807E4C4
	ldr r2, _0807E560 @ =0x00000442
	adds r0, r5, r2
	movs r1, #0
	strh r1, [r0]
	adds r2, #4
	adds r0, r5, r2
	strh r1, [r0]
	adds r2, r5, #0
	adds r2, #0xe8
	ldr r0, [r2]
	ldr r1, _0807E564 @ =0xFFFFFBFF
	ands r0, r1
	str r0, [r2]
_0807E4C4:
	ldr r1, _0807E568 @ =0x000003EA
	adds r0, r5, r1
	ldrh r2, [r0]
	cmp r2, #0
	bne _0807E4DC
	movs r0, #0xfb
	lsls r0, r0, #2
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0807E4DC
	strh r2, [r1]
_0807E4DC:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x13
	bne _0807E4FE
	movs r1, #0x80
	lsls r1, r1, #7
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _0807E4FE
	adds r0, r5, #0
	bl FUN_08063220
	movs r2, #1
	add r8, r2
_0807E4FE:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r7, #0
	bl FUN_08060cf8
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	cmp r1, #1
	bne _0807E51A
	ldr r2, _0807E56C @ =0x00000449
	adds r0, r5, r2
	strb r1, [r0]
_0807E51A:
	ldrh r0, [r4]
	movs r1, #0
	cmp r0, #0
	beq _0807E52E
	ldr r2, _0807E560 @ =0x00000442
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #3
	bne _0807E52E
	movs r1, #1
_0807E52E:
	cmp r1, #0
	beq _0807E570
	movs r0, #0
	strh r0, [r7, #0x3e]
	movs r4, #0
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _0807E546
	b _0807E76E
_0807E546:
	adds r0, r5, #0
	bl FUN_08063220
	b _0807E76E
	.align 2, 0
_0807E550: .4byte 0x000003D6
_0807E554: .4byte 0x00000381
_0807E558: .4byte 0x000003FF
_0807E55C: .4byte 0x00000446
_0807E560: .4byte 0x00000442
_0807E564: .4byte 0xFFFFFBFF
_0807E568: .4byte 0x000003EA
_0807E56C: .4byte 0x00000449
_0807E570:
	ldrh r0, [r4]
	movs r1, #0
	cmp r0, #0
	beq _0807E584
	ldr r4, _0807E5E0 @ =0x00000442
	adds r0, r5, r4
	ldrh r0, [r0]
	cmp r0, #5
	bne _0807E584
	movs r1, #1
_0807E584:
	cmp r1, #0
	bne _0807E5A4
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _0807E5A4
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #2
	beq _0807E5A4
	cmp r0, #3
	bne _0807E5A8
_0807E5A4:
	movs r4, #1
	add r8, r4
_0807E5A8:
	movs r0, #0x80
	lsls r0, r0, #0xe
	ldr r1, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _0807E5F0
	adds r0, r7, #0
	adds r0, #0x43
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0807E670
	ldr r1, _0807E5E4 @ =0x000003D2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0807E5D4
	ldr r2, _0807E5E8 @ =0x000003D6
	adds r1, r5, r2
	ldr r0, _0807E5EC @ =0x00000191
	strh r0, [r1]
_0807E5D4:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08063288
	b _0807E670
	.align 2, 0
_0807E5E0: .4byte 0x00000442
_0807E5E4: .4byte 0x000003D2
_0807E5E8: .4byte 0x000003D6
_0807E5EC: .4byte 0x00000191
_0807E5F0:
	movs r0, #0x80
	lsls r0, r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _0807E630
	adds r0, r7, #0
	adds r0, #0x43
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0807E670
	ldr r4, _0807E624 @ =0x000003D2
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0807E61A
	ldr r0, _0807E628 @ =0x000003D6
	adds r1, r5, r0
	ldr r0, _0807E62C @ =0x00000133
	strh r0, [r1]
_0807E61A:
	adds r0, r5, #0
	movs r1, #2
	bl FUN_08063288
	b _0807E670
	.align 2, 0
_0807E624: .4byte 0x000003D2
_0807E628: .4byte 0x000003D6
_0807E62C: .4byte 0x00000133
_0807E630:
	movs r0, #0x80
	lsls r0, r0, #7
	ands r0, r1
	cmp r0, #0
	beq _0807E660
	ldr r2, _0807E654 @ =0x000003D6
	adds r1, r5, r2
	movs r4, #0
	ldr r0, _0807E658 @ =0x00000133
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #3
	bl FUN_08063288
	ldr r1, _0807E65C @ =0x000003D2
	adds r0, r5, r1
	strb r4, [r0]
	b _0807E670
	.align 2, 0
_0807E654: .4byte 0x000003D6
_0807E658: .4byte 0x00000133
_0807E65C: .4byte 0x000003D2
_0807E660:
	movs r0, #0x80
	lsls r0, r0, #0xb
	ands r1, r0
	cmp r1, #0
	beq _0807E670
	adds r0, r5, #0
	bl FUN_08063220
_0807E670:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _0807E694
	movs r1, #0x20
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _0807E694
	movs r2, #0xe1
	lsls r2, r2, #3
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08063574
_0807E694:
	movs r1, #0x80
	lsls r1, r1, #0xd
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _0807E6AC
	movs r2, #0xe1
	lsls r2, r2, #2
	adds r0, r5, #0
	movs r1, #2
	bl FUN_08063574
_0807E6AC:
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _0807E73A
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _0807E6E8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0807E6EC
	asrs r0, r0, #0xc
	b _0807E6F2
	.align 2, 0
_0807E6E8: .4byte 0x085B0A08
_0807E6EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0807E6F2:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xc8
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #4]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0807E714
	asrs r0, r0, #0xc
	b _0807E71A
_0807E714:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0807E71A:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0807E748 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	adds r0, r5, #0
	adds r0, #0x2c
	movs r1, #1
	str r1, [sp]
	add r1, sp, #4
	movs r2, #0
	movs r3, #0
	bl FUN_080dc0b8
_0807E73A:
	mov r4, r8
	cmp r4, #0
	blt _0807E74C
	ldrh r4, [r7, #0x3e]
	mov r0, r8
	lsls r4, r0
	b _0807E760
	.align 2, 0
_0807E748: .4byte 0xFFFF0000
_0807E74C:
	ldrh r1, [r7, #0x3e]
	mov r2, r8
	rsbs r0, r2, #0
	adds r4, r1, #0
	asrs r4, r0
	cmp r1, #0
	beq _0807E760
	cmp r4, #0
	bne _0807E760
	movs r4, #1
_0807E760:
	movs r0, #0
	strh r0, [r7, #0x3e]
	ldr r0, _0807E780 @ =0x00000376
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, r0, r4
	strh r0, [r1]
_0807E76E:
	adds r0, r4, #0
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0807E780: .4byte 0x00000376

	thumb_func_start FUN_0807e784
FUN_0807e784: @ 0x0807E784
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	ldr r1, [r4, #0x1c]
	cmp r1, #1
	bne _0807E7F4
	movs r0, #0x80
	lsls r0, r0, #2
	ldrh r2, [r6, #6]
	ands r0, r2
	cmp r0, #0
	beq _0807E7B4
	movs r0, #0x46
	adds r0, r0, r5
	mov ip, r0
	ldrb r3, [r0]
	ands r1, r3
	cmp r1, #0
	beq _0807E7F4
	movs r0, #0xfe
	ands r0, r3
	mov r1, ip
	strb r0, [r1]
_0807E7B4:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r2, r0
	cmp r2, #0
	beq _0807E7D2
	adds r2, r5, #0
	adds r2, #0x46
	ldrb r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0807E7F4
	movs r0, #2
	orrs r0, r1
	strb r0, [r2]
_0807E7D2:
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r5, #0
	bl FUN_0807e3b0
	movs r1, #0x80
	lsls r1, r1, #0xb
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0807E7F4
	adds r0, r4, #0
	bl FUN_0807e2cc
_0807E7F4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0807e7fc
FUN_0807e7fc: @ 0x0807E7FC
	push {r4, r5, r6, lr}
	sub sp, #0x50
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r3, #0
	ldr r0, [r4, #0x1c]
	cmp r0, #1
	bne _0807E848
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r3, r4, r0
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bgt _0807E848
	mov r1, sp
	movs r0, #0x80
	lsls r0, r0, #6
	strh r0, [r1, #6]
	mov r0, sp
	strh r5, [r0, #0x3c]
	add r0, sp, #0x40
	strh r2, [r0]
	adds r0, #2
	strb r6, [r0]
	ldr r0, [sp, #0x64]
	str r0, [sp, #0x38]
	add r1, sp, #0x44
	ldr r0, [sp, #0x60]
	strh r0, [r1]
	adds r0, r4, #0
	mov r1, sp
	adds r2, r3, #0
	bl FUN_0807e3b0
	b _0807E84A
_0807E848:
	movs r0, #0
_0807E84A:
	add sp, #0x50
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0807e854
FUN_0807e854: @ 0x0807E854
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _0807E87A
	movs r2, #0xe0
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	ldr r3, _0807E8A8 @ =0x00000381
	adds r0, r5, r3
	strb r1, [r0]
_0807E87A:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r5, r0
	ldrb r0, [r2]
	movs r1, #1
	orrs r1, r0
	strb r1, [r2]
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0807E8B4
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _0807E8AC @ =0x000002E6
	adds r1, r5, r2
	strb r0, [r1]
	ldr r3, _0807E8B0 @ =0x000002E7
	adds r1, r5, r3
	movs r0, #1
	b _0807E8C2
	.align 2, 0
_0807E8A8: .4byte 0x00000381
_0807E8AC: .4byte 0x000002E6
_0807E8B0: .4byte 0x000002E7
_0807E8B4:
	lsrs r1, r1, #0x19
	ldr r2, _0807E93C @ =0x000002E6
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _0807E940 @ =0x000002E7
	adds r1, r5, r3
	movs r0, #0
_0807E8C2:
	strb r0, [r1]
	movs r0, #4
	str r0, [r5, #0x1c]
	ldr r1, _0807E944 @ =0x0000037D
	adds r0, r5, r1
	movs r4, #0
	strb r4, [r0]
	ldr r2, _0807E948 @ =0x0000037E
	adds r0, r5, r2
	movs r1, #0
	strh r4, [r0]
	movs r3, #0xd8
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r4, [r0]
	subs r2, #0xfb
	adds r0, r5, r2
	strb r1, [r0]
	ldr r0, _0807E94C @ =0x03002BD0
	strh r4, [r0]
	ldr r0, _0807E950 @ =0x03002B80
	strh r4, [r0]
	ldr r0, _0807E954 @ =0x03002B78
	strh r4, [r0]
	adds r0, r5, #0
	bl FUN_08063220
	ldr r3, _0807E958 @ =0x00000442
	adds r0, r5, r3
	strh r4, [r0]
	ldr r1, _0807E95C @ =0x00000444
	adds r0, r5, r1
	strh r4, [r0]
	ldr r2, _0807E960 @ =0x00000446
	adds r0, r5, r2
	strh r4, [r0]
	movs r2, #0
	movs r1, #2
	subs r3, #2
	adds r0, r5, r3
_0807E912:
	strh r2, [r0]
	subs r0, #2
	subs r1, #1
	cmp r1, #0
	bge _0807E912
	adds r0, r5, #0
	bl FUN_08060c60
	ldr r1, _0807E964 @ =0x000003CE
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _0807E934
	adds r0, r5, #0
	bl FUN_08066d10
_0807E934:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807E93C: .4byte 0x000002E6
_0807E940: .4byte 0x000002E7
_0807E944: .4byte 0x0000037D
_0807E948: .4byte 0x0000037E
_0807E94C: .4byte 0x03002BD0
_0807E950: .4byte 0x03002B80
_0807E954: .4byte 0x03002B78
_0807E958: .4byte 0x00000442
_0807E95C: .4byte 0x00000444
_0807E960: .4byte 0x00000446
_0807E964: .4byte 0x000003CE

	thumb_func_start FUN_0807e968
FUN_0807e968: @ 0x0807E968
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0807E992
	cmp r1, #0
	blt _0807E992
	ldr r0, _0807E998 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0807E992
	ldr r0, _0807E99C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0807E9A0
_0807E992:
	movs r4, #0
	b _0807E9AE
	.align 2, 0
_0807E998: .4byte 0x030046A8
_0807E99C: .4byte 0x030046AC
_0807E9A0:
	ldr r0, _0807E9C0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0807E9AE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0807E9C4
	adds r0, #4
	b _0807E9D0
	.align 2, 0
_0807E9C0: .4byte 0x030046A4
_0807E9C4:
	ldr r0, _0807EA00 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0807E9D0:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0807EA1E
	movs r1, #0xe4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0807EA1E
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r0, _0807EA04 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _0807EA08 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0807EA0C
	movs r0, #1
	b _0807EA0E
	.align 2, 0
_0807EA00: .4byte 0x030046A4
_0807EA04: .4byte 0x030046A0
_0807EA08: .4byte 0x00000934
_0807EA0C:
	movs r0, #0
_0807EA0E:
	cmp r0, #0
	beq _0807EA18
	adds r0, r5, #0
	movs r1, #0x1d
	b _0807EA36
_0807EA18:
	adds r0, r5, #0
	movs r1, #0x1c
	b _0807EA36
_0807EA1E:
	ldr r0, _0807EA40 @ =0x030046A0
	ldr r0, [r0]
	movs r7, #0xdd
	lsls r7, r7, #1
	adds r0, r0, r7
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _0807EA44 @ =0x00001387
	cmp r1, r0
	ble _0807EA48
	adds r0, r5, #0
	movs r1, #0x1e
_0807EA36:
	movs r2, #0
	bl FUN_08060b84
_0807EA3C:
	movs r0, #1
	b _0807EC8E
	.align 2, 0
_0807EA40: .4byte 0x030046A0
_0807EA44: .4byte 0x00001387
_0807EA48:
	movs r7, #0xe5
	lsls r7, r7, #2
	adds r0, r5, r7
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807EA64
	adds r0, r5, #0
	bl FUN_08065cb8
	ldr r1, _0807EA60 @ =0x00000376
	adds r2, r5, r1
	b _0807EA78
	.align 2, 0
_0807EA60: .4byte 0x00000376
_0807EA64:
	ldr r2, _0807EB14 @ =0x00000396
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807EA7E
	adds r0, r5, #0
	bl FUN_08065e24
	ldr r7, _0807EB18 @ =0x00000376
	adds r2, r5, r7
_0807EA78:
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
_0807EA7E:
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r3, [r0]
	cmp r3, #0
	beq _0807EA8C
	b _0807EBA0
_0807EA8C:
	ldr r2, _0807EB1C @ =0x0000043E
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _0807EAB6
	movs r7, #0xf6
	lsls r7, r7, #2
	adds r2, r5, r7
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _0807EAB6
	ldr r0, _0807EB18 @ =0x00000376
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	strh r3, [r2]
_0807EAB6:
	ldr r1, _0807EB20 @ =0x000004C5
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0807EAFC
	ldr r7, _0807EB24 @ =0x000004C7
	adds r2, r5, r7
	ldrb r0, [r2]
	cmp r0, #0
	beq _0807EAFC
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r0, [r5, #0x20]
	orrs r0, r1
	str r0, [r5, #0x20]
	ldr r0, _0807EB28 @ =0x000003DA
	adds r6, r5, r0
	ldrh r4, [r6]
	adds r4, #1
	strh r4, [r6]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldrb r1, [r2]
	movs r0, #0x3c
	bl Div
	cmp r4, r0
	blt _0807EAFC
	ldr r1, _0807EB18 @ =0x00000376
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r1, #0xa
	strh r1, [r0]
	movs r0, #0
	strh r0, [r6]
_0807EAFC:
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, _0807EB2C @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _0807EB30 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0807EB34
	movs r0, #1
	b _0807EB36
	.align 2, 0
_0807EB14: .4byte 0x00000396
_0807EB18: .4byte 0x00000376
_0807EB1C: .4byte 0x0000043E
_0807EB20: .4byte 0x000004C5
_0807EB24: .4byte 0x000004C7
_0807EB28: .4byte 0x000003DA
_0807EB2C: .4byte 0x030046A0
_0807EB30: .4byte 0x00000934
_0807EB34:
	movs r0, #0
_0807EB36:
	cmp r0, #0
	beq _0807EB64
	movs r7, #0xf8
	lsls r7, r7, #2
	adds r2, r5, r7
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bls _0807EB6E
	ldr r1, _0807EB60 @ =0x00000376
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	movs r0, #0
	strh r0, [r2]
	b _0807EB6E
	.align 2, 0
_0807EB60: .4byte 0x00000376
_0807EB64:
	movs r2, #0xf8
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #0x78
	strh r0, [r1]
_0807EB6E:
	movs r1, #0x80
	lsls r1, r1, #0xc
	movs r7, #0xde
	lsls r7, r7, #2
	adds r0, r5, r7
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0807EBA0
	ldr r0, _0807EBF8 @ =0x000003E2
	adds r2, r5, r0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls _0807EBA0
	ldr r1, _0807EBFC @ =0x00000376
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	movs r0, #0
	strh r0, [r2]
_0807EBA0:
	ldr r2, _0807EBFC @ =0x00000376
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _0807EC0C
	ldr r7, _0807EC00 @ =0x00000446
	adds r0, r5, r7
	ldrh r0, [r0]
	movs r6, #0
	cmp r0, #0
	beq _0807EBC2
	ldr r1, _0807EC04 @ =0x00000442
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #3
	bne _0807EBC2
	movs r6, #1
_0807EBC2:
	cmp r6, #0
	bne _0807EC0C
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r7, _0807EBFC @ =0x00000376
	adds r4, r5, r7
	ldrh r1, [r4]
	adds r3, r5, #0
	adds r3, #0x2c
	movs r7, #0x97
	lsls r7, r7, #4
	adds r2, r5, r7
	str r2, [sp]
	str r6, [sp, #4]
	movs r2, #0
	bl FUN_0805fe7c
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r5, r0
	ldrh r2, [r1]
	ldrh r0, [r4]
	cmp r2, r0
	bhs _0807EC08
	strh r6, [r1]
	b _0807EC0C
	.align 2, 0
_0807EBF8: .4byte 0x000003E2
_0807EBFC: .4byte 0x00000376
_0807EC00: .4byte 0x00000446
_0807EC04: .4byte 0x00000442
_0807EC08:
	subs r0, r2, r0
	strh r0, [r1]
_0807EC0C:
	ldr r1, _0807EC98 @ =0x00000376
	adds r0, r5, r1
	movs r1, #0
	strh r1, [r0]
	movs r2, #0x97
	lsls r2, r2, #4
	adds r0, r5, r2
	strh r1, [r0]
	ldr r7, _0807EC9C @ =0x00000972
	adds r0, r5, r7
	strh r1, [r0]
	adds r2, #4
	adds r0, r5, r2
	strh r1, [r0]
	movs r7, #0xdf
	lsls r7, r7, #2
	adds r0, r5, r7
	ldrb r0, [r0]
	cmp r0, #0x15
	beq _0807EC8C
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0807EC8C
	ldr r0, _0807ECA0 @ =0x030047A4
	ldr r4, [r0]
	movs r0, #0x80
	lsls r0, r0, #5
	ands r4, r0
	cmp r4, #0
	beq _0807EC50
	b _0807EA3C
_0807EC50:
	movs r0, #0x30
	bl CheckItemOwn
	cmp r0, #0
	bne _0807EC5C
	b _0807EA3C
_0807EC5C:
	ldr r2, _0807ECA4 @ =0x000003D6
	adds r0, r5, r2
	strh r4, [r0]
	movs r7, #0xd6
	lsls r7, r7, #1
	adds r3, r5, r7
	ldrh r0, [r3]
	cmp r0, #0
	bne _0807EC80
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r5, r0
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	movs r0, #1
	strh r0, [r3]
_0807EC80:
	movs r0, #0x30
	bl RemoveSpecifiedItem
	adds r0, r5, #0
	bl FUN_080a9e88
_0807EC8C:
	movs r0, #0
_0807EC8E:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0807EC98: .4byte 0x00000376
_0807EC9C: .4byte 0x00000972
_0807ECA0: .4byte 0x030047A4
_0807ECA4: .4byte 0x000003D6

	thumb_func_start FUN_0807eca8
FUN_0807eca8: @ 0x0807ECA8
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r5, [r0]
	cmp r5, #0
	ble _0807ECFC
	adds r0, r4, #0
	movs r1, #8
	bl FUN_08060c40
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0807ECFC
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x18
	beq _0807ECFC
	cmp r0, #0x19
	beq _0807ECFC
	subs r5, #1
	cmp r5, #0
	beq _0807ECF4
	asrs r0, r5, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0807ECF4
	adds r0, r4, #0
	movs r1, #5
	bl FUN_08060c40
_0807ECF4:
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r5, [r0]
_0807ECFC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0807ed04
FUN_0807ed04: @ 0x0807ED04
	push {r4, r5, r6, lr}
	mov ip, r0
	ldr r4, _0807ED98 @ =0x030046A0
	ldr r1, [r4]
	ldrh r0, [r0, #0x2c]
	strh r0, [r1, #0x30]
	ldr r1, [r4]
	mov r2, ip
	ldrh r0, [r2, #0x2e]
	strh r0, [r1, #0x32]
	ldr r1, [r4]
	ldrh r0, [r2, #0x30]
	strh r0, [r1, #0x34]
	ldr r1, [r4]
	movs r5, #0xba
	lsls r5, r5, #2
	add r5, ip
	ldrb r0, [r5]
	strh r0, [r1, #0x36]
	ldr r2, [r4]
	ldr r3, _0807ED9C @ =0x00000932
	adds r2, r2, r3
	ldrb r0, [r5]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	strh r0, [r2]
	ldr r1, [r4]
	adds r3, r1, r3
	ldrh r0, [r3]
	mov r2, ip
	adds r2, #0x29
	strb r0, [r2]
	movs r2, #0
	ldrsh r0, [r3, r2]
	movs r2, #0xd7
	lsls r2, r2, #1
	add r2, ip
	strb r0, [r2]
	movs r0, #0x94
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r2, #0xd6
	lsls r2, r2, #2
	add r2, ip
	ldrb r0, [r2]
	strh r0, [r1]
	ldr r0, [r4]
	movs r1, #0x93
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r1, #0xdf
	lsls r1, r1, #2
	add r1, ip
	ldrb r1, [r1]
	strh r1, [r0]
	ldrb r0, [r2]
	cmp r0, #5
	bne _0807EDA0
	ldr r1, [r4]
	movs r0, #0xd9
	lsls r0, r0, #2
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r1, #0x38]
	ldr r1, [r4]
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r1, #0x3a]
	b _0807EDB8
	.align 2, 0
_0807ED98: .4byte 0x030046A0
_0807ED9C: .4byte 0x00000932
_0807EDA0:
	ldr r1, [r4]
	movs r0, #0xd9
	lsls r0, r0, #2
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r1, #0x28]
	ldr r1, [r4]
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r1, #0x2c]
_0807EDB8:
	ldr r1, [r4]
	ldr r0, _0807EE24 @ =0x00000366
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r1, #0x2a]
	ldr r1, [r4]
	ldr r0, _0807EE28 @ =0x0000036A
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r1, #0x2e]
	ldr r1, _0807EE2C @ =0x03002B60
	ldr r0, _0807EE30 @ =0x00000442
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0807EE34 @ =0x03002B7C
	ldr r0, _0807EE38 @ =0x00000444
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0807EE3C @ =0x03002B8C
	ldr r0, _0807EE40 @ =0x00000446
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r5, _0807EE44 @ =0x03002BC0
	mov r4, ip
	adds r4, #0x28
	ldr r6, _0807EE48 @ =0x03002BB0
	ldr r1, _0807EE4C @ =0x0000043C
	add r1, ip
	ldr r3, _0807EE50 @ =0x03002BA0
	movs r2, #2
_0807EDFA:
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, #2
	adds r3, #2
	subs r2, #1
	cmp r2, #0
	bge _0807EDFA
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r5
	mov r2, ip
	ldr r1, [r2, #0x1c]
	str r1, [r0]
	ldr r0, _0807EE54 @ =0x00000283
	add r0, ip
	ldrb r0, [r0]
	strh r0, [r6]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807EE24: .4byte 0x00000366
_0807EE28: .4byte 0x0000036A
_0807EE2C: .4byte 0x03002B60
_0807EE30: .4byte 0x00000442
_0807EE34: .4byte 0x03002B7C
_0807EE38: .4byte 0x00000444
_0807EE3C: .4byte 0x03002B8C
_0807EE40: .4byte 0x00000446
_0807EE44: .4byte 0x03002BC0
_0807EE48: .4byte 0x03002BB0
_0807EE4C: .4byte 0x0000043C
_0807EE50: .4byte 0x03002BA0
_0807EE54: .4byte 0x00000283

	thumb_func_start FUN_0807ee58
FUN_0807ee58: @ 0x0807EE58
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0807EE6A
	b _0807F092
_0807EE6A:
	ldr r2, _0807EEC8 @ =0x00000381
	adds r0, r5, r2
	ldrb r1, [r0]
	cmp r1, #2
	bne _0807EEEC
	subs r2, #0x29
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	movs r0, #0xac
	lsls r0, r0, #4
	adds r1, r5, r0
	ldr r0, _0807EECC @ =FUN_080798a4
	str r0, [r1]
	ldr r0, _0807EED0 @ =0x00000359
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	str r2, [r5, #0x50]
	adds r0, r5, #0
	adds r0, #0xe8
	str r0, [r5, #0x4c]
	ldr r2, _0807EED4 @ =0x000004CC
	adds r1, r5, r2
	movs r2, #0x82
	lsls r2, r2, #1
	adds r0, r5, r2
	str r0, [r1]
	adds r0, r5, #0
	bl FUN_08062c3c
	ldr r0, _0807EED8 @ =0x0000094C
	adds r1, r5, r0
	ldr r0, _0807EEDC @ =0x0000FFFF
	strh r0, [r1]
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r2, _0807EEE0 @ =0x0000094A
	adds r0, r5, r2
	ldrh r0, [r0]
	strh r0, [r1, #6]
	ldr r0, _0807EEE4 @ =0x0000095E
	adds r1, r5, r0
	ldr r0, _0807EEE8 @ =0x0000026D
	b _0807EF46
	.align 2, 0
_0807EEC8: .4byte 0x00000381
_0807EECC: .4byte FUN_080798a4
_0807EED0: .4byte 0x00000359
_0807EED4: .4byte 0x000004CC
_0807EED8: .4byte 0x0000094C
_0807EEDC: .4byte 0x0000FFFF
_0807EEE0: .4byte 0x0000094A
_0807EEE4: .4byte 0x0000095E
_0807EEE8: .4byte 0x0000026D
_0807EEEC:
	cmp r1, #3
	bne _0807EF70
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	movs r0, #0xac
	lsls r0, r0, #4
	adds r1, r5, r0
	ldr r0, _0807EF54 @ =FUN_08079b64
	str r0, [r1]
	ldr r0, _0807EF58 @ =0x00000359
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	str r2, [r5, #0x50]
	adds r0, r5, #0
	adds r0, #0xe8
	str r0, [r5, #0x4c]
	ldr r2, _0807EF5C @ =0x000004CC
	adds r1, r5, r2
	movs r2, #0x82
	lsls r2, r2, #1
	adds r0, r5, r2
	str r0, [r1]
	adds r0, r5, #0
	bl FUN_08062c3c
	ldr r0, _0807EF60 @ =0x0000094C
	adds r1, r5, r0
	ldr r0, _0807EF64 @ =0x0000FFFF
	strh r0, [r1]
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r2, _0807EF68 @ =0x0000094A
	adds r0, r5, r2
	ldrh r0, [r0]
	strh r0, [r1, #6]
	ldr r0, _0807EF6C @ =0x0000095E
	adds r1, r5, r0
	movs r0, #0x91
	lsls r0, r0, #1
_0807EF46:
	strh r0, [r1]
	adds r2, #0x16
	adds r1, r5, r2
	movs r0, #0x20
	strh r0, [r1]
	b _0807F066
	.align 2, 0
_0807EF54: .4byte FUN_08079b64
_0807EF58: .4byte 0x00000359
_0807EF5C: .4byte 0x000004CC
_0807EF60: .4byte 0x0000094C
_0807EF64: .4byte 0x0000FFFF
_0807EF68: .4byte 0x0000094A
_0807EF6C: .4byte 0x0000095E
_0807EF70:
	cmp r1, #4
	bne _0807EFFC
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r4, #0
	strb r1, [r0]
	movs r0, #0xac
	lsls r0, r0, #4
	adds r1, r5, r0
	ldr r0, _0807EFE8 @ =FUN_08079e4c
	str r0, [r1]
	adds r2, #1
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	str r4, [r5, #0x50]
	adds r0, r5, #0
	adds r0, #0xe8
	str r0, [r5, #0x4c]
	ldr r0, _0807EFEC @ =0x000004CC
	adds r1, r5, r0
	movs r2, #0x82
	lsls r2, r2, #1
	adds r0, r5, r2
	str r0, [r1]
	adds r0, r5, #0
	bl FUN_08062c3c
	ldr r0, _0807EFF0 @ =0x0000094C
	adds r1, r5, r0
	ldr r0, _0807EFF4 @ =0x0000FFFF
	strh r0, [r1]
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	ldr r1, _0807EFF8 @ =0x0000094A
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r1, #0
	strh r0, [r2, #6]
	movs r2, #0xe2
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r4, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r4, [r0]
	subs r2, #0xa2
	adds r0, r5, r2
	strb r1, [r0]
	subs r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	b _0807F066
	.align 2, 0
_0807EFE8: .4byte FUN_08079e4c
_0807EFEC: .4byte 0x000004CC
_0807EFF0: .4byte 0x0000094C
_0807EFF4: .4byte 0x0000FFFF
_0807EFF8: .4byte 0x0000094A
_0807EFFC:
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r3, r5, r0
	ldrb r0, [r3]
	cmp r0, #4
	beq _0807F01C
	ldr r2, _0807F098 @ =0x0000095E
	adds r1, r5, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r5, r0
	movs r0, #0x20
	strh r0, [r1]
_0807F01C:
	movs r2, #0
	movs r0, #1
	strb r0, [r3]
	movs r0, #0xac
	lsls r0, r0, #4
	adds r1, r5, r0
	ldr r0, _0807F09C @ =FUN_08078d5c
	str r0, [r1]
	ldr r1, _0807F0A0 @ =0x00000359
	adds r0, r5, r1
	strb r2, [r0]
	adds r0, r5, #0
	adds r0, #0x88
	str r0, [r5, #0x50]
	str r2, [r5, #0x4c]
	ldr r2, _0807F0A4 @ =0x000004CC
	adds r1, r5, r2
	adds r0, #0x20
	str r0, [r1]
	adds r0, r5, #0
	bl FUN_08062c3c
	ldr r0, _0807F0A8 @ =0x0000094C
	adds r1, r5, r0
	ldr r0, _0807F0AC @ =0x0000FFFF
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_08064d04
	adds r0, #1
	ldr r2, _0807F0B0 @ =0x00000951
	adds r1, r5, r2
	strb r0, [r1]
	adds r0, #1
	subs r2, #1
	adds r1, r5, r2
	strb r0, [r1]
_0807F066:
	ldr r1, _0807F0B4 @ =0x0000094A
	adds r0, r5, r1
	ldrh r0, [r0]
	adds r1, r5, #0
	adds r1, #0xc2
	movs r4, #0
	strh r0, [r1]
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r0, r5, #0
	bl FUN_08064c48
	ldr r2, _0807F0B8 @ =0x00000282
	adds r1, r5, r2
	strb r0, [r1]
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r4, [r0]
_0807F092:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807F098: .4byte 0x0000095E
_0807F09C: .4byte FUN_08078d5c
_0807F0A0: .4byte 0x00000359
_0807F0A4: .4byte 0x000004CC
_0807F0A8: .4byte 0x0000094C
_0807F0AC: .4byte 0x0000FFFF
_0807F0B0: .4byte 0x00000951
_0807F0B4: .4byte 0x0000094A
_0807F0B8: .4byte 0x00000282

	thumb_func_start FUN_0807f0bc
FUN_0807f0bc: @ 0x0807F0BC
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, #0
	beq _0807F12A
	movs r0, #6
	bl IsMagicUnlocked
	cmp r0, #0
	beq _0807F10A
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0807F0F0
	ldr r0, _0807F0EC @ =0x030046A0
	ldr r0, [r0]
	subs r1, #0x80
	b _0807F0FC
	.align 2, 0
_0807F0EC: .4byte 0x030046A0
_0807F0F0:
	cmp r0, #5
	beq _0807F10A
	ldr r0, _0807F130 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xb7
	lsls r1, r1, #2
_0807F0FC:
	adds r2, r0, r1
	ldr r1, [r2]
	ldr r0, _0807F134 @ =0x7FFFFFFE
	cmp r1, r0
	bgt _0807F10A
	adds r0, r1, #1
	str r0, [r2]
_0807F10A:
	ldr r1, _0807F138 @ =0x00000A75
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r1, _0807F130 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0xb8
	lsls r1, r1, #2
	adds r2, r0, r1
	ldr r1, [r2]
	ldr r0, _0807F134 @ =0x7FFFFFFE
	cmp r1, r0
	bgt _0807F12A
	adds r0, r1, #1
	str r0, [r2]
_0807F12A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807F130: .4byte 0x030046A0
_0807F134: .4byte 0x7FFFFFFE
_0807F138: .4byte 0x00000A75

	thumb_func_start dark_django_0807f13c
dark_django_0807f13c: @ 0x0807F13C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r4, [r0]
	cmp r4, #1
	bne _0807F1EC
	ldr r2, _0807F1B8 @ =0x030046A0
	mov r8, r2
	ldr r0, [r2]
	subs r1, #0xb0
	adds r3, r0, r1
	movs r7, #0xab
	lsls r7, r7, #2
	adds r0, r0, r7
	ldr r1, [r3]
	ldr r0, [r0]
	cmp r1, r0
	blt _0807F1DC
	ldr r2, _0807F1BC @ =0x0000044A
	adds r6, r5, r2
	ldrb r2, [r6]
	cmp r2, #0
	beq _0807F1C8
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bhi _0807F1FA
	movs r4, #0
	str r4, [r3]
	ldr r2, _0807F1C0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	adds r1, #0x83
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0807F1C4 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x64
	bl Mod
	mov r2, r8
	ldr r1, [r2]
	adds r1, r1, r7
	adds r0, #0xc8
	str r0, [r1]
	strb r4, [r6]
	adds r0, r5, #0
	movs r1, #2
	bl FUN_08060e90
	adds r0, r5, #0
	bl FUN_080801b0
	b _0807F1FA
	.align 2, 0
_0807F1B8: .4byte 0x030046A0
_0807F1BC: .4byte 0x0000044A
_0807F1C0: .4byte 0x030046B8
_0807F1C4: .4byte 0x0203B400
_0807F1C8:
	ldr r0, _0807F1D8 @ =0x00000449
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0807F1FA
	strb r4, [r6]
	strb r2, [r1]
	b _0807F1FA
	.align 2, 0
_0807F1D8: .4byte 0x00000449
_0807F1DC:
	ldr r2, _0807F1E8 @ =0x00000449
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	b _0807F1FA
	.align 2, 0
_0807F1E8: .4byte 0x00000449
_0807F1EC:
	ldr r1, _0807F204 @ =0x0000044A
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _0807F208 @ =0x00000449
	adds r0, r5, r2
	strb r1, [r0]
_0807F1FA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807F204: .4byte 0x0000044A
_0807F208: .4byte 0x00000449

	thumb_func_start FUN_0807f20c
FUN_0807f20c: @ 0x0807F20C
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_0807dde4
	adds r0, r4, #0
	bl FUN_08060bac
	ldr r0, [r4, #0x1c]
	cmp r0, #1
	bne _0807F276
	adds r0, r4, #0
	bl FUN_0807f0bc
	adds r0, r4, #0
	bl FUN_08064764
	adds r0, r4, #0
	bl FUN_0807e388
	ldr r3, _0807F24C @ =0x03002B80
	ldrh r0, [r3]
	cmp r0, #0
	beq _0807F256
	ldr r2, _0807F250 @ =0x03002B78
	ldrh r0, [r2]
	adds r1, r0, #0
	cmp r1, #0
	beq _0807F254
	subs r0, #1
	strh r0, [r2]
	b _0807F256
	.align 2, 0
_0807F24C: .4byte 0x03002B80
_0807F250: .4byte 0x03002B78
_0807F254:
	strh r1, [r3]
_0807F256:
	adds r0, r4, #0
	bl FUN_0807e968
	cmp r0, #0
	beq _0807F268
	adds r0, r4, #0
	bl FUN_0807e854
	b _0807F2AE
_0807F268:
	adds r0, r4, #0
	bl FUN_0807eca8
	adds r0, r4, #0
	bl dark_django_0807f13c
	b _0807F2AE
_0807F276:
	cmp r0, #2
	bne _0807F2AE
	adds r0, r4, #0
	bl FUN_0806521c
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	bne _0807F290
	movs r0, #1
	strh r0, [r1]
_0807F290:
	ldr r1, _0807F320 @ =0x00000376
	adds r0, r4, r1
	movs r2, #0
	strh r2, [r0]
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r2, [r0]
	movs r0, #0xd8
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	ble _0807F2AE
	strh r2, [r1]
_0807F2AE:
	adds r0, r4, #0
	bl FUN_0807ee58
	ldr r1, _0807F324 @ =0x00000979
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	beq _0807F2C8
	ldr r0, _0807F328 @ =0x00000393
	bl PlaySound_082406e0
	movs r0, #0
	strb r0, [r5]
_0807F2C8:
	movs r1, #0xac
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080639f8
	adds r0, r4, #0
	bl FUN_080612a8
	ldr r0, _0807F32C @ =0x000003EA
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #0
	bne _0807F2FA
	adds r0, r4, #0
	bl FUN_0807ed04
_0807F2FA:
	ldr r0, [r4, #0x1c]
	cmp r0, #4
	beq _0807F316
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x2c
	str r1, [r0]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_08234660
_0807F316:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0807F320: .4byte 0x00000376
_0807F324: .4byte 0x00000979
_0807F328: .4byte 0x00000393
_0807F32C: .4byte 0x000003EA

	thumb_func_start FUN_0807f330
FUN_0807f330: @ 0x0807F330
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x88
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_080f8cac
	adds r0, r4, #0
	adds r0, #0x88
	bl FUN_0822f1c0
	adds r0, r4, #0
	adds r0, #0xe8
	bl FUN_0822a4e0
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_08236424
	adds r0, r4, #0
	adds r0, #0x24
	bl FUN_0823b284
	adds r0, r4, #0
	bl FUN_08063b24
	adds r0, r4, #0
	bl FUN_0807ddd4
	adds r0, r4, #0
	bl FUN_08060c60
	ldr r0, _0807F39C @ =0x03002BA8
	movs r1, #0
	str r1, [r0]
	ldr r0, _0807F3A0 @ =0x03002BF4
	strh r1, [r0]
	ldr r2, _0807F3A4 @ =0x03002BE0
	adds r0, r4, #0
	adds r0, #0x28
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	str r1, [r0]
	ldr r1, _0807F3A8 @ =0x03002B98
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0807F39C: .4byte 0x03002BA8
_0807F3A0: .4byte 0x03002BF4
_0807F3A4: .4byte 0x03002BE0
_0807F3A8: .4byte 0x03002B98
