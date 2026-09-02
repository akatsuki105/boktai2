	.include "asm/macros.inc"

	.syntax unified
	
	.text

@ EnemyXXX_Create でファイル分けしているだけなので他の敵のコードも混じっているかもしれない

	thumb_func_start FUN_0816a9b4
FUN_0816a9b4: @ 0x0816A9B4
	bx lr
	.align 2, 0

	thumb_func_start FUN_0816a9b8
FUN_0816a9b8: @ 0x0816A9B8
	push {r4, r5, r6, r7, lr}
	adds r5, r1, #0
	adds r4, r2, #0
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0816AA8E
	movs r1, #0x80
	lsls r1, r1, #7
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _0816AA8E
	ldrh r5, [r5, #0xa]
	cmp r5, #1
	bne _0816AA8E
	movs r7, #0xe6
	lsls r7, r7, #1
	adds r0, r4, r7
	ldr r6, [r0]
	ldr r2, _0816AA94 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r7, _0816AA98 @ =0x0000046D
	adds r0, r4, r7
	strb r5, [r0]
	subs r7, #2
	adds r0, r4, r7
	strb r3, [r0]
	adds r7, #0xe8
	adds r0, r4, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r2, #0
	strh r3, [r0]
	movs r1, #2
	subs r7, #0xeb
	adds r0, r4, r7
	strb r2, [r0]
	adds r7, #1
	adds r0, r4, r7
	strb r1, [r0]
	ldr r1, _0816AA9C @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _0816AAA0 @ =0x00000484
	adds r0, r4, r2
	str r3, [r0]
	adds r7, #3
	adds r0, r4, r7
	strb r5, [r0]
	movs r0, #0x94
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1, #6]
	movs r2, #4
	orrs r0, r2
	strh r0, [r1, #6]
	adds r1, r4, #0
	adds r1, #0xd8
	ldrh r0, [r1, #6]
	orrs r0, r2
	strh r0, [r1, #6]
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r4, r1
	ldr r0, _0816AAA4 @ =0xFFFFFE7F
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r2, _0816AAA8 @ =0x000007DC
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	ldr r0, _0816AAAC @ =0x03002BE0
	ldr r1, [r0]
	movs r3, #3
	ldr r7, _0816AAB0 @ =0x00000402
	adds r1, r1, r7
	ldrb r0, [r1]
	adds r0, #3
	strb r0, [r1]
	movs r2, #0x80
	ldr r0, _0816AAA8 @ =0x000007DC
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _0816AAB4 @ =0x0000083F
	adds r0, r6, r1
	strb r3, [r0]
	ldr r0, _0816AAB8 @ =0x000003CB
	bl PlaySound_082406e0
_0816AA8E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816AA94: .4byte FUN_080e48d0
_0816AA98: .4byte 0x0000046D
_0816AA9C: .4byte 0x0000046A
_0816AAA0: .4byte 0x00000484
_0816AAA4: .4byte 0xFFFFFE7F
_0816AAA8: .4byte 0x000007DC
_0816AAAC: .4byte 0x03002BE0
_0816AAB0: .4byte 0x00000402
_0816AAB4: .4byte 0x0000083F
_0816AAB8: .4byte 0x000003CB

	thumb_func_start FUN_0816aabc
FUN_0816aabc: @ 0x0816AABC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	mov r8, r1
	adds r6, r2, #0
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0816AADC
	b _0816B17A
_0816AADC:
	movs r5, #0x80
	lsls r5, r5, #7
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r5
	mov sl, r1
	cmp r0, #0
	beq _0816AAF2
	b _0816B17A
_0816AAF2:
	movs r1, #0x80
	lsls r1, r1, #4
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _0816AB00
	b _0816B17A
_0816AB00:
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _0816AB10
	b _0816B17A
_0816AB10:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0816AB3C
	ldr r3, _0816AB38 @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0816AB28
	b _0816B17A
_0816AB28:
	movs r1, #0
	mov r4, r8
	strh r2, [r4, #0x3e]
	mov r0, r8
	adds r0, #0x43
	strb r1, [r0]
	b _0816B17A
	.align 2, 0
_0816AB38: .4byte 0x0000048C
_0816AB3C:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r1, #4
	mov sb, r1
	ldrh r0, [r0, #6]
	ands r0, r1
	cmp r0, #0
	beq _0816AB4E
	b _0816B17A
_0816AB4E:
	movs r4, #1
	ldrh r3, [r7, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _0816AB5C
	b _0816AE54
_0816AB5C:
	ldr r1, [r7, #0x34]
	adds r0, r1, #0
	ands r0, r5
	adds r5, r1, #0
	cmp r0, #0
	bne _0816AB6A
	b _0816B17A
_0816AB6A:
	ldr r1, _0816ABF4 @ =0x0000A007
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0816AB78
	b _0816B17A
_0816AB78:
	movs r0, #0x91
	lsls r0, r0, #3
	adds r1, r6, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0816AB86
	b _0816B17A
_0816AB86:
	movs r0, #0x3c
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0x14
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	bne _0816AB9E
	b _0816ACE0
_0816AB9E:
	movs r1, #0x80
	lsls r1, r1, #1
	mov r2, r8
	ldrh r0, [r2, #6]
	ands r0, r1
	cmp r0, #0
	beq _0816AC04
	ands r3, r1
	cmp r3, #0
	beq _0816AC04
	mov r0, r8
	adds r0, #0x42
	ldrb r1, [r0]
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0816ABC6
	rsbs r1, r1, #0
_0816ABC6:
	cmp r1, #0x20
	bgt _0816AC04
	ldrh r0, [r7, #0x3c]
	ldr r3, _0816ABF8 @ =0x000004BE
	adds r1, r6, r3
	strh r0, [r1]
	ldr r2, _0816ABFC @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _0816AC00 @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _0816B17A
	.align 2, 0
_0816ABF4: .4byte 0x0000A007
_0816ABF8: .4byte 0x000004BE
_0816ABFC: .4byte 0x0000048C
_0816AC00: .4byte 0x0000044E
_0816AC04:
	movs r1, #0
	mov r0, r8
	strh r1, [r0, #0x3e]
	ldr r2, _0816AC2C @ =0x0000048A
	adds r0, r6, r2
	strh r1, [r0]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0816AC34
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0816AC30 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0816ACA2
	.align 2, 0
_0816AC2C: .4byte 0x0000048A
_0816AC30: .4byte 0x03002BE0
_0816AC34:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0816AC50
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0816AC4C @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0816ACA2
	.align 2, 0
_0816AC4C: .4byte 0x03002BE0
_0816AC50:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0816AC6C
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0816AC68 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0816ACA2
	.align 2, 0
_0816AC68: .4byte 0x03002BE0
_0816AC6C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0816AC88
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0816AC84 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0816ACA2
	.align 2, 0
_0816AC84: .4byte 0x03002BE0
_0816AC88:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0816AC9A
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	str r3, [r0]
	b _0816ACA2
_0816AC9A:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0816ACA4
_0816ACA2:
	movs r3, #1
_0816ACA4:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	ldr r1, [r7, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	str r5, [r0]
	ldr r4, _0816ACD4 @ =0x0000049C
	adds r0, r6, r4
	str r1, [r0]
	cmp r3, #0
	bne _0816ACC2
	b _0816AE14
_0816ACC2:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816ACD8
	movs r0, #1
	b _0816ACDA
	.align 2, 0
_0816ACD4: .4byte 0x0000049C
_0816ACD8:
	movs r0, #0
_0816ACDA:
	cmp r0, #0
	bne _0816ADB8
	b _0816ADD0
_0816ACE0:
	mov r1, r8
	strh r2, [r1, #0x3e]
	ldr r3, _0816AD08 @ =0x0000048A
	adds r0, r6, r3
	strh r2, [r0]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _0816AD10
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0816AD0C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0816AD82
	.align 2, 0
_0816AD08: .4byte 0x0000048A
_0816AD0C: .4byte 0x03002BE0
_0816AD10:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0816AD2C
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0816AD28 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0816AD82
	.align 2, 0
_0816AD28: .4byte 0x03002BE0
_0816AD2C:
	adds r0, r2, #0
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	beq _0816AD4C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0816AD48 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0816AD82
	.align 2, 0
_0816AD48: .4byte 0x03002BE0
_0816AD4C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0816AD68
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0816AD64 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0816AD82
	.align 2, 0
_0816AD64: .4byte 0x03002BE0
_0816AD68:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0816AD7A
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _0816AD82
_0816AD7A:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0816AD84
_0816AD82:
	movs r3, #1
_0816AD84:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	ldr r1, [r7, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	str r5, [r0]
	subs r4, #4
	adds r0, r6, r4
	str r1, [r0]
	cmp r3, #0
	beq _0816AE14
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816ADB2
	movs r0, #1
	b _0816ADB4
_0816ADB2:
	movs r0, #0
_0816ADB4:
	cmp r0, #0
	beq _0816ADD0
_0816ADB8:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0816ADCC @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0816ADDC
	.align 2, 0
_0816ADCC: .4byte 0x03002BE0
_0816ADD0:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0816AE14
_0816ADDC:
	ldr r1, [r0]
	movs r0, #8
	ldrsh r5, [r1, r0]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_0816AE14:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0816AE40
	ldr r0, _0816AE4C @ =0x0000024E
	adds r2, r6, r0
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r1, r6, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _0816AE40
	strh r1, [r2]
_0816AE40:
	ldr r0, _0816AE50 @ =0x0000048C
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	b _0816B17A
	.align 2, 0
_0816AE4C: .4byte 0x0000024E
_0816AE50: .4byte 0x0000048C
_0816AE54:
	ldr r0, _0816AE68 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0816AE6C
	movs r0, #1
	b _0816AE6E
	.align 2, 0
_0816AE68: .4byte 0x030047A4
_0816AE6C:
	movs r0, #0
_0816AE6E:
	cmp r0, #0
	beq _0816AE7C
	adds r0, r7, #0
	mov r1, r8
	bl FUN_08236640
	b _0816AE84
_0816AE7C:
	adds r0, r7, #0
	mov r1, r8
	bl FUN_08236524
_0816AE84:
	adds r0, r7, #0
	adds r0, #0x44
	ldrh r1, [r0]
	mov r0, r8
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _0816AEBC @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _0816AEC0 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _0816AEB2
	cmp r2, #0x17
	bne _0816AEC4
_0816AEB2:
	adds r0, r7, #0
	adds r0, #0x40
	ldrh r1, [r0]
	b _0816AEE4
	.align 2, 0
_0816AEBC: .4byte 0x0000048C
_0816AEC0: .4byte 0x000001DF
_0816AEC4:
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r7, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _0816AEB2
	adds r0, r7, #0
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r4, _0816AF0C @ =0x00000187
	adds r0, r6, r4
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0816AEE4
	movs r1, #0
_0816AEE4:
	mov r0, r8
	adds r0, #0x40
	strh r1, [r0]
	mov sb, r0
	movs r1, #6
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0816AF1A
	mov r3, r8
	ldrh r0, [r3, #0x3e]
	lsls r0, r0, #1
	strh r0, [r3, #0x3e]
	mov r4, sb
	ldrh r0, [r4]
	cmp r0, #0
	blt _0816AF10
	asrs r0, r0, #1
	b _0816AF16
	.align 2, 0
_0816AF0C: .4byte 0x00000187
_0816AF10:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_0816AF16:
	mov r1, sb
	strh r0, [r1]
_0816AF1A:
	ldrh r1, [r7, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0816AF38
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r2, _0816AF34 @ =0x000001DD
	adds r1, r6, r2
	b _0816AFAC
	.align 2, 0
_0816AF34: .4byte 0x000001DD
_0816AF38:
	mov r4, sp
	adds r3, r7, #0
	adds r3, #0xc
	mov r2, r8
	adds r2, #0xc
	mov r1, r8
	ldrh r0, [r1, #0xc]
	ldrh r1, [r7, #0xc]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r2, #4]
	ldrh r0, [r3, #4]
	subs r1, r1, r0
	strh r1, [r4, #4]
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _0816AF98
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _0816AF98
	ldr r2, _0816AF88 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0816AF8C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0816AF90 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _0816AF94 @ =0x000001DD
	adds r1, r6, r4
	b _0816AFAC
	.align 2, 0
_0816AF88: .4byte 0x030046B8
_0816AF8C: .4byte 0x000003FF
_0816AF90: .4byte 0x0203B400
_0816AF94: .4byte 0x000001DD
_0816AF98:
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	ldr r3, _0816AFCC @ =0x000001DD
	adds r1, r6, r3
_0816AFAC:
	strb r0, [r1]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0816AFD4
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0816AFD0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0816B042
	.align 2, 0
_0816AFCC: .4byte 0x000001DD
_0816AFD0: .4byte 0x03002BE0
_0816AFD4:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0816AFF0
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0816AFEC @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0816B042
	.align 2, 0
_0816AFEC: .4byte 0x03002BE0
_0816AFF0:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0816B00C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0816B008 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0816B042
	.align 2, 0
_0816B008: .4byte 0x03002BE0
_0816B00C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0816B028
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0816B024 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0816B042
	.align 2, 0
_0816B024: .4byte 0x03002BE0
_0816B028:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0816B03A
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _0816B042
_0816B03A:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0816B044
_0816B042:
	movs r3, #1
_0816B044:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	ldr r1, [r7, #0x34]
	ldr r2, [r7, #0x38]
	subs r4, #8
	adds r0, r6, r4
	str r1, [r0]
	ldr r1, _0816B074 @ =0x0000049C
	adds r0, r6, r1
	str r2, [r0]
	cmp r3, #0
	beq _0816B0DC
	movs r1, #2
	ldr r2, _0816B078 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816B07C
	movs r0, #1
	b _0816B07E
	.align 2, 0
_0816B074: .4byte 0x0000049C
_0816B078: .4byte 0x00000474
_0816B07C:
	movs r0, #0
_0816B07E:
	cmp r0, #0
	beq _0816B098
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0816B094 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0816B0A4
	.align 2, 0
_0816B094: .4byte 0x03002BE0
_0816B098:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0816B0DC
_0816B0A4:
	ldr r1, [r0]
	movs r0, #8
	ldrsh r5, [r1, r0]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_0816B0DC:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _0816B110
	movs r1, #0x80
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0816B110
	ldr r3, _0816B128 @ =0x0000024E
	adds r2, r6, r3
	movs r4, #0x96
	lsls r4, r4, #1
	adds r0, r4, #0
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	subs r3, #2
	adds r1, r6, r3
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _0816B110
	strh r1, [r2]
_0816B110:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _0816B12C @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _0816B130 @ =0x00000934
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816B134
	movs r0, #1
	b _0816B136
	.align 2, 0
_0816B128: .4byte 0x0000024E
_0816B12C: .4byte 0x030046A0
_0816B130: .4byte 0x00000934
_0816B134:
	movs r0, #0
_0816B136:
	ldr r1, _0816B18C @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _0816B150
	movs r0, #0
	mov r2, r8
	strh r0, [r2, #0x3e]
	mov r3, sb
	strh r0, [r3]
	strh r0, [r4]
	movs r0, #1
	ldr r1, [sp, #8]
	strb r0, [r1]
_0816B150:
	adds r0, r6, #0
	bl FUN_080e64e4
	mov r2, r8
	ldrh r0, [r2, #0x3e]
	strh r0, [r4]
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r1, r6, r3
	ldrh r0, [r7, #0x3e]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r7, #0x3e]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0816B17A:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816B18C: .4byte 0x0000048A

	thumb_func_start FUN_0816b190
FUN_0816b190: @ 0x0816B190
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _0816B1B8 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816B1BC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816B1BE
	.align 2, 0
_0816B1B8: .4byte 0x0000046D
_0816B1BC:
	movs r0, #0
_0816B1BE:
	cmp r0, #0
	beq _0816B1E4
	ldr r0, _0816B224 @ =0x03002BE0
	ldr r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r1, [r0]
	ldr r0, _0816B228 @ =0x00000842
	add r0, r8
	movs r2, #0
	strb r1, [r0]
	ldr r0, _0816B22C @ =0x000007E6
	add r0, r8
	strh r2, [r0]
	ldr r0, _0816B230 @ =0x00000482
	adds r1, r5, r0
	movs r0, #4
	strh r0, [r1]
_0816B1E4:
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_0816d438
	ldr r1, _0816B234 @ =0x000004C4
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _0816B238 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0816B244
	ldr r1, _0816B23C @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r2, _0816B240 @ =0x0000046E
	adds r7, r5, r2
	b _0816B2C6
	.align 2, 0
_0816B224: .4byte 0x03002BE0
_0816B228: .4byte 0x00000842
_0816B22C: .4byte 0x000007E6
_0816B230: .4byte 0x00000482
_0816B234: .4byte 0x000004C4
_0816B238: .4byte 0x0000025D
_0816B23C: .4byte 0x000004B7
_0816B240: .4byte 0x0000046E
_0816B244:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r3, _0816B2B4 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0816B2B8 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _0816B27E
	ldrb r0, [r7]
	cmp r0, #0
	bne _0816B27E
	cmp r4, #1
	bne _0816B270
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0816B2CA
_0816B270:
	cmp r4, #0
	bne _0816B27E
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0816B2CA
_0816B27E:
	strb r2, [r3]
	movs r1, #4
	mov sb, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0816B290
	movs r3, #6
_0816B290:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _0816B2BC
	ldr r0, [r6, #8]
	mov r2, sb
	orrs r0, r2
	b _0816B2C4
	.align 2, 0
_0816B2B4: .4byte 0x000004B7
_0816B2B8: .4byte 0x0000046E
_0816B2BC:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0816B2C4:
	str r0, [r6, #8]
_0816B2C6:
	movs r0, #0
	strb r0, [r7]
_0816B2CA:
	movs r3, #0x90
	lsls r3, r3, #3
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _0816B308
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	ldr r1, _0816B300 @ =0x000007E4
	add r1, r8
	ldrb r1, [r1]
	bl Mod
	cmp r0, #0
	bne _0816B344
	ldr r0, _0816B304 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0x89
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r1, [r1]
	bl FUN_0807aa60
	b _0816B344
	.align 2, 0
_0816B300: .4byte 0x000007E4
_0816B304: .4byte 0x03002BE0
_0816B308:
	cmp r0, #1
	bne _0816B344
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	ldr r1, _0816B364 @ =0x000007E4
	add r1, r8
	ldrb r1, [r1]
	bl Mod
	cmp r0, #0
	bne _0816B332
	ldr r0, _0816B368 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0x89
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r1, [r1]
	bl FUN_0807aa60
_0816B332:
	ldr r0, _0816B368 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _0816B344
	movs r2, #0xe1
	lsls r2, r2, #2
	movs r1, #2
	bl FUN_08063574
_0816B344:
	ldr r0, _0816B36C @ =0x00000842
	add r0, r8
	ldrb r2, [r0]
	ldr r0, _0816B368 @ =0x03002BE0
	ldr r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r1, [r0]
	cmp r1, r2
	bge _0816B374
	ldr r3, _0816B370 @ =0xFFFFFF00
	adds r0, r2, r3
	subs r4, r1, r0
	b _0816B376
	.align 2, 0
_0816B364: .4byte 0x000007E4
_0816B368: .4byte 0x03002BE0
_0816B36C: .4byte 0x00000842
_0816B370: .4byte 0xFFFFFF00
_0816B374:
	subs r4, r1, r2
_0816B376:
	ldr r6, _0816B3C0 @ =0x00000841
	add r6, r8
	ldrb r0, [r6]
	cmp r0, r4
	beq _0816B39A
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _0816B398
	movs r0, #0x20
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0816B398:
	strb r4, [r6]
_0816B39A:
	ldr r0, _0816B3C0 @ =0x00000841
	add r0, r8
	ldr r1, _0816B3C4 @ =0x000007E5
	add r1, r8
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bls _0816B3B2
	ldr r2, _0816B3C8 @ =0x0000046B
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
_0816B3B2:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816B3C0: .4byte 0x00000841
_0816B3C4: .4byte 0x000007E5
_0816B3C8: .4byte 0x0000046B

	thumb_func_start FUN_0816b3cc
FUN_0816b3cc: @ 0x0816B3CC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _0816B424 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816B3E4
	movs r0, #0
	strb r0, [r1]
_0816B3E4:
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_0816d438
	ldr r1, _0816B428 @ =0x000004C4
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _0816B42C @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0816B438
	ldr r1, _0816B430 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r0, _0816B434 @ =0x0000046E
	adds r7, r5, r0
	b _0816B4BA
	.align 2, 0
_0816B424: .4byte 0x0000046D
_0816B428: .4byte 0x000004C4
_0816B42C: .4byte 0x0000025D
_0816B430: .4byte 0x000004B7
_0816B434: .4byte 0x0000046E
_0816B438:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _0816B4A8 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0816B4AC @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _0816B472
	ldrb r0, [r7]
	cmp r0, #0
	bne _0816B472
	cmp r4, #1
	bne _0816B464
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0816B4BE
_0816B464:
	cmp r4, #0
	bne _0816B472
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0816B4BE
_0816B472:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0816B484
	movs r3, #6
_0816B484:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _0816B4B0
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _0816B4B8
	.align 2, 0
_0816B4A8: .4byte 0x000004B7
_0816B4AC: .4byte 0x0000046E
_0816B4B0:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0816B4B8:
	str r0, [r6, #8]
_0816B4BA:
	movs r0, #0
	strb r0, [r7]
_0816B4BE:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0816b4cc
FUN_0816b4cc: @ 0x0816B4CC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _0816B4E8 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816B4EC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816B4EE
	.align 2, 0
_0816B4E8: .4byte 0x0000046D
_0816B4EC:
	movs r0, #0
_0816B4EE:
	cmp r0, #0
	beq _0816B4FA
	ldr r0, _0816B544 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
_0816B4FA:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080ef86c
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_0816d438
	ldr r1, _0816B548 @ =0x000004C4
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _0816B54C @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0816B558
	ldr r1, _0816B550 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r0, _0816B554 @ =0x0000046E
	adds r7, r5, r0
	b _0816B5DA
	.align 2, 0
_0816B544: .4byte 0x00000482
_0816B548: .4byte 0x000004C4
_0816B54C: .4byte 0x0000025D
_0816B550: .4byte 0x000004B7
_0816B554: .4byte 0x0000046E
_0816B558:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _0816B5C8 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0816B5CC @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _0816B592
	ldrb r0, [r7]
	cmp r0, #0
	bne _0816B592
	cmp r4, #1
	bne _0816B584
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0816B5DE
_0816B584:
	cmp r4, #0
	bne _0816B592
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0816B5DE
_0816B592:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0816B5A4
	movs r3, #6
_0816B5A4:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _0816B5D0
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _0816B5D8
	.align 2, 0
_0816B5C8: .4byte 0x000004B7
_0816B5CC: .4byte 0x0000046E
_0816B5D0:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0816B5D8:
	str r0, [r6, #8]
_0816B5DA:
	movs r0, #0
	strb r0, [r7]
_0816B5DE:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0816b5ec
FUN_0816b5ec: @ 0x0816B5EC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	adds r6, r5, #0
	ldr r0, _0816B60C @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816B610
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816B612
	.align 2, 0
_0816B60C: .4byte 0x0000046D
_0816B610:
	movs r0, #0
_0816B612:
	cmp r0, #0
	beq _0816B6B0
	ldrb r0, [r5, #5]
	adds r0, #0x10
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #5
	adds r3, r0, #3
	movs r1, #7
	ands r3, r1
	movs r4, #0xee
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrb r4, [r0]
	adds r0, r4, #0
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	ands r0, r1
	cmp r3, r0
	bne _0816B680
	movs r1, #0
	strb r4, [r5, #5]
	ldr r2, _0816B674 @ =0x000005A4
	adds r0, r5, r2
	ldr r3, [r0]
	ldr r4, _0816B678 @ =0x0000046D
	adds r0, r5, r4
	movs r2, #1
	strb r2, [r0]
	subs r4, #2
	adds r0, r5, r4
	strb r1, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	adds r4, #0x25
	adds r0, r5, r4
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	ldr r4, _0816B67C @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	b _0816B872
	.align 2, 0
_0816B674: .4byte 0x000005A4
_0816B678: .4byte 0x0000046D
_0816B67C: .4byte 0x0000046B
_0816B680:
	subs r0, #8
	subs r0, r3, r0
	movs r1, #7
	ands r0, r1
	cmp r0, #4
	bgt _0816B6A0
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r1, _0816B69C @ =0xFFFEFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _0816B6B0
	.align 2, 0
_0816B69C: .4byte 0xFFFEFFFF
_0816B6A0:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0816B6B0:
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	mov r8, r0
	ldr r1, _0816B6D4 @ =0x0000A02F
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816B6DC
	ldr r0, _0816B6D8 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0816B6EC
	.align 2, 0
_0816B6D4: .4byte 0x0000A02F
_0816B6D8: .4byte 0x00000482
_0816B6DC:
	ldr r1, _0816B714 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0816B6EC
	movs r0, #1
	strh r0, [r2]
_0816B6EC:
	ldr r3, _0816B718 @ =0x0000025D
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r7, r0, #0
	cmp r1, #0
	bne _0816B71C
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _0816B734
	.align 2, 0
_0816B714: .4byte 0x00000482
_0816B718: .4byte 0x0000025D
_0816B71C:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_0816B734:
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _0816B746
	b _0816B872
_0816B746:
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r2, _0816B790 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0816B794 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
	movs r1, #0x80
	lsls r1, r1, #9
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816B798
	ldrb r0, [r6, #5]
	adds r0, #0x20
	b _0816B79C
	.align 2, 0
_0816B790: .4byte 0x0000046D
_0816B794: .4byte 0x0000046B
_0816B798:
	ldrb r0, [r6, #5]
	subs r0, #0x20
_0816B79C:
	strb r0, [r6, #5]
	ldrb r0, [r6, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_0816d438
	movs r0, #0
	mov r3, r8
	strb r0, [r3, #5]
	ldr r4, _0816B7E0 @ =0x000004C4
	adds r0, r5, r4
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldrb r0, [r7]
	cmp r0, #0
	bne _0816B7EC
	ldr r1, _0816B7E4 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r2, _0816B7E8 @ =0x0000046E
	adds r7, r5, r2
	b _0816B86E
	.align 2, 0
_0816B7E0: .4byte 0x000004C4
_0816B7E4: .4byte 0x000004B7
_0816B7E8: .4byte 0x0000046E
_0816B7EC:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r3, _0816B85C @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0816B860 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _0816B826
	ldrb r0, [r7]
	cmp r0, #0
	bne _0816B826
	cmp r4, #1
	bne _0816B818
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0816B872
_0816B818:
	cmp r4, #0
	bne _0816B826
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0816B872
_0816B826:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0816B838
	movs r3, #6
_0816B838:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _0816B864
	ldr r0, [r6, #8]
	mov r2, r8
	orrs r0, r2
	b _0816B86C
	.align 2, 0
_0816B85C: .4byte 0x000004B7
_0816B860: .4byte 0x0000046E
_0816B864:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0816B86C:
	str r0, [r6, #8]
_0816B86E:
	movs r0, #0
	strb r0, [r7]
_0816B872:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0816b880
FUN_0816b880: @ 0x0816B880
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	mov sb, r1
	ldr r0, _0816B8DC @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816B89C
	movs r0, #0
	strb r0, [r1]
_0816B89C:
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_0816d438
	ldr r1, _0816B8E0 @ =0x000004EC
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _0816B8E4 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0816B8F0
	ldr r1, _0816B8E8 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r0, _0816B8EC @ =0x0000046E
	adds r7, r5, r0
	b _0816B972
	.align 2, 0
_0816B8DC: .4byte 0x0000046D
_0816B8E0: .4byte 0x000004EC
_0816B8E4: .4byte 0x0000025D
_0816B8E8: .4byte 0x000004B7
_0816B8EC: .4byte 0x0000046E
_0816B8F0:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _0816B960 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0816B964 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _0816B92A
	ldrb r0, [r7]
	cmp r0, #0
	bne _0816B92A
	cmp r4, #1
	bne _0816B91C
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0816B976
_0816B91C:
	cmp r4, #0
	bne _0816B92A
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0816B976
_0816B92A:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0816B93C
	movs r3, #6
_0816B93C:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _0816B968
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _0816B970
	.align 2, 0
_0816B960: .4byte 0x000004B7
_0816B964: .4byte 0x0000046E
_0816B968:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0816B970:
	str r0, [r6, #8]
_0816B972:
	movs r0, #0
	strb r0, [r7]
_0816B976:
	mov r0, sb
	cmp r0, #0x1d
	bgt _0816B98A
	movs r0, #0x20
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0816B98A:
	mov r0, sb
	cmp r0, #0x3b
	ble _0816B998
	ldr r0, _0816B9A8 @ =0x0000046B
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_0816B998:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816B9A8: .4byte 0x0000046B

	thumb_func_start FUN_0816b9ac
FUN_0816b9ac: @ 0x0816B9AC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _0816B9C4 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816B9C8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816B9CA
	.align 2, 0
_0816B9C4: .4byte 0x0000046D
_0816B9C8:
	movs r0, #0
_0816B9CA:
	cmp r0, #0
	beq _0816B9D6
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_080ef86c
_0816B9D6:
	cmp r5, #0x1d
	bgt _0816B9E8
	movs r0, #0x20
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0816B9E8:
	cmp r5, #0x3b
	ble _0816B9F4
	ldr r0, _0816B9FC @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_0816B9F4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0816B9FC: .4byte 0x0000046B

	thumb_func_start FUN_0816ba00
FUN_0816ba00: @ 0x0816BA00
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	adds r4, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, _0816BA2C @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816BA30
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816BA32
	.align 2, 0
_0816BA2C: .4byte 0x0000046D
_0816BA30:
	movs r0, #0
_0816BA32:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r6, r7, r3
	cmp r0, #0
	beq _0816BA7C
	movs r0, #0x20
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
	movs r1, #8
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0816BA68
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #0x95
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0816BA70
_0816BA68:
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0816BA70:
	adds r0, r7, #0
	bl FUN_0816d50c
	adds r0, r7, #0
	bl FUN_0816d3b8
_0816BA7C:
	movs r1, #8
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0816BAE8
	adds r0, r4, #0
	movs r1, #0xc
	bl Mod
	cmp r0, #0
	bne _0816BAE8
	ldr r2, _0816BB08 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x3c
	orrs r0, r1
	ldr r1, _0816BB0C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r1, #0x28
	orrs r0, r1
	str r0, [sp, #0x14]
	ldr r2, _0816BB10 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0816BB14 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r5, _0816BB18 @ =0x0203B400
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	adds r0, r7, #0
	adds r0, #8
	ldrb r3, [r7, #5]
	adds r3, #0x80
	movs r2, #0xa
	str r2, [sp]
	movs r2, #6
	str r2, [sp, #4]
	movs r2, #2
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	add r2, sp, #0x10
	bl FUN_080ddcc8
_0816BAE8:
	movs r1, #0x83
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r5, #0x85
	lsls r5, r5, #2
	adds r1, r7, r5
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _0816BB1C
	asrs r0, r0, #2
	b _0816BB22
	.align 2, 0
_0816BB08: .4byte 0xFFFF0000
_0816BB0C: .4byte 0x0000FFFF
_0816BB10: .4byte 0x030046B8
_0816BB14: .4byte 0x000003FF
_0816BB18: .4byte 0x0203B400
_0816BB1C:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0816BB22:
	adds r3, r0, #0
	movs r5, #0x84
	lsls r5, r5, #2
	adds r0, r7, r5
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r5, #8
	adds r1, r7, r5
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	cmp r0, #0
	blt _0816BB40
	asrs r0, r0, #2
	b _0816BB46
_0816BB40:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0816BB46:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _0816BB50
	movs r3, #0xc8
	b _0816BB5A
_0816BB50:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _0816BB5A
	adds r3, r0, #0
_0816BB5A:
	cmp r2, #0xc8
	ble _0816BB62
	movs r2, #0xc8
	b _0816BB6C
_0816BB62:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _0816BB6C
	adds r2, r0, #0
_0816BB6C:
	ldrh r0, [r7, #0x10]
	adds r0, r0, r3
	strh r0, [r7, #0x10]
	ldrh r0, [r7, #0x14]
	adds r0, r0, r2
	strh r0, [r7, #0x14]
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _0816BB90
	cmp r2, #0
	bne _0816BB90
	movs r0, #1
	b _0816BB92
_0816BB90:
	movs r0, #0
_0816BB92:
	cmp r0, #0
	beq _0816BC18
	ldr r1, _0816BC28 @ =0x0000046B
	adds r0, r7, r1
	movs r2, #0
	mov r8, r2
	movs r5, #1
	strb r5, [r0]
	adds r0, r7, #0
	bl FUN_0816de68
	movs r0, #0x29
	rsbs r0, r0, #0
	ldrh r1, [r6]
	ands r0, r1
	movs r4, #0
	strh r0, [r6]
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r2, r7, r3
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_0816d3b8
	movs r2, #0x10
	ldr r1, _0816BC2C @ =0x000007DC
	add r1, sb
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x93
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r2, _0816BC30 @ =0x0000024E
	adds r0, r7, r2
	strh r1, [r0]
	movs r1, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r4, [r0]
	ldr r2, _0816BC34 @ =0x00000469
	adds r0, r7, r2
	strb r1, [r0]
	adds r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _0816BC38 @ =0x00000484
	adds r0, r7, r1
	mov r2, r8
	str r2, [r0]
	adds r3, #2
	adds r0, r7, r3
	strb r5, [r0]
_0816BC18:
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816BC28: .4byte 0x0000046B
_0816BC2C: .4byte 0x000007DC
_0816BC30: .4byte 0x0000024E
_0816BC34: .4byte 0x00000469
_0816BC38: .4byte 0x00000484

	thumb_func_start FUN_0816bc3c
FUN_0816bc3c: @ 0x0816BC3C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x4c
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _0816BC64 @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816BC68
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816BC6A
	.align 2, 0
_0816BC64: .4byte 0x0000046D
_0816BC68:
	movs r0, #0
_0816BC6A:
	cmp r0, #0
	beq _0816BD1A
	adds r0, r4, #0
	movs r1, #0xa
	bl FUN_080ef86c
	adds r0, r4, #0
	bl FUN_080e8360
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r2, r4, r3
	ldr r1, _0816BDC0 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r7, _0816BDC4 @ =0x0000021E
	adds r0, r4, r7
	movs r1, #0
	strh r1, [r0]
	movs r2, #0x88
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	adds r3, #0x8a
	adds r0, r4, r3
	strh r1, [r0]
	adds r2, r4, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	adds r0, r4, #0
	bl FUN_0816de68
	movs r1, #0x80
	lsls r1, r1, #7
	subs r7, #0x9e
	adds r0, r4, r7
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0816BD1A
	ldr r2, _0816BDC8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0816BDCC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0816BDD0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	adds r6, r0, #1
	adds r7, r4, #0
	adds r7, #8
	ldrh r3, [r4, #8]
	ldrh r5, [r4, #0xa]
	ldrh r2, [r4, #0xc]
	add r0, sp, #0xc
	movs r1, #2
_0816BCEC:
	strh r3, [r0]
	strh r5, [r0, #2]
	strh r2, [r0, #4]
	adds r0, #8
	subs r1, #1
	cmp r1, #0
	bge _0816BCEC
	movs r0, #0x84
	lsls r0, r0, #4
	add r0, r8
	ldrb r2, [r0]
	add r3, sp, #0xc
	str r3, [sp]
	movs r0, #0x96
	lsls r0, r0, #1
	str r0, [sp, #4]
	movs r0, #0x78
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	adds r3, r7, #0
	bl FUN_0800ac80
_0816BD1A:
	ldr r7, _0816BDD4 @ =0x0000046E
	adds r0, r4, r7
	ldrb r0, [r0]
	cmp r0, #0
	bne _0816BD26
	b _0816BE6A
_0816BD26:
	ldr r1, _0816BDD8 @ =0x0000046B
	adds r0, r4, r1
	movs r5, #1
	strb r5, [r0]
	adds r0, r4, #0
	bl FUN_080e6658
	movs r3, #0xcd
	lsls r3, r3, #1
	adds r2, r4, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _0816BD96
	movs r7, #8
	ldrsh r0, [r4, r7]
	str r0, [sp, #0x24]
	movs r1, #0xa
	ldrsh r0, [r4, r1]
	str r0, [sp, #0x28]
	movs r3, #0xc
	ldrsh r0, [r4, r3]
	str r0, [sp, #0x2c]
	movs r7, #0xce
	lsls r7, r7, #1
	adds r0, r4, r7
	ldr r0, [r0]
	str r0, [sp, #0x30]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	str r0, [sp, #0x34]
	movs r3, #0xd2
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r0, [r0]
	str r0, [sp, #0x38]
	movs r7, #0x94
	lsls r7, r7, #3
	adds r0, r4, r7
	ldr r0, [r0]
	str r0, [sp, #0x3c]
	ldrh r0, [r4]
	str r0, [sp, #0x40]
	ldr r1, _0816BDDC @ =0xFFFF0000
	ldr r0, [sp, #0x44]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x44]
	add r0, sp, #0x24
	add r1, sp, #0x44
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_0816BD96:
	ldr r1, _0816BDE0 @ =0x000001DF
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r4, r2
	ldrh r1, [r1]
	bl FUN_0820ccd0
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _0816BDE8
	ldr r0, _0816BDE4 @ =0x030046A0
	ldr r2, [r0]
	movs r7, #0xe2
	lsls r7, r7, #2
	adds r2, r2, r7
	adds r1, r5, #0
	lsls r1, r3
	b _0816BDFA
	.align 2, 0
_0816BDC0: .4byte 0xFFFEBE3F
_0816BDC4: .4byte 0x0000021E
_0816BDC8: .4byte 0x030046B8
_0816BDCC: .4byte 0x000003FF
_0816BDD0: .4byte 0x0203B400
_0816BDD4: .4byte 0x0000046E
_0816BDD8: .4byte 0x0000046B
_0816BDDC: .4byte 0xFFFF0000
_0816BDE0: .4byte 0x000001DF
_0816BDE4: .4byte 0x030046A0
_0816BDE8:
	ldr r0, _0816BE78 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r5, #0
	lsls r1, r0
_0816BDFA:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r2, #0xc9
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r6, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #7
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne _0816BE6A
	ldr r3, _0816BE7C @ =FUN_080e48d0
	movs r2, #0x10
	ldr r7, _0816BE80 @ =0x0000046D
	adds r0, r4, r7
	movs r1, #1
	strb r1, [r0]
	subs r7, #2
	adds r0, r4, r7
	strb r6, [r0]
	adds r7, #0xe8
	adds r0, r4, r7
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r4, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r5, [r0]
	movs r2, #2
	subs r7, #0xeb
	adds r0, r4, r7
	strb r1, [r0]
	ldr r3, _0816BE84 @ =0x00000469
	adds r0, r4, r3
	strb r6, [r0]
	adds r7, #2
	adds r0, r4, r7
	strb r2, [r0]
	ldr r2, _0816BE88 @ =0x00000484
	adds r0, r4, r2
	str r5, [r0]
	adds r3, #3
	adds r0, r4, r3
	strb r1, [r0]
_0816BE6A:
	add sp, #0x4c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816BE78: .4byte 0x030046A0
_0816BE7C: .4byte FUN_080e48d0
_0816BE80: .4byte 0x0000046D
_0816BE84: .4byte 0x00000469
_0816BE88: .4byte 0x00000484

	thumb_func_start FUN_0816be8c
FUN_0816be8c: @ 0x0816BE8C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _0816BEAC @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816BEB0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816BEB2
	.align 2, 0
_0816BEAC: .4byte 0x0000046C
_0816BEB0:
	movs r0, #0
_0816BEB2:
	cmp r0, #0
	beq _0816BEFC
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	movs r4, #1
	ldr r2, _0816BF28 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	strb r4, [r0]
	ldr r3, _0816BF2C @ =0x0000046B
	adds r0, r5, r3
	strb r2, [r0]
	adds r3, #0xe8
	adds r0, r5, r3
	strb r4, [r0]
	adds r3, #0x25
	adds r0, r5, r3
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	ldr r3, _0816BF30 @ =0x00000888
	adds r1, r7, r3
	str r2, [sp]
	mov r0, sp
	ldr r2, _0816BF34 @ =0x05000002
	bl CpuSet
	ldr r1, _0816BF38 @ =0x0000083B
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _0816BF3C @ =0x00000482
	adds r0, r5, r2
	strh r4, [r0]
_0816BEFC:
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r0, #0
	ldr r1, _0816BF40 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816BF44
	ldr r3, _0816BF3C @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0816BF54
	.align 2, 0
_0816BF28: .4byte 0x0000046D
_0816BF2C: .4byte 0x0000046B
_0816BF30: .4byte 0x00000888
_0816BF34: .4byte 0x05000002
_0816BF38: .4byte 0x0000083B
_0816BF3C: .4byte 0x00000482
_0816BF40: .4byte 0x0000A02F
_0816BF44:
	ldr r1, _0816BF78 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0816BF54
	movs r0, #1
	strh r0, [r2]
_0816BF54:
	ldr r3, _0816BF7C @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0816BF80
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _0816BF98
	.align 2, 0
_0816BF78: .4byte 0x00000482
_0816BF7C: .4byte 0x0000025D
_0816BF80:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_0816BF98:
	adds r0, r5, #0
	bl FUN_0816ce08
	ldr r1, _0816BFD8 @ =0x000004A4
	adds r0, r5, r1
	ldr r1, [r0]
	ldrh r2, [r1, #0xc]
	ldrh r0, [r5, #8]
	subs r2, r2, r0
	lsls r2, r2, #0x10
	ldrh r0, [r1, #0x10]
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsrs r3, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0
	bge _0816BFC0
	rsbs r2, r2, #0
_0816BFC0:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _0816BFDC
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _0816BFCE
	rsbs r2, r2, #0
_0816BFCE:
	cmp r2, #0x20
	bgt _0816BFDC
	movs r0, #1
	b _0816C046
	.align 2, 0
_0816BFD8: .4byte 0x000004A4
_0816BFDC:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _0816BFE8
	cmp r1, #0
	beq _0816C044
_0816BFE8:
	asrs r1, r1, #0x10
	bl FUN_0823785c
	strb r0, [r5, #5]
	ldr r2, _0816C00C @ =0x085B0A08
	ldrb r0, [r5, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0816C010
	asrs r1, r0, #0xc
	b _0816C016
	.align 2, 0
_0816C00C: .4byte 0x085B0A08
_0816C010:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816C016:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldr r1, _0816C034 @ =0x085B0A08
	ldrb r0, [r5, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r6, r0
	cmp r0, #0
	blt _0816C038
	asrs r1, r0, #0xc
	b _0816C03E
	.align 2, 0
_0816C034: .4byte 0x085B0A08
_0816C038:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816C03E:
	ldrh r0, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
_0816C044:
	movs r0, #0
_0816C046:
	cmp r0, #0
	bne _0816C04C
	b _0816C14E
_0816C04C:
	adds r0, r5, #0
	bl FUN_0816cfe0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0816C05A
	b _0816C14E
_0816C05A:
	ldr r0, _0816C07C @ =0x00000888
	adds r3, r7, r0
	ldrb r4, [r5, #5]
	ldr r2, _0816C080 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0816C084
	asrs r1, r0, #0xc
	b _0816C08A
	.align 2, 0
_0816C07C: .4byte 0x00000888
_0816C080: .4byte 0x085B0A08
_0816C084:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816C08A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0816C0A2
	asrs r0, r0, #0xc
	b _0816C0A8
_0816C0A2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0816C0A8:
	strh r0, [r3, #4]
	adds r0, r5, #0
	bl FUN_0816ce70
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0816C14E
	add r6, sp, #4
	adds r0, r5, #0
	adds r0, #0x9c
	ldr r1, [r0, #8]
	ldrh r0, [r1]
	strh r0, [r6]
	ldrh r1, [r1, #2]
	strh r1, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r7, r6, #0
	cmp r2, #0
	blt _0816C0E8
	cmp r1, #0
	blt _0816C0E8
	ldr r0, _0816C0EC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0816C0E8
	ldr r0, _0816C0F0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0816C0F4
_0816C0E8:
	movs r4, #0
	b _0816C102
	.align 2, 0
_0816C0EC: .4byte 0x030046A8
_0816C0F0: .4byte 0x030046AC
_0816C0F4:
	ldr r0, _0816C114 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0816C102:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0816C118
	adds r0, #4
	b _0816C124
	.align 2, 0
_0816C114: .4byte 0x030046A4
_0816C118:
	ldr r0, _0816C138 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0816C124:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0816C13C
	cmp r2, #2
	beq _0816C140
	b _0816C144
	.align 2, 0
_0816C138: .4byte 0x030046A4
_0816C13C:
	ldrb r0, [r6, #4]
	b _0816C142
_0816C140:
	ldrb r0, [r6]
_0816C142:
	subs r1, r1, r0
_0816C144:
	strh r1, [r6, #2]
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_0816d468
_0816C14E:
	ldr r3, _0816C160 @ =0x00000484
	adds r1, r5, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816C160: .4byte 0x00000484

	thumb_func_start FUN_0816c164
FUN_0816c164: @ 0x0816C164
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _0816C184 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816C188
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816C18A
	.align 2, 0
_0816C184: .4byte 0x0000046C
_0816C188:
	movs r0, #0
_0816C18A:
	cmp r0, #0
	beq _0816C1BE
	movs r3, #0xb2
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r4, [r0]
	movs r3, #2
	ldr r0, _0816C244 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0816C248 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
_0816C1BE:
	ldr r0, _0816C24C @ =0x00000888
	adds r6, r7, r0
	ldrh r0, [r6]
	ldrh r1, [r5, #0x10]
	adds r0, r0, r1
	movs r3, #0
	strh r0, [r5, #0x10]
	ldr r2, _0816C250 @ =0x0000088C
	adds r4, r7, r2
	ldrh r0, [r4]
	ldrh r1, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
	ldr r2, _0816C254 @ =0x00000484
	adds r7, r5, r2
	ldr r0, [r7]
	movs r1, #4
	str r3, [sp]
	bl Mod
	ldr r3, [sp]
	cmp r0, #0
	bne _0816C1FC
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	strh r0, [r6]
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	strh r0, [r4]
_0816C1FC:
	ldr r4, _0816C248 @ =0x0000046B
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _0816C28C
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _0816C260
	movs r1, #2
	movs r2, #1
	subs r4, #3
	adds r0, r5, r4
	strb r3, [r0]
	ldr r3, _0816C258 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	adds r4, #2
	adds r0, r5, r4
	strb r2, [r0]
	ldr r0, _0816C254 @ =0x00000484
	adds r1, r5, r0
	movs r0, #0
	str r0, [r1]
	ldr r1, _0816C25C @ =0x0000046C
	adds r0, r5, r1
	strb r2, [r0]
	b _0816C292
	.align 2, 0
_0816C244: .4byte 0x0000046D
_0816C248: .4byte 0x0000046B
_0816C24C: .4byte 0x00000888
_0816C250: .4byte 0x0000088C
_0816C254: .4byte 0x00000484
_0816C258: .4byte 0x00000469
_0816C25C: .4byte 0x0000046C
_0816C260:
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r3, [r0]
	ldr r4, _0816C284 @ =0x00000469
	adds r0, r5, r4
	strb r3, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r3, [r0]
	ldr r3, _0816C288 @ =0x00000484
	adds r0, r5, r3
	str r1, [r0]
	adds r4, #3
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
	b _0816C292
	.align 2, 0
_0816C284: .4byte 0x00000469
_0816C288: .4byte 0x00000484
_0816C28C:
	ldr r0, [r7]
	adds r0, #1
	str r0, [r7]
_0816C292:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0816c29c
FUN_0816c29c: @ 0x0816C29C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, _0816C2C4 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816C2C8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816C2CA
	.align 2, 0
_0816C2C4: .4byte 0x0000046C
_0816C2C8:
	movs r0, #0
_0816C2CA:
	cmp r0, #0
	beq _0816C300
	ldr r1, _0816C348 @ =0x000005A4
	adds r0, r6, r1
	ldr r3, [r0]
	movs r2, #0
	ldr r0, _0816C34C @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0816C350 @ =0x0000046B
	adds r0, r6, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r6, r1
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #0
	strh r2, [r0]
	ldr r0, _0816C354 @ =0x0000083A
	add r0, sb
	strb r1, [r0]
_0816C300:
	ldr r2, _0816C358 @ =0x00000484
	adds r0, r6, r2
	ldr r0, [r0]
	cmp r0, #0x3c
	bgt _0816C30C
	b _0816C432
_0816C30C:
	adds r0, r6, #0
	bl FUN_0816ce70
	add r7, sp, #4
	adds r0, r6, #0
	adds r0, #0x9c
	ldr r1, [r0, #8]
	ldrh r0, [r1]
	strh r0, [r7]
	ldrh r1, [r1, #2]
	strh r1, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r5, r7, #0
	cmp r2, #0
	blt _0816C344
	cmp r1, #0
	blt _0816C344
	ldr r0, _0816C35C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0816C344
	ldr r0, _0816C360 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0816C364
_0816C344:
	movs r4, #0
	b _0816C372
	.align 2, 0
_0816C348: .4byte 0x000005A4
_0816C34C: .4byte 0x0000046D
_0816C350: .4byte 0x0000046B
_0816C354: .4byte 0x0000083A
_0816C358: .4byte 0x00000484
_0816C35C: .4byte 0x030046A8
_0816C360: .4byte 0x030046AC
_0816C364:
	ldr r0, _0816C384 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0816C372:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0816C388
	adds r0, #4
	b _0816C394
	.align 2, 0
_0816C384: .4byte 0x030046A4
_0816C388:
	ldr r0, _0816C3A8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0816C394:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0816C3AC
	cmp r2, #2
	beq _0816C3B0
	b _0816C3B4
	.align 2, 0
_0816C3A8: .4byte 0x030046A4
_0816C3AC:
	ldrb r0, [r7, #4]
	b _0816C3B2
_0816C3B0:
	ldrb r0, [r7]
_0816C3B2:
	subs r1, r1, r0
_0816C3B4:
	movs r4, #0
	movs r0, #0
	mov r8, r0
	strh r1, [r7, #2]
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_0816cfa4
	adds r0, r6, #0
	bl FUN_0816cfe0
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r4, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r4, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _0816C44C @ =0x00000484
	adds r0, r6, r1
	mov r2, r8
	str r2, [r0]
	ldr r0, _0816C450 @ =0x0000046C
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	adds r3, r6, #0
	adds r3, #8
	add r2, sp, #4
	ldrh r0, [r2]
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r5, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r5, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r2, #4
	ldrsh r1, [r5, r2]
	bl FUN_0823785c
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	ldr r1, _0816C454 @ =0x00000888
	add r1, sb
	mov r0, r8
	str r0, [sp]
	mov r0, sp
	ldr r2, _0816C458 @ =0x05000002
	bl CpuSet
_0816C432:
	ldr r2, _0816C44C @ =0x00000484
	adds r1, r6, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816C44C: .4byte 0x00000484
_0816C450: .4byte 0x0000046C
_0816C454: .4byte 0x00000888
_0816C458: .4byte 0x05000002

	thumb_func_start FUN_0816c45c
FUN_0816c45c: @ 0x0816C45C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _0816C47C @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816C480
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816C482
	.align 2, 0
_0816C47C: .4byte 0x0000046C
_0816C480:
	movs r0, #0
_0816C482:
	cmp r0, #0
	beq _0816C564
	ldr r3, _0816C4EC @ =FUN_0816b9ac
	movs r2, #0x23
	ldr r6, _0816C4F0 @ =0x0000046D
	adds r1, r5, r6
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0816C4F4 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	adds r0, r5, #0
	bl FUN_0816de68
	ldr r2, _0816C4F8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0816C4FC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r6, _0816C500 @ =0x0203B400
	adds r0, r0, r6
	ldrb r6, [r0]
	ldr r0, _0816C504 @ =0x00000888
	adds r1, r7, r0
	str r4, [sp]
	mov r0, sp
	ldr r2, _0816C508 @ =0x05000002
	bl CpuSet
	ldr r1, _0816C50C @ =0x085B0A08
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #6
	cmp r0, #0
	blt _0816C510
	asrs r1, r0, #0xc
	b _0816C516
	.align 2, 0
_0816C4EC: .4byte FUN_0816b9ac
_0816C4F0: .4byte 0x0000046D
_0816C4F4: .4byte 0x0000046B
_0816C4F8: .4byte 0x030046B8
_0816C4FC: .4byte 0x000003FF
_0816C500: .4byte 0x0203B400
_0816C504: .4byte 0x00000888
_0816C508: .4byte 0x05000002
_0816C50C: .4byte 0x085B0A08
_0816C510:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816C516:
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	ldr r2, _0816C53C @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	lsls r0, r0, #6
	cmp r0, #0
	blt _0816C540
	asrs r0, r0, #0xc
	b _0816C546
	.align 2, 0
_0816C53C: .4byte 0x085B0A08
_0816C540:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0816C546:
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	movs r6, #0xe0
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r6, #0
	ldrsh r1, [r1, r6]
	bl FUN_0823785c
	subs r0, #0x80
	strb r0, [r5, #5]
_0816C564:
	ldr r1, _0816C610 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0816C570
	b _0816C688
_0816C570:
	adds r0, r5, #0
	bl FUN_0816d50c
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r4, #0
	str r4, [sp]
	mov r0, sp
	ldr r2, _0816C614 @ =0x05000002
	bl CpuSet
	movs r1, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r4, [r0]
	ldr r2, _0816C618 @ =0x00000469
	adds r0, r5, r2
	strb r4, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0816C61C @ =0x00000484
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #3
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	ldr r3, _0816C620 @ =FUN_080e48d0
	movs r2, #0x10
	adds r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0816C610 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	adds r0, r5, #0
	bl FUN_0816ce70
	add r6, sp, #4
	adds r0, r5, #0
	adds r0, #0x9c
	ldr r1, [r0, #8]
	ldrh r0, [r1]
	strh r0, [r6]
	ldrh r1, [r1, #2]
	strh r1, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r7, r6, #0
	cmp r2, #0
	blt _0816C60A
	cmp r1, #0
	blt _0816C60A
	ldr r0, _0816C624 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0816C60A
	ldr r0, _0816C628 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0816C62C
_0816C60A:
	movs r4, #0
	b _0816C63A
	.align 2, 0
_0816C610: .4byte 0x0000046B
_0816C614: .4byte 0x05000002
_0816C618: .4byte 0x00000469
_0816C61C: .4byte 0x00000484
_0816C620: .4byte FUN_080e48d0
_0816C624: .4byte 0x030046A8
_0816C628: .4byte 0x030046AC
_0816C62C:
	ldr r0, _0816C64C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0816C63A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0816C650
	adds r0, #4
	b _0816C65C
	.align 2, 0
_0816C64C: .4byte 0x030046A4
_0816C650:
	ldr r0, _0816C670 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0816C65C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0816C674
	cmp r2, #2
	beq _0816C678
	b _0816C67C
	.align 2, 0
_0816C670: .4byte 0x030046A4
_0816C674:
	ldrb r0, [r6, #4]
	b _0816C67A
_0816C678:
	ldrb r0, [r6]
_0816C67A:
	subs r1, r1, r0
_0816C67C:
	strh r1, [r6, #2]
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_0816d468
	b _0816C692
_0816C688:
	ldr r6, _0816C69C @ =0x00000484
	adds r1, r5, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0816C692:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816C69C: .4byte 0x00000484

	thumb_func_start FUN_0816c6a0
FUN_0816c6a0: @ 0x0816C6A0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _0816C6C8 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816C6CC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816C6CE
	.align 2, 0
_0816C6C8: .4byte 0x0000046C
_0816C6CC:
	movs r0, #0
_0816C6CE:
	ldr r3, _0816C728 @ =0x000007DC
	adds r3, r3, r7
	mov sb, r3
	adds r4, r5, #0
	adds r4, #8
	add r6, sp, #8
	mov r8, r6
	cmp r0, #0
	bne _0816C6E2
	b _0816C902
_0816C6E2:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, [r0]
	movs r1, #1
	ldr r2, _0816C72C @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r4, _0816C730 @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	ldr r6, _0816C734 @ =0x00000553
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r1, #0
	strh r2, [r0]
	ldr r4, _0816C738 @ =0x00000834
	adds r0, r7, r4
	strb r1, [r0]
	movs r1, #4
	mov r6, sb
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0816C73C
	movs r0, #1
	b _0816C73E
	.align 2, 0
_0816C728: .4byte 0x000007DC
_0816C72C: .4byte 0x0000046D
_0816C730: .4byte 0x0000046B
_0816C734: .4byte 0x00000553
_0816C738: .4byte 0x00000834
_0816C73C:
	movs r0, #0
_0816C73E:
	cmp r0, #0
	beq _0816C7F4
	ldr r3, _0816C794 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _0816C798 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _0816C79C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrb r2, [r1]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x80
	adds r4, r2, r0
	movs r1, #0xff
	mov r6, sp
	ands r4, r1
	movs r0, #0xb6
	lsls r0, r0, #2
	mov r8, r0
	ldr r2, _0816C7A0 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	mov ip, r3
	mov sl, r2
	cmp r0, #0
	blt _0816C7A4
	asrs r1, r0, #0xc
	b _0816C7AA
	.align 2, 0
_0816C794: .4byte 0x030046B8
_0816C798: .4byte 0x000003FF
_0816C79C: .4byte 0x0203B400
_0816C7A0: .4byte 0x085B0A08
_0816C7A4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816C7AA:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	lsls r0, r4, #1
	add r0, sl
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r3, r8
	muls r3, r0, r3
	adds r0, r3, #0
	cmp r0, #0
	blt _0816C7C6
	asrs r0, r0, #0xc
	b _0816C7CC
_0816C7C6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0816C7CC:
	strh r0, [r6, #4]
	mov r2, sp
	mov r1, sp
	ldrh r0, [r5, #8]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	adds r1, r5, #0
	adds r1, #8
	ldrh r4, [r5, #0xa]
	adds r0, r0, r4
	strh r0, [r2, #2]
	ldrh r0, [r1, #4]
	ldrh r6, [r2, #4]
	adds r0, r0, r6
	strh r0, [r2, #4]
	adds r4, r1, #0
	b _0816C80C
_0816C7F4:
	ldr r0, _0816C848 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, _0816C84C @ =0x030046B8
	mov ip, r0
	ldr r1, _0816C850 @ =0x085B0A08
	mov sl, r1
	adds r4, r5, #0
	adds r4, #8
_0816C80C:
	add r2, sp, #8
	mov r3, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r6, #4
	ldrsh r0, [r2, r6]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r0, r1, r0
	mov r8, r2
	cmp r0, #0
	blt _0816C854
	asrs r1, r0, #2
	b _0816C85A
	.align 2, 0
_0816C848: .4byte 0x03002BE0
_0816C84C: .4byte 0x030046B8
_0816C850: .4byte 0x085B0A08
_0816C854:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_0816C85A:
	movs r6, #0xfc
	lsls r6, r6, #3
	adds r0, r7, r6
	str r1, [r0]
	mov r1, ip
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _0816C8A8 @ =0x000003FF
	ands r0, r1
	mov r2, ip
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0816C8AC @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r6, #0xfe
	lsls r6, r6, #1
	adds r2, r5, r6
	movs r1, #0x3f
	ands r0, r1
	ldrb r2, [r2]
	adds r2, r0, r2
	movs r1, #0xff
	ldr r0, _0816C8B0 @ =0x00000888
	adds r3, r7, r0
	ands r2, r1
	adds r0, r2, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _0816C8B4
	asrs r1, r0, #0xc
	b _0816C8BA
	.align 2, 0
_0816C8A8: .4byte 0x000003FF
_0816C8AC: .4byte 0x0203B400
_0816C8B0: .4byte 0x00000888
_0816C8B4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816C8BA:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r2, #1
	add r0, sl
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _0816C8D4
	asrs r0, r0, #0xc
	b _0816C8DA
_0816C8D4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0816C8DA:
	strh r0, [r3, #4]
	adds r0, r5, #0
	mov r1, sp
	bl FUN_0816db54
	ldr r3, _0816C93C @ =0x000007EA
	adds r1, r7, r3
	movs r0, #1
	strh r0, [r1]
	adds r0, #0xff
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r2, r5, r6
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _0816C940 @ =0x00000482
	adds r1, r5, r0
	movs r0, #2
	strh r0, [r1]
_0816C902:
	ldr r1, _0816C944 @ =0x00000834
	adds r0, r7, r1
	ldrb r1, [r0]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldr r2, _0816C948 @ =0x000007EC
	adds r1, r1, r2
	ldrh r0, [r1]
	ldrh r2, [r5, #8]
	subs r0, r0, r2
	add r2, sp, #8
	strh r0, [r2]
	ldrh r0, [r1, #2]
	ldrh r2, [r4, #2]
	subs r0, r0, r2
	mov r3, r8
	strh r0, [r3, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r1, #4
	mov r4, sb
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0816C94C
	movs r0, #1
	b _0816C94E
	.align 2, 0
_0816C93C: .4byte 0x000007EA
_0816C940: .4byte 0x00000482
_0816C944: .4byte 0x00000834
_0816C948: .4byte 0x000007EC
_0816C94C:
	movs r0, #0
_0816C94E:
	cmp r0, #0
	bne _0816C962
	movs r6, #0x94
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r1, #5
	rsbs r1, r1, #0
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_0816C962:
	adds r0, r5, #0
	bl FUN_0816d920
	add r0, sp, #8
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	mov r2, r8
	movs r3, #4
	ldrsh r0, [r2, r3]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #3
	cmp r1, r0
	ble _0816CA40
	ldr r6, _0816C9DC @ =0x00000834
	adds r0, r7, r6
	ldrb r1, [r0]
	lsls r1, r1, #3
	adds r1, r7, r1
	ldr r2, _0816C9E0 @ =0x000007EC
	adds r0, r1, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r4, #8
	ldrsh r2, [r5, r4]
	subs r0, r0, r2
	subs r6, #0x44
	adds r1, r1, r6
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r3, #0xc
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r5, #5]
	ldr r4, _0816C9E4 @ =0x000007EA
	adds r0, r7, r4
	mov r6, r8
	ldrb r3, [r5, #5]
	ldrh r4, [r0]
	ldr r2, _0816C9E8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0816C9EC
	asrs r1, r0, #0xc
	b _0816C9F2
	.align 2, 0
_0816C9DC: .4byte 0x00000834
_0816C9E0: .4byte 0x000007EC
_0816C9E4: .4byte 0x000007EA
_0816C9E8: .4byte 0x085B0A08
_0816C9EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816C9F2:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	ldr r1, _0816CA0C @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _0816CA10
	asrs r0, r0, #0xc
	b _0816CA16
	.align 2, 0
_0816CA0C: .4byte 0x085B0A08
_0816CA10:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0816CA16:
	strh r0, [r6, #4]
	mov r3, r8
	ldrh r0, [r3]
	ldrh r4, [r5, #0x10]
	adds r0, r0, r4
	strh r0, [r5, #0x10]
	add r0, sp, #8
	ldrh r0, [r0, #4]
	ldrh r6, [r5, #0x14]
	adds r0, r0, r6
	strh r0, [r5, #0x14]
	ldr r0, _0816CA3C @ =0x00000888
	adds r2, r7, r0
	ldr r0, [r5, #0x10]
	ldr r1, [r5, #0x14]
	str r0, [r2]
	str r1, [r2, #4]
	b _0816CB70
	.align 2, 0
_0816CA3C: .4byte 0x00000888
_0816CA40:
	ldr r2, _0816CA94 @ =0x00000834
	adds r1, r7, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bhi _0816CA54
	b _0816CB70
_0816CA54:
	ldr r3, _0816CA98 @ =0x0000082C
	adds r0, r7, r3
	ldrh r0, [r0]
	strh r0, [r5, #8]
	movs r4, #0x83
	lsls r4, r4, #4
	adds r0, r7, r4
	ldrh r0, [r0]
	strh r0, [r5, #0xc]
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r2, r5, r6
	ldr r0, _0816CA9C @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x94
	lsls r0, r0, #1
	adds r2, r5, r0
	movs r3, #4
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	mov r1, sb
	ldr r0, [r1]
	ands r0, r3
	cmp r0, #0
	beq _0816CAA0
	movs r0, #1
	b _0816CAA2
	.align 2, 0
_0816CA94: .4byte 0x00000834
_0816CA98: .4byte 0x0000082C
_0816CA9C: .4byte 0xFFFFFEFF
_0816CAA0:
	movs r0, #0
_0816CAA2:
	adds r4, r0, #0
	cmp r4, #0
	beq _0816CB14
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0816CB00 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r4, _0816CB04 @ =0x0000046A
	adds r0, r5, r4
	strb r1, [r0]
	ldr r6, _0816CB08 @ =0x00000484
	adds r0, r5, r6
	str r1, [r0]
	adds r2, #4
	adds r0, r5, r2
	movs r2, #1
	strb r2, [r0]
	ldr r4, _0816CB0C @ =FUN_080e48d0
	movs r3, #0x10
	subs r6, #0x17
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _0816CB10 @ =0x0000046B
	adds r0, r5, r2
	strb r1, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	subs r1, #5
	mov r4, sb
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	b _0816CBC2
	.align 2, 0
_0816CB00: .4byte 0x00000469
_0816CB04: .4byte 0x0000046A
_0816CB08: .4byte 0x00000484
_0816CB0C: .4byte FUN_080e48d0
_0816CB10: .4byte 0x0000046B
_0816CB14:
	movs r2, #2
	movs r1, #1
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r4, [r0]
	ldr r3, _0816CB60 @ =0x00000469
	adds r0, r5, r3
	strb r2, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r1, [r0]
	ldr r2, _0816CB64 @ =0x00000484
	adds r0, r5, r2
	str r4, [r0]
	adds r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r3, _0816CB68 @ =FUN_080e48d0
	movs r2, #0x10
	adds r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0816CB6C @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	b _0816CBC2
	.align 2, 0
_0816CB60: .4byte 0x00000469
_0816CB64: .4byte 0x00000484
_0816CB68: .4byte FUN_080e48d0
_0816CB6C: .4byte 0x0000046B
_0816CB70:
	movs r3, #0x90
	lsls r3, r3, #3
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _0816CBA4
	ldr r4, _0816CB9C @ =0x00000484
	adds r0, r5, r4
	ldr r0, [r0]
	movs r1, #8
	bl Mod
	cmp r0, #0
	bne _0816CBC2
	ldr r6, _0816CBA0 @ =0x000007EA
	adds r1, r7, r6
	ldrh r0, [r1]
	cmp r0, #0x13
	bhi _0816CBC2
	adds r0, #1
	b _0816CBC0
	.align 2, 0
_0816CB9C: .4byte 0x00000484
_0816CBA0: .4byte 0x000007EA
_0816CBA4:
	ldr r1, _0816CBD4 @ =0x00000484
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _0816CBC2
	ldr r2, _0816CBD8 @ =0x000007EA
	adds r1, r7, r2
	ldrh r0, [r1]
	cmp r0, #0x13
	bhi _0816CBC2
	adds r0, #2
_0816CBC0:
	strh r0, [r1]
_0816CBC2:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816CBD4: .4byte 0x00000484
_0816CBD8: .4byte 0x000007EA

	thumb_func_start FUN_0816cbdc
FUN_0816cbdc: @ 0x0816CBDC
	ldr r1, _0816CBE8 @ =0x00000634
	adds r0, r0, r1
	ldr r1, _0816CBEC @ =0x085ADA84
	str r1, [r0]
	bx lr
	.align 2, 0
_0816CBE8: .4byte 0x00000634
_0816CBEC: .4byte 0x085ADA84

	thumb_func_start FUN_0816cbf0
FUN_0816cbf0: @ 0x0816CBF0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0816CC7A
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0x80
	ldr r2, _0816CC18 @ =0x000007DC
	adds r0, r0, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816CC1C
	movs r0, #1
	b _0816CC1E
	.align 2, 0
_0816CC18: .4byte 0x000007DC
_0816CC1C:
	movs r0, #0
_0816CC1E:
	cmp r0, #0
	beq _0816CC7A
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r2, #0
	strb r2, [r0]
	ldr r6, _0816CC80 @ =0x00000469
	adds r0, r5, r6
	strb r2, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r2, [r0]
	ldr r1, _0816CC84 @ =0x0000046C
	adds r0, r5, r1
	movs r1, #1
	strb r1, [r0]
	ldr r4, _0816CC88 @ =FUN_080e48d0
	movs r3, #0x10
	subs r6, #0x17
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0816CC8C @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
	adds r2, r5, #0
	adds r2, #0xde
	ldrh r1, [r2]
	ldr r0, _0816CC90 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
_0816CC7A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0816CC80: .4byte 0x00000469
_0816CC84: .4byte 0x0000046C
_0816CC88: .4byte FUN_080e48d0
_0816CC8C: .4byte 0x0000046B
_0816CC90: .4byte 0x0000FFFB

	thumb_func_start FUN_0816cc94
FUN_0816cc94: @ 0x0816CC94
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0816CD2A
	movs r1, #0x80
	lsls r1, r1, #7
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816CD2A
	movs r2, #0x20
	ldr r3, _0816CCD4 @ =0x000007DC
	adds r1, r5, r3
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _0816CCD8
	movs r0, #1
	b _0816CCDA
	.align 2, 0
_0816CCD4: .4byte 0x000007DC
_0816CCD8:
	movs r0, #0
_0816CCDA:
	cmp r0, #0
	bne _0816CD2A
	movs r1, #1
	ldr r3, _0816CCF8 @ =0x0000025D
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0816CCFC
	ldr r0, [r4, #0x44]
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0816CD06
	b _0816CD0A
	.align 2, 0
_0816CCF8: .4byte 0x0000025D
_0816CCFC:
	ldr r0, [r4, #0x44]
	ldr r0, [r0, #0x28]
	ands r0, r1
	cmp r0, #0
	beq _0816CD0A
_0816CD06:
	movs r0, #1
	b _0816CD0C
_0816CD0A:
	movs r0, #0
_0816CD0C:
	cmp r0, #0
	beq _0816CD2A
	ldr r0, _0816CD30 @ =0x00000836
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	ldr r1, _0816CD34 @ =0xFFFFFDBF
	ldr r0, [r2]
	ands r0, r1
	movs r1, #0x20
	orrs r0, r1
	str r0, [r2]
	ldr r0, _0816CD38 @ =0x0000021E
	bl PlaySound_082406e0
_0816CD2A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0816CD30: .4byte 0x00000836
_0816CD34: .4byte 0xFFFFFDBF
_0816CD38: .4byte 0x0000021E

	thumb_func_start FUN_0816cd3c
FUN_0816cd3c: @ 0x0816CD3C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r0, _0816CD74 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _0816CD5C
	ldr r0, _0816CD78 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #5
	bne _0816CD5C
	movs r1, #1
_0816CD5C:
	ldr r3, _0816CD7C @ =0x03002BE0
	cmp r1, #0
	bne _0816CD70
	ldr r0, [r3]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #3
	bne _0816CD80
_0816CD70:
	movs r2, #0x64
	b _0816CD82
	.align 2, 0
_0816CD74: .4byte 0x03002B8C
_0816CD78: .4byte 0x03002B60
_0816CD7C: .4byte 0x03002BE0
_0816CD80:
	movs r2, #0xdc
_0816CD82:
	ldr r6, _0816CDA8 @ =0x00000553
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, #0x22
	bne _0816CDAC
	ldr r0, [r3]
	movs r1, #0x2e
	ldrsh r0, [r0, r1]
	adds r1, r0, r2
	movs r2, #0xa
	ldrsh r0, [r4, r2]
	subs r0, r1, r0
	movs r1, #0xa
	bl Div
	ldrh r1, [r4, #0xa]
	adds r1, r1, r0
	strh r1, [r4, #0xa]
	b _0816CDFC
	.align 2, 0
_0816CDA8: .4byte 0x00000553
_0816CDAC:
	ldr r1, _0816CDC8 @ =0x085B0A08
	ldr r6, _0816CDCC @ =0x0000083A
	adds r0, r5, r6
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _0816CDD0
	asrs r1, r0, #0xc
	b _0816CDD6
	.align 2, 0
_0816CDC8: .4byte 0x085B0A08
_0816CDCC: .4byte 0x0000083A
_0816CDD0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816CDD6:
	ldr r0, [r3]
	movs r3, #0x2e
	ldrsh r0, [r0, r3]
	adds r0, r0, r2
	adds r1, r0, r1
	movs r6, #0xa
	ldrsh r0, [r4, r6]
	subs r0, r1, r0
	movs r1, #0xa
	bl Div
	ldrh r1, [r4, #0xa]
	adds r1, r1, r0
	strh r1, [r4, #0xa]
	ldr r0, _0816CE04 @ =0x0000083A
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
_0816CDFC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0816CE04: .4byte 0x0000083A

	thumb_func_start FUN_0816ce08
FUN_0816ce08: @ 0x0816CE08
	push {r4, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r3, [r0]
	ldr r0, _0816CE2C @ =0x0000083C
	adds r2, r3, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r4, #0xa0
	lsls r4, r4, #1
	cmp r0, r4
	ble _0816CE34
	ldr r0, _0816CE30 @ =0x0000083B
	adds r1, r3, r0
	movs r0, #0xff
	b _0816CE40
	.align 2, 0
_0816CE2C: .4byte 0x0000083C
_0816CE30: .4byte 0x0000083B
_0816CE34:
	ldr r4, _0816CE64 @ =0xFFFFFEC0
	cmp r0, r4
	bge _0816CE44
	ldr r0, _0816CE68 @ =0x0000083B
	adds r1, r3, r0
	movs r0, #1
_0816CE40:
	strb r0, [r1]
	strh r4, [r2]
_0816CE44:
	ldr r1, _0816CE6C @ =0x0000083C
	adds r2, r3, r1
	subs r1, #1
	adds r0, r3, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0816CE64: .4byte 0xFFFFFEC0
_0816CE68: .4byte 0x0000083B
_0816CE6C: .4byte 0x0000083C

	thumb_func_start FUN_0816ce70
FUN_0816ce70: @ 0x0816CE70
	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0x9c
	ldr r3, [r4, #4]
	ldrb r0, [r3]
	cmp r0, #1
	bhi _0816CE82
	movs r0, #0
	b _0816CECA
_0816CE82:
	ldr r2, _0816CED0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0816CED4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0816CED8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrb r1, [r3]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldrb r0, [r4, #2]
	cmp r1, r0
	bne _0816CEB4
	adds r0, r1, #1
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
_0816CEB4:
	movs r0, #0
	strb r1, [r4, #2]
	strb r0, [r4, #3]
	ldr r0, [r4, #4]
	bl FUN_08234f6c
	ldrb r1, [r4, #2]
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r4, #8]
	movs r0, #1
_0816CECA:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0816CED0: .4byte 0x030046B8
_0816CED4: .4byte 0x000003FF
_0816CED8: .4byte 0x0203B400

	thumb_func_start FUN_0816cedc
FUN_0816cedc: @ 0x0816CEDC
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x1c
	mov r8, r0
	ldr r2, _0816CF8C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r1, #0x10
	mov sb, r1
	orrs r0, r1
	ldr r1, _0816CF90 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	add r5, sp, #0xc
	ldr r0, [sp, #0x10]
	ands r0, r2
	mov r1, sb
	orrs r0, r1
	str r0, [sp, #0x10]
	movs r6, #0
	str r6, [sp, #0x14]
	add r4, sp, #0x14
	ldr r0, [r4, #4]
	ands r0, r2
	str r0, [r4, #4]
	ldr r3, _0816CF94 @ =FUN_0816aabc
	mov r0, r8
	str r0, [sp]
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080e3834
	movs r1, #0x18
	add r0, sp, #0xc
	strh r1, [r0]
	movs r0, #0x40
	strh r0, [r5, #2]
	strh r1, [r5, #4]
	strh r6, [r4]
	strh r6, [r4, #2]
	strh r6, [r4, #4]
	ldr r2, _0816CF98 @ =0x00002003
	movs r5, #0x94
	lsls r5, r5, #1
	add r5, r8
	mov r0, r8
	ldrh r1, [r0]
	mov r0, sb
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r4, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0823646c
	str r6, [sp]
	str r6, [sp, #4]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_082364f8
	mov r1, r8
	adds r1, #8
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _0816CF9C @ =FUN_0816a9b8
	adds r0, r5, #0
	mov r2, r8
	bl FUN_0823651c
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0816CF8C: .4byte 0xFFFF0000
_0816CF90: .4byte 0x0000FFFF
_0816CF94: .4byte FUN_0816aabc
_0816CF98: .4byte 0x00002003
_0816CF9C: .4byte FUN_0816a9b8

	thumb_func_start FUN_0816cfa0
FUN_0816cfa0: @ 0x0816CFA0
	movs r0, #4
	bx lr

	thumb_func_start FUN_0816cfa4
FUN_0816cfa4: @ 0x0816CFA4
	push {r4, r5, lr}
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r2, r0, r3
	ldr r4, [r2]
	ldr r2, _0816CFD8 @ =0x00000878
	adds r5, r4, r2
	ldr r2, [r0, #8]
	ldr r3, [r0, #0xc]
	str r2, [r5]
	str r3, [r5, #4]
	movs r3, #0x88
	lsls r3, r3, #4
	adds r2, r4, r3
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, _0816CFDC @ =0x00000838
	adds r4, r4, r0
	movs r0, #0
	strh r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0816CFD8: .4byte 0x00000878
_0816CFDC: .4byte 0x00000838

	thumb_func_start FUN_0816cfe0
FUN_0816cfe0: @ 0x0816CFE0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r1, [r1]
	mov r8, r1
	ldr r1, _0816D078 @ =0x00000878
	add r1, r8
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [sp, #4]
	str r2, [sp, #8]
	ldr r3, _0816D07C @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r3
	str r1, [sp, #4]
	movs r1, #0x88
	lsls r1, r1, #4
	add r1, r8
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	ldr r1, [sp, #0xc]
	ands r1, r3
	str r1, [sp, #0xc]
	ldr r1, _0816D080 @ =0x00000838
	add r1, r8
	ldr r3, _0816D084 @ =0x0000083C
	add r3, r8
	ldr r5, _0816D088 @ =0x000004A4
	adds r0, r0, r5
	ldr r0, [r0]
	adds r0, #0xc
	mov sb, r0
	add r7, sp, #4
	add r2, sp, #0xc
	ldrh r6, [r1]
	movs r1, #0
	ldrsh r0, [r3, r1]
	str r0, [sp, #0x24]
	add r4, sp, #0x14
	ldrh r0, [r2]
	ldrh r1, [r7]
	subs r0, r0, r1
	movs r3, #0
	strh r0, [r4]
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	add r5, sp, #0x1c
	str r3, [sp]
	mov r0, sp
	adds r1, r5, #0
	ldr r2, _0816D08C @ =0x05000002
	bl CpuSet
	adds r0, r6, #0
	muls r0, r6, r0
	mov sl, r4
	mov ip, r5
	cmp r0, #0
	blt _0816D090
	asrs r0, r0, #0xa
	b _0816D096
	.align 2, 0
_0816D078: .4byte 0x00000878
_0816D07C: .4byte 0x0000FFFF
_0816D080: .4byte 0x00000838
_0816D084: .4byte 0x0000083C
_0816D088: .4byte 0x000004A4
_0816D08C: .4byte 0x05000002
_0816D090:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r0, r0, #0
_0816D096:
	adds r1, r0, #0
	adds r0, r1, #0
	muls r0, r6, r0
	cmp r0, #0
	blt _0816D0A4
	asrs r3, r0, #0xa
	b _0816D0AA
_0816D0A4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r3, r0, #0
_0816D0AA:
	lsls r2, r3, #1
	lsls r0, r1, #1
	adds r4, r0, r1
	subs r0, r3, r0
	adds r0, r0, r6
	ldr r5, [sp, #0x24]
	adds r3, r0, #0
	muls r3, r5, r3
	str r3, [sp, #0x30]
	subs r0, r2, r4
	adds r0, #1
	mov r6, ip
	movs r3, #0
	ldrsh r1, [r6, r3]
	adds r5, r0, #0
	muls r5, r1, r5
	subs r6, r4, r2
	mov r1, sl
	movs r3, #0
	ldrsh r0, [r1, r3]
	muls r0, r6, r0
	adds r0, r5, r0
	ldr r5, [sp, #0x30]
	adds r0, r0, r5
	cmp r0, #0
	blt _0816D0E2
	asrs r1, r0, #0xa
	b _0816D0E8
_0816D0E2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0816D0E8:
	ldrh r0, [r7]
	adds r0, r0, r1
	mov r6, sb
	strh r0, [r6]
	subs r3, r2, r4
	adds r0, r3, #1
	str r0, [sp, #0x28]
	mov r1, ip
	movs r5, #2
	ldrsh r0, [r1, r5]
	ldr r6, [sp, #0x28]
	adds r5, r6, #0
	muls r5, r0, r5
	rsbs r2, r2, #0
	adds r0, r2, r4
	mov r1, sl
	movs r6, #2
	ldrsh r1, [r1, r6]
	adds r6, r0, #0
	adds r0, r1, #0
	muls r0, r6, r0
	adds r0, r5, r0
	ldr r1, [sp, #0x30]
	adds r0, r0, r1
	adds r0, #0
	cmp r0, #0
	blt _0816D122
	asrs r1, r0, #0xa
	b _0816D128
_0816D122:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0816D128:
	ldrh r0, [r7, #2]
	adds r0, r0, r1
	mov r5, sb
	strh r0, [r5, #2]
	adds r1, r3, #1
	mov r6, ip
	movs r3, #4
	ldrsh r0, [r6, r3]
	adds r5, r1, #0
	muls r5, r0, r5
	adds r1, r2, r4
	mov r6, sl
	movs r2, #4
	ldrsh r0, [r6, r2]
	muls r0, r1, r0
	adds r0, r5, r0
	ldr r3, [sp, #0x30]
	adds r0, r0, r3
	adds r0, #0
	cmp r0, #0
	blt _0816D156
	asrs r1, r0, #0xa
	b _0816D15C
_0816D156:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0816D15C:
	ldrh r0, [r7, #4]
	adds r0, r0, r1
	mov r5, sb
	strh r0, [r5, #4]
	ldr r1, _0816D17C @ =0x00000838
	add r1, r8
	ldrh r2, [r1]
	ldr r0, _0816D180 @ =0x000003FF
	cmp r2, r0
	bhi _0816D184
	adds r0, r2, #0
	adds r0, #0x80
	strh r0, [r1]
	movs r0, #0
	b _0816D186
	.align 2, 0
_0816D17C: .4byte 0x00000838
_0816D180: .4byte 0x000003FF
_0816D184:
	movs r0, #1
_0816D186:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0816d198
FUN_0816d198: @ 0x0816D198
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #3
	movs r2, #2
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #0
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #3
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xb
	movs r2, #0
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #1
	movs r3, #0
	bl FUN_080ef84c
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start ghost_0816d200
ghost_0816d200: @ 0x0816D200
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	ldr r2, _0816D2E4 @ =0x00000838
	adds r0, r4, r2
	movs r1, #0
	movs r5, #0
	strh r5, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	movs r2, #1
	mov r8, r2
	mov r2, r8
	strb r2, [r0]
	ldr r2, _0816D2E8 @ =0x0000083C
	adds r0, r4, r2
	strh r5, [r0]
	adds r2, #5
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _0816D2EC @ =0x000007DC
	adds r1, r4, r0
	ldr r2, _0816D2F0 @ =0x00000574
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [r1]
	movs r0, #0x89
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, _0816D2F4 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _0816D2F8 @ =0x00000878
	adds r1, r4, r2
	str r5, [sp]
	mov r0, sp
	ldr r2, _0816D2FC @ =0x05000002
	bl CpuSet
	movs r0, #0x88
	lsls r0, r0, #4
	adds r1, r4, r0
	str r5, [sp]
	mov r0, sp
	ldr r2, _0816D2FC @ =0x05000002
	bl CpuSet
	ldr r1, _0816D300 @ =0x00000888
	adds r4, r4, r1
	str r5, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _0816D2FC @ =0x05000002
	bl CpuSet
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r0, [r0]
	movs r1, #8
	bl ClearMemory
	ldr r1, _0816D304 @ =0x0825215C
	adds r0, r6, #0
	movs r2, #0x96
	lsls r2, r2, #1
	bl FUN_080e6768
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x48]
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
	beq _0816D308
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0816D310
	.align 2, 0
_0816D2E4: .4byte 0x00000838
_0816D2E8: .4byte 0x0000083C
_0816D2EC: .4byte 0x000007DC
_0816D2F0: .4byte 0x00000574
_0816D2F4: .4byte 0x03002BE0
_0816D2F8: .4byte 0x00000878
_0816D2FC: .4byte 0x05000002
_0816D300: .4byte 0x00000888
_0816D304: .4byte 0x0825215C
_0816D308:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0816D310:
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
	beq _0816D334
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0816D33C
_0816D334:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0816D33C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0816D374 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0816D3AC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0816D378
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0816D36C
	ldrb r0, [r4, #5]
_0816D36C:
	subs r0, #1
	strh r0, [r4, #8]
	b _0816D388
	.align 2, 0
_0816D374: .4byte 0x0000FFFF
_0816D378:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0816D388
	strh r1, [r4, #8]
_0816D388:
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
	bne _0816D3AC
	movs r0, #1
	strb r0, [r4, #7]
_0816D3AC:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0816d3b8
FUN_0816d3b8: @ 0x0816D3B8
	push {r4, lr}
	mov ip, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, ip
	ldr r4, [r0]
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r1, #0xbe
	lsls r1, r1, #1
	add r1, ip
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0816D3FC @ =0x000007DC
	adds r3, r4, r0
	movs r1, #0x12
	rsbs r1, r1, #0
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	mov r2, ip
	adds r2, #0xde
	ldrh r1, [r2]
	ldr r0, _0816D400 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0816D404
	movs r0, #1
	b _0816D406
	.align 2, 0
_0816D3FC: .4byte 0x000007DC
_0816D400: .4byte 0x0000FFFB
_0816D404:
	movs r0, #0
_0816D406:
	cmp r0, #0
	beq _0816D426
	ldr r0, _0816D42C @ =0x03002BE0
	ldr r1, [r0]
	ldr r0, _0816D430 @ =0x00000402
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #3
	strb r0, [r1]
	ldr r0, _0816D434 @ =0x000007DC
	adds r2, r4, r0
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_0816D426:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0816D42C: .4byte 0x03002BE0
_0816D430: .4byte 0x00000402
_0816D434: .4byte 0x000007DC

	thumb_func_start FUN_0816d438
FUN_0816d438: @ 0x0816D438
	push {lr}
	adds r3, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r1, r0, #3
	movs r0, #7
	ands r1, r0
	cmp r1, #4
	ble _0816D45C
	movs r0, #8
	subs r0, r0, r1
	str r0, [r3]
	movs r0, #1
	b _0816D460
_0816D45C:
	str r1, [r3]
	movs r0, #0
_0816D460:
	str r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0816d468
FUN_0816d468: @ 0x0816D468
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	mov r8, r0
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0816cfa4
	adds r0, r4, #0
	bl FUN_0816cfe0
	movs r1, #1
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r6, #0
	strb r6, [r0]
	ldr r3, _0816D500 @ =0x00000469
	adds r0, r4, r3
	strb r6, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r3, #0x1b
	adds r0, r4, r3
	str r6, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	add r2, sp, #4
	adds r3, r4, #0
	adds r3, #8
	ldrh r0, [r5]
	ldrh r1, [r4, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r5, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r5, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	movs r1, #0xee
	lsls r1, r1, #1
	adds r4, r4, r1
	strb r0, [r4]
	ldr r2, _0816D504 @ =0x00000888
	add r8, r2
	str r6, [sp]
	mov r0, sp
	mov r1, r8
	ldr r2, _0816D508 @ =0x05000002
	bl CpuSet
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0816D500: .4byte 0x00000469
_0816D504: .4byte 0x00000888
_0816D508: .4byte 0x05000002

	thumb_func_start FUN_0816d50c
FUN_0816d50c: @ 0x0816D50C
	mov ip, r0
	movs r2, #0xc0
	lsls r2, r2, #1
	add r2, ip
	ldr r0, _0816D54C @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	movs r3, #0
	strh r0, [r2]
	movs r2, #0xbc
	lsls r2, r2, #1
	add r2, ip
	ldr r1, _0816D550 @ =0xFBFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, ip
	ldr r1, [r0]
	ldr r0, _0816D554 @ =0x000007DC
	adds r1, r1, r0
	movs r2, #0x11
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldr r0, _0816D558 @ =0x0000024E
	add r0, ip
	strh r3, [r0]
	bx lr
	.align 2, 0
_0816D54C: .4byte 0xFFFFFEFF
_0816D550: .4byte 0xFBFFFFFF
_0816D554: .4byte 0x000007DC
_0816D558: .4byte 0x0000024E

	thumb_func_start FUN_0816d55c
FUN_0816d55c: @ 0x0816D55C
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0816D578
	b _0816D6A2
_0816D578:
	movs r1, #0x90
	lsls r1, r1, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816D58C
	b _0816D6A2
_0816D58C:
	movs r1, #0x10
	ldr r2, _0816D5A0 @ =0x000007DC
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816D5A4
	movs r0, #1
	b _0816D5A6
	.align 2, 0
_0816D5A0: .4byte 0x000007DC
_0816D5A4:
	movs r0, #0
_0816D5A6:
	adds r1, r0, #0
	cmp r1, #0
	bne _0816D5B8
	ldr r2, _0816D5B4 @ =0x0000024E
	adds r0, r6, r2
	strh r1, [r0]
	b _0816D6A2
	.align 2, 0
_0816D5B4: .4byte 0x0000024E
_0816D5B8:
	ldr r0, _0816D5C8 @ =0x0000024E
	adds r1, r6, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0816D5CC
	subs r0, #1
	strh r0, [r1]
	b _0816D6A2
	.align 2, 0
_0816D5C8: .4byte 0x0000024E
_0816D5CC:
	adds r0, r6, #0
	bl FUN_0816ce70
	mov r7, sp
	adds r0, r6, #0
	adds r0, #0x9c
	ldr r2, [r0, #8]
	ldrh r1, [r2]
	mov r0, sp
	strh r1, [r0]
	ldrh r1, [r2, #2]
	strh r1, [r7, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _0816D606
	cmp r1, #0
	blt _0816D606
	ldr r0, _0816D60C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0816D606
	ldr r0, _0816D610 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0816D614
_0816D606:
	movs r4, #0
	b _0816D622
	.align 2, 0
_0816D60C: .4byte 0x030046A8
_0816D610: .4byte 0x030046AC
_0816D614:
	ldr r0, _0816D634 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0816D622:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0816D638
	adds r0, #4
	b _0816D644
	.align 2, 0
_0816D634: .4byte 0x030046A4
_0816D638:
	ldr r0, _0816D658 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0816D644:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0816D65C
	cmp r2, #2
	beq _0816D660
	b _0816D664
	.align 2, 0
_0816D658: .4byte 0x030046A4
_0816D65C:
	ldrb r0, [r7, #4]
	b _0816D662
_0816D660:
	ldrb r0, [r7]
_0816D662:
	subs r1, r1, r0
_0816D664:
	movs r4, #0
	movs r5, #0
	strh r1, [r7, #2]
	adds r0, r6, #0
	mov r1, sp
	bl FUN_0816d468
	adds r0, r6, #0
	bl FUN_0816d50c
	adds r0, r6, #0
	bl FUN_0816d3b8
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r4, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r4, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _0816D6AC @ =0x00000484
	adds r0, r6, r1
	str r5, [r0]
	adds r2, #2
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
_0816D6A2:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816D6AC: .4byte 0x00000484

	thumb_func_start FUN_0816d6b0
FUN_0816d6b0: @ 0x0816D6B0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0816D6C6
	b _0816D84A
_0816D6C6:
	movs r1, #0x20
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r5, r6, r0
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0816D6D8
	b _0816D84A
_0816D6D8:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov ip, r0
	ldr r2, _0816D728 @ =0x03002BE0
	mov r8, r2
	mov r7, sp
	movs r2, #0x89
	lsls r2, r2, #4
	add r2, ip
	mov r4, r8
	ldr r3, [r4]
	adds r4, r3, #0
	adds r4, #0x2c
	ldrh r0, [r3, #0x2c]
	ldrh r1, [r2]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r7, #4]
	ldr r0, [r3, #0x2c]
	ldr r1, [r3, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _0816D72C @ =0x0000083E
	add r1, ip
	ldrb r0, [r1]
	mov r4, r8
	cmp r0, #0
	beq _0816D730
	subs r0, #1
	b _0816D848
	.align 2, 0
_0816D728: .4byte 0x03002BE0
_0816D72C: .4byte 0x0000083E
_0816D730:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0816D73E
	b _0816D84A
_0816D73E:
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0816D752
	movs r2, #4
	ldrsh r0, [r7, r2]
	cmp r0, #0
	bne _0816D752
	b _0816D84A
_0816D752:
	movs r0, #8
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r2, r6, r3
	ldr r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0816D84A
	movs r0, #9
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
	movs r0, #0xa
	ldrsh r1, [r6, r0]
	ldr r0, [r4]
	movs r2, #0x2e
	ldrsh r0, [r0, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _0816D77C
	rsbs r1, r1, #0
_0816D77C:
	movs r0, #0x80
	lsls r0, r0, #2
	cmp r1, r0
	bgt _0816D84A
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r1, r6, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _0816D84A
	movs r2, #0x10
	ldr r1, _0816D7AC @ =0x000007DC
	add r1, ip
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _0816D7B0
	movs r0, #1
	b _0816D7B2
	.align 2, 0
_0816D7AC: .4byte 0x000007DC
_0816D7B0:
	movs r0, #0
_0816D7B2:
	adds r3, r0, #0
	cmp r3, #0
	beq _0816D808
	ldr r0, [r4]
	movs r3, #0xda
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _0816D84A
	movs r2, #4
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r6, r4
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0816D7FC @ =0x00000469
	adds r0, r6, r3
	strb r1, [r0]
	adds r4, #2
	adds r0, r6, r4
	strb r2, [r0]
	ldr r2, _0816D800 @ =0x00000484
	adds r0, r6, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r0, r6, r4
	ldrh r1, [r0]
	ldr r2, _0816D804 @ =0x0000024E
	adds r0, r6, r2
	strh r1, [r0]
	b _0816D84A
	.align 2, 0
_0816D7FC: .4byte 0x00000469
_0816D800: .4byte 0x00000484
_0816D804: .4byte 0x0000024E
_0816D808:
	movs r1, #0x10
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #2
	movs r2, #1
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r6, r4
	strb r3, [r0]
	adds r4, #1
	adds r0, r6, r4
	strb r1, [r0]
	ldr r1, _0816D858 @ =0x0000046A
	adds r0, r6, r1
	strb r2, [r0]
	adds r4, #0x1b
	adds r0, r6, r4
	str r3, [r0]
	adds r1, #2
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrh r1, [r0]
	ldr r3, _0816D85C @ =0x0000024E
	adds r0, r6, r3
	strh r1, [r0]
	ldr r1, _0816D860 @ =0x0000083E
	add r1, ip
	movs r0, #0xa
_0816D848:
	strb r0, [r1]
_0816D84A:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816D858: .4byte 0x0000046A
_0816D85C: .4byte 0x0000024E
_0816D860: .4byte 0x0000083E

	thumb_func_start FUN_0816d864
FUN_0816d864: @ 0x0816D864
	movs r0, #0
	bx lr

	thumb_func_start FUN_0816d868
FUN_0816d868: @ 0x0816D868
	bx lr
	.align 2, 0

	thumb_func_start FUN_0816d86c
FUN_0816d86c: @ 0x0816D86C
	push {lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	movs r2, #3
	movs r3, #0xf6
	lsls r3, r3, #3
	adds r0, r0, r3
_0816D87E:
	str r1, [r0]
	subs r0, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0816D87E
	pop {r0}
	bx r0

	thumb_func_start FUN_0816d88c
FUN_0816d88c: @ 0x0816D88C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r6, [r0]
	ldr r2, _0816D908 @ =0x00000684
	adds r4, r6, r2
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r5, r6, r0
	movs r1, #0
	mov r8, r1
	movs r7, #3
_0816D8AA:
	adds r0, r4, #0
	ldr r1, _0816D90C @ =0x0000D637
	bl Video_GetActorSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r4, #0
	movs r1, #0xc0
	lsls r1, r1, #1
	bl FUN_0822b20c
	ldr r0, _0816D910 @ =0x0000922E
	ldr r1, _0816D914 @ =0x000029FB
	bl GetFile
	movs r2, #0xd6
	lsls r2, r2, #3
	adds r1, r6, r2
	add r1, r8
	str r0, [r1]
	ldr r0, _0816D918 @ =0x00000201
	str r0, [r5]
	movs r1, #0
	strh r1, [r4, #0x30]
	adds r4, #0x60
	adds r5, #0x60
	movs r0, #0x60
	add r8, r0
	subs r7, #1
	cmp r7, #0
	bge _0816D8AA
	movs r2, #0xfb
	lsls r2, r2, #3
	adds r0, r6, r2
	strh r1, [r0]
	ldr r0, _0816D91C @ =0x000007DA
	adds r1, r6, r0
	movs r0, #2
	strh r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816D908: .4byte 0x00000684
_0816D90C: .4byte 0x0000D637
_0816D910: .4byte 0x0000922E
_0816D914: .4byte 0x000029FB
_0816D918: .4byte 0x00000201
_0816D91C: .4byte 0x000007DA

	thumb_func_start FUN_0816d920
FUN_0816d920: @ 0x0816D920
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	mov r8, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, r8
	ldr r7, [r0]
	movs r0, #0xe5
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	ldr r2, _0816D9D0 @ =0x000007DA
	adds r1, r7, r2
	ldrh r1, [r1]
	bl Mod
	cmp r0, #0
	beq _0816D94A
	b _0816DAD4
_0816D94A:
	mov r4, r8
	ldrb r0, [r4, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_0816d438
	ldr r0, [r4, #0x44]
	adds r0, #0x48
	ldrh r2, [r0, #0xa]
	movs r0, #0xfb
	lsls r0, r0, #3
	adds r5, r7, r0
	ldrh r0, [r5]
	lsls r3, r0, #1
	adds r3, r3, r0
	lsls r3, r3, #5
	movs r6, #0xcb
	lsls r6, r6, #3
	adds r0, r3, r6
	adds r0, r7, r0
	adds r0, #0x48
	movs r4, #0xd6
	lsls r4, r4, #3
	adds r1, r7, r4
	adds r1, r1, r3
	ldr r1, [r1]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r4, [sp, #8]
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldrh r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r5, r0, r7
	adds r5, r5, r6
	adds r4, r0, r7
	movs r0, #0xd4
	lsls r0, r0, #3
	adds r4, r4, r0
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
	beq _0816D9D4
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0816D9DC
	.align 2, 0
_0816D9D0: .4byte 0x000007DA
_0816D9D4:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0816D9DC:
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
	beq _0816DA00
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0816DA08
_0816DA00:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0816DA08:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0816DA40 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0816DA78
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0816DA44
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0816DA38
	ldrb r0, [r4, #5]
_0816DA38:
	subs r0, #1
	strh r0, [r4, #8]
	b _0816DA54
	.align 2, 0
_0816DA40: .4byte 0x0000FFFF
_0816DA44:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0816DA54
	strh r1, [r4, #8]
_0816DA54:
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
	bne _0816DA78
	movs r0, #1
	strb r0, [r4, #7]
_0816DA78:
	movs r4, #0xfb
	lsls r4, r4, #3
	adds r3, r7, r4
	ldrh r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r7, r0
	ldr r1, _0816DAE0 @ =0x00000674
	adds r0, r0, r1
	mov r4, r8
	ldr r1, [r4, #8]
	ldr r2, [r4, #0xc]
	str r1, [r0]
	str r2, [r0, #4]
	ldrh r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r1, r7, r2
	adds r1, r1, r0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	ldrh r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r7, r0
	ldr r4, _0816DAE4 @ =0x000006B4
	adds r0, r0, r4
	movs r1, #8
	strh r1, [r0]
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _0816DAD4
	movs r0, #0
	strh r0, [r3]
_0816DAD4:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816DAE0: .4byte 0x00000674
_0816DAE4: .4byte 0x000006B4

	thumb_func_start FUN_0816dae8
FUN_0816dae8: @ 0x0816DAE8
	push {r4, r5, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r2, r0, r1
	adds r3, r0, #0
	ldr r5, _0816DB28 @ =0x000006B4
	movs r4, #3
_0816DAFE:
	adds r1, r3, r5
	ldrh r0, [r1]
	cmp r0, #0
	beq _0816DB18
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0816DB18
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
_0816DB18:
	adds r2, #0x60
	adds r3, #0x60
	subs r4, #1
	cmp r4, #0
	bge _0816DAFE
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0816DB28: .4byte 0x000006B4

	thumb_func_start FUN_0816db2c
FUN_0816db2c: @ 0x0816DB2C
	push {r4, r5, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r4, r0, r1
	movs r5, #3
_0816DB3E:
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0816DB3E
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0816db54
FUN_0816db54: @ 0x0816DB54
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r2, r0, r3
	ldr r2, [r2]
	str r2, [sp, #0x24]
	ldr r2, [r0, #8]
	ldr r3, [r0, #0xc]
	str r2, [sp, #4]
	str r3, [sp, #8]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r1, _0816DC1C @ =0x0000FFFF
	ldr r0, [sp, #4]
	ands r0, r1
	str r0, [sp, #4]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
	movs r0, #0x80
	lsls r0, r0, #3
	movs r1, #8
	bl Div
	str r0, [sp, #0x28]
	ldr r4, [sp, #0x24]
	ldr r7, _0816DC20 @ =0x00000888
	adds r0, r4, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	str r0, [sp, #0x2c]
	ldr r2, _0816DC24 @ =0x0000088C
	adds r0, r4, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #7
	str r0, [sp, #0x30]
	movs r0, #0
	mov r4, sp
	adds r4, #0x14
	str r4, [sp, #0x38]
	add r7, sp, #0x1c
	mov sl, r7
	add r1, sp, #4
	mov sb, r1
	mov r2, sp
	adds r2, #0xc
	str r2, [sp, #0x34]
_0816DBC4:
	adds r4, r0, #1
	lsls r0, r0, #3
	ldr r3, [sp, #0x24]
	adds r0, r0, r3
	mov r8, r0
	ldr r7, _0816DC28 @ =0x000007EC
	add r8, r7
	ldr r0, [sp, #0x28]
	adds r5, r0, #0
	muls r5, r4, r5
	add r0, sp, #0xc
	ldrh r1, [r0]
	add r0, sp, #4
	ldrh r0, [r0]
	subs r1, r1, r0
	add r0, sp, #0x14
	strh r1, [r0]
	ldr r1, [sp, #0x34]
	ldrh r0, [r1, #2]
	mov r2, sb
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	mov r3, sp
	strh r0, [r3, #0x16]
	ldr r7, [sp, #0x34]
	ldrh r0, [r7, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r3, #0x18]
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	mov r1, sl
	ldr r2, _0816DC2C @ =0x05000002
	bl CpuSet
	adds r0, r5, #0
	muls r0, r5, r0
	mov ip, r4
	cmp r0, #0
	blt _0816DC30
	asrs r0, r0, #0xa
	b _0816DC36
	.align 2, 0
_0816DC1C: .4byte 0x0000FFFF
_0816DC20: .4byte 0x00000888
_0816DC24: .4byte 0x0000088C
_0816DC28: .4byte 0x000007EC
_0816DC2C: .4byte 0x05000002
_0816DC30:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r0, r0, #0
_0816DC36:
	adds r3, r0, #0
	adds r0, r3, #0
	muls r0, r5, r0
	cmp r0, #0
	blt _0816DC44
	asrs r1, r0, #0xa
	b _0816DC4A
_0816DC44:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0816DC4A:
	lsls r2, r1, #1
	lsls r0, r3, #1
	adds r6, r0, r3
	subs r0, r1, r0
	adds r0, r0, r5
	ldr r4, [sp, #0x30]
	adds r5, r0, #0
	muls r5, r4, r5
	subs r1, r1, r3
	str r1, [sp, #0x3c]
	subs r0, r2, r6
	adds r0, #1
	mov r7, sl
	movs r3, #0
	ldrsh r1, [r7, r3]
	muls r0, r1, r0
	ldr r7, [sp, #0x2c]
	adds r4, r0, #0
	muls r4, r7, r4
	subs r1, r6, r2
	ldr r3, [sp, #0x38]
	movs r7, #0
	ldrsh r0, [r3, r7]
	muls r0, r1, r0
	adds r0, r4, r0
	adds r0, r0, r5
	ldr r1, [sp, #0x3c]
	adds r0, r0, r1
	cmp r0, #0
	blt _0816DC8A
	asrs r1, r0, #0xa
	b _0816DC90
_0816DC8A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0816DC90:
	mov r3, sb
	ldrh r0, [r3]
	adds r0, r0, r1
	mov r4, r8
	strh r0, [r4]
	subs r3, r2, r6
	adds r1, r3, #1
	mov r7, sl
	movs r4, #2
	ldrsh r0, [r7, r4]
	muls r0, r1, r0
	ldr r7, [sp, #0x2c]
	adds r4, r0, #0
	muls r4, r7, r4
	rsbs r2, r2, #0
	adds r0, r2, r6
	str r0, [sp, #0x40]
	ldr r1, [sp, #0x38]
	movs r7, #2
	ldrsh r0, [r1, r7]
	ldr r1, [sp, #0x40]
	muls r0, r1, r0
	adds r0, r4, r0
	adds r0, r0, r5
	ldr r4, [sp, #0x3c]
	adds r0, r0, r4
	cmp r0, #0
	blt _0816DCCC
	asrs r1, r0, #0xa
	b _0816DCD2
_0816DCCC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0816DCD2:
	mov r7, sb
	ldrh r0, [r7, #2]
	adds r0, r0, r1
	mov r1, r8
	strh r0, [r1, #2]
	adds r1, r3, #1
	mov r3, sl
	movs r4, #4
	ldrsh r0, [r3, r4]
	muls r0, r1, r0
	ldr r7, [sp, #0x2c]
	adds r4, r0, #0
	muls r4, r7, r4
	adds r1, r2, r6
	ldr r2, [sp, #0x38]
	movs r3, #4
	ldrsh r0, [r2, r3]
	muls r0, r1, r0
	adds r0, r4, r0
	adds r0, r0, r5
	ldr r4, [sp, #0x3c]
	adds r0, r0, r4
	cmp r0, #0
	blt _0816DD06
	asrs r1, r0, #0xa
	b _0816DD0C
_0816DD06:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0816DD0C:
	mov r7, sb
	ldrh r0, [r7, #4]
	adds r0, r0, r1
	mov r1, r8
	strh r0, [r1, #4]
	mov r0, ip
	cmp r0, #7
	bgt _0816DD1E
	b _0816DBC4
_0816DD1E:
	ldr r3, [sp, #0x24]
	ldr r4, _0816DD3C @ =0x0000082C
	adds r2, r3, r4
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	str r0, [r2]
	str r1, [r2, #4]
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816DD3C: .4byte 0x0000082C

	thumb_func_start FUN_0816dd40
FUN_0816dd40: @ 0x0816DD40
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0816DE12
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	movs r1, #0x60
	ldr r2, _0816DD68 @ =0x000007DC
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816DD6C
	movs r0, #1
	b _0816DD6E
	.align 2, 0
_0816DD68: .4byte 0x000007DC
_0816DD6C:
	movs r0, #0
_0816DD6E:
	cmp r0, #0
	beq _0816DE12
	ldr r0, _0816DD98 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	ldr r1, _0816DD9C @ =0x00000836
	adds r0, r5, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0x13
	bhi _0816DDA0
	lsrs r0, r0, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0816DDAE
	b _0816DDBC
	.align 2, 0
_0816DD98: .4byte 0x030047A4
_0816DD9C: .4byte 0x00000836
_0816DDA0:
	cmp r1, #0x1d
	bhi _0816DDC8
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0816DDBC
_0816DDAE:
	ldr r0, [r4, #0x44]
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	b _0816DE08
_0816DDBC:
	ldr r0, [r4, #0x44]
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _0816DE08
_0816DDC8:
	movs r2, #0x20
	ldr r0, _0816DDDC @ =0x000007DC
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	adds r3, r1, #0
	cmp r0, #0
	beq _0816DDE0
	movs r0, #1
	b _0816DDE2
	.align 2, 0
_0816DDDC: .4byte 0x000007DC
_0816DDE0:
	movs r0, #0
_0816DDE2:
	cmp r0, #0
	beq _0816DDF6
	ldr r2, [r4, #0x44]
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	subs r1, #0x1f
	b _0816DE02
_0816DDF6:
	ldr r2, [r4, #0x44]
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	subs r1, #0x42
_0816DE02:
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
_0816DE08:
	ldr r2, _0816DE18 @ =0x00000836
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0816DE12:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0816DE18: .4byte 0x00000836

	thumb_func_start FUN_0816de1c
FUN_0816de1c: @ 0x0816DE1C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0816DE5A
	ldr r0, _0816DE60 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	ldr r0, _0816DE64 @ =0x0000083F
	adds r3, r5, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _0816DE5A
	ldr r2, [r4, #0x44]
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldrb r0, [r3]
	subs r0, #1
	strb r0, [r3]
_0816DE5A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0816DE60: .4byte 0x030047A4
_0816DE64: .4byte 0x0000083F

	thumb_func_start FUN_0816de68
FUN_0816de68: @ 0x0816DE68
	push {lr}
	adds r2, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r0, [r0]
	movs r1, #0x80
	ldr r3, _0816DE88 @ =0x000007DC
	adds r0, r0, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816DE8C
	movs r0, #1
	b _0816DE8E
	.align 2, 0
_0816DE88: .4byte 0x000007DC
_0816DE8C:
	movs r0, #0
_0816DE8E:
	cmp r0, #0
	beq _0816DEB6
	ldr r0, _0816DEBC @ =0x03002BE0
	ldr r1, [r0]
	ldr r0, _0816DEC0 @ =0x00000402
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #3
	strb r0, [r1]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r1, [r0]
	ldr r3, _0816DEC4 @ =0x000007DC
	adds r1, r1, r3
	movs r2, #0x81
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
_0816DEB6:
	pop {r0}
	bx r0
	.align 2, 0
_0816DEBC: .4byte 0x03002BE0
_0816DEC0: .4byte 0x00000402
_0816DEC4: .4byte 0x000007DC

	thumb_func_start FUN_0816dec8
FUN_0816dec8: @ 0x0816DEC8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r0, #0x94
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	movs r1, #0x80
	lsls r1, r1, #7
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816DF40
	movs r6, #0xe6
	lsls r6, r6, #1
	adds r0, r4, r6
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r7, _0816DF08 @ =0x000007DC
	adds r0, r0, r7
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816DF0C
	movs r0, #1
	b _0816DF0E
	.align 2, 0
_0816DF08: .4byte 0x000007DC
_0816DF0C:
	movs r0, #0
_0816DF0E:
	cmp r0, #0
	beq _0816DF38
	ldr r2, [r4, #0x44]
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r2, _0816DF34 @ =0x000007DC
	adds r1, r1, r2
	movs r2, #0x21
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	b _0816E116
	.align 2, 0
_0816DF34: .4byte 0x000007DC
_0816DF38:
	adds r0, r4, #0
	bl FUN_0816dd40
	b _0816E116
_0816DF40:
	movs r6, #0xe6
	lsls r6, r6, #1
	adds r0, r4, r6
	ldr r5, [r0]
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0816DF56
	b _0816E0FE
_0816DF56:
	ldr r0, _0816DF78 @ =0x030047A4
	ldr r1, [r0]
	movs r2, #0x90
	lsls r2, r2, #7
	ands r1, r2
	adds r6, r0, #0
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r7, _0816DF7C @ =0x000007DC
	adds r1, r5, r7
	ldr r0, [r1]
	ands r0, r2
	adds r3, r1, #0
	cmp r0, #0
	beq _0816DF80
	movs r0, #1
	b _0816DF82
	.align 2, 0
_0816DF78: .4byte 0x030047A4
_0816DF7C: .4byte 0x000007DC
_0816DF80:
	movs r0, #0
_0816DF82:
	cmp r0, #0
	beq _0816DFAC
	movs r2, #0x20
	ldr r1, _0816DFA0 @ =0x030046A0
	ldr r0, [r1]
	ldr r7, _0816DFA4 @ =0x00000934
	adds r0, r0, r7
	ldrh r0, [r0]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _0816DFA8
	movs r0, #1
	b _0816DFBA
	.align 2, 0
_0816DFA0: .4byte 0x030046A0
_0816DFA4: .4byte 0x00000934
_0816DFA8:
	movs r0, #0
	b _0816DFBA
_0816DFAC:
	ldr r1, _0816DFF0 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _0816DFF4 @ =0x00000942
	adds r0, r0, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	adds r2, r1, #0
_0816DFBA:
	cmp r0, #0
	ble _0816E0A4
	ldr r0, [r6]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0816E008
	ldr r0, _0816DFF8 @ =0x03002BE0
	ldr r1, [r0]
	cmp r1, #0
	beq _0816E004
	ldr r2, _0816DFFC @ =0x00000446
	adds r0, r1, r2
	ldrh r0, [r0]
	movs r2, #0
	cmp r0, #0
	beq _0816DFEA
	ldr r6, _0816E000 @ =0x00000442
	adds r0, r1, r6
	ldrh r0, [r0]
	cmp r0, #4
	bne _0816DFEA
	movs r2, #1
_0816DFEA:
	adds r0, r2, #0
	b _0816E036
	.align 2, 0
_0816DFF0: .4byte 0x030046A0
_0816DFF4: .4byte 0x00000942
_0816DFF8: .4byte 0x03002BE0
_0816DFFC: .4byte 0x00000446
_0816E000: .4byte 0x00000442
_0816E004:
	movs r0, #0
	b _0816E036
_0816E008:
	ldr r0, _0816E048 @ =0x03002B48
	ldr r0, [r0]
	cmp r0, #0
	bgt _0816E0A4
	ldr r0, [r2]
	movs r7, #0x94
	lsls r7, r7, #2
	adds r0, r0, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #2
	beq _0816E0A4
	ldr r0, _0816E04C @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _0816E034
	ldr r0, _0816E050 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #4
	bne _0816E034
	movs r1, #1
_0816E034:
	adds r0, r1, #0
_0816E036:
	cmp r0, #0
	bne _0816E0A4
	movs r1, #0x40
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0816E054
	movs r0, #1
	b _0816E056
	.align 2, 0
_0816E048: .4byte 0x03002B48
_0816E04C: .4byte 0x03002B8C
_0816E050: .4byte 0x03002B60
_0816E054:
	movs r0, #0
_0816E056:
	cmp r0, #0
	bne _0816E0FE
	movs r1, #1
	ldr r2, _0816E074 @ =0x0000025D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0816E078
	ldr r0, [r4, #0x44]
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0816E082
	b _0816E086
	.align 2, 0
_0816E074: .4byte 0x0000025D
_0816E078:
	ldr r0, [r4, #0x44]
	ldr r0, [r0, #0x28]
	ands r0, r1
	cmp r0, #0
	beq _0816E086
_0816E082:
	movs r0, #1
	b _0816E088
_0816E086:
	movs r0, #0
_0816E088:
	adds r1, r0, #0
	cmp r1, #0
	bne _0816E0FE
	ldr r6, _0816E0A0 @ =0x00000836
	adds r0, r5, r6
	strh r1, [r0]
	movs r1, #0x21
	rsbs r1, r1, #0
	ldr r0, [r3]
	ands r0, r1
	movs r1, #0x40
	b _0816E0FA
	.align 2, 0
_0816E0A0: .4byte 0x00000836
_0816E0A4:
	movs r1, #0x20
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0816E0B2
	movs r0, #1
	b _0816E0B4
_0816E0B2:
	movs r0, #0
_0816E0B4:
	cmp r0, #0
	bne _0816E0FE
	movs r1, #1
	ldr r7, _0816E0D0 @ =0x0000025D
	adds r0, r4, r7
	ldrb r0, [r0]
	cmp r0, #0
	bne _0816E0D4
	ldr r0, [r4, #0x44]
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0816E0DE
	b _0816E0E2
	.align 2, 0
_0816E0D0: .4byte 0x0000025D
_0816E0D4:
	ldr r0, [r4, #0x44]
	ldr r0, [r0, #0x28]
	ands r0, r1
	cmp r0, #0
	beq _0816E0E2
_0816E0DE:
	movs r0, #1
	b _0816E0E4
_0816E0E2:
	movs r0, #0
_0816E0E4:
	cmp r0, #0
	beq _0816E0FE
	ldr r0, _0816E124 @ =0x00000836
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0x41
	rsbs r1, r1, #0
	ldr r0, [r3]
	ands r0, r1
	movs r1, #0x20
_0816E0FA:
	orrs r0, r1
	str r0, [r3]
_0816E0FE:
	adds r0, r4, #0
	bl FUN_0816dd40
	adds r0, r4, #0
	bl FUN_0816de1c
	adds r0, r4, #0
	bl FUN_0816d55c
	adds r0, r4, #0
	bl FUN_0816d6b0
_0816E116:
	adds r0, r4, #0
	bl FUN_0816cd3c
	movs r0, #1
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0816E124: .4byte 0x00000836

	thumb_func_start FUN_0816e128
FUN_0816e128: @ 0x0816E128
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl FUN_0816dae8
	movs r0, #0x20
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r4, r5, r1
	ldrh r1, [r4]
	ands r0, r1
	cmp r0, #0
	bne _0816E19A
	movs r0, #0x88
	lsls r0, r0, #1
	ands r1, r0
	cmp r1, #0
	bne _0816E164
	adds r0, r5, #0
	bl FUN_080e7078
	lsls r0, r0, #0x18
	adds r6, r5, #0
	adds r6, #8
	cmp r0, #0
	beq _0816E18E
	movs r1, #6
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	bne _0816E18E
_0816E164:
	movs r1, #0x97
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	adds r6, r5, #0
	adds r6, #8
	cmp r0, #0
	bne _0816E18E
	movs r0, #0x94
	lsls r0, r0, #1
	adds r4, r5, r0
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
_0816E18E:
	adds r0, r5, #0
	adds r0, #0xd8
	adds r1, r6, #0
	movs r2, #0
	bl FUN_082364c4
_0816E19A:
	movs r0, #1
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0816e1a4
FUN_0816e1a4: @ 0x0816E1A4
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _0816E1C4 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816E1C8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816E1CA
	.align 2, 0
_0816E1C4: .4byte 0x0000046C
_0816E1C8:
	movs r0, #0
_0816E1CA:
	ldr r3, _0816E298 @ =0x03002BE0
	mov ip, r3
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r6, r5, r1
	cmp r0, #0
	beq _0816E236
	ldr r4, _0816E29C @ =FUN_0816b190
	movs r3, #0x22
	ldr r2, _0816E2A0 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0816E2A4 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	ldr r3, _0816E2A8 @ =0x00000878
	adds r2, r7, r3
	mov r1, ip
	ldr r0, [r1]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	movs r2, #0x80
	lsls r2, r2, #0x12
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	strb r0, [r5, #5]
_0816E236:
	ldr r2, _0816E2AC @ =0x00000494
	adds r1, r5, r2
	movs r0, #0x40
	strh r0, [r1]
	mov r4, sp
	ldr r3, _0816E2A8 @ =0x00000878
	adds r2, r7, r3
	mov r1, ip
	ldr r0, [r1]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r2]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r3, #4]
	ldrh r0, [r2, #4]
	subs r1, r1, r0
	strh r1, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r5, #0x10]
	adds r0, r0, r3
	strh r0, [r5, #0x10]
	ldrh r0, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
	mov r1, ip
	ldr r0, [r1]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _0816E2B0 @ =0x0000A02F
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0816E2B8
	ldr r2, _0816E2B4 @ =0x00000482
	adds r1, r5, r2
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0816E2C8
	.align 2, 0
_0816E298: .4byte 0x03002BE0
_0816E29C: .4byte FUN_0816b190
_0816E2A0: .4byte 0x0000046D
_0816E2A4: .4byte 0x0000046B
_0816E2A8: .4byte 0x00000878
_0816E2AC: .4byte 0x00000494
_0816E2B0: .4byte 0x0000A02F
_0816E2B4: .4byte 0x00000482
_0816E2B8:
	ldr r3, _0816E2EC @ =0x00000482
	adds r0, r5, r3
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0816E2C8
	movs r0, #1
	strh r0, [r2]
_0816E2C8:
	ldr r6, _0816E2F0 @ =0x0000025D
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _0816E2F4
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _0816E30C
	.align 2, 0
_0816E2EC: .4byte 0x00000482
_0816E2F0: .4byte 0x0000025D
_0816E2F4:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_0816E30C:
	ldr r1, _0816E38C @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0816E326
	ldr r0, _0816E390 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _0816E3A0
_0816E326:
	movs r0, #0xf3
	lsls r0, r0, #2
	bl PlaySound_082406e0
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r2, #0
	strb r2, [r0]
	ldr r6, _0816E394 @ =0x00000469
	adds r0, r5, r6
	strb r2, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r2, [r0]
	ldr r1, _0816E398 @ =0x0000046C
	adds r0, r5, r1
	movs r1, #1
	strb r1, [r0]
	ldr r4, _0816E39C @ =FUN_080e48d0
	movs r3, #0x10
	subs r6, #0x17
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0816E38C @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
	adds r2, r5, #0
	adds r2, #0xd8
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
	b _0816E3AA
	.align 2, 0
_0816E38C: .4byte 0x0000046B
_0816E390: .4byte 0x03002BE0
_0816E394: .4byte 0x00000469
_0816E398: .4byte 0x0000046C
_0816E39C: .4byte FUN_080e48d0
_0816E3A0:
	ldr r6, _0816E3B4 @ =0x00000484
	adds r1, r5, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0816E3AA:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816E3B4: .4byte 0x00000484

	thumb_func_start FUN_0816e3b8
FUN_0816e3b8: @ 0x0816E3B8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _0816E3DC @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816E3E0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816E3E2
	.align 2, 0
_0816E3DC: .4byte 0x0000046C
_0816E3E0:
	movs r0, #0
_0816E3E2:
	movs r3, #8
	adds r3, r3, r5
	mov r8, r3
	cmp r0, #0
	bne _0816E3EE
	b _0816E588
_0816E3EE:
	movs r4, #0xb4
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r3, [r0]
	movs r1, #1
	ldr r2, _0816E468 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r4, _0816E46C @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r1, #0
	strh r2, [r0]
	ldr r4, _0816E470 @ =0x00000834
	adds r0, r7, r4
	strb r1, [r0]
	ldr r0, _0816E474 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, _0816E478 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0816E47C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0816E480 @ =0x0203B400
	adds r0, r0, r1
	movs r1, #0xff
	ldrb r6, [r0]
	mov r4, sp
	ldr r3, _0816E484 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #9
	mov r8, r2
	mov ip, r3
	cmp r0, #0
	blt _0816E488
	asrs r1, r0, #0xc
	b _0816E48E
	.align 2, 0
_0816E468: .4byte 0x0000046D
_0816E46C: .4byte 0x0000046B
_0816E470: .4byte 0x00000834
_0816E474: .4byte 0x03002BE0
_0816E478: .4byte 0x030046B8
_0816E47C: .4byte 0x000003FF
_0816E480: .4byte 0x0203B400
_0816E484: .4byte 0x085B0A08
_0816E488:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816E48E:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r6, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _0816E4AA
	asrs r0, r0, #0xc
	b _0816E4B0
_0816E4AA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0816E4B0:
	strh r0, [r4, #4]
	mov r0, sp
	add r3, sp, #8
	ldrh r1, [r3]
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r4, _0816E540 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #8]
	mov r2, sp
	ldrh r0, [r3, #4]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r3, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r3, #4]
	adds r4, r5, #0
	adds r4, #8
	ldrh r0, [r3]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r2, r8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0816E544 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0816E548 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r2, r5, r1
	movs r1, #0x3f
	ands r0, r1
	ldrb r2, [r2]
	adds r2, r0, r2
	movs r1, #0xff
	ldr r0, _0816E54C @ =0x00000888
	adds r6, r7, r0
	ands r2, r1
	adds r0, r2, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	mov r8, r4
	cmp r0, #0
	blt _0816E550
	asrs r1, r0, #0xc
	b _0816E556
	.align 2, 0
_0816E540: .4byte 0xFFFF0000
_0816E544: .4byte 0x000003FF
_0816E548: .4byte 0x0203B400
_0816E54C: .4byte 0x00000888
_0816E550:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816E556:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	lsls r0, r2, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _0816E570
	asrs r0, r0, #0xc
	b _0816E576
_0816E570:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0816E576:
	strh r0, [r6, #4]
	adds r0, r5, #0
	adds r1, r3, #0
	bl FUN_0816db54
	ldr r3, _0816E628 @ =0x000007EA
	adds r1, r7, r3
	movs r0, #1
	strh r0, [r1]
_0816E588:
	ldr r4, _0816E62C @ =0x00000834
	adds r6, r7, r4
	ldrb r1, [r6]
	mov r4, sp
	lsls r1, r1, #3
	adds r1, r1, r7
	ldr r0, _0816E630 @ =0x000007EC
	adds r1, r1, r0
	ldrh r0, [r1]
	ldrh r2, [r5, #8]
	subs r0, r0, r2
	mov r2, sp
	strh r0, [r2]
	ldrh r0, [r1, #2]
	mov r3, r8
	ldrh r2, [r3, #2]
	subs r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	adds r0, r5, #0
	bl FUN_0816d920
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r4, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #3
	cmp r1, r0
	ble _0816E68C
	ldrb r1, [r6]
	lsls r1, r1, #3
	adds r1, r7, r1
	ldr r4, _0816E630 @ =0x000007EC
	adds r0, r1, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r3, #8
	ldrsh r2, [r5, r3]
	subs r0, r0, r2
	adds r4, #4
	adds r1, r1, r4
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r3, #0xc
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r5, #5]
	subs r4, #6
	adds r0, r7, r4
	mov r6, sp
	ldrb r3, [r5, #5]
	ldrh r4, [r0]
	ldr r2, _0816E634 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0816E638
	asrs r1, r0, #0xc
	b _0816E63E
	.align 2, 0
_0816E628: .4byte 0x000007EA
_0816E62C: .4byte 0x00000834
_0816E630: .4byte 0x000007EC
_0816E634: .4byte 0x085B0A08
_0816E638:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816E63E:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	ldr r1, _0816E658 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _0816E65C
	asrs r0, r0, #0xc
	b _0816E662
	.align 2, 0
_0816E658: .4byte 0x085B0A08
_0816E65C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0816E662:
	strh r0, [r6, #4]
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r5, #0x10]
	adds r0, r0, r3
	strh r0, [r5, #0x10]
	mov r0, sp
	ldrh r0, [r0, #4]
	ldrh r4, [r5, #0x14]
	adds r0, r0, r4
	strh r0, [r5, #0x14]
	ldr r0, _0816E688 @ =0x00000888
	adds r2, r7, r0
	ldr r0, [r5, #0x10]
	ldr r1, [r5, #0x14]
	str r0, [r2]
	str r1, [r2, #4]
	b _0816E7B8
	.align 2, 0
_0816E688: .4byte 0x00000888
_0816E68C:
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bhi _0816E69C
	b _0816E7B8
_0816E69C:
	ldr r1, _0816E728 @ =0x00000888
	adds r3, r7, r1
	ldr r4, _0816E72C @ =0x0000082C
	adds r2, r7, r4
	ldrh r0, [r2]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #2]
	mov r4, r8
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	ldr r0, _0816E730 @ =0x0000088A
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
	ldrh r0, [r2]
	strh r0, [r5, #8]
	movs r1, #0x83
	lsls r1, r1, #4
	adds r0, r7, r1
	ldrh r0, [r0]
	strh r0, [r5, #0xc]
	movs r0, #0
	strb r0, [r6]
	ldr r0, _0816E734 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, _0816E738 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0816E73C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0816E740 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r1, #0x3f
	ands r0, r1
	ldrb r2, [r2]
	adds r4, r0, r2
	movs r1, #0xff
	mov r3, sp
	ands r4, r1
	ldr r2, _0816E744 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #9
	mov ip, r2
	cmp r0, #0
	blt _0816E748
	asrs r1, r0, #0xc
	b _0816E74E
	.align 2, 0
_0816E728: .4byte 0x00000888
_0816E72C: .4byte 0x0000082C
_0816E730: .4byte 0x0000088A
_0816E734: .4byte 0x03002BE0
_0816E738: .4byte 0x030046B8
_0816E73C: .4byte 0x000003FF
_0816E740: .4byte 0x0203B400
_0816E744: .4byte 0x085B0A08
_0816E748:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816E74E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _0816E76A
	asrs r0, r0, #0xc
	b _0816E770
_0816E76A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0816E770:
	strh r0, [r3, #4]
	add r1, sp, #8
	mov r0, sp
	ldrh r2, [r0]
	ldrh r3, [r1]
	adds r2, r2, r3
	strh r2, [r1]
	mov r3, sp
	ldrh r0, [r3, #4]
	ldrh r4, [r1, #4]
	adds r0, r0, r4
	strh r0, [r1, #4]
	ldrh r0, [r5, #8]
	subs r2, r2, r0
	mov r0, sp
	strh r2, [r0]
	ldrh r0, [r1, #2]
	mov r4, r8
	ldrh r2, [r4, #2]
	subs r0, r0, r2
	strh r0, [r3, #2]
	ldrh r0, [r1, #4]
	ldrh r2, [r4, #4]
	subs r0, r0, r2
	strh r0, [r3, #4]
	adds r0, r5, #0
	bl FUN_0816db54
	ldr r0, _0816E7B4 @ =0x000007EA
	adds r1, r7, r0
	ldrh r0, [r1]
	lsrs r0, r0, #1
	strh r0, [r1]
	b _0816E814
	.align 2, 0
_0816E7B4: .4byte 0x000007EA
_0816E7B8:
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0816E7EC
	ldr r2, _0816E7E4 @ =0x00000484
	adds r0, r5, r2
	ldr r0, [r0]
	movs r1, #0x10
	bl Mod
	cmp r0, #0
	bne _0816E80A
	ldr r3, _0816E7E8 @ =0x000007EA
	adds r1, r7, r3
	ldrh r0, [r1]
	cmp r0, #0xb
	bhi _0816E80A
	adds r0, #1
	b _0816E808
	.align 2, 0
_0816E7E4: .4byte 0x00000484
_0816E7E8: .4byte 0x000007EA
_0816E7EC:
	ldr r4, _0816E820 @ =0x00000484
	adds r0, r5, r4
	ldr r0, [r0]
	movs r1, #8
	bl Mod
	cmp r0, #0
	bne _0816E80A
	ldr r0, _0816E824 @ =0x000007EA
	adds r1, r7, r0
	ldrh r0, [r1]
	cmp r0, #0xb
	bhi _0816E80A
	adds r0, #2
_0816E808:
	strh r0, [r1]
_0816E80A:
	ldr r2, _0816E820 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0816E814:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816E820: .4byte 0x00000484
_0816E824: .4byte 0x000007EA

	thumb_func_start FUN_0816e828
FUN_0816e828: @ 0x0816E828
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _0816E850 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816E854
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816E856
	.align 2, 0
_0816E850: .4byte 0x0000046C
_0816E854:
	movs r0, #0
_0816E856:
	adds r7, r5, #0
	adds r7, #8
	cmp r0, #0
	bne _0816E860
	b _0816E9F4
_0816E860:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r4, _0816E8D8 @ =0x0000046D
	adds r0, r5, r4
	movs r2, #0
	strb r1, [r0]
	subs r4, #2
	adds r0, r5, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r1, #0
	strh r2, [r0]
	ldr r0, _0816E8DC @ =0x00000834
	add r0, r8
	strb r1, [r0]
	ldr r0, _0816E8E0 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, _0816E8E4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0816E8E8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _0816E8EC @ =0x0203B400
	adds r0, r0, r4
	movs r1, #0xff
	ldrb r6, [r0]
	mov r4, sp
	ldr r3, _0816E8F0 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #9
	adds r7, r2, #0
	mov ip, r3
	cmp r0, #0
	blt _0816E8F4
	asrs r1, r0, #0xc
	b _0816E8FA
	.align 2, 0
_0816E8D8: .4byte 0x0000046D
_0816E8DC: .4byte 0x00000834
_0816E8E0: .4byte 0x03002BE0
_0816E8E4: .4byte 0x030046B8
_0816E8E8: .4byte 0x000003FF
_0816E8EC: .4byte 0x0203B400
_0816E8F0: .4byte 0x085B0A08
_0816E8F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816E8FA:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r6, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _0816E916
	asrs r0, r0, #0xc
	b _0816E91C
_0816E916:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0816E91C:
	strh r0, [r4, #4]
	mov r0, sp
	add r3, sp, #8
	ldrh r1, [r3]
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r4, _0816E9AC @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #8]
	mov r2, sp
	ldrh r0, [r3, #4]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r3, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r3, #4]
	adds r4, r5, #0
	adds r4, #8
	ldrh r0, [r3]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _0816E9B0 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r2, _0816E9B4 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r2, r5, r1
	movs r1, #0x3f
	ands r0, r1
	ldrb r2, [r2]
	adds r2, r0, r2
	movs r1, #0xff
	ldr r6, _0816E9B8 @ =0x00000888
	add r6, r8
	ands r2, r1
	adds r0, r2, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	adds r7, r4, #0
	cmp r0, #0
	blt _0816E9BC
	asrs r1, r0, #0xc
	b _0816E9C2
	.align 2, 0
_0816E9AC: .4byte 0xFFFF0000
_0816E9B0: .4byte 0x000003FF
_0816E9B4: .4byte 0x0203B400
_0816E9B8: .4byte 0x00000888
_0816E9BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816E9C2:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	lsls r0, r2, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _0816E9DC
	asrs r0, r0, #0xc
	b _0816E9E2
_0816E9DC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0816E9E2:
	strh r0, [r6, #4]
	adds r0, r5, #0
	adds r1, r3, #0
	bl FUN_0816db54
	ldr r1, _0816EA90 @ =0x000007EA
	add r1, r8
	movs r0, #1
	strh r0, [r1]
_0816E9F4:
	ldr r6, _0816EA94 @ =0x00000834
	add r6, r8
	ldrb r1, [r6]
	mov r4, sp
	lsls r1, r1, #3
	add r1, r8
	ldr r3, _0816EA98 @ =0x000007EC
	adds r1, r1, r3
	ldrh r0, [r1]
	ldrh r2, [r5, #8]
	subs r0, r0, r2
	mov r2, sp
	strh r0, [r2]
	ldrh r0, [r1, #2]
	ldrh r2, [r7, #2]
	subs r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	adds r0, r5, #0
	bl FUN_0816d920
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r4, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #3
	cmp r1, r0
	ble _0816EAF4
	ldrb r1, [r6]
	lsls r1, r1, #3
	add r1, r8
	ldr r4, _0816EA98 @ =0x000007EC
	adds r0, r1, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r3, #8
	ldrsh r2, [r5, r3]
	subs r0, r0, r2
	adds r4, #4
	adds r1, r1, r4
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r3, #0xc
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r5, #5]
	ldr r0, _0816EA90 @ =0x000007EA
	add r0, r8
	mov r6, sp
	ldrb r3, [r5, #5]
	ldrh r4, [r0]
	ldr r2, _0816EA9C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0816EAA0
	asrs r1, r0, #0xc
	b _0816EAA6
	.align 2, 0
_0816EA90: .4byte 0x000007EA
_0816EA94: .4byte 0x00000834
_0816EA98: .4byte 0x000007EC
_0816EA9C: .4byte 0x085B0A08
_0816EAA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816EAA6:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	ldr r1, _0816EAC0 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _0816EAC4
	asrs r0, r0, #0xc
	b _0816EACA
	.align 2, 0
_0816EAC0: .4byte 0x085B0A08
_0816EAC4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0816EACA:
	strh r0, [r6, #4]
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r5, #0x10]
	adds r0, r0, r3
	strh r0, [r5, #0x10]
	mov r0, sp
	ldrh r0, [r0, #4]
	ldrh r4, [r5, #0x14]
	adds r0, r0, r4
	strh r0, [r5, #0x14]
	ldr r2, _0816EAF0 @ =0x00000888
	add r2, r8
	ldr r0, [r5, #0x10]
	ldr r1, [r5, #0x14]
	str r0, [r2]
	str r1, [r2, #4]
	b _0816EC10
	.align 2, 0
_0816EAF0: .4byte 0x00000888
_0816EAF4:
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bhi _0816EB04
	b _0816EC10
_0816EB04:
	ldr r3, _0816EB90 @ =0x00000888
	add r3, r8
	ldr r2, _0816EB94 @ =0x0000082C
	add r2, r8
	ldrh r0, [r2]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	ldr r1, _0816EB98 @ =0x0000088A
	add r1, r8
	movs r0, #0
	strh r0, [r1]
	ldrh r0, [r2]
	strh r0, [r5, #8]
	movs r0, #0x83
	lsls r0, r0, #4
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r5, #0xc]
	movs r0, #0
	strb r0, [r6]
	ldr r0, _0816EB9C @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, _0816EBA0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0816EBA4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0816EBA8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r1, #0x3f
	ands r0, r1
	ldrb r2, [r2]
	adds r4, r0, r2
	movs r1, #0xff
	mov r3, sp
	ands r4, r1
	ldr r2, _0816EBAC @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #8
	mov ip, r2
	cmp r0, #0
	blt _0816EBB0
	asrs r1, r0, #0xc
	b _0816EBB6
	.align 2, 0
_0816EB90: .4byte 0x00000888
_0816EB94: .4byte 0x0000082C
_0816EB98: .4byte 0x0000088A
_0816EB9C: .4byte 0x03002BE0
_0816EBA0: .4byte 0x030046B8
_0816EBA4: .4byte 0x000003FF
_0816EBA8: .4byte 0x0203B400
_0816EBAC: .4byte 0x085B0A08
_0816EBB0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816EBB6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #1
	muls r0, r1, r0
	cmp r0, #0
	blt _0816EBD2
	asrs r0, r0, #0xc
	b _0816EBD8
_0816EBD2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0816EBD8:
	strh r0, [r3, #4]
	add r1, sp, #8
	mov r0, sp
	ldrh r2, [r0]
	ldrh r3, [r1]
	adds r2, r2, r3
	strh r2, [r1]
	mov r3, sp
	ldrh r0, [r3, #4]
	ldrh r4, [r1, #4]
	adds r0, r0, r4
	strh r0, [r1, #4]
	ldrh r0, [r5, #8]
	subs r2, r2, r0
	mov r0, sp
	strh r2, [r0]
	ldrh r0, [r1, #2]
	ldrh r2, [r7, #2]
	subs r0, r0, r2
	strh r0, [r3, #2]
	ldrh r0, [r1, #4]
	ldrh r2, [r7, #4]
	subs r0, r0, r2
	strh r0, [r3, #4]
	adds r0, r5, #0
	bl FUN_0816db54
	b _0816EC38
_0816EC10:
	ldr r1, _0816EC44 @ =0x00000484
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0x10
	bl Mod
	cmp r0, #0
	bne _0816EC2E
	ldr r1, _0816EC48 @ =0x000007EA
	add r1, r8
	ldrh r0, [r1]
	cmp r0, #0x11
	bhi _0816EC2E
	adds r0, #1
	strh r0, [r1]
_0816EC2E:
	ldr r2, _0816EC44 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0816EC38:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816EC44: .4byte 0x00000484
_0816EC48: .4byte 0x000007EA

	thumb_func_start FUN_0816ec4c
FUN_0816ec4c: @ 0x0816EC4C
	ldr r1, _0816EC58 @ =0x0000063C
	adds r0, r0, r1
	ldr r1, _0816EC5C @ =0x085ADA98
	str r1, [r0]
	bx lr
	.align 2, 0
_0816EC58: .4byte 0x0000063C
_0816EC5C: .4byte 0x085ADA98

	thumb_func_start FUN_0816ec60
FUN_0816ec60: @ 0x0816EC60
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0816EC78 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816EC7C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816EC7E
	.align 2, 0
_0816EC78: .4byte 0x0000046C
_0816EC7C:
	movs r0, #0
_0816EC7E:
	cmp r0, #0
	beq _0816ECC6
	ldr r4, _0816ECE0 @ =0x0816B881
	movs r3, #0xa
	ldr r2, _0816ECE4 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0816ECE8 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	subs r1, #0x48
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r1, [r0]
_0816ECC6:
	ldr r1, _0816ECE8 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0816ECF0
	ldr r0, _0816ECEC @ =0x03002BE0
	ldr r1, [r0]
	adds r1, #0x2c
	adds r0, r5, #0
	bl FUN_0816d468
	b _0816ECFA
	.align 2, 0
_0816ECE0: .4byte 0x0816B881
_0816ECE4: .4byte 0x0000046D
_0816ECE8: .4byte 0x0000046B
_0816ECEC: .4byte 0x03002BE0
_0816ECF0:
	ldr r2, _0816ED00 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0816ECFA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0816ED00: .4byte 0x00000484

	thumb_func_start FUN_0816ed04
FUN_0816ed04: @ 0x0816ED04
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, _0816ED88 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816ED28
	movs r0, #0
	strb r0, [r1]
_0816ED28:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0816ED3E
	b _0816EE78
_0816ED3E:
	ldr r2, _0816ED8C @ =0x00000484
	adds r1, r6, r2
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _0816ED4A
	b _0816EE74
_0816ED4A:
	adds r0, r6, #0
	bl FUN_0816ce70
	add r7, sp, #4
	adds r0, r6, #0
	adds r0, #0x9c
	ldr r1, [r0, #8]
	ldrh r0, [r1]
	strh r0, [r7]
	ldrh r1, [r1, #2]
	strh r1, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r5, r7, #0
	cmp r2, #0
	blt _0816ED82
	cmp r1, #0
	blt _0816ED82
	ldr r0, _0816ED90 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0816ED82
	ldr r0, _0816ED94 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0816ED98
_0816ED82:
	movs r4, #0
	b _0816EDA6
	.align 2, 0
_0816ED88: .4byte 0x0000046C
_0816ED8C: .4byte 0x00000484
_0816ED90: .4byte 0x030046A8
_0816ED94: .4byte 0x030046AC
_0816ED98:
	ldr r0, _0816EDB8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0816EDA6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0816EDBC
	adds r0, #4
	b _0816EDC8
	.align 2, 0
_0816EDB8: .4byte 0x030046A4
_0816EDBC:
	ldr r0, _0816EDDC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0816EDC8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0816EDE0
	cmp r2, #2
	beq _0816EDE4
	b _0816EDE8
	.align 2, 0
_0816EDDC: .4byte 0x030046A4
_0816EDE0:
	ldrb r0, [r7, #4]
	b _0816EDE6
_0816EDE4:
	ldrb r0, [r7]
_0816EDE6:
	subs r1, r1, r0
_0816EDE8:
	movs r4, #0
	movs r0, #0
	mov r8, r0
	strh r1, [r7, #2]
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_0816cfa4
	adds r0, r6, #0
	bl FUN_0816cfe0
	movs r1, #1
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r4, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r4, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	adds r2, #0x1a
	adds r0, r6, r2
	mov r2, r8
	str r2, [r0]
	ldr r2, _0816EE68 @ =0x0000046C
	adds r0, r6, r2
	strb r1, [r0]
	adds r3, r6, #0
	adds r3, #8
	add r2, sp, #4
	ldrh r0, [r2]
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r5, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r5, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r2, #4
	ldrsh r1, [r5, r2]
	bl FUN_0823785c
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	ldr r1, _0816EE6C @ =0x00000888
	add r1, sb
	mov r0, r8
	str r0, [sp]
	mov r0, sp
	ldr r2, _0816EE70 @ =0x05000002
	bl CpuSet
	b _0816EE78
	.align 2, 0
_0816EE68: .4byte 0x0000046C
_0816EE6C: .4byte 0x00000888
_0816EE70: .4byte 0x05000002
_0816EE74:
	adds r0, #1
	str r0, [r1]
_0816EE78:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0816ee88
FUN_0816ee88: @ 0x0816EE88
	movs r1, #0xc7
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r1, _0816EE94 @ =0x085ADAA4
	str r1, [r0]
	bx lr
	.align 2, 0
_0816EE94: .4byte 0x085ADAA4

	thumb_func_start FUN_0816ee98
FUN_0816ee98: @ 0x0816EE98
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	ldr r2, _0816EEB8 @ =0x0000046C
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816EEBC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816EEBE
	.align 2, 0
_0816EEB8: .4byte 0x0000046C
_0816EEBC:
	movs r0, #0
_0816EEBE:
	cmp r0, #0
	beq _0816EEEE
	ldr r5, _0816EF88 @ =0x000005A4
	adds r0, r4, r5
	ldr r3, [r0]
	movs r2, #0
	ldr r7, _0816EF8C @ =0x0000046D
	adds r1, r4, r7
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0816EF90 @ =0x0000046B
	adds r0, r4, r1
	strb r2, [r0]
	subs r5, #0x51
	adds r0, r4, r5
	strb r2, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r4, r7
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r2, [r0]
_0816EEEE:
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrb r0, [r0]
	strb r0, [r4, #5]
	ldr r0, _0816EF94 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r5, #1
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0816EFB4
	movs r7, #0xf2
	lsls r7, r7, #1
	adds r0, r4, r7
	ldr r2, _0816EF98 @ =0x00000848
	adds r1, r6, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _0816EFB4
	ldr r0, _0816EF9C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0816EFB4
	movs r1, #4
	ldr r0, _0816EFA0 @ =0x03002BC0
	ldr r3, [r0]
	ands r3, r1
	cmp r3, #0
	bne _0816EFB4
	movs r1, #2
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r4, r7
	strb r1, [r0]
	ldr r1, _0816EFA4 @ =0x00000469
	adds r0, r4, r1
	strb r3, [r0]
	ldr r2, _0816EFA8 @ =0x0000046A
	adds r0, r4, r2
	strb r3, [r0]
	adds r7, #0x1c
	adds r0, r4, r7
	str r3, [r0]
	adds r1, #3
	adds r0, r4, r1
	strb r5, [r0]
	ldr r2, _0816EFAC @ =FUN_080e48d0
	movs r1, #0x10
	subs r7, #0x17
	adds r0, r4, r7
	strb r5, [r0]
	ldr r5, _0816EF90 @ =0x0000046B
	adds r0, r4, r5
	strb r3, [r0]
	adds r7, #0xe6
	adds r0, r4, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r3, [r0]
	ldr r5, _0816EFB0 @ =0x00000844
	adds r0, r6, r5
	ldrh r0, [r0]
	movs r1, #0
	bl Script_ExecById
	b _0816EFBE
	.align 2, 0
_0816EF88: .4byte 0x000005A4
_0816EF8C: .4byte 0x0000046D
_0816EF90: .4byte 0x0000046B
_0816EF94: .4byte 0x030044E0
_0816EF98: .4byte 0x00000848
_0816EF9C: .4byte 0x030047A4
_0816EFA0: .4byte 0x03002BC0
_0816EFA4: .4byte 0x00000469
_0816EFA8: .4byte 0x0000046A
_0816EFAC: .4byte FUN_080e48d0
_0816EFB0: .4byte 0x00000844
_0816EFB4:
	ldr r7, _0816EFC4 @ =0x00000484
	adds r1, r4, r7
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0816EFBE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816EFC4: .4byte 0x00000484

	thumb_func_start FUN_0816efc8
FUN_0816efc8: @ 0x0816EFC8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _0816EFE0 @ =0x0000046C
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816EFE4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816EFE6
	.align 2, 0
_0816EFE0: .4byte 0x0000046C
_0816EFE4:
	movs r0, #0
_0816EFE6:
	cmp r0, #0
	beq _0816F024
	ldr r1, _0816F018 @ =0x000005A4
	adds r0, r4, r1
	ldr r3, [r0]
	movs r2, #0
	ldr r0, _0816F01C @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0816F020 @ =0x0000046B
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r4, r1
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r2, [r0]
	b _0816F03E
	.align 2, 0
_0816F018: .4byte 0x000005A4
_0816F01C: .4byte 0x0000046D
_0816F020: .4byte 0x0000046B
_0816F024:
	ldr r0, _0816F044 @ =0x00000484
	adds r5, r4, r0
	ldr r0, [r5]
	cmp r0, #0
	bne _0816F038
	adds r0, r4, #0
	adds r0, #0x48
	movs r1, #1
	bl FUN_08022488
_0816F038:
	ldr r0, [r5]
	adds r0, #1
	str r0, [r5]
_0816F03E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0816F044: .4byte 0x00000484

	thumb_func_start FUN_0816f048
FUN_0816f048: @ 0x0816F048
	ldr r1, _0816F054 @ =0x0000064C
	adds r0, r0, r1
	ldr r1, _0816F058 @ =0x085ADAAC
	str r1, [r0]
	bx lr
	.align 2, 0
_0816F054: .4byte 0x0000064C
_0816F058: .4byte 0x085ADAAC

	thumb_func_start FUN_0816f05c
FUN_0816f05c: @ 0x0816F05C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0816dec8
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r2, _0816F094 @ =0x0000062C
	adds r1, r4, r2
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080e4964
	adds r0, r4, #0
	bl FUN_0816e128
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0816F094: .4byte 0x0000062C

	thumb_func_start FUN_0816f098
FUN_0816f098: @ 0x0816F098
	push {lr}
	movs r1, #0xec
	lsls r1, r1, #1
	adds r2, r0, r1
	ldr r1, _0816F0B4 @ =0x03002BE0
	ldr r1, [r1]
	adds r1, #0x24
	str r1, [r2]
	bl FUN_080f06b0
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_0816F0B4: .4byte 0x03002BE0

	thumb_func_start EnemyGhost_Destroy
EnemyGhost_Destroy: @ 0x0816F0B8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl FUN_0816db2c
	ldr r1, _0816F0D4 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0816F0D8
	ldr r0, [r4, #0x44]
	bl FUN_0822a4e0
	b _0816F0E0
	.align 2, 0
_0816F0D4: .4byte 0x0000025D
_0816F0D8:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl FUN_0822f1c0
_0816F0E0:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _0816F0FC @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _0816F100
	movs r0, #1
	b _0816F102
	.align 2, 0
_0816F0FC: .4byte 0x00000474
_0816F100:
	movs r0, #0
_0816F102:
	cmp r0, #0
	beq _0816F10E
	adds r0, r4, #0
	adds r0, #0x48
	bl FUN_08022428
_0816F10E:
	ldr r1, _0816F168 @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _0816F126
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl FUN_080138fc
	movs r0, #1
	strb r0, [r5]
_0816F126:
	ldr r0, _0816F16C @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _0816F13E
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08247504
	movs r0, #1
	strb r0, [r5]
_0816F13E:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0816F156
	adds r0, r4, #0
	bl FUN_08002a58
_0816F156:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0816F170
	movs r0, #1
	b _0816F172
	.align 2, 0
_0816F168: .4byte 0x0000044C
_0816F16C: .4byte 0x0000044D
_0816F170:
	movs r0, #0
_0816F172:
	cmp r0, #0
	beq _0816F17E
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_0807f598
_0816F17E:
	adds r0, r4, #0
	bl FUN_0823b284
	adds r0, r4, #0
	adds r0, #0xd8
	bl FUN_08236424
	adds r0, r4, #0
	bl FUN_080ec6fc
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EnemyGhost_Init
EnemyGhost_Init: @ 0x0816F19C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c4
	adds r7, r0, #0
	str r7, [sp, #0x2c]
	ldr r1, _0816F22C @ =0x000007DC
	adds r0, r7, r1
	movs r6, #0
	str r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_080e37e8
	ldr r2, _0816F230 @ =0x000001DF
	adds r1, r7, r2
	movs r0, #0x17
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_0816d198
	ldr r3, _0816F234 @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0816F244
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _0816F238 @ =0x0000D637
	bl Video_GetActorSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r5, #0
	ldr r1, _0816F23C @ =0x000029FB
	bl FUN_080e3804
	ldr r4, _0816F230 @ =0x000001DF
	adds r0, r7, r4
	ldrb r1, [r0]
	str r0, [sp, #0x120]
	cmp r1, #0x11
	beq _0816F214
	cmp r1, #0x17
	bne _0816F218
_0816F214:
	movs r0, #1
	strb r0, [r5, #7]
_0816F218:
	movs r5, #0xef
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0
	strb r0, [r1]
	ldr r6, _0816F240 @ =0x000004B7
	adds r6, r7, r6
	str r6, [sp, #0x8c]
	b _0816F2AE
	.align 2, 0
_0816F22C: .4byte 0x000007DC
_0816F230: .4byte 0x000001DF
_0816F234: .4byte 0x0000025D
_0816F238: .4byte 0x0000D637
_0816F23C: .4byte 0x000029FB
_0816F240: .4byte 0x000004B7
_0816F244:
	movs r0, #0x80
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x80
	bl ClearMemory
	ldr r4, [r7, #0x44]
	add r0, sp, #0x14
	mov r8, r0
	str r6, [sp, #0x10]
	add r0, sp, #0x10
	mov r1, r8
	ldr r2, _0816F32C @ =0x05000002
	bl CpuSet
	ldr r0, _0816F330 @ =0x0000CB05
	ldr r1, _0816F334 @ =0x0000D637
	bl GetFile
	adds r1, r0, #0
	adds r2, r4, #0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r2!, {r3, r5}
	adds r0, r4, #0
	bl OpenSpriteSetFile
	adds r0, r4, #0
	adds r0, #0x20
	movs r1, #2
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	mov r6, r8
	str r6, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822f3fc
	ldr r0, _0816F338 @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r2, _0816F33C @ =0x000001DF
	adds r2, r7, r2
	str r2, [sp, #0x120]
	str r1, [sp, #0x8c]
_0816F2AE:
	str r7, [sp, #0x30]
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r3, r3, r7
	mov sb, r3
	movs r4, #0
	str r4, [r3]
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r5, r5, r7
	mov r8, r5
	str r4, [r5]
	ldr r6, _0816F340 @ =0x0000046F
	adds r0, r7, r6
	strb r4, [r0]
	movs r0, #0xde
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r2, #0
	mov sl, r2
	movs r0, #8
	strh r0, [r1]
	movs r0, #0x4d
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r3, _0816F344 @ =0x00000474
	adds r6, r7, r3
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _0816F32C @ =0x05000002
	bl CpuSet
	ldr r4, _0816F348 @ =0x000004B6
	adds r2, r7, r4
	mov r0, sl
	strb r0, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1bc]
	bl prepare_08231510
	mov r1, sb
	str r1, [sp, #0x90]
	mov r3, r8
	str r3, [sp, #0x98]
	str r6, [sp, #0x5c]
	ldr r2, [sp, #0x1bc]
	adds r6, r2, #0
	cmp r0, #0
	bne _0816F31A
	b _0816F47C
_0816F31A:
	bl VM_GetPC
	cmp r0, #0
	beq _0816F34C
	bl Script_GetValue
	adds r1, r0, #0
	b _0816F34E
	.align 2, 0
_0816F32C: .4byte 0x05000002
_0816F330: .4byte 0x0000CB05
_0816F334: .4byte 0x0000D637
_0816F338: .4byte 0x000004B7
_0816F33C: .4byte 0x000001DF
_0816F340: .4byte 0x0000046F
_0816F344: .4byte 0x00000474
_0816F348: .4byte 0x000004B6
_0816F34C:
	movs r1, #0
_0816F34E:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _0816F374 @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0x198]
	str r4, [sp, #0x19c]
	cmp r0, #0
	beq _0816F378
	bl Script_GetValue
	adds r1, r0, #0
	b _0816F37A
	.align 2, 0
_0816F374: .4byte 0x00000251
_0816F378:
	movs r1, #0
_0816F37A:
	ldr r2, _0816F3B0 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _0816F3B4 @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0x198]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0x1a0]
	cmp r0, #0
	beq _0816F3B8
	bl Script_GetValue
	b _0816F3BC
	.align 2, 0
_0816F3B0: .4byte 0x00000252
_0816F3B4: .4byte 0x000004B4
_0816F3B8:
	ldr r4, [sp, #0x198]
	ldrb r0, [r4]
_0816F3BC:
	strb r0, [r6]
	ldr r5, [sp, #0x198]
	ldrb r1, [r5]
	ldr r6, [sp, #0x1a0]
	ldrb r2, [r6]
	add r0, sp, #0x1c
	bl FUN_08234f90
	add r0, sp, #0x1c
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, sp
	ldrh r0, [r1, #0x20]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0816F3F4
	cmp r1, #0
	blt _0816F3F4
	ldr r0, _0816F3F8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0816F3F4
	ldr r0, _0816F3FC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0816F400
_0816F3F4:
	movs r1, #0
	b _0816F40E
	.align 2, 0
_0816F3F8: .4byte 0x030046A8
_0816F3FC: .4byte 0x030046AC
_0816F400:
	ldr r0, _0816F428 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_0816F40E:
	ldr r2, _0816F42C @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0816F430
	adds r0, #4
	b _0816F43C
	.align 2, 0
_0816F428: .4byte 0x030046A4
_0816F42C: .4byte 0x00000256
_0816F430:
	ldr r0, _0816F450 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0816F43C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0816F454
	cmp r2, #2
	beq _0816F458
	b _0816F45C
	.align 2, 0
_0816F450: .4byte 0x030046A4
_0816F454:
	ldrb r0, [r4, #4]
	b _0816F45A
_0816F458:
	ldrb r0, [r4]
_0816F45A:
	subs r1, r1, r0
_0816F45C:
	ldr r3, _0816F474 @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _0816F478 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x34]
	b _0816F4BC
	.align 2, 0
_0816F474: .4byte 0x00000472
_0816F478: .4byte 0x0000FFFF
_0816F47C:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _0816F4E0 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _0816F4E4 @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _0816F4E8 @ =0x000004B4
	adds r1, r7, r6
	adds r0, r1, r0
	mov r6, sl
	strb r6, [r0]
	ldrb r2, [r2]
	movs r0, #1
	eors r0, r2
	adds r1, r1, r0
	strb r6, [r1]
	movs r0, #0
	str r0, [sp, #0x34]
	str r5, [sp, #0x198]
	str r4, [sp, #0x19c]
	str r3, [sp, #0x1a0]
_0816F4BC:
	movs r0, #0x4e
	movs r1, #0
	bl Script_GetKeywordValue
	mov sb, r0
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _0816F506
	bl VM_GetPC
	cmp r0, #0
	beq _0816F4EC
	bl Script_GetValue
	adds r4, r0, #0
	b _0816F4EE
	.align 2, 0
_0816F4E0: .4byte 0x00000251
_0816F4E4: .4byte 0x00000252
_0816F4E8: .4byte 0x000004B4
_0816F4EC:
	movs r4, #0x30
_0816F4EE:
	bl VM_GetPC
	cmp r0, #0
	beq _0816F500
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _0816F502
_0816F500:
	movs r5, #0x40
_0816F502:
	mov r8, r4
	b _0816F50C
_0816F506:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_0816F50C:
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _0816F544
	bl VM_GetPC
	cmp r0, #0
	beq _0816F526
	bl Script_GetValue
	adds r6, r0, #0
	b _0816F528
_0816F526:
	movs r6, #0
_0816F528:
	bl VM_GetPC
	cmp r0, #0
	beq _0816F538
	bl Script_GetValue
	adds r1, r0, #0
	b _0816F53A
_0816F538:
	movs r1, #0
_0816F53A:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _0816F54E
_0816F544:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_0816F54E:
	movs r0, #0x61
	bl prepare_08231510
	ldr r1, _0816F7E0 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0x1b0]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x190]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0xac]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xa4]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x1a4]
	lsls r4, r4, #0x10
	str r4, [sp, #0x10c]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0x118]
	lsls r6, r6, #0x10
	str r6, [sp, #0x124]
	lsls r5, r5, #0x10
	str r5, [sp, #0x114]
	ldr r4, _0816F7E4 @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0x1ac]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x100]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x44]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x128]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x130]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x58]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x64]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x3c]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x78]
	ldr r1, _0816F7E8 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x6c]
	ldr r2, _0816F7EC @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x70]
	ldr r3, _0816F7F0 @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x74]
	ldr r4, _0816F7F4 @ =0x00000476
	adds r4, r7, r4
	str r4, [sp, #0x60]
	movs r5, #0x8f
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x68]
	ldr r6, _0816F7F8 @ =0x000004A4
	adds r6, r7, r6
	str r6, [sp, #0x84]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x88]
	movs r2, #0xb0
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xdc]
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xe4]
	movs r4, #0xb2
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xf0]
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x108]
	ldr r6, _0816F7FC @ =0x000005A4
	adds r6, r7, r6
	str r6, [sp, #0x110]
	movs r1, #0xb8
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x13c]
	ldr r2, _0816F800 @ =0x000005C4
	adds r2, r7, r2
	str r2, [sp, #0x140]
	ldr r3, _0816F804 @ =0x000005CC
	adds r3, r7, r3
	str r3, [sp, #0x148]
	movs r4, #0xba
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x14c]
	ldr r5, _0816F808 @ =0x000005D4
	adds r5, r7, r5
	str r5, [sp, #0x150]
	ldr r6, _0816F80C @ =0x000005DC
	adds r6, r7, r6
	str r6, [sp, #0x158]
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x144]
	ldr r2, _0816F810 @ =0x00000584
	adds r2, r7, r2
	str r2, [sp, #0xe0]
	ldr r3, _0816F814 @ =0x00000604
	adds r3, r7, r3
	str r3, [sp, #0x180]
	movs r4, #0xc1
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x184]
	ldr r5, _0816F818 @ =0x0000021D
	adds r5, r7, r5
	str r5, [sp, #0x164]
	ldr r6, _0816F81C @ =0x0000060C
	adds r6, r7, r6
	str r6, [sp, #0x188]
	movs r1, #0xbe
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x170]
	ldr r2, _0816F820 @ =0x000005E4
	adds r2, r7, r2
	str r2, [sp, #0x160]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x174]
	ldr r4, _0816F824 @ =0x000005FC
	adds r4, r7, r4
	str r4, [sp, #0x178]
	movs r5, #0xc0
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x17c]
	ldr r6, _0816F828 @ =0x00000614
	adds r6, r7, r6
	str r6, [sp, #0x18c]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x194]
	ldr r2, _0816F82C @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0x138]
	movs r3, #0xbd
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x168]
	movs r4, #0xbc
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x15c]
	ldr r5, _0816F830 @ =0x000005EC
	adds r5, r7, r5
	str r5, [sp, #0x16c]
	movs r6, #0xbb
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x154]
	movs r1, #0xb5
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x11c]
	ldr r2, _0816F834 @ =0x00000624
	adds r2, r7, r2
	str r2, [sp, #0x1a8]
	ldr r3, _0816F838 @ =0x0000058C
	adds r3, r7, r3
	str r3, [sp, #0xec]
	movs r4, #0xc5
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x1b4]
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x134]
	ldr r6, _0816F83C @ =0x00000594
	adds r6, r7, r6
	str r6, [sp, #0xf4]
	movs r1, #0xb3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xf8]
	ldr r2, _0816F840 @ =0x0000059C
	adds r2, r7, r2
	str r2, [sp, #0xfc]
	ldr r3, _0816F844 @ =0x000005B4
	adds r3, r7, r3
	str r3, [sp, #0x12c]
	ldr r4, _0816F848 @ =0x00000543
	adds r4, r7, r4
	str r4, [sp, #0x94]
	movs r5, #0xcc
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0xb0]
	movs r6, #0xcd
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0xb8]
	ldr r1, _0816F84C @ =0x00000496
	adds r1, r7, r1
	str r1, [sp, #0x80]
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x48]
	ldr r3, _0816F850 @ =0x00000469
	adds r3, r7, r3
	str r3, [sp, #0x4c]
	ldr r4, _0816F854 @ =0x0000046A
	adds r4, r7, r4
	str r4, [sp, #0x50]
	ldr r5, _0816F858 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x9c]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xd8]
	movs r1, #0x92
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x7c]
	movs r2, #0xea
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x104]
	mov r3, sp
	adds r3, #0x24
	str r3, [sp, #0x38]
	mov r4, sp
	adds r4, #0x28
	str r4, [sp, #0x40]
	ldr r5, _0816F85C @ =0x0000046E
	adds r5, r7, r5
	str r5, [sp, #0x54]
	ldr r6, _0816F860 @ =0x00000572
	adds r6, r7, r6
	str r6, [sp, #0xd4]
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xe8]
	movs r2, #0xae
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xd0]
	ldr r3, _0816F864 @ =0x0000055C
	adds r3, r7, r3
	str r3, [sp, #0xa0]
	movs r4, #0xac
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xa8]
	ldr r5, _0816F868 @ =0x00000564
	adds r5, r7, r5
	str r5, [sp, #0xb4]
	ldr r6, _0816F86C @ =0x00000565
	adds r6, r7, r6
	str r6, [sp, #0xbc]
	ldr r1, _0816F870 @ =0x00000566
	adds r1, r7, r1
	str r1, [sp, #0xc0]
	ldr r2, _0816F874 @ =0x00000567
	adds r2, r7, r2
	str r2, [sp, #0xc4]
	movs r3, #0xad
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xc8]
	ldr r4, _0816F878 @ =0x0000056C
	adds r4, r7, r4
	str r4, [sp, #0xcc]
	cmp r0, #0
	bne _0816F7B0
	b _0816F8D4
_0816F7B0:
	movs r5, #0
	mov sl, r5
	movs r6, #0x8d
	lsls r6, r6, #2
	adds r6, r6, r7
	mov sb, r6
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r0, r0, r7
	mov r8, r0
	movs r1, #0x8b
	lsls r1, r1, #2
	adds r5, r7, r1
	movs r2, #0x89
	lsls r2, r2, #2
	adds r4, r7, r2
_0816F7D0:
	bl VM_GetPC
	cmp r0, #0
	beq _0816F87C
	bl Script_GetValue
	b _0816F87E
	.align 2, 0
_0816F7E0: .4byte 0x0000025D
_0816F7E4: .4byte 0x0000025A
_0816F7E8: .4byte 0x0000047A
_0816F7EC: .4byte 0x0000047C
_0816F7F0: .4byte 0x0000047E
_0816F7F4: .4byte 0x00000476
_0816F7F8: .4byte 0x000004A4
_0816F7FC: .4byte 0x000005A4
_0816F800: .4byte 0x000005C4
_0816F804: .4byte 0x000005CC
_0816F808: .4byte 0x000005D4
_0816F80C: .4byte 0x000005DC
_0816F810: .4byte 0x00000584
_0816F814: .4byte 0x00000604
_0816F818: .4byte 0x0000021D
_0816F81C: .4byte 0x0000060C
_0816F820: .4byte 0x000005E4
_0816F824: .4byte 0x000005FC
_0816F828: .4byte 0x00000614
_0816F82C: .4byte 0x000005BC
_0816F830: .4byte 0x000005EC
_0816F834: .4byte 0x00000624
_0816F838: .4byte 0x0000058C
_0816F83C: .4byte 0x00000594
_0816F840: .4byte 0x0000059C
_0816F844: .4byte 0x000005B4
_0816F848: .4byte 0x00000543
_0816F84C: .4byte 0x00000496
_0816F850: .4byte 0x00000469
_0816F854: .4byte 0x0000046A
_0816F858: .4byte 0x00000553
_0816F85C: .4byte 0x0000046E
_0816F860: .4byte 0x00000572
_0816F864: .4byte 0x0000055C
_0816F868: .4byte 0x00000564
_0816F86C: .4byte 0x00000565
_0816F870: .4byte 0x00000566
_0816F874: .4byte 0x00000567
_0816F878: .4byte 0x0000056C
_0816F87C:
	movs r0, #0x18
_0816F87E:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _0816F890
	bl Script_GetValue
	b _0816F892
_0816F890:
	movs r0, #0x18
_0816F892:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _0816F8A4
	bl Script_GetValue
	b _0816F8A6
_0816F8A4:
	movs r0, #0
_0816F8A6:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _0816F8B8
	bl Script_GetValue
	b _0816F8BA
_0816F8B8:
	movs r0, #0
_0816F8BA:
	strh r0, [r6]
	movs r3, #2
	add sb, r3
	movs r6, #4
	add r8, r6
	adds r5, #2
	adds r4, #2
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #3
	bgt _0816F8D4
	b _0816F7D0
_0816F8D4:
	movs r0, #0x6c
	bl prepare_08231510
	cmp r0, #0
	beq _0816F920
	bl VM_GetPC
	cmp r0, #0
	beq _0816F8EE
	bl Script_GetValue
	adds r4, r0, #0
	b _0816F8F2
_0816F8EE:
	movs r4, #0x96
	lsls r4, r4, #1
_0816F8F2:
	bl VM_GetPC
	cmp r0, #0
	beq _0816F902
	bl Script_GetValue
	adds r6, r0, #0
	b _0816F906
_0816F902:
	movs r6, #0x96
	lsls r6, r6, #1
_0816F906:
	bl VM_GetPC
	cmp r0, #0
	beq _0816F914
	bl Script_GetValue
	b _0816F91A
_0816F914:
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r2, #0
_0816F91A:
	ldr r3, [sp, #0x190]
	strh r0, [r3]
	b _0816F928
_0816F920:
	movs r4, #0
	movs r6, #0
	ldr r5, [sp, #0x190]
	strh r6, [r5]
_0816F928:
	movs r0, #0x62
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _0816F940
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x98]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_0816F940:
	movs r0, #0x46
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r3, [sp, #0xac]
	strh r0, [r3]
	movs r0, #0x52
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r5, [sp, #0xa4]
	strh r0, [r5]
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _0816FA10
	bl VM_GetPC
	cmp r0, #0
	beq _0816F970
	bl Script_GetValue
	b _0816F972
_0816F970:
	movs r0, #0
_0816F972:
	ldr r1, [sp, #0x1a4]
	strh r0, [r1]
	ldrh r0, [r1]
	cmp r0, #0
	blt _0816F980
	asrs r1, r0, #1
	b _0816F986
_0816F980:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_0816F986:
	ldr r2, _0816F99C @ =0x00000546
	adds r0, r7, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0816F9A0
	bl Script_GetValue
	b _0816F9A2
	.align 2, 0
_0816F99C: .4byte 0x00000546
_0816F9A0:
	movs r0, #0
_0816F9A2:
	movs r3, #0xc3
	lsls r3, r3, #1
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _0816F9B8
	bl Script_GetValue
	b _0816F9BA
_0816F9B8:
	movs r0, #0
_0816F9BA:
	ldr r5, _0816F9D0 @ =0x00000187
	adds r1, r7, r5
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _0816F9D4
	bl Script_GetValue
	adds r1, r0, #0
	b _0816F9D6
	.align 2, 0
_0816F9D0: .4byte 0x00000187
_0816F9D4:
	movs r1, #0
_0816F9D6:
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r7, r2
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0816F9EC
	bl Script_GetValue
	b _0816F9EE
_0816F9EC:
	movs r0, #0
_0816F9EE:
	movs r3, #0xc5
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _0816FA06
	bl Script_GetValue
	adds r1, r0, #0
	b _0816FA08
_0816FA06:
	movs r1, #0
_0816FA08:
	movs r5, #0xc6
	lsls r5, r5, #1
	adds r0, r7, r5
	strh r1, [r0]
_0816FA10:
	ldr r0, [sp, #0x1a4]
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080e48e8
	ldr r1, [sp, #0x10c]
	lsrs r2, r1, #0x10
	ldr r4, [sp, #0x118]
	lsrs r3, r4, #0x10
	ldr r5, [sp, #0x124]
	lsrs r0, r5, #0x10
	str r0, [sp]
	ldr r6, [sp, #0x114]
	lsrs r0, r6, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080e3a90
	movs r0, #0x58
	bl prepare_08231510
	cmp r0, #0
	beq _0816FA72
	movs r0, #0xe8
	lsls r0, r0, #1
	adds r6, r7, r0
	bl VM_GetPC
	cmp r0, #0
	beq _0816FA58
	bl Script_GetValue
	b _0816FA5A
_0816FA58:
	movs r0, #0
_0816FA5A:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _0816FA6A
	bl Script_GetValue
	b _0816FA6C
_0816FA6A:
	movs r0, #0
_0816FA6C:
	ldr r2, _0816FAD4 @ =0x00000189
	adds r1, r7, r2
	strb r0, [r1]
_0816FA72:
	movs r0, #0x4b
	movs r1, #2
	bl Script_GetKeywordValue
	ldr r3, [sp, #0x1ac]
	strh r0, [r3]
	movs r0, #0x48
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _0816FA96
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r4, [sp, #0x98]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_0816FA96:
	movs r0, #0x4c
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _0816FAAE
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r5, [sp, #0x98]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_0816FAAE:
	ldr r6, [sp, #0x100]
	lsrs r1, r6, #0x10
	movs r0, #4
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0x30]
	add r2, sp, #0x1c
	movs r3, #0
	bl FUN_0823b400
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x5c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0816FAD8
	movs r0, #1
	b _0816FADA
	.align 2, 0
_0816FAD4: .4byte 0x00000189
_0816FAD8:
	movs r0, #0
_0816FADA:
	cmp r0, #0
	beq _0816FAEA
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _0816FB14 @ =FUN_080f48ac
	ldr r1, [sp, #0x30]
	bl FUN_0807f558
_0816FAEA:
	ldr r3, [sp, #0x1b0]
	ldrb r0, [r3]
	movs r1, #0
	cmp r0, #0
	bne _0816FAF6
	ldr r1, [r7, #0x44]
_0816FAF6:
	ldr r0, [sp, #0x30]
	bl FUN_0823b46c
	ldr r4, [sp, #0x120]
	ldrb r0, [r4]
	cmp r0, #0x15
	bne _0816FB18
	ldr r0, [sp, #0x30]
	ldr r1, [sp, #0x44]
	movs r2, #0x3c
	movs r3, #0x3c
	bl FUN_0823b43c
	b _0816FB24
	.align 2, 0
_0816FB14: .4byte FUN_080f48ac
_0816FB18:
	ldr r0, [sp, #0x30]
	ldr r1, [sp, #0x44]
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_0823b43c
_0816FB24:
	ldr r5, [sp, #0x120]
	ldrb r1, [r5]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0816FB72
	adds r0, r1, #0
	cmp r0, #0xb
	beq _0816FB72
	cmp r0, #0x16
	beq _0816FB72
	cmp r0, #0x14
	beq _0816FB72
	cmp r0, #9
	beq _0816FB72
	cmp r0, #0x19
	beq _0816FB72
	cmp r0, #0x1a
	beq _0816FB72
	cmp r0, #0xd
	beq _0816FB72
	cmp r0, #0x1b
	beq _0816FB72
	cmp r0, #0x1f
	beq _0816FB72
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r6, [sp, #0x198]
	ldrb r2, [r6]
	ldr r0, [sp, #0x19c]
	ldrb r3, [r0]
	ldr r4, [sp, #0x1a0]
	ldrb r0, [r4]
	str r0, [sp]
	ldr r0, [sp, #0x30]
	bl FUN_0823b490
_0816FB72:
	movs r1, #8
	ldr r5, [sp, #0x5c]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0816FB82
	movs r0, #1
	b _0816FB84
_0816FB82:
	movs r0, #0
_0816FB84:
	cmp r0, #0
	beq _0816FB92
	ldr r6, [sp, #0x130]
	ldr r0, [r6]
	ldr r1, [sp, #0x128]
	str r0, [r1]
	b _0816FBA4
_0816FB92:
	ldr r2, [sp, #0x130]
	ldr r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r3, [sp, #0x128]
	str r0, [r3]
_0816FBA4:
	ldrh r0, [r7]
	ldr r4, [sp, #0x58]
	strh r0, [r4]
	ldr r5, [sp, #0x3c]
	ldr r6, [sp, #0x64]
	str r5, [r6]
	ldr r0, [sp, #0x34]
	cmp r0, #0
	beq _0816FBCE
	adds r0, r7, #0
	adds r0, #0xa4
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	lsrs r0, r0, #0xc
	movs r1, #7
	ands r0, r1
	adds r0, #5
	ands r0, r1
	lsls r0, r0, #5
	ldr r1, [sp, #0x30]
	strb r0, [r1, #5]
_0816FBCE:
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0816FCB0
	bl VM_GetPC
	cmp r0, #0
	beq _0816FBE6
	bl Script_GetValue
	b _0816FBE8
_0816FBE6:
	movs r0, #0
_0816FBE8:
	strh r0, [r7, #8]
	bl VM_GetPC
	cmp r0, #0
	beq _0816FBF8
	bl Script_GetValue
	b _0816FBFA
_0816FBF8:
	movs r0, #0
_0816FBFA:
	strh r0, [r7, #0xa]
	bl VM_GetPC
	cmp r0, #0
	beq _0816FC0A
	bl Script_GetValue
	b _0816FC0C
_0816FC0A:
	movs r0, #0
_0816FC0C:
	strh r0, [r7, #0xc]
	ldrh r0, [r7, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldr r3, [sp, #0x3c]
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0816FC34
	cmp r1, #0
	blt _0816FC34
	ldr r0, _0816FC38 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0816FC34
	ldr r0, _0816FC3C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0816FC40
_0816FC34:
	movs r1, #0
	b _0816FC4E
	.align 2, 0
_0816FC38: .4byte 0x030046A8
_0816FC3C: .4byte 0x030046AC
_0816FC40:
	ldr r0, _0816FC68 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_0816FC4E:
	ldr r4, _0816FC6C @ =0x00000256
	adds r0, r7, r4
	strh r1, [r0]
	ldrh r4, [r0]
	ldr r5, [sp, #0x3c]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0816FC70
	adds r0, #4
	b _0816FC7C
	.align 2, 0
_0816FC68: .4byte 0x030046A4
_0816FC6C: .4byte 0x00000256
_0816FC70:
	ldr r0, _0816FC90 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0816FC7C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0816FC94
	cmp r2, #2
	beq _0816FC98
	b _0816FC9C
	.align 2, 0
_0816FC90: .4byte 0x030046A4
_0816FC94:
	ldrb r0, [r5, #4]
	b _0816FC9A
_0816FC98:
	ldrb r0, [r5]
_0816FC9A:
	subs r1, r1, r0
_0816FC9C:
	ldr r5, _0816FCAC @ =0x00000472
	adds r0, r7, r5
	strh r1, [r0]
	ldr r6, [sp, #0x2c]
	movs r2, #0xfd
	lsls r2, r2, #3
	adds r0, r6, r2
	b _0816FCBE
	.align 2, 0
_0816FCAC: .4byte 0x00000472
_0816FCB0:
	ldr r3, _0816FCF0 @ =0x00000472
	adds r0, r7, r3
	ldrh r1, [r0]
	ldr r4, [sp, #0x2c]
	movs r5, #0xfd
	lsls r5, r5, #3
	adds r0, r4, r5
_0816FCBE:
	strh r1, [r0]
	ldr r6, [sp, #0x2c]
	movs r0, #0x89
	lsls r0, r0, #4
	adds r2, r6, r0
	ldr r0, _0816FCF4 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0x50
	bl prepare_08231510
	cmp r0, #0
	beq _0816FD44
	bl VM_GetPC
	cmp r0, #0
	beq _0816FCF8
	bl Script_GetValue
	adds r1, r0, #0
	b _0816FCFA
	.align 2, 0
_0816FCF0: .4byte 0x00000472
_0816FCF4: .4byte 0x03002BE0
_0816FCF8:
	movs r1, #0
_0816FCFA:
	ldr r2, [sp, #0x2c]
	ldr r3, _0816FD14 @ =0x000007E4
	adds r0, r2, r3
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0816FD18
	bl Script_GetValue
	adds r1, r0, #0
	b _0816FD1A
	.align 2, 0
_0816FD14: .4byte 0x000007E4
_0816FD18:
	movs r1, #0
_0816FD1A:
	ldr r4, [sp, #0x2c]
	ldr r5, _0816FD34 @ =0x000007E5
	adds r0, r4, r5
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0816FD38
	bl Script_GetValue
	adds r1, r0, #0
	b _0816FD3A
	.align 2, 0
_0816FD34: .4byte 0x000007E5
_0816FD38:
	movs r1, #0
_0816FD3A:
	ldr r6, [sp, #0x2c]
	movs r2, #0x84
	lsls r2, r2, #4
	adds r0, r6, r2
	strb r1, [r0]
_0816FD44:
	movs r0, #0x67
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _0816FD60
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r3, [sp, #0x2c]
	ldr r4, _0816FD7C @ =0x000007DC
	adds r1, r3, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0816FD60:
	movs r0, #0x64
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _0816FDBC
	bl VM_GetPC
	cmp r0, #0
	beq _0816FD80
	bl Script_GetValue
	adds r1, r0, #0
	b _0816FD82
	.align 2, 0
_0816FD7C: .4byte 0x000007DC
_0816FD80:
	movs r1, #0
_0816FD82:
	ldr r5, [sp, #0x2c]
	ldr r6, _0816FD9C @ =0x00000844
	adds r0, r5, r6
	strh r1, [r0]
	ldr r0, _0816FDA0 @ =0x00000848
	adds r4, r5, r0
	bl VM_GetPC
	cmp r0, #0
	beq _0816FDA4
	bl Script_GetValue
	b _0816FDA6
	.align 2, 0
_0816FD9C: .4byte 0x00000844
_0816FDA0: .4byte 0x00000848
_0816FDA4:
	movs r0, #0
_0816FDA6:
	str r0, [r4]
	ldr r1, [sp, #0x2c]
	ldr r2, _0816FDB8 @ =0x00000848
	adds r0, r1, r2
	ldr r1, [r0]
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	b _0816FDC8
	.align 2, 0
_0816FDB8: .4byte 0x00000848
_0816FDBC:
	ldr r4, [sp, #0x2c]
	ldr r5, _0816FE24 @ =0x00000844
	adds r0, r4, r5
	strh r1, [r0]
	ldr r6, _0816FE28 @ =0x00000848
	adds r0, r4, r6
_0816FDC8:
	str r1, [r0]
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _0816FDE6
	movs r2, #0x80
	lsls r2, r2, #2
	ldr r0, [sp, #0x2c]
	ldr r3, _0816FE2C @ =0x000007DC
	adds r1, r0, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0816FDE6:
	ldr r4, _0816FE30 @ =0x0000017D
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r6, [sp, #0x78]
	strh r0, [r6]
	ldr r0, [sp, #0x6c]
	strh r4, [r0]
	ldr r1, [sp, #0x70]
	strh r5, [r1]
	ldrh r0, [r6]
	adds r0, r0, r4
	ldr r2, [sp, #0x74]
	strh r0, [r2]
	ldr r3, [sp, #0x6c]
	ldrh r1, [r3]
	ldrh r0, [r6]
	adds r1, r1, r0
	ldr r4, [sp, #0x1b0]
	ldrb r0, [r4]
	cmp r0, #0
	bne _0816FE34
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _0816FE40
	.align 2, 0
_0816FE24: .4byte 0x00000844
_0816FE28: .4byte 0x00000848
_0816FE2C: .4byte 0x000007DC
_0816FE30: .4byte 0x0000017D
_0816FE34:
	ldr r2, [r7, #0x44]
	ldr r0, _0816FE78 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_0816FE40:
	ldr r5, [sp, #0x1b0]
	ldrb r0, [r5]
	cmp r0, #1
	bne _0816FE90
	ldr r6, [sp, #0x120]
	ldrb r0, [r6]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _0816FE7C
	movs r0, #5
	bl FUN_080ecf60
	adds r4, r0, #1
	movs r0, #6
	bl FUN_080ecf60
	adds r4, r4, r0
	movs r0, #7
	bl FUN_080ecf60
	adds r4, r4, r0
	movs r0, #8
	bl FUN_080ecf60
	adds r4, r4, r0
	b _0816FE86
	.align 2, 0
_0816FE78: .4byte 0x03003584
_0816FE7C:
	ldr r1, [sp, #0x120]
	ldrb r0, [r1]
	bl FUN_080ecf60
	adds r4, r0, #1
_0816FE86:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_0816FE90:
	ldr r2, [sp, #0x6c]
	ldrh r0, [r2]
	ldr r3, [sp, #0x60]
	strh r0, [r3]
	ldrh r0, [r2]
	adds r0, #2
	ldr r4, [sp, #0x68]
	strh r0, [r4]
	ldr r5, _0816FED4 @ =0x0000047E
	adds r1, r7, r5
	movs r0, #0xc0
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x55
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	bne _0816FF60
	movs r6, #0xe6
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r3, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, _0816FED8 @ =0x000007DC
	adds r0, r3, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816FEDC
	movs r0, #1
	b _0816FEDE
	.align 2, 0
_0816FED4: .4byte 0x0000047E
_0816FED8: .4byte 0x000007DC
_0816FEDC:
	movs r0, #0
_0816FEDE:
	cmp r0, #0
	beq _0816FF04
	movs r1, #0x20
	ldr r0, _0816FEF8 @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _0816FEFC @ =0x00000934
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816FF00
	movs r0, #1
	b _0816FF10
	.align 2, 0
_0816FEF8: .4byte 0x030046A0
_0816FEFC: .4byte 0x00000934
_0816FF00:
	movs r0, #0
	b _0816FF10
_0816FF04:
	ldr r0, _0816FF30 @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _0816FF34 @ =0x00000942
	adds r0, r0, r5
	movs r6, #0
	ldrsh r0, [r0, r6]
_0816FF10:
	cmp r0, #0
	ble _0816FF40
	movs r2, #0x40
	ldr r0, _0816FF38 @ =0x000007DC
	adds r1, r3, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r2, [r7, #0x44]
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r2, _0816FF3C @ =0x00000836
	adds r1, r3, r2
	b _0816FF5C
	.align 2, 0
_0816FF30: .4byte 0x030046A0
_0816FF34: .4byte 0x00000942
_0816FF38: .4byte 0x000007DC
_0816FF3C: .4byte 0x00000836
_0816FF40:
	movs r2, #0x20
	ldr r4, _081700F8 @ =0x000007DC
	adds r1, r3, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r2, [r7, #0x44]
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r5, _081700FC @ =0x00000836
	adds r1, r3, r5
_0816FF5C:
	movs r0, #0
	strh r0, [r1]
_0816FF60:
	adds r0, r7, #0
	bl FUN_0816cedc
	ldr r6, [sp, #0x2c]
	ldr r0, _08170100 @ =0x0000084C
	adds r4, r6, r0
	movs r1, #0x87
	lsls r1, r1, #4
	adds r5, r6, r1
	ldr r2, _08170104 @ =FUN_0816f05c
	str r2, [sp, #0x1c0]
	ldr r3, _08170108 @ =FUN_0816cfa0
	mov r8, r3
	ldr r6, _0817010C @ =FUN_0816b5ec
	mov sb, r6
	ldr r0, _08170110 @ =FUN_0816b3cc
	mov sl, r0
	ldr r1, _08170114 @ =FUN_0816b4cc
	mov ip, r1
	movs r2, #0
	ldr r3, _08170118 @ =FUN_080f62b0
	ldr r6, _0817011C @ =FUN_080f62ac
	str r6, [sp, #0x1b8]
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x90]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	ldr r0, [sp, #0x84]
	str r4, [r0]
	ldr r1, [sp, #0x88]
	str r5, [r1]
	ldr r4, [sp, #0x1c0]
	ldr r5, [sp, #0xdc]
	str r4, [r5]
	mov r6, r8
	ldr r0, [sp, #0xe4]
	str r6, [r0]
	mov r1, sb
	ldr r4, [sp, #0xf0]
	str r1, [r4]
	mov r5, sl
	ldr r6, [sp, #0x108]
	str r5, [r6]
	mov r0, ip
	ldr r1, [sp, #0x110]
	str r0, [r1]
	ldr r4, [sp, #0x13c]
	str r2, [r4]
	ldr r5, [sp, #0x140]
	str r3, [r5]
	ldr r6, _08170120 @ =FUN_0816ba00
	ldr r0, [sp, #0x148]
	str r6, [r0]
	ldr r1, _08170124 @ =FUN_0816bc3c
	ldr r3, [sp, #0x14c]
	str r1, [r3]
	ldr r0, _08170128 @ =FUN_080f44f4
	ldr r4, [sp, #0x150]
	str r0, [r4]
	ldr r0, _0817012C @ =FUN_080f410c
	ldr r5, [sp, #0x158]
	str r0, [r5]
	ldr r6, [sp, #0x144]
	str r2, [r6]
	ldr r0, [sp, #0xe0]
	str r2, [r0]
	ldr r1, [sp, #0x1b8]
	ldr r3, [sp, #0x180]
	str r1, [r3]
	ldr r0, _08170130 @ =FUN_080f0430
	ldr r4, [sp, #0x184]
	str r0, [r4]
	movs r6, #1
	ldr r5, [sp, #0x164]
	strb r6, [r5]
	ldr r0, _08170134 @ =0x085AD470
	ldr r1, [sp, #0x188]
	str r0, [r1]
	ldr r0, _08170138 @ =FUN_080e73c8
	ldr r3, [sp, #0x170]
	str r0, [r3]
	ldr r4, [sp, #0x160]
	str r2, [r4]
	ldr r5, [sp, #0x174]
	str r2, [r5]
	ldr r6, [sp, #0x178]
	str r2, [r6]
	ldr r0, [sp, #0x17c]
	str r2, [r0]
	ldr r1, [sp, #0x18c]
	str r2, [r1]
	ldr r0, _0817013C @ =FUN_080f0320
	ldr r3, [sp, #0x194]
	str r0, [r3]
	ldr r0, _08170140 @ =FUN_080eff14
	ldr r4, [sp, #0x138]
	str r0, [r4]
	ldr r0, _08170144 @ =FUN_080e72b0
	ldr r5, [sp, #0x168]
	str r0, [r5]
	ldr r6, [sp, #0x15c]
	str r2, [r6]
	ldr r0, _08170148 @ =FUN_080f47c8
	ldr r1, [sp, #0x16c]
	str r0, [r1]
	ldr r0, _0817014C @ =FUN_080f54e4
	ldr r3, [sp, #0x154]
	str r0, [r3]
	ldr r4, [sp, #0x11c]
	str r2, [r4]
	ldr r0, _08170150 @ =FUN_080f6e64
	ldr r5, [sp, #0x1a8]
	str r0, [r5]
	ldr r0, _08170154 @ =FUN_080f64f0
	ldr r6, [sp, #0xec]
	str r0, [r6]
	ldr r0, _08170158 @ =FUN_080f84d4
	ldr r1, [sp, #0x1b4]
	str r0, [r1]
	ldr r0, _0817015C @ =FUN_080f624c
	ldr r3, [sp, #0x134]
	str r0, [r3]
	ldr r0, _08170160 @ =FUN_080f56ec
	ldr r4, [sp, #0xf4]
	str r0, [r4]
	ldr r0, _08170164 @ =FUN_080f5b34
	ldr r5, [sp, #0xf8]
	str r0, [r5]
	ldr r0, _08170168 @ =FUN_080f5fac
	ldr r6, [sp, #0xfc]
	str r0, [r6]
	ldr r0, [sp, #0x12c]
	str r2, [r0]
	movs r0, #0x28
	ldr r1, [sp, #0x94]
	strb r0, [r1]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _0817016C @ =ghost_0816d200
	str r0, [r1]
	ldr r4, _08170170 @ =0x000005FC
	adds r0, r7, r4
	str r2, [r0]
	ldr r5, _08170174 @ =0x000005AC
	adds r1, r7, r5
	ldr r0, _08170178 @ =FUN_0816d868
	str r0, [r1]
	movs r6, #0xb6
	lsls r6, r6, #3
	adds r0, r7, r6
	str r2, [r0]
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _0817017C @ =FUN_0816d864
	str r0, [r1]
	ldr r2, _08170180 @ =0x0000060C
	adds r1, r7, r2
	ldr r0, _08170184 @ =0x085ADAC4
	str r0, [r1]
	movs r0, #0x20
	ldr r3, [sp, #0x5c]
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r4, [sp, #0x90]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r1, _08170188 @ =0x02100400
	ldr r5, [sp, #0x98]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	adds r0, r7, #0
	bl Enemy_Init_080e5dd4
	movs r0, #0x49
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r6, [sp, #0xb0]
	strh r0, [r6]
	movs r0, #0x47
	bl prepare_08231510
	cmp r0, #0
	beq _08170196
	movs r0, #0xce
	lsls r0, r0, #1
	adds r5, r7, r0
	movs r4, #4
_081700EA:
	bl VM_GetPC
	cmp r0, #0
	beq _0817018C
	bl Script_GetValue
	b _0817018E
	.align 2, 0
_081700F8: .4byte 0x000007DC
_081700FC: .4byte 0x00000836
_08170100: .4byte 0x0000084C
_08170104: .4byte FUN_0816f05c
_08170108: .4byte FUN_0816cfa0
_0817010C: .4byte FUN_0816b5ec
_08170110: .4byte FUN_0816b3cc
_08170114: .4byte FUN_0816b4cc
_08170118: .4byte FUN_080f62b0
_0817011C: .4byte FUN_080f62ac
_08170120: .4byte FUN_0816ba00
_08170124: .4byte FUN_0816bc3c
_08170128: .4byte FUN_080f44f4
_0817012C: .4byte FUN_080f410c
_08170130: .4byte FUN_080f0430
_08170134: .4byte 0x085AD470
_08170138: .4byte FUN_080e73c8
_0817013C: .4byte FUN_080f0320
_08170140: .4byte FUN_080eff14
_08170144: .4byte FUN_080e72b0
_08170148: .4byte FUN_080f47c8
_0817014C: .4byte FUN_080f54e4
_08170150: .4byte FUN_080f6e64
_08170154: .4byte FUN_080f64f0
_08170158: .4byte FUN_080f84d4
_0817015C: .4byte FUN_080f624c
_08170160: .4byte FUN_080f56ec
_08170164: .4byte FUN_080f5b34
_08170168: .4byte FUN_080f5fac
_0817016C: .4byte ghost_0816d200
_08170170: .4byte 0x000005FC
_08170174: .4byte 0x000005AC
_08170178: .4byte FUN_0816d868
_0817017C: .4byte FUN_0816d864
_08170180: .4byte 0x0000060C
_08170184: .4byte 0x085ADAC4
_08170188: .4byte 0x02100400
_0817018C:
	movs r0, #0
_0817018E:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _081700EA
_08170196:
	movs r0, #0x44
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r1, [sp, #0xb8]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl Script_GetKeywordValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x80]
	strh r0, [r3]
	cmp r2, #0
	beq _081701CE
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x90]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _081701CE
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_081701CE:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x5c]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081701E0
	movs r0, #1
	b _081701E2
_081701E0:
	movs r0, #0
_081701E2:
	cmp r0, #0
	beq _081701F4
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x98]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_081701F4:
	cmp r2, #1
	beq _08170234
	movs r1, #0
	ldr r0, [sp, #0x48]
	strb r1, [r0]
	ldr r2, [sp, #0x4c]
	strb r1, [r2]
	ldr r3, [sp, #0x50]
	strb r1, [r3]
	ldr r4, _08170244 @ =0x00000484
	adds r0, r7, r4
	str r1, [r0]
	ldr r5, _08170248 @ =0x0000046C
	adds r0, r7, r5
	movs r2, #1
	strb r2, [r0]
	ldr r6, [sp, #0x110]
	ldr r3, [r6]
	subs r4, #0x17
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, [sp, #0x9c]
	strb r1, [r6]
	ldr r0, [sp, #0xd8]
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
_08170234:
	movs r1, #2
	ldr r3, [sp, #0x5c]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0817024C
	movs r0, #1
	b _0817024E
	.align 2, 0
_08170244: .4byte 0x00000484
_08170248: .4byte 0x0000046C
_0817024C:
	movs r0, #0
_0817024E:
	cmp r0, #0
	beq _08170268
	ldr r0, _08170264 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x92
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r5, [sp, #0x7c]
	strh r0, [r5]
	b _08170272
	.align 2, 0
_08170264: .4byte 0x030046A0
_08170268:
	ldr r0, [sp, #0x3c]
	bl FUN_08241574
	ldr r6, [sp, #0x7c]
	strh r0, [r6]
_08170272:
	movs r1, #0x40
	ldr r2, [sp, #0x5c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08170282
	movs r0, #1
	b _08170284
_08170282:
	movs r0, #0
_08170284:
	cmp r0, #0
	beq _08170294
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _081702B8 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_08170294:
	movs r0, #0x53
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	bne _081702C6
	ldr r0, _081702BC @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x7c]
	ldrh r4, [r4]
	cmp r0, r4
	bne _081702C0
	movs r0, #1
	b _081702C2
	.align 2, 0
_081702B8: .4byte 0xFFFFFEFF
_081702BC: .4byte 0x030046A0
_081702C0:
	movs r0, #0
_081702C2:
	cmp r0, #0
	bne _081702CE
_081702C6:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080f07d0
_081702CE:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r5, [sp, #0x1b0]
	ldrb r0, [r5]
	cmp r0, #0
	bne _081703B6
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x48]
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
	beq _08170310
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08170318
_08170310:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08170318:
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
	beq _0817033C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08170344
_0817033C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08170344:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _0817037C @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081703C0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08170380
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08170374
	ldrb r0, [r4, #5]
_08170374:
	subs r0, #1
	strh r0, [r4, #8]
	b _08170390
	.align 2, 0
_0817037C: .4byte 0x0000FFFF
_08170380:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08170390
	strh r1, [r4, #8]
_08170390:
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
	bne _081703C0
	movs r0, #1
	strb r0, [r4, #7]
	b _081703C0
_081703B6:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl FUN_082372cc
_081703C0:
	movs r0, #0
	ldr r3, [sp, #0x104]
	str r0, [r3]
	ldr r0, _081703D8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081703DC
	movs r0, #1
	b _081703DE
	.align 2, 0
_081703D8: .4byte 0x030047A4
_081703DC:
	movs r0, #0
_081703DE:
	cmp r0, #0
	bne _0817041E
	ldr r4, [sp, #0x120]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08170406
	adds r0, r1, #0
	cmp r0, #7
	beq _08170406
	cmp r0, #6
	beq _08170406
	cmp r0, #0x15
	beq _08170406
	cmp r0, #0x14
	beq _08170406
	cmp r0, #0x17
	bne _0817041E
_08170406:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl FUN_080223f4
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x5c]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_0817041E:
	adds r0, r7, #0
	bl Enemy_Init_080f3680
	adds r0, r7, #0
	bl FUN_0816cbdc
	adds r0, r7, #0
	bl FUN_0816ec4c
	adds r0, r7, #0
	bl FUN_0816ee88
	ldr r6, [sp, #0x2c]
	ldr r1, _08170488 @ =0x00000844
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08170448
	adds r0, r7, #0
	bl FUN_0816f048
_08170448:
	adds r0, r7, #0
	movs r1, #1
	bl FUN_080ef86c
	ldrb r0, [r7, #5]
	ldr r1, [sp, #0x38]
	ldr r2, [sp, #0x40]
	bl FUN_0816d438
	ldr r2, _0817048C @ =0x000004C4
	adds r0, r7, r2
	ldrb r2, [r0]
	ldr r3, [sp, #0x24]
	ldr r4, [sp, #0x28]
	ldr r5, [sp, #0x1b0]
	ldrb r0, [r5]
	cmp r0, #0
	bne _08170490
	ldr r6, [sp, #0x8c]
	strb r2, [r6]
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	b _08170500
	.align 2, 0
_08170488: .4byte 0x00000844
_0817048C: .4byte 0x000004C4
_08170490:
	ldr r0, [r7, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r2, r2, r3
	ldr r1, [sp, #0x8c]
	ldrb r0, [r1]
	cmp r0, r2
	bne _081704C4
	ldr r3, [sp, #0x54]
	ldrb r0, [r3]
	cmp r0, #0
	bne _081704C4
	cmp r4, #1
	bne _081704B6
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08170506
_081704B6:
	cmp r4, #0
	bne _081704C4
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08170506
_081704C4:
	ldr r6, [sp, #0x8c]
	strb r2, [r6]
	movs r6, #4
	adds r0, r4, #0
	ands r0, r6
	movs r3, #4
	cmp r0, #0
	beq _081704D6
	movs r3, #6
_081704D6:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _081704F6
	ldr r0, [r5, #8]
	orrs r0, r6
	b _081704FE
_081704F6:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081704FE:
	str r0, [r5, #8]
_08170500:
	movs r0, #0
	ldr r1, [sp, #0x54]
	strb r0, [r1]
_08170506:
	movs r2, #0xde
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #2
	strh r0, [r1]
	adds r0, r7, #0
	bl FUN_0816d88c
	ldr r3, [sp, #0x5c]
	ldrh r0, [r3]
	ldr r4, [sp, #0xd4]
	strh r0, [r4]
	ldr r5, [sp, #0xe8]
	ldrh r0, [r5]
	ldr r6, [sp, #0xd0]
	strh r0, [r6]
	ldr r1, [sp, #0x90]
	ldr r0, [r1]
	ldr r2, [sp, #0xa0]
	str r0, [r2]
	ldr r3, [sp, #0x98]
	ldr r0, [r3]
	ldr r4, [sp, #0xa8]
	str r0, [r4]
	ldrb r0, [r7, #5]
	ldr r5, [sp, #0xb4]
	strb r0, [r5]
	ldr r6, [sp, #0x48]
	ldrb r0, [r6]
	ldr r1, [sp, #0xbc]
	strb r0, [r1]
	ldr r2, [sp, #0x4c]
	ldrb r0, [r2]
	ldr r3, [sp, #0xc0]
	strb r0, [r3]
	ldr r4, [sp, #0x50]
	ldrb r0, [r4]
	ldr r5, [sp, #0xc4]
	strb r0, [r5]
	ldr r6, [sp, #0xd8]
	ldr r0, [r6]
	ldr r1, [sp, #0xc8]
	str r0, [r1]
	ldr r2, [sp, #0x9c]
	ldrb r0, [r2]
	ldr r3, [sp, #0xcc]
	strb r0, [r3]
	ldr r4, _0817059C @ =0x00000574
	adds r1, r7, r4
	ldr r5, [sp, #0x2c]
	ldr r6, _081705A0 @ =0x000007DC
	adds r0, r5, r6
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _081705A4 @ =0x0000057C
	adds r1, r7, r0
	ldr r0, _081705A8 @ =FUN_080f09e0
	str r0, [r1]
	ldr r2, _081705AC @ =0x0000061C
	adds r1, r7, r2
	ldr r0, _081705B0 @ =FUN_0816f098
	str r0, [r1]
	movs r3, #0xc4
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _081705B4 @ =EnemyGhost_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Init_080ec640
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081705B8
	movs r0, #0
	b _081705BC
	.align 2, 0
_0817059C: .4byte 0x00000574
_081705A0: .4byte 0x000007DC
_081705A4: .4byte 0x0000057C
_081705A8: .4byte FUN_080f09e0
_081705AC: .4byte 0x0000061C
_081705B0: .4byte FUN_0816f098
_081705B4: .4byte EnemyGhost_Destroy
_081705B8:
	movs r0, #1
	rsbs r0, r0, #0
_081705BC:
	add sp, #0x1c4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start EnemyGhost_Create
EnemyGhost_Create: @ 0x081705CC
	push {r4, r5, lr}
	ldr r5, _08170600 @ =0x00000898
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _081705F8
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl EnemyGhost_Init
	cmp r0, #0
	bge _081705F8
	adds r0, r4, #0
	bl EnemyGhost_Destroy
	adds r0, r4, #0
	bl Free
_081705F8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08170600: .4byte 0x00000898
