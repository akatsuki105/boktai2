	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start umul3232H32
umul3232H32: @ 0x08243a98
	add r2, pc, #0x0
	bx r2

	arm_func_start sub_08243a9c
sub_08243a9c: @ 0x08243a9c
	umull r2, r3, r0, r1
	add r0, r3, #0
	bx lr

	thumb_func_start SoundMain
SoundMain: @ 0x08243AA8
	ldr r0, _08243B14 @ =0x03007FF0
	ldr r0, [r0]
	ldr r2, _08243B18 @ =0x68736D53
	ldr r3, [r0]
	cmp r2, r3
	beq _08243AB6
	bx lr
_08243AB6:
	adds r3, #1
	str r3, [r0]
	push {r4, r5, r6, r7, lr}
	mov r1, r8
	mov r2, sb
	mov r3, sl
	mov r4, fp
	push {r0, r1, r2, r3, r4}
	sub sp, #0x18
	ldrb r1, [r0, #0xc]
	cmp r1, #0
	beq _08243ADA
	ldr r2, _08243B20 @ =0x04000006
	ldrb r2, [r2]
	cmp r2, #0xa0
	bhs _08243AD8
	adds r2, #0xe4
_08243AD8:
	adds r1, r1, r2
_08243ADA:
	str r1, [sp, #0x14]
	ldr r3, [r0, #0x20]
	cmp r3, #0
	beq _08243AEA
	ldr r0, [r0, #0x24]
	bl FUN_08243e56
	ldr r0, [sp, #0x18]
_08243AEA:
	ldr r3, [r0, #0x28]
	bl FUN_08243e56
	ldr r0, [sp, #0x18]
	ldr r3, [r0, #0x10]
	mov r8, r3
	ldr r5, _08243B24 @ =0x00000350
	adds r5, r5, r0
	ldrb r4, [r0, #4]
	subs r7, r4, #1
	bls _08243B0A
	ldrb r1, [r0, #0xb]
	subs r1, r1, r7
	mov r2, r8
	muls r2, r1, r2
	adds r5, r5, r2
_08243B0A:
	str r5, [sp, #8]
	ldr r6, _08243B28 @ =0x00000630
	ldr r3, _08243B1C @ =0x030027A9
	bx r3
	.align 2, 0
_08243B14: .4byte 0x03007FF0
_08243B18: .4byte 0x68736D53
_08243B1C: .4byte 0x030027A9
_08243B20: .4byte 0x04000006
_08243B24: .4byte 0x00000350
_08243B28: .4byte 0x00000630

	thumb_func_start SoundMainRAM
SoundMainRAM: @ 0x08243B2C
	ldrb r3, [r0, #5]
	cmp r3, #0
	beq sub_08243B78
	add r1, pc, #0x4 @ =sub_08243B38
	bx r1
	.align 2, 0

	arm_func_start sub_08243B38
sub_08243B38: @ 0x08243B38
	cmp r4, #2
	addeq r7, r0, #0x350
	addne r7, r5, r8
	mov r4, r8
_08243B48:
	ldrsb r0, [r5]
	ldrsb r1, [r7], #1
	add r0, r0, r1
	mul r1, r0, r3
	asr r0, r1, #8
	tst r0, #0x80
	addne r0, r0, #1
	strb r0, [r5], #1
	subs r4, r4, #1
	bgt _08243B48
	add r0, pc, #0x1F @ =sub_08243B96
	bx r0

	thumb_func_start sub_08243B78
sub_08243B78: @ 0x08243B78
	movs r0, #0
	mov r1, r8
	lsrs r1, r1, #3
	blo _08243B82
	stm r5!, {r0}
_08243B82:
	lsrs r1, r1, #1
	blo _08243B8A
	stm r5!, {r0}
	stm r5!, {r0}
_08243B8A:
	stm r5!, {r0}
	stm r5!, {r0}
	stm r5!, {r0}
	stm r5!, {r0}
	subs r1, #1
	bgt _08243B8A

	non_word_aligned_thumb_func_start sub_08243B96
sub_08243B96: @ 0x08243B96
	ldr r4, [sp, #0x18]
	ldr r0, [r4, #0x18]
	mov ip, r0
	ldrb r0, [r4, #6]
	adds r4, #0x50
_08243BA0:
	str r0, [sp, #4]
	ldr r3, [r4, #0x24]
	ldr r0, [sp, #0x14]
	cmp r0, #0
	beq _08243BC0
	ldr r1, _08243BBC @ =0x04000006
	ldrb r1, [r1]
	cmp r1, #0xa0
	bhs _08243BB4
	adds r1, #0xe4
_08243BB4:
	cmp r1, r0
	blo _08243BC0
	b _08243E42
	.align 2, 0
_08243BBC: .4byte 0x04000006
_08243BC0:
	ldrb r6, [r4]
	movs r0, #0xc7
	tst r0, r6
	bne _08243BCA
	b sub_08243E38
_08243BCA:
	movs r0, #0x80
	tst r0, r6
	beq _08243BFA
	movs r0, #0x40
	tst r0, r6
	bne _08243C0A
	movs r6, #3
	strb r6, [r4]
	adds r0, r3, #0
	adds r0, #0x10
	str r0, [r4, #0x28]
	ldr r0, [r3, #0xc]
	str r0, [r4, #0x18]
	movs r5, #0
	strb r5, [r4, #9]
	str r5, [r4, #0x1c]
	ldrb r2, [r3, #3]
	movs r0, #0xc0
	tst r0, r2
	beq _08243C52
	movs r0, #0x10
	orrs r6, r0
	strb r6, [r4]
	b _08243C52
_08243BFA:
	ldrb r5, [r4, #9]
	movs r0, #4
	tst r0, r6
	beq _08243C10
	ldrb r0, [r4, #0xd]
	subs r0, #1
	strb r0, [r4, #0xd]
	bhi _08243C60
_08243C0A:
	movs r0, #0
	strb r0, [r4]
	b sub_08243E38
_08243C10:
	movs r0, #0x40
	tst r0, r6
	beq _08243C30
	ldrb r0, [r4, #7]
	muls r5, r0, r5
	lsrs r5, r5, #8
	ldrb r0, [r4, #0xc]
	cmp r5, r0
	bhi _08243C60
_08243C22:
	ldrb r5, [r4, #0xc]
	cmp r5, #0
	beq _08243C0A
	movs r0, #4
	orrs r6, r0
	strb r6, [r4]
	b _08243C60
_08243C30:
	movs r2, #3
	ands r2, r6
	cmp r2, #2
	bne _08243C4E
	ldrb r0, [r4, #5]
	muls r5, r0, r5
	lsrs r5, r5, #8
	ldrb r0, [r4, #6]
	cmp r5, r0
	bhi _08243C60
	adds r5, r0, #0
	beq _08243C22
	subs r6, #1
	strb r6, [r4]
	b _08243C60
_08243C4E:
	cmp r2, #3
	bne _08243C60
_08243C52:
	ldrb r0, [r4, #4]
	adds r5, r5, r0
	cmp r5, #0xff
	blo _08243C60
	movs r5, #0xff
	subs r6, #1
	strb r6, [r4]
_08243C60:
	strb r5, [r4, #9]
	ldr r0, [sp, #0x18]
	ldrb r0, [r0, #7]
	adds r0, #1
	muls r0, r5, r0
	lsrs r5, r0, #4
	ldrb r0, [r4, #2]
	ldrb r1, [r4, #3]
	adds r0, r0, r1
	muls r0, r5, r0
	lsrs r0, r0, #9
	strb r0, [r4, #0xa]
	movs r0, #0x10
	ands r0, r6
	str r0, [sp, #0x10]
	beq _08243C90
	adds r0, r3, #0
	adds r0, #0x10
	ldr r1, [r3, #8]
	adds r0, r0, r1
	str r0, [sp, #0xc]
	ldr r0, [r3, #0xc]
	subs r0, r0, r1
	str r0, [sp, #0x10]
_08243C90:
	ldr r5, [sp, #8]
	ldr r2, [r4, #0x18]
	ldr r3, [r4, #0x28]
	add r0, pc, #0x4 @ =sub_08243C9C
	bx r0
	.align 2, 0

	arm_func_start sub_08243C9C
sub_08243C9C: @ 0x08243C9C
	str r8, [sp]
	ldrb sl, [r4, #0xa]
	lsl sl, sl, #0x10
	ldrb r0, [r4, #1]
	tst r0, #8
	beq _08243DA4
_08243CB4:
	cmp r2, #4
	ble _08243D10
	subs r2, r2, r8
	movgt lr, #0
	bgt _08243CE0
	mov lr, r8
	add r2, r2, r8
	sub r8, r2, #4
	sub lr, lr, r8
	ands r2, r2, #3
	moveq r2, #4
_08243CE0:
	ldr r6, [r5]
_08243CE4:
	ldrsb r0, [r3], #1
	mul r1, sl, r0
	bic r1, r1, #0xff0000
	add r6, r1, r6, ror #8
	adds r5, r5, #0x40000000
	blo _08243CE4
	str r6, [r5], #4
	subs r8, r8, #4
	bgt _08243CE0
	adds r8, r8, lr
	beq _08243E24
_08243D10:
	ldr r6, [r5]
_08243D14:
	ldrsb r0, [r3], #1
	mul r1, sl, r0
	bic r1, r1, #0xff0000
	add r6, r1, r6, ror #8
	subs r2, r2, #1
	beq _08243D74
_08243D2C:
	adds r5, r5, #0x40000000
	blo _08243D14
	str r6, [r5], #4
	subs r8, r8, #4
	bgt _08243CB4
	b _08243E24
_08243D44:
	ldr r0, [sp, #0x18]
	cmp r0, #0
	beq _08243D68
	ldr r3, [sp, #0x14]
	rsb sb, r2, #0
_08243D58:
	adds r2, r0, r2
	bgt _08243DF8
	sub sb, sb, r0
	b _08243D58
_08243D68:
	pop {r4, ip}
	mov r2, #0
	b _08243D84
_08243D74:
	ldr r2, [sp, #0x10]
	cmp r2, #0
	ldrne r3, [sp, #0xc]
	bne _08243D2C
_08243D84:
	strb r2, [r4]
	lsr r0, r5, #0x1e
	bic r5, r5, #0xc0000000
	rsb r0, r0, #3
	lsl r0, r0, #3
	ror r6, r6, r0
	str r6, [r5], #4
	b _08243E2C
_08243DA4:
	push {r4, ip}
	ldr lr, [r4, #0x1c]
	ldr r1, [r4, #0x20]
	mul r4, ip, r1
	ldrsb r0, [r3]
	ldrsb r1, [r3, #1]!
	sub r1, r1, r0
_08243DC0:
	ldr r6, [r5]
_08243DC4:
	mul sb, lr, r1
	add sb, r0, sb, asr #23
	mul ip, sl, sb
	bic ip, ip, #0xff0000
	add r6, ip, r6, ror #8
	add lr, lr, r4
	lsrs sb, lr, #0x17
	beq _08243E04
	bic lr, lr, #0x3f800000
	subs r2, r2, sb
	ble _08243D44
	subs sb, sb, #1
	addeq r0, r0, r1
_08243DF8:
	ldrsbne r0, [r3, sb]!
	ldrsb r1, [r3, #1]!
	sub r1, r1, r0
_08243E04:
	adds r5, r5, #0x40000000
	blo _08243DC4
	str r6, [r5], #4
	subs r8, r8, #4
	bgt _08243DC0
	sub r3, r3, #1
	pop {r4, ip}
	str lr, [r4, #0x1c]
_08243E24:
	str r2, [r4, #0x18]
	str r3, [r4, #0x28]
_08243E2C:
	ldr r8, [sp]
	add r0, pc, #0x1 @ =sub_08243E38
	bx r0

	thumb_func_start sub_08243E38
sub_08243E38: @ 0x08243E38
	ldr r0, [sp, #4]
	subs r0, #1
	ble _08243E42
	adds r4, #0x40
	b _08243BA0
_08243E42:
	ldr r0, [sp, #0x18]
	ldr r3, _08243E58 @ =0x68736D53
	str r3, [r0]
	add sp, #0x1c
	pop {r0, r1, r2, r3, r4, r5, r6, r7}
	mov r8, r0
	mov sb, r1
	mov sl, r2
	mov fp, r3
	pop {r3}

	non_word_aligned_thumb_func_start FUN_08243e56
FUN_08243e56: @ 0x08243E56
	bx r3
	.align 2, 0
_08243E58: .4byte 0x68736D53

	thumb_func_start FUN_08243e5c
FUN_08243e5c: @ 0x08243E5C
	mov ip, r4
	movs r1, #0
	movs r2, #0
	movs r3, #0
	movs r4, #0
	stm r0!, {r1, r2, r3, r4}
	stm r0!, {r1, r2, r3, r4}
	stm r0!, {r1, r2, r3, r4}
	stm r0!, {r1, r2, r3, r4}
	mov r4, ip
	bx lr
	.align 2, 0

	thumb_func_start FUN_08243e74
FUN_08243e74: @ 0x08243E74
	ldr r3, [r0, #0x2c]
	cmp r3, #0
	beq _08243E92
	ldr r1, [r0, #0x34]
	ldr r2, [r0, #0x30]
	cmp r2, #0
	beq _08243E86
	str r1, [r2, #0x34]
	b _08243E88
_08243E86:
	str r1, [r3, #0x20]
_08243E88:
	cmp r1, #0
	beq _08243E8E
	str r2, [r1, #0x30]
_08243E8E:
	movs r1, #0
	str r1, [r0, #0x2c]
_08243E92:
	bx lr
_08243E94:
	push {r4, r5, lr}
	adds r5, r1, #0
	ldr r4, [r5, #0x20]
	cmp r4, #0
	beq _08243EC2
_08243E9E:
	ldrb r1, [r4]
	movs r0, #0xc7
	tst r0, r1
	beq _08243EAC
	movs r0, #0x40
	orrs r1, r0
	strb r1, [r4]
_08243EAC:
	adds r0, r4, #0
	bl FUN_08243e74
	ldr r1, [r4, #0x34]
	cmp r1, r4
	bne _08243EBC
	movs r1, #0
	str r1, [r4, #0x34]
_08243EBC:
	adds r4, r1, #0
	cmp r4, #0
	bne _08243E9E
_08243EC2:
	movs r0, #0
	strb r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start MPlayJumpTableCopy
MPlayJumpTableCopy: @ 0x08243ECC
	mov ip, lr
	movs r1, #0x24
	ldr r2, _08243EFC @ =0x08252928
_08243ED2:
	ldr r3, [r2]
	bl _08243EE6
	stm r0!, {r3}
	adds r2, #4
	subs r1, #1
	bgt _08243ED2
	bx ip
	.align 2, 0

	thumb_func_start FUN_08243ee4
FUN_08243ee4: @ 0x08243EE4
	ldrb r3, [r2]
_08243EE6:
	push {r0}
	lsrs r0, r2, #0x19
	bne _08243EF8
	ldr r0, _08243EFC @ =0x08252928
	cmp r2, r0
	blo _08243EF6
	lsrs r0, r2, #0xe
	beq _08243EF8
_08243EF6:
	movs r3, #0
_08243EF8:
	pop {r0}
	bx lr
	.align 2, 0
_08243EFC: .4byte 0x08252928

	thumb_func_start FUN_08243f00
FUN_08243f00: @ 0x08243F00
	ldr r2, [r1, #0x40]

	non_word_aligned_thumb_func_start FUN_08243f02
FUN_08243f02: @ 0x08243F02
	adds r3, r2, #1
	str r3, [r1, #0x40]
	ldrb r3, [r2]
	b _08243EE6
	.align 2, 0
_08243F0C:
	push {lr}
_08243F0E:
	ldr r2, [r1, #0x40]
	ldrb r0, [r2, #3]
	lsls r0, r0, #8
	ldrb r3, [r2, #2]
	orrs r0, r3
	lsls r0, r0, #8
	ldrb r3, [r2, #1]
	orrs r0, r3
	lsls r0, r0, #8
	bl FUN_08243ee4
	orrs r0, r3
	str r0, [r1, #0x40]
	pop {r0}
	bx r0

	thumb_func_start FUN_08243f2c
FUN_08243f2c: @ 0x08243F2C
	ldrb r2, [r1, #2]
	cmp r2, #3
	bhs _08243F44
	lsls r2, r2, #2
	adds r3, r1, r2
	ldr r2, [r1, #0x40]
	adds r2, #4
	str r2, [r3, #0x44]
	ldrb r2, [r1, #2]
	adds r2, #1
	strb r2, [r1, #2]
	b _08243F0C
_08243F44:
	b _08243E94
	.align 2, 0

	thumb_func_start FUN_08243f48
FUN_08243f48: @ 0x08243F48
	ldrb r2, [r1, #2]
	cmp r2, #0
	beq _08243F5A
	subs r2, #1
	strb r2, [r1, #2]
	lsls r2, r2, #2
	adds r3, r1, r2
	ldr r2, [r3, #0x44]
	str r2, [r1, #0x40]
_08243F5A:
	bx lr

	thumb_func_start FUN_08243f5c
FUN_08243f5c: @ 0x08243F5C
	push {lr}
	ldr r2, [r1, #0x40]
	ldrb r3, [r2]
	cmp r3, #0
	bne _08243F6C
	adds r2, #1
	str r2, [r1, #0x40]
	b _08243F0E
_08243F6C:
	ldrb r3, [r1, #3]
	adds r3, #1
	strb r3, [r1, #3]
	mov ip, r3
	bl FUN_08243f00
	cmp ip, r3
	bhs _08243F7E
	b _08243F0E
_08243F7E:
	movs r3, #0
	strb r3, [r1, #3]
	adds r2, #5
	str r2, [r1, #0x40]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08243f8c
FUN_08243f8c: @ 0x08243F8C
	mov ip, lr
	bl FUN_08243f00
	strb r3, [r1, #0x1d]
	bx ip
	.align 2, 0

	thumb_func_start FUN_08243f98
FUN_08243f98: @ 0x08243F98
	mov ip, lr
	bl FUN_08243f00
	lsls r3, r3, #1
	strh r3, [r0, #0x1c]
	ldrh r2, [r0, #0x1e]
	muls r3, r2, r3
	lsrs r3, r3, #8
	strh r3, [r0, #0x20]
	bx ip

	thumb_func_start FUN_08243fac
FUN_08243fac: @ 0x08243FAC
	mov ip, lr
	bl FUN_08243f00
	strb r3, [r1, #0xa]
	ldrb r3, [r1]
	movs r2, #0xc
	orrs r3, r2
	strb r3, [r1]
	bx ip
	.align 2, 0

	thumb_func_start FUN_08243fc0
FUN_08243fc0: @ 0x08243FC0
	mov ip, lr
	ldr r2, [r1, #0x40]
	ldrb r3, [r2]
	adds r2, #1
	str r2, [r1, #0x40]
	lsls r2, r3, #1
	adds r2, r2, r3
	lsls r2, r2, #2
	ldr r3, [r0, #0x30]
	adds r2, r2, r3
	ldr r3, [r2]
	bl _08243EE6
	str r3, [r1, #0x24]
	ldr r3, [r2, #4]
	bl _08243EE6
	str r3, [r1, #0x28]
	ldr r3, [r2, #8]
	bl _08243EE6
	str r3, [r1, #0x2c]
	bx ip
	.align 2, 0

	thumb_func_start FUN_08243ff0
FUN_08243ff0: @ 0x08243FF0
	mov ip, lr
	bl FUN_08243f00
	strb r3, [r1, #0x12]
	ldrb r3, [r1]
	movs r2, #3
	orrs r3, r2
	strb r3, [r1]
	bx ip
	.align 2, 0

	thumb_func_start FUN_08244004
FUN_08244004: @ 0x08244004
	mov ip, lr
	bl FUN_08243f00
	subs r3, #0x40
	strb r3, [r1, #0x14]
	ldrb r3, [r1]
	movs r2, #3
	orrs r3, r2
	strb r3, [r1]
	bx ip

	thumb_func_start FUN_08244018
FUN_08244018: @ 0x08244018
	mov ip, lr
	bl FUN_08243f00
	subs r3, #0x40
	strb r3, [r1, #0xe]
	ldrb r3, [r1]
	movs r2, #0xc
	orrs r3, r2
	strb r3, [r1]
	bx ip

	thumb_func_start FUN_0824402c
FUN_0824402c: @ 0x0824402C
	mov ip, lr
	bl FUN_08243f00
	strb r3, [r1, #0xf]
	ldrb r3, [r1]
	movs r2, #0xc
	orrs r3, r2
	strb r3, [r1]
	bx ip
	.align 2, 0

	thumb_func_start FUN_08244040
FUN_08244040: @ 0x08244040
	mov ip, lr
	bl FUN_08243f00
	strb r3, [r1, #0x1b]
	bx ip
	.align 2, 0

	thumb_func_start FUN_0824404c
FUN_0824404c: @ 0x0824404C
	mov ip, lr
	bl FUN_08243f00
	ldrb r0, [r1, #0x18]
	cmp r0, r3
	beq _08244062
	strb r3, [r1, #0x18]
	ldrb r3, [r1]
	movs r2, #0xf
	orrs r3, r2
	strb r3, [r1]
_08244062:
	bx ip

	thumb_func_start FUN_08244064
FUN_08244064: @ 0x08244064
	mov ip, lr
	bl FUN_08243f00
	subs r3, #0x40
	strb r3, [r1, #0xc]
	ldrb r3, [r1]
	movs r2, #0xc
	orrs r3, r2
	strb r3, [r1]
	bx ip

	thumb_func_start FUN_08244078
FUN_08244078: @ 0x08244078
	mov ip, lr
	ldr r2, [r1, #0x40]
	ldrb r3, [r2]
	adds r2, #1
	ldr r0, _0824408C @ =0x04000060
	adds r0, r0, r3
	bl FUN_08243f02
	strb r3, [r0]
	bx ip
	.align 2, 0
_0824408C: .4byte 0x04000060

	thumb_func_start MPlayMain
MPlayMain: @ 0x08244090
	ldr r2, _08244308 @ =0x68736D53
	ldr r3, [r0, #0x34]
	cmp r2, r3
	beq _0824409A
	bx lr
_0824409A:
	adds r3, #1
	str r3, [r0, #0x34]
	push {r0, lr}
	ldr r3, [r0, #0x38]
	cmp r3, #0
	beq _082440AC
	ldr r0, [r0, #0x3c]
	bl FUN_082442fc
_082440AC:
	pop {r0}
	push {r4, r5, r6, r7}
	mov r4, r8
	mov r5, sb
	mov r6, sl
	mov r7, fp
	push {r4, r5, r6, r7}
	adds r7, r0, #0
	ldr r0, [r7, #4]
	cmp r0, #0
	bge _082440C4
	b _082442EC
_082440C4:
	ldr r0, _08244304 @ =0x03007FF0
	ldr r0, [r0]
	mov r8, r0
	adds r0, r7, #0
	bl FadeOutBody
	ldr r0, [r7, #4]
	cmp r0, #0
	bge _082440D8
	b _082442EC
_082440D8:
	ldrh r0, [r7, #0x22]
	ldrh r1, [r7, #0x20]
	adds r0, r0, r1
	b _08244232
_082440E0:
	ldrb r6, [r7, #8]
	ldr r5, [r7, #0x2c]
	movs r3, #1
	movs r4, #0
_082440E8:
	ldrb r0, [r5]
	movs r1, #0x80
	tst r1, r0
	bne _082440F2
	b _0824420E
_082440F2:
	mov sl, r3
	orrs r4, r3
	mov fp, r4
	ldr r4, [r5, #0x20]
	cmp r4, #0
	beq _08244130
_082440FE:
	ldrb r1, [r4]
	movs r0, #0xc7
	tst r0, r1
	beq _0824411A
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	beq _08244120
	subs r0, #1
	strb r0, [r4, #0x10]
	bne _08244120
	movs r0, #0x40
	orrs r1, r0
	strb r1, [r4]
	b _08244120
_0824411A:
	adds r0, r4, #0
	bl ClearChain
_08244120:
	ldr r1, [r4, #0x34]
	cmp r1, r4
	bne _0824412A
	movs r1, #0
	str r1, [r4, #0x34]
_0824412A:
	adds r4, r1, #0
	cmp r4, #0
	bne _082440FE
_08244130:
	ldrb r3, [r5]
	movs r0, #0x40
	tst r0, r3
	beq _082441AE
	adds r0, r5, #0
	bl Clear64byte
	movs r0, #0x80
	strb r0, [r5]
	movs r0, #2
	strb r0, [r5, #0xf]
	movs r0, #0x40
	strb r0, [r5, #0x13]
	movs r0, #0x16
	strb r0, [r5, #0x19]
	movs r0, #1
	adds r1, r5, #6
	strb r0, [r1, #0x1e]
	b _082441AE
_08244156:
	ldr r2, [r5, #0x40]
	ldrb r1, [r2]
	cmp r1, #0x80
	bhs _08244162
	ldrb r1, [r5, #7]
	b _0824416C
_08244162:
	adds r2, #1
	str r2, [r5, #0x40]
	cmp r1, #0xbd
	blo _0824416C
	strb r1, [r5, #7]
_0824416C:
	cmp r1, #0xcf
	blo _08244182
	mov r0, r8
	ldr r3, [r0, #0x38]
	adds r0, r1, #0
	subs r0, #0xcf
	adds r1, r7, #0
	adds r2, r5, #0
	bl FUN_082442fc
	b _082441AE
_08244182:
	cmp r1, #0xb0
	bls _082441A4
	adds r0, r1, #0
	subs r0, #0xb1
	strb r0, [r7, #0xa]
	mov r3, r8
	ldr r3, [r3, #0x34]
	lsls r0, r0, #2
	ldr r3, [r3, r0]
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_082442fc
	ldrb r0, [r5]
	cmp r0, #0
	beq _0824420A
	b _082441AE
_082441A4:
	ldr r0, _08244300 @ =0x08252B9C
	subs r1, #0x80
	adds r1, r1, r0
	ldrb r0, [r1]
	strb r0, [r5, #1]
_082441AE:
	ldrb r0, [r5, #1]
	cmp r0, #0
	beq _08244156
	subs r0, #1
	strb r0, [r5, #1]
	ldrb r1, [r5, #0x19]
	cmp r1, #0
	beq _0824420A
	ldrb r0, [r5, #0x17]
	cmp r0, #0
	beq _0824420A
	ldrb r0, [r5, #0x1c]
	cmp r0, #0
	beq _082441D0
	subs r0, #1
	strb r0, [r5, #0x1c]
	b _0824420A
_082441D0:
	ldrb r0, [r5, #0x1a]
	adds r0, r0, r1
	strb r0, [r5, #0x1a]
	adds r1, r0, #0
	subs r0, #0x40
	lsls r0, r0, #0x18
	bpl _082441E4
	lsls r2, r1, #0x18
	asrs r2, r2, #0x18
	b _082441E8
_082441E4:
	movs r0, #0x80
	subs r2, r0, r1
_082441E8:
	ldrb r0, [r5, #0x17]
	muls r0, r2, r0
	asrs r2, r0, #6
	ldrb r0, [r5, #0x16]
	eors r0, r2
	lsls r0, r0, #0x18
	beq _0824420A
	strb r2, [r5, #0x16]
	ldrb r0, [r5]
	ldrb r1, [r5, #0x18]
	cmp r1, #0
	bne _08244204
	movs r1, #0xc
	b _08244206
_08244204:
	movs r1, #3
_08244206:
	orrs r0, r1
	strb r0, [r5]
_0824420A:
	mov r3, sl
	mov r4, fp
_0824420E:
	subs r6, #1
	ble _0824421A
	movs r0, #0x50
	adds r5, r5, r0
	lsls r3, r3, #1
	b _082440E8
_0824421A:
	ldr r0, [r7, #0xc]
	adds r0, #1
	str r0, [r7, #0xc]
	cmp r4, #0
	bne _0824422C
	movs r0, #0x80
	lsls r0, r0, #0x18
	str r0, [r7, #4]
	b _082442EC
_0824422C:
	str r4, [r7, #4]
	ldrh r0, [r7, #0x22]
	subs r0, #0x96
_08244232:
	strh r0, [r7, #0x22]
	cmp r0, #0x96
	blo _0824423A
	b _082440E0
_0824423A:
	ldrb r2, [r7, #8]
	ldr r5, [r7, #0x2c]
_0824423E:
	ldrb r0, [r5]
	movs r1, #0x80
	tst r1, r0
	beq _082442E2
	movs r1, #0xf
	tst r1, r0
	beq _082442E2
	mov sb, r2
	adds r0, r7, #0
	adds r1, r5, #0
	bl TrkVolPitSet
	ldr r4, [r5, #0x20]
	cmp r4, #0
	beq _082442D8
_0824425C:
	ldrb r1, [r4]
	movs r0, #0xc7
	tst r0, r1
	bne _0824426C
	adds r0, r4, #0
	bl ClearChain
	b _082442C8
_0824426C:
	ldrb r0, [r4, #1]
	movs r6, #7
	ands r6, r0
	ldrb r3, [r5]
	movs r0, #3
	tst r0, r3
	beq _0824428A
	bl ChnVolSetAsm
	cmp r6, #0
	beq _0824428A
	ldrb r0, [r4, #0x1d]
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0x1d]
_0824428A:
	ldrb r3, [r5]
	movs r0, #0xc
	tst r0, r3
	beq _082442C8
	ldrb r1, [r4, #8]
	movs r0, #8
	ldrsb r0, [r5, r0]
	adds r2, r1, r0
	bpl _0824429E
	movs r2, #0
_0824429E:
	cmp r6, #0
	beq _082442BC
	mov r0, r8
	ldr r3, [r0, #0x30]
	adds r1, r2, #0
	ldrb r2, [r5, #9]
	adds r0, r6, #0
	bl FUN_082442fc
	str r0, [r4, #0x20]
	ldrb r0, [r4, #0x1d]
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0x1d]
	b _082442C8
_082442BC:
	adds r1, r2, #0
	ldrb r2, [r5, #9]
	ldr r0, [r4, #0x24]
	bl MidiKeyToFreq
	str r0, [r4, #0x20]
_082442C8:
	ldr r1, [r4, #0x34]
	cmp r1, r4
	bne _082442D2
	movs r1, #0
	str r1, [r4, #0x34]
_082442D2:
	adds r4, r1, #0
	cmp r4, #0
	bne _0824425C
_082442D8:
	ldrb r0, [r5]
	movs r1, #0xf0
	ands r0, r1
	strb r0, [r5]
	mov r2, sb
_082442E2:
	subs r2, #1
	ble _082442EC
	movs r0, #0x50
	adds r5, r5, r0
	bgt _0824423E
_082442EC:
	ldr r0, _08244308 @ =0x68736D53
	str r0, [r7, #0x34]
	pop {r0, r1, r2, r3, r4, r5, r6, r7}
	mov r8, r0
	mov sb, r1
	mov sl, r2
	mov fp, r3
	pop {r3}

	thumb_func_start FUN_082442fc
FUN_082442fc: @ 0x082442FC
	bx r3
	.align 2, 0
_08244300: .4byte 0x08252B9C
_08244304: .4byte 0x03007FF0
_08244308: .4byte 0x68736D53

	thumb_func_start TrackStop
TrackStop: @ 0x0824430C
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	ldrb r1, [r5]
	movs r0, #0x80
	tst r0, r1
	beq _0824434E
	ldr r4, [r5, #0x20]
	cmp r4, #0
	beq _0824434C
	movs r6, #0
_08244320:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0824433A
	ldrb r0, [r4, #1]
	movs r3, #7
	ands r0, r3
	beq _08244338
	ldr r3, _08244354 @ =0x03007FF0
	ldr r3, [r3]
	ldr r3, [r3, #0x2c]
	bl FUN_082442fc
_08244338:
	strb r6, [r4]
_0824433A:
	str r6, [r4, #0x2c]
	ldr r0, [r4, #0x34]
	cmp r0, r4
	bne _08244346
	movs r0, #0
	str r0, [r4, #0x34]
_08244346:
	adds r4, r0, #0
	cmp r4, #0
	bne _08244320
_0824434C:
	str r4, [r5, #0x20]
_0824434E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08244354: .4byte 0x03007FF0

	thumb_func_start ChnVolSetAsm
ChnVolSetAsm: @ 0x08244358
	ldrb r1, [r4, #0x12]
	movs r0, #0x14
	ldrsb r2, [r4, r0]
	movs r3, #0x80
	adds r3, r3, r2
	muls r3, r1, r3
	ldrb r0, [r5, #0x10]
	muls r0, r3, r0
	asrs r0, r0, #0xe
	cmp r0, #0xff
	bls _08244370
	movs r0, #0xff
_08244370:
	strb r0, [r4, #2]
	movs r3, #0x7f
	subs r3, r3, r2
	muls r3, r1, r3
	ldrb r0, [r5, #0x11]
	muls r0, r3, r0
	asrs r0, r0, #0xe
	cmp r0, #0xff
	bls _08244384
	movs r0, #0xff
_08244384:
	strb r0, [r4, #3]
	bx lr

	thumb_func_start ply_note
ply_note: @ 0x08244388
	push {r4, r5, r6, r7, lr}
	mov r4, r8
	mov r5, sb
	mov r6, sl
	mov r7, fp
	push {r4, r5, r6, r7}
	sub sp, #0x18
	str r1, [sp]
	adds r5, r2, #0
	ldr r1, _08244580 @ =0x03007FF0
	ldr r1, [r1]
	str r1, [sp, #4]
	ldr r1, _08244584 @ =0x08252B9C
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #4]
	ldr r3, [r5, #0x40]
	ldrb r0, [r3]
	cmp r0, #0x80
	bhs _082443CE
	strb r0, [r5, #5]
	adds r3, #1
	ldrb r0, [r3]
	cmp r0, #0x80
	bhs _082443CC
	strb r0, [r5, #6]
	adds r3, #1
	ldrb r0, [r3]
	cmp r0, #0x80
	bhs _082443CC
	ldrb r1, [r5, #4]
	adds r1, r1, r0
	strb r1, [r5, #4]
	adds r3, #1
_082443CC:
	str r3, [r5, #0x40]
_082443CE:
	movs r0, #0
	str r0, [sp, #0x14]
	adds r4, r5, #0
	adds r4, #0x24
	ldrb r2, [r4]
	movs r0, #0xc0
	tst r0, r2
	beq _08244420
	ldrb r3, [r5, #5]
	movs r0, #0x40
	tst r0, r2
	beq _082443EE
	ldr r1, [r5, #0x2c]
	adds r1, r1, r3
	ldrb r0, [r1]
	b _082443F0
_082443EE:
	adds r0, r3, #0
_082443F0:
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, [r5, #0x28]
	adds r1, r1, r0
	mov sb, r1
	mov r6, sb
	ldrb r1, [r6]
	movs r0, #0xc0
	tst r0, r1
	beq _08244408
	b _0824456E
_08244408:
	movs r0, #0x80
	tst r0, r2
	beq _08244424
	ldrb r1, [r6, #3]
	movs r0, #0x80
	tst r0, r1
	beq _0824441C
	subs r1, #0xc0
	lsls r1, r1, #1
	str r1, [sp, #0x14]
_0824441C:
	ldrb r3, [r6, #1]
	b _08244424
_08244420:
	mov sb, r4
	ldrb r3, [r5, #5]
_08244424:
	str r3, [sp, #8]
	ldr r6, [sp]
	ldrb r1, [r6, #9]
	ldrb r0, [r5, #0x1d]
	adds r0, r0, r1
	cmp r0, #0xff
	bls _08244434
	movs r0, #0xff
_08244434:
	str r0, [sp, #0x10]
	mov r6, sb
	ldrb r0, [r6]
	movs r6, #7
	ands r6, r0
	str r6, [sp, #0xc]
	beq _08244474
	ldr r0, [sp, #4]
	ldr r4, [r0, #0x1c]
	cmp r4, #0
	bne _0824444C
	b _0824456E
_0824444C:
	subs r6, #1
	lsls r0, r6, #6
	adds r4, r4, r0
	ldrb r1, [r4]
	movs r0, #0xc7
	tst r0, r1
	beq _082444C8
	movs r0, #0x40
	tst r0, r1
	bne _082444C8
	ldrb r1, [r4, #0x13]
	ldr r0, [sp, #0x10]
	cmp r1, r0
	blo _082444C8
	beq _0824446C
	b _0824456E
_0824446C:
	ldr r0, [r4, #0x2c]
	cmp r0, r5
	bhs _082444C8
	b _0824456E
_08244474:
	ldr r6, [sp, #0x10]
	adds r7, r5, #0
	movs r2, #0
	mov r8, r2
	ldr r4, [sp, #4]
	ldrb r3, [r4, #6]
	adds r4, #0x50
_08244482:
	ldrb r1, [r4]
	movs r0, #0xc7
	tst r0, r1
	beq _082444C8
	movs r0, #0x40
	tst r0, r1
	beq _0824449C
	cmp r2, #0
	bne _082444A0
	adds r2, #1
	ldrb r6, [r4, #0x13]
	ldr r7, [r4, #0x2c]
	b _082444BA
_0824449C:
	cmp r2, #0
	bne _082444BC
_082444A0:
	ldrb r0, [r4, #0x13]
	cmp r0, r6
	bhs _082444AC
	adds r6, r0, #0
	ldr r7, [r4, #0x2c]
	b _082444BA
_082444AC:
	bhi _082444BC
	ldr r0, [r4, #0x2c]
	cmp r0, r7
	bls _082444B8
	adds r7, r0, #0
	b _082444BA
_082444B8:
	blo _082444BC
_082444BA:
	mov r8, r4
_082444BC:
	adds r4, #0x40
	subs r3, #1
	bgt _08244482
	mov r4, r8
	cmp r4, #0
	beq _0824456E
_082444C8:
	adds r0, r4, #0
	bl ClearChain
	movs r1, #0
	str r1, [r4, #0x30]
	ldr r3, [r5, #0x20]
	str r3, [r4, #0x34]
	cmp r3, #0
	beq _082444DC
	str r4, [r3, #0x30]
_082444DC:
	str r4, [r5, #0x20]
	str r5, [r4, #0x2c]
	ldrb r0, [r5, #0x1b]
	strb r0, [r5, #0x1c]
	cmp r0, r1
	beq _082444EE
	adds r1, r5, #0
	bl FUN_082445d4
_082444EE:
	ldr r0, [sp]
	adds r1, r5, #0
	bl TrkVolPitSet
	ldr r0, [r5, #4]
	str r0, [r4, #0x10]
	ldr r0, [sp, #0x10]
	strb r0, [r4, #0x13]
	ldr r0, [sp, #8]
	strb r0, [r4, #8]
	ldr r0, [sp, #0x14]
	strb r0, [r4, #0x14]
	mov r6, sb
	ldrb r0, [r6]
	strb r0, [r4, #1]
	ldr r7, [r6, #4]
	str r7, [r4, #0x24]
	ldr r0, [r6, #8]
	str r0, [r4, #4]
	ldrh r0, [r5, #0x1e]
	strh r0, [r4, #0xc]
	bl ChnVolSetAsm
	ldrb r1, [r4, #8]
	movs r0, #8
	ldrsb r0, [r5, r0]
	adds r3, r1, r0
	bpl _08244528
	movs r3, #0
_08244528:
	ldr r6, [sp, #0xc]
	cmp r6, #0
	beq _08244556
	mov r6, sb
	ldrb r0, [r6, #2]
	strb r0, [r4, #0x1e]
	ldrb r1, [r6, #3]
	movs r0, #0x80
	tst r0, r1
	bne _08244542
	movs r0, #0x70
	tst r0, r1
	bne _08244544
_08244542:
	movs r1, #8
_08244544:
	strb r1, [r4, #0x1f]
	ldrb r2, [r5, #9]
	adds r1, r3, #0
	ldr r0, [sp, #0xc]
	ldr r3, [sp, #4]
	ldr r3, [r3, #0x30]
	bl FUN_082442fc
	b _08244560
_08244556:
	ldrb r2, [r5, #9]
	adds r1, r3, #0
	adds r0, r7, #0
	bl MidiKeyToFreq
_08244560:
	str r0, [r4, #0x20]
	movs r0, #0x80
	strb r0, [r4]
	ldrb r1, [r5]
	movs r0, #0xf0
	ands r0, r1
	strb r0, [r5]
_0824456E:
	add sp, #0x18
	pop {r0, r1, r2, r3, r4, r5, r6, r7}
	mov r8, r0
	mov sb, r1
	mov sl, r2
	mov fp, r3
	pop {r0}
	bx r0
	.align 2, 0
_08244580: .4byte 0x03007FF0
_08244584: .4byte 0x08252B9C

	thumb_func_start ply_endtie
ply_endtie: @ 0x08244588
	push {r4, r5}
	ldr r2, [r1, #0x40]
	ldrb r3, [r2]
	cmp r3, #0x80
	bhs _0824459A
	strb r3, [r1, #5]
	adds r2, #1
	str r2, [r1, #0x40]
	b _0824459C
_0824459A:
	ldrb r3, [r1, #5]
_0824459C:
	ldr r1, [r1, #0x20]
	cmp r1, #0
	beq _082445CE
	movs r4, #0x83
	movs r5, #0x40
_082445A6:
	ldrb r2, [r1]
	tst r2, r4
	beq _082445BE
	tst r2, r5
	bne _082445BE
	ldrb r0, [r1, #0x11]
	cmp r0, r3
	bne _082445BE
	movs r0, #0x40
	orrs r2, r0
	strb r2, [r1]
	b _082445CE
_082445BE:
	ldr r2, [r1, #0x34]
	cmp r2, r1
	bne _082445C8
	movs r2, #0
	str r2, [r1, #0x34]
_082445C8:
	adds r1, r2, #0
	cmp r1, #0
	bne _082445A6
_082445CE:
	pop {r4, r5}
	bx lr
	.align 2, 0

	thumb_func_start FUN_082445d4
FUN_082445d4: @ 0x082445D4
	movs r2, #0
	strb r2, [r1, #0x16]
	strb r2, [r1, #0x1a]
	ldrb r2, [r1, #0x18]
	cmp r2, #0
	bne _082445E4
	movs r2, #0xc
	b _082445E6
_082445E4:
	movs r2, #3
_082445E6:
	ldrb r3, [r1]
	orrs r3, r2
	strb r3, [r1]
	bx lr
	.align 2, 0

	thumb_func_start ld_r3_tp_adr_i_unchecked
ld_r3_tp_adr_i_unchecked: @ 0x082445F0
	ldr r2, [r1, #0x40]
	adds r3, r2, #1
	str r3, [r1, #0x40]
	ldrb r3, [r2]
	bx lr
	.align 2, 0

	thumb_func_start ply_lfos
ply_lfos: @ 0x082445FC
	mov ip, lr
	bl ld_r3_tp_adr_i_unchecked
	strb r3, [r1, #0x19]
	cmp r3, #0
	bne _0824460C
	bl FUN_082445d4
_0824460C:
	bx ip
	.align 2, 0

	thumb_func_start ply_mod
ply_mod: @ 0x08244610
	mov ip, lr
	bl ld_r3_tp_adr_i_unchecked
	strb r3, [r1, #0x17]
	cmp r3, #0
	bne _08244620
	bl FUN_082445d4
_08244620:
	bx ip
	.align 2, 0
