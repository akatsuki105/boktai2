	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08052eb8
FUN_08052eb8: @ 0x08052EB8
	push {r4, r5, lr}
	sub sp, #4
	adds r2, r0, #0
	adds r4, r1, #0
	adds r5, r4, #0
	adds r5, #0x14
	adds r2, #0x18
	adds r0, r5, #0
	adds r1, r2, #0
	movs r2, #3
	bl FUN_0822a470
	movs r0, #0
	strb r0, [r5, #7]
	adds r4, #0x30
	str r0, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _08052EEC @ =0x05000002
	bl CpuSet
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08052EEC: .4byte 0x05000002

	thumb_func_start FUN_08052ef0
FUN_08052ef0: @ 0x08052EF0
	push {lr}
	adds r0, r1, #0
	adds r0, #0x14
	bl FUN_0822a4e0
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08052f00
FUN_08052f00: @ 0x08052F00
	push {r4, lr}
	sub sp, #0x1c
	adds r2, r1, #0
	adds r4, r2, #0
	adds r4, #0x14
	ldr r0, [r2, #0x10]
	cmp r0, #0
	beq _08052F18
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2, #8]
	str r1, [r2, #0xc]
_08052F18:
	ldr r0, [r2, #4]
	cmp r0, #7
	bhi _08052F2E
	lsls r0, r0, #6
	ldrh r1, [r2, #0xa]
	adds r0, r0, r1
	strh r0, [r4, #0x1e]
	ldr r0, [r2, #4]
	lsls r0, r0, #1
	adds r0, #1
	b _08052F30
_08052F2E:
	movs r0, #0x40
_08052F30:
	strb r0, [r4, #8]
	ldr r0, [r2, #4]
	cmp r0, #0x13
	bls _08052F70
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	movs r3, #0
	strb r3, [r2, #1]
	ldr r0, _08052F6C @ =0x085AB73C
	ldrb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x1c
	movs r0, #0xff
	str r0, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	str r3, [sp, #0x10]
	movs r0, #0x10
	str r0, [sp, #0x14]
	movs r0, #8
	str r0, [sp, #0x18]
	movs r0, #7
	bl FUN_080149dc
	b _08052F74
	.align 2, 0
_08052F6C: .4byte 0x085AB73C
_08052F70:
	adds r0, #1
	str r0, [r2, #4]
_08052F74:
	add sp, #0x1c
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08052f7c
FUN_08052f7c: @ 0x08052F7C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x34
	movs r5, #0
_08052F86:
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _08052F96
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_08052f00
_08052F96:
	adds r5, #1
	adds r4, #0x40
	cmp r5, #3
	ble _08052F86
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08052fa8
FUN_08052fa8: @ 0x08052FA8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x34
	movs r4, #0
_08052FB2:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08052ef0
	adds r4, #1
	adds r5, #0x40
	cmp r4, #3
	ble _08052FB2
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08052fcc
FUN_08052fcc: @ 0x08052FCC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r0, #0x18
	ldr r1, _08052FF8 @ =0x000018A8
	bl FUN_0822b16c
	adds r5, r6, #0
	adds r5, #0x34
	movs r4, #0
_08052FDE:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08052eb8
	adds r4, #1
	adds r5, #0x40
	cmp r4, #3
	ble _08052FDE
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08052FF8: .4byte 0x000018A8

	thumb_func_start FUN_08052ffc
FUN_08052ffc: @ 0x08052FFC
	push {r4, lr}
	movs r1, #0x9a
	lsls r1, r1, #1
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08053034
	ldr r1, _0805302C @ =FUN_08052f7c
	ldr r2, _08053030 @ =FUN_08052fa8
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_08052fcc
	cmp r0, #0
	bge _08053034
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08053036
	.align 2, 0
_0805302C: .4byte FUN_08052f7c
_08053030: .4byte FUN_08052fa8
_08053034:
	adds r0, r4, #0
_08053036:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805303c
FUN_0805303c: @ 0x0805303C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	cmp r4, #0
	beq _08053086
	lsls r0, r1, #6
	adds r0, #0x34
	adds r2, r4, r0
	adds r4, r2, #0
	adds r4, #0x14
	movs r0, #0
	strb r5, [r2]
	str r0, [r2, #4]
	strh r1, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #8]
	ldr r0, [r2, #0x14]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #0x14]
	ldrb r0, [r2]
	cmp r0, #0
	bne _08053070
	str r0, [r2, #0x10]
	b _08053076
_08053070:
	cmp r0, #1
	bne _08053076
	str r3, [r2, #0x10]
_08053076:
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2, #8]
	str r1, [r2, #0xc]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	movs r0, #1
	strb r0, [r2, #1]
_08053086:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805308c
FUN_0805308c: @ 0x0805308C
	ldr r1, _08053094 @ =0x03000120
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08053094: .4byte 0x03000120

	thumb_func_start FUN_08053098
FUN_08053098: @ 0x08053098
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r5, r3, #0
	cmp r1, #8
	bls _080530A6
	b _0805321A
_080530A6:
	lsls r0, r1, #2
	ldr r1, _080530B0 @ =_080530B4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080530B0: .4byte _080530B4
_080530B4: @ jump table
	.4byte _080530D8 @ case 0
	.4byte _0805311E @ case 1
	.4byte _08053104 @ case 2
	.4byte _08053146 @ case 3
	.4byte _08053170 @ case 4
	.4byte _08053196 @ case 5
	.4byte _080531BC @ case 6
	.4byte _080531D8 @ case 7
	.4byte _080531F4 @ case 8
_080530D8:
	movs r2, #0
	str r2, [r4, #0x28]
	ldr r0, [r4, #0x24]
	adds r1, r4, #0
	adds r1, #0x30
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #1
	bl FUN_080da9c4
	str r0, [r4, #0x24]
	ldr r0, _08053100 @ =0x000001B1
	bl PlaySound_082406e0
	b _0805321A
	.align 2, 0
_08053100: .4byte 0x000001B1
_08053104:
	movs r2, #0
	str r2, [r4, #0x28]
	ldr r0, [r4, #0x24]
	adds r1, r4, #0
	adds r1, #0x30
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #0
	b _08053136
_0805311E:
	movs r2, #0
	str r2, [r4, #0x28]
	ldr r0, [r4, #0x24]
	adds r1, r4, #0
	adds r1, #0x30
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #3
_08053136:
	bl FUN_080da9c4
	str r0, [r4, #0x24]
	movs r0, #0xf6
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0805321A
_08053146:
	movs r2, #0
	str r2, [r4, #0x28]
	ldr r0, [r4, #0x24]
	adds r1, r4, #0
	adds r1, #0x30
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #2
	bl FUN_080da9c4
	str r0, [r4, #0x24]
	ldr r0, _0805316C @ =0x000001ED
	bl PlaySound_082406e0
	b _0805321A
	.align 2, 0
_0805316C: .4byte 0x000001ED
_08053170:
	movs r0, #1
	str r0, [r4, #0x28]
	movs r3, #0
	strh r2, [r4, #0x2c]
	strh r5, [r4, #0x2e]
	ldr r0, [r4, #0x24]
	adds r1, r4, #0
	adds r1, #0x30
	adds r2, r4, #0
	adds r2, #0x2c
	str r2, [sp]
	movs r5, #0x2e
	ldrsh r2, [r4, r5]
	str r2, [sp, #4]
	str r3, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #1
	b _08053214
_08053196:
	movs r0, #3
	str r0, [r4, #0x28]
	movs r3, #0
	strh r2, [r4, #0x2c]
	strh r5, [r4, #0x2e]
	ldr r0, [r4, #0x24]
	adds r1, r4, #0
	adds r1, #0x30
	adds r2, r4, #0
	adds r2, #0x2c
	str r2, [sp]
	movs r5, #0x2e
	ldrsh r2, [r4, r5]
	str r2, [sp, #4]
	str r3, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #3
	b _08053214
_080531BC:
	movs r0, #5
	str r0, [r4, #0x28]
	ldr r0, [r4, #0x24]
	adds r1, r4, #0
	adds r1, #0x30
	movs r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #5
	movs r3, #0
	b _08053214
_080531D8:
	movs r0, #4
	str r0, [r4, #0x28]
	ldr r0, [r4, #0x24]
	adds r1, r4, #0
	adds r1, #0x30
	movs r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #4
	movs r3, #0
	b _08053214
_080531F4:
	ldr r3, [r4, #0x24]
	cmp r3, #0
	beq _0805321A
	adds r1, r4, #0
	adds r1, #0x30
	ldr r2, [r4, #0x28]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	movs r0, #0x64
	str r0, [sp, #0xc]
	adds r0, r3, #0
	movs r3, #0x7f
_08053214:
	bl FUN_080da9c4
	str r0, [r4, #0x24]
_0805321A:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08053224
FUN_08053224: @ 0x08053224
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r7, r1, #0
	adds r6, r2, #0
	adds r5, r4, #0
	adds r5, #0x7c
	ldr r0, [r4, #0x7c]
	cmp r0, #1
	bne _0805324C
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bls _08053246
	adds r1, r0, #0
	movs r0, #3
	subs r2, r0, r1
	b _08053262
_08053246:
	ldrb r2, [r4, #0x10]
	movs r3, #0
	b _08053264
_0805324C:
	ldrb r1, [r4, #0x10]
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r2, #0
	cmp r0, #1
	bhi _0805325C
	adds r2, r3, #0
_0805325C:
	movs r3, #0
	cmp r1, #1
	bls _08053264
_08053262:
	movs r3, #1
_08053264:
	str r6, [sp]
	ldr r0, [sp, #0x20]
	str r0, [sp, #4]
	ldr r0, [sp, #0x24]
	str r0, [sp, #8]
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_08055b5c
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08053280
FUN_08053280: @ 0x08053280
	push {r4, r5, lr}
	sub sp, #0xc
	adds r3, r0, #0
	adds r5, r1, #0
	adds r1, r2, #0
	adds r4, r3, #0
	adds r4, #0x7c
	ldr r0, [r3, #0x7c]
	cmp r0, #1
	bne _0805329E
	ldrb r2, [r3, #0x10]
	movs r3, #0
	cmp r2, #1
	bls _080532AA
	b _080532A8
_0805329E:
	movs r2, #0
	ldrb r0, [r3, #0x10]
	movs r3, #0
	cmp r0, #1
	bls _080532AA
_080532A8:
	movs r3, #1
_080532AA:
	str r1, [sp]
	ldr r0, [sp, #0x18]
	str r0, [sp, #4]
	ldr r0, [sp, #0x1c]
	str r0, [sp, #8]
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08055b5c
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080532c4
FUN_080532c4: @ 0x080532C4
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r7, r1, #0
	adds r6, r2, #0
	adds r5, r3, #0
	ldr r0, [r4, #0x7c]
	cmp r0, #1
	bne _080532EC
	ldrb r0, [r4, #0x11]
	cmp r0, #4
	bls _080532E6
	adds r1, r0, #0
	movs r0, #8
	subs r2, r0, r1
	movs r3, #1
	b _08053308
_080532E6:
	ldrb r2, [r4, #0x11]
	movs r3, #0
	b _08053308
_080532EC:
	ldrb r0, [r4, #0x11]
	cmp r0, #4
	bls _080532FC
	adds r1, r0, #0
	movs r0, #8
	subs r2, r0, r1
	movs r3, #1
	b _08053302
_080532FC:
	ldrb r2, [r4, #0x11]
	movs r3, #0
	adds r1, r2, #0
_08053302:
	adds r0, r1, #0
	muls r0, r5, r0
	strb r0, [r4, #0x11]
_08053308:
	adds r0, r4, #0
	adds r0, #0x7c
	str r6, [sp]
	ldr r1, [sp, #0x20]
	str r1, [sp, #4]
	ldr r1, [sp, #0x24]
	str r1, [sp, #8]
	adds r1, r7, #0
	bl FUN_08055b5c
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08053324
FUN_08053324: @ 0x08053324
	push {r4, lr}
	sub sp, #0xc
	ldr r3, [sp, #0x14]
	ldr r4, [sp, #0x18]
	adds r0, #0x7c
	str r2, [sp]
	str r3, [sp, #4]
	str r4, [sp, #8]
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	add sp, #0xc
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08053344
FUN_08053344: @ 0x08053344
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r3, #0
	ldr r7, [sp, #0x1c]
	str r2, [r4, #0x20]
	cmp r2, #3
	bgt _0805337E
	ldr r0, [r4]
	cmp r0, #0
	bne _08053368
	adds r0, r6, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _08053368
	adds r2, #0xa
_08053368:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	ldrh r2, [r0, #2]
	movs r3, #1
	ldrsb r3, [r0, r3]
	b _0805338C
_0805337E:
	subs r0, r2, #4
	ldr r1, _080533A4 @ =0x085AB924
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	ldrh r2, [r0, #2]
	ldrb r3, [r0, #1]
_0805338C:
	cmp r1, #1
	bne _080533A8
	str r7, [sp]
	ldr r0, [sp, #0x20]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r2, #0
	adds r2, r5, #0
	bl FUN_08053280
	b _080533E4
	.align 2, 0
_080533A4: .4byte 0x085AB924
_080533A8:
	cmp r1, #2
	bne _080533BE
	str r7, [sp]
	ldr r1, [sp, #0x20]
	str r1, [sp, #4]
	adds r0, r4, #0
	adds r1, r2, #0
	adds r2, r5, #0
	bl FUN_08053224
	b _080533E4
_080533BE:
	cmp r1, #3
	bne _080533D4
	str r7, [sp]
	ldr r0, [sp, #0x20]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r2, #0
	adds r2, r5, #0
	bl FUN_080532c4
	b _080533E4
_080533D4:
	str r7, [sp]
	ldr r1, [sp, #0x20]
	str r1, [sp, #4]
	adds r0, r4, #0
	adds r1, r2, #0
	adds r2, r5, #0
	bl FUN_08053324
_080533E4:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080533ec
FUN_080533ec: @ 0x080533EC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	adds r7, r1, #0
	adds r1, r3, #0
	ldr r5, [sp, #0x24]
	ldr r3, [sp, #0x28]
	adds r4, r7, #0
	adds r4, #0x7c
	cmp r2, #2
	bne _0805342E
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_08055e34
	adds r5, r0, #0
	adds r0, r7, #0
	adds r0, #0xa8
	ldr r1, [r7]
	cmp r1, #2
	bne _08053422
	movs r1, #0x27
	bl FUN_0822f63c
	b _0805344E
_08053422:
	cmp r1, #1
	bne _0805344E
	movs r1, #0x26
	bl FUN_0822f63c
	b _0805344E
_0805342E:
	str r3, [sp]
	adds r0, r4, #0
	ldr r2, [sp, #0x20]
	adds r3, r5, #0
	bl FUN_08055dac
	adds r5, r0, #0
	adds r1, r7, #0
	adds r1, #0x88
	ldr r0, [r7]
	cmp r0, #2
	bne _0805344E
	adds r0, r1, #0
	movs r1, #0x27
	bl FUN_0822b20c
_0805344E:
	cmp r5, #0
	bge _08053458
	movs r0, #1
	rsbs r0, r0, #0
	b _080534CC
_08053458:
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08055f5c
	movs r0, #0xc0
	movs r1, #0
	strb r0, [r7, #0xf]
	movs r0, #1
	strb r0, [r7, #0x11]
	movs r0, #3
	mov r8, r0
	movs r0, #0
	strb r0, [r7, #0x10]
	str r1, [sp]
	str r1, [sp, #4]
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #3
	movs r3, #1
	bl FUN_08053344
	movs r1, #0x9e
	lsls r1, r1, #1
	adds r4, r7, r1
	movs r2, #0x84
	lsls r2, r2, #1
	adds r5, r7, r2
	ldr r1, [r5]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0801385c
	adds r0, r4, #0
	bl FUN_08013698
	movs r0, #0x88
	lsls r0, r0, #1
	adds r4, r7, r0
	ldr r2, _080534D8 @ =0x000017EC
	adds r1, r6, r2
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822a470
	movs r1, #7
	strh r1, [r4, #0x10]
	ldr r2, _080534DC @ =0x00000117
	adds r1, r7, r2
	mov r2, r8
	strb r2, [r1]
	movs r1, #0x96
	lsls r1, r1, #1
	adds r3, r7, r1
	ldr r1, [r5]
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [r3]
	str r2, [r3, #4]
_080534CC:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080534D8: .4byte 0x000017EC
_080534DC: .4byte 0x00000117

	thumb_func_start FUN_080534e0
FUN_080534e0: @ 0x080534E0
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x28]
	adds r0, r0, r1
	str r0, [r2, #0x28]
	cmp r0, #0
	bge _080534F4
	movs r0, #0
	str r0, [r2, #0x28]
	b _080534FE
_080534F4:
	movs r1, #0xfa
	lsls r1, r1, #2
	cmp r0, r1
	ble _080534FE
	str r1, [r2, #0x28]
_080534FE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08053504
FUN_08053504: @ 0x08053504
	push {lr}
	adds r0, #0x44
	ldrh r0, [r0]
	cmp r0, #1
	beq _08053518
	cmp r0, #1
	ble _08053522
	cmp r0, #2
	beq _0805351C
	b _08053522
_08053518:
	movs r0, #0x80
	b _08053524
_0805351C:
	movs r0, #0xa0
	lsls r0, r0, #1
	b _08053524
_08053522:
	movs r0, #0x40
_08053524:
	pop {r1}
	bx r1

	thumb_func_start FUN_08053528
FUN_08053528: @ 0x08053528
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	cmp r3, #0
	beq _08053540
	adds r3, r4, #0
	adds r3, #0x33
	movs r1, #0
	movs r0, #1
	strb r0, [r3]
	str r1, [r4, #0x34]
	str r5, [r4, #0x38]
_08053540:
	adds r0, r5, #0
	muls r0, r2, r0
	cmp r0, #0
	blt _0805354C
	asrs r1, r0, #6
	b _08053552
_0805354C:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r1, r0, #0
_08053552:
	ldr r0, [r4, #0x3c]
	adds r0, r0, r1
	str r0, [r4, #0x3c]
	ldr r1, _08053564 @ =0x0000270F
	cmp r0, r1
	ble _08053568
	str r1, [r4, #0x3c]
	b _08053570
	.align 2, 0
_08053564: .4byte 0x0000270F
_08053568:
	cmp r0, #0
	bge _08053570
	movs r0, #0
	str r0, [r4, #0x3c]
_08053570:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08053578
FUN_08053578: @ 0x08053578
	push {lr}
	adds r1, r0, #0
	ldr r0, [r1, #0x50]
	adds r0, #1
	str r0, [r1, #0x50]
	ldr r2, _08053598 @ =0x000003E7
	cmp r0, r2
	bls _0805358A
	str r2, [r1, #0x3c]
_0805358A:
	ldr r2, [r1, #0x50]
	ldr r0, [r1, #0x54]
	cmp r2, r0
	bls _08053594
	str r2, [r1, #0x54]
_08053594:
	pop {r0}
	bx r0
	.align 2, 0
_08053598: .4byte 0x000003E7

	thumb_func_start FUN_0805359c
FUN_0805359c: @ 0x0805359C
	movs r1, #0
	str r1, [r0, #0x50]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080535a4
FUN_080535a4: @ 0x080535A4
	str r1, [r0, #0x74]
	bx lr

	thumb_func_start FUN_080535a8
FUN_080535a8: @ 0x080535A8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r7, r1, #0
	ldr r4, [sp, #0x18]
	movs r6, #0
	strb r6, [r7, #1]
	ldr r0, [r0, #0x2c]
	asrs r1, r0, #2
	adds r2, r2, r1
	strb r2, [r7, #2]
	strb r3, [r7, #3]
	asrs r0, r0, #1
	adds r0, #0x13
	strh r0, [r7, #4]
	strh r6, [r7, #6]
	str r4, [r7, #8]
	str r6, [r7, #0xc]
	movs r0, #0x20
	str r0, [r7, #0x10]
	adds r5, r7, #0
	adds r5, #0x1c
	ldr r0, _08053628 @ =0x085AB954
	lsls r4, r4, #1
	adds r4, r4, r0
	ldrh r1, [r4]
	adds r0, r5, #0
	bl FUN_0822b16c
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0822a470
	ldr r1, _0805362C @ =0x085AB740
	ldrb r0, [r7, #3]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x54
	strh r1, [r0]
	adds r1, r7, #0
	adds r1, #0x56
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1]
	adds r1, #2
	ldr r0, _08053630 @ =0x000008FC
	strh r0, [r1]
	str r6, [r7, #0x74]
	movs r0, #1
	strb r0, [r7]
	mov r1, r8
	ldr r0, [r1, #0x4c]
	adds r0, #1
	str r0, [r1, #0x4c]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08053628: .4byte 0x085AB954
_0805362C: .4byte 0x085AB740
_08053630: .4byte 0x000008FC

	thumb_func_start FUN_08053634
FUN_08053634: @ 0x08053634
	push {r4, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	adds r0, #0x38
	bl FUN_0822a4e0
	movs r0, #0
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805364c
FUN_0805364c: @ 0x0805364C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r0, #0
	adds r5, r1, #0
	adds r7, r5, #0
	adds r7, #0x38
	ldrb r0, [r5, #1]
	cmp r0, #0
	beq _080536B0
	ldr r2, _080536A4 @ =0xFFFF0000
	movs r0, #0
	str r0, [sp, #8]
	ldrh r1, [r5, #4]
	lsrs r1, r1, #1
	ldr r0, [sp, #0xc]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r1, _080536A8 @ =0x00001004
	adds r2, r5, #0
	adds r2, #0x54
	movs r0, #0x20
	str r0, [sp]
	movs r0, #0xfa
	str r0, [sp, #4]
	movs r0, #0
	add r3, sp, #8
	bl FUN_080607ec
	adds r0, r6, #0
	bl FUN_0805359c
	adds r0, r6, #0
	movs r1, #0x64
	bl FUN_080534e0
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_08053634
	ldr r0, _080536AC @ =0x00000195
	bl PlaySound_082406e0
	b _080537D4
	.align 2, 0
_080536A4: .4byte 0xFFFF0000
_080536A8: .4byte 0x00001004
_080536AC: .4byte 0x00000195
_080536B0:
	movs r3, #1
	ldrh r1, [r5, #6]
	movs r0, #1
	orrs r0, r1
	strh r0, [r5, #6]
	ldrh r0, [r5, #4]
	ldrh r1, [r7, #0x20]
	adds r0, r0, r1
	strh r0, [r7, #0x20]
	lsls r0, r0, #0x10
	ldr r1, _08053700 @ =0x0F9F0000
	cmp r0, r1
	ble _08053704
	adds r0, r6, #0
	bl FUN_08053578
	ldr r0, [r6, #0x2c]
	movs r1, #0x10
	rsbs r1, r1, #0
	subs r1, r1, r0
	adds r0, r6, #0
	bl FUN_080534e0
	movs r4, #2
	ldrsb r4, [r5, r4]
	adds r0, r6, #0
	bl FUN_08053504
	adds r2, r0, #0
	adds r0, r6, #0
	adds r1, r4, #0
	movs r3, #0
	bl FUN_08053528
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_08053634
	b _080537D4
	.align 2, 0
_08053700: .4byte 0x0F9F0000
_08053704:
	adds r4, r5, #0
	adds r4, #0x64
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x64]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08053732
	ldr r0, [r5, #0x38]
	movs r1, #4
	orrs r0, r1
	b _0805373A
_08053732:
	ldr r0, [r5, #0x38]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0805373A:
	str r0, [r5, #0x38]
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
	beq _0805375E
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _08053766
_0805375E:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08053766:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0805379C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080537D4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080537A0
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08053796
	ldrb r0, [r4, #5]
_08053796:
	subs r0, #1
	strh r0, [r4, #8]
	b _080537B0
	.align 2, 0
_0805379C: .4byte 0x0000FFFF
_080537A0:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080537B0
	strh r1, [r4, #8]
_080537B0:
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
	bne _080537D4
	movs r0, #1
	strb r0, [r4, #7]
_080537D4:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080537dc
FUN_080537dc: @ 0x080537DC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	adds r7, r5, #0
	adds r7, #0x38
	ldrb r0, [r5, #1]
	cmp r0, #0
	beq _080537FC
	adds r0, r6, #0
	bl FUN_0805359c
	adds r0, r6, #0
	movs r1, #0x64
	bl FUN_080534e0
	b _08053840
_080537FC:
	ldrh r1, [r5, #6]
	movs r0, #1
	orrs r0, r1
	strh r0, [r5, #6]
	ldrh r0, [r5, #4]
	ldrh r1, [r7, #0x20]
	adds r0, r0, r1
	strh r0, [r7, #0x20]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	ldr r0, _0805384C @ =0x00000F9F
	cmp r1, r0
	ble _08053850
	adds r0, r6, #0
	bl FUN_08053578
	ldr r0, [r6, #0x2c]
	movs r1, #0x10
	rsbs r1, r1, #0
	subs r1, r1, r0
	adds r0, r6, #0
	bl FUN_080534e0
	movs r4, #2
	ldrsb r4, [r5, r4]
	adds r0, r6, #0
	bl FUN_08053504
	adds r2, r0, #0
	adds r0, r6, #0
	adds r1, r4, #0
	movs r3, #0
	bl FUN_08053528
_08053840:
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_08053634
	b _08053950
	.align 2, 0
_0805384C: .4byte 0x00000F9F
_08053850:
	ldr r0, _08053864 @ =0x00000BB8
	cmp r1, r0
	bgt _08053878
	ldr r0, [r5, #0xc]
	movs r1, #3
	ands r0, r1
	cmp r0, #1
	bhi _08053868
	ldrb r0, [r5, #0x14]
	b _0805386A
	.align 2, 0
_08053864: .4byte 0x00000BB8
_08053868:
	ldrb r0, [r5, #0x15]
_0805386A:
	strb r0, [r5, #3]
	ldr r0, _080538A8 @ =0x085AB740
	ldrb r1, [r5, #3]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	strh r0, [r7, #0x1c]
_08053878:
	adds r4, r5, #0
	adds r4, #0x64
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x64]
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
	cmp r1, r0
	beq _080538AC
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _080538B4
	.align 2, 0
_080538A8: .4byte 0x085AB740
_080538AC:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080538B4:
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
	beq _080538D8
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080538E0
_080538D8:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080538E0:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08053918 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08053950
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0805391C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08053910
	ldrb r0, [r4, #5]
_08053910:
	subs r0, #1
	strh r0, [r4, #8]
	b _0805392C
	.align 2, 0
_08053918: .4byte 0x0000FFFF
_0805391C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0805392C
	strh r1, [r4, #8]
_0805392C:
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
	bne _08053950
	movs r0, #1
	strb r0, [r4, #7]
_08053950:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08053958
FUN_08053958: @ 0x08053958
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r5, r1, #0
	adds r7, r5, #0
	adds r7, #0x38
	ldrb r0, [r5, #1]
	cmp r0, #0
	beq _0805397A
	adds r0, r6, #0
	bl FUN_0805359c
	adds r0, r6, #0
	movs r1, #0x64
	bl FUN_080534e0
	b _080539E6
_0805397A:
	ldrh r0, [r5, #6]
	movs r1, #1
	orrs r1, r0
	strh r1, [r5, #6]
	ldr r0, [r5, #0xc]
	cmp r0, #0x40
	bne _080539A6
	adds r0, r5, #0
	adds r0, #0x64
	ldr r2, _080539F0 @ =0x000017E4
	adds r1, r6, r2
	ldr r1, [r1]
	movs r2, #1
	str r2, [sp]
	movs r2, #2
	movs r3, #1
	bl FUN_08236fac
	movs r0, #0xf2
	lsls r0, r0, #2
	bl PlaySound_082406e0
_080539A6:
	ldr r0, [r5, #0xc]
	cmp r0, #0x3f
	bls _080539F8
	ldrh r0, [r5, #4]
	ldrh r1, [r7, #0x20]
	adds r0, r0, r1
	strh r0, [r7, #0x20]
	lsls r0, r0, #0x10
	ldr r1, _080539F4 @ =0x0F9F0000
	cmp r0, r1
	ble _08053A38
	adds r0, r6, #0
	bl FUN_08053578
	ldr r0, [r6, #0x2c]
	movs r1, #0x10
	rsbs r1, r1, #0
	subs r1, r1, r0
	adds r0, r6, #0
	bl FUN_080534e0
	movs r4, #2
	ldrsb r4, [r5, r4]
	adds r0, r6, #0
	bl FUN_08053504
	adds r2, r0, #0
	adds r0, r6, #0
	adds r1, r4, #0
	movs r3, #0
	bl FUN_08053528
_080539E6:
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_08053634
	b _08053B10
	.align 2, 0
_080539F0: .4byte 0x000017E4
_080539F4: .4byte 0x0F9F0000
_080539F8:
	ldrh r0, [r5, #4]
	lsrs r0, r0, #1
	ldrh r2, [r7, #0x20]
	adds r0, r0, r2
	strh r0, [r7, #0x20]
	ldr r2, _08053A20 @ =0x085B0A08
	ldr r0, [r5, #0xc]
	lsls r0, r0, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	cmp r0, #0
	blt _08053A24
	asrs r2, r0, #0xc
	b _08053A2A
	.align 2, 0
_08053A20: .4byte 0x085B0A08
_08053A24:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08053A2A:
	ldr r0, _08053A68 @ =0x085AB740
	ldrb r1, [r5, #3]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
_08053A38:
	adds r4, r5, #0
	adds r4, #0x64
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x64]
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
	cmp r1, r0
	beq _08053A6C
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _08053A74
	.align 2, 0
_08053A68: .4byte 0x085AB740
_08053A6C:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08053A74:
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
	beq _08053A98
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _08053AA0
_08053A98:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08053AA0:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08053AD8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08053B10
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08053ADC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08053AD0
	ldrb r0, [r4, #5]
_08053AD0:
	subs r0, #1
	strh r0, [r4, #8]
	b _08053AEC
	.align 2, 0
_08053AD8: .4byte 0x0000FFFF
_08053ADC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08053AEC
	strh r1, [r4, #8]
_08053AEC:
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
	bne _08053B10
	movs r0, #1
	strb r0, [r4, #7]
_08053B10:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08053b18
FUN_08053b18: @ 0x08053B18
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08053B50 @ =0x000008DC
	adds r4, r5, r0
	movs r6, #0x1f
_08053B22:
	ldrb r0, [r4]
	cmp r0, #0
	beq _08053B40
	movs r0, #0
	strh r0, [r4, #6]
	ldr r2, [r4, #0x74]
	cmp r2, #0
	beq _08053B3A
	adds r0, r5, #0
	adds r1, r4, #0
	bl _call_via_r2
_08053B3A:
	ldr r0, [r4, #0xc]
	adds r0, #1
	str r0, [r4, #0xc]
_08053B40:
	subs r6, #1
	adds r4, #0x78
	cmp r6, #0
	bge _08053B22
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08053B50: .4byte 0x000008DC

	thumb_func_start FUN_08053b54
FUN_08053b54: @ 0x08053B54
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08053B7C @ =0x000008DC
	adds r4, r5, r0
	movs r6, #0x1f
_08053B5E:
	ldrb r0, [r4]
	cmp r0, #0
	beq _08053B6C
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08053634
_08053B6C:
	subs r6, #1
	adds r4, #0x78
	cmp r6, #0
	bge _08053B5E
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08053B7C: .4byte 0x000008DC

	thumb_func_start FUN_08053b80
FUN_08053b80: @ 0x08053B80
	push {lr}
	ldr r2, _08053B94 @ =0x000008DC
	adds r1, r0, r2
	movs r2, #0
_08053B88:
	ldrb r0, [r1]
	cmp r0, #0
	bne _08053B98
	adds r0, r1, #0
	b _08053BA2
	.align 2, 0
_08053B94: .4byte 0x000008DC
_08053B98:
	adds r2, #1
	adds r1, #0x78
	cmp r2, #0x1f
	ble _08053B88
	movs r0, #0
_08053BA2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08053ba8
FUN_08053ba8: @ 0x08053BA8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	bl FUN_08053b80
	adds r6, r0, #0
	cmp r6, #0
	beq _08053C02
	ldr r2, _08053C0C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08053C10 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08053C14 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	adds r3, r0, #0
	ldr r2, _08053C18 @ =0x00001E0C
	adds r0, r5, r2
	ldr r2, [r0]
	movs r4, #0
	str r4, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_080535a8
	adds r0, r6, #0
	adds r0, #0x64
	ldr r2, _08053C1C @ =0x000017DC
	adds r1, r5, r2
	ldr r1, [r1]
	str r4, [sp]
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
	ldr r1, _08053C20 @ =FUN_0805364c
	adds r0, r6, #0
	bl FUN_080535a4
_08053C02:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08053C0C: .4byte 0x030046B8
_08053C10: .4byte 0x000003FF
_08053C14: .4byte 0x0203B400
_08053C18: .4byte 0x00001E0C
_08053C1C: .4byte 0x000017DC
_08053C20: .4byte FUN_0805364c

	thumb_func_start FUN_08053c24
FUN_08053c24: @ 0x08053C24
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	bl FUN_08053b80
	adds r5, r0, #0
	cmp r5, #0
	beq _08053C9A
	ldr r2, _08053CA4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08053CA8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08053CAC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	adds r3, r0, #0
	ldr r2, _08053CB0 @ =0x00001E10
	adds r0, r6, r2
	ldr r2, [r0]
	movs r4, #1
	str r4, [sp]
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_080535a8
	adds r0, r5, #0
	adds r0, #0x1c
	ldr r1, _08053CB4 @ =0x00000269
	bl FUN_0822b20c
	adds r0, r5, #0
	adds r0, #0x64
	movs r2, #0xbf
	lsls r2, r2, #5
	adds r1, r6, r2
	ldr r1, [r1]
	str r4, [sp]
	movs r2, #0
	movs r3, #1
	bl FUN_08236fac
	ldrb r0, [r5, #3]
	strb r0, [r5, #0x14]
	ldrb r0, [r5, #3]
	adds r0, #2
	movs r1, #3
	bl Mod
	strb r0, [r5, #0x15]
	ldr r1, _08053CB8 @ =FUN_080537dc
	adds r0, r5, #0
	bl FUN_080535a4
_08053C9A:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08053CA4: .4byte 0x030046B8
_08053CA8: .4byte 0x000003FF
_08053CAC: .4byte 0x0203B400
_08053CB0: .4byte 0x00001E10
_08053CB4: .4byte 0x00000269
_08053CB8: .4byte FUN_080537dc

	thumb_func_start FUN_08053cbc
FUN_08053cbc: @ 0x08053CBC
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	bl FUN_08053b80
	adds r4, r0, #0
	cmp r4, #0
	beq _08053D22
	ldr r2, _08053D2C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08053D30 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08053D34 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	adds r3, r0, #0
	ldr r2, _08053D38 @ =0x00001E14
	adds r0, r5, r2
	ldr r2, [r0]
	movs r0, #2
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080535a8
	adds r1, r4, #0
	adds r1, #0x56
	movs r0, #0xa0
	lsls r0, r0, #1
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x64
	ldr r2, _08053D3C @ =0x000017E4
	adds r1, r5, r2
	ldr r1, [r1]
	movs r2, #1
	str r2, [sp]
	movs r2, #0
	movs r3, #3
	bl FUN_08236fac
	ldr r1, _08053D40 @ =FUN_08053958
	adds r0, r4, #0
	bl FUN_080535a4
_08053D22:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08053D2C: .4byte 0x030046B8
_08053D30: .4byte 0x000003FF
_08053D34: .4byte 0x0203B400
_08053D38: .4byte 0x00001E14
_08053D3C: .4byte 0x000017E4
_08053D40: .4byte FUN_08053958

	thumb_func_start FUN_08053d44
FUN_08053d44: @ 0x08053D44
	push {r4, r5, r6, r7, lr}
	adds r3, r1, #0
	mov ip, r2
	adds r1, #0x78
	movs r4, #0
	ldrsh r2, [r1, r4]
	ldr r1, [r3, #0x14]
	subs r6, r2, r1
	adds r5, r2, r1
	ldr r7, _08053D98 @ =0x000008DC
	adds r1, r0, r7
	movs r2, #0
	movs r4, #1
_08053D5E:
	ldrh r0, [r1, #6]
	ands r0, r4
	cmp r0, #0
	beq _08053D9C
	ldrb r0, [r1, #3]
	ldrb r7, [r3, #8]
	cmp r0, r7
	bne _08053D9C
	adds r0, r1, #0
	adds r0, #0x58
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, r6
	blt _08053D9C
	cmp r0, r5
	bgt _08053D9C
	mov r0, ip
	cmp r0, #0
	bne _08053D86
	strb r4, [r1, #1]
_08053D86:
	ldr r0, [r1, #8]
	cmp r0, #1
	beq _08053D94
	cmp r0, #1
	blo _08053D94
	cmp r0, #2
	bne _08053D9C
_08053D94:
	movs r0, #1
	b _08053DA6
	.align 2, 0
_08053D98: .4byte 0x000008DC
_08053D9C:
	adds r2, #1
	adds r1, #0x78
	cmp r2, #0x1f
	ble _08053D5E
	movs r0, #0
_08053DA6:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08053dac
FUN_08053dac: @ 0x08053DAC
	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #0xe]
	cmp r0, #0
	beq _08053DBA
	movs r0, #0
	strb r0, [r2, #0xe]
_08053DBA:
	ldrb r0, [r2, #0xa]
	movs r1, #1
	orrs r1, r0
	strb r1, [r2, #0xa]
	ldr r0, [r2, #0x1c]
	adds r0, #1
	str r0, [r2, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start FUN_08053dcc
FUN_08053dcc: @ 0x08053DCC
	push {r4, lr}
	sub sp, #8
	adds r2, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08053DEC
	movs r0, #0
	strb r0, [r4, #0xe]
	str r0, [sp]
	str r0, [sp, #4]
	adds r0, r2, #0
	movs r2, #0
	movs r3, #1
	bl FUN_08053344
_08053DEC:
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08053dfc
FUN_08053dfc: @ 0x08053DFC
	push {r4, lr}
	sub sp, #8
	adds r2, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08053E1C
	movs r0, #0
	strb r0, [r4, #0xe]
	str r0, [sp]
	str r0, [sp, #4]
	adds r0, r2, #0
	movs r2, #1
	movs r3, #1
	bl FUN_08053344
_08053E1C:
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08053e2c
FUN_08053e2c: @ 0x08053E2C
	push {r4, lr}
	sub sp, #8
	adds r2, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08053E56
	movs r1, #0
	strb r1, [r4, #0xe]
	ldr r0, [r4, #0x20]
	cmp r0, #3
	beq _08053E56
	str r1, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r2, #0
	adds r1, r4, #0
	movs r2, #3
	movs r3, #1
	bl FUN_08053344
_08053E56:
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08053e64
FUN_08053e64: @ 0x08053E64
	push {r4, r5, lr}
	sub sp, #8
	adds r2, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08053E8E
	movs r1, #0
	strb r1, [r4, #0xe]
	ldr r0, [r4, #0x20]
	cmp r0, #3
	beq _08053E8E
	str r1, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r2, #0
	adds r1, r4, #0
	movs r2, #3
	movs r3, #1
	bl FUN_08053344
_08053E8E:
	ldr r0, [r4, #0x1c]
	cmp r0, #0xf
	bhi _08053ECA
	ldr r2, _08053EB0 @ =0x085B0A08
	lsls r0, r0, #3
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0xa4
	muls r0, r1, r0
	cmp r0, #0
	blt _08053EB4
	asrs r0, r0, #0xc
	b _08053EBA
	.align 2, 0
_08053EB0: .4byte 0x085B0A08
_08053EB4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08053EBA:
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r0, r3
	adds r0, r4, #0
	adds r0, #0x76
	strh r1, [r0]
	adds r3, r0, #0
	b _08053ED8
_08053ECA:
	adds r1, r4, #0
	adds r1, #0x76
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r2, _08053EF4 @ =0x085B0A08
	adds r3, r1, #0
_08053ED8:
	ldr r0, [r4, #0x1c]
	lsls r0, r0, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	cmp r0, #0
	blt _08053EF8
	asrs r0, r0, #0xc
	b _08053EFE
	.align 2, 0
_08053EF4: .4byte 0x085B0A08
_08053EF8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08053EFE:
	ldr r1, _08053F34 @ =0x00000DAC
	adds r5, r1, #0
	subs r0, r5, r0
	adds r2, r4, #0
	adds r2, #0x78
	strh r0, [r2]
	ldr r0, [r4, #0x1c]
	subs r0, #0xe
	cmp r0, #5
	bhi _08053F1A
	ldrb r1, [r4, #0xa]
	movs r0, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
_08053F1A:
	ldr r0, [r4, #0x1c]
	cmp r0, #0x1f
	bls _08053F38
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r3]
	strh r5, [r2]
	movs r0, #3
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	movs r0, #0
	b _08053F3A
	.align 2, 0
_08053F34: .4byte 0x00000DAC
_08053F38:
	adds r0, #1
_08053F3A:
	str r0, [r4, #0x1c]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08053f44
FUN_08053f44: @ 0x08053F44
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r2, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08053F72
	movs r1, #0
	strb r1, [r4, #0xe]
	ldr r0, [r4, #0x20]
	cmp r0, #3
	beq _08053F6E
	str r1, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r2, #0
	adds r1, r4, #0
	movs r2, #3
	movs r3, #1
	bl FUN_08053344
_08053F6E:
	ldrb r0, [r4, #9]
	strb r0, [r4, #8]
_08053F72:
	adds r5, r4, #0
	adds r5, #0x74
	movs r0, #0
	ldrsh r2, [r5, r0]
	ldr r1, _08053FA4 @ =0x085AB740
	ldrb r0, [r4, #8]
	lsls r0, r0, #1
	adds r3, r0, r1
	movs r1, #0
	ldrsh r0, [r3, r1]
	subs r2, r2, r0
	cmp r2, #0
	bge _08053F8E
	rsbs r2, r2, #0
_08053F8E:
	cmp r2, #0xc
	bgt _08053FA8
	ldrh r0, [r3]
	movs r1, #0
	strh r0, [r5]
	movs r0, #3
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	str r1, [r4, #0x1c]
	b _08053FC8
	.align 2, 0
_08053FA4: .4byte 0x085AB740
_08053FA8:
	ldrh r2, [r5]
	movs r6, #0
	ldrsh r1, [r5, r6]
	movs r6, #0
	ldrsh r0, [r3, r6]
	cmp r1, r0
	bge _08053FBC
	adds r0, r2, #0
	adds r0, #0xc
	b _08053FC0
_08053FBC:
	adds r0, r2, #0
	subs r0, #0xc
_08053FC0:
	strh r0, [r5]
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
_08053FC8:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08053fd0
FUN_08053fd0: @ 0x08053FD0
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08054002
	movs r1, #0
	strb r1, [r4, #0xe]
	adds r2, r5, #0
	adds r2, #0x32
	movs r0, #1
	strb r0, [r2]
	str r1, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #4
	movs r3, #2
	bl FUN_08053344
	ldr r0, _08054030 @ =0x00000322
	bl PlaySound_082406e0
_08054002:
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_08055d20
	cmp r0, #0
	beq _08054046
	ldr r1, [r5, #0x24]
	ldr r0, _08054034 @ =0x000003E7
	cmp r1, r0
	ble _08054038
	movs r0, #7
	movs r1, #0
	strb r0, [r4, #0xd]
	movs r2, #1
	strb r2, [r4, #0xe]
	str r1, [r4, #0x1c]
	adds r0, r5, #0
	adds r0, #0x30
	strb r1, [r0]
	adds r0, #0x16
	strh r2, [r0]
	b _0805404C
	.align 2, 0
_08054030: .4byte 0x00000322
_08054034: .4byte 0x000003E7
_08054038:
	movs r0, #3
	movs r1, #0
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	str r1, [r4, #0x1c]
	b _0805404C
_08054046:
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
_0805404C:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08054054
FUN_08054054: @ 0x08054054
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r6, r0, #0
	adds r5, r1, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _080540A2
	movs r4, #0
	strb r4, [r5, #0xe]
	str r4, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	movs r2, #0xf
	movs r3, #2
	bl FUN_08053344
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	movs r0, #0xa
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	str r4, [sp, #0x10]
	movs r0, #0x14
	str r0, [sp, #0x14]
	movs r0, #0x10
	str r0, [sp, #0x18]
	movs r0, #7
	movs r1, #0x1a
	movs r3, #0
	bl FUN_080149dc
_080540A2:
	ldr r0, [r6, #0x28]
	adds r0, #0x18
	str r0, [r6, #0x28]
	str r0, [r6, #0x24]
	adds r0, r5, #0
	adds r0, #0x7c
	bl FUN_08055d20
	cmp r0, #0
	beq _080540C4
	movs r0, #3
	movs r1, #0
	strb r0, [r5, #0xd]
	movs r0, #1
	strb r0, [r5, #0xe]
	str r1, [r5, #0x1c]
	b _080540CA
_080540C4:
	ldr r0, [r5, #0x1c]
	adds r0, #1
	str r0, [r5, #0x1c]
_080540CA:
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080540d4
FUN_080540d4: @ 0x080540D4
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080540F6
	movs r0, #0
	strb r0, [r4, #0xe]
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r2, #5
	movs r3, #2
	bl FUN_08053344
_080540F6:
	ldr r0, [r4, #0x1c]
	cmp r0, #0x1e
	bne _08054102
	ldr r0, _0805412C @ =0x00000321
	bl PlaySound_082406e0
_08054102:
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_08055d20
	cmp r0, #0
	beq _0805411E
	ldr r0, [r5, #0x1c]
	cmp r0, #0
	beq _0805411E
	movs r1, #0
	bl Script_ExecById
	movs r0, #0
	str r0, [r5, #0x1c]
_0805411E:
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805412C: .4byte 0x00000321

	thumb_func_start FUN_08054130
FUN_08054130: @ 0x08054130
	push {r4, lr}
	sub sp, #8
	adds r3, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08054160
	movs r1, #0
	strb r1, [r4, #0xe]
	adds r0, r3, #0
	adds r0, #0x32
	ldrb r0, [r0]
	movs r2, #6
	cmp r0, #0
	beq _08054150
	movs r2, #7
_08054150:
	str r1, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r3, #0
	adds r1, r4, #0
	movs r3, #2
	bl FUN_08053344
_08054160:
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08054170
FUN_08054170: @ 0x08054170
	push {r4, lr}
	sub sp, #8
	adds r2, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080541B8
	movs r1, #0
	strb r1, [r4, #0xe]
	adds r0, r2, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _080541A0
	str r1, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r2, #0
	adds r1, r4, #0
	movs r2, #8
	movs r3, #2
	bl FUN_08053344
	b _080541B2
_080541A0:
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r2, #0
	adds r1, r4, #0
	movs r2, #9
	movs r3, #2
	bl FUN_08053344
_080541B2:
	ldr r0, _080541C8 @ =0x0000031F
	bl PlaySound_082406e0
_080541B8:
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080541C8: .4byte 0x0000031F

	thumb_func_start FUN_080541cc
FUN_080541cc: @ 0x080541CC
	push {r4, lr}
	sub sp, #8
	adds r2, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080541EE
	movs r0, #0
	strb r0, [r4, #0xe]
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r2, #0
	movs r2, #0xa
	movs r3, #2
	bl FUN_08053344
_080541EE:
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080541fc
FUN_080541fc: @ 0x080541FC
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0805421E
	movs r0, #0
	strb r0, [r4, #0xe]
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	movs r2, #0
	movs r3, #2
	bl FUN_08053344
_0805421E:
	ldr r0, [r4, #0x1c]
	cmp r0, #0x20
	bne _08054282
	movs r5, #0
	ldr r0, [r4]
	subs r0, #2
	cmp r0, #4
	bhi _0805426E
	lsls r0, r0, #2
	ldr r1, _08054238 @ =_0805423C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08054238: .4byte _0805423C
_0805423C: @ jump table
	.4byte _08054250 @ case 0
	.4byte _08054260 @ case 1
	.4byte _08054264 @ case 2
	.4byte _08054268 @ case 3
	.4byte _0805426C @ case 4
_08054250:
	movs r5, #0xb
	ldr r0, _0805425C @ =0x000002E6
	bl PlaySound_082406e0
	b _0805426E
	.align 2, 0
_0805425C: .4byte 0x000002E6
_08054260:
	movs r5, #0xc
	b _0805426E
_08054264:
	movs r5, #0xd
	b _0805426E
_08054268:
	movs r5, #0xe
	b _0805426E
_0805426C:
	movs r5, #0
_0805426E:
	movs r0, #0
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	movs r3, #2
	bl FUN_08053344
_08054282:
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08054290
FUN_08054290: @ 0x08054290
	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #0xc]
	cmp r0, #0
	beq _080542A6
	movs r1, #0
	strb r1, [r2, #0xc]
	strb r1, [r2, #0xd]
	movs r0, #1
	strb r0, [r2, #0xe]
	str r1, [r2, #0x1c]
_080542A6:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080542ac
FUN_080542ac: @ 0x080542AC
	push {r4, r5, lr}
	adds r3, r1, #0
	movs r1, #0xf0
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r5, #1
	str r5, [r0]
	ldrb r0, [r3, #0xc]
	cmp r0, #0
	beq _080542E2
	movs r2, #0
	strb r2, [r3, #0xc]
	adds r1, r3, #0
	adds r1, #0x78
	movs r0, #0xfa
	lsls r0, r0, #4
	strh r0, [r1]
	movs r0, #2
	strb r0, [r3, #0xd]
	strb r5, [r3, #0xe]
	str r2, [r3, #0x1c]
	movs r0, #0xc0
	strb r0, [r3, #0xf]
	movs r0, #1
	strb r0, [r3, #0x11]
	movs r0, #0
	strb r0, [r3, #0x10]
_080542E2:
	adds r2, r3, #0
	adds r2, #0x78
	ldrh r1, [r2]
	movs r4, #0
	ldrsh r0, [r2, r4]
	ldr r4, _0805430C @ =0x00000DAC
	cmp r0, r4
	bgt _08054310
	movs r1, #0
	strh r4, [r2]
	movs r0, #2
	strb r0, [r3, #0xb]
	strb r5, [r3, #0xc]
	str r1, [r3, #0x18]
	adds r0, r3, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08053098
	b _08054314
	.align 2, 0
_0805430C: .4byte 0x00000DAC
_08054310:
	subs r0, r1, #4
	strh r0, [r2]
_08054314:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805431c
FUN_0805431c: @ 0x0805431C
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r1, #0xf0
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r2, #1
	str r2, [r0]
	ldrb r0, [r4, #0xc]
	cmp r0, #0
	beq _0805434A
	movs r1, #0
	strb r1, [r4, #0xc]
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	str r1, [r4, #0x1c]
	movs r0, #0xc0
	strb r0, [r4, #0xf]
	movs r0, #1
	strb r0, [r4, #0x11]
	movs r0, #0
	strb r0, [r4, #0x10]
_0805434A:
	adds r0, r5, #0
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #0
	beq _080543CA
	movs r2, #0
	ldr r0, [r5, #0x50]
	cmp r0, #0x1d
	bhi _08054368
	ldr r0, [r5, #0x18]
	movs r1, #0x3f
	ands r0, r1
	cmp r0, #0
	bne _08054374
	b _08054378
_08054368:
	ldr r0, [r5, #0x18]
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _08054374
	movs r2, #1
_08054374:
	cmp r2, #0
	beq _080543CA
_08054378:
	ldr r2, _080543A4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080543A8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080543AC @ =0x0203B400
	adds r0, r0, r1
	ldrb r1, [r0]
	ldr r0, [r5, #0x4c]
	cmp r0, #0x63
	bls _080543B8
	cmp r1, #0x65
	ble _080543BC
	cmp r1, #0xa9
	bgt _080543B0
	adds r0, r5, #0
	bl FUN_08053cbc
	b _080543CA
	.align 2, 0
_080543A4: .4byte 0x030046B8
_080543A8: .4byte 0x000003FF
_080543AC: .4byte 0x0203B400
_080543B0:
	adds r0, r5, #0
	bl FUN_08053c24
	b _080543CA
_080543B8:
	cmp r1, #0x7f
	bgt _080543C4
_080543BC:
	adds r0, r5, #0
	bl FUN_08053ba8
	b _080543CA
_080543C4:
	adds r0, r5, #0
	bl FUN_08053c24
_080543CA:
	ldrb r0, [r4, #0xd]
	cmp r0, #3
	bne _0805443E
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_08053d44
	adds r3, r0, #0
	cmp r3, #0
	beq _080543EE
	movs r0, #6
	movs r1, #0
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	str r1, [r4, #0x1c]
	b _0805443E
_080543EE:
	ldr r0, _08054400 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r5, #1
	movs r2, #1
	ands r2, r1
	cmp r2, #0
	beq _08054404
	movs r0, #4
	b _08054438
	.align 2, 0
_08054400: .4byte 0x030044E0
_08054404:
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq _08054424
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _0805441A
	subs r0, #1
	strb r0, [r4, #9]
_0805441A:
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
	str r2, [r4, #0x1c]
	b _0805443E
_08054424:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805443E
	ldrb r0, [r4, #8]
	cmp r0, #1
	bhi _08054436
	adds r0, #1
	strb r0, [r4, #9]
_08054436:
	movs r0, #5
_08054438:
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
	str r3, [r4, #0x1c]
_0805443E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08054444
FUN_08054444: @ 0x08054444
	push {r4, lr}
	adds r2, r1, #0
	movs r1, #0xf0
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r4, #1
	str r4, [r0]
	ldrb r0, [r2, #0xc]
	cmp r0, #0
	beq _08054468
	movs r0, #0
	strb r0, [r2, #0xc]
	movs r0, #0xc0
	strb r0, [r2, #0xf]
	movs r0, #1
	strb r0, [r2, #0x11]
	movs r0, #0
	strb r0, [r2, #0x10]
_08054468:
	ldrb r0, [r2, #0xd]
	cmp r0, #3
	bne _0805448A
	ldrb r3, [r2, #8]
	cmp r3, #1
	beq _08054480
	movs r1, #0
	strb r4, [r2, #9]
	movs r0, #5
	strb r0, [r2, #0xd]
	strb r4, [r2, #0xe]
	b _08054488
_08054480:
	movs r0, #2
	movs r1, #0
	strb r0, [r2, #0xd]
	strb r3, [r2, #0xe]
_08054488:
	str r1, [r2, #0x1c]
_0805448A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08054490
FUN_08054490: @ 0x08054490
	push {lr}
	adds r2, r1, #0
	movs r1, #0xf0
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r3, #1
	str r3, [r0]
	ldrb r0, [r2, #0xc]
	cmp r0, #0
	beq _080544B0
	movs r1, #0
	strb r1, [r2, #0xc]
	movs r0, #8
	strb r0, [r2, #0xd]
	strb r3, [r2, #0xe]
	str r1, [r2, #0x1c]
_080544B0:
	pop {r0}
	bx r0

	thumb_func_start FUN_080544b4
FUN_080544b4: @ 0x080544B4
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r3, r1, #0
	ldrb r0, [r3, #0xc]
	cmp r0, #0
	beq _080544DE
	movs r2, #0
	strb r2, [r3, #0xc]
	adds r1, #0x78
	ldr r0, _0805450C @ =0x000008FC
	strh r0, [r1]
	movs r0, #1
	strb r0, [r3, #0xd]
	strb r0, [r3, #0xe]
	str r2, [r3, #0x1c]
	movs r0, #0x40
	strb r0, [r3, #0xf]
	movs r0, #5
	strb r0, [r3, #0x11]
	movs r0, #2
	strb r0, [r3, #0x10]
_080544DE:
	adds r4, r3, #0
	adds r4, #0x78
	movs r0, #0
	ldrsh r2, [r4, r0]
	ldr r1, [r5, #0x24]
	ldr r0, _08054510 @ =0x00000CE4
	subs r1, r0, r1
	cmp r2, r1
	blt _08054514
	movs r0, #0
	strh r1, [r4]
	movs r1, #6
	strb r1, [r3, #0xb]
	movs r1, #1
	strb r1, [r3, #0xc]
	str r0, [r3, #0x18]
	adds r0, r3, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08053098
	b _0805451A
	.align 2, 0
_0805450C: .4byte 0x000008FC
_08054510: .4byte 0x00000CE4
_08054514:
	ldrh r0, [r4]
	adds r0, #6
	strh r0, [r4]
_0805451A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08054520
FUN_08054520: @ 0x08054520
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #0xc]
	cmp r0, #0
	beq _0805454C
	movs r1, #0
	strb r1, [r4, #0xc]
	movs r0, #3
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	str r1, [r4, #0x1c]
	movs r0, #0xc0
	strb r0, [r4, #0xf]
	movs r1, #1
	strb r1, [r4, #0x11]
	movs r0, #0
	strb r0, [r4, #0x10]
	adds r0, r5, #0
	adds r0, #0x30
	strb r1, [r0]
_0805454C:
	ldrb r0, [r4, #0xd]
	adds r6, r4, #0
	adds r6, #0x78
	cmp r0, #3
	bne _080545AE
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #2
	ldrb r0, [r0, #0xa]
	ands r0, r1
	cmp r0, #0
	beq _080545AE
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	ldrb r1, [r4, #8]
	cmp r0, r1
	bne _080545AE
	adds r2, #0x70
	adds r0, r5, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #0
	ldrsh r0, [r6, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _08054588
	rsbs r1, r1, #0
_08054588:
	cmp r1, #0x7f
	bgt _080545AE
	ldr r1, _080545C0 @ =0x00001E18
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	movs r2, #0x40
	movs r3, #1
	bl FUN_08053528
	movs r0, #6
	movs r1, #0
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	str r1, [r4, #0x1c]
	ldr r0, _080545C4 @ =0x0000028B
	bl PlaySound_082406e0
_080545AE:
	ldr r3, [r5, #0x28]
	ldr r1, [r5, #0x24]
	subs r2, r3, r1
	cmp r2, #3
	ble _080545C8
	adds r0, r1, #4
	str r0, [r5, #0x24]
	b _080545D8
	.align 2, 0
_080545C0: .4byte 0x00001E18
_080545C4: .4byte 0x0000028B
_080545C8:
	movs r0, #4
	rsbs r0, r0, #0
	cmp r2, r0
	bgt _080545D6
	subs r0, r1, #4
	str r0, [r5, #0x24]
	b _080545D8
_080545D6:
	str r3, [r5, #0x24]
_080545D8:
	ldr r0, [r5, #0x24]
	ldr r2, _080545F8 @ =0x00000CE4
	adds r1, r2, #0
	subs r1, r1, r0
	strh r1, [r6]
	ldr r1, _080545FC @ =0x000003E7
	cmp r0, r1
	ble _08054600
	movs r0, #7
	strb r0, [r4, #0xb]
	movs r0, #1
	strb r0, [r4, #0xc]
	movs r0, #0
	str r0, [r4, #0x18]
	b _08054668
	.align 2, 0
_080545F8: .4byte 0x00000CE4
_080545FC: .4byte 0x000003E7
_08054600:
	ldrb r0, [r4, #0xd]
	cmp r0, #3
	bne _08054668
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #1
	bl FUN_08053d44
	cmp r0, #0
	beq _08054668
	ldrb r0, [r4, #8]
	cmp r0, #1
	beq _0805462A
	cmp r0, #1
	bgt _08054624
	cmp r0, #0
	beq _08054658
	b _0805465C
_08054624:
	cmp r0, #2
	beq _08054658
	b _0805465C
_0805462A:
	ldr r2, _08054648 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805464C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08054650 @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _08054654
	movs r0, #0
	b _0805465A
	.align 2, 0
_08054648: .4byte 0x030046B8
_0805464C: .4byte 0x000003FF
_08054650: .4byte 0x0203B400
_08054654:
	movs r0, #2
	b _0805465A
_08054658:
	movs r0, #1
_0805465A:
	strb r0, [r4, #9]
_0805465C:
	movs r0, #5
	movs r1, #0
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	str r1, [r4, #0x1c]
_08054668:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08054670
FUN_08054670: @ 0x08054670
	push {lr}
	ldrb r0, [r1, #0xc]
	cmp r0, #0
	beq _0805467C
	movs r0, #0
	strb r0, [r1, #0xc]
_0805467C:
	adds r1, #0x78
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bgt _0805468C
	movs r0, #0
	b _08054690
_0805468C:
	adds r0, r2, #0
	subs r0, #0xc
_08054690:
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08054698
FUN_08054698: @ 0x08054698
	push {r4, lr}
	adds r3, r1, #0
	ldrb r0, [r3, #0xc]
	cmp r0, #0
	beq _080546C0
	movs r2, #0
	strb r2, [r3, #0xc]
	adds r1, #0x78
	ldr r0, _080546EC @ =0x000008FC
	strh r0, [r1]
	movs r0, #1
	strb r0, [r3, #0xd]
	strb r0, [r3, #0xe]
	str r2, [r3, #0x1c]
	movs r0, #0x40
	strb r0, [r3, #0xf]
	movs r0, #5
	strb r0, [r3, #0x11]
	movs r0, #2
	strb r0, [r3, #0x10]
_080546C0:
	adds r2, r3, #0
	adds r2, #0x78
	ldrh r4, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _080546F0 @ =0x00000A8B
	cmp r1, r0
	ble _080546F4
	movs r1, #0
	adds r0, #1
	strh r0, [r2]
	movs r0, #9
	strb r0, [r3, #0xb]
	movs r0, #1
	strb r0, [r3, #0xc]
	str r1, [r3, #0x18]
	adds r0, r3, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08053098
	b _080546F8
	.align 2, 0
_080546EC: .4byte 0x000008FC
_080546F0: .4byte 0x00000A8B
_080546F4:
	adds r0, r4, #4
	strh r0, [r2]
_080546F8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08054700
FUN_08054700: @ 0x08054700
	push {r4, lr}
	adds r2, r1, #0
	ldrb r0, [r2, #0xc]
	cmp r0, #0
	beq _08054718
	movs r0, #0
	strb r0, [r2, #0xc]
	movs r1, #3
	strb r1, [r2, #0xd]
	movs r1, #1
	strb r1, [r2, #0xe]
	str r0, [r2, #0x1c]
_08054718:
	adds r3, r2, #0
	adds r3, #0x78
	ldrh r4, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _0805473C @ =0x00000D47
	cmp r1, r0
	ble _08054740
	movs r1, #0
	adds r0, #1
	strh r0, [r3]
	movs r0, #0xa
	strb r0, [r2, #0xb]
	movs r0, #1
	strb r0, [r2, #0xc]
	str r1, [r2, #0x18]
	b _08054746
	.align 2, 0
_0805473C: .4byte 0x00000D47
_08054740:
	adds r0, r4, #0
	adds r0, #8
	strh r0, [r3]
_08054746:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805474c
FUN_0805474c: @ 0x0805474C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r1, #0xc]
	cmp r0, #0
	beq _0805479C
	movs r2, #0
	strb r2, [r1, #0xc]
	movs r0, #8
	strb r0, [r1, #0xd]
	movs r5, #1
	strb r5, [r1, #0xe]
	str r2, [r1, #0x1c]
	movs r0, #0x40
	strb r0, [r1, #0xf]
	movs r0, #5
	strb r0, [r1, #0x11]
	movs r3, #1
	movs r0, #2
	strb r0, [r1, #0x10]
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #4
	strb r1, [r0, #0xb]
	strb r3, [r0, #0xc]
	str r2, [r0, #0x18]
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	bne _0805479C
	ldr r1, _080547A4 @ =0x00001E1C
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	movs r2, #0x40
	movs r3, #1
	bl FUN_08053528
	str r5, [r4, #0x48]
_0805479C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080547A4: .4byte 0x00001E1C

	thumb_func_start FUN_080547a8
FUN_080547a8: @ 0x080547A8
	push {lr}
	mov ip, r1
	ldrb r0, [r1, #0xc]
	cmp r0, #0
	beq _080547E6
	movs r2, #0
	strb r2, [r1, #0xc]
	ldr r0, _080547EC @ =0x085AB740
	ldrh r0, [r0, #2]
	subs r0, #0xe0
	adds r1, #0x74
	movs r3, #0
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1]
	adds r1, #2
	ldr r0, _080547F0 @ =0x00000DCC
	strh r0, [r1]
	movs r0, #9
	mov r1, ip
	strb r0, [r1, #0xd]
	movs r0, #1
	strb r0, [r1, #0xe]
	str r2, [r1, #0x1c]
	strb r3, [r1, #0xf]
	movs r0, #3
	strb r0, [r1, #0x11]
	movs r0, #1
	strb r0, [r1, #0x10]
_080547E6:
	pop {r0}
	bx r0
	.align 2, 0
_080547EC: .4byte 0x085AB740
_080547F0: .4byte 0x00000DCC

	thumb_func_start FUN_080547f4
FUN_080547f4: @ 0x080547F4
	push {lr}
	adds r3, r1, #0
	ldrb r0, [r3, #0xc]
	cmp r0, #0
	beq _0805483C
	movs r2, #0
	strb r2, [r3, #0xc]
	ldr r0, _08054840 @ =0x085AB740
	ldrh r0, [r0, #2]
	adds r0, #0x20
	adds r1, #0x74
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1]
	adds r1, #2
	ldr r0, _08054844 @ =0x00000DCC
	strh r0, [r1]
	movs r0, #9
	strb r0, [r3, #0xd]
	movs r0, #1
	strb r0, [r3, #0xe]
	str r2, [r3, #0x1c]
	movs r0, #0xc0
	strb r0, [r3, #0xf]
	movs r0, #1
	strb r0, [r3, #0x11]
	movs r0, #0
	strb r0, [r3, #0x10]
	adds r0, r3, #0
	movs r1, #4
	movs r2, #0xb4
	movs r3, #0xb4
	bl FUN_08053098
_0805483C:
	pop {r0}
	bx r0
	.align 2, 0
_08054840: .4byte 0x085AB740
_08054844: .4byte 0x00000DCC

	thumb_func_start FUN_08054848
FUN_08054848: @ 0x08054848
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #0x1c
	mov sl, r0
	adds r4, r1, #0
	adds r1, r3, #0
	str r2, [r4]
	ldr r0, _0805491C @ =0x085AB748
	lsls r5, r2, #3
	subs r5, r5, r2
	lsls r5, r5, #3
	adds r5, r5, r0
	ldr r0, [r5]
	str r0, [r4, #4]
	movs r0, #0
	movs r2, #1
	mov r8, r2
	mov r2, r8
	strb r2, [r4, #8]
	strb r0, [r4, #0xa]
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	str r0, [r4, #0x1c]
	ldr r0, _08054920 @ =0x085AB740
	ldr r6, _08054924 @ =0xFFFF0000
	ldrh r0, [r0, #2]
	movs r2, #0x80
	lsls r2, r2, #0x11
	orrs r0, r2
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r6
	ldr r2, _08054928 @ =0x00001770
	orrs r0, r2
	str r0, [sp, #0x10]
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #0x10]
	str r2, [r4, #0x74]
	str r3, [r4, #0x78]
	movs r0, #0x30
	adds r0, r0, r4
	mov sb, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrb r3, [r4, #0xf]
	movs r0, #7
	str r0, [sp]
	str r4, [sp, #4]
	mov r0, sb
	add r2, sp, #0xc
	bl FUN_0823b400
	ldr r0, [sp, #0x14]
	ands r0, r6
	str r0, [sp, #0x14]
	ldr r1, _0805492C @ =0x085AB912
	ldr r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r6
	str r0, [r1, #4]
	mov r0, sb
	bl FUN_0823b47c
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r4, r1
	str r5, [r0]
	ldr r0, [r4, #4]
	ldr r1, [r5, #4]
	bl FUN_08040d94
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r4, r2
	str r0, [r1]
	ldr r2, [r5, #8]
	ldr r3, [r4, #4]
	ldr r0, [r5, #0xc]
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	add r1, sp, #0xc
	str r1, [sp, #8]
	mov r0, sl
	adds r1, r4, #0
	bl FUN_080533ec
	movs r0, #0x40
	str r0, [r4, #0x14]
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805491C: .4byte 0x085AB748
_08054920: .4byte 0x085AB740
_08054924: .4byte 0xFFFF0000
_08054928: .4byte 0x00001770
_0805492C: .4byte 0x085AB912

	thumb_func_start FUN_08054930
FUN_08054930: @ 0x08054930
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_0822a4e0
	movs r1, #0x9e
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_080138fc
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_08055d7c
	adds r0, r4, #0
	adds r0, #0x30
	bl FUN_0823b284
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08054960
FUN_08054960: @ 0x08054960
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r6, #0
	adds r7, #0x7c
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	movs r2, #0x84
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r2, [r0]
	ldr r0, [r6, #0x74]
	ldr r1, [r6, #0x78]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r7, #0
	bl FUN_08055c04
	ldr r1, _080549DC @ =0x085AB95C
	ldrb r0, [r6, #0xb]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	bl _call_via_r2
	movs r0, #0
	strb r0, [r6, #0xa]
	ldrb r0, [r6, #0xd]
	lsls r0, r0, #2
	adds r4, #0x10
	adds r4, r4, r0
	ldr r2, [r4]
	adds r0, r5, #0
	adds r1, r6, #0
	bl _call_via_r2
	movs r4, #1
	ldrb r0, [r6, #0xa]
	ands r0, r4
	cmp r0, #0
	beq _080549E0
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08055ef8
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	orrs r1, r4
	str r1, [r0]
	movs r2, #0x9e
	lsls r2, r2, #1
	adds r0, r6, r2
	bl FUN_080136b4
	b _08054AB4
	.align 2, 0
_080549DC: .4byte 0x085AB95C
_080549E0:
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08055f1c
	movs r0, #0x88
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0x9e
	lsls r1, r1, #1
	adds r0, r6, r1
	bl FUN_08013698
	movs r0, #0x96
	lsls r0, r0, #1
	adds r2, r6, r0
	movs r1, #0x84
	lsls r1, r1, #1
	adds r3, r6, r1
	ldr r0, [r3]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	subs r0, #0x10
	strh r0, [r2]
	movs r2, #0x98
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r1]
	subs r0, #0x10
	strh r0, [r1]
	ldr r5, [r3]
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08054A50
	cmp r1, #0
	blt _08054A50
	ldr r0, _08054A54 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08054A50
	ldr r0, _08054A58 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08054A5C
_08054A50:
	movs r4, #0
	b _08054A6A
	.align 2, 0
_08054A54: .4byte 0x030046A8
_08054A58: .4byte 0x030046AC
_08054A5C:
	ldr r0, _08054A7C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08054A6A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08054A80
	adds r0, #4
	b _08054A8C
	.align 2, 0
_08054A7C: .4byte 0x030046A4
_08054A80:
	ldr r0, _08054AA0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08054A8C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08054AA4
	cmp r2, #2
	beq _08054AA8
	b _08054AAC
	.align 2, 0
_08054AA0: .4byte 0x030046A4
_08054AA4:
	ldrb r0, [r5, #4]
	b _08054AAA
_08054AA8:
	ldrb r0, [r5]
_08054AAA:
	subs r1, r1, r0
_08054AAC:
	movs r2, #0x97
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r1, [r0]
_08054AB4:
	adds r0, r6, #0
	adds r0, #0x30
	bl FUN_0823b4b8
	ldr r0, [r6, #0x74]
	ldr r1, [r6, #0x78]
	str r0, [r6, #0x38]
	str r1, [r6, #0x3c]
	ldrh r1, [r6, #0x2c]
	movs r2, #0x2c
	ldrsh r0, [r6, r2]
	cmp r0, #0
	ble _08054ADE
	subs r0, r1, #1
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	bgt _08054ADE
	movs r0, #3
	strh r0, [r6, #0x2c]
_08054ADE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08054ae4
FUN_08054ae4: @ 0x08054AE4
	push {r4, lr}
	movs r2, #0xa4
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r3, #0
	strb r3, [r1, #0xb]
	movs r4, #1
	strb r4, [r1, #0xc]
	str r3, [r1, #0x18]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r1, r0, r2
	strb r3, [r1, #0xb]
	strb r4, [r1, #0xc]
	str r3, [r1, #0x18]
	ldr r2, _08054B3C @ =0x000005D4
	adds r1, r0, r2
	strb r3, [r1, #0xb]
	strb r4, [r1, #0xc]
	str r3, [r1, #0x18]
	movs r2, #0x8a
	lsls r2, r2, #3
	adds r1, r0, r2
	movs r2, #0xb
	strb r2, [r1, #0xb]
	strb r4, [r1, #0xc]
	str r3, [r1, #0x18]
	movs r2, #0xeb
	lsls r2, r2, #3
	adds r1, r0, r2
	movs r2, #0xc
	strb r2, [r1, #0xb]
	strb r4, [r1, #0xc]
	str r3, [r1, #0x18]
	str r4, [r0, #0x58]
	ldr r0, _08054B40 @ =0x0300445C
	str r3, [r0]
	ldr r1, _08054B44 @ =0x03004464
	ldr r2, _08054B48 @ =0x00001084
	adds r0, r2, #0
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08054B3C: .4byte 0x000005D4
_08054B40: .4byte 0x0300445C
_08054B44: .4byte 0x03004464
_08054B48: .4byte 0x00001084

	thumb_func_start FUN_08054b4c
FUN_08054b4c: @ 0x08054B4C
	push {r4, lr}
	adds r1, r0, #0
	movs r4, #1
	ldr r3, _08054B6C @ =0x000019D0
	adds r2, r1, r3
	movs r3, #3
_08054B58:
	ldr r1, [r2]
	orrs r1, r4
	str r1, [r2]
	adds r2, #0x60
	subs r3, #1
	cmp r3, #0
	bge _08054B58
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08054B6C: .4byte 0x000019D0

	thumb_func_start FUN_08054b70
FUN_08054b70: @ 0x08054B70
	push {r4, lr}
	sub sp, #0x14
	adds r2, r0, #0
	ldr r4, [r2, #0x3c]
	ldr r1, [r2, #0x40]
	subs r3, r4, r1
	cmp r3, #4
	ble _08054B86
	adds r0, r1, #4
	str r0, [r2, #0x40]
	b _08054B96
_08054B86:
	movs r0, #4
	rsbs r0, r0, #0
	cmp r3, r0
	bge _08054B94
	subs r0, r1, #4
	str r0, [r2, #0x40]
	b _08054B96
_08054B94:
	str r4, [r2, #0x40]
_08054B96:
	ldr r1, _08054BC4 @ =0x00001848
	adds r0, r2, r1
	ldr r3, _08054BC8 @ =0x00001828
	adds r1, r2, r3
	ldr r2, [r2, #0x40]
	movs r3, #0x1e
	str r3, [sp]
	movs r3, #0x20
	str r3, [sp, #4]
	movs r3, #0x98
	str r3, [sp, #8]
	movs r3, #8
	str r3, [sp, #0xc]
	movs r3, #0
	str r3, [sp, #0x10]
	movs r3, #4
	bl FUN_082376a4
	add sp, #0x14
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08054BC4: .4byte 0x00001848
_08054BC8: .4byte 0x00001828

	thumb_func_start FUN_08054bcc
FUN_08054bcc: @ 0x08054BCC
	push {r4, r5, r6, lr}
	sub sp, #0x14
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x33
	ldrb r0, [r5]
	cmp r0, #0
	beq _08054C62
	ldr r0, [r4, #0x34]
	adds r2, r0, #1
	str r2, [r4, #0x34]
	cmp r2, #0x3b
	ble _08054BF4
	adds r0, r4, #0
	bl FUN_08054b4c
	movs r0, #0
	str r0, [r4, #0x34]
	strb r0, [r5]
	b _08054C5C
_08054BF4:
	cmp r2, #9
	ble _08054C22
	cmp r2, #0x31
	ble _08054C0A
	movs r0, #3
	ands r2, r0
	movs r0, #1
	cmp r2, #1
	bgt _08054C1C
	movs r0, #0
	b _08054C1C
_08054C0A:
	cmp r2, #0x1d
	ble _08054C1A
	movs r1, #3
	ands r1, r2
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
	b _08054C1C
_08054C1A:
	movs r0, #1
_08054C1C:
	movs r5, #0
	movs r6, #0x88
	b _08054C2C
_08054C22:
	movs r0, #0xa
	subs r0, r0, r2
	lsls r5, r0, #3
	movs r6, #0x88
	movs r0, #1
_08054C2C:
	cmp r0, #0
	beq _08054C5C
	ldr r1, _08054C54 @ =0x000019C8
	adds r0, r4, r1
	ldr r2, _08054C58 @ =0x00001828
	adds r1, r4, r2
	ldr r2, [r4, #0x38]
	movs r3, #0x1e
	str r3, [sp]
	str r5, [sp, #4]
	subs r3, r6, #2
	str r3, [sp, #8]
	movs r3, #8
	str r3, [sp, #0xc]
	movs r3, #0
	str r3, [sp, #0x10]
	movs r3, #4
	bl FUN_082376a4
	b _08054C62
	.align 2, 0
_08054C54: .4byte 0x000019C8
_08054C58: .4byte 0x00001828
_08054C5C:
	adds r0, r4, #0
	bl FUN_08054b4c
_08054C62:
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08054c6c
FUN_08054c6c: @ 0x08054C6C
	push {lr}
	sub sp, #0x14
	ldr r1, _08054C9C @ =0x00001B48
	adds r3, r0, r1
	ldr r2, _08054CA0 @ =0x00001828
	adds r1, r0, r2
	ldr r2, [r0, #0x50]
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0x20
	str r0, [sp, #4]
	movs r0, #0x90
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	movs r0, #0
	str r0, [sp, #0x10]
	adds r0, r3, #0
	movs r3, #3
	bl FUN_082376a4
	add sp, #0x14
	pop {r0}
	bx r0
	.align 2, 0
_08054C9C: .4byte 0x00001B48
_08054CA0: .4byte 0x00001828

	thumb_func_start FUN_08054ca4
FUN_08054ca4: @ 0x08054CA4
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, [r3, #0x5c]
	cmp r0, #0
	beq _08054D1C
	movs r4, #1
	ldr r0, _08054D24 @ =0x00001850
	adds r1, r3, r0
	movs r2, #3
_08054CB6:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _08054CB6
	movs r4, #1
	ldr r0, _08054D28 @ =0x000019D0
	adds r1, r3, r0
	movs r2, #3
_08054CCC:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _08054CCC
	movs r4, #1
	ldr r0, _08054D2C @ =0x00001B50
	adds r1, r3, r0
	movs r2, #2
_08054CE2:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _08054CE2
	movs r4, #1
	ldr r0, _08054D30 @ =0x00001C84
	adds r1, r3, r0
	movs r2, #5
_08054CF8:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x2c
	subs r2, #1
	cmp r2, #0
	bge _08054CF8
	movs r4, #1
	ldr r0, _08054D34 @ =0x00001DA8
	adds r1, r3, r0
	movs r2, #1
_08054D0E:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x2c
	subs r2, #1
	cmp r2, #0
	bge _08054D0E
_08054D1C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08054D24: .4byte 0x00001850
_08054D28: .4byte 0x000019D0
_08054D2C: .4byte 0x00001B50
_08054D30: .4byte 0x00001C84
_08054D34: .4byte 0x00001DA8

	thumb_func_start FUN_08054d38
FUN_08054d38: @ 0x08054D38
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _08054D8C @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08054D90 @ =0x00000942
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [r6, #0x2c]
	adds r0, r6, #0
	bl FUN_08053b18
	movs r0, #0xa4
	lsls r0, r0, #1
	adds r5, r6, r0
	movs r4, #4
_08054D58:
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_08054960
	subs r4, #1
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r5, r5, r1
	cmp r4, #0
	bge _08054D58
	adds r0, r6, #0
	adds r0, #0x60
	bl FUN_0823b8ac
	ldr r0, [r6, #0x50]
	cmp r0, #0x63
	bls _08054D94
	adds r0, r6, #0
	adds r0, #0x44
	ldrh r1, [r0]
	adds r4, r0, #0
	cmp r1, #2
	beq _08054DBE
	movs r0, #2
	b _08054DA6
	.align 2, 0
_08054D8C: .4byte 0x030046A0
_08054D90: .4byte 0x00000942
_08054D94:
	cmp r0, #0x1d
	bls _08054DB4
	adds r0, r6, #0
	adds r0, #0x44
	ldrh r1, [r0]
	adds r4, r0, #0
	cmp r1, #1
	beq _08054DBE
	movs r0, #1
_08054DA6:
	strh r0, [r4]
	ldr r0, _08054DB0 @ =0x0000028B
	bl PlaySound_082406e0
	b _08054DBE
	.align 2, 0
_08054DB0: .4byte 0x0000028B
_08054DB4:
	adds r1, r6, #0
	adds r1, #0x44
	movs r0, #0
	strh r0, [r1]
	adds r4, r1, #0
_08054DBE:
	ldrh r0, [r4]
	cmp r0, #0
	beq _08054E08
	cmp r0, #1
	bne _08054DD4
	ldr r0, _08054DD0 @ =0x00001CB0
	adds r1, r6, r0
	movs r0, #4
	b _08054DDE
	.align 2, 0
_08054DD0: .4byte 0x00001CB0
_08054DD4:
	cmp r0, #2
	bne _08054DE0
	ldr r0, _08054E00 @ =0x00001CB0
	adds r1, r6, r0
	movs r0, #5
_08054DDE:
	strh r0, [r1, #0x10]
_08054DE0:
	adds r5, r6, #0
	adds r5, #0x31
	movs r2, #2
	rsbs r2, r2, #0
	ldr r0, _08054E04 @ =0x00001C84
	adds r1, r6, r0
	movs r4, #5
_08054DEE:
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	adds r1, #0x2c
	subs r4, #1
	cmp r4, #0
	bge _08054DEE
	b _08054E22
	.align 2, 0
_08054E00: .4byte 0x00001CB0
_08054E04: .4byte 0x00001C84
_08054E08:
	adds r5, r6, #0
	adds r5, #0x31
	movs r2, #1
	ldr r0, _08054E50 @ =0x00001C84
	adds r1, r6, r0
	movs r4, #5
_08054E14:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x2c
	subs r4, #1
	cmp r4, #0
	bge _08054E14
_08054E22:
	adds r0, r6, #0
	bl FUN_08054b70
	adds r0, r6, #0
	bl FUN_08054bcc
	adds r0, r6, #0
	bl FUN_08054c6c
	ldr r0, [r6, #0x58]
	cmp r0, #1
	bne _08054E58
	ldr r1, _08054E54 @ =0x0300445C
	ldr r0, [r1]
	adds r0, #4
	str r0, [r1]
	cmp r0, #0x3f
	ble _08054E6E
	movs r0, #0x40
	str r0, [r1]
	movs r0, #0
	b _08054E6C
	.align 2, 0
_08054E50: .4byte 0x00001C84
_08054E54: .4byte 0x0300445C
_08054E58:
	cmp r0, #2
	bne _08054E6E
	ldr r1, _08054EB0 @ =0x0300445C
	ldr r0, [r1]
	subs r0, #4
	str r0, [r1]
	cmp r0, #0
	bgt _08054E6E
	movs r0, #0
	str r0, [r1]
_08054E6C:
	str r0, [r6, #0x58]
_08054E6E:
	ldrb r0, [r5]
	cmp r0, #0
	beq _08054E84
	subs r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08054E84
	adds r0, r6, #0
	bl FUN_08054ae4
_08054E84:
	adds r0, r6, #0
	bl FUN_08054ca4
	ldr r2, _08054EB4 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0xec
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, [r6, #0x3c]
	strh r1, [r0]
	ldr r0, [r2]
	ldr r1, _08054EB8 @ =0x000003B2
	adds r0, r0, r1
	ldr r1, [r6, #0x54]
	strh r1, [r0]
	ldr r0, [r6, #0x18]
	adds r0, #1
	str r0, [r6, #0x18]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08054EB0: .4byte 0x0300445C
_08054EB4: .4byte 0x030046A0
_08054EB8: .4byte 0x000003B2

	thumb_func_start FUN_08054ebc
FUN_08054ebc: @ 0x08054EBC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0xa4
	lsls r0, r0, #1
	adds r5, r6, r0
	movs r4, #4
_08054EC8:
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_08054930
	subs r4, #1
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r5, r5, r0
	cmp r4, #0
	bge _08054EC8
	ldr r0, _08054F74 @ =0x00001848
	adds r5, r6, r0
	movs r4, #3
_08054EE2:
	adds r0, r5, #0
	bl FUN_0822f1c0
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _08054EE2
	ldr r0, _08054F78 @ =0x000019C8
	adds r5, r6, r0
	movs r4, #3
_08054EF6:
	adds r0, r5, #0
	bl FUN_0822f1c0
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _08054EF6
	ldr r0, _08054F7C @ =0x00001B48
	adds r5, r6, r0
	movs r4, #2
_08054F0A:
	adds r0, r5, #0
	bl FUN_0822f1c0
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _08054F0A
	ldr r0, _08054F80 @ =0x00001C84
	adds r5, r6, r0
	movs r4, #5
_08054F1E:
	adds r0, r5, #0
	bl FUN_0822a4e0
	adds r5, #0x2c
	subs r4, #1
	cmp r4, #0
	bge _08054F1E
	ldr r0, _08054F84 @ =0x00001DA8
	adds r5, r6, r0
	movs r4, #1
_08054F32:
	adds r0, r5, #0
	bl FUN_0822a4e0
	adds r5, #0x2c
	subs r4, #1
	cmp r4, #0
	bge _08054F32
	movs r4, #0
	adds r0, r6, #0
	bl FUN_08053b54
	movs r0, #0
	movs r1, #0
	bl SetBGPrioDirect
	movs r0, #1
	movs r1, #1
	bl SetBGPrioDirect
	movs r0, #2
	movs r1, #2
	bl SetBGPrioDirect
	movs r0, #3
	movs r1, #3
	bl SetBGPrioDirect
	ldr r0, _08054F88 @ =0x03000120
	str r4, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08054F74: .4byte 0x00001848
_08054F78: .4byte 0x000019C8
_08054F7C: .4byte 0x00001B48
_08054F80: .4byte 0x00001C84
_08054F84: .4byte 0x00001DA8
_08054F88: .4byte 0x03000120

	thumb_func_start FUN_08054f8c
FUN_08054f8c: @ 0x08054F8C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	mov r8, r0
	ldr r0, _08054FF4 @ =0x03000120
	mov r1, r8
	str r1, [r0]
	ldr r5, _08054FF8 @ =0x030046B8
	bl GetMinute
	adds r4, r0, #0
	bl GetSecond
	ldr r1, _08054FFC @ =0x03002CF0
	lsls r2, r4, #4
	subs r2, r2, r4
	lsls r2, r2, #2
	ldr r1, [r1]
	adds r1, r1, r2
	adds r1, r1, r0
	ldr r0, _08055000 @ =0x000003FF
	ands r1, r0
	str r1, [r5]
	movs r0, #0
	movs r1, #3
	bl SetBGPrioDirect
	movs r0, #1
	movs r1, #3
	bl SetBGPrioDirect
	movs r0, #2
	movs r1, #3
	bl SetBGPrioDirect
	movs r0, #3
	movs r1, #3
	bl SetBGPrioDirect
	ldr r0, _08055004 @ =0x0000CB05
	ldr r1, _08055008 @ =0x0000B343
	bl GetFile
	mov ip, r0
	cmp r0, #0
	bne _0805500C
_08054FEE:
	movs r0, #1
	rsbs r0, r0, #0
	b _080553EA
	.align 2, 0
_08054FF4: .4byte 0x03000120
_08054FF8: .4byte 0x030046B8
_08054FFC: .4byte 0x03002CF0
_08055000: .4byte 0x000003FF
_08055004: .4byte 0x0000CB05
_08055008: .4byte 0x0000B343
_0805500C:
	ldr r2, _080550F4 @ =0x00001828
	add r2, r8
	mov sb, r2
	mov r1, ip
	ldm r1!, {r0, r3, r4}
	stm r2!, {r0, r3, r4}
	ldm r1!, {r0, r3, r4}
	stm r2!, {r0, r3, r4}
	ldm r1!, {r3, r4}
	stm r2!, {r3, r4}
	mov r0, sb
	mov r1, ip
	bl FUN_0822f284
	ldr r4, _080550F8 @ =0x0000922E
	ldr r1, _080550FC @ =0x0000871C
	adds r0, r4, #0
	bl GetFile
	ldr r1, _08055100 @ =0x000017DC
	add r1, r8
	str r0, [r1]
	ldr r1, _08055104 @ =0x00005BB7
	adds r0, r4, #0
	bl GetFile
	movs r1, #0xbf
	lsls r1, r1, #5
	add r1, r8
	str r0, [r1]
	ldr r1, _08055108 @ =0x000062C7
	adds r0, r4, #0
	bl GetFile
	ldr r1, _0805510C @ =0x000017E4
	add r1, r8
	str r0, [r1]
	ldr r1, _08055110 @ =0x00006830
	adds r0, r4, #0
	bl GetFile
	ldr r1, _08055114 @ =0x000017E8
	add r1, r8
	str r0, [r1]
	movs r5, #0
	ldr r0, _08055118 @ =0x085AB748
	mov sl, r0
	movs r1, #0x68
	add r1, r8
	mov sb, r1
	mov r2, sl
	str r2, [sp, #0x34]
	movs r3, #0
	str r3, [sp, #0x2c]
_08055078:
	mov r0, sl
	adds r0, #8
	ldr r4, [sp, #0x2c]
	adds r0, r4, r0
	ldr r0, [r0]
	cmp r0, #2
	bne _080550B0
	ldr r0, [sp, #0x34]
	ldrh r1, [r0]
	ldr r0, _0805511C @ =0x0000CB05
	bl GetFile
	mov ip, r0
	cmp r0, #0
	beq _08054FEE
	lsls r1, r5, #5
	add r1, r8
	adds r1, #0x68
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3}
	stm r1!, {r2, r3}
	mov r0, sb
	mov r1, ip
	bl FUN_0822f284
_080550B0:
	movs r4, #0x20
	add sb, r4
	ldr r0, [sp, #0x34]
	adds r0, #0x38
	str r0, [sp, #0x34]
	ldr r1, [sp, #0x2c]
	adds r1, #0x38
	str r1, [sp, #0x2c]
	adds r5, #1
	cmp r5, #6
	ble _08055078
	movs r0, #0x63
	bl prepare_08231510
	adds r2, r0, #0
	cmp r2, #0
	beq _08055120
	bl Script_GetValue
	mov r4, r8
	adds r4, #0x60
	strh r0, [r4]
	bl Script_GetValue
	mov r1, r8
	adds r1, #0x62
	strh r0, [r1]
	bl Script_GetValue
	mov r1, r8
	adds r1, #0x64
	strh r0, [r1]
	adds r0, r4, #0
	b _08055132
	.align 2, 0
_080550F4: .4byte 0x00001828
_080550F8: .4byte 0x0000922E
_080550FC: .4byte 0x0000871C
_08055100: .4byte 0x000017DC
_08055104: .4byte 0x00005BB7
_08055108: .4byte 0x000062C7
_0805510C: .4byte 0x000017E4
_08055110: .4byte 0x00006830
_08055114: .4byte 0x000017E8
_08055118: .4byte 0x085AB748
_0805511C: .4byte 0x0000CB05
_08055120:
	mov r1, r8
	adds r1, #0x60
	strh r2, [r1]
	mov r0, r8
	adds r0, #0x62
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, r1, #0
_08055132:
	bl FUN_0823b8ac
	movs r0, #0x70
	movs r1, #0
	bl Script_GetKeywordValue
	mov r2, r8
	str r0, [r2, #0x1c]
	movs r0, #0x43
	bl prepare_08231510
	cmp r0, #0
	beq _08055164
	mov r3, r8
	adds r3, #0x46
	str r3, [sp, #0x28]
	add r4, sp, #0x10
	movs r5, #4
_08055156:
	bl Script_GetValue
	stm r4!, {r0}
	subs r5, #1
	cmp r5, #0
	bge _08055156
	b _0805517C
_08055164:
	str r0, [sp, #0x10]
	movs r0, #7
	str r0, [sp, #0x14]
	movs r0, #2
	str r0, [sp, #0x18]
	movs r0, #5
	str r0, [sp, #0x1c]
	movs r0, #1
	str r0, [sp, #0x20]
	mov r4, r8
	adds r4, #0x46
	str r4, [sp, #0x28]
_0805517C:
	ldr r0, _080552D0 @ =0x000017EC
	add r0, r8
	ldr r1, _080552D4 @ =0x00001C1B
	bl FUN_0822b16c
	ldr r1, _080552D8 @ =0x000017F2
	add r1, r8
	ldr r0, _080552DC @ =0x00007584
	strh r0, [r1]
	ldr r1, _080552E0 @ =0x000017F8
	add r1, r8
	ldr r0, _080552E4 @ =0x00001808
	add r0, r8
	str r0, [r1]
	ldr r1, _080552E8 @ =0x00005294
	movs r5, #0xf
	ldr r0, _080552EC @ =0x00001826
	add r0, r8
_080551A0:
	strh r1, [r0]
	subs r0, #2
	subs r5, #1
	cmp r5, #0
	bge _080551A0
	movs r4, #0xa4
	lsls r4, r4, #1
	add r4, r8
	ldr r0, _080552F0 @ =0x085AB908
	mov sb, r0
	add r1, sp, #0x10
	mov sl, r1
	movs r5, #4
_080551BA:
	mov r3, sl
	adds r3, #4
	mov sl, r3
	subs r3, #4
	ldm r3!, {r2}
	mov r0, sb
	ldrh r3, [r0]
	mov r0, r8
	adds r1, r4, #0
	bl FUN_08054848
	movs r1, #2
	add sb, r1
	subs r5, #1
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r4, r4, r2
	cmp r5, #0
	bge _080551BA
	movs r5, #5
	movs r0, #0xa4
	lsls r0, r0, #1
	add r0, r8
	movs r1, #1
	movs r2, #0
	strb r1, [r0, #0xb]
	strb r1, [r0, #0xc]
	str r2, [r0, #0x18]
	movs r0, #0xb3
	lsls r0, r0, #2
	add r0, r8
	strb r5, [r0, #0xb]
	strb r1, [r0, #0xc]
	str r2, [r0, #0x18]
	movs r0, #3
	mov r3, r8
	str r0, [r3, #0x20]
	movs r0, #0xc8
	str r0, [r3, #0x24]
	str r0, [r3, #0x28]
	str r2, [r3, #0x3c]
	ldr r4, _080552F4 @ =0x00001828
	add r4, r8
	str r4, [sp, #0x24]
	movs r4, #0
	ldr r0, _080552F8 @ =0x000019C8
	add r0, r8
	mov sl, r0
	ldr r1, _080552FC @ =0x00001848
	add r1, r8
	mov sb, r1
	movs r5, #3
_08055222:
	str r4, [sp]
	str r4, [sp, #4]
	movs r2, #0x3c
	str r2, [sp, #8]
	str r4, [sp, #0xc]
	mov r0, sb
	ldr r1, [sp, #0x24]
	movs r2, #0x1e
	movs r3, #0x10
	bl FUN_0822f3fc
	str r4, [sp]
	str r4, [sp, #4]
	movs r3, #0x3c
	str r3, [sp, #8]
	str r4, [sp, #0xc]
	mov r0, sl
	ldr r1, [sp, #0x24]
	movs r2, #0x1e
	movs r3, #0x11
	bl FUN_0822f3fc
	movs r0, #0x60
	add sl, r0
	add sb, r0
	subs r5, #1
	cmp r5, #0
	bge _08055222
	movs r0, #0
	mov r1, r8
	str r0, [r1, #0x4c]
	str r0, [r1, #0x50]
	str r0, [r1, #0x54]
	mov sb, r0
	ldr r4, _08055300 @ =0x00001B48
	add r4, r8
	movs r5, #2
_0805526C:
	mov r2, sb
	str r2, [sp]
	str r2, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	adds r0, r4, #0
	ldr r1, _080552F4 @ =0x00001828
	add r1, r8
	movs r2, #0x1e
	movs r3, #0x11
	bl FUN_0822f3fc
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0805526C
	ldr r2, _08055304 @ =0xFFFF0000
	adds r0, r2, #0
	ands r0, r6
	movs r1, #0x42
	orrs r0, r1
	ldr r1, _08055308 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x98
	lsls r1, r1, #0x10
	adds r6, r0, #0
	orrs r6, r1
	ands r7, r2
	ldr r0, _0805530C @ =0x00001C68
	add r0, r8
	ldr r1, _08055310 @ =0x0000A8E7
	bl FUN_0822b16c
	movs r5, #0
	movs r3, #0
	ldr r4, _08055314 @ =0x00001C84
	add r4, r8
_080552B8:
	adds r0, r4, #0
	ldr r1, _0805530C @ =0x00001C68
	add r1, r8
	movs r2, #0x11
	str r3, [sp, #0x30]
	bl FUN_0822a470
	ldr r3, [sp, #0x30]
	cmp r5, #1
	bgt _08055318
	adds r0, r5, #3
	b _0805531A
	.align 2, 0
_080552D0: .4byte 0x000017EC
_080552D4: .4byte 0x00001C1B
_080552D8: .4byte 0x000017F2
_080552DC: .4byte 0x00007584
_080552E0: .4byte 0x000017F8
_080552E4: .4byte 0x00001808
_080552E8: .4byte 0x00005294
_080552EC: .4byte 0x00001826
_080552F0: .4byte 0x085AB908
_080552F4: .4byte 0x00001828
_080552F8: .4byte 0x000019C8
_080552FC: .4byte 0x00001848
_08055300: .4byte 0x00001B48
_08055304: .4byte 0xFFFF0000
_08055308: .4byte 0x0000FFFF
_0805530C: .4byte 0x00001C68
_08055310: .4byte 0x0000A8E7
_08055314: .4byte 0x00001C84
_08055318:
	adds r0, r5, #5
_0805531A:
	strh r0, [r4, #0x10]
	movs r0, #0xe5
	lsls r0, r0, #5
	add r0, r8
	adds r0, r0, r3
	str r6, [r0]
	str r7, [r0, #4]
	movs r0, #0
	strb r0, [r4, #7]
	adds r0, r6, #0
	adds r0, #8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _080553FC @ =0xFFFF0000
	adds r1, r2, #0
	ands r1, r6
	orrs r1, r0
	adds r6, r1, #0
	adds r3, #0x2c
	adds r4, #0x2c
	adds r5, #1
	cmp r5, #5
	ble _080552B8
	movs r6, #0x90
	lsls r6, r6, #0x10
	ands r7, r2
	ldr r0, _08055400 @ =0x00001D8C
	add r0, r8
	ldr r1, _08055404 @ =0x0000A5BD
	bl FUN_0822b16c
	movs r5, #0
	ldr r3, _08055408 @ =0x00001DA8
	movs r4, #0
	mov sb, r4
_08055360:
	movs r0, #0x2c
	adds r4, r5, #0
	muls r4, r0, r4
	adds r0, r4, r3
	add r0, r8
	ldr r1, _08055400 @ =0x00001D8C
	add r1, r8
	movs r2, #0x10
	str r3, [sp, #0x30]
	bl FUN_0822a470
	mov r1, r8
	adds r0, r4, r1
	ldr r3, [sp, #0x30]
	adds r0, r0, r3
	strh r5, [r0, #0x10]
	add r4, r8
	ldr r2, _0805540C @ =0x00001DC4
	adds r0, r4, r2
	str r6, [r0]
	str r7, [r0, #4]
	ldr r0, _08055410 @ =0x00001DAF
	adds r4, r4, r0
	mov r1, sb
	strb r1, [r4]
	adds r2, r6, #0
	asrs r1, r2, #0x10
	adds r1, #8
	lsls r1, r1, #0x10
	ldr r0, _08055414 @ =0x0000FFFF
	ands r2, r0
	adds r6, r2, #0
	orrs r6, r1
	adds r5, #1
	cmp r5, #1
	ble _08055360
	ldr r1, _08055418 @ =0x00001E0C
	add r1, r8
	movs r0, #2
	str r0, [r1]
	ldr r1, _0805541C @ =0x00001E10
	add r1, r8
	movs r0, #4
	str r0, [r1]
	ldr r1, _08055420 @ =0x00001E14
	add r1, r8
	movs r0, #6
	str r0, [r1]
	ldr r1, _08055424 @ =0x00001E18
	add r1, r8
	movs r0, #0x32
	str r0, [r1]
	ldr r1, _08055428 @ =0x00001E1C
	add r1, r8
	movs r0, #0xfa
	lsls r0, r0, #1
	str r0, [r1]
	movs r1, #0
	ldr r2, [sp, #0x28]
	strh r1, [r2]
	mov r3, r8
	str r1, [r3, #0x5c]
	ldr r0, _0805542C @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0xeb
	lsls r4, r4, #2
	adds r0, r0, r4
	strh r1, [r0]
	movs r0, #0
_080553EA:
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080553FC: .4byte 0xFFFF0000
_08055400: .4byte 0x00001D8C
_08055404: .4byte 0x0000A5BD
_08055408: .4byte 0x00001DA8
_0805540C: .4byte 0x00001DC4
_08055410: .4byte 0x00001DAF
_08055414: .4byte 0x0000FFFF
_08055418: .4byte 0x00001E0C
_0805541C: .4byte 0x00001E10
_08055420: .4byte 0x00001E14
_08055424: .4byte 0x00001E18
_08055428: .4byte 0x00001E1C
_0805542C: .4byte 0x030046A0

	thumb_func_start FUN_08055430
FUN_08055430: @ 0x08055430
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _08055470 @ =0x03000120
	ldr r0, [r0]
	cmp r0, #0
	bne _0805547E
	movs r1, #0xf1
	lsls r1, r1, #5
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805547C
	ldr r1, _08055474 @ =FUN_08054d38
	ldr r2, _08055478 @ =FUN_08054ebc
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_08054f8c
	cmp r0, #0
	bge _0805547C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805547E
	.align 2, 0
_08055470: .4byte 0x03000120
_08055474: .4byte FUN_08054d38
_08055478: .4byte FUN_08054ebc
_0805547C:
	adds r0, r4, #0
_0805547E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08055484
FUN_08055484: @ 0x08055484
	push {r4, lr}
	ldr r0, _080554D0 @ =0x03000120
	ldr r4, [r0]
	cmp r4, #0
	beq _080554C8
	adds r0, r4, #0
	adds r0, #0x46
	ldrh r3, [r0]
	cmp r3, #0
	bne _080554C8
	movs r0, #0xa4
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #3
	strb r0, [r1, #0xb]
	movs r2, #1
	strb r2, [r1, #0xc]
	str r3, [r1, #0x18]
	movs r1, #0xb3
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #7
	strb r1, [r0, #0xb]
	strb r2, [r0, #0xc]
	str r3, [r0, #0x18]
	ldr r1, _080554D4 @ =0x000005D4
	adds r0, r4, r1
	movs r1, #8
	strb r1, [r0, #0xb]
	strb r2, [r0, #0xc]
	str r3, [r0, #0x18]
	adds r0, r4, #0
	adds r0, #0x30
	strb r3, [r0]
_080554C8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080554D0: .4byte 0x03000120
_080554D4: .4byte 0x000005D4

	thumb_func_start FUN_080554d8
FUN_080554d8: @ 0x080554D8
	push {r4, r5, lr}
	ldr r0, _0805552C @ =0x03000120
	ldr r2, [r0]
	cmp r2, #0
	beq _0805554C
	movs r3, #1
	str r3, [r2, #0x5c]
	adds r0, r2, #0
	adds r0, #0x46
	ldrh r4, [r0]
	cmp r4, #0
	bne _0805554C
	movs r0, #2
	str r0, [r2, #0x58]
	ldr r1, _08055530 @ =0x0300445C
	movs r0, #0x40
	str r0, [r1]
	ldr r1, _08055534 @ =0x03004464
	ldr r5, _08055538 @ =0x00001084
	adds r0, r5, #0
	strh r0, [r1]
	adds r1, r2, #0
	adds r1, #0x31
	movs r0, #0x10
	strb r0, [r1]
	ldr r1, _0805553C @ =0x030046A0
	ldr r0, [r1]
	movs r5, #0xeb
	lsls r5, r5, #2
	adds r0, r0, r5
	strh r3, [r0]
	adds r0, r2, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	bne _08055544
	ldr r0, [r1]
	ldr r1, _08055540 @ =0x000003AE
	adds r0, r0, r1
	strh r3, [r0]
	b _0805554C
	.align 2, 0
_0805552C: .4byte 0x03000120
_08055530: .4byte 0x0300445C
_08055534: .4byte 0x03004464
_08055538: .4byte 0x00001084
_0805553C: .4byte 0x030046A0
_08055540: .4byte 0x000003AE
_08055544:
	ldr r0, [r1]
	ldr r5, _08055554 @ =0x000003AE
	adds r0, r0, r5
	strh r4, [r0]
_0805554C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08055554: .4byte 0x000003AE

	thumb_func_start FUN_08055558
FUN_08055558: @ 0x08055558
	push {r4, lr}
	adds r3, r0, #0
	ldr r2, _080555C8 @ =0x030044E0
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	adds r4, r2, #0
	cmp r0, #0
	beq _08055578
	ldr r0, [r3, #0x1c]
	subs r0, #1
	str r0, [r3, #0x1c]
	ldr r0, [r3, #0x20]
	subs r0, #1
	str r0, [r3, #0x20]
_08055578:
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _08055592
	ldr r0, [r3, #0x1c]
	adds r0, #1
	str r0, [r3, #0x1c]
	ldr r0, [r3, #0x20]
	adds r0, #1
	str r0, [r3, #0x20]
_08055592:
	ldr r0, [r3, #0x1c]
	cmp r0, #0x10
	bgt _0805559C
	movs r0, #0x10
	str r0, [r3, #0x1c]
_0805559C:
	ldr r0, [r3, #0x1c]
	cmp r0, #0x7e
	ble _080555A6
	movs r0, #0x7f
	str r0, [r3, #0x1c]
_080555A6:
	ldr r0, [r3, #0x20]
	cmp r0, #0x10
	bgt _080555B0
	movs r0, #0x10
	str r0, [r3, #0x20]
_080555B0:
	ldr r0, [r3, #0x20]
	cmp r0, #0x7e
	ble _080555BA
	movs r0, #0x7f
	str r0, [r3, #0x20]
_080555BA:
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _080555CC
	ldr r0, [r3, #0x28]
	subs r0, #1
	b _080555D8
	.align 2, 0
_080555C8: .4byte 0x030044E0
_080555CC:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080555DA
	ldr r0, [r3, #0x28]
	adds r0, #1
_080555D8:
	str r0, [r3, #0x28]
_080555DA:
	ldrh r2, [r4]
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _080555EA
	ldr r0, [r3, #0x24]
	subs r0, #1
	b _080555F6
_080555EA:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _080555F8
	ldr r0, [r3, #0x24]
	adds r0, #1
_080555F6:
	str r0, [r3, #0x24]
_080555F8:
	ldr r0, [r3, #0x24]
	ldr r1, _0805563C @ =0xFFFFFF00
	cmp r0, r1
	blt _08055608
	movs r1, #0x80
	lsls r1, r1, #1
	cmp r0, r1
	ble _0805560A
_08055608:
	str r1, [r3, #0x24]
_0805560A:
	ldr r0, [r3, #0x28]
	ldr r1, _0805563C @ =0xFFFFFF00
	cmp r0, r1
	blt _0805561A
	movs r1, #0x80
	lsls r1, r1, #1
	cmp r0, r1
	ble _0805561C
_0805561A:
	str r1, [r3, #0x28]
_0805561C:
	ldr r1, [r3, #0x1c]
	adds r0, r3, #0
	adds r0, #0x88
	strb r1, [r0]
	ldr r0, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x89
	strb r0, [r1]
	ldrb r0, [r3, #0x18]
	cmp r0, #0x80
	bls _08055640
	ldr r0, [r3, #0x5c]
	movs r1, #4
	orrs r0, r1
	b _08055648
	.align 2, 0
_0805563C: .4byte 0xFFFFFF00
_08055640:
	ldr r0, [r3, #0x5c]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08055648:
	str r0, [r3, #0x5c]
	ldr r0, [r3, #0x18]
	adds r0, #1
	str r0, [r3, #0x18]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08055658
FUN_08055658: @ 0x08055658
	movs r0, #0
	bx lr

	thumb_func_start FUN_0805565c
FUN_0805565c: @ 0x0805565C
	push {r4, r5, r6, lr}
	sub sp, #0x18
	adds r5, r0, #0
	ldr r0, _080556E8 @ =0x0000CB05
	ldr r1, _080556EC @ =0x00002117
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _080556F8
	adds r1, r5, #0
	adds r1, #0x34
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r4, r5, #0
	adds r4, #0x34
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822f284
	movs r2, #0
	str r2, [r5, #0x18]
	str r2, [r5, #0x24]
	str r2, [r5, #0x28]
	movs r0, #0x40
	str r0, [r5, #0x1c]
	str r0, [r5, #0x20]
	str r2, [r5, #0x2c]
	str r2, [r5, #0x30]
	ldr r3, _080556F0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r3
	movs r1, #0x78
	orrs r0, r1
	ldr r1, _080556F4 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r3
	str r0, [sp, #0x14]
	adds r0, r5, #0
	adds r0, #0x54
	movs r1, #2
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r6, sp, #0x10
	str r6, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #1
	movs r3, #0x12
	bl FUN_0822f3fc
	ldr r1, [r5, #0x1c]
	adds r0, r5, #0
	adds r0, #0x88
	strb r1, [r0]
	ldr r1, [r5, #0x20]
	adds r0, #1
	strb r1, [r0]
	movs r0, #0
	b _080556FC
	.align 2, 0
_080556E8: .4byte 0x0000CB05
_080556EC: .4byte 0x00002117
_080556F0: .4byte 0xFFFF0000
_080556F4: .4byte 0x0000FFFF
_080556F8:
	movs r0, #1
	rsbs r0, r0, #0
_080556FC:
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08055704
FUN_08055704: @ 0x08055704
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #8
	movs r1, #0xb4
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08055740
	ldr r1, _08055738 @ =FUN_08055558
	ldr r2, _0805573C @ =FUN_08055658
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0805565c
	cmp r0, #0
	bge _08055740
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08055742
	.align 2, 0
_08055738: .4byte FUN_08055558
_0805573C: .4byte FUN_08055658
_08055740:
	adds r0, r4, #0
_08055742:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08055748
FUN_08055748: @ 0x08055748
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r7, #0
	movs r6, #0
	ldr r0, [r4, #0x24]
	adds r0, r0, r1
	str r0, [r4, #0x24]
	cmp r0, #0
	bge _0805575C
	str r6, [r4, #0x24]
_0805575C:
	ldr r0, [r4, #0x18]
	bl VM_SetPC
	movs r5, #0
	b _0805577C
_08055766:
	bl VM_GetPC
	bl VM_GetValueAtSafe
	adds r7, r0, #0
	bl VM_GetPC
	bl VM_GetValueAt
	adds r6, r0, #0
	adds r5, #1
_0805577C:
	ldr r0, [r4, #0x24]
	cmp r5, r0
	bgt _0805578C
	bl VM_GetPC
	cmp r0, #0
	bne _08055766
	str r5, [r4, #0x24]
_0805578C:
	str r7, [r4, #0x1c]
	str r6, [r4, #0x20]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08055798
FUN_08055798: @ 0x08055798
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, _080557D4 @ =0x030044E0
	ldrh r1, [r6]
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0
	beq _080557E8
	movs r0, #0x40
	ands r1, r0
	movs r4, #1
	cmp r1, #0
	beq _080557B4
	subs r4, #2
_080557B4:
	ldr r0, [r5, #0x2c]
	cmp r0, r4
	bne _080557D8
	ldr r0, [r5, #0x28]
	subs r0, #1
	str r0, [r5, #0x28]
	cmp r0, #0
	bge _080557EA
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08055748
	movs r0, #4
	str r0, [r5, #0x28]
	b _080557EA
	.align 2, 0
_080557D4: .4byte 0x030044E0
_080557D8:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08055748
	movs r0, #0x14
	str r0, [r5, #0x28]
	str r4, [r5, #0x2c]
	b _080557EA
_080557E8:
	str r0, [r5, #0x2c]
_080557EA:
	ldrh r1, [r6, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08055804
_080557F4:
	ldr r4, [r5, #0x24]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08055748
	ldr r0, [r5, #0x24]
	cmp r4, r0
	bne _080557F4
_08055804:
	ldrh r1, [r6, #4]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0805581C
	ldr r0, [r5, #0x20]
	movs r1, #0
	bl Script_ExecById
	adds r0, r5, #0
	bl KillEntity
_0805581C:
	bl FUN_0823d4c8
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08055828
FUN_08055828: @ 0x08055828
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _08055874
	bl VM_GetPC
	str r0, [r4, #0x18]
	movs r0, #0
	str r0, [r4, #0x24]
	str r0, [r4, #0x2c]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08055748
	ldr r0, _08055864 @ =0x000092B3
	ldr r1, _08055868 @ =0x0000519C
	bl GetFile
	movs r1, #0xfa
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, _0805586C @ =0x03004430
	ldr r2, _08055870 @ =0x04000008
	bl CpuSet
	movs r0, #0
	b _08055878
	.align 2, 0
_08055864: .4byte 0x000092B3
_08055868: .4byte 0x0000519C
_0805586C: .4byte 0x03004430
_08055870: .4byte 0x04000008
_08055874:
	movs r0, #1
	rsbs r0, r0, #0
_08055878:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08055880
FUN_08055880: @ 0x08055880
	push {r4, lr}
	movs r0, #4
	movs r1, #0x30
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080558B0
	ldr r1, _080558AC @ =FUN_08055798
	movs r2, #0
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_08055828
	cmp r0, #0
	bge _080558B0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080558B2
	.align 2, 0
_080558AC: .4byte FUN_08055798
_080558B0:
	adds r0, r4, #0
_080558B2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080558b8
FUN_080558b8: @ 0x080558B8
	bx lr
	.align 2, 0

	thumb_func_start FUN_080558bc
FUN_080558bc: @ 0x080558BC
	bx lr
	.align 2, 0

	thumb_func_start FUN_080558c0
FUN_080558c0: @ 0x080558C0
	ldr r1, _080558C8 @ =0x03000124
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080558C8: .4byte 0x03000124

	thumb_func_start FUN_080558cc
FUN_080558cc: @ 0x080558CC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	mov r8, r0
	mov r7, r8
	adds r7, #0x38
	mov r5, r8
	adds r5, #0x64
	ldr r0, _08055908 @ =0x03002BE0
	ldr r6, [r0]
	add r4, sp, #8
	mov r0, r8
	ldr r3, [r0, #0x18]
	ldr r2, _0805590C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #8
	mov ip, r4
	cmp r0, #0
	blt _08055910
	asrs r1, r0, #0xc
	b _08055916
	.align 2, 0
_08055908: .4byte 0x03002BE0
_0805590C: .4byte 0x085B0A08
_08055910:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08055916:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #1
	muls r0, r1, r0
	cmp r0, #0
	blt _08055936
	asrs r0, r0, #0xc
	b _0805593C
_08055936:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805593C:
	strh r0, [r4, #4]
	adds r2, r7, #0
	adds r2, #0x1c
	adds r1, r6, #0
	adds r1, #0x2c
	add r0, sp, #8
	ldrh r0, [r0]
	ldrh r6, [r6, #0x2c]
	adds r0, r0, r6
	strh r0, [r7, #0x1c]
	mov r3, ip
	ldrh r0, [r3, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r2, #2]
	mov r3, ip
	ldrh r0, [r3, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	movs r1, #0xff
	mov r2, r8
	ldrb r0, [r2, #0x18]
	adds r0, #0x20
	ands r0, r1
	asrs r0, r0, #6
	adds r1, r0, #1
	movs r0, #3
	ands r1, r0
	add r3, sp, #4
	mov r2, sp
	adds r2, #5
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r2, #0
	cmp r0, #1
	bhi _0805598C
	movs r0, #1
	b _0805598E
_0805598C:
	movs r0, #0
_0805598E:
	strb r0, [r3]
	cmp r1, #1
	bls _08055998
	movs r0, #1
	b _0805599A
_08055998:
	movs r0, #0
_0805599A:
	strb r0, [r2]
	mov r3, r8
	ldr r1, [r3, #0x74]
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r0, [r4]
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_08236fac
	ldrh r1, [r5, #8]
	lsls r1, r1, #1
	ldr r2, [r5]
	adds r6, r2, r1
	ldrh r1, [r6]
	lsrs r1, r1, #6
	strh r1, [r7, #0x10]
	ldrb r1, [r5, #4]
	movs r4, #1
	adds r2, r4, #0
	ands r2, r1
	ldrh r3, [r6]
	movs r1, #0x30
	ands r1, r3
	lsrs r1, r1, #4
	ands r1, r4
	cmp r2, r1
	beq _080559DC
	ldr r1, [r7]
	movs r2, #4
	orrs r1, r2
	b _080559E4
_080559DC:
	ldr r1, [r7]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_080559E4:
	str r1, [r7]
	ldrb r1, [r5, #4]
	movs r4, #2
	adds r2, r4, #0
	ands r2, r1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrh r3, [r6]
	movs r1, #0x30
	ands r1, r3
	lsrs r1, r1, #4
	ands r1, r4
	cmp r2, r1
	beq _08055A08
	ldr r1, [r7]
	movs r2, #8
	orrs r1, r2
	b _08055A10
_08055A08:
	ldr r1, [r7]
	movs r2, #9
	rsbs r2, r2, #0
	ands r1, r2
_08055A10:
	str r1, [r7]
	ldrh r1, [r5, #0xe]
	adds r1, #1
	strh r1, [r5, #0xe]
	ldr r2, _08055A48 @ =0x0000FFFF
	adds r3, r2, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrb r2, [r5, #7]
	cmp r1, r2
	blo _08055A80
	movs r1, #0
	strh r1, [r5, #0xe]
	ldrb r2, [r5, #4]
	movs r1, #4
	ands r1, r2
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	cmp r2, #0
	beq _08055A4C
	ldrh r1, [r5, #8]
	cmp r1, #0
	bne _08055A40
	ldrb r1, [r5, #5]
_08055A40:
	subs r1, #1
	strh r1, [r5, #8]
	b _08055A5C
	.align 2, 0
_08055A48: .4byte 0x0000FFFF
_08055A4C:
	ldrh r1, [r5, #8]
	adds r1, #1
	strh r1, [r5, #8]
	ands r1, r3
	ldrb r3, [r5, #5]
	cmp r1, r3
	blo _08055A5C
	strh r2, [r5, #8]
_08055A5C:
	ldrh r1, [r5, #8]
	lsls r1, r1, #1
	ldr r2, [r5]
	adds r6, r2, r1
	ldrh r2, [r6]
	movs r1, #0xf
	ands r1, r2
	strb r1, [r5, #6]
	ldrb r2, [r5, #6]
	ldrh r1, [r5, #0xc]
	muls r1, r2, r1
	asrs r1, r1, #6
	strb r1, [r5, #7]
	lsls r1, r1, #0x18
	cmp r1, #0
	bne _08055A80
	movs r1, #1
	strb r1, [r5, #7]
_08055A80:
	mov r2, r8
	ldr r1, [r2, #0x18]
	adds r1, #1
	str r1, [r2, #0x18]
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08055a94
FUN_08055a94: @ 0x08055A94
	push {lr}
	adds r0, #0x38
	bl FUN_0822a4e0
	ldr r2, _08055AA8 @ =0x03000124
	movs r1, #0
	str r1, [r2]
	pop {r1}
	bx r1
	.align 2, 0
_08055AA8: .4byte 0x03000124

	thumb_func_start FUN_08055aac
FUN_08055aac: @ 0x08055AAC
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, _08055AFC @ =0x03000124
	str r7, [r0]
	adds r4, r7, #0
	adds r4, #0x1c
	adds r5, r7, #0
	adds r5, #0x38
	adds r6, r7, #0
	adds r6, #0x64
	ldr r0, _08055B00 @ =0x0000922E
	ldr r1, _08055B04 @ =0x00005BB7
	bl GetFile
	str r0, [r7, #0x74]
	ldr r1, _08055B08 @ =0x0000DA6D
	adds r0, r4, #0
	bl FUN_0822b16c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	ldr r1, [r7, #0x74]
	movs r4, #0
	str r4, [sp]
	adds r0, r6, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	str r4, [r7, #0x18]
	movs r0, #0
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08055AFC: .4byte 0x03000124
_08055B00: .4byte 0x0000922E
_08055B04: .4byte 0x00005BB7
_08055B08: .4byte 0x0000DA6D

	thumb_func_start FUN_08055b0c
FUN_08055b0c: @ 0x08055B0C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08055B44 @ =0x03000124
	ldr r0, [r0]
	cmp r0, #0
	bne _08055B52
	movs r0, #8
	movs r1, #0x78
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08055B50
	ldr r1, _08055B48 @ =FUN_080558cc
	ldr r2, _08055B4C @ =FUN_08055a94
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08055aac
	cmp r0, #0
	bge _08055B50
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08055B52
	.align 2, 0
_08055B44: .4byte 0x03000124
_08055B48: .4byte FUN_080558cc
_08055B4C: .4byte FUN_08055a94
_08055B50:
	adds r0, r4, #0
_08055B52:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08055b58
FUN_08055b58: @ 0x08055B58
	bx lr
	.align 2, 0

	thumb_func_start FUN_08055b5c
FUN_08055b5c: @ 0x08055B5C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r1, [sp, #0x1c]
	ldr r7, [sp, #0x20]
	ldr r0, [r4]
	cmp r0, #0
	bne _08055B74
	movs r0, #1
	rsbs r0, r0, #0
	b _08055BFC
_08055B74:
	cmp r0, #1
	bne _08055BB0
	adds r5, r4, #0
	adds r5, #0xc
	strb r2, [r4, #8]
	strb r3, [r4, #9]
	ands r3, r0
	cmp r3, #0
	beq _08055B88
	orrs r1, r0
_08055B88:
	str r6, [r4, #4]
	ldr r5, [r5, #0x58]
	cmp r5, #0
	beq _08055BFA
	adds r0, r4, #0
	adds r0, #0x54
	lsls r2, r6, #0x10
	lsrs r2, r2, #0x10
	ldrb r3, [r4, #8]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp]
	adds r1, r5, #0
	bl FUN_08236fac
	cmp r0, #0
	beq _08055BFA
	movs r0, #0
	strb r0, [r4, #0xa]
	b _08055BFA
_08055BB0:
	adds r5, r4, #0
	adds r5, #0xc
	strb r2, [r4, #8]
	strb r3, [r4, #9]
	ldrb r2, [r4, #8]
	adds r2, r6, r2
	str r2, [r4, #4]
	adds r0, r4, #0
	adds r0, #0x2c
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r3, [sp, #0x18]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r1, r7, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp]
	adds r1, r5, #0
	bl FUN_082370cc
	movs r0, #1
	ands r0, r7
	cmp r0, #0
	bne _08055BE2
	strb r0, [r4, #0xa]
_08055BE2:
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08055BF0
	ldr r0, [r5, #0x28]
	movs r1, #4
	orrs r0, r1
	b _08055BF8
_08055BF0:
	ldr r0, [r5, #0x28]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08055BF8:
	str r0, [r5, #0x28]
_08055BFA:
	movs r0, #0
_08055BFC:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08055c04
FUN_08055c04: @ 0x08055C04
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r3, [r6]
	cmp r3, #0
	bne _08055C14
	movs r0, #1
	rsbs r0, r0, #0
	b _08055D18
_08055C14:
	cmp r3, #1
	bne _08055D08
	ldr r0, [r6, #0x64]
	cmp r0, #0
	beq _08055D16
	adds r7, r6, #0
	adds r7, #0x28
	adds r4, r6, #0
	adds r4, #0x54
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x54]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08055C50
	ldr r0, [r6, #0x28]
	movs r1, #4
	orrs r0, r1
	b _08055C58
_08055C50:
	ldr r0, [r6, #0x28]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08055C58:
	str r0, [r6, #0x28]
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
	beq _08055C7C
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _08055C84
_08055C7C:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08055C84:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08055CBC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08055D02
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08055CC6
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08055CC0
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08055CDC
	.align 2, 0
_08055CBC: .4byte 0x0000FFFF
_08055CC0:
	subs r0, #1
	strh r0, [r4, #8]
	b _08055CDA
_08055CC6:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08055CDA
	strh r1, [r4, #8]
	movs r2, #1
	b _08055CDC
_08055CDA:
	movs r2, #0
_08055CDC:
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
	bne _08055D04
	movs r0, #1
	strb r0, [r4, #7]
	b _08055D04
_08055D02:
	movs r2, #0
_08055D04:
	strb r2, [r6, #0xa]
	b _08055D16
_08055D08:
	adds r1, r6, #0
	adds r1, #0xc
	adds r0, r6, #0
	adds r0, #0x2c
	bl FUN_082372cc
	strb r0, [r6, #0xa]
_08055D16:
	ldrb r0, [r6, #0xa]
_08055D18:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08055d20
FUN_08055d20: @ 0x08055D20
	push {lr}
	adds r1, r0, #0
	ldr r0, [r1]
	cmp r0, #1
	bne _08055D2E
	ldrb r0, [r1, #0xa]
	b _08055D42
_08055D2E:
	adds r0, r1, #0
	adds r0, #0x2c
	ldrb r1, [r0, #0x1d]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08055D40
	movs r0, #0
	b _08055D42
_08055D40:
	movs r0, #1
_08055D42:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08055d48
FUN_08055d48: @ 0x08055D48
	push {lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldr r0, [r2]
	cmp r0, #2
	bne _08055D64
	adds r2, #0x2c
	ldrb r1, [r2, #0x1d]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08055D76
	ldrh r0, [r2, #0x14]
	b _08055D70
_08055D64:
	adds r1, r2, #0
	adds r1, #0x54
	ldrh r0, [r1, #0xe]
	cmp r0, #0
	bne _08055D76
	ldrh r0, [r1, #8]
_08055D70:
	str r0, [r3]
	movs r0, #1
	b _08055D78
_08055D76:
	movs r0, #0
_08055D78:
	pop {r1}
	bx r1

	thumb_func_start FUN_08055d7c
FUN_08055d7c: @ 0x08055D7C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4]
	cmp r0, #0
	bne _08055D8C
	movs r0, #1
	rsbs r0, r0, #0
	b _08055DA6
_08055D8C:
	cmp r0, #1
	bne _08055D9A
	adds r0, r4, #0
	adds r0, #0x28
	bl FUN_0822a4e0
	b _08055DA2
_08055D9A:
	adds r0, r4, #0
	adds r0, #0x2c
	bl FUN_0822f1c0
_08055DA2:
	movs r0, #0
	str r0, [r4]
_08055DA6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08055dac
FUN_08055dac: @ 0x08055DAC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r7, r1, #0
	adds r4, r2, #0
	mov r8, r3
	ldr r0, [r6]
	cmp r0, #0
	bne _08055DF0
	adds r0, r6, #0
	movs r1, #0x94
	bl ClearMemory
	movs r0, #1
	str r0, [r6]
	adds r5, r6, #0
	adds r5, #0xc
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_0822b16c
	cmp r0, #0
	beq _08055DF0
	cmp r4, #0
	beq _08055DFC
	ldr r0, _08055DF8 @ =0x0000922E
	lsls r1, r4, #0x10
	lsrs r1, r1, #0x10
	bl GetFile
	str r0, [r5, #0x58]
	cmp r0, #0
	bne _08055DFE
_08055DF0:
	movs r0, #1
	rsbs r0, r0, #0
	b _08055E28
	.align 2, 0
_08055DF8: .4byte 0x0000922E
_08055DFC:
	str r4, [r5, #0x58]
_08055DFE:
	adds r4, r5, #0
	adds r4, #0x1c
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, r8
	bl FUN_0822a470
	ldr r0, [sp, #0x18]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x38]
	str r1, [r5, #0x3c]
	adds r1, r6, #0
	adds r1, #0x8c
	adds r0, r5, #0
	adds r0, #0x38
	str r0, [r1]
	adds r0, r6, #0
	adds r0, #0x90
	str r4, [r0]
	movs r0, #0
_08055E28:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08055e34
FUN_08055e34: @ 0x08055E34
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r4, r0, #0
	adds r6, r1, #0
	mov sb, r2
	mov r8, r3
	ldr r0, [r4]
	mov sl, r0
	cmp r0, #0
	bne _08055E70
	adds r0, r4, #0
	movs r1, #0x94
	bl ClearMemory
	movs r0, #2
	str r0, [r4]
	adds r5, r4, #0
	adds r5, #0xc
	ldr r0, _08055E78 @ =0x0000CB05
	lsls r1, r6, #0x10
	lsrs r1, r1, #0x10
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _08055E7C
_08055E70:
	movs r0, #1
	rsbs r0, r0, #0
	b _08055EC2
	.align 2, 0
_08055E78: .4byte 0x0000CB05
_08055E7C:
	adds r1, r5, #0
	adds r0, r2, #0
	ldm r0!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	ldm r0!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	ldm r0!, {r3, r6}
	stm r1!, {r3, r6}
	adds r0, r5, #0
	adds r1, r2, #0
	bl FUN_0822f284
	adds r0, r4, #0
	adds r0, #0x2c
	movs r1, #1
	str r1, [sp]
	mov r7, sl
	str r7, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	mov r1, r8
	str r1, [sp, #0xc]
	adds r1, r5, #0
	movs r2, #0
	mov r3, sb
	bl FUN_0822f3fc
	adds r2, r4, #0
	adds r2, #0x8c
	adds r1, r4, #0
	adds r1, #0x4c
	str r1, [r2]
	adds r2, #4
	subs r1, #0x18
	str r1, [r2]
_08055EC2:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08055ed4
FUN_08055ed4: @ 0x08055ED4
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldr r1, [r3]
	cmp r1, #0
	bne _08055EE6
	movs r0, #1
	rsbs r0, r0, #0
	b _08055EF4
_08055EE6:
	adds r1, r3, #0
	adds r1, #0x8c
	ldr r3, [r1]
	ldr r1, [r2]
	ldr r2, [r2, #4]
	str r1, [r3]
	str r2, [r3, #4]
_08055EF4:
	pop {r1}
	bx r1

	thumb_func_start FUN_08055ef8
FUN_08055ef8: @ 0x08055EF8
	push {lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldr r0, [r2]
	cmp r0, #0
	beq _08055F14
	adds r0, r2, #0
	adds r0, #0x90
	ldr r1, [r0]
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	movs r0, #0
	b _08055F18
_08055F14:
	movs r0, #1
	rsbs r0, r0, #0
_08055F18:
	pop {r1}
	bx r1

	thumb_func_start FUN_08055f1c
FUN_08055f1c: @ 0x08055F1C
	push {lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldr r0, [r2]
	cmp r0, #0
	beq _08055F38
	adds r0, r2, #0
	adds r0, #0x90
	ldr r1, [r0]
	ldr r0, [r1]
	bics r0, r3
	str r0, [r1]
	movs r0, #0
	b _08055F3C
_08055F38:
	movs r0, #1
	rsbs r0, r0, #0
_08055F3C:
	pop {r1}
	bx r1

	thumb_func_start FUN_08055f40
FUN_08055f40: @ 0x08055F40
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2]
	cmp r0, #0
	beq _08055F56
	adds r0, r2, #0
	adds r0, #0x90
	ldr r0, [r0]
	ldr r0, [r0]
	ands r0, r1
	b _08055F58
_08055F56:
	movs r0, #0
_08055F58:
	pop {r1}
	bx r1

	thumb_func_start FUN_08055f5c
FUN_08055f5c: @ 0x08055F5C
	push {lr}
	ldr r2, [r0]
	cmp r2, #0
	bne _08055F6A
	movs r0, #1
	rsbs r0, r0, #0
	b _08055F7A
_08055F6A:
	cmp r2, #1
	bne _08055F74
	adds r0, #0x28
	strb r1, [r0, #7]
	b _08055F78
_08055F74:
	adds r0, #0x2c
	strb r1, [r0, #0x1a]
_08055F78:
	movs r0, #0
_08055F7A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08055f80
FUN_08055f80: @ 0x08055F80
	push {r4, lr}
	mov ip, r0
	adds r4, r1, #0
	ldr r0, [r0]
	cmp r0, #0
	bne _08055F92
	movs r0, #1
	rsbs r0, r0, #0
	b _08055FB4
_08055F92:
	cmp r0, #1
	bne _08055FA2
	mov r0, ip
	adds r0, #0x28
	strb r4, [r0, #8]
	strb r2, [r0, #9]
	strb r3, [r0, #6]
	b _08055FB2
_08055FA2:
	mov r0, ip
	adds r0, #0x2c
	mov r1, ip
	adds r1, #0x60
	strb r4, [r1]
	adds r1, #1
	strb r2, [r1]
	strh r3, [r0, #0x36]
_08055FB2:
	movs r0, #0
_08055FB4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08055fbc
FUN_08055fbc: @ 0x08055FBC
	push {lr}
	ldr r2, [r0]
	cmp r2, #0
	bne _08055FCA
	movs r0, #1
	rsbs r0, r0, #0
	b _08055FDE
_08055FCA:
	cmp r2, #1
	bne _08055FD6
	adds r0, #0xc
	bl FUN_0822b20c
	b _08055FDC
_08055FD6:
	adds r0, #0x2c
	bl FUN_0822f63c
_08055FDC:
	movs r0, #0
_08055FDE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08055fe4
FUN_08055fe4: @ 0x08055FE4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	adds r6, r1, #0
	movs r0, #0x30
	adds r0, r0, r6
	mov ip, r0
	ldrh r0, [r6, #6]
	cmp r0, #0xf
	bls _0805606A
	ldrb r1, [r6, #5]
	mov sb, r1
	ldrb r5, [r6, #8]
	adds r4, r6, #0
	adds r4, #0x4c
	ldr r3, _080560C4 @ =0x00000DAC
	adds r0, r7, r3
	ldr r3, [r0]
	movs r0, #0x2c
	adds r0, r0, r3
	mov r8, r0
	ldr r1, _080560C8 @ =0x085AB990
	lsls r0, r5, #1
	adds r0, r0, r1
	ldrh r1, [r7, #0x24]
	ldrh r0, [r0]
	cmp r1, r0
	bhs _0805606A
	ldr r0, [r7, #0x20]
	movs r1, #3
	ands r0, r1
	ands r2, r1
	cmp r0, r2
	bne _0805606A
	movs r2, #0x2c
	ldrsh r1, [r3, r2]
	movs r3, #0
	ldrsh r0, [r4, r3]
	subs r0, r1, r0
	cmp r0, #0
	bge _0805603E
	rsbs r0, r0, #0
_0805603E:
	cmp r0, #0x7f
	bgt _0805606A
	mov r0, r8
	movs r2, #4
	ldrsh r1, [r0, r2]
	movs r3, #4
	ldrsh r0, [r4, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _08056054
	rsbs r1, r1, #0
_08056054:
	cmp r1, #0x7f
	bgt _0805606A
	adds r0, r7, #0
	adds r0, #0x2a
	strb r5, [r0]
	ldrh r0, [r7, #0x24]
	adds r0, #1
	strh r0, [r7, #0x24]
	ldrh r0, [r7, #0x28]
	add r0, sb
	strh r0, [r7, #0x28]
_0805606A:
	mov r1, ip
	adds r1, #0x1c
	adds r2, r6, #0
	adds r2, #0xc
	ldrh r0, [r6, #0xc]
	mov r4, ip
	ldrh r4, [r4, #0x1c]
	adds r0, r0, r4
	mov r3, ip
	strh r0, [r3, #0x1c]
	ldrh r0, [r2, #2]
	ldrh r4, [r1, #2]
	adds r0, r0, r4
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	adds r4, r6, #0
	adds r4, #0x5c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x5c]
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
	mov r8, r4
	cmp r1, r0
	beq _080560CC
	mov r3, ip
	ldr r0, [r3]
	movs r1, #4
	orrs r0, r1
	str r0, [r3]
	b _080560DA
	.align 2, 0
_080560C4: .4byte 0x00000DAC
_080560C8: .4byte 0x085AB990
_080560CC:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
	str r0, [r2]
_080560DA:
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
	beq _08056100
	mov r3, ip
	ldr r0, [r3]
	movs r1, #8
	orrs r0, r1
	str r0, [r3]
	b _0805610E
_08056100:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
	str r0, [r2]
_0805610E:
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _08056144 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0805618A
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0805614E
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08056148
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08056164
	.align 2, 0
_08056144: .4byte 0x0000FFFF
_08056148:
	subs r0, #1
	strh r0, [r4, #8]
	b _08056162
_0805614E:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08056162
	strh r1, [r4, #8]
	movs r2, #1
	b _08056164
_08056162:
	movs r2, #0
_08056164:
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
	bne _0805618C
	movs r0, #1
	strb r0, [r4, #7]
	b _0805618C
_0805618A:
	movs r2, #0
_0805618C:
	cmp r2, #0
	beq _080561A8
	ldrb r0, [r6, #2]
	adds r0, #1
	movs r3, #0
	strb r0, [r6, #2]
	strh r3, [r6, #6]
	ldr r1, [r7, #0x18]
	ldrb r2, [r6, #2]
	adds r2, #3
	str r3, [sp]
	mov r0, r8
	bl FUN_08236fac
_080561A8:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080561b8
FUN_080561b8: @ 0x080561B8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	mov ip, r1
	mov sl, r2
	mov r7, ip
	adds r7, #0x30
	mov r3, ip
	adds r3, #0x4c
	adds r1, #0xc
	mov r2, ip
	ldrh r0, [r2, #0xc]
	ldrh r2, [r3]
	adds r0, r0, r2
	strh r0, [r3]
	ldrh r0, [r1, #2]
	ldrh r2, [r3, #2]
	adds r0, r0, r2
	strh r0, [r3, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r3, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
	mov r2, ip
	ldrb r2, [r2, #5]
	mov sb, r2
	mov r0, ip
	ldrb r5, [r0, #8]
	ldr r1, _0805629C @ =0x00000DAC
	adds r0, r6, r1
	ldr r4, [r0]
	movs r2, #0x2c
	adds r2, r2, r4
	mov r8, r2
	ldr r1, _080562A0 @ =0x085AB990
	lsls r0, r5, #1
	adds r0, r0, r1
	ldrh r1, [r6, #0x24]
	ldrh r0, [r0]
	cmp r1, r0
	bhs _0805625C
	ldr r0, [r6, #0x20]
	movs r2, #3
	ands r0, r2
	mov r1, sl
	ands r1, r2
	cmp r0, r1
	bne _0805625C
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	movs r2, #0
	ldrsh r0, [r3, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _08056230
	rsbs r0, r0, #0
_08056230:
	cmp r0, #0x7f
	bgt _0805625C
	mov r0, r8
	movs r2, #4
	ldrsh r1, [r0, r2]
	movs r2, #4
	ldrsh r0, [r3, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _08056246
	rsbs r1, r1, #0
_08056246:
	cmp r1, #0x7f
	bgt _0805625C
	adds r0, r6, #0
	adds r0, #0x2a
	strb r5, [r0]
	ldrh r0, [r6, #0x24]
	adds r0, #1
	strh r0, [r6, #0x24]
	ldrh r0, [r6, #0x28]
	add r0, sb
	strh r0, [r6, #0x28]
_0805625C:
	mov r1, ip
	ldrh r0, [r1]
	cmp r0, #0
	beq _08056268
	subs r0, #1
	strh r0, [r1]
_08056268:
	mov r4, ip
	adds r4, #0x5c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	mov r2, ip
	ldr r1, [r2, #0x5c]
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
	mov r8, r4
	cmp r1, r0
	beq _080562A4
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _080562AC
	.align 2, 0
_0805629C: .4byte 0x00000DAC
_080562A0: .4byte 0x085AB990
_080562A4:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080562AC:
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
	beq _080562D0
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080562D8
_080562D0:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080562D8:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08056310 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08056356
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0805631A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08056314
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08056330
	.align 2, 0
_08056310: .4byte 0x0000FFFF
_08056314:
	subs r0, #1
	strh r0, [r4, #8]
	b _0805632E
_0805631A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0805632E
	strh r1, [r4, #8]
	movs r2, #1
	b _08056330
_0805632E:
	movs r2, #0
_08056330:
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
	bne _08056358
	movs r0, #1
	strb r0, [r4, #7]
	b _08056358
_08056356:
	movs r2, #0
_08056358:
	cmp r2, #0
	beq _0805639E
	mov r0, ip
	ldrh r3, [r0]
	cmp r3, #0
	bne _0805639E
	ldrb r0, [r0, #8]
	cmp r0, #0
	beq _0805636E
	cmp r0, #3
	bne _0805638C
_0805636E:
	mov r1, ip
	ldrb r0, [r1, #2]
	adds r0, #1
	strb r0, [r1, #2]
	strh r3, [r1, #6]
	ldr r1, [r6, #0x18]
	mov r0, ip
	ldrb r2, [r0, #2]
	adds r2, #3
	str r3, [sp]
	mov r0, r8
	movs r3, #0
	bl FUN_08236fac
	b _0805639E
_0805638C:
	movs r1, #1
	mov r2, sl
	lsls r1, r2
	ldr r0, [r6, #0x1c]
	bics r0, r1
	str r0, [r6, #0x1c]
	adds r0, r7, #0
	bl FUN_0822a4e0
_0805639E:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080563b0
FUN_080563b0: @ 0x080563B0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	mov ip, r1
	mov r8, r2
	mov r6, ip
	adds r6, #0x30
	adds r1, #0x4c
	mov r2, ip
	adds r2, #0xc
	mov r3, ip
	ldrh r0, [r3, #0xc]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	mov r4, ip
	adds r4, #0x5c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	mov r3, ip
	ldr r1, [r3, #0x5c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08056418
	mov r1, ip
	ldr r0, [r1, #0x30]
	movs r1, #4
	orrs r0, r1
	mov r2, ip
	str r0, [r2, #0x30]
	b _08056424
_08056418:
	mov r3, ip
	ldr r0, [r3, #0x30]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3, #0x30]
_08056424:
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
	beq _08056446
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0805644E
_08056446:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0805644E:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08056488 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _080564CE
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08056492
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0805648C
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080564A8
	.align 2, 0
_08056488: .4byte 0x0000FFFF
_0805648C:
	subs r0, #1
	strh r0, [r4, #8]
	b _080564A6
_08056492:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080564A6
	strh r1, [r4, #8]
	movs r2, #1
	b _080564A8
_080564A6:
	movs r2, #0
_080564A8:
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
	bne _080564D0
	movs r0, #1
	strb r0, [r4, #7]
	b _080564D0
_080564CE:
	movs r2, #0
_080564D0:
	cmp r2, #0
	beq _080564E6
	movs r1, #1
	mov r3, r8
	lsls r1, r3
	ldr r0, [r7, #0x1c]
	bics r0, r1
	str r0, [r7, #0x1c]
	adds r0, r6, #0
	bl FUN_0822a4e0
_080564E6:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080564f0
FUN_080564f0: @ 0x080564F0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0
	strh r0, [r5, #0x24]
	strh r0, [r5, #0x28]
	adds r4, r5, #0
	adds r4, #0x2c
	movs r6, #0
	ldr r0, _08056548 @ =0x0000011F
	mov r8, r0
	ldr r7, _0805654C @ =0x0000021F
_0805650C:
	movs r1, #1
	lsls r1, r6
	ldr r0, [r5, #0x1c]
	ands r0, r1
	cmp r0, #0
	beq _0805657E
	ldr r1, _08056550 @ =0x085AB998
	ldrb r0, [r4, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl _call_via_r3
	ldrb r0, [r4, #8]
	cmp r0, #0
	bne _08056578
	adds r1, r4, #0
	adds r1, #0x4c
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, r8
	bgt _08056554
	movs r0, #0x90
	lsls r0, r0, #1
	strh r0, [r1]
	b _0805655E
	.align 2, 0
_08056548: .4byte 0x0000011F
_0805654C: .4byte 0x0000021F
_08056550: .4byte 0x085AB998
_08056554:
	movs r2, #0xbe
	lsls r2, r2, #4
	cmp r0, r2
	ble _0805655E
	strh r2, [r1]
_0805655E:
	movs r2, #4
	ldrsh r0, [r1, r2]
	cmp r0, r7
	bgt _0805656E
	movs r0, #0x88
	lsls r0, r0, #2
	strh r0, [r1, #4]
	b _08056578
_0805656E:
	movs r2, #0xc8
	lsls r2, r2, #4
	cmp r0, r2
	ble _08056578
	strh r2, [r1, #4]
_08056578:
	ldrh r0, [r4, #6]
	adds r0, #1
	strh r0, [r4, #6]
_0805657E:
	adds r6, #1
	adds r4, #0x6c
	cmp r6, #0x1f
	ble _0805650C
	ldrh r0, [r5, #0x24]
	cmp r0, #0
	beq _0805660C
	adds r1, r0, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldrh r1, [r5, #0x26]
	adds r0, r0, r1
	strh r0, [r5, #0x26]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bls _08056612
	movs r0, #0
	strh r0, [r5, #0x26]
	adds r0, r5, #0
	adds r0, #0x2a
	ldrb r3, [r0]
	cmp r3, #1
	beq _080565D8
	cmp r3, #1
	bgt _080565BA
	cmp r3, #0
	beq _080565C2
	b _08056612
_080565BA:
	cmp r3, #2
	beq _080565F0
	cmp r3, #3
	bne _08056612
_080565C2:
	ldr r2, _080565D4 @ =0x00000DAC
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r5, #0x28]
	movs r2, #8
	str r2, [sp]
	movs r2, #0x10
	str r2, [sp, #4]
	b _080565FE
	.align 2, 0
_080565D4: .4byte 0x00000DAC
_080565D8:
	ldr r1, _080565EC @ =0x00000DAC
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r5, #0x28]
	movs r2, #8
	str r2, [sp]
	movs r2, #0x20
	str r2, [sp, #4]
	b _080565FE
	.align 2, 0
_080565EC: .4byte 0x00000DAC
_080565F0:
	ldr r2, _08056608 @ =0x00000DAC
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r5, #0x28]
	movs r2, #8
	str r2, [sp]
	str r3, [sp, #4]
_080565FE:
	movs r2, #0
	movs r3, #0
	bl FUN_0807e7fc
	b _08056612
	.align 2, 0
_08056608: .4byte 0x00000DAC
_0805660C:
	ldrh r0, [r5, #0x26]
	subs r0, #1
	strh r0, [r5, #0x26]
_08056612:
	ldr r0, [r5, #0x20]
	adds r0, #1
	str r0, [r5, #0x20]
	movs r0, #0
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08056628
FUN_08056628: @ 0x08056628
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x2c
	movs r4, #0
_08056632:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6, #0x1c]
	ands r0, r1
	cmp r0, #0
	beq _08056646
	adds r0, r5, #0
	adds r0, #0x30
	bl FUN_0822a4e0
_08056646:
	adds r4, #1
	adds r5, #0x6c
	cmp r4, #0x1f
	ble _08056632
	ldr r1, _0805665C @ =0x03000128
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805665C: .4byte 0x03000128

	thumb_func_start FUN_08056660
FUN_08056660: @ 0x08056660
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r0, _080566A8 @ =0x03000128
	str r7, [r0]
	ldr r0, _080566AC @ =0x0000922E
	ldr r1, _080566B0 @ =0x000031F4
	bl GetFile
	str r0, [r7, #0x18]
	movs r0, #0
	str r0, [r7, #0x1c]
	adds r5, r7, #0
	adds r5, #0x2c
	mov sb, r0
	mov r8, r0
_08056686:
	mov r0, r8
	strb r0, [r5, #4]
	strb r0, [r5, #3]
	adds r4, r5, #0
	adds r4, #0x14
	adds r0, r4, #0
	ldr r1, _080566B4 @ =0x000061F9
	bl FUN_0822b16c
	adds r6, r5, #0
	adds r6, #0x30
	cmp r0, #0
	bne _080566B8
	movs r0, #1
	rsbs r0, r0, #0
	b _0805670E
	.align 2, 0
_080566A8: .4byte 0x03000128
_080566AC: .4byte 0x0000922E
_080566B0: .4byte 0x000031F4
_080566B4: .4byte 0x000061F9
_080566B8:
	adds r0, r4, #0
	movs r1, #0x89
	lsls r1, r1, #2
	bl FUN_0822b20c
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a4b0
	movs r0, #0xc
	strh r0, [r6, #0x10]
	adds r0, r5, #0
	adds r0, #0x5c
	ldr r1, [r7, #0x18]
	mov r2, r8
	str r2, [sp]
	movs r2, #3
	movs r3, #0
	bl FUN_08236fac
	movs r0, #2
	strb r0, [r6, #7]
	adds r1, r5, #0
	adds r1, #0x4c
	mov r0, r8
	str r0, [sp, #4]
	add r0, sp, #4
	ldr r2, _0805671C @ =0x05000002
	bl CpuSet
	movs r2, #1
	add sb, r2
	adds r5, #0x6c
	mov r0, sb
	cmp r0, #0x1f
	ble _08056686
	ldr r0, _08056720 @ =0x03002BE0
	ldr r1, [r0]
	ldr r2, _08056724 @ =0x00000DAC
	adds r0, r7, r2
	str r1, [r0]
	movs r0, #0
_0805670E:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805671C: .4byte 0x05000002
_08056720: .4byte 0x03002BE0
_08056724: .4byte 0x00000DAC

	thumb_func_start FUN_08056728
FUN_08056728: @ 0x08056728
	push {r4, lr}
	ldr r0, _08056760 @ =0x03000128
	ldr r0, [r0]
	cmp r0, #0
	bne _0805676E
	movs r1, #0xdb
	lsls r1, r1, #4
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805676C
	ldr r1, _08056764 @ =FUN_080564f0
	ldr r2, _08056768 @ =FUN_08056628
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_08056660
	cmp r0, #0
	bge _0805676C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805676E
	.align 2, 0
_08056760: .4byte 0x03000128
_08056764: .4byte FUN_080564f0
_08056768: .4byte FUN_08056628
_0805676C:
	adds r0, r4, #0
_0805676E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08056774
FUN_08056774: @ 0x08056774
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	str r0, [sp, #4]
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	str r3, [sp, #0x10]
	ldr r1, _080567A4 @ =0x03000128
	ldr r1, [r1]
	mov r8, r1
	cmp r1, #0
	bne _080567A8
	bl FUN_08056728
	mov r8, r0
	cmp r0, #0
	bne _080567A8
	movs r0, #1
	rsbs r0, r0, #0
	b _080569E2
	.align 2, 0
_080567A4: .4byte 0x03000128
_080567A8:
	ldr r1, [sp, #0x58]
	cmp r1, #1
	beq _080567D2
	cmp r1, #1
	bgt _080567B8
	cmp r1, #0
	beq _080567C2
	b _080567F4
_080567B8:
	ldr r2, [sp, #0x58]
	cmp r2, #2
	beq _080567E2
	cmp r2, #3
	bne _080567F4
_080567C2:
	movs r3, #3
	str r3, [sp, #0x20]
	movs r5, #0x89
	lsls r5, r5, #2
	str r5, [sp, #0x24]
	movs r1, #2
	str r1, [sp, #0x28]
	b _08056802
_080567D2:
	movs r2, #6
	str r2, [sp, #0x20]
	movs r3, #0x8b
	lsls r3, r3, #2
	str r3, [sp, #0x24]
	movs r5, #1
	str r5, [sp, #0x28]
	b _08056802
_080567E2:
	movs r1, #8
	str r1, [sp, #0x20]
	ldr r2, _080567F0 @ =0x0000023A
	str r2, [sp, #0x24]
	movs r3, #2
	str r3, [sp, #0x28]
	b _08056802
	.align 2, 0
_080567F0: .4byte 0x0000023A
_080567F4:
	movs r5, #3
	str r5, [sp, #0x20]
	movs r1, #0x89
	lsls r1, r1, #2
	str r1, [sp, #0x24]
	movs r2, #2
	str r2, [sp, #0x28]
_08056802:
	ldr r3, [sp, #0xc]
	asrs r3, r3, #1
	str r3, [sp, #0x18]
	ldr r5, [sp, #0x4c]
	asrs r5, r5, #1
	str r5, [sp, #0x1c]
	movs r1, #0
	str r1, [sp, #0x14]
	mov r4, r8
	adds r4, #0x2c
	mov sl, r1
	movs r2, #0x40
	add r2, r8
	mov sb, r2
_0805681E:
	movs r2, #1
	mov r3, sl
	lsls r2, r3
	mov r5, r8
	ldr r1, [r5, #0x1c]
	ands r1, r2
	cmp r1, #0
	beq _08056830
	b _080569D0
_08056830:
	adds r7, r4, #0
	adds r7, #0x30
	add r0, sp, #0x58
	ldrb r0, [r0]
	strb r0, [r4, #8]
	movs r1, #0
	add r2, sp, #0x50
	ldrh r2, [r2]
	strh r2, [r4]
	ldr r3, [sp, #0x58]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _08056850
	cmp r0, #3
	bne _08056854
_08056850:
	strb r1, [r4, #2]
	b _08056858
_08056854:
	movs r5, #1
	strb r5, [r4, #2]
_08056858:
	movs r0, #0
	strh r0, [r4, #6]
	add r1, sp, #0x54
	ldrb r1, [r1]
	strb r1, [r4, #5]
	ldr r2, [sp, #0xc]
	cmp r2, #0
	bne _08056870
	mov r3, sp
	ldrb r3, [r3, #8]
	strb r3, [r4, #3]
	b _08056894
_08056870:
	ldr r5, _080568A0 @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _080568A4 @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _080568A8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [sp, #0xc]
	bl Mod
	ldr r2, [sp, #8]
	adds r0, r2, r0
	ldr r3, [sp, #0x18]
	subs r0, r0, r3
	strb r0, [r4, #3]
_08056894:
	ldr r5, [sp, #0x4c]
	cmp r5, #0
	bne _080568AC
	mov r0, sp
	ldrb r0, [r0, #0x10]
	b _080568D0
	.align 2, 0
_080568A0: .4byte 0x030046B8
_080568A4: .4byte 0x000003FF
_080568A8: .4byte 0x0203B400
_080568AC:
	ldr r1, _080568F8 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _080568FC @ =0x000003FF
	ands r0, r1
	ldr r2, _080568F8 @ =0x030046B8
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08056900 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [sp, #0x4c]
	bl Mod
	ldr r5, [sp, #0x10]
	adds r0, r5, r0
	ldr r1, [sp, #0x1c]
	subs r0, r0, r1
_080568D0:
	strb r0, [r4, #4]
	adds r3, r4, #0
	adds r3, #0xc
	ldrb r5, [r4, #3]
	ldrb r6, [r4, #4]
	ldr r2, _08056904 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08056908
	asrs r0, r0, #0xc
	b _0805690E
	.align 2, 0
_080568F8: .4byte 0x030046B8
_080568FC: .4byte 0x000003FF
_08056900: .4byte 0x0203B400
_08056904: .4byte 0x085B0A08
_08056908:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805690E:
	strh r0, [r3]
	movs r0, #0
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08056926
	asrs r0, r0, #0xc
	b _0805692C
_08056926:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805692C:
	strh r0, [r3, #4]
	movs r2, #0
	strh r2, [r4, #0xe]
	ldr r3, [sp, #0x5c]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	adds r0, r4, #0
	adds r0, #0x5c
	mov r5, r8
	ldr r1, [r5, #0x18]
	ldr r3, [sp, #0x20]
	lsls r2, r3, #0x10
	movs r5, #0
	str r5, [sp]
	lsrs r2, r2, #0x10
	movs r3, #0
	bl FUN_08236fac
	movs r0, #0x12
	strh r0, [r7, #0x10]
	add r0, sp, #0x28
	ldrb r0, [r0]
	strb r0, [r7, #7]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_0822a340
	mov r0, sb
	ldr r1, [sp, #0x24]
	bl FUN_0822b20c
	ldrb r1, [r4, #8]
	cmp r1, #0
	bne _080569B6
	adds r3, r4, #0
	adds r3, #0x4c
	mov r1, sb
	movs r5, #0x38
	ldrsh r2, [r1, r5]
	ldr r1, _0805698C @ =0x0000011F
	cmp r2, r1
	bgt _08056990
	adds r1, #1
	mov r2, sb
	strh r1, [r2, #0x38]
	b _0805699A
	.align 2, 0
_0805698C: .4byte 0x0000011F
_08056990:
	movs r1, #0xbe
	lsls r1, r1, #4
	cmp r2, r1
	ble _0805699A
	strh r1, [r3]
_0805699A:
	movs r5, #4
	ldrsh r2, [r3, r5]
	ldr r1, _080569A8 @ =0x0000021F
	cmp r2, r1
	bgt _080569AC
	adds r1, #1
	b _080569B4
	.align 2, 0
_080569A8: .4byte 0x0000021F
_080569AC:
	movs r1, #0xc8
	lsls r1, r1, #4
	cmp r2, r1
	ble _080569B6
_080569B4:
	strh r1, [r3, #4]
_080569B6:
	movs r2, #1
	mov r1, sl
	lsls r2, r1
	mov r3, r8
	ldr r1, [r3, #0x1c]
	orrs r1, r2
	str r1, [r3, #0x1c]
	ldr r5, [sp, #0x14]
	adds r5, #1
	str r5, [sp, #0x14]
	ldr r1, [sp, #4]
	cmp r5, r1
	bge _080569E2
_080569D0:
	movs r2, #1
	add sl, r2
	movs r3, #0x6c
	add sb, r3
	adds r4, #0x6c
	mov r5, sl
	cmp r5, #0x1f
	bgt _080569E2
	b _0805681E
_080569E2:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080569f4
FUN_080569f4: @ 0x080569F4
	mov ip, r0
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0, #0x3c]
	strh r1, [r0, #0x3e]
	adds r0, #0x40
	movs r2, #0x80
	lsls r2, r2, #2
	strh r2, [r0]
	adds r0, #4
	movs r3, #0x80
	lsls r3, r3, #4
	strh r3, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #4
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	movs r2, #0x90
	lsls r2, r2, #4
	strh r2, [r0]
	adds r0, #4
	strh r3, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r2, [r0]
	bx lr

	thumb_func_start FUN_08056a34
FUN_08056a34: @ 0x08056A34
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r2, r0, #0
	adds r7, r1, #0
	ldr r1, _08056AD0 @ =0x00000EBC
	adds r2, r2, r1
	ldr r2, [r2]
	mov r8, r2
	movs r4, #0x2c
	add r4, r8
	mov ip, r4
	adds r6, r7, #0
	adds r6, #0x4c
	ldrh r4, [r6, #0x1c]
	ldr r5, _08056AD4 @ =0xFFFFFC00
	adds r3, r5, #0
	adds r2, r4, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r5, _08056AD8 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r5
	orrs r1, r2
	str r1, [sp]
	ldrh r2, [r6, #0x20]
	adds r3, r2, r3
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov r6, sp
	ldr r1, [sp, #4]
	ands r1, r5
	orrs r1, r3
	str r1, [sp, #4]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r3, r1, #0
	adds r4, r4, r3
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r1, [sp, #8]
	ands r1, r5
	orrs r1, r4
	str r1, [sp, #8]
	adds r2, r2, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	add r3, sp, #8
	ldr r1, [r3, #4]
	ands r1, r5
	orrs r1, r2
	str r1, [r3, #4]
	mov r1, sp
	mov r4, r8
	movs r5, #0x2c
	ldrsh r2, [r4, r5]
	movs r4, #0
	ldrsh r1, [r1, r4]
	cmp r2, r1
	blt _08056ADC
	movs r5, #0
	ldrsh r1, [r3, r5]
	cmp r2, r1
	bgt _08056ADC
	mov r1, ip
	movs r4, #4
	ldrsh r2, [r1, r4]
	movs r5, #4
	ldrsh r1, [r6, r5]
	cmp r2, r1
	blt _08056ADC
	movs r4, #4
	ldrsh r1, [r3, r4]
	cmp r2, r1
	bgt _08056ADC
	movs r1, #1
	b _08056ADE
	.align 2, 0
_08056AD0: .4byte 0x00000EBC
_08056AD4: .4byte 0xFFFFFC00
_08056AD8: .4byte 0xFFFF0000
_08056ADC:
	movs r1, #0
_08056ADE:
	adds r2, r1, #0
	cmp r2, #0
	beq _08056AEA
	movs r0, #0
	strb r0, [r7, #0xc]
	b _08056AFC
_08056AEA:
	ldrb r1, [r7, #0xc]
	adds r1, #1
	strb r1, [r7, #0xc]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0x1f
	bls _08056AFC
	strb r2, [r7, #0xc]
	movs r0, #1
_08056AFC:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08056b08
FUN_08056b08: @ 0x08056B08
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x48
	mov r8, r1
	mov r3, r8
	adds r3, #0x4c
	mov r0, r8
	ldrh r1, [r0, #0x20]
	ldrh r2, [r3, #0x1c]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08056B84 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	mov r4, r8
	ldrh r0, [r4, #0x24]
	ldrh r3, [r3, #0x20]
	adds r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	adds r4, #0x20
	str r4, [sp, #0x18]
	movs r0, #0x68
	add r0, r8
	mov sl, r0
	mov sb, sp
	add r7, sp, #8
	movs r1, #0
	str r1, [sp, #0x1c]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r3, sb
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08056B7E
	cmp r1, #0
	blt _08056B7E
	ldr r0, _08056B88 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08056B7E
	ldr r0, _08056B8C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08056B90
_08056B7E:
	movs r4, #0
	b _08056B9E
	.align 2, 0
_08056B84: .4byte 0xFFFF0000
_08056B88: .4byte 0x030046A8
_08056B8C: .4byte 0x030046AC
_08056B90:
	ldr r0, _08056BB0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08056B9E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08056BB4
	adds r0, #4
	b _08056BC0
	.align 2, 0
_08056BB0: .4byte 0x030046A4
_08056BB4:
	ldr r0, _08056BF4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08056BC0:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08056C5E
	mov r4, sb
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08056BF0
	cmp r1, #0
	blt _08056BF0
	ldr r0, _08056BF8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08056BF0
	ldr r0, _08056BFC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08056C00
_08056BF0:
	movs r4, #0
	b _08056C0E
	.align 2, 0
_08056BF4: .4byte 0x030046A4
_08056BF8: .4byte 0x030046A8
_08056BFC: .4byte 0x030046AC
_08056C00:
	ldr r0, _08056C20 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08056C0E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08056C24
	adds r0, #4
	b _08056C30
	.align 2, 0
_08056C20: .4byte 0x030046A4
_08056C24:
	ldr r0, _08056C44 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08056C30:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08056C48
	cmp r2, #2
	beq _08056C4E
	b _08056C54
	.align 2, 0
_08056C44: .4byte 0x030046A4
_08056C48:
	mov r2, sb
	ldrb r0, [r2, #4]
	b _08056C52
_08056C4E:
	mov r3, sb
	ldrb r0, [r3]
_08056C52:
	subs r1, r1, r0
_08056C54:
	movs r0, #0x80
	lsls r0, r0, #1
	movs r2, #0
	cmp r1, r0
	beq _08056C60
_08056C5E:
	movs r2, #1
_08056C60:
	cmp r2, #0
	bne _08056C66
	b _08056F7A
_08056C66:
	mov r4, sl
	ldrh r0, [r4]
	ldr r3, _08056CC4 @ =0xFFFFFF00
	adds r1, r3, #0
	ands r1, r0
	ldr r2, _08056CC8 @ =0xFFFF0000
	adds r0, r2, #0
	ands r0, r5
	adds r5, r0, #0
	orrs r5, r1
	ldrh r0, [r4, #4]
	ands r3, r0
	adds r0, r2, #0
	ands r0, r6
	adds r6, r0, #0
	orrs r6, r3
	adds r3, r5, #0
	adds r1, r3, #0
	adds r1, #0xff
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r2, #0
	ldr r4, [sp, #0x20]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x20]
	adds r0, r6, #0
	adds r0, #0xff
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x24]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, #0x24]
	mov r2, sb
	ldrh r1, [r2]
	strh r1, [r7]
	ldrh r0, [r2, #4]
	strh r0, [r7, #4]
	lsls r1, r1, #0x10
	lsls r3, r3, #0x10
	asrs r2, r1, #0x10
	cmp r1, r3
	bge _08056CCC
	strh r5, [r7]
	b _08056CDC
	.align 2, 0
_08056CC4: .4byte 0xFFFFFF00
_08056CC8: .4byte 0xFFFF0000
_08056CCC:
	ldr r3, [sp, #0x20]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r2, r0
	ble _08056CDC
	mov r4, sp
	ldrh r4, [r4, #0x20]
	strh r4, [r7]
_08056CDC:
	movs r0, #4
	ldrsh r2, [r7, r0]
	adds r3, r6, #0
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r2, r0
	bge _08056CEE
	strh r3, [r7, #4]
	b _08056CFC
_08056CEE:
	mov r3, sp
	ldrh r1, [r3, #0x24]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r2, r0
	ble _08056CFC
	strh r1, [r7, #4]
_08056CFC:
	mov r4, sb
	ldrh r1, [r4]
	ldrh r0, [r7]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08056DB8 @ =0xFFFF0000
	adds r0, r2, #0
	ldr r3, [sp, #0x28]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x28]
	ldrh r1, [r4, #4]
	ldrh r0, [r7, #4]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r2, #0
	ldr r4, [sp, #0x2c]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x2c]
	mov r0, sp
	ldrh r1, [r0, #0x28]
	lsls r0, r1, #0x10
	cmp r0, #0
	beq _08056D3C
	rsbs r0, r1, #0
	ldr r1, [sp, #0x18]
	strh r0, [r1]
	movs r3, #1
	str r3, [sp, #0x1c]
_08056D3C:
	mov r4, sp
	ldrh r1, [r4, #0x2c]
	lsls r0, r1, #0x10
	cmp r0, #0
	beq _08056D50
	rsbs r0, r1, #0
	ldr r1, [sp, #0x18]
	strh r0, [r1, #4]
	movs r3, #1
	str r3, [sp, #0x1c]
_08056D50:
	ldr r4, [sp, #0x1c]
	cmp r4, #0
	bne _08056D58
	b _08056F7A
_08056D58:
	mov r0, sp
	ldrh r1, [r0, #8]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	add r4, sp, #8
	ldrh r1, [r4, #4]
	add r3, sp, #0x10
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r3, #4]
	mov r2, r8
	ldrh r1, [r2, #0x20]
	ldrh r0, [r4]
	adds r2, r1, r0
	mov r0, sp
	strh r2, [r0]
	ldrh r2, [r4, #4]
	adds r1, r1, r2
	strh r1, [r0, #4]
	movs r0, #0x20
	add r8, r0
	adds r7, r3, #0
	mov r5, sp
	adds r6, r4, #0
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08056DB2
	cmp r1, #0
	blt _08056DB2
	ldr r0, _08056DBC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08056DB2
	ldr r0, _08056DC0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08056DC4
_08056DB2:
	movs r4, #0
	b _08056DD2
	.align 2, 0
_08056DB8: .4byte 0xFFFF0000
_08056DBC: .4byte 0x030046A8
_08056DC0: .4byte 0x030046AC
_08056DC4:
	ldr r0, _08056DE4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08056DD2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08056DE8
	adds r0, #4
	b _08056DF4
	.align 2, 0
_08056DE4: .4byte 0x030046A4
_08056DE8:
	ldr r0, _08056E28 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08056DF4:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08056E8E
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08056E22
	cmp r1, #0
	blt _08056E22
	ldr r0, _08056E2C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08056E22
	ldr r0, _08056E30 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08056E34
_08056E22:
	movs r4, #0
	b _08056E42
	.align 2, 0
_08056E28: .4byte 0x030046A4
_08056E2C: .4byte 0x030046A8
_08056E30: .4byte 0x030046AC
_08056E34:
	ldr r0, _08056E54 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08056E42:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08056E58
	adds r0, #4
	b _08056E64
	.align 2, 0
_08056E54: .4byte 0x030046A4
_08056E58:
	ldr r0, _08056E78 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08056E64:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08056E7C
	cmp r2, #2
	beq _08056E80
	b _08056E84
	.align 2, 0
_08056E78: .4byte 0x030046A4
_08056E7C:
	ldrb r0, [r5, #4]
	b _08056E82
_08056E80:
	ldrb r0, [r5]
_08056E82:
	subs r1, r1, r0
_08056E84:
	movs r0, #0x80
	lsls r0, r0, #1
	movs r2, #0
	cmp r1, r0
	beq _08056E90
_08056E8E:
	movs r2, #1
_08056E90:
	cmp r2, #0
	beq _08056F7A
	ldrh r0, [r7]
	ldr r3, _08056EFC @ =0xFFFFFF00
	adds r1, r3, #0
	ands r1, r0
	ldr r2, _08056F00 @ =0xFFFF0000
	adds r0, r2, #0
	ldr r4, [sp, #0x30]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x30]
	ldrh r0, [r7, #4]
	ands r3, r0
	adds r0, r2, #0
	ldr r1, [sp, #0x34]
	ands r0, r1
	orrs r0, r3
	str r0, [sp, #0x34]
	mov r4, sp
	ldrh r3, [r4, #0x30]
	adds r1, r3, #0
	adds r1, #0xff
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r2, #0
	ldr r4, [sp, #0x38]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x38]
	ldr r0, [sp, #0x34]
	adds r0, #0xff
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x3c]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, #0x3c]
	ldrh r0, [r5]
	strh r0, [r6]
	ldrh r2, [r5, #4]
	strh r2, [r6, #4]
	lsls r1, r0, #0x10
	lsls r3, r3, #0x10
	asrs r5, r1, #0x10
	adds r4, r0, #0
	adds r7, r2, #0
	cmp r1, r3
	bge _08056F04
	mov r2, sp
	ldrh r2, [r2, #0x30]
	strh r2, [r6]
	b _08056F14
	.align 2, 0
_08056EFC: .4byte 0xFFFFFF00
_08056F00: .4byte 0xFFFF0000
_08056F04:
	ldr r3, [sp, #0x38]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r5, r0
	ble _08056F14
	mov r0, sp
	ldrh r0, [r0, #0x38]
	strh r0, [r6]
_08056F14:
	movs r1, #4
	ldrsh r2, [r6, r1]
	mov r0, sp
	ldrh r3, [r0, #0x34]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r2, r0
	bge _08056F28
	strh r3, [r6, #4]
	b _08056F36
_08056F28:
	mov r3, sp
	ldrh r1, [r3, #0x3c]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r2, r0
	ble _08056F36
	strh r1, [r6, #4]
_08056F36:
	ldrh r1, [r6]
	subs r1, r4, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08056F8C @ =0xFFFF0000
	adds r0, r2, #0
	ldr r4, [sp, #0x40]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x40]
	ldrh r0, [r6, #4]
	subs r0, r7, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x44]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, #0x44]
	add r2, sp, #0x40
	ldrh r1, [r2]
	lsls r0, r1, #0x10
	cmp r0, #0
	beq _08056F6A
	rsbs r0, r1, #0
	mov r3, r8
	strh r0, [r3]
_08056F6A:
	add r4, sp, #0x44
	ldrh r1, [r4]
	lsls r0, r1, #0x10
	cmp r0, #0
	beq _08056F7A
	rsbs r0, r1, #0
	mov r1, r8
	strh r0, [r1, #4]
_08056F7A:
	add sp, #0x48
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08056F8C: .4byte 0xFFFF0000

	thumb_func_start FUN_08056f90
FUN_08056f90: @ 0x08056F90
	bx lr
	.align 2, 0

	thumb_func_start FUN_08056f94
FUN_08056f94: @ 0x08056F94
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r6, r0, #0
	adds r7, r1, #0
	adds r4, r2, #0
	bl FUN_08236524
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r6, #6]
	ands r0, r1
	cmp r0, #0
	beq _08056FBA
	adds r0, r6, #0
	adds r0, #0x42
	ldrb r3, [r0]
	b _08056FD4
_08056FBA:
	movs r1, #0x24
	ldrsh r0, [r7, r1]
	movs r2, #0x24
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	movs r3, #0x28
	ldrsh r1, [r7, r3]
	movs r3, #0x28
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	adds r3, r0, #0
_08056FD4:
	movs r0, #1
	ldr r1, [r6, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _08057004
	ldr r0, _08057000 @ =0x03002BE0
	ldr r2, [r0]
	movs r1, #0xc
	ldrsh r0, [r7, r1]
	movs r3, #0x2c
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	movs r3, #0x10
	ldrsh r1, [r7, r3]
	movs r3, #0x30
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	adds r3, r0, #0
	movs r0, #0x10
	b _08057044
	.align 2, 0
_08057000: .4byte 0x03002BE0
_08057004:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08057012
	movs r1, #0x20
	mov ip, r1
	b _08057046
_08057012:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08057038
	movs r2, #0xc
	ldrsh r0, [r7, r2]
	movs r3, #0xc
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	movs r2, #0x10
	ldrsh r1, [r7, r2]
	movs r3, #0x10
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	adds r3, r0, #0
	movs r0, #0x18
	b _08057044
_08057038:
	movs r0, #8
	ands r1, r0
	movs r2, #0x10
	mov ip, r2
	cmp r1, #0
	beq _08057046
_08057044:
	mov ip, r0
_08057046:
	ldr r2, _08057088 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805708C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08057090 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	subs r2, r3, #4
	movs r1, #7
	ands r0, r1
	adds r3, r2, r0
	adds r5, r4, #0
	adds r5, #0x20
	ldr r2, _08057094 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _08057098
	asrs r1, r0, #0xc
	b _0805709E
	.align 2, 0
_08057088: .4byte 0x030046B8
_0805708C: .4byte 0x000003FF
_08057090: .4byte 0x0203B400
_08057094: .4byte 0x085B0A08
_08057098:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805709E:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r3, ip
	muls r3, r0, r3
	adds r0, r3, #0
	cmp r0, #0
	blt _080570BE
	asrs r0, r0, #0xc
	b _080570C4
_080570BE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080570C4:
	movs r1, #0
	mov r8, r1
	strh r0, [r5, #4]
	adds r0, r4, #0
	adds r0, #0x30
	movs r1, #0x99
	lsls r1, r1, #1
	bl FUN_0822b20c
	movs r0, #0xa
	strb r0, [r4, #9]
	ldr r3, _08057134 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r2, #0x10
	orrs r0, r2
	ldr r1, _08057138 @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0xc]
	ldrh r1, [r7, #0x3e]
	adds r3, r4, #0
	adds r3, #0x68
	add r2, sp, #8
	str r2, [sp]
	movs r5, #1
	str r5, [sp, #4]
	adds r0, r7, #0
	movs r2, #0
	bl FUN_0805fe7c
	ldrh r0, [r6, #0x3e]
	adds r0, #2
	strh r0, [r6, #0x3e]
	movs r0, #0x89
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldrh r0, [r4]
	ldrh r1, [r7, #0x3e]
	subs r0, r0, r1
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0805713C
	mov r3, r8
	strh r3, [r4]
	movs r0, #7
	strb r0, [r4, #4]
	strb r5, [r4, #8]
	mov r0, r8
	str r0, [r4, #0x14]
	b _08057146
	.align 2, 0
_08057134: .4byte 0xFFFF0000
_08057138: .4byte 0x0000FFFF
_0805713C:
	movs r0, #6
	strb r0, [r4, #4]
	strb r5, [r4, #8]
	mov r1, r8
	str r1, [r4, #0x14]
_08057146:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08057154
FUN_08057154: @ 0x08057154
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	str r1, [sp, #0x1c]
	movs r0, #0
	strh r0, [r7, #0x24]
	ldr r0, _08057200 @ =0xFFFF0000
	mov sl, r0
	add r6, sp, #0xc
	ldr r1, _08057204 @ =0x00000D7C
	mov sb, r1
	add r5, sp, #0x14
	movs r0, #3
	mov r8, r0
_08057178:
	mov r1, sb
	adds r4, r7, r1
	ldr r0, [sp, #0xc]
	mov r1, sl
	ands r0, r1
	movs r1, #0x18
	orrs r0, r1
	ldr r1, _08057208 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [r6, #4]
	mov r1, sl
	ands r0, r1
	movs r1, #0x18
	orrs r0, r1
	str r0, [r6, #4]
	movs r0, #0x80
	lsls r0, r0, #0xe
	str r0, [sp, #0x14]
	ldr r0, [r5, #4]
	mov r1, sl
	ands r0, r1
	str r0, [r5, #4]
	movs r0, #0x10
	str r0, [sp]
	str r6, [sp, #4]
	str r5, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	ldr r2, _0805720C @ =0x00002001
	movs r3, #0
	bl FUN_0823646c
	adds r0, r4, #0
	ldr r1, _08057210 @ =FUN_08056f90
	adds r2, r7, #0
	bl FUN_0823651c
	movs r0, #0
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	adds r0, r4, #0
	ldr r1, [sp, #0x1c]
	movs r2, #0x1e
	movs r3, #0
	bl FUN_082364f8
	movs r0, #0x50
	add sb, r0
	movs r1, #1
	rsbs r1, r1, #0
	add r8, r1
	mov r0, r8
	cmp r0, #0
	bge _08057178
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08057200: .4byte 0xFFFF0000
_08057204: .4byte 0x00000D7C
_08057208: .4byte 0x0000FFFF
_0805720C: .4byte 0x00002001
_08057210: .4byte FUN_08056f90

	thumb_func_start FUN_08057214
FUN_08057214: @ 0x08057214
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r2, r1, #0
	ldrh r0, [r4, #0x24]
	cmp r0, #3
	bhi _080572AA
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #4
	ldr r0, _08057248 @ =0x00000D7C
	adds r1, r1, r0
	adds r5, r4, r1
	ldr r0, [r2, #0x68]
	ldr r1, [r2, #0x6c]
	str r0, [sp]
	str r1, [sp, #4]
	ldrb r1, [r2, #5]
	cmp r1, #1
	beq _0805725E
	cmp r1, #1
	bgt _0805724C
	cmp r1, #0
	beq _08057256
	b _08057294
	.align 2, 0
_08057248: .4byte 0x00000D7C
_0805724C:
	cmp r1, #2
	beq _08057266
	cmp r1, #3
	beq _08057280
	b _08057294
_08057256:
	mov r0, sp
	ldrh r1, [r0, #4]
	subs r1, #0x30
	b _0805726C
_0805725E:
	mov r0, sp
	ldrh r1, [r0]
	adds r1, #0x30
	b _08057286
_08057266:
	mov r0, sp
	ldrh r1, [r0, #4]
	adds r1, #0x30
_0805726C:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0805727C @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	b _08057294
	.align 2, 0
_0805727C: .4byte 0xFFFF0000
_08057280:
	mov r0, sp
	ldrh r1, [r0]
	subs r1, #0x30
_08057286:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080572B4 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
_08057294:
	adds r0, r5, #0
	mov r1, sp
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	ldrh r0, [r4, #0x24]
	adds r0, #1
	strh r0, [r4, #0x24]
_080572AA:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080572B4: .4byte 0xFFFF0000

	thumb_func_start FUN_080572b8
FUN_080572b8: @ 0x080572B8
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r5, r1, #0
	adds r4, r5, #0
	adds r4, #0x88
	ldr r2, _08057334 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x40
	orrs r0, r3
	ldr r1, _08057338 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _0805733C @ =0x00005001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	adds r1, r5, #0
	adds r1, #0x68
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _08057340 @ =FUN_08056f94
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0823651c
	movs r0, #2
	ldrsh r1, [r5, r0]
	adds r0, r4, #0
	movs r2, #0x80
	movs r3, #0
	bl FUN_08236514
	adds r0, r4, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08057334: .4byte 0xFFFF0000
_08057338: .4byte 0x0000FFFF
_0805733C: .4byte 0x00005001
_08057340: .4byte FUN_08056f94

	thumb_func_start FUN_08057344
FUN_08057344: @ 0x08057344
	push {lr}
	adds r0, r1, #0
	adds r0, #0x88
	bl FUN_08236424
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08057354
FUN_08057354: @ 0x08057354
	push {lr}
	sub sp, #0x14
	ldr r2, [r0, #0x38]
	cmp r2, #0
	beq _08057394
	adds r0, r1, #0
	adds r0, #0x68
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp]
	adds r0, r1, #0
	adds r0, #0x6a
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp, #4]
	adds r0, r1, #0
	adds r0, #0x6c
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #8]
	ldr r1, _0805739C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r1
	movs r1, #3
	orrs r0, r1
	str r0, [sp, #0xc]
	add r1, sp, #0xc
	mov r3, sp
	str r3, [r1, #4]
	adds r0, r2, #0
	bl Script_ExecById
_08057394:
	add sp, #0x14
	pop {r0}
	bx r0
	.align 2, 0
_0805739C: .4byte 0xFFFF0000

	thumb_func_start FUN_080573a0
FUN_080573a0: @ 0x080573A0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _080573E2
	movs r0, #0
	strb r0, [r4, #8]
	adds r5, r4, #0
	adds r5, #0x78
	ldr r1, [r6, #0x18]
	movs r3, #0
	ldrb r2, [r4, #5]
	subs r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080573C8
	movs r3, #1
_080573C8:
	movs r0, #0
	cmp r2, #1
	bls _080573D0
	movs r0, #1
_080573D0:
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_08236fac
	adds r0, r5, #0
	movs r1, #0x40
	bl FUN_08237098
_080573E2:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080573EE
	subs r0, #1
	strb r0, [r4, #0xe]
	b _08057422
_080573EE:
	ldr r1, [r4, #0x18]
	movs r0, #0x80
	lsls r0, r0, #9
	cmp r1, r0
	bhi _08057422
	ldrb r0, [r4, #0xf]
	adds r2, r0, #0
	cmp r2, #0
	beq _08057406
	subs r0, #1
	strb r0, [r4, #0xf]
	b _08057422
_08057406:
	movs r0, #0x1e
	strb r0, [r4, #0xf]
	movs r0, #0x78
	strb r0, [r4, #0xe]
	movs r1, #5
	ldr r0, [r6, #0x30]
	cmp r0, #0
	beq _08057418
	movs r1, #8
_08057418:
	strb r1, [r4, #4]
	movs r0, #1
	strb r0, [r4, #8]
	str r2, [r4, #0x14]
	b _0805746E
_08057422:
	ldrb r3, [r4, #0x10]
	cmp r3, #0
	bne _0805744E
	movs r1, #0x80
	lsls r1, r1, #0xd
	ldr r0, [r4, #0x18]
	movs r2, #0
	cmp r0, r1
	bhi _08057436
	movs r2, #1
_08057436:
	cmp r2, #0
	beq _0805744E
	movs r1, #4
	ldr r0, [r6, #0x30]
	cmp r0, #0
	beq _08057444
	movs r1, #8
_08057444:
	strb r1, [r4, #4]
	movs r0, #1
	strb r0, [r4, #8]
	str r3, [r4, #0x14]
	b _0805746E
_0805744E:
	ldr r0, [r4, #0x14]
	cmp r0, #0x3b
	bls _0805746A
	movs r2, #2
	ldr r0, [r6, #0x30]
	cmp r0, #0
	beq _0805745E
	movs r2, #8
_0805745E:
	movs r1, #0
	strb r2, [r4, #4]
	movs r0, #1
	strb r0, [r4, #8]
	str r1, [r4, #0x14]
	b _0805746E
_0805746A:
	adds r0, #1
	str r0, [r4, #0x14]
_0805746E:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08057478
FUN_08057478: @ 0x08057478
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	mov r8, r0
	adds r4, r1, #0
	adds r7, r4, #0
	adds r7, #0x4c
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _080574B6
	movs r2, #0
	strb r2, [r4, #8]
	adds r0, r4, #0
	adds r0, #0x78
	mov r3, r8
	ldr r1, [r3, #0x18]
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
	ldr r0, [r4, #0x4c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x4c]
	adds r0, r4, #0
	adds r0, #0xd8
	bl FUN_08013698
_080574B6:
	ldrh r0, [r7, #0x1e]
	subs r0, #0x20
	strh r0, [r7, #0x1e]
	adds r6, r4, #0
	adds r6, #0x68
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080574E4
	cmp r1, #0
	blt _080574E4
	ldr r0, _080574E8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080574E4
	ldr r0, _080574EC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080574F0
_080574E4:
	movs r5, #0
	b _080574FE
	.align 2, 0
_080574E8: .4byte 0x030046A8
_080574EC: .4byte 0x030046AC
_080574F0:
	ldr r0, _08057510 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_080574FE:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08057514
	adds r0, #4
	b _08057520
	.align 2, 0
_08057510: .4byte 0x030046A4
_08057514:
	ldr r0, _08057534 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08057520:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08057538
	cmp r2, #2
	beq _0805753C
	b _08057540
	.align 2, 0
_08057534: .4byte 0x030046A4
_08057538:
	ldrb r0, [r6, #4]
	b _0805753E
_0805753C:
	ldrb r0, [r6]
_0805753E:
	subs r1, r1, r0
_08057540:
	movs r2, #0x1e
	ldrsh r0, [r7, r2]
	cmp r0, r1
	bgt _08057578
	movs r2, #0
	strh r1, [r7, #0x1e]
	movs r1, #0x80
	lsls r1, r1, #0xd
	ldr r0, [r4, #0x18]
	cmp r0, r1
	bhi _0805755A
	movs r1, #4
	b _0805755C
_0805755A:
	movs r1, #2
_0805755C:
	mov r3, r8
	ldr r0, [r3, #0x30]
	cmp r0, #0
	beq _08057566
	movs r1, #8
_08057566:
	strb r1, [r4, #4]
	movs r0, #1
	strb r0, [r4, #8]
	str r2, [r4, #0x14]
	adds r0, r4, #0
	adds r0, #0xd8
	bl FUN_080136b4
	b _0805757E
_08057578:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
_0805757E:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805758c
FUN_0805758c: @ 0x0805758C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov r8, r0
	adds r7, r1, #0
	mov sb, r2
	adds r0, r7, #0
	adds r0, #0x4c
	str r0, [sp, #0xc]
	ldrb r0, [r7, #8]
	cmp r0, #0
	beq _080575EE
	movs r0, #0
	strb r0, [r7, #8]
	ldr r6, _08057624 @ =0x0203B400
	ldr r4, _08057628 @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r3, _0805762C @ =0x000003FF
	ands r1, r3
	str r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r2, #3
	mov r5, sb
	ands r2, r5
	lsls r2, r2, #3
	add r2, r8
	ands r0, r3
	ldrh r5, [r2, #0x3c]
	adds r0, r0, r5
	movs r5, #0
	strh r0, [r7, #0x1c]
	adds r1, #1
	ands r1, r3
	str r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	adds r2, #0x40
	ands r0, r3
	ldrh r2, [r2]
	adds r0, r0, r2
	strh r0, [r7, #0x1e]
	strb r5, [r7, #0x10]
_080575EE:
	mov r6, r8
	ldr r1, [r6, #0x18]
	movs r3, #0
	ldrb r2, [r7, #5]
	subs r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r7, #0
	adds r4, #0x78
	cmp r0, #1
	bhi _08057606
	movs r3, #1
_08057606:
	movs r0, #0
	cmp r2, #1
	bls _0805760E
	movs r0, #1
_0805760E:
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_08236fac
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _08057630
	subs r0, #1
	strb r0, [r7, #0xe]
	b _08057666
	.align 2, 0
_08057624: .4byte 0x0203B400
_08057628: .4byte 0x030046B8
_0805762C: .4byte 0x000003FF
_08057630:
	ldr r1, [r7, #0x18]
	movs r0, #0x80
	lsls r0, r0, #9
	cmp r1, r0
	bhi _08057666
	ldrb r0, [r7, #0xf]
	adds r2, r0, #0
	cmp r2, #0
	beq _08057648
	subs r0, #1
	strb r0, [r7, #0xf]
	b _08057666
_08057648:
	movs r0, #0x1e
	strb r0, [r7, #0xf]
	movs r0, #0x78
	strb r0, [r7, #0xe]
	movs r1, #5
	mov r3, r8
	ldr r0, [r3, #0x30]
	cmp r0, #0
	beq _0805765C
	movs r1, #8
_0805765C:
	strb r1, [r7, #4]
	movs r0, #1
	strb r0, [r7, #8]
	str r2, [r7, #0x14]
	b _08057992
_08057666:
	ldrb r3, [r7, #0x10]
	cmp r3, #0
	bne _08057694
	movs r1, #0x80
	lsls r1, r1, #0xd
	ldr r0, [r7, #0x18]
	movs r2, #0
	cmp r0, r1
	bhi _0805767A
	movs r2, #1
_0805767A:
	cmp r2, #0
	beq _08057694
	movs r1, #4
	mov r5, r8
	ldr r0, [r5, #0x30]
	cmp r0, #0
	beq _0805768A
	movs r1, #8
_0805768A:
	strb r1, [r7, #4]
	movs r0, #1
	strb r0, [r7, #8]
	str r3, [r7, #0x14]
	b _08057992
_08057694:
	ldrh r0, [r4, #0xa]
	cmp r0, #1
	bne _080576B4
	ldr r2, _080576B0 @ =0x085AB9A4
	ldrh r1, [r4, #8]
	movs r0, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r0, r0, #3
	asrs r0, r0, #6
	b _080576B6
	.align 2, 0
_080576B0: .4byte 0x085AB9A4
_080576B4:
	movs r0, #0
_080576B6:
	movs r4, #0
	strb r0, [r7, #6]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080576C2
	b _0805798C
_080576C2:
	adds r2, r7, #0
	adds r2, #0x4c
	movs r6, #0x1c
	ldrsh r1, [r7, r6]
	movs r3, #0x1c
	ldrsh r0, [r2, r3]
	subs r3, r1, r0
	movs r5, #0x1e
	ldrsh r1, [r7, r5]
	movs r6, #0x20
	ldrsh r0, [r2, r6]
	subs r1, r1, r0
	adds r0, r3, #0
	cmp r3, #0
	bge _080576E2
	rsbs r0, r3, #0
_080576E2:
	cmp r0, #0x17
	bgt _0805771E
	adds r0, r1, #0
	cmp r1, #0
	bge _080576EE
	rsbs r0, r1, #0
_080576EE:
	cmp r0, #0x17
	bgt _08057710
	strb r4, [r7, #6]
	movs r0, #0xff
	strb r0, [r7, #0xb]
	movs r3, #1
	mov r0, r8
	ldr r1, [r0, #0x30]
	rsbs r0, r1, #0
	orrs r0, r1
	asrs r0, r0, #0x1f
	movs r1, #8
	ands r0, r1
	strb r0, [r7, #4]
	strb r3, [r7, #8]
	str r4, [r7, #0x14]
	b _08057992
_08057710:
	mvns r0, r1
	asrs r2, r0, #0x1f
	movs r0, #2
	ands r2, r0
	movs r5, #1
	ldrb r4, [r7, #0xb]
	b _08057774
_0805771E:
	adds r0, r1, #0
	cmp r1, #0
	bge _08057726
	rsbs r0, r1, #0
_08057726:
	cmp r0, #0x17
	bgt _0805773E
	movs r2, #1
	cmp r3, #0
	bge _08057732
	movs r2, #3
_08057732:
	mvns r0, r1
	asrs r5, r0, #0x1f
	movs r0, #2
	ands r5, r0
	ldrb r4, [r7, #0xb]
	b _0805777A
_0805773E:
	movs r0, #0xb
	ldrsb r0, [r7, r0]
	ldrb r4, [r7, #0xb]
	cmp r0, #0
	blt _0805774E
	movs r0, #1
	ands r0, r4
	b _08057754
_0805774E:
	movs r0, #1
	mov r2, sb
	ands r0, r2
_08057754:
	cmp r0, #0
	bne _0805776A
	movs r2, #1
	cmp r3, #0
	bge _08057760
	movs r2, #3
_08057760:
	mvns r0, r1
	asrs r5, r0, #0x1f
	movs r0, #2
	ands r5, r0
	b _0805777A
_0805776A:
	mvns r0, r1
	asrs r2, r0, #0x1f
	movs r0, #2
	ands r2, r0
	movs r5, #1
_08057774:
	cmp r3, #0
	bge _0805777A
	movs r5, #3
_0805777A:
	lsls r0, r4, #0x18
	cmp r0, #0
	blt _08057790
	movs r0, #1
	adds r1, r5, #0
	ands r1, r0
	ands r0, r4
	cmp r1, r0
	bne _08057790
	movs r5, #0xb
	ldrsb r5, [r7, r5]
_08057790:
	str r7, [sp, #0x10]
	mov r8, r2
	mov sl, r5
	ldrb r3, [r7, #6]
	mov sb, r3
	adds r6, r7, #0
	adds r6, #0x20
	str r6, [sp, #0x14]
_080577A0:
	ldr r0, [sp, #0x10]
	adds r0, #0x68
	ldrh r0, [r0]
	ldr r1, _080577D8 @ =0xFFFF0000
	ldr r3, [sp, #4]
	ands r3, r1
	orrs r3, r0
	str r3, [sp, #4]
	ldr r0, [sp, #0x10]
	adds r0, #0x6c
	ldrh r0, [r0]
	add r4, sp, #4
	ldr r2, [sp, #8]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, #8]
	movs r0, #1
	mov r6, r8
	ands r0, r6
	cmp r0, #0
	bne _080577EC
	cmp r6, #0
	bne _080577DC
	ldrh r0, [r4, #4]
	mov r3, sb
	subs r0, r0, r3
	b _080577E0
	.align 2, 0
_080577D8: .4byte 0xFFFF0000
_080577DC:
	ldrh r0, [r4, #4]
	add r0, sb
_080577E0:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	b _0805780C
_080577EC:
	mov r6, r8
	cmp r6, #1
	bne _080577FA
	add r0, sp, #4
	ldrh r0, [r0]
	add r0, sb
	b _08057802
_080577FA:
	add r0, sp, #4
	ldrh r0, [r0]
	mov r2, sb
	subs r0, r0, r2
_08057802:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #4]
_0805780C:
	add r1, sp, #4
	adds r0, r1, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08057834
	cmp r1, #0
	blt _08057834
	ldr r0, _08057838 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08057834
	ldr r0, _0805783C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08057840
_08057834:
	movs r4, #0
	b _0805784E
	.align 2, 0
_08057838: .4byte 0x030046A8
_0805783C: .4byte 0x030046AC
_08057840:
	ldr r0, _08057860 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0805784E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08057864
	adds r0, #4
	b _08057870
	.align 2, 0
_08057860: .4byte 0x030046A4
_08057864:
	ldr r0, _080578A8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08057870:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0805790C
	add r6, sp, #4
	adds r0, r6, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080578A2
	cmp r1, #0
	blt _080578A2
	ldr r0, _080578AC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080578A2
	ldr r0, _080578B0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080578B4
_080578A2:
	movs r4, #0
	b _080578C2
	.align 2, 0
_080578A8: .4byte 0x030046A4
_080578AC: .4byte 0x030046A8
_080578B0: .4byte 0x030046AC
_080578B4:
	ldr r0, _080578D4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080578C2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080578D8
	adds r0, #4
	b _080578E4
	.align 2, 0
_080578D4: .4byte 0x030046A4
_080578D8:
	ldr r0, _080578F8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080578E4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080578FC
	cmp r2, #2
	beq _08057900
	b _08057904
	.align 2, 0
_080578F8: .4byte 0x030046A4
_080578FC:
	ldrb r0, [r6, #4]
	b _08057902
_08057900:
	ldrb r0, [r6]
_08057902:
	subs r1, r1, r0
_08057904:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	beq _08057922
_0805790C:
	mov r3, sl
	cmp r3, #0
	blt _0805791C
	mov r8, sl
	movs r6, #1
	rsbs r6, r6, #0
	mov sl, r6
	b _080577A0
_0805791C:
	movs r2, #1
	rsbs r2, r2, #0
	b _08057924
_08057922:
	mov r2, r8
_08057924:
	cmp r2, r5
	bne _0805792C
	strb r2, [r7, #0xb]
	b _08057930
_0805792C:
	movs r0, #0xff
	strb r0, [r7, #0xb]
_08057930:
	cmp r2, #0
	bge _08057938
	movs r2, #0
	strb r2, [r7, #6]
_08057938:
	strb r2, [r7, #5]
	movs r3, #0
	ldrb r1, [r7, #5]
	ldrb r0, [r7, #6]
	ldr r2, [sp, #0x14]
	strh r3, [r2, #2]
	cmp r1, #1
	beq _08057964
	cmp r1, #1
	bgt _08057952
	cmp r1, #0
	beq _0805795C
	b _08057978
_08057952:
	cmp r1, #2
	beq _0805796A
	cmp r1, #3
	beq _08057970
	b _08057978
_0805795C:
	strh r3, [r7, #0x20]
	rsbs r0, r0, #0
	strh r0, [r2, #4]
	b _08057978
_08057964:
	strh r0, [r7, #0x20]
	strh r3, [r2, #4]
	b _08057978
_0805796A:
	strh r3, [r7, #0x20]
	strh r0, [r2, #4]
	b _08057978
_08057970:
	rsbs r0, r0, #0
	strh r0, [r7, #0x20]
	ldr r0, [sp, #0x14]
	strh r3, [r0, #4]
_08057978:
	ldrh r0, [r7, #0x20]
	ldr r1, [sp, #0xc]
	ldrh r1, [r1, #0x1c]
	adds r0, r0, r1
	ldr r2, [sp, #0xc]
	strh r0, [r2, #0x1c]
	ldrh r0, [r7, #0x24]
	ldrh r3, [r2, #0x20]
	adds r0, r0, r3
	strh r0, [r2, #0x20]
_0805798C:
	ldr r0, [r7, #0x14]
	adds r0, #1
	str r0, [r7, #0x14]
_08057992:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080579a4
FUN_080579a4: @ 0x080579A4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	adds r6, r1, #0
	mov r8, r2
	adds r0, r6, #0
	adds r0, #0x4c
	str r0, [sp, #0xc]
	ldrb r0, [r6, #8]
	cmp r0, #0
	beq _08057A04
	movs r0, #0
	strb r0, [r6, #8]
	ldr r1, _08057A38 @ =0x0203B400
	mov sb, r1
	ldr r4, _08057A3C @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r3, _08057A40 @ =0x000003FF
	ands r1, r3
	str r1, [r4]
	lsls r0, r1, #1
	add r0, sb
	ldrh r0, [r0]
	movs r2, #3
	mov r5, r8
	ands r2, r5
	lsls r2, r2, #3
	adds r2, r7, r2
	ands r0, r3
	ldrh r5, [r2, #0x3c]
	adds r0, r0, r5
	strh r0, [r6, #0x1c]
	adds r1, #1
	ands r1, r3
	str r1, [r4]
	lsls r1, r1, #1
	add r1, sb
	ldrh r0, [r1]
	adds r2, #0x40
	ands r0, r3
	ldrh r2, [r2]
	adds r0, r0, r2
	strh r0, [r6, #0x1e]
_08057A04:
	ldr r1, [r7, #0x18]
	movs r3, #0
	ldrb r2, [r6, #5]
	subs r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r6, #0
	adds r4, #0x78
	cmp r0, #1
	bhi _08057A1A
	movs r3, #1
_08057A1A:
	movs r0, #0
	cmp r2, #1
	bls _08057A22
	movs r0, #1
_08057A22:
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_08236fac
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _08057A44
	subs r0, #1
	strb r0, [r6, #0xe]
	b _08057A78
	.align 2, 0
_08057A38: .4byte 0x0203B400
_08057A3C: .4byte 0x030046B8
_08057A40: .4byte 0x000003FF
_08057A44:
	ldr r1, [r6, #0x18]
	movs r0, #0x80
	lsls r0, r0, #9
	cmp r1, r0
	bhi _08057A78
	ldrb r0, [r6, #0xf]
	adds r2, r0, #0
	cmp r2, #0
	beq _08057A5C
	subs r0, #1
	strb r0, [r6, #0xf]
	b _08057A78
_08057A5C:
	movs r0, #0x1e
	strb r0, [r6, #0xf]
	movs r0, #0x78
	strb r0, [r6, #0xe]
	movs r1, #5
	ldr r0, [r7, #0x30]
	cmp r0, #0
	beq _08057A6E
	movs r1, #8
_08057A6E:
	strb r1, [r6, #4]
	movs r0, #1
	strb r0, [r6, #8]
	str r2, [r6, #0x14]
	b _08057D9E
_08057A78:
	ldrb r3, [r6, #0x10]
	cmp r3, #0
	bne _08057AA4
	movs r1, #0x80
	lsls r1, r1, #0xd
	ldr r0, [r6, #0x18]
	movs r2, #0
	cmp r0, r1
	bhi _08057A8C
	movs r2, #1
_08057A8C:
	cmp r2, #0
	beq _08057AA4
	movs r1, #4
	ldr r0, [r7, #0x30]
	cmp r0, #0
	beq _08057A9A
	movs r1, #8
_08057A9A:
	strb r1, [r6, #4]
	movs r0, #1
	strb r0, [r6, #8]
	str r3, [r6, #0x14]
	b _08057D9E
_08057AA4:
	ldrh r0, [r4, #0xa]
	cmp r0, #1
	bne _08057AC4
	ldr r2, _08057AC0 @ =0x085AB9A4
	ldrh r1, [r4, #8]
	movs r0, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r0, r0, #3
	asrs r0, r0, #6
	b _08057AC6
	.align 2, 0
_08057AC0: .4byte 0x085AB9A4
_08057AC4:
	movs r0, #0
_08057AC6:
	movs r4, #0
	strb r0, [r6, #6]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08057AD2
	b _08057D98
_08057AD2:
	adds r2, r6, #0
	adds r2, #0x4c
	movs r0, #0x1c
	ldrsh r1, [r6, r0]
	movs r3, #0x1c
	ldrsh r0, [r2, r3]
	subs r3, r1, r0
	movs r5, #0x1e
	ldrsh r1, [r6, r5]
	movs r5, #0x20
	ldrsh r0, [r2, r5]
	subs r1, r1, r0
	adds r0, r3, #0
	cmp r3, #0
	bge _08057AF2
	rsbs r0, r3, #0
_08057AF2:
	cmp r0, #0x17
	bgt _08057B2C
	adds r0, r1, #0
	cmp r1, #0
	bge _08057AFE
	rsbs r0, r1, #0
_08057AFE:
	cmp r0, #0x17
	bgt _08057B1E
	strb r4, [r6, #6]
	movs r0, #0xff
	strb r0, [r6, #0xb]
	movs r3, #1
	ldr r1, [r7, #0x30]
	rsbs r0, r1, #0
	orrs r0, r1
	asrs r0, r0, #0x1f
	movs r1, #8
	ands r0, r1
	strb r0, [r6, #4]
	strb r3, [r6, #8]
	str r4, [r6, #0x14]
	b _08057D9E
_08057B1E:
	mvns r0, r1
	asrs r2, r0, #0x1f
	movs r0, #2
	ands r2, r0
	movs r5, #1
	ldrb r4, [r6, #0xb]
	b _08057B82
_08057B2C:
	adds r0, r1, #0
	cmp r1, #0
	bge _08057B34
	rsbs r0, r1, #0
_08057B34:
	cmp r0, #0x17
	bgt _08057B4C
	movs r2, #1
	cmp r3, #0
	bge _08057B40
	movs r2, #3
_08057B40:
	mvns r0, r1
	asrs r5, r0, #0x1f
	movs r0, #2
	ands r5, r0
	ldrb r4, [r6, #0xb]
	b _08057B88
_08057B4C:
	movs r0, #0xb
	ldrsb r0, [r6, r0]
	ldrb r4, [r6, #0xb]
	cmp r0, #0
	blt _08057B5C
	movs r0, #1
	ands r0, r4
	b _08057B62
_08057B5C:
	movs r0, #1
	mov r7, r8
	ands r0, r7
_08057B62:
	cmp r0, #0
	bne _08057B78
	movs r2, #1
	cmp r3, #0
	bge _08057B6E
	movs r2, #3
_08057B6E:
	mvns r0, r1
	asrs r5, r0, #0x1f
	movs r0, #2
	ands r5, r0
	b _08057B88
_08057B78:
	mvns r0, r1
	asrs r2, r0, #0x1f
	movs r0, #2
	ands r2, r0
	movs r5, #1
_08057B82:
	cmp r3, #0
	bge _08057B88
	movs r5, #3
_08057B88:
	lsls r0, r4, #0x18
	cmp r0, #0
	blt _08057B9E
	movs r0, #1
	adds r1, r5, #0
	ands r1, r0
	ands r0, r4
	cmp r1, r0
	bne _08057B9E
	movs r5, #0xb
	ldrsb r5, [r6, r5]
_08057B9E:
	str r6, [sp, #0x10]
	mov r8, r2
	mov sl, r5
	ldrb r0, [r6, #6]
	mov sb, r0
	adds r1, r6, #0
	adds r1, #0x20
	str r1, [sp, #0x14]
_08057BAE:
	ldr r0, [sp, #0x10]
	adds r0, #0x68
	ldrh r0, [r0]
	ldr r1, _08057BE4 @ =0xFFFF0000
	ldr r3, [sp, #4]
	ands r3, r1
	orrs r3, r0
	str r3, [sp, #4]
	ldr r0, [sp, #0x10]
	adds r0, #0x6c
	ldrh r0, [r0]
	add r4, sp, #4
	ldr r2, [sp, #8]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, #8]
	movs r0, #1
	mov r7, r8
	ands r0, r7
	cmp r0, #0
	bne _08057BF8
	cmp r7, #0
	bne _08057BE8
	ldrh r0, [r4, #4]
	mov r3, sb
	subs r0, r0, r3
	b _08057BEC
	.align 2, 0
_08057BE4: .4byte 0xFFFF0000
_08057BE8:
	ldrh r0, [r4, #4]
	add r0, sb
_08057BEC:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	b _08057C18
_08057BF8:
	mov r7, r8
	cmp r7, #1
	bne _08057C06
	add r0, sp, #4
	ldrh r0, [r0]
	add r0, sb
	b _08057C0E
_08057C06:
	add r0, sp, #4
	ldrh r0, [r0]
	mov r2, sb
	subs r0, r0, r2
_08057C0E:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #4]
_08057C18:
	add r1, sp, #4
	adds r0, r1, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08057C40
	cmp r1, #0
	blt _08057C40
	ldr r0, _08057C44 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08057C40
	ldr r0, _08057C48 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08057C4C
_08057C40:
	movs r4, #0
	b _08057C5A
	.align 2, 0
_08057C44: .4byte 0x030046A8
_08057C48: .4byte 0x030046AC
_08057C4C:
	ldr r0, _08057C6C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08057C5A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08057C70
	adds r0, #4
	b _08057C7C
	.align 2, 0
_08057C6C: .4byte 0x030046A4
_08057C70:
	ldr r0, _08057CB4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08057C7C:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08057D18
	add r7, sp, #4
	adds r0, r7, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08057CAE
	cmp r1, #0
	blt _08057CAE
	ldr r0, _08057CB8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08057CAE
	ldr r0, _08057CBC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08057CC0
_08057CAE:
	movs r4, #0
	b _08057CCE
	.align 2, 0
_08057CB4: .4byte 0x030046A4
_08057CB8: .4byte 0x030046A8
_08057CBC: .4byte 0x030046AC
_08057CC0:
	ldr r0, _08057CE0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08057CCE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08057CE4
	adds r0, #4
	b _08057CF0
	.align 2, 0
_08057CE0: .4byte 0x030046A4
_08057CE4:
	ldr r0, _08057D04 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08057CF0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08057D08
	cmp r2, #2
	beq _08057D0C
	b _08057D10
	.align 2, 0
_08057D04: .4byte 0x030046A4
_08057D08:
	ldrb r0, [r7, #4]
	b _08057D0E
_08057D0C:
	ldrb r0, [r7]
_08057D0E:
	subs r1, r1, r0
_08057D10:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	beq _08057D2E
_08057D18:
	mov r3, sl
	cmp r3, #0
	blt _08057D28
	mov r8, sl
	movs r7, #1
	rsbs r7, r7, #0
	mov sl, r7
	b _08057BAE
_08057D28:
	movs r2, #1
	rsbs r2, r2, #0
	b _08057D30
_08057D2E:
	mov r2, r8
_08057D30:
	cmp r2, r5
	bne _08057D38
	strb r2, [r6, #0xb]
	b _08057D3C
_08057D38:
	movs r0, #0xff
	strb r0, [r6, #0xb]
_08057D3C:
	cmp r2, #0
	bge _08057D44
	movs r2, #0
	strb r2, [r6, #6]
_08057D44:
	strb r2, [r6, #5]
	movs r3, #0
	ldrb r1, [r6, #5]
	ldrb r0, [r6, #6]
	ldr r2, [sp, #0x14]
	strh r3, [r2, #2]
	cmp r1, #1
	beq _08057D70
	cmp r1, #1
	bgt _08057D5E
	cmp r1, #0
	beq _08057D68
	b _08057D84
_08057D5E:
	cmp r1, #2
	beq _08057D76
	cmp r1, #3
	beq _08057D7C
	b _08057D84
_08057D68:
	strh r3, [r6, #0x20]
	rsbs r0, r0, #0
	strh r0, [r2, #4]
	b _08057D84
_08057D70:
	strh r0, [r6, #0x20]
	strh r3, [r2, #4]
	b _08057D84
_08057D76:
	strh r3, [r6, #0x20]
	strh r0, [r2, #4]
	b _08057D84
_08057D7C:
	rsbs r0, r0, #0
	strh r0, [r6, #0x20]
	ldr r0, [sp, #0x14]
	strh r3, [r0, #4]
_08057D84:
	ldrh r0, [r6, #0x20]
	ldr r1, [sp, #0xc]
	ldrh r1, [r1, #0x1c]
	adds r0, r0, r1
	ldr r2, [sp, #0xc]
	strh r0, [r2, #0x1c]
	ldrh r0, [r6, #0x24]
	ldrh r3, [r2, #0x20]
	adds r0, r0, r3
	strh r0, [r2, #0x20]
_08057D98:
	ldr r0, [r6, #0x14]
	adds r0, #1
	str r0, [r6, #0x14]
_08057D9E:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08057db0
FUN_08057db0: @ 0x08057DB0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov sl, r0
	adds r5, r1, #0
	adds r7, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
	str r0, [sp, #0xc]
	ldrb r0, [r5, #8]
	cmp r0, #0
	beq _08057E00
	movs r0, #0
	strb r0, [r5, #8]
	ldr r0, _08057E70 @ =0x00000EBC
	add r0, sl
	ldr r4, [r0]
	ldrh r0, [r4, #0x2c]
	ldr r1, _08057E74 @ =0xFFFFFF00
	adds r2, r1, #0
	ands r2, r0
	movs r3, #3
	adds r0, r7, #0
	ands r0, r3
	lsls r0, r0, #5
	adds r2, r2, r0
	movs r3, #0
	strh r2, [r5, #0x1c]
	ldrh r0, [r4, #0x30]
	ands r1, r0
	asrs r0, r7, #2
	lsls r0, r0, #5
	adds r1, r1, r0
	strh r1, [r5, #0x1e]
	strb r3, [r5, #0xc]
	movs r0, #1
	strb r0, [r5, #0x10]
_08057E00:
	adds r4, r5, #0
	adds r4, #0x78
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_08237098
	mov r2, sl
	ldr r1, [r2, #0x18]
	movs r3, #0
	ldrb r2, [r5, #5]
	subs r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r6, r4, #0
	cmp r0, #1
	bhi _08057E22
	movs r3, #1
_08057E22:
	movs r0, #0
	cmp r2, #1
	bls _08057E2A
	movs r0, #1
_08057E2A:
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #1
	bl FUN_08236fac
	ldr r0, [r5, #0x14]
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _08057E64
	ldr r0, _08057E70 @ =0x00000EBC
	add r0, sl
	ldr r4, [r0]
	ldrh r0, [r4, #0x2c]
	ldr r1, _08057E74 @ =0xFFFFFF00
	adds r2, r1, #0
	ands r2, r0
	movs r3, #3
	adds r0, r7, #0
	ands r0, r3
	lsls r0, r0, #5
	adds r2, r2, r0
	strh r2, [r5, #0x1c]
	ldrh r0, [r4, #0x30]
	ands r1, r0
	asrs r0, r7, #2
	lsls r0, r0, #5
	adds r1, r1, r0
	strh r1, [r5, #0x1e]
_08057E64:
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _08057E78
	subs r0, #1
	strb r0, [r5, #0xe]
	b _08057EAE
	.align 2, 0
_08057E70: .4byte 0x00000EBC
_08057E74: .4byte 0xFFFFFF00
_08057E78:
	ldr r1, [r5, #0x18]
	movs r0, #0x80
	lsls r0, r0, #9
	cmp r1, r0
	bhi _08057EAE
	ldrb r0, [r5, #0xf]
	adds r2, r0, #0
	cmp r2, #0
	beq _08057E90
	subs r0, #1
	strb r0, [r5, #0xf]
	b _08057EAE
_08057E90:
	movs r0, #0x1e
	strb r0, [r5, #0xf]
	movs r0, #0x78
	strb r0, [r5, #0xe]
	movs r1, #5
	mov r3, sl
	ldr r0, [r3, #0x30]
	cmp r0, #0
	beq _08057EA4
	movs r1, #8
_08057EA4:
	strb r1, [r5, #4]
	movs r0, #1
	strb r0, [r5, #8]
	str r2, [r5, #0x14]
	b _080581CA
_08057EAE:
	ldrh r0, [r6, #0xa]
	cmp r0, #1
	bne _08057ECC
	ldr r2, _08057EC8 @ =0x085AB9A4
	ldrh r1, [r6, #8]
	movs r0, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r0, r0, #4
	asrs r0, r0, #6
	b _08057ECE
	.align 2, 0
_08057EC8: .4byte 0x085AB9A4
_08057ECC:
	movs r0, #0
_08057ECE:
	movs r4, #0
	strb r0, [r5, #6]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08057EDA
	b _080581A0
_08057EDA:
	adds r2, r5, #0
	adds r2, #0x4c
	movs r6, #0x1c
	ldrsh r1, [r5, r6]
	movs r3, #0x1c
	ldrsh r0, [r2, r3]
	subs r3, r1, r0
	movs r6, #0x1e
	ldrsh r1, [r5, r6]
	movs r6, #0x20
	ldrsh r0, [r2, r6]
	subs r1, r1, r0
	adds r0, r3, #0
	cmp r3, #0
	bge _08057EFA
	rsbs r0, r3, #0
_08057EFA:
	cmp r0, #0x17
	bgt _08057F36
	adds r0, r1, #0
	cmp r1, #0
	bge _08057F06
	rsbs r0, r1, #0
_08057F06:
	cmp r0, #0x17
	bgt _08057F28
	strb r4, [r5, #6]
	movs r0, #0xff
	strb r0, [r5, #0xb]
	movs r3, #1
	mov r7, sl
	ldr r1, [r7, #0x30]
	rsbs r0, r1, #0
	orrs r0, r1
	asrs r0, r0, #0x1f
	movs r1, #8
	ands r0, r1
	strb r0, [r5, #4]
	strb r3, [r5, #8]
	str r4, [r5, #0x14]
	b _080581CA
_08057F28:
	mvns r0, r1
	asrs r2, r0, #0x1f
	movs r0, #2
	ands r2, r0
	movs r6, #1
	ldrb r4, [r5, #0xb]
	b _08057F8A
_08057F36:
	adds r0, r1, #0
	cmp r1, #0
	bge _08057F3E
	rsbs r0, r1, #0
_08057F3E:
	cmp r0, #0x17
	bgt _08057F56
	movs r2, #1
	cmp r3, #0
	bge _08057F4A
	movs r2, #3
_08057F4A:
	mvns r0, r1
	asrs r6, r0, #0x1f
	movs r0, #2
	ands r6, r0
	ldrb r4, [r5, #0xb]
	b _08057F90
_08057F56:
	movs r0, #0xb
	ldrsb r0, [r5, r0]
	ldrb r4, [r5, #0xb]
	cmp r0, #0
	blt _08057F66
	movs r0, #1
	ands r0, r4
	b _08057F6A
_08057F66:
	movs r0, #1
	ands r0, r7
_08057F6A:
	cmp r0, #0
	bne _08057F80
	movs r2, #1
	cmp r3, #0
	bge _08057F76
	movs r2, #3
_08057F76:
	mvns r0, r1
	asrs r6, r0, #0x1f
	movs r0, #2
	ands r6, r0
	b _08057F90
_08057F80:
	mvns r0, r1
	asrs r2, r0, #0x1f
	movs r0, #2
	ands r2, r0
	movs r6, #1
_08057F8A:
	cmp r3, #0
	bge _08057F90
	movs r6, #3
_08057F90:
	lsls r0, r4, #0x18
	cmp r0, #0
	blt _08057FA6
	movs r0, #1
	adds r1, r6, #0
	ands r1, r0
	ands r0, r4
	cmp r1, r0
	bne _08057FA6
	movs r6, #0xb
	ldrsb r6, [r5, r6]
_08057FA6:
	str r5, [sp, #0x10]
	mov r8, r2
	str r6, [sp, #0x14]
	ldrb r0, [r5, #6]
	mov sb, r0
	adds r1, r5, #0
	adds r1, #0x20
	str r1, [sp, #0x18]
_08057FB6:
	ldr r0, [sp, #0x10]
	adds r0, #0x68
	ldrh r0, [r0]
	ldr r1, _08057FEC @ =0xFFFF0000
	ldr r3, [sp, #4]
	ands r3, r1
	orrs r3, r0
	str r3, [sp, #4]
	ldr r0, [sp, #0x10]
	adds r0, #0x6c
	ldrh r0, [r0]
	add r4, sp, #4
	ldr r2, [sp, #8]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, #8]
	movs r0, #1
	mov r7, r8
	ands r0, r7
	cmp r0, #0
	bne _08058000
	cmp r7, #0
	bne _08057FF0
	ldrh r0, [r4, #4]
	mov r3, sb
	subs r0, r0, r3
	b _08057FF4
	.align 2, 0
_08057FEC: .4byte 0xFFFF0000
_08057FF0:
	ldrh r0, [r4, #4]
	add r0, sb
_08057FF4:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	b _08058020
_08058000:
	mov r7, r8
	cmp r7, #1
	bne _0805800E
	add r0, sp, #4
	ldrh r0, [r0]
	add r0, sb
	b _08058016
_0805800E:
	add r0, sp, #4
	ldrh r0, [r0]
	mov r2, sb
	subs r0, r0, r2
_08058016:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #4]
_08058020:
	add r1, sp, #4
	adds r0, r1, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08058048
	cmp r1, #0
	blt _08058048
	ldr r0, _0805804C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08058048
	ldr r0, _08058050 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08058054
_08058048:
	movs r4, #0
	b _08058062
	.align 2, 0
_0805804C: .4byte 0x030046A8
_08058050: .4byte 0x030046AC
_08058054:
	ldr r0, _08058074 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08058062:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08058078
	adds r0, #4
	b _08058084
	.align 2, 0
_08058074: .4byte 0x030046A4
_08058078:
	ldr r0, _080580BC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08058084:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08058120
	add r7, sp, #4
	adds r0, r7, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080580B6
	cmp r1, #0
	blt _080580B6
	ldr r0, _080580C0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080580B6
	ldr r0, _080580C4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080580C8
_080580B6:
	movs r4, #0
	b _080580D6
	.align 2, 0
_080580BC: .4byte 0x030046A4
_080580C0: .4byte 0x030046A8
_080580C4: .4byte 0x030046AC
_080580C8:
	ldr r0, _080580E8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080580D6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080580EC
	adds r0, #4
	b _080580F8
	.align 2, 0
_080580E8: .4byte 0x030046A4
_080580EC:
	ldr r0, _0805810C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080580F8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08058110
	cmp r2, #2
	beq _08058114
	b _08058118
	.align 2, 0
_0805810C: .4byte 0x030046A4
_08058110:
	ldrb r0, [r7, #4]
	b _08058116
_08058114:
	ldrb r0, [r7]
_08058116:
	subs r1, r1, r0
_08058118:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	beq _08058136
_08058120:
	ldr r3, [sp, #0x14]
	cmp r3, #0
	blt _08058130
	mov r8, r3
	movs r7, #1
	rsbs r7, r7, #0
	str r7, [sp, #0x14]
	b _08057FB6
_08058130:
	movs r2, #1
	rsbs r2, r2, #0
	b _08058138
_08058136:
	mov r2, r8
_08058138:
	cmp r2, r6
	bne _08058140
	strb r2, [r5, #0xb]
	b _08058144
_08058140:
	movs r0, #0xff
	strb r0, [r5, #0xb]
_08058144:
	cmp r2, #0
	bge _0805814C
	movs r2, #0
	strb r2, [r5, #6]
_0805814C:
	strb r2, [r5, #5]
	movs r3, #0
	ldrb r1, [r5, #5]
	ldrb r0, [r5, #6]
	ldr r2, [sp, #0x18]
	strh r3, [r2, #2]
	cmp r1, #1
	beq _08058178
	cmp r1, #1
	bgt _08058166
	cmp r1, #0
	beq _08058170
	b _0805818C
_08058166:
	cmp r1, #2
	beq _0805817E
	cmp r1, #3
	beq _08058184
	b _0805818C
_08058170:
	strh r3, [r5, #0x20]
	rsbs r0, r0, #0
	strh r0, [r2, #4]
	b _0805818C
_08058178:
	strh r0, [r5, #0x20]
	strh r3, [r2, #4]
	b _0805818C
_0805817E:
	strh r3, [r5, #0x20]
	strh r0, [r2, #4]
	b _0805818C
_08058184:
	rsbs r0, r0, #0
	strh r0, [r5, #0x20]
	ldr r0, [sp, #0x18]
	strh r3, [r0, #4]
_0805818C:
	ldrh r0, [r5, #0x20]
	ldr r1, [sp, #0xc]
	ldrh r1, [r1, #0x1c]
	adds r0, r0, r1
	ldr r2, [sp, #0xc]
	strh r0, [r2, #0x1c]
	ldrh r0, [r5, #0x24]
	ldrh r3, [r2, #0x20]
	adds r0, r0, r3
	strh r0, [r2, #0x20]
_080581A0:
	mov r0, sl
	adds r1, r5, #0
	bl FUN_08056a34
	cmp r0, #0
	beq _080581C4
	movs r2, #2
	mov r6, sl
	ldr r0, [r6, #0x30]
	cmp r0, #0
	beq _080581B8
	movs r2, #8
_080581B8:
	movs r1, #0
	strb r2, [r5, #4]
	movs r0, #1
	strb r0, [r5, #8]
	str r1, [r5, #0x14]
	b _080581CA
_080581C4:
	ldr r0, [r5, #0x14]
	adds r0, #1
	str r0, [r5, #0x14]
_080581CA:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080581dc
FUN_080581dc: @ 0x080581DC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	mov r8, r0
	adds r4, r1, #0
	adds r7, r4, #0
	adds r7, #0x4c
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _08058262
	movs r0, #0
	strb r0, [r4, #8]
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [r4, #0x28]
	str r1, [r4, #0x2c]
	ldr r0, _08058280 @ =0x00000EBC
	add r0, r8
	ldr r2, [r0]
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	movs r3, #0x28
	ldrsh r1, [r4, r3]
	subs r0, r0, r1
	movs r3, #0x30
	ldrsh r1, [r2, r3]
	movs r3, #0x2c
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r4, #0xd]
	ldrb r0, [r4, #0xd]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r2, r1, #0
	strb r1, [r4, #5]
	adds r5, r4, #0
	adds r5, #0x78
	mov r0, r8
	ldr r1, [r0, #0x18]
	movs r3, #0
	subs r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08058248
	movs r3, #1
_08058248:
	movs r0, #0
	cmp r2, #1
	bls _08058250
	movs r0, #1
_08058250:
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #1
	bl FUN_08236fac
	adds r0, r5, #0
	movs r1, #0x10
	bl FUN_08237098
_08058262:
	ldr r2, _08058284 @ =0x085B0A08
	ldr r0, [r4, #0x14]
	lsls r0, r0, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	adds r6, r2, #0
	cmp r0, #0
	blt _08058288
	asrs r0, r0, #0xc
	b _0805828E
	.align 2, 0
_08058280: .4byte 0x00000EBC
_08058284: .4byte 0x085B0A08
_08058288:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805828E:
	adds r2, r0, #0
	adds r3, r4, #0
	adds r3, #0x20
	ldrb r5, [r4, #0xd]
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080582B0
	asrs r1, r0, #0xc
	b _080582B6
_080582B0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080582B6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080582CE
	asrs r0, r0, #0xc
	b _080582D4
_080582CE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080582D4:
	strh r0, [r3, #4]
	ldr r0, [r4, #0x14]
	subs r0, #8
	cmp r0, #7
	bhi _080582E6
	ldrb r1, [r4, #0xa]
	movs r0, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
_080582E6:
	ldrh r0, [r4, #0x20]
	ldrh r3, [r4, #0x28]
	adds r0, r0, r3
	lsls r0, r0, #0x10
	ldr r2, _0805833C @ =0xFFFF0000
	ldrh r1, [r4, #0x22]
	ldrh r3, [r4, #0x2a]
	adds r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp, #4]
	ldrh r0, [r4, #0x24]
	ldrh r1, [r4, #0x2c]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	add r6, sp, #4
	adds r0, r6, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08058338
	cmp r1, #0
	blt _08058338
	ldr r0, _08058340 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08058338
	ldr r0, _08058344 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08058348
_08058338:
	movs r5, #0
	b _08058356
	.align 2, 0
_0805833C: .4byte 0xFFFF0000
_08058340: .4byte 0x030046A8
_08058344: .4byte 0x030046AC
_08058348:
	ldr r0, _08058368 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08058356:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0805836C
	adds r0, #4
	b _08058378
	.align 2, 0
_08058368: .4byte 0x030046A4
_0805836C:
	ldr r0, _080583AC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08058378:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08058412
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080583A6
	cmp r1, #0
	blt _080583A6
	ldr r0, _080583B0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080583A6
	ldr r0, _080583B4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080583B8
_080583A6:
	movs r5, #0
	b _080583C6
	.align 2, 0
_080583AC: .4byte 0x030046A4
_080583B0: .4byte 0x030046A8
_080583B4: .4byte 0x030046AC
_080583B8:
	ldr r0, _080583D8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_080583C6:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080583DC
	adds r0, #4
	b _080583E8
	.align 2, 0
_080583D8: .4byte 0x030046A4
_080583DC:
	ldr r0, _080583FC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080583E8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08058400
	cmp r2, #2
	beq _08058404
	b _08058408
	.align 2, 0
_080583FC: .4byte 0x030046A4
_08058400:
	ldrb r0, [r6, #4]
	b _08058406
_08058404:
	ldrb r0, [r6]
_08058406:
	subs r1, r1, r0
_08058408:
	movs r0, #0x80
	lsls r0, r0, #1
	movs r2, #0
	cmp r1, r0
	beq _08058414
_08058412:
	movs r2, #1
_08058414:
	cmp r2, #0
	beq _08058420
	movs r2, #0
	mov r3, r8
	ldr r1, [r3, #0x30]
	b _0805843A
_08058420:
	add r0, sp, #4
	ldrh r0, [r0]
	strh r0, [r7, #0x1c]
	add r1, sp, #4
	ldrh r0, [r1, #2]
	strh r0, [r7, #0x1e]
	ldrh r0, [r1, #4]
	strh r0, [r7, #0x20]
	ldr r0, [r4, #0x14]
	cmp r0, #0x1f
	bls _0805844E
	mov r0, r8
	ldr r1, [r0, #0x30]
_0805843A:
	rsbs r0, r1, #0
	orrs r0, r1
	asrs r0, r0, #0x1f
	movs r1, #8
	ands r0, r1
	strb r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #8]
	str r2, [r4, #0x14]
	b _08058452
_0805844E:
	adds r0, #1
	str r0, [r4, #0x14]
_08058452:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08058460
FUN_08058460: @ 0x08058460
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	mov r8, r0
	adds r5, r1, #0
	adds r7, r5, #0
	adds r7, #0x4c
	ldrb r0, [r5, #8]
	cmp r0, #0
	beq _0805853C
	movs r0, #0
	strb r0, [r5, #8]
	adds r0, r5, #0
	adds r0, #0xd8
	bl FUN_08013698
	adds r6, r5, #0
	adds r6, #0x68
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080584AC
	cmp r1, #0
	blt _080584AC
	ldr r0, _080584B0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080584AC
	ldr r0, _080584B4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080584B8
_080584AC:
	movs r4, #0
	b _080584C6
	.align 2, 0
_080584B0: .4byte 0x030046A8
_080584B4: .4byte 0x030046AC
_080584B8:
	ldr r0, _080584D8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080584C6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080584DC
	adds r0, #4
	b _080584E8
	.align 2, 0
_080584D8: .4byte 0x030046A4
_080584DC:
	ldr r0, _0805851C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080584E8:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0805853C
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08058516
	cmp r1, #0
	blt _08058516
	ldr r0, _08058520 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08058516
	ldr r0, _08058524 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08058528
_08058516:
	movs r0, #0
	b _08058536
	.align 2, 0
_0805851C: .4byte 0x030046A4
_08058520: .4byte 0x030046A8
_08058524: .4byte 0x030046AC
_08058528:
	ldr r0, _08058580 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_08058536:
	movs r1, #1
	bl FUN_08234224
_0805853C:
	mov r0, r8
	adds r1, r5, #0
	bl FUN_08056b08
	ldrh r0, [r5, #0x20]
	ldrh r1, [r7, #0x1c]
	adds r0, r0, r1
	strh r0, [r7, #0x1c]
	ldrh r1, [r5, #0x24]
	ldrh r2, [r7, #0x20]
	adds r1, r1, r2
	strh r1, [r7, #0x20]
	adds r6, r7, #0
	adds r6, #0x1c
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov sb, r6
	cmp r2, #0
	blt _0805857C
	cmp r1, #0
	blt _0805857C
	ldr r0, _08058584 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0805857C
	ldr r0, _08058588 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0805858C
_0805857C:
	movs r4, #0
	b _0805859A
	.align 2, 0
_08058580: .4byte 0x030046A4
_08058584: .4byte 0x030046A8
_08058588: .4byte 0x030046AC
_0805858C:
	ldr r0, _080585AC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0805859A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080585B0
	adds r0, #4
	b _080585BC
	.align 2, 0
_080585AC: .4byte 0x030046A4
_080585B0:
	ldr r0, _080585D0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080585BC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080585D4
	cmp r2, #2
	beq _080585D8
	b _080585DC
	.align 2, 0
_080585D0: .4byte 0x030046A4
_080585D4:
	ldrb r0, [r6, #4]
	b _080585DA
_080585D8:
	ldrb r0, [r6]
_080585DA:
	subs r1, r1, r0
_080585DC:
	adds r3, r1, #0
	ldr r2, _080585FC @ =0x085B0A08
	ldr r0, [r5, #0x14]
	lsls r0, r0, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xfa
	muls r0, r1, r0
	cmp r0, #0
	blt _08058600
	asrs r0, r0, #0xc
	b _08058606
	.align 2, 0
_080585FC: .4byte 0x085B0A08
_08058600:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08058606:
	adds r0, r3, r0
	strh r0, [r7, #0x1e]
	movs r0, #0x20
	ldrsh r1, [r5, r0]
	cmp r1, #0
	bge _08058614
	rsbs r1, r1, #0
_08058614:
	movs r2, #0x24
	ldrsh r0, [r5, r2]
	cmp r0, #0
	bge _0805861E
	rsbs r0, r0, #0
_0805861E:
	cmp r1, r0
	bge _08058638
	adds r0, r5, #0
	adds r0, #0x78
	mov r2, r8
	ldr r1, [r2, #0x18]
	movs r2, #0
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
	b _0805864C
_08058638:
	adds r0, r5, #0
	adds r0, #0x78
	mov r2, r8
	ldr r1, [r2, #0x18]
	movs r2, #1
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
_0805864C:
	ldrb r0, [r5, #0xa]
	movs r1, #1
	orrs r1, r0
	strb r1, [r5, #0xa]
	ldr r0, [r5, #0x14]
	cmp r0, #0x1f
	bhi _0805865C
	b _080587B4
_0805865C:
	movs r1, #4
	mov r2, r8
	ldr r0, [r2, #0x30]
	cmp r0, #0
	beq _08058668
	movs r1, #8
_08058668:
	strb r1, [r5, #4]
	movs r0, #1
	strb r0, [r5, #8]
	movs r0, #0
	str r0, [r5, #0x14]
	mov r6, sb
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08058698
	cmp r1, #0
	blt _08058698
	ldr r0, _0805869C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08058698
	ldr r0, _080586A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080586A4
_08058698:
	movs r4, #0
	b _080586B2
	.align 2, 0
_0805869C: .4byte 0x030046A8
_080586A0: .4byte 0x030046AC
_080586A4:
	ldr r0, _080586C4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080586B2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080586C8
	adds r0, #4
	b _080586D4
	.align 2, 0
_080586C4: .4byte 0x030046A4
_080586C8:
	ldr r0, _080586E8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080586D4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080586EC
	cmp r2, #2
	beq _080586F0
	b _080586F4
	.align 2, 0
_080586E8: .4byte 0x030046A4
_080586EC:
	ldrb r0, [r6, #4]
	b _080586F2
_080586F0:
	ldrb r0, [r6]
_080586F2:
	subs r1, r1, r0
_080586F4:
	strh r1, [r7, #0x1e]
	mov r6, sb
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0805871C
	cmp r1, #0
	blt _0805871C
	ldr r0, _08058720 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0805871C
	ldr r0, _08058724 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08058728
_0805871C:
	movs r4, #0
	b _08058736
	.align 2, 0
_08058720: .4byte 0x030046A8
_08058724: .4byte 0x030046AC
_08058728:
	ldr r0, _08058748 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08058736:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0805874C
	adds r0, #4
	b _08058758
	.align 2, 0
_08058748: .4byte 0x030046A4
_0805874C:
	ldr r0, _0805878C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08058758:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080587AC
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08058786
	cmp r1, #0
	blt _08058786
	ldr r0, _08058790 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08058786
	ldr r0, _08058794 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08058798
_08058786:
	movs r0, #0
	b _080587A6
	.align 2, 0
_0805878C: .4byte 0x030046A4
_08058790: .4byte 0x030046A8
_08058794: .4byte 0x030046AC
_08058798:
	ldr r0, _080587C8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080587A6:
	movs r1, #1
	bl FUN_08234224
_080587AC:
	adds r0, r5, #0
	adds r0, #0xd8
	bl FUN_080136b4
_080587B4:
	ldr r0, [r5, #0x14]
	adds r0, #1
	str r0, [r5, #0x14]
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080587C8: .4byte 0x030046A4

	thumb_func_start FUN_080587cc
FUN_080587cc: @ 0x080587CC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	mov r8, r0
	adds r5, r1, #0
	mov sb, r2
	adds r6, r5, #0
	adds r6, #0x4c
	ldrb r0, [r5, #8]
	cmp r0, #0
	beq _080588AC
	movs r0, #0
	strb r0, [r5, #8]
	adds r0, r5, #0
	adds r0, #0xd8
	bl FUN_08013698
	adds r7, r5, #0
	adds r7, #0x68
	ldrh r0, [r6, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0805881A
	cmp r1, #0
	blt _0805881A
	ldr r0, _08058820 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0805881A
	ldr r0, _08058824 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08058828
_0805881A:
	movs r4, #0
	b _08058836
	.align 2, 0
_08058820: .4byte 0x030046A8
_08058824: .4byte 0x030046AC
_08058828:
	ldr r0, _08058848 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08058836:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0805884C
	adds r0, #4
	b _08058858
	.align 2, 0
_08058848: .4byte 0x030046A4
_0805884C:
	ldr r0, _0805888C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08058858:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080588AC
	ldrh r0, [r7]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08058886
	cmp r1, #0
	blt _08058886
	ldr r0, _08058890 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08058886
	ldr r0, _08058894 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08058898
_08058886:
	movs r0, #0
	b _080588A6
	.align 2, 0
_0805888C: .4byte 0x030046A4
_08058890: .4byte 0x030046A8
_08058894: .4byte 0x030046AC
_08058898:
	ldr r0, _08058930 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080588A6:
	movs r1, #1
	bl FUN_08234224
_080588AC:
	ldr r4, [r5, #0x14]
	movs r0, #7
	ands r4, r0
	adds r7, r6, #0
	adds r7, #0x1c
	cmp r4, #0
	bne _080588F0
	ldr r2, _08058934 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08058938 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0805893C @ =0x0203B400
	adds r0, r0, r1
	ldrb r3, [r0]
	movs r0, #0x20
	str r0, [sp]
	movs r0, #6
	str r0, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	movs r0, #3
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r0, #0x10
	str r0, [sp, #0x14]
	str r4, [sp, #0x18]
	movs r0, #3
	movs r1, #9
	adds r2, r7, #0
	bl FUN_080149dc
_080588F0:
	mov r0, r8
	adds r1, r5, #0
	bl FUN_08056b08
	ldrh r0, [r5, #0x20]
	ldrh r2, [r6, #0x1c]
	adds r0, r0, r2
	strh r0, [r6, #0x1c]
	ldrh r1, [r5, #0x24]
	ldrh r2, [r6, #0x20]
	adds r1, r1, r2
	strh r1, [r6, #0x20]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0805892A
	cmp r1, #0
	blt _0805892A
	ldr r0, _08058940 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0805892A
	ldr r0, _08058944 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08058948
_0805892A:
	movs r4, #0
	b _08058956
	.align 2, 0
_08058930: .4byte 0x030046A4
_08058934: .4byte 0x030046B8
_08058938: .4byte 0x000003FF
_0805893C: .4byte 0x0203B400
_08058940: .4byte 0x030046A8
_08058944: .4byte 0x030046AC
_08058948:
	ldr r0, _08058968 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08058956:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0805896C
	adds r0, #4
	b _08058978
	.align 2, 0
_08058968: .4byte 0x030046A4
_0805896C:
	ldr r0, _0805898C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08058978:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08058990
	cmp r2, #2
	beq _08058994
	b _08058998
	.align 2, 0
_0805898C: .4byte 0x030046A4
_08058990:
	ldrb r0, [r7, #4]
	b _08058996
_08058994:
	ldrb r0, [r7]
_08058996:
	subs r1, r1, r0
_08058998:
	adds r3, r1, #0
	ldr r2, _080589B8 @ =0x085B0A08
	ldr r0, [r5, #0x14]
	lsls r0, r0, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xfa
	muls r0, r1, r0
	cmp r0, #0
	blt _080589BC
	asrs r0, r0, #0xc
	b _080589C2
	.align 2, 0
_080589B8: .4byte 0x085B0A08
_080589BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080589C2:
	adds r0, r3, r0
	strh r0, [r6, #0x1e]
	movs r0, #0x20
	ldrsh r1, [r5, r0]
	cmp r1, #0
	bge _080589D0
	rsbs r1, r1, #0
_080589D0:
	movs r2, #0x24
	ldrsh r0, [r5, r2]
	cmp r0, #0
	bge _080589DA
	rsbs r0, r0, #0
_080589DA:
	cmp r1, r0
	bge _080589F4
	adds r0, r5, #0
	adds r0, #0x78
	mov r2, r8
	ldr r1, [r2, #0x18]
	movs r2, #0
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
	b _08058A08
_080589F4:
	adds r0, r5, #0
	adds r0, #0x78
	mov r2, r8
	ldr r1, [r2, #0x18]
	movs r2, #1
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
_08058A08:
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r1, [r5, #0x14]
	cmp r1, #7
	bls _08058A26
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne _08058A3A
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	b _08058A42
_08058A26:
	cmp r1, #0xf
	bls _08058A44
	movs r0, #3
	ands r1, r0
	cmp r1, #2
	bhi _08058A3A
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	b _08058A42
_08058A3A:
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
_08058A42:
	str r0, [r6]
_08058A44:
	ldr r0, [r5, #0x14]
	cmp r0, #0x1f
	bls _08058A84
	mov r0, r8
	adds r1, r5, #0
	bl FUN_08057354
	adds r0, r5, #0
	adds r0, #0xd8
	bl FUN_080136b4
	adds r0, r6, #0
	bl FUN_0822a4e0
	mov r0, r8
	adds r1, r5, #0
	bl FUN_08057344
	movs r1, #1
	mov r0, sb
	lsls r1, r0
	mov r2, r8
	ldr r0, [r2, #0x1c]
	bics r0, r1
	str r0, [r2, #0x1c]
	ldr r0, [r2, #0x34]
	bl FUN_0807a798
	mov r1, r8
	ldr r0, [r1, #0x2c]
	adds r0, #1
	str r0, [r1, #0x2c]
_08058A84:
	ldr r0, [r5, #0x14]
	adds r0, #1
	str r0, [r5, #0x14]
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08058a98
FUN_08058a98: @ 0x08058A98
	push {r4, lr}
	sub sp, #4
	adds r2, r0, #0
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _08058ADA
	movs r0, #0
	strb r0, [r1, #8]
	adds r4, r1, #0
	adds r4, #0x78
	ldr r2, [r2, #0x18]
	movs r3, #0
	ldrb r1, [r1, #5]
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08058ABE
	movs r3, #1
_08058ABE:
	movs r0, #0
	cmp r1, #1
	bls _08058AC6
	movs r0, #1
_08058AC6:
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r2, #0
	movs r2, #0
	bl FUN_08236fac
	adds r0, r4, #0
	movs r1, #0x40
	bl FUN_08237098
_08058ADA:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08058ae4
FUN_08058ae4: @ 0x08058AE4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	mov r8, r0
	adds r4, r1, #0
	mov sb, r2
	adds r6, r4, #0
	adds r6, #0x4c
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _08058B16
	movs r0, #0
	strb r0, [r4, #8]
	adds r0, r4, #0
	adds r0, #0xd8
	bl FUN_08013698
	adds r0, r4, #0
	adds r0, #0x30
	movs r1, #0x99
	lsls r1, r1, #1
	bl FUN_0822b20c
_08058B16:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0xa
	strb r0, [r4, #9]
	ldr r5, [r4, #0x14]
	movs r0, #7
	ands r5, r0
	adds r7, r4, #0
	adds r7, #0x68
	cmp r5, #0
	bne _08058B66
	ldr r2, _08058B90 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08058B94 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08058B98 @ =0x0203B400
	adds r0, r0, r1
	ldrb r3, [r0]
	movs r0, #0x20
	str r0, [sp]
	movs r0, #6
	str r0, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	movs r0, #3
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r0, #0x10
	str r0, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #3
	movs r1, #9
	adds r2, r7, #0
	bl FUN_080149dc
_08058B66:
	ldrh r0, [r6, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08058B8A
	cmp r1, #0
	blt _08058B8A
	ldr r0, _08058B9C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08058B8A
	ldr r0, _08058BA0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08058BA4
_08058B8A:
	movs r5, #0
	b _08058BB2
	.align 2, 0
_08058B90: .4byte 0x030046B8
_08058B94: .4byte 0x000003FF
_08058B98: .4byte 0x0203B400
_08058B9C: .4byte 0x030046A8
_08058BA0: .4byte 0x030046AC
_08058BA4:
	ldr r0, _08058BC4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08058BB2:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08058BC8
	adds r0, #4
	b _08058BD4
	.align 2, 0
_08058BC4: .4byte 0x030046A4
_08058BC8:
	ldr r0, _08058BE8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08058BD4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08058BEC
	cmp r2, #2
	beq _08058BF0
	b _08058BF4
	.align 2, 0
_08058BE8: .4byte 0x030046A4
_08058BEC:
	ldrb r0, [r7, #4]
	b _08058BF2
_08058BF0:
	ldrb r0, [r7]
_08058BF2:
	subs r1, r1, r0
_08058BF4:
	adds r3, r1, #0
	ldr r2, _08058C14 @ =0x085B0A08
	ldr r0, [r4, #0x14]
	lsls r0, r0, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xfa
	muls r0, r1, r0
	cmp r0, #0
	blt _08058C18
	asrs r0, r0, #0xc
	b _08058C1E
	.align 2, 0
_08058C14: .4byte 0x085B0A08
_08058C18:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08058C1E:
	adds r0, r3, r0
	movs r2, #0
	strh r0, [r6, #0x1e]
	adds r0, r4, #0
	adds r0, #0x78
	mov r3, r8
	ldr r1, [r3, #0x18]
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
	ldr r1, [r4, #0x14]
	cmp r1, #7
	bls _08058C4C
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne _08058C60
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	b _08058C68
_08058C4C:
	cmp r1, #0xf
	bls _08058C6A
	movs r0, #3
	ands r1, r0
	cmp r1, #2
	bhi _08058C60
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	b _08058C68
_08058C60:
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
_08058C68:
	str r0, [r6]
_08058C6A:
	ldr r0, [r4, #0x14]
	cmp r0, #0x1f
	bls _08058C94
	adds r0, r4, #0
	adds r0, #0xd8
	bl FUN_080136b4
	adds r0, r6, #0
	bl FUN_0822a4e0
	mov r0, r8
	adds r1, r4, #0
	bl FUN_08057344
	movs r1, #1
	mov r0, sb
	lsls r1, r0
	mov r2, r8
	ldr r0, [r2, #0x1c]
	bics r0, r1
	str r0, [r2, #0x1c]
_08058C94:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08058ca8
FUN_08058ca8: @ 0x08058CA8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0
	strh r0, [r7, #0x24]
	strh r0, [r7, #0x26]
	adds r5, r7, #0
	adds r5, #0x5c
	mov sb, r0
	movs r0, #1
	mov sl, r0
	movs r1, #0xd4
	adds r1, r1, r7
	mov r8, r1
_08058CCC:
	mov r0, sl
	mov r2, sb
	lsls r0, r2
	ldr r1, [r7, #0x1c]
	ands r1, r0
	adds r3, r5, #0
	adds r3, #0x68
	str r3, [sp]
	cmp r1, #0
	bne _08058CE2
	b _08058E82
_08058CE2:
	adds r6, r5, #0
	adds r6, #0x4c
	mov r3, r8
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x78]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r3, #4]
	mov r2, sl
	ands r2, r0
	ldrh r1, [r4]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	mov r1, sl
	ands r0, r1
	cmp r2, r0
	beq _08058D14
	ldr r0, [r5, #0x4c]
	movs r1, #4
	orrs r0, r1
	b _08058D1C
_08058D14:
	ldr r0, [r5, #0x4c]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08058D1C:
	str r0, [r5, #0x4c]
	ldrb r0, [r3, #4]
	movs r1, #2
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	movs r2, #2
	ands r0, r2
	cmp r1, r0
	beq _08058D40
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _08058D48
_08058D40:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08058D48:
	str r0, [r6]
	ldrh r0, [r3, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xe]
	ldr r4, _08058D80 @ =0x0000FFFF
	adds r2, r4, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r4, [r3, #7]
	cmp r0, r4
	blo _08058DC6
	strh r1, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08058D8A
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _08058D84
	ldrb r0, [r3, #5]
	subs r0, #1
	strh r0, [r3, #8]
	movs r2, #1
	b _08058DA0
	.align 2, 0
_08058D80: .4byte 0x0000FFFF
_08058D84:
	subs r0, #1
	strh r0, [r3, #8]
	b _08058D9E
_08058D8A:
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _08058D9E
	strh r1, [r3, #8]
	movs r2, #1
	b _08058DA0
_08058D9E:
	movs r2, #0
_08058DA0:
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r3, #6]
	ldrb r1, [r3, #6]
	ldrh r0, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08058DC8
	mov r4, sl
	strb r4, [r3, #7]
	b _08058DC8
_08058DC6:
	movs r2, #0
_08058DC8:
	movs r0, #0
	strb r2, [r5, #7]
	strb r0, [r5, #0xa]
	ldr r1, [r7, #0x20]
	movs r2, #3
	ands r1, r2
	mov r0, sb
	ands r0, r2
	cmp r1, r0
	bne _08058E04
	ldr r1, _08058E30 @ =0x00000EBC
	adds r0, r7, r1
	ldr r1, [r0]
	movs r3, #0x2c
	ldrsh r2, [r1, r3]
	movs r4, #0x1c
	ldrsh r0, [r6, r4]
	subs r2, r2, r0
	movs r0, #0x30
	ldrsh r1, [r1, r0]
	movs r3, #0x20
	ldrsh r0, [r6, r3]
	subs r1, r1, r0
	adds r0, r2, #0
	muls r0, r2, r0
	adds r4, r1, #0
	muls r4, r1, r4
	adds r1, r4, #0
	adds r0, r0, r1
	str r0, [r5, #0x18]
_08058E04:
	ldr r1, _08058E34 @ =0x085AB9B4
	ldrb r0, [r5, #4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	bl _call_via_r3
	ldrb r1, [r5, #0xa]
	mov r0, sl
	ands r0, r1
	cmp r0, #0
	beq _08058E38
	mov r0, r8
	ldrh r1, [r0, #0x16]
	movs r0, #4
	orrs r0, r1
	mov r1, r8
	strh r0, [r1, #0x16]
	b _08058E50
	.align 2, 0
_08058E30: .4byte 0x00000EBC
_08058E34: .4byte 0x085AB9B4
_08058E38:
	mov r2, r8
	ldrh r0, [r2, #0x16]
	ldr r3, _08058EB0 @ =0x0000FFFB
	adds r1, r3, #0
	ands r0, r1
	strh r0, [r2, #0x16]
	adds r0, r5, #0
	adds r0, #0x88
	ldr r1, [sp]
	movs r2, #0
	bl FUN_082364c4
_08058E50:
	ldrb r1, [r5, #0xa]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08058E62
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_08057214
_08058E62:
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _08058E7C
	subs r0, #1
	strb r0, [r5, #9]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08058E7C
	adds r0, r5, #0
	adds r0, #0x30
	ldr r1, _08058EB4 @ =0x0000022A
	bl FUN_0822b20c
_08058E7C:
	ldrh r0, [r7, #0x26]
	adds r0, #1
	strh r0, [r7, #0x26]
_08058E82:
	movs r4, #1
	add sb, r4
	movs r0, #0x8c
	lsls r0, r0, #1
	add r8, r0
	adds r5, r5, r0
	mov r1, sb
	cmp r1, #0xb
	bgt _08058E96
	b _08058CCC
_08058E96:
	ldr r0, [r7, #0x20]
	adds r0, #1
	str r0, [r7, #0x20]
	movs r0, #0
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08058EB0: .4byte 0x0000FFFB
_08058EB4: .4byte 0x0000022A

	thumb_func_start FUN_08058eb8
FUN_08058eb8: @ 0x08058EB8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x5c
	movs r7, #0
_08058EC2:
	adds r0, r4, #0
	adds r0, #0xd8
	bl FUN_080138fc
	movs r6, #1
	lsls r6, r7
	ldr r0, [r5, #0x1c]
	ands r0, r6
	cmp r0, #0
	beq _08058EEC
	adds r0, r4, #0
	adds r0, #0x4c
	bl FUN_0822a4e0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08057344
	ldr r0, [r5, #0x1c]
	bics r0, r6
	str r0, [r5, #0x1c]
_08058EEC:
	adds r7, #1
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r4, r4, r0
	cmp r7, #0xb
	ble _08058EC2
	ldr r1, _08058F04 @ =0x0300012C
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08058F04: .4byte 0x0300012C

	thumb_func_start FUN_08058f08
FUN_08058f08: @ 0x08058F08
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r6, r3, #0
	ldr r0, _08058F70 @ =0x0300012C
	str r7, [r0]
	ldr r0, _08058F74 @ =0x0000922E
	ldr r1, _08058F78 @ =0x000031F4
	bl GetFile
	str r0, [r7, #0x18]
	adds r0, r7, #0
	bl FUN_080569f4
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_08057154
	str r5, [r7, #0x34]
	str r6, [r7, #0x38]
	movs r0, #0
	str r0, [r7, #0x1c]
	strh r0, [r7, #0x26]
	str r0, [r7, #0x28]
	str r0, [r7, #0x2c]
	str r0, [r7, #0x30]
	adds r6, r7, #0
	adds r6, #0x5c
	mov sb, r0
	mov r8, r0
_08058F4E:
	mov r0, r8
	strb r0, [r6, #6]
	strb r0, [r6, #5]
	adds r4, r6, #0
	adds r4, #0x30
	adds r0, r4, #0
	ldr r1, _08058F7C @ =0x000061F9
	bl FUN_0822b16c
	adds r5, r6, #0
	adds r5, #0x4c
	cmp r0, #0
	bne _08058F80
	movs r0, #1
	rsbs r0, r0, #0
	b _08058FE2
	.align 2, 0
_08058F70: .4byte 0x0300012C
_08058F74: .4byte 0x0000922E
_08058F78: .4byte 0x000031F4
_08058F7C: .4byte 0x000061F9
_08058F80:
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a4b0
	adds r0, r6, #0
	adds r0, #0x78
	ldr r1, [r7, #0x18]
	mov r2, r8
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
	movs r0, #2
	strb r0, [r5, #7]
	adds r5, r6, #0
	adds r5, #0x68
	mov r0, r8
	str r0, [sp, #4]
	add r0, sp, #4
	adds r1, r5, #0
	ldr r2, _08058FF0 @ =0x05000002
	bl CpuSet
	adds r4, r6, #0
	adds r4, #0xd8
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0801385c
	adds r0, r4, #0
	bl FUN_080136b4
	movs r2, #1
	add sb, r2
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r6, r6, r0
	mov r2, sb
	cmp r2, #0xb
	ble _08058F4E
	ldr r0, _08058FF4 @ =0x03002BE0
	ldr r1, [r0]
	ldr r2, _08058FF8 @ =0x00000EBC
	adds r0, r7, r2
	str r1, [r0]
	movs r0, #0
_08058FE2:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08058FF0: .4byte 0x05000002
_08058FF4: .4byte 0x03002BE0
_08058FF8: .4byte 0x00000EBC

	thumb_func_start FUN_08058ffc
FUN_08058ffc: @ 0x08058FFC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	ldr r0, _08059040 @ =0x0300012C
	ldr r0, [r0]
	cmp r0, #0
	bne _0805904E
	movs r1, #0xec
	lsls r1, r1, #4
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805904C
	ldr r1, _08059044 @ =FUN_08058ca8
	ldr r2, _08059048 @ =FUN_08058eb8
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	adds r3, r7, #0
	bl FUN_08058f08
	cmp r0, #0
	bge _0805904C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805904E
	.align 2, 0
_08059040: .4byte 0x0300012C
_08059044: .4byte FUN_08058ca8
_08059048: .4byte FUN_08058eb8
_0805904C:
	adds r0, r4, #0
_0805904E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08059054
FUN_08059054: @ 0x08059054
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	str r0, [sp, #4]
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	str r3, [sp, #0x10]
	ldr r1, _08059088 @ =0x0300012C
	ldr r5, [r1]
	cmp r5, #0
	bne _0805908C
	ldr r0, [sp, #0x48]
	movs r1, #1
	movs r2, #0
	bl FUN_08058ffc
	adds r5, r0, #0
	cmp r5, #0
	bne _0805908C
	movs r0, #1
	rsbs r0, r0, #0
	b _080591DA
	.align 2, 0
_08059088: .4byte 0x0300012C
_0805908C:
	movs r1, #0
	str r1, [sp, #0x14]
	mov sl, r1
	adds r2, r5, #0
	adds r2, #0xd4
	str r2, [sp, #0x18]
	adds r3, r5, #0
	adds r3, #0x8c
	str r3, [sp, #0x1c]
	movs r6, #0x7c
	adds r6, r6, r5
	mov r8, r6
	adds r4, r5, #0
	adds r4, #0x5c
	adds r1, r5, #0
	adds r1, #0xa8
	str r1, [sp, #0x20]
	str r4, [sp, #0x24]
_080590B0:
	movs r1, #1
	mov r2, sl
	lsls r1, r2
	ldr r2, [r5, #0x1c]
	ands r2, r1
	cmp r2, #0
	bne _080591AE
	ldr r7, [sp, #0x20]
	mov r3, sp
	ldrh r3, [r3, #0xc]
	strh r3, [r4]
	mov r6, sp
	ldrh r6, [r6, #0x10]
	strh r6, [r4, #2]
	mov r0, sp
	ldrb r0, [r0, #8]
	strb r0, [r4, #5]
	movs r3, #8
	strb r3, [r4, #6]
	ldrb r1, [r4, #5]
	movs r0, #8
	strh r2, [r4, #0x22]
	cmp r1, #1
	beq _080590FE
	cmp r1, #1
	bgt _080590EA
	cmp r1, #0
	beq _080590F4
	b _08059116
_080590EA:
	cmp r1, #2
	beq _08059106
	cmp r1, #3
	beq _0805910E
	b _08059116
_080590F4:
	strh r2, [r4, #0x20]
	rsbs r0, r0, #0
	mov r1, r8
	strh r0, [r1, #4]
	b _08059116
_080590FE:
	strh r0, [r4, #0x20]
	mov r3, r8
	strh r2, [r3, #4]
	b _08059116
_08059106:
	strh r2, [r4, #0x20]
	mov r6, r8
	strh r0, [r6, #4]
	b _08059116
_0805910E:
	rsbs r0, r3, #0
	strh r0, [r4, #0x20]
	mov r0, r8
	strh r2, [r0, #4]
_08059116:
	ldr r2, [sp, #0x4c]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	movs r6, #0
	strb r6, [r4, #9]
	strb r6, [r4, #0xa]
	movs r0, #0xff
	strb r0, [r4, #0xb]
	strb r6, [r4, #0x10]
	movs r3, #1
	mov sb, r3
	movs r1, #1
	ldr r0, [r5, #0x30]
	cmp r0, #0
	beq _0805913A
	movs r1, #8
_0805913A:
	strb r1, [r4, #4]
	mov r0, sb
	strb r0, [r4, #8]
	str r6, [r4, #0x14]
	ldr r0, [sp, #0x1c]
	ldr r1, _080591EC @ =0x0000022A
	bl FUN_0822b20c
	ldr r1, [r5, #0x18]
	str r6, [sp]
	ldr r0, [sp, #0x18]
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
	adds r0, r7, #0
	movs r1, #0
	bl FUN_0822a340
	adds r0, r5, #0
	ldr r1, [sp, #0x24]
	bl FUN_080572b8
	ldr r2, _080591F0 @ =0x00000EBC
	adds r1, r5, r2
	ldr r2, [r1]
	movs r6, #0x2c
	ldrsh r3, [r2, r6]
	movs r6, #0x1c
	ldrsh r1, [r7, r6]
	subs r3, r3, r1
	movs r1, #0x30
	ldrsh r2, [r2, r1]
	movs r6, #0x20
	ldrsh r1, [r7, r6]
	subs r2, r2, r1
	adds r1, r3, #0
	muls r1, r3, r1
	adds r3, r2, #0
	muls r3, r2, r3
	adds r2, r3, #0
	adds r1, r1, r2
	str r1, [r4, #0x18]
	mov r2, sb
	mov r6, sl
	lsls r2, r6
	ldr r1, [r5, #0x1c]
	orrs r1, r2
	str r1, [r5, #0x1c]
	ldr r1, [r5, #0x28]
	adds r1, #1
	str r1, [r5, #0x28]
	ldr r1, [sp, #0x14]
	adds r1, #1
	str r1, [sp, #0x14]
	ldr r2, [sp, #4]
	cmp r1, r2
	bge _080591DA
_080591AE:
	ldr r3, [sp, #0x18]
	movs r6, #0x8c
	lsls r6, r6, #1
	adds r3, r3, r6
	str r3, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	adds r1, r1, r6
	str r1, [sp, #0x1c]
	add r8, r6
	adds r4, r4, r6
	ldr r2, [sp, #0x20]
	adds r2, r2, r6
	str r2, [sp, #0x20]
	ldr r3, [sp, #0x24]
	adds r3, r3, r6
	str r3, [sp, #0x24]
	movs r6, #1
	add sl, r6
	mov r1, sl
	cmp r1, #0xb
	bgt _080591DA
	b _080590B0
_080591DA:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080591EC: .4byte 0x0000022A
_080591F0: .4byte 0x00000EBC

	thumb_func_start FUN_080591f4
FUN_080591f4: @ 0x080591F4
	push {lr}
	ldr r0, _08059204 @ =0x0300012C
	ldr r0, [r0]
	cmp r0, #0
	beq _08059208
	ldrh r0, [r0, #0x26]
	b _0805920A
	.align 2, 0
_08059204: .4byte 0x0300012C
_08059208:
	movs r0, #0
_0805920A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08059210
FUN_08059210: @ 0x08059210
	push {lr}
	ldr r0, _08059220 @ =0x0300012C
	ldr r0, [r0]
	cmp r0, #0
	beq _08059224
	ldr r0, [r0, #0x28]
	b _08059226
	.align 2, 0
_08059220: .4byte 0x0300012C
_08059224:
	movs r0, #0
_08059226:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805922c
FUN_0805922c: @ 0x0805922C
	push {lr}
	ldr r0, _0805923C @ =0x0300012C
	ldr r0, [r0]
	cmp r0, #0
	beq _08059240
	ldr r0, [r0, #0x2c]
	b _08059242
	.align 2, 0
_0805923C: .4byte 0x0300012C
_08059240:
	movs r0, #0
_08059242:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08059248
FUN_08059248: @ 0x08059248
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r1, _0805925C @ =0x0300012C
	ldr r5, [r1]
	cmp r5, #0
	bne _08059260
	movs r0, #0
	b _0805929A
	.align 2, 0
_0805925C: .4byte 0x0300012C
_08059260:
	movs r1, #1
	str r1, [r5, #0x30]
	movs r4, #0
	movs r6, #1
	movs r1, #8
	mov r8, r1
	mov ip, r4
	adds r3, r5, #0
	adds r3, #0x60
	movs r7, #0x8c
	lsls r7, r7, #1
_08059276:
	adds r2, r6, #0
	lsls r2, r4
	ldr r1, [r5, #0x1c]
	ands r1, r2
	cmp r1, #0
	beq _08059292
	ldrb r1, [r3]
	cmp r1, #5
	bhi _08059292
	mov r1, r8
	strb r1, [r3]
	strb r6, [r3, #4]
	mov r1, ip
	str r1, [r3, #0x10]
_08059292:
	adds r3, r3, r7
	adds r4, #1
	cmp r4, #0xb
	ble _08059276
_0805929A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080592a4
FUN_080592a4: @ 0x080592A4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r1, _080592B8 @ =0x0300012C
	ldr r5, [r1]
	cmp r5, #0
	bne _080592BC
	movs r0, #0
	b _080592F2
	.align 2, 0
_080592B8: .4byte 0x0300012C
_080592BC:
	movs r4, #0
	movs r6, #1
	movs r1, #9
	mov r8, r1
	mov ip, r4
	adds r3, r5, #0
	adds r3, #0x60
	movs r7, #0x8c
	lsls r7, r7, #1
_080592CE:
	adds r2, r6, #0
	lsls r2, r4
	ldr r1, [r5, #0x1c]
	ands r1, r2
	cmp r1, #0
	beq _080592EA
	ldrb r1, [r3]
	cmp r1, #7
	beq _080592EA
	mov r1, r8
	strb r1, [r3]
	strb r6, [r3, #4]
	mov r1, ip
	str r1, [r3, #0x10]
_080592EA:
	adds r3, r3, r7
	adds r4, #1
	cmp r4, #0xb
	ble _080592CE
_080592F2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080592fc
FUN_080592fc: @ 0x080592FC
	bx lr
	.align 2, 0

	thumb_func_start FUN_08059300
FUN_08059300: @ 0x08059300
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x1c
	adds r5, r0, #0
	mov r8, r1
	mov sb, r2
	adds r6, r3, #0
	adds r4, r5, #0
	adds r4, #0xc0
	ldr r2, _08059380 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x30
	orrs r0, r3
	ldr r1, _08059384 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _08059388 @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r1, _0805938C @ =FUN_080592fc
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0823651c
	movs r0, #0
	str r0, [sp]
	str r6, [sp, #4]
	adds r0, r4, #0
	mov r1, r8
	mov r2, sb
	movs r3, #0
	bl FUN_082364f8
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08059380: .4byte 0xFFFF0000
_08059384: .4byte 0x0000FFFF
_08059388: .4byte 0x00002001
_0805938C: .4byte FUN_080592fc

	thumb_func_start FUN_08059390
FUN_08059390: @ 0x08059390
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r4, r0, #0
	adds r3, r1, #0
	ldrb r0, [r2, #2]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0805941A
	movs r0, #3
	movs r1, #0
	strb r0, [r2, #2]
	strh r1, [r2, #6]
	movs r0, #1
	strb r0, [r2]
	ldrh r1, [r3, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r3, #6]
	adds r4, #0x42
	mov sl, r4
	ldrb r1, [r4]
	subs r1, #0x40
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r7, r2, #0
	adds r7, #0x50
	movs r0, #5
	mov sb, r0
	str r0, [sp]
	movs r0, #0xc0
	lsls r0, r0, #6
	mov r8, r0
	str r0, [sp, #4]
	movs r6, #0x20
	str r6, [sp, #8]
	movs r4, #0xa
	str r4, [sp, #0xc]
	str r4, [sp, #0x10]
	movs r5, #0xf8
	str r5, [sp, #0x14]
	adds r0, r7, #0
	movs r2, #0x20
	movs r3, #2
	bl FUN_08015c28
	mov r0, sl
	ldrb r1, [r0]
	adds r1, #0x40
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r0, sb
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r4, [sp, #0xc]
	str r4, [sp, #0x10]
	str r5, [sp, #0x14]
	adds r0, r7, #0
	movs r2, #0x20
	movs r3, #2
	bl FUN_08015c28
_0805941A:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805942c
FUN_0805942c: @ 0x0805942C
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x70
	ldr r2, _080594A4 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	orrs r0, r3
	ldr r1, _080594A8 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _080594AC @ =0x00004001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	adds r1, r5, #0
	adds r1, #0x50
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _080594B0 @ =FUN_08059390
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0823651c
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236514
	adds r0, r4, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080594A4: .4byte 0xFFFF0000
_080594A8: .4byte 0x0000FFFF
_080594AC: .4byte 0x00004001
_080594B0: .4byte FUN_08059390

	thumb_func_start FUN_080594b4
FUN_080594b4: @ 0x080594B4
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	adds r6, r1, #0
	adds r4, r6, #0
	adds r4, #0x18
	ldr r1, _080594D4 @ =0x000061F9
	adds r0, r4, #0
	bl FUN_0822b16c
	cmp r0, #0
	bne _080594D8
	movs r0, #1
	rsbs r0, r0, #0
	b _08059540
	.align 2, 0
_080594D4: .4byte 0x000061F9
_080594D8:
	movs r1, #0x89
	lsls r1, r1, #2
	adds r0, r4, #0
	bl FUN_0822b20c
	adds r0, r6, #0
	adds r0, #0x34
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a4b0
	adds r0, r6, #0
	adds r0, #0x60
	ldr r1, [r7, #0x18]
	movs r4, #0
	str r4, [sp]
	movs r2, #7
	movs r3, #0
	bl FUN_08236fac
	adds r1, r6, #0
	adds r1, #0x3b
	movs r0, #2
	strb r0, [r1]
	adds r5, r6, #0
	adds r5, #0x50
	str r4, [sp, #4]
	add r0, sp, #4
	adds r1, r5, #0
	ldr r2, _08059548 @ =0x05000002
	bl CpuSet
	ldrh r1, [r7, #0x24]
	ldrh r2, [r7, #0x26]
	ldrh r3, [r7, #0x28]
	adds r0, r6, #0
	bl FUN_08059300
	adds r0, r6, #0
	bl FUN_0805942c
	movs r0, #0x88
	lsls r0, r0, #1
	adds r4, r6, r0
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0801385c
	adds r0, r4, #0
	bl FUN_080136b4
_08059540:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059548: .4byte 0x05000002

	thumb_func_start FUN_0805954c
FUN_0805954c: @ 0x0805954C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r4, #1
	lsls r4, r2
	ldr r0, [r5, #0x1c]
	ands r0, r4
	cmp r0, #0
	beq _0805957A
	adds r0, r6, #0
	adds r0, #0x34
	bl FUN_0822a4e0
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r6, r1
	bl FUN_080136b4
	ldr r0, [r5, #0x1c]
	bics r0, r4
	str r0, [r5, #0x1c]
	movs r0, #0
	b _0805957E
_0805957A:
	movs r0, #1
	rsbs r0, r0, #0
_0805957E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08059584
FUN_08059584: @ 0x08059584
	push {r4, lr}
	adds r4, r1, #0
	bl FUN_0805954c
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_080138fc
	adds r4, #0x70
	adds r0, r4, #0
	bl FUN_08236424
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080595a4
FUN_080595a4: @ 0x080595A4
	movs r0, #0
	bx lr

	thumb_func_start FUN_080595a8
FUN_080595a8: @ 0x080595A8
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	movs r0, #0x34
	adds r0, r0, r4
	mov ip, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _080595BE
	movs r0, #0
	strb r0, [r4]
_080595BE:
	ldrb r0, [r4, #1]
	adds r0, #4
	strb r0, [r4, #1]
	adds r5, r4, #0
	adds r5, #0x50
	ldrb r6, [r4, #1]
	ldr r2, _080595E8 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #8
	adds r3, r5, #0
	cmp r0, #0
	blt _080595EC
	asrs r1, r0, #0xc
	b _080595F2
	.align 2, 0
_080595E8: .4byte 0x085B0A08
_080595EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080595F2:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #1
	muls r0, r1, r0
	cmp r0, #0
	blt _0805960E
	asrs r0, r0, #0xc
	b _08059614
_0805960E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08059614:
	strh r0, [r5, #4]
	adds r1, r7, #0
	adds r1, #0x34
	ldrh r0, [r7, #0x34]
	mov r5, ip
	ldrh r5, [r5, #0x1c]
	adds r0, r0, r5
	mov r2, ip
	strh r0, [r2, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r5, [r3, #2]
	adds r0, r0, r5
	strh r0, [r3, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r3, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
	adds r0, r4, #0
	adds r0, #0x70
	adds r1, r3, #0
	movs r2, #0
	bl FUN_082364c4
	ldrh r0, [r4, #6]
	cmp r0, #0x3f
	bls _08059654
	movs r0, #2
	strb r0, [r4, #2]
	movs r0, #0
	strh r0, [r4, #6]
	movs r0, #1
	strb r0, [r4]
_08059654:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805965c
FUN_0805965c: @ 0x0805965C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	mov r8, r0
	adds r6, r1, #0
	adds r7, r6, #0
	adds r7, #0x34
	ldrb r0, [r6]
	cmp r0, #0
	beq _080596E2
	movs r0, #0
	strb r0, [r6]
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [r6, #8]
	str r1, [r6, #0xc]
	ldr r0, _0805970C @ =0x00000ABC
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r6, #0x10]
	str r1, [r6, #0x14]
	adds r5, r6, #0
	adds r5, #8
	adds r4, r6, #0
	adds r4, #0x10
	movs r1, #0x10
	ldrsh r0, [r6, r1]
	movs r2, #8
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r4, r3]
	movs r3, #4
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r6, #1]
	movs r0, #0x10
	ldrsh r2, [r6, r0]
	movs r1, #8
	ldrsh r0, [r6, r1]
	subs r2, r2, r0
	movs r3, #4
	ldrsh r1, [r4, r3]
	movs r4, #4
	ldrsh r0, [r5, r4]
	subs r1, r1, r0
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	strh r0, [r6, #4]
	adds r2, r6, #0
	adds r2, #0x70
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_080596E2:
	ldrh r1, [r6, #4]
	ldrh r0, [r6, #6]
	muls r0, r1, r0
	add r3, sp, #0x14
	ldrb r4, [r6, #1]
	asrs r5, r0, #6
	ldr r2, _08059710 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	mov ip, r2
	cmp r0, #0
	blt _08059714
	asrs r1, r0, #0xc
	b _0805971A
	.align 2, 0
_0805970C: .4byte 0x00000ABC
_08059710: .4byte 0x085B0A08
_08059714:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805971A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	add r0, ip
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08059732
	asrs r0, r0, #0xc
	b _08059738
_08059732:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08059738:
	strh r0, [r3, #4]
	adds r2, r7, #0
	adds r2, #0x1c
	adds r3, r6, #0
	adds r3, #8
	add r1, sp, #0x14
	adds r0, r1, #0
	ldrh r0, [r0]
	ldrh r4, [r6, #8]
	adds r0, r0, r4
	strh r0, [r7, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r4, [r3, #2]
	adds r0, r0, r4
	strh r0, [r2, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	ldrh r0, [r6, #6]
	lsls r0, r0, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #9
	adds r5, r2, #0
	cmp r0, #0
	blt _0805977A
	asrs r1, r0, #0xc
	b _08059780
_0805977A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08059780:
	ldrh r0, [r6, #0xa]
	adds r1, r0, r1
	strh r1, [r7, #0x1e]
	ldrh r0, [r6, #6]
	cmp r0, #0x1f
	bls _080597A8
	lsls r1, r1, #0x10
	ldr r0, _080597FC @ =0x01FF0000
	cmp r1, r0
	bgt _080597A8
	adds r4, r6, #0
	adds r4, #0xc0
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
_080597A8:
	ldrh r0, [r6, #6]
	cmp r0, #0x3f
	bls _080597EC
	ldr r0, _08059800 @ =0x000003C3
	bl PlaySound_082406e0
	movs r0, #3
	movs r3, #0
	strb r0, [r6, #2]
	strh r3, [r6, #6]
	movs r0, #1
	strb r0, [r6]
	adds r2, r6, #0
	adds r2, #0x70
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	movs r2, #0x80
	lsls r2, r2, #1
	movs r0, #2
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	mov r4, r8
	ldrh r0, [r4, #0x2a]
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	str r5, [sp, #0x10]
	movs r0, #3
	movs r1, #0
	movs r3, #2
	bl FUN_08056774
_080597EC:
	movs r0, #0
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080597FC: .4byte 0x01FF0000
_08059800: .4byte 0x000003C3

	thumb_func_start FUN_08059804
FUN_08059804: @ 0x08059804
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08059818
	movs r0, #0
	strb r0, [r1]
	adds r0, r3, #0
	bl FUN_0805954c
_08059818:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08059820
FUN_08059820: @ 0x08059820
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r0, #0
	mov sl, r0
	adds r4, r7, #0
	adds r4, #0x3c
	mov r8, r0
	movs r1, #1
	mov sb, r1
_0805983A:
	mov r1, sb
	mov r2, r8
	lsls r1, r2
	ldr r0, [r7, #0x1c]
	ands r0, r1
	cmp r0, #0
	bne _0805984A
	b _08059956
_0805984A:
	ldr r1, _08059890 @ =0x085AB9DC
	ldrb r0, [r4, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	bl _call_via_r3
	adds r6, r4, #0
	adds r6, #0x34
	adds r3, r4, #0
	adds r3, #0x60
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r4, #0x60]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r3, #4]
	mov r2, sb
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	mov r1, sb
	ands r0, r1
	cmp r2, r0
	beq _08059894
	ldr r0, [r4, #0x34]
	movs r1, #4
	orrs r0, r1
	b _0805989C
	.align 2, 0
_08059890: .4byte 0x085AB9DC
_08059894:
	ldr r0, [r4, #0x34]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0805989C:
	str r0, [r4, #0x34]
	ldrb r0, [r3, #4]
	movs r1, #2
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	movs r2, #2
	ands r0, r2
	cmp r1, r0
	beq _080598C0
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _080598C8
_080598C0:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080598C8:
	str r0, [r6]
	ldrh r0, [r3, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xe]
	ldr r5, _08059900 @ =0x0000FFFF
	adds r2, r5, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r5, [r3, #7]
	cmp r0, r5
	blo _08059938
	strh r1, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08059904
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _080598F8
	ldrb r0, [r3, #5]
_080598F8:
	subs r0, #1
	strh r0, [r3, #8]
	b _08059914
	.align 2, 0
_08059900: .4byte 0x0000FFFF
_08059904:
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _08059914
	strh r1, [r3, #8]
_08059914:
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r3, #6]
	ldrb r1, [r3, #6]
	ldrh r0, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08059938
	mov r5, sb
	strb r5, [r3, #7]
_08059938:
	adds r0, r4, #0
	adds r0, #0x70
	adds r1, r4, #0
	adds r1, #0x50
	movs r2, #0
	bl FUN_082364c4
	ldrb r0, [r4, #2]
	cmp r0, #1
	bne _08059950
	movs r0, #1
	add sl, r0
_08059950:
	ldrh r0, [r4, #6]
	adds r0, #1
	strh r0, [r4, #6]
_08059956:
	movs r1, #1
	add r8, r1
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r4, r4, r2
	mov r5, r8
	cmp r5, #7
	bgt _08059968
	b _0805983A
_08059968:
	mov r0, sl
	str r0, [r7, #0x2c]
	ldr r0, [r7, #0x20]
	adds r0, #1
	str r0, [r7, #0x20]
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08059984
FUN_08059984: @ 0x08059984
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x3c
	movs r4, #0
_0805998E:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08059584
	adds r4, #1
	movs r0, #0xa8
	lsls r0, r0, #1
	adds r5, r5, r0
	cmp r4, #7
	ble _0805998E
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080599ac
FUN_080599ac: @ 0x080599AC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r6, r3, #0
	ldr r0, _08059A0C @ =0x0000922E
	ldr r1, _08059A10 @ =0x000031F4
	bl GetFile
	str r0, [r7, #0x18]
	strh r4, [r7, #0x24]
	strh r5, [r7, #0x26]
	strh r6, [r7, #0x28]
	mov r0, sp
	ldrh r0, [r0, #0x14]
	strh r0, [r7, #0x2a]
	adds r5, r7, #0
	adds r5, #0x3c
	movs r4, #0
_080599D2:
	adds r0, r7, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080594b4
	adds r4, #1
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r5, r5, r1
	cmp r4, #7
	ble _080599D2
	movs r1, #0xd0
	lsls r1, r1, #3
	strh r1, [r7, #0x34]
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r7, #0x36]
	movs r1, #0xf0
	lsls r1, r1, #3
	strh r1, [r7, #0x38]
	ldr r1, _08059A14 @ =0x03002BE0
	ldr r2, [r1]
	ldr r3, _08059A18 @ =0x00000ABC
	adds r1, r7, r3
	str r2, [r1]
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059A0C: .4byte 0x0000922E
_08059A10: .4byte 0x000031F4
_08059A14: .4byte 0x03002BE0
_08059A18: .4byte 0x00000ABC

	thumb_func_start FUN_08059a1c
FUN_08059a1c: @ 0x08059A1C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	movs r1, #0xac
	lsls r1, r1, #4
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08059A68
	ldr r1, _08059A60 @ =FUN_08059820
	ldr r2, _08059A64 @ =FUN_08059984
	bl SetEntityRoutine
	str r5, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl FUN_080599ac
	cmp r0, #0
	bge _08059A68
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08059A6A
	.align 2, 0
_08059A60: .4byte FUN_08059820
_08059A64: .4byte FUN_08059984
_08059A68:
	adds r0, r4, #0
_08059A6A:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08059a78
FUN_08059a78: @ 0x08059A78
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	cmp r0, #0
	bne _08059A8C
	movs r0, #1
	rsbs r0, r0, #0
	b _08059B6C
_08059A8C:
	adds r6, r0, #0
	movs r0, #0x3c
	adds r0, r0, r6
	mov ip, r0
	movs r7, #0
	movs r3, #1
	mov r8, r3
	movs r5, #0x34
	adds r5, r5, r6
	mov sl, r5
_08059AA0:
	mov r0, r8
	lsls r0, r7
	ldr r3, [r6, #0x1c]
	ands r3, r0
	cmp r3, #0
	bne _08059B5E
	mov r4, ip
	adds r4, #0x34
	mov r5, r8
	mov r0, ip
	strb r5, [r0, #2]
	strh r3, [r0, #6]
	strb r5, [r0]
	strb r1, [r0, #1]
	strb r2, [r0, #3]
	ldrh r1, [r6, #0x24]
	adds r0, #0xfc
	strh r1, [r0]
	mov r3, ip
	adds r3, #0x50
	mov r0, ip
	ldrb r5, [r0, #1]
	movs r1, #0x80
	lsls r1, r1, #1
	mov sb, r1
	ldr r2, _08059AF0 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #8
	cmp r0, #0
	blt _08059AF4
	asrs r1, r0, #0xc
	b _08059AFA
	.align 2, 0
_08059AF0: .4byte 0x085B0A08
_08059AF4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08059AFA:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r5, sb
	muls r5, r0, r5
	adds r0, r5, #0
	cmp r0, #0
	blt _08059B16
	asrs r0, r0, #0xc
	b _08059B1C
_08059B16:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08059B1C:
	strh r0, [r3, #4]
	adds r1, r4, #0
	adds r1, #0x1c
	ldrh r0, [r6, #0x34]
	ldrh r2, [r4, #0x1c]
	adds r0, r0, r2
	strh r0, [r4, #0x1c]
	mov r3, sl
	ldrh r0, [r3, #2]
	ldrh r5, [r1, #2]
	adds r0, r0, r5
	strh r0, [r1, #2]
	ldrh r0, [r3, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	movs r0, #0x88
	lsls r0, r0, #1
	add r0, ip
	bl FUN_08013698
	movs r0, #0x29
	strh r0, [r4, #0x10]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0822a340
	mov r1, r8
	lsls r1, r7
	ldr r0, [r6, #0x1c]
	orrs r0, r1
	str r0, [r6, #0x1c]
	b _08059B6A
_08059B5E:
	adds r7, #1
	movs r3, #0xa8
	lsls r3, r3, #1
	add ip, r3
	cmp r7, #7
	ble _08059AA0
_08059B6A:
	movs r0, #0
_08059B6C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08059b7c
FUN_08059b7c: @ 0x08059B7C
	push {r4, r5, r6, lr}
	adds r4, r1, #0
	movs r2, #0
	movs r6, #1
	ldr r1, [r0, #0x18]
	adds r3, r0, #0
	adds r3, #0x20
	movs r5, #0x82
	lsls r5, r5, #1
_08059B8E:
	adds r0, r6, #0
	lsls r0, r2
	ands r0, r1
	cmp r0, #0
	bne _08059B9E
	str r2, [r4]
	adds r0, r3, #0
	b _08059BA8
_08059B9E:
	adds r3, r3, r5
	adds r2, #1
	cmp r2, #7
	ble _08059B8E
	movs r0, #0
_08059BA8:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08059bb0
FUN_08059bb0: @ 0x08059BB0
	push {lr}
	movs r0, #5
	movs r1, #0
	strb r0, [r2, #2]
	movs r0, #1
	strb r0, [r2, #1]
	strh r1, [r2, #8]
	movs r0, #0xb8
	lsls r0, r0, #1
	bl PlaySound_082406e0
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08059bcc
FUN_08059bcc: @ 0x08059BCC
	bx lr
	.align 2, 0

	thumb_func_start FUN_08059bd0
FUN_08059bd0: @ 0x08059BD0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	str r0, [sp, #0x20]
	mov sl, r1
	movs r1, #0
	movs r6, #0
	movs r0, #1
	mov r2, sl
	strb r0, [r2, #2]
	strb r0, [r2, #1]
	strh r6, [r2, #8]
	strb r1, [r2, #0xd]
	strb r1, [r2, #0xc]
	mov r4, sl
	adds r4, #0xbc
	mov r5, sl
	adds r5, #0xe8
	ldr r1, _08059CFC @ =0x00005292
	adds r0, r5, #0
	bl FUN_0822b16c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #3
	bl FUN_0822a470
	movs r0, #3
	strh r0, [r4, #0x10]
	movs r0, #2
	strb r0, [r4, #7]
	movs r0, #0xd8
	add r0, sl
	mov r8, r0
	str r6, [sp, #0xc]
	add r0, sp, #0xc
	mov r1, r8
	ldr r2, _08059D00 @ =0x05000002
	bl CpuSet
	mov r7, sl
	adds r7, #0x6c
	ldr r2, _08059D04 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r3, #0x40
	orrs r0, r3
	ldr r1, _08059D08 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x10]
	add r5, sp, #0x10
	ldr r0, [r5, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r5, #4]
	movs r0, #0xf0
	lsls r0, r0, #0xf
	str r0, [sp, #0x18]
	add r4, sp, #0x18
	ldr r0, [r4, #4]
	ands r0, r2
	str r0, [r4, #4]
	ldr r2, _08059D0C @ =0x00004005
	movs r0, #0x10
	mov sb, r0
	str r0, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _08059D10 @ =FUN_08059bb0
	adds r0, r7, #0
	mov r2, sl
	bl FUN_0823651c
	ldr r2, [sp, #0x20]
	ldrh r1, [r2, #0x1e]
	adds r0, r7, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236514
	adds r0, r7, #0
	bl FUN_08236400
	subs r7, #0x50
	movs r1, #0x20
	strh r1, [r5]
	movs r0, #0xf0
	strh r0, [r5, #2]
	strh r1, [r5, #4]
	strh r6, [r4]
	movs r0, #0x78
	strh r0, [r4, #2]
	strh r6, [r4, #4]
	ldr r2, _08059D14 @ =0x00002001
	mov r0, sb
	str r0, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _08059D18 @ =FUN_08059bcc
	adds r0, r7, #0
	mov r2, sl
	bl FUN_0823651c
	ldr r2, [sp, #0x20]
	ldrh r1, [r2, #0x1c]
	movs r0, #0x80
	lsls r0, r0, #0xa
	str r0, [sp]
	movs r0, #5
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r2, #0x1e
	movs r3, #0
	bl FUN_082364f8
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059CFC: .4byte 0x00005292
_08059D00: .4byte 0x05000002
_08059D04: .4byte 0xFFFF0000
_08059D08: .4byte 0x0000FFFF
_08059D0C: .4byte 0x00004005
_08059D10: .4byte FUN_08059bb0
_08059D14: .4byte 0x00002001
_08059D18: .4byte FUN_08059bcc

	thumb_func_start FUN_08059d1c
FUN_08059d1c: @ 0x08059D1C
	push {r4, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	adds r0, #0x6c
	bl FUN_08236424
	adds r4, #0xbc
	adds r0, r4, #0
	bl FUN_0822a4e0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08059d38
FUN_08059d38: @ 0x08059D38
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	adds r5, #0xbc
	ldr r3, [r5]
	movs r4, #1
	orrs r3, r4
	str r3, [r5]
	adds r1, #0x6c
	ldrh r5, [r1, #6]
	movs r3, #4
	orrs r3, r5
	strh r3, [r1, #6]
	lsls r4, r2
	ldr r1, [r6, #0x18]
	bics r1, r4
	str r1, [r6, #0x18]
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08059d60
FUN_08059d60: @ 0x08059D60
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _08059D6E
	movs r0, #0
	strb r0, [r4, #1]
_08059D6E:
	ldrh r0, [r4, #8]
	ldrh r1, [r4, #0xa]
	cmp r0, r1
	blo _08059D86
	movs r0, #1
	movs r1, #0
	strb r0, [r4, #2]
	strb r0, [r4, #1]
	strh r1, [r4, #8]
	ldr r0, _08059D94 @ =0x0000016D
	bl PlaySound_082406e0
_08059D86:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08059D94: .4byte 0x0000016D

	thumb_func_start FUN_08059d98
FUN_08059d98: @ 0x08059D98
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r1, #0
	movs r0, #0xbc
	adds r0, r0, r4
	mov ip, r0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _08059DCC
	movs r0, #0
	strb r0, [r4, #1]
	mov r1, ip
	ldr r0, [r1]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
	str r0, [r2]
	movs r2, #1
	mov r3, ip
	strb r2, [r3, #9]
	ldr r0, [r3, #0x1c]
	ldr r1, [r3, #0x20]
	str r0, [r4, #0x10]
	str r1, [r4, #0x14]
	strb r2, [r4, #4]
_08059DCC:
	ldrh r1, [r4, #8]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _08059DDE
	ldrb r0, [r4, #0xd]
	adds r0, #0x20
	strb r0, [r4, #0xd]
_08059DDE:
	ldrh r1, [r4, #8]
	lsls r2, r1, #3
	adds r0, r1, #0
	ands r0, r3
	lsls r0, r0, #7
	adds r3, r2, r0
	movs r0, #0x20
	subs r0, r0, r1
	mov r5, sp
	lsls r6, r0, #3
	ldr r2, _08059E10 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08059E14
	asrs r1, r0, #0xc
	b _08059E1A
	.align 2, 0
_08059E10: .4byte 0x085B0A08
_08059E14:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08059E1A:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _08059E36
	asrs r0, r0, #0xc
	b _08059E3C
_08059E36:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08059E3C:
	strh r0, [r5, #4]
	mov r3, ip
	adds r3, #0x1c
	mov r2, sp
	mov r1, sp
	ldrh r0, [r4, #0x10]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, ip
	strh r0, [r1, #0x1c]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #0x12]
	adds r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #0x14]
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r3, #4]
	ldrh r0, [r4, #8]
	cmp r0, #0
	beq _08059E6E
	lsls r0, r0, #1
	mov r2, ip
	strb r0, [r2, #9]
	b _08059E74
_08059E6E:
	movs r0, #1
	mov r3, ip
	strb r0, [r3, #9]
_08059E74:
	ldrh r0, [r4, #8]
	cmp r0, #0x1f
	bls _08059E8C
	movs r1, #0
	movs r0, #0x40
	mov r2, ip
	strb r0, [r2, #9]
	movs r0, #2
	strb r0, [r4, #2]
	movs r0, #1
	strb r0, [r4, #1]
	strh r1, [r4, #8]
_08059E8C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08059e9c
FUN_08059e9c: @ 0x08059E9C
	push {r4, r5, lr}
	adds r4, r1, #0
	adds r3, r4, #0
	adds r3, #0xbc
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _08059EC0
	movs r0, #0
	strb r0, [r4, #1]
	ldrb r0, [r4, #0xc]
	strb r0, [r4, #0xd]
	adds r2, r4, #0
	adds r2, #0x6c
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_08059EC0:
	ldrh r1, [r4, #8]
	cmp r1, #0x1f
	bhi _08059EFA
	movs r0, #7
	ands r0, r1
	cmp r0, #3
	bhi _08059ED2
	movs r0, #1
	b _08059ED4
_08059ED2:
	movs r0, #0
_08059ED4:
	strb r0, [r4, #4]
	ldrb r0, [r4]
	cmp r0, #1
	bhi _08059EFA
	ldr r2, [r4, #0x18]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r5, #0x1c
	ldrsh r1, [r3, r5]
	subs r0, r0, r1
	movs r5, #4
	ldrsh r1, [r2, r5]
	movs r5, #0x20
	ldrsh r2, [r3, r5]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r4, #0xc]
	strb r0, [r4, #0xd]
_08059EFA:
	ldrh r0, [r4, #8]
	cmp r0, #0x3f
	bls _08059F0E
	movs r0, #0
	strb r0, [r4, #4]
	movs r1, #3
	strb r1, [r4, #2]
	movs r1, #1
	strb r1, [r4, #1]
	strh r0, [r4, #8]
_08059F0E:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08059f1c
FUN_08059f1c: @ 0x08059F1C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r1, #0
	movs r0, #0xbc
	adds r0, r0, r7
	mov r8, r0
	ldrb r0, [r7, #1]
	cmp r0, #0
	beq _08059F52
	movs r0, #0
	strb r0, [r7, #1]
	ldrb r0, [r7, #0xc]
	strb r0, [r7, #0xd]
	movs r0, #0x28
	strh r0, [r7, #0xe]
	adds r2, r7, #0
	adds r2, #0x6c
	subs r0, #0x2d
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
	movs r0, #0xb5
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08059F52:
	mov r3, sp
	ldrb r4, [r7, #0xc]
	ldrh r5, [r7, #0xe]
	ldr r2, _08059F74 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08059F78
	asrs r1, r0, #0xc
	b _08059F7E
	.align 2, 0
_08059F74: .4byte 0x085B0A08
_08059F78:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08059F7E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08059F96
	asrs r0, r0, #0xc
	b _08059F9C
_08059F96:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08059F9C:
	strh r0, [r3, #4]
	mov r5, r8
	adds r5, #0x1c
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	mov r3, r8
	ldrh r3, [r3, #0x1c]
	adds r0, r0, r3
	mov r2, r8
	strh r0, [r2, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r3, [r5, #2]
	adds r0, r0, r3
	strh r0, [r5, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r5, #4]
	adds r0, r0, r1
	strh r0, [r5, #4]
	adds r4, r7, #0
	adds r4, #0x1c
	adds r6, r7, #0
	adds r6, #0xd8
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	adds r0, r7, #0
	adds r0, #0x6c
	adds r1, r6, #0
	movs r2, #0
	bl FUN_082364c4
	mov r2, r8
	movs r3, #0x1e
	ldrsh r6, [r2, r3]
	adds r4, r5, #0
	ldrh r0, [r2, #0x1c]
	lsls r0, r0, #0x10
	asrs r5, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r5, #0
	blt _0805A012
	cmp r1, #0
	blt _0805A012
	ldr r0, _0805A018 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _0805A012
	ldr r0, _0805A01C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0805A020
_0805A012:
	movs r5, #0
	b _0805A02E
	.align 2, 0
_0805A018: .4byte 0x030046A8
_0805A01C: .4byte 0x030046AC
_0805A020:
	ldr r0, _0805A040 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r5
_0805A02E:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0805A044
	adds r0, #4
	b _0805A050
	.align 2, 0
_0805A040: .4byte 0x030046A4
_0805A044:
	ldr r0, _0805A064 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0805A050:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0805A068
	cmp r2, #2
	beq _0805A06C
	b _0805A070
	.align 2, 0
_0805A064: .4byte 0x030046A4
_0805A068:
	ldrb r0, [r4, #4]
	b _0805A06E
_0805A06C:
	ldrb r0, [r4]
_0805A06E:
	subs r1, r1, r0
_0805A070:
	cmp r6, r1
	bhi _0805A078
	movs r0, #5
	b _0805A080
_0805A078:
	ldrh r0, [r7, #8]
	cmp r0, #0x7f
	bls _0805A08C
	movs r0, #4
_0805A080:
	movs r1, #0
	strb r0, [r7, #2]
	movs r0, #1
	strb r0, [r7, #1]
	strh r1, [r7, #8]
	b _0805A090
_0805A08C:
	adds r0, #1
	strh r0, [r7, #8]
_0805A090:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805a09c
FUN_0805a09c: @ 0x0805A09C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0805A0BE
	movs r0, #0
	strb r0, [r4, #1]
	adds r3, r4, #0
	adds r3, #0x6c
	ldrh r1, [r3, #6]
	movs r0, #4
	movs r2, #0
	orrs r0, r1
	strh r0, [r3, #6]
	strb r2, [r4, #4]
_0805A0BE:
	ldrh r0, [r4, #8]
	cmp r0, #0x1f
	bls _0805A0D0
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl FUN_08059d38
	b _0805A0D4
_0805A0D0:
	adds r0, #1
	strh r0, [r4, #8]
_0805A0D4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805a0dc
FUN_0805a0dc: @ 0x0805A0DC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	mov r8, r0
	adds r4, r1, #0
	mov sb, r2
	movs r0, #0xbc
	adds r0, r0, r4
	mov ip, r0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0805A120
	movs r0, #0
	strb r0, [r4, #1]
	movs r3, #0
	movs r0, #0xa
	strh r0, [r4, #0xe]
	ldrb r0, [r4, #0xc]
	adds r0, #0x80
	strb r0, [r4, #0xc]
	mov r2, ip
	ldr r0, [r2, #0x1c]
	ldr r1, [r2, #0x20]
	str r0, [r4, #0x10]
	str r1, [r4, #0x14]
	adds r2, r4, #0
	adds r2, #0x6c
	ldrh r0, [r2, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2, #6]
	strb r3, [r4, #4]
_0805A120:
	mov r3, sp
	ldrb r5, [r4, #0xc]
	ldrh r6, [r4, #0xe]
	ldr r2, _0805A144 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	adds r7, r2, #0
	cmp r0, #0
	blt _0805A148
	asrs r1, r0, #0xc
	b _0805A14E
	.align 2, 0
_0805A144: .4byte 0x085B0A08
_0805A148:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805A14E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r7
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805A166
	asrs r0, r0, #0xc
	b _0805A16C
_0805A166:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805A16C:
	strh r0, [r3, #4]
	mov r1, ip
	adds r1, #0x1c
	mov r2, sp
	mov r0, sp
	ldrh r0, [r0]
	mov r3, ip
	ldrh r3, [r3, #0x1c]
	adds r0, r0, r3
	mov r5, ip
	strh r0, [r5, #0x1c]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r5, [r1, #4]
	adds r0, r0, r5
	strh r0, [r1, #4]
	ldrh r0, [r4, #8]
	lsls r0, r0, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #8
	cmp r0, #0
	blt _0805A1AC
	asrs r2, r0, #0xc
	b _0805A1B2
_0805A1AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0805A1B2:
	ldrh r0, [r4, #0x12]
	adds r0, r0, r2
	mov r2, ip
	strh r0, [r2, #0x1e]
	ldrb r0, [r4, #0xd]
	adds r0, #0x10
	strb r0, [r4, #0xd]
	ldrh r1, [r4, #8]
	cmp r1, #0xf
	bhi _0805A1E6
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0805A1D8
	mov r3, ip
	ldr r0, [r3]
	orrs r0, r2
	b _0805A206
_0805A1D8:
	mov r5, ip
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	b _0805A208
_0805A1E6:
	movs r0, #3
	ands r0, r1
	cmp r0, #1
	bhi _0805A1FC
	mov r1, ip
	ldr r0, [r1]
	movs r1, #1
	orrs r0, r1
	mov r2, ip
	str r0, [r2]
	b _0805A208
_0805A1FC:
	mov r3, ip
	ldr r0, [r3]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
_0805A206:
	str r0, [r3]
_0805A208:
	ldrh r0, [r4, #8]
	cmp r0, #0x1f
	bls _0805A21A
	mov r0, r8
	adds r1, r4, #0
	mov r2, sb
	bl FUN_08059d38
	b _0805A21E
_0805A21A:
	adds r0, #1
	strh r0, [r4, #8]
_0805A21E:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805a22c
FUN_0805a22c: @ 0x0805A22C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0x20
	movs r6, #0
_0805A236:
	movs r0, #1
	lsls r0, r6
	ldr r1, [r7, #0x18]
	ands r1, r0
	adds r5, r4, #0
	adds r5, #0xe8
	cmp r1, #0
	beq _0805A2AC
	ldr r1, _0805A280 @ =0x085AB9EC
	ldrb r0, [r4, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl _call_via_r3
	adds r1, r4, #0
	adds r1, #0xbc
	ldrb r0, [r4, #0xd]
	adds r0, #0x60
	rsbs r0, r0, #0
	strb r0, [r1, #6]
	ldrb r1, [r4, #4]
	ldrb r0, [r4, #3]
	cmp r0, r1
	beq _0805A2AC
	strb r1, [r4, #3]
	ldrb r0, [r4, #3]
	cmp r0, #1
	beq _0805A298
	cmp r0, #1
	bgt _0805A284
	cmp r0, #0
	beq _0805A28A
	b _0805A2AC
	.align 2, 0
_0805A280: .4byte 0x085AB9EC
_0805A284:
	cmp r0, #2
	beq _0805A2A4
	b _0805A2AC
_0805A28A:
	adds r0, r5, #0
	ldr r1, _0805A294 @ =0x0000012D
	bl FUN_0822b20c
	b _0805A2AC
	.align 2, 0
_0805A294: .4byte 0x0000012D
_0805A298:
	adds r0, r5, #0
	movs r1, #0x98
	lsls r1, r1, #1
	bl FUN_0822b20c
	b _0805A2AC
_0805A2A4:
	adds r0, r5, #0
	ldr r1, _0805A2C0 @ =0x00000131
	bl FUN_0822b20c
_0805A2AC:
	adds r6, #1
	movs r0, #0x82
	lsls r0, r0, #1
	adds r4, r4, r0
	cmp r6, #7
	ble _0805A236
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805A2C0: .4byte 0x00000131

	thumb_func_start FUN_0805a2c4
FUN_0805a2c4: @ 0x0805A2C4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x20
	movs r4, #0
_0805A2CE:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08059d1c
	adds r4, #1
	movs r0, #0x82
	lsls r0, r0, #1
	adds r5, r5, r0
	cmp r4, #7
	ble _0805A2CE
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805a2ec
FUN_0805a2ec: @ 0x0805A2EC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	strh r1, [r6, #0x1c]
	movs r0, #0xa
	strh r0, [r6, #0x1e]
	adds r5, r6, #0
	adds r5, #0x20
	movs r4, #0
_0805A2FC:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08059bd0
	adds r4, #1
	movs r0, #0x82
	lsls r0, r0, #1
	adds r5, r5, r0
	cmp r4, #7
	ble _0805A2FC
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805a31c
FUN_0805a31c: @ 0x0805A31C
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x84
	lsls r1, r1, #4
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805A358
	ldr r1, _0805A350 @ =FUN_0805a22c
	ldr r2, _0805A354 @ =FUN_0805a2c4
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0805a2ec
	cmp r0, #0
	bge _0805A358
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805A35A
	.align 2, 0
_0805A350: .4byte FUN_0805a22c
_0805A354: .4byte FUN_0805a2c4
_0805A358:
	adds r0, r4, #0
_0805A35A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805a360
FUN_0805a360: @ 0x0805A360
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	mov sb, r0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r4, r3, #0
	mov r1, sp
	bl FUN_08059b7c
	adds r7, r0, #0
	cmp r7, #0
	bne _0805A384
	movs r0, #1
	rsbs r0, r0, #0
	b _0805A42E
_0805A384:
	str r4, [r7, #0x18]
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r2, #0
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r4, r3]
	movs r3, #4
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	adds r3, r0, #0
	adds r2, r7, #0
	adds r2, #0xbc
	movs r1, #0
	strb r6, [r7]
	ldrb r0, [r7]
	cmp r0, #1
	beq _0805A3BE
	cmp r0, #1
	bgt _0805A3B8
	cmp r0, #0
	beq _0805A3C2
	b _0805A3CA
_0805A3B8:
	cmp r0, #2
	beq _0805A3C2
	b _0805A3CA
_0805A3BE:
	strb r1, [r7, #2]
	b _0805A3C6
_0805A3C2:
	strb r1, [r7, #2]
	movs r0, #1
_0805A3C6:
	strb r0, [r7, #1]
	strh r1, [r7, #8]
_0805A3CA:
	strb r3, [r7, #0xc]
	strb r3, [r7, #0xd]
	movs r0, #0
	mov r8, r0
	ldr r0, [sp, #0x20]
	strh r0, [r7, #0xe]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldrb r0, [r7, #0xd]
	adds r0, #0x60
	rsbs r0, r0, #0
	strb r0, [r2, #6]
	ldr r0, [r2]
	movs r5, #1
	orrs r0, r5
	str r0, [r2]
	strb r5, [r2, #9]
	adds r0, r7, #0
	adds r0, #0x1c
	adds r6, r7, #0
	adds r6, #0xd8
	adds r1, r6, #0
	movs r2, #0
	bl FUN_082364c4
	adds r4, r7, #0
	adds r4, #0x6c
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_082364c4
	ldrh r0, [r4, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r4, #6]
	mov r1, r8
	strb r1, [r7, #3]
	strb r1, [r7, #4]
	ldr r0, [sp, #0x24]
	strh r0, [r7, #0xa]
	ldr r0, [sp]
	lsls r5, r0
	mov r2, sb
	ldr r0, [r2, #0x18]
	orrs r0, r5
	str r0, [r2, #0x18]
	movs r0, #0
_0805A42E:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805a43c
FUN_0805a43c: @ 0x0805A43C
	push {r4, r5, r6, lr}
	adds r4, r1, #0
	movs r2, #0
	movs r6, #1
	ldr r1, [r0, #0x18]
	adds r3, r0, #0
	adds r3, #0x24
	movs r5, #0xe2
	lsls r5, r5, #1
_0805A44E:
	adds r0, r6, #0
	lsls r0, r2
	ands r0, r1
	cmp r0, #0
	bne _0805A45E
	str r2, [r4]
	adds r0, r3, #0
	b _0805A468
_0805A45E:
	adds r3, r3, r5
	adds r2, #1
	cmp r2, #7
	ble _0805A44E
	movs r0, #0
_0805A468:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805a470
FUN_0805a470: @ 0x0805A470
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r2, #0
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r5, #6]
	ands r0, r1
	cmp r0, #0
	beq _0805A48E
	adds r0, r5, #0
	adds r0, #0x42
	ldrb r0, [r0]
	b _0805A4A6
_0805A48E:
	movs r1, #0x24
	ldrsh r0, [r6, r1]
	movs r2, #0x24
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	movs r3, #0x28
	ldrsh r1, [r6, r3]
	movs r3, #0x28
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl FUN_0823785c
_0805A4A6:
	strb r0, [r4, #0xa]
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_08236524
	ldr r3, _0805A508 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r2, #0x10
	orrs r0, r2
	ldr r1, _0805A50C @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0xc]
	ldrh r1, [r6, #0x3e]
	adds r3, r4, #0
	adds r3, #0x14
	add r0, sp, #8
	str r0, [sp]
	movs r7, #1
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r2, #0
	bl FUN_0805fe7c
	ldrh r0, [r5, #0x3e]
	adds r0, #2
	movs r2, #0
	strh r0, [r5, #0x3e]
	ldrh r0, [r4, #0x12]
	ldrh r1, [r6, #0x3e]
	subs r0, r0, r1
	strh r0, [r4, #0x12]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0805A514
	strh r2, [r4, #0x12]
	movs r0, #6
	strb r0, [r4, #1]
	strb r7, [r4]
	strh r2, [r4, #6]
	ldr r0, _0805A510 @ =0x00000339
	bl PlaySound_082406e0
	b _0805A524
	.align 2, 0
_0805A508: .4byte 0xFFFF0000
_0805A50C: .4byte 0x0000FFFF
_0805A510: .4byte 0x00000339
_0805A514:
	movs r0, #5
	strb r0, [r4, #1]
	strb r7, [r4]
	strh r2, [r4, #6]
	movs r0, #0xcd
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0805A524:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805a52c
FUN_0805a52c: @ 0x0805A52C
	movs r0, #4
	movs r1, #0
	strb r0, [r2, #1]
	movs r0, #1
	strb r0, [r2]
	strh r1, [r2, #6]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0805a53c
FUN_0805a53c: @ 0x0805A53C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	str r0, [sp, #0x20]
	adds r7, r1, #0
	movs r1, #0
	movs r2, #0
	strb r1, [r7, #1]
	movs r0, #1
	strb r0, [r7]
	strh r2, [r7, #6]
	strb r1, [r7, #0xa]
	strb r1, [r7, #0xb]
	movs r0, #0xd4
	lsls r0, r0, #1
	adds r4, r7, r0
	ldr r1, _0805A5A8 @ =0x00003668
	adds r0, r4, #0
	bl FUN_0822b16c
	adds r0, r4, #0
	movs r1, #0xc8
	bl FUN_0822b20c
	adds r4, r7, #0
	adds r4, #0xf8
	movs r5, #0
	add r1, sp, #0x10
	mov sb, r1
	add r2, sp, #0x18
	mov sl, r2
_0805A580:
	adds r0, r4, #0
	movs r2, #0xd4
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r2, #1
	bl FUN_0822a470
	cmp r5, #0
	bne _0805A5AC
	ldr r0, [sp, #0x20]
	ldr r1, [r0, #0x20]
	str r5, [sp]
	adds r0, r7, #0
	adds r0, #0xe8
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	movs r0, #1
	b _0805A5B2
	.align 2, 0
_0805A5A8: .4byte 0x00003668
_0805A5AC:
	adds r0, r5, #3
	strh r0, [r4, #0x10]
	movs r0, #2
_0805A5B2:
	strb r0, [r4, #7]
	adds r1, r4, #0
	adds r1, #0x1c
	movs r2, #0
	mov r8, r2
	str r2, [sp, #0xc]
	add r0, sp, #0xc
	ldr r2, _0805A6A8 @ =0x05000002
	bl CpuSet
	adds r5, #1
	adds r4, #0x2c
	cmp r5, #3
	ble _0805A580
	adds r6, r7, #0
	adds r6, #0x98
	ldr r2, _0805A6AC @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r4, #0x20
	orrs r0, r4
	ldr r1, _0805A6B0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x10]
	mov r1, sb
	ldr r0, [r1, #4]
	ands r0, r2
	orrs r0, r4
	str r0, [r1, #4]
	mov r0, r8
	str r0, [sp, #0x18]
	mov r1, sl
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _0805A6B4 @ =0x00005005
	movs r5, #0x10
	str r5, [sp]
	mov r0, sb
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	adds r1, r7, #0
	adds r1, #0x14
	str r1, [sp, #0x24]
	adds r0, r6, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _0805A6B8 @ =FUN_0805a470
	adds r0, r6, #0
	adds r2, r7, #0
	bl FUN_0823651c
	ldr r2, [sp, #0x20]
	ldrh r1, [r2, #0x1e]
	ldr r2, _0805A6BC @ =0x00000202
	adds r0, r6, #0
	movs r3, #1
	bl FUN_08236514
	adds r0, r6, #0
	bl FUN_08236400
	subs r6, #0x50
	add r0, sp, #0x10
	strh r4, [r0]
	movs r0, #0x64
	mov r1, sb
	strh r0, [r1, #2]
	strh r4, [r1, #4]
	add r0, sp, #0x18
	mov r2, r8
	strh r2, [r0]
	mov r0, sl
	strh r2, [r0, #2]
	strh r2, [r0, #4]
	ldr r2, _0805A6C0 @ =0x00002001
	str r5, [sp]
	str r1, [sp, #4]
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r6, #0
	ldr r1, [sp, #0x24]
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _0805A6C4 @ =FUN_0805a52c
	adds r0, r6, #0
	adds r2, r7, #0
	bl FUN_0823651c
	ldr r2, [sp, #0x20]
	ldrh r1, [r2, #0x1c]
	movs r0, #2
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	adds r0, r6, #0
	movs r2, #0x1e
	movs r3, #0
	bl FUN_082364f8
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805A6A8: .4byte 0x05000002
_0805A6AC: .4byte 0xFFFF0000
_0805A6B0: .4byte 0x0000FFFF
_0805A6B4: .4byte 0x00005005
_0805A6B8: .4byte FUN_0805a470
_0805A6BC: .4byte 0x00000202
_0805A6C0: .4byte 0x00002001
_0805A6C4: .4byte FUN_0805a52c

	thumb_func_start FUN_0805a6c8
FUN_0805a6c8: @ 0x0805A6C8
	push {r4, r5, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	adds r0, #0x98
	bl FUN_08236424
	adds r4, #0xf8
	movs r5, #3
_0805A6D8:
	adds r0, r4, #0
	bl FUN_0822a4e0
	subs r5, #1
	adds r4, #0x2c
	cmp r5, #0
	bge _0805A6D8
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805a6ec
FUN_0805a6ec: @ 0x0805A6EC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r7, r2, #0
	adds r2, r4, #0
	adds r2, #0xf8
	movs r5, #1
	movs r3, #3
_0805A6FC:
	ldr r1, [r2]
	orrs r1, r5
	str r1, [r2]
	subs r3, #1
	adds r2, #0x2c
	cmp r3, #0
	bge _0805A6FC
	adds r3, r4, #0
	adds r3, #0x98
	ldrh r2, [r3, #6]
	movs r1, #4
	orrs r1, r2
	strh r1, [r3, #6]
	movs r2, #1
	lsls r2, r7
	ldr r1, [r6, #0x18]
	bics r1, r2
	str r1, [r6, #0x18]
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805a728
FUN_0805a728: @ 0x0805A728
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0xf8
	movs r0, #0x8a
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r0, [r6, #0x14]
	ldr r1, [r6, #0x18]
	str r0, [r2]
	str r1, [r2, #4]
	adds r4, r6, #0
	adds r4, #0xe8
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
	beq _0805A76E
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0805A776
_0805A76E:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0805A776:
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
	beq _0805A79A
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0805A7A2
_0805A79A:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0805A7A2:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0805A7DC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0805A822
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0805A7E6
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0805A7E0
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _0805A7FC
	.align 2, 0
_0805A7DC: .4byte 0x0000FFFF
_0805A7E0:
	subs r0, #1
	strh r0, [r4, #8]
	b _0805A7FA
_0805A7E6:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0805A7FA
	strh r1, [r4, #8]
	movs r2, #1
	b _0805A7FC
_0805A7FA:
	movs r2, #0
_0805A7FC:
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
	bne _0805A824
	movs r0, #1
	strb r0, [r4, #7]
	b _0805A824
_0805A822:
	movs r2, #0
_0805A824:
	strb r2, [r6, #4]
	ldr r0, _0805A83C @ =0x085B0A08
	ldrb r1, [r6, #5]
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #6
	cmp r0, #0
	blt _0805A840
	asrs r1, r0, #0xc
	b _0805A846
	.align 2, 0
_0805A83C: .4byte 0x085B0A08
_0805A840:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805A846:
	ldrh r0, [r5, #0x1e]
	adds r0, r0, r1
	strh r0, [r5, #0x1e]
	adds r5, #0x2c
	ldrb r0, [r6, #0xc]
	subs r2, r0, #1
	cmp r2, #0
	bge _0805A858
	movs r2, #3
_0805A858:
	movs r3, #2
_0805A85A:
	lsls r0, r2, #3
	adds r0, r0, r6
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	subs r2, #1
	cmp r2, #0
	bge _0805A86E
	movs r2, #3
_0805A86E:
	subs r3, #1
	adds r5, #0x2c
	cmp r3, #0
	bge _0805A85A
	ldrb r0, [r6, #5]
	adds r0, #4
	strb r0, [r6, #5]
	ldrh r0, [r6, #6]
	movs r3, #3
	ands r3, r0
	cmp r3, #0
	bne _0805A8AA
	ldrb r2, [r6, #0xc]
	lsls r2, r2, #3
	adds r2, r2, r6
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldrb r0, [r6, #0xc]
	adds r0, #1
	strb r0, [r6, #0xc]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _0805A8AA
	strb r3, [r6, #0xc]
_0805A8AA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805a8b0
FUN_0805a8b0: @ 0x0805A8B0
	push {lr}
	movs r2, #0x92
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r3, #2
	rsbs r3, r3, #0
	movs r2, #2
_0805A8BE:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	subs r2, #1
	adds r1, #0x2c
	cmp r2, #0
	bge _0805A8BE
	pop {r0}
	bx r0

	thumb_func_start FUN_0805a8d0
FUN_0805a8d0: @ 0x0805A8D0
	push {lr}
	movs r2, #0x92
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r3, #1
	movs r2, #2
_0805A8DC:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	subs r2, #1
	adds r1, #0x2c
	cmp r2, #0
	bge _0805A8DC
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805a8f0
FUN_0805a8f0: @ 0x0805A8F0
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0x44]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #0x14
	ldrsh r1, [r4, r3]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r3, #0x18
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r4, #0xb]
	ldrb r1, [r4, #0xa]
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	asrs r2, r0, #0x18
	movs r0, #2
	rsbs r0, r0, #0
	cmp r2, r0
	bge _0805A926
	movs r1, #0xfe
	b _0805A92C
_0805A926:
	cmp r2, #2
	ble _0805A92C
	movs r1, #2
_0805A92C:
	ldrb r0, [r4, #0xa]
	adds r0, r0, r1
	strb r0, [r4, #0xa]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805a938
FUN_0805a938: @ 0x0805A938
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805A95A
	movs r2, #0
	strb r2, [r4]
	adds r0, r4, #0
	adds r0, #0xe8
	ldr r1, [r5, #0x20]
	str r2, [sp]
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
_0805A95A:
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _0805A978
	movs r0, #1
	movs r2, #0
	strb r0, [r4, #1]
	strb r0, [r4]
	strh r2, [r4, #6]
	adds r0, r4, #0
	adds r0, #0xe8
	ldr r1, [r5, #0x20]
	str r2, [sp]
	movs r3, #0
	bl FUN_08236fac
_0805A978:
	ldrh r0, [r4, #6]
	adds r0, #1
	strh r0, [r4, #6]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805a988
FUN_0805a988: @ 0x0805A988
	push {r4, r5, lr}
	sub sp, #4
	adds r3, r0, #0
	adds r5, r1, #0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0805A9C8
	movs r2, #0
	strb r2, [r5]
	adds r4, r5, #0
	adds r4, #0x98
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r4, #6]
	ands r0, r1
	strh r0, [r4, #6]
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, [r3, #0x20]
	str r2, [sp]
	movs r3, #0
	bl FUN_08236fac
	adds r0, r5, #0
	bl FUN_0805a8b0
	adds r1, r5, #0
	adds r1, #0x14
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
_0805A9C8:
	ldrh r0, [r5, #6]
	cmp r0, #0x1f
	bls _0805A9DA
	movs r0, #2
	movs r1, #0
	strb r0, [r5, #1]
	movs r0, #1
	strb r0, [r5]
	strh r1, [r5, #6]
_0805A9DA:
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805a9e8
FUN_0805a9e8: @ 0x0805A9E8
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r1, #0
	ldrb r0, [r6]
	cmp r0, #0
	beq _0805AA42
	movs r0, #0
	strb r0, [r6]
	movs r0, #0xa
	strh r0, [r6, #0x10]
	adds r2, r6, #0
	adds r2, #0x98
	subs r0, #0xf
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r6, #0x44]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #0x14
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r3, #0x18
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	ldr r3, _0805AA6C @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r2, _0805AA70 @ =0x000003FF
	ands r1, r2
	str r1, [r3]
	lsls r1, r1, #1
	ldr r2, _0805AA74 @ =0x0203B400
	adds r1, r1, r2
	ldrh r1, [r1]
	movs r2, #0x3f
	ands r1, r2
	subs r1, #0x80
	adds r0, r0, r1
	subs r0, #0x20
	strb r0, [r6, #0xa]
_0805AA42:
	adds r0, r6, #0
	bl FUN_0805a8f0
	mov r3, sp
	ldrb r4, [r6, #0xa]
	ldrh r5, [r6, #0x10]
	ldr r2, _0805AA78 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805AA7C
	asrs r1, r0, #0xc
	b _0805AA82
	.align 2, 0
_0805AA6C: .4byte 0x030046B8
_0805AA70: .4byte 0x000003FF
_0805AA74: .4byte 0x0203B400
_0805AA78: .4byte 0x085B0A08
_0805AA7C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805AA82:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _0805AA9C @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805AAA0
	asrs r0, r0, #0xc
	b _0805AAA6
	.align 2, 0
_0805AA9C: .4byte 0x085B0A08
_0805AAA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805AAA6:
	strh r0, [r3, #4]
	adds r4, r6, #0
	adds r4, #0x14
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r6, #0x14]
	adds r0, r0, r3
	strh r0, [r6, #0x14]
	ldrh r0, [r1, #2]
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r4, #4]
	adds r0, r0, r3
	strh r0, [r4, #4]
	adds r5, r6, #0
	adds r5, #0x48
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r6, #0
	adds r0, #0x98
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	ldrh r0, [r6, #8]
	adds r0, #1
	strh r0, [r6, #8]
	lsls r0, r0, #0x10
	ldr r1, _0805AB04 @ =0x02570000
	cmp r0, r1
	bls _0805AB08
	movs r0, #3
	strb r0, [r6, #1]
	movs r0, #1
	strb r0, [r6]
	movs r0, #0
	b _0805AB0C
	.align 2, 0
_0805AB04: .4byte 0x02570000
_0805AB08:
	ldrh r0, [r6, #6]
	adds r0, #1
_0805AB0C:
	strh r0, [r6, #6]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805ab18
FUN_0805ab18: @ 0x0805AB18
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r5, r1, #0
	adds r7, r2, #0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0805AB4E
	movs r4, #0
	strb r4, [r5]
	adds r2, r5, #0
	adds r2, #0x98
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	adds r0, r5, #0
	bl FUN_0805a8d0
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, [r6, #0x20]
	str r4, [sp]
	movs r2, #4
	movs r3, #0
	bl FUN_08236fac
_0805AB4E:
	ldrb r0, [r5, #4]
	cmp r0, #0
	beq _0805AB60
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r7, #0
	bl FUN_0805a6ec
	b _0805AB66
_0805AB60:
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_0805AB66:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805ab70
FUN_0805ab70: @ 0x0805AB70
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	str r0, [sp, #0x20]
	adds r7, r1, #0
	str r2, [sp, #0x24]
	ldrb r0, [r7]
	cmp r0, #0
	bne _0805AB8A
	b _0805ACCA
_0805AB8A:
	movs r4, #0
	strb r4, [r7]
	adds r2, r7, #0
	adds r2, #0x98
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	adds r0, r7, #0
	bl FUN_0805a8d0
	adds r0, r7, #0
	adds r0, #0xe8
	ldr r2, [sp, #0x20]
	ldr r1, [r2, #0x20]
	str r4, [sp]
	movs r2, #4
	movs r3, #0
	bl FUN_08236fac
	ldr r3, _0805ACF0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r3
	movs r2, #0x40
	orrs r0, r2
	ldr r1, _0805ACF4 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0x14]
	ldr r5, _0805ACF8 @ =0x030046B8
	ldr r2, [r5]
	adds r2, #1
	ldr r4, _0805ACFC @ =0x000003FF
	ands r2, r4
	lsls r0, r2, #1
	ldr r3, _0805AD00 @ =0x0203B400
	adds r0, r0, r3
	ldrh r1, [r0]
	movs r6, #1
	ands r1, r6
	adds r1, #1
	adds r2, #1
	ands r2, r4
	str r2, [r5]
	lsls r0, r2, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	ldrb r3, [r7, #0xa]
	movs r6, #0xf
	ands r0, r6
	subs r3, r3, r0
	adds r3, #3
	adds r2, #1
	ands r2, r4
	str r2, [r5]
	lsls r2, r2, #1
	ldr r0, _0805AD00 @ =0x0203B400
	adds r2, r2, r0
	ldrh r0, [r2]
	movs r2, #7
	mov sl, r2
	ands r0, r2
	ldrh r6, [r7, #0x10]
	adds r0, r0, r6
	adds r6, r7, #0
	adds r6, #0x14
	str r0, [sp]
	movs r0, #1
	mov r8, r0
	str r0, [sp, #4]
	movs r2, #2
	mov sb, r2
	str r2, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r6, #0
	add r2, sp, #0x10
	bl FUN_080ddcc8
	ldr r0, [r5]
	adds r0, #1
	ands r0, r4
	lsls r1, r0, #1
	ldr r3, _0805AD00 @ =0x0203B400
	adds r1, r1, r3
	ldrh r1, [r1]
	movs r2, #1
	ands r1, r2
	adds r1, #1
	adds r0, #1
	ands r0, r4
	str r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	mov r3, sl
	ands r0, r3
	ldrh r2, [r7, #0x10]
	adds r0, r0, r2
	ldrb r3, [r7, #0xa]
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	mov r2, sb
	str r2, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r6, #0
	add r2, sp, #0x10
	bl FUN_080ddcc8
	ldr r0, [r5]
	adds r0, #1
	ands r0, r4
	lsls r1, r0, #1
	ldr r3, _0805AD00 @ =0x0203B400
	adds r1, r1, r3
	ldrh r1, [r1]
	movs r2, #1
	ands r1, r2
	adds r1, #1
	adds r0, #1
	ands r0, r4
	str r0, [r5]
	lsls r2, r0, #1
	adds r2, r2, r3
	ldrh r3, [r2]
	movs r2, #0xf
	ands r3, r2
	ldrb r2, [r7, #0xa]
	adds r3, r3, r2
	adds r3, #3
	adds r0, #1
	ands r0, r4
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _0805AD00 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r2, sl
	ands r0, r2
	ldrh r2, [r7, #0x10]
	adds r0, r0, r2
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	mov r2, sb
	str r2, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r6, #0
	add r2, sp, #0x10
	bl FUN_080ddcc8
	ldr r0, _0805AD04 @ =0x00000339
	bl PlaySound_082406e0
_0805ACCA:
	add r3, sp, #0x18
	ldrb r4, [r7, #0xa]
	ldrh r5, [r7, #0x10]
	ldr r2, _0805AD08 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	muls r0, r5, r0
	adds r6, r3, #0
	cmp r0, #0
	blt _0805AD0C
	asrs r1, r0, #0xc
	b _0805AD12
	.align 2, 0
_0805ACF0: .4byte 0xFFFF0000
_0805ACF4: .4byte 0x0000FFFF
_0805ACF8: .4byte 0x030046B8
_0805ACFC: .4byte 0x000003FF
_0805AD00: .4byte 0x0203B400
_0805AD04: .4byte 0x00000339
_0805AD08: .4byte 0x085B0A08
_0805AD0C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805AD12:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805AD2A
	asrs r0, r0, #0xc
	b _0805AD30
_0805AD2A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805AD30:
	strh r0, [r3, #4]
	adds r1, r7, #0
	adds r1, #0x14
	add r0, sp, #0x18
	ldrh r0, [r0]
	ldrh r2, [r7, #0x14]
	adds r0, r0, r2
	strh r0, [r7, #0x14]
	ldrh r0, [r6, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r6, #4]
	ldrh r6, [r1, #4]
	adds r0, r0, r6
	strh r0, [r1, #4]
	ldrb r0, [r7, #4]
	cmp r0, #0
	beq _0805AD62
	ldr r0, [sp, #0x20]
	adds r1, r7, #0
	ldr r2, [sp, #0x24]
	bl FUN_0805a6ec
	b _0805AD68
_0805AD62:
	ldrh r0, [r7, #6]
	adds r0, #1
	strh r0, [r7, #6]
_0805AD68:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805ad78
FUN_0805ad78: @ 0x0805AD78
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805ADA0
	movs r0, #0
	strb r0, [r4]
	adds r2, r4, #0
	adds r2, #0x98
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	movs r1, #0xd4
	lsls r1, r1, #1
	adds r0, r4, r1
	subs r1, #0x76
	bl FUN_0822b20c
_0805ADA0:
	ldrh r1, [r4, #6]
	movs r0, #0x14
	subs r0, r0, r1
	mov r3, sp
	ldrb r5, [r4, #0xa]
	lsls r6, r0, #1
	ldr r2, _0805ADC8 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805ADCC
	asrs r1, r0, #0xc
	b _0805ADD2
	.align 2, 0
_0805ADC8: .4byte 0x085B0A08
_0805ADCC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805ADD2:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805ADEA
	asrs r0, r0, #0xc
	b _0805ADF0
_0805ADEA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805ADF0:
	strh r0, [r3, #4]
	adds r1, r4, #0
	adds r1, #0x14
	mov r2, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r4, #0x14]
	adds r0, r0, r3
	strh r0, [r4, #0x14]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	ldrh r0, [r4, #6]
	cmp r0, #0x13
	bls _0805AE24
	movs r0, #2
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	movs r0, #0
	b _0805AE38
_0805AE24:
	cmp r0, #0xa
	bne _0805AE34
	movs r3, #0xd4
	lsls r3, r3, #1
	adds r0, r4, r3
	movs r1, #0xc8
	bl FUN_0822b20c
_0805AE34:
	ldrh r0, [r4, #6]
	adds r0, #1
_0805AE38:
	strh r0, [r4, #6]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805ae44
FUN_0805ae44: @ 0x0805AE44
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov sb, r0
	adds r7, r1, #0
	mov sl, r2
	ldrb r0, [r7]
	cmp r0, #0
	beq _0805AE84
	movs r4, #0
	strb r4, [r7]
	adds r2, r7, #0
	adds r2, #0x98
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	adds r0, r7, #0
	bl FUN_0805a8d0
	adds r0, r7, #0
	adds r0, #0xe8
	mov r2, sb
	ldr r1, [r2, #0x20]
	str r4, [sp]
	movs r2, #4
	movs r3, #0
	bl FUN_08236fac
_0805AE84:
	add r3, sp, #0x10
	ldrb r4, [r7, #0xa]
	movs r5, #0x14
	ldr r2, _0805AEA8 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805AEAC
	asrs r1, r0, #0xc
	b _0805AEB2
	.align 2, 0
_0805AEA8: .4byte 0x085B0A08
_0805AEAC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805AEB2:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805AECA
	asrs r0, r0, #0xc
	b _0805AED0
_0805AECA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805AED0:
	strh r0, [r3, #4]
	adds r6, r7, #0
	adds r6, #0x14
	add r1, sp, #0x10
	adds r0, r1, #0
	ldrh r0, [r0]
	ldrh r4, [r7, #0x14]
	adds r0, r0, r4
	strh r0, [r7, #0x14]
	ldrh r0, [r1, #2]
	ldrh r2, [r6, #2]
	adds r0, r0, r2
	strh r0, [r6, #2]
	ldrh r0, [r1, #4]
	ldrh r4, [r6, #4]
	adds r0, r0, r4
	strh r0, [r6, #4]
	ldrh r0, [r7, #6]
	movs r1, #3
	mov ip, r1
	mov r2, ip
	ands r2, r0
	mov ip, r2
	cmp r2, #0
	bne _0805AF74
	ldr r4, _0805AF88 @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r4
	movs r3, #0x40
	orrs r0, r3
	ldr r1, _0805AF8C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x18]
	add r2, sp, #0x18
	ldr r0, [r2, #4]
	ands r0, r4
	orrs r0, r3
	str r0, [r2, #4]
	ldr r5, _0805AF90 @ =0x0203B400
	ldr r4, _0805AF94 @ =0x030046B8
	mov r8, r4
	ldr r0, [r4]
	adds r0, #1
	ldr r4, _0805AF98 @ =0x000003FF
	ands r0, r4
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	movs r3, #1
	ands r1, r3
	adds r1, #1
	adds r0, #1
	ands r0, r4
	lsls r3, r0, #1
	adds r3, r3, r5
	ldrb r3, [r3]
	adds r0, #1
	ands r0, r4
	mov r4, r8
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r4, #7
	ands r0, r4
	adds r0, #0x10
	mov r4, ip
	str r4, [sp]
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	bl FUN_080ddcc8
	ldr r0, _0805AF9C @ =0x00000339
	bl PlaySound_082406e0
_0805AF74:
	ldrb r0, [r7, #4]
	cmp r0, #0
	beq _0805AFA0
	mov r0, sb
	adds r1, r7, #0
	mov r2, sl
	bl FUN_0805a6ec
	b _0805AFA6
	.align 2, 0
_0805AF88: .4byte 0xFFFF0000
_0805AF8C: .4byte 0x0000FFFF
_0805AF90: .4byte 0x0203B400
_0805AF94: .4byte 0x030046B8
_0805AF98: .4byte 0x000003FF
_0805AF9C: .4byte 0x00000339
_0805AFA0:
	ldrh r0, [r7, #6]
	adds r0, #1
	strh r0, [r7, #6]
_0805AFA6:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805afb8
FUN_0805afb8: @ 0x0805AFB8
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x24
	movs r5, #0
	ldr r7, _0805AFFC @ =0x085ABA04
_0805AFC4:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _0805AFE8
	ldrb r0, [r4, #1]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r3, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl _call_via_r3
	adds r0, r4, #0
	bl FUN_0805a728
_0805AFE8:
	adds r5, #1
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r4, r4, r0
	cmp r5, #7
	ble _0805AFC4
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805AFFC: .4byte 0x085ABA04

	thumb_func_start FUN_0805b000
FUN_0805b000: @ 0x0805B000
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x24
	movs r4, #0
_0805B00A:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805a6c8
	adds r4, #1
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r5, r5, r0
	cmp r4, #7
	ble _0805B00A
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805b028
FUN_0805b028: @ 0x0805B028
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	strh r1, [r6, #0x1c]
	strh r2, [r6, #0x1e]
	ldr r0, _0805B060 @ =0x0000922E
	ldr r1, _0805B064 @ =0x000078E1
	bl GetFile
	str r0, [r6, #0x20]
	adds r5, r6, #0
	adds r5, #0x24
	movs r4, #0
_0805B040:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805a53c
	adds r4, #1
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r5, r5, r0
	cmp r4, #7
	ble _0805B040
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805B060: .4byte 0x0000922E
_0805B064: .4byte 0x000078E1

	thumb_func_start FUN_0805b068
FUN_0805b068: @ 0x0805B068
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r1, _0805B09C @ =0x00000E44
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805B0A8
	ldr r1, _0805B0A0 @ =FUN_0805afb8
	ldr r2, _0805B0A4 @ =FUN_0805b000
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0805b028
	cmp r0, #0
	bge _0805B0A8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805B0AA
	.align 2, 0
_0805B09C: .4byte 0x00000E44
_0805B0A0: .4byte FUN_0805afb8
_0805B0A4: .4byte FUN_0805b000
_0805B0A8:
	adds r0, r4, #0
_0805B0AA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805b0b0
FUN_0805b0b0: @ 0x0805B0B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov r8, r0
	adds r7, r1, #0
	adds r6, r2, #0
	adds r5, r3, #0
	add r1, sp, #4
	bl FUN_0805a43c
	adds r4, r0, #0
	cmp r4, #0
	bne _0805B0D6
	movs r0, #1
	rsbs r0, r0, #0
	b _0805B190
_0805B0D6:
	movs r1, #0
	strb r1, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	movs r2, #0
	strh r1, [r4, #6]
	strb r5, [r4, #0xa]
	strb r5, [r4, #0xb]
	ldr r0, [sp, #0x28]
	strh r0, [r4, #0x10]
	ldr r0, [sp, #0x2c]
	strh r0, [r4, #0x12]
	strh r1, [r4, #8]
	str r6, [r4, #0x44]
	strb r2, [r4, #0xc]
	ldr r0, [r7]
	ldr r1, [r7, #4]
	str r0, [r4, #0x14]
	str r1, [r4, #0x18]
	adds r5, r4, #0
	adds r5, #0xf8
	movs r6, #0
	movs r0, #0x48
	adds r0, r0, r4
	mov sl, r0
	movs r1, #0x14
	adds r1, r1, r4
	mov sb, r1
	adds r7, r4, #0
	adds r7, #0x98
_0805B112:
	lsls r0, r6, #3
	adds r0, r0, r4
	ldr r1, [r4, #0x14]
	ldr r2, [r4, #0x18]
	str r1, [r0, #0x1c]
	str r2, [r0, #0x20]
	ldr r0, [r4, #0x14]
	ldr r1, [r4, #0x18]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	cmp r6, #0
	bne _0805B148
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	mov r2, r8
	ldr r1, [r2, #0x20]
	str r6, [sp]
	adds r0, r4, #0
	adds r0, #0xe8
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	b _0805B150
_0805B148:
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
_0805B150:
	adds r6, #1
	adds r5, #0x2c
	cmp r6, #3
	ble _0805B112
	movs r1, #0xd4
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0xc8
	bl FUN_0822b20c
	mov r0, sl
	mov r1, sb
	movs r2, #0
	bl FUN_082364c4
	adds r0, r7, #0
	mov r1, sb
	movs r2, #0
	bl FUN_082364c4
	ldrh r1, [r7, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r7, #6]
	ldr r0, [sp, #4]
	movs r1, #1
	lsls r1, r0
	mov r2, r8
	ldr r0, [r2, #0x18]
	orrs r0, r1
	str r0, [r2, #0x18]
	movs r0, #0
_0805B190:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805b1a0
FUN_0805b1a0: @ 0x0805B1A0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r3, r5, #0
	adds r3, #0x24
	movs r4, #0
	movs r6, #1
	movs r1, #3
	mov r8, r1
	mov ip, r4
	movs r7, #0xe2
	lsls r7, r7, #1
_0805B1BA:
	adds r2, r6, #0
	lsls r2, r4
	ldr r1, [r5, #0x18]
	ands r1, r2
	cmp r1, #0
	beq _0805B1D6
	ldrb r1, [r3, #1]
	cmp r1, #2
	bhi _0805B1D6
	mov r1, r8
	strb r1, [r3, #1]
	strb r6, [r3]
	mov r1, ip
	strh r1, [r3, #6]
_0805B1D6:
	adds r4, #1
	adds r3, r3, r7
	cmp r4, #7
	ble _0805B1BA
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805b1e8
FUN_0805b1e8: @ 0x0805B1E8
	push {r4, r5, lr}
	adds r4, r1, #0
	movs r2, #0
	movs r5, #1
	ldr r1, [r0, #0x18]
	adds r3, r0, #0
	adds r3, #0x40
_0805B1F6:
	adds r0, r5, #0
	lsls r0, r2
	ands r0, r1
	cmp r0, #0
	bne _0805B206
	str r2, [r4]
	adds r0, r3, #0
	b _0805B210
_0805B206:
	adds r3, #0x8c
	adds r2, #1
	cmp r2, #0xf
	ble _0805B1F6
	movs r0, #0
_0805B210:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805b218
FUN_0805b218: @ 0x0805B218
	movs r0, #2
	movs r1, #0
	strb r0, [r2, #2]
	movs r0, #1
	strb r0, [r2, #1]
	strh r1, [r2, #4]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0805b228
FUN_0805b228: @ 0x0805B228
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x20
	adds r2, r0, #0
	adds r7, r1, #0
	movs r0, #0
	movs r5, #0
	strb r0, [r7, #2]
	movs r6, #1
	strb r6, [r7, #1]
	strh r5, [r7, #4]
	strb r0, [r7, #3]
	adds r4, r7, #0
	adds r4, #0x60
	adds r2, #0x24
	adds r0, r4, #0
	adds r1, r2, #0
	movs r2, #3
	bl FUN_0822a470
	strh r6, [r4, #0x10]
	movs r0, #2
	strb r0, [r4, #7]
	movs r0, #0x7c
	adds r0, r0, r7
	mov r8, r0
	str r5, [sp, #0xc]
	add r0, sp, #0xc
	mov r1, r8
	ldr r2, _0805B2E0 @ =0x05000002
	bl CpuSet
	subs r4, #0x50
	ldr r2, _0805B2E4 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r5, #0x1e
	orrs r0, r5
	ldr r1, _0805B2E8 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x10]
	add r3, sp, #0x10
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r5
	str r0, [r3, #4]
	movs r0, #0xf0
	lsls r0, r0, #0xf
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _0805B2EC @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	str r3, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _0805B2F0 @ =FUN_0805b218
	adds r0, r4, #0
	adds r2, r7, #0
	bl FUN_0823651c
	str r6, [sp]
	str r5, [sp, #4]
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0xa
	movs r3, #0x10
	bl FUN_082364f8
	add sp, #0x20
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805B2E0: .4byte 0x05000002
_0805B2E4: .4byte 0xFFFF0000
_0805B2E8: .4byte 0x0000FFFF
_0805B2EC: .4byte 0x00002001
_0805B2F0: .4byte FUN_0805b218

	thumb_func_start FUN_0805b2f4
FUN_0805b2f4: @ 0x0805B2F4
	push {lr}
	adds r0, r1, #0
	adds r0, #0x60
	bl FUN_0822a4e0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805b304
FUN_0805b304: @ 0x0805B304
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r3, [r1, #0x60]
	movs r4, #1
	orrs r3, r4
	str r3, [r1, #0x60]
	lsls r4, r2
	ldr r1, [r5, #0x18]
	bics r1, r4
	str r1, [r5, #0x18]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805b320
FUN_0805b320: @ 0x0805B320
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r4, #0
	adds r3, #0x7c
	ldr r2, [r4, #0xc]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r5, #0
	ldrsh r1, [r3, r5]
	subs r0, r0, r1
	movs r5, #4
	ldrsh r1, [r2, r5]
	movs r5, #4
	ldrsh r2, [r3, r5]
	subs r1, r1, r2
	bl FUN_0823785c
	ldrb r1, [r4, #3]
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	asrs r3, r0, #0x18
	ldrb r1, [r4, #8]
	rsbs r0, r1, #0
	cmp r3, r0
	bge _0805B35A
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	b _0805B360
_0805B35A:
	cmp r3, r1
	ble _0805B360
	adds r2, r1, #0
_0805B360:
	ldrb r0, [r4, #3]
	adds r0, r0, r2
	strb r0, [r4, #3]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805b36c
FUN_0805b36c: @ 0x0805B36C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	adds r6, r1, #0
	mov sl, r2
	adds r7, r6, #0
	adds r7, #0x60
	ldrb r0, [r6, #1]
	cmp r0, #0
	beq _0805B38C
	movs r0, #0
	strb r0, [r6, #1]
_0805B38C:
	mov r3, sp
	ldrb r4, [r6, #3]
	ldrh r5, [r6, #6]
	ldr r2, _0805B3B0 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805B3B4
	asrs r1, r0, #0xc
	b _0805B3BA
	.align 2, 0
_0805B3B0: .4byte 0x085B0A08
_0805B3B4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805B3BA:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805B3D2
	asrs r0, r0, #0xc
	b _0805B3D8
_0805B3D2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805B3D8:
	strh r0, [r3, #4]
	adds r4, r7, #0
	adds r4, #0x1c
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r2, [r7, #0x1c]
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r4, #4]
	adds r0, r0, r1
	strh r0, [r4, #4]
	adds r5, r6, #0
	adds r5, #0x10
	adds r1, r6, #0
	adds r1, #0x7c
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	movs r0, #0x1e
	ldrsh r2, [r7, r0]
	mov r8, r2
	adds r5, r4, #0
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _0805B43C
	cmp r1, #0
	blt _0805B43C
	ldr r0, _0805B440 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0805B43C
	ldr r0, _0805B444 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0805B448
_0805B43C:
	movs r4, #0
	b _0805B456
	.align 2, 0
_0805B440: .4byte 0x030046A8
_0805B444: .4byte 0x030046AC
_0805B448:
	ldr r0, _0805B468 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0805B456:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0805B46C
	adds r0, #4
	b _0805B478
	.align 2, 0
_0805B468: .4byte 0x030046A4
_0805B46C:
	ldr r0, _0805B48C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0805B478:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0805B490
	cmp r2, #2
	beq _0805B494
	b _0805B498
	.align 2, 0
_0805B48C: .4byte 0x030046A4
_0805B490:
	ldrb r0, [r5, #4]
	b _0805B496
_0805B494:
	ldrb r0, [r5]
_0805B496:
	subs r1, r1, r0
_0805B498:
	cmp r8, r1
	bhi _0805B4AA
	movs r0, #2
	movs r1, #0
	strb r0, [r6, #2]
	movs r0, #1
	strb r0, [r6, #1]
	strh r1, [r6, #4]
	b _0805B4C0
_0805B4AA:
	ldrh r0, [r6, #4]
	cmp r0, #0x7f
	bls _0805B4BC
	mov r0, sb
	adds r1, r6, #0
	mov r2, sl
	bl FUN_0805b304
	b _0805B4C0
_0805B4BC:
	adds r0, #1
	strh r0, [r6, #4]
_0805B4C0:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805b4d0
FUN_0805b4d0: @ 0x0805B4D0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	adds r6, r1, #0
	mov sl, r2
	adds r7, r6, #0
	adds r7, #0x60
	ldrb r0, [r6, #1]
	cmp r0, #0
	beq _0805B4F0
	movs r0, #0
	strb r0, [r6, #1]
_0805B4F0:
	adds r0, r6, #0
	bl FUN_0805b320
	mov r3, sp
	ldrb r4, [r6, #3]
	ldrh r5, [r6, #6]
	ldr r2, _0805B518 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805B51C
	asrs r1, r0, #0xc
	b _0805B522
	.align 2, 0
_0805B518: .4byte 0x085B0A08
_0805B51C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805B522:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _0805B53C @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805B540
	asrs r0, r0, #0xc
	b _0805B546
	.align 2, 0
_0805B53C: .4byte 0x085B0A08
_0805B540:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805B546:
	strh r0, [r3, #4]
	adds r4, r7, #0
	adds r4, #0x1c
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r2, [r7, #0x1c]
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r4, #4]
	adds r0, r0, r1
	strh r0, [r4, #4]
	adds r5, r6, #0
	adds r5, #0x10
	adds r1, r6, #0
	adds r1, #0x7c
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	movs r0, #0x1e
	ldrsh r2, [r7, r0]
	mov r8, r2
	adds r5, r4, #0
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _0805B5AA
	cmp r1, #0
	blt _0805B5AA
	ldr r0, _0805B5B0 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0805B5AA
	ldr r0, _0805B5B4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0805B5B8
_0805B5AA:
	movs r4, #0
	b _0805B5C6
	.align 2, 0
_0805B5B0: .4byte 0x030046A8
_0805B5B4: .4byte 0x030046AC
_0805B5B8:
	ldr r0, _0805B5D8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0805B5C6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0805B5DC
	adds r0, #4
	b _0805B5E8
	.align 2, 0
_0805B5D8: .4byte 0x030046A4
_0805B5DC:
	ldr r0, _0805B5FC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0805B5E8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0805B600
	cmp r2, #2
	beq _0805B604
	b _0805B608
	.align 2, 0
_0805B5FC: .4byte 0x030046A4
_0805B600:
	ldrb r0, [r5, #4]
	b _0805B606
_0805B604:
	ldrb r0, [r5]
_0805B606:
	subs r1, r1, r0
_0805B608:
	cmp r8, r1
	bhi _0805B61A
	movs r0, #2
	movs r1, #0
	strb r0, [r6, #2]
	movs r0, #1
	strb r0, [r6, #1]
	strh r1, [r6, #4]
	b _0805B630
_0805B61A:
	ldrh r0, [r6, #4]
	cmp r0, #0x7f
	bls _0805B62C
	mov r0, sb
	adds r1, r6, #0
	mov r2, sl
	bl FUN_0805b304
	b _0805B630
_0805B62C:
	adds r0, #1
	strh r0, [r6, #4]
_0805B630:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805b640
FUN_0805b640: @ 0x0805B640
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r3, r4, #0
	adds r3, #0x60
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0805B658
	movs r0, #0
	strb r0, [r4, #1]
	movs r0, #4
	strh r0, [r3, #0x10]
_0805B658:
	ldrh r0, [r4, #4]
	cmp r0, #3
	bne _0805B6C4
	ldrb r0, [r4, #3]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r1, r0, #3
	movs r0, #7
	ands r1, r0
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _0805B67C
	movs r0, #7
	b _0805B68A
_0805B67C:
	asrs r0, r1, #1
	ands r0, r2
	cmp r0, #0
	beq _0805B688
	movs r0, #8
	b _0805B68A
_0805B688:
	movs r0, #6
_0805B68A:
	strh r0, [r3, #0x10]
	cmp r1, #2
	bgt _0805B698
	ldr r0, [r3]
	movs r1, #0xd
	rsbs r1, r1, #0
	b _0805B6BE
_0805B698:
	cmp r1, #4
	bgt _0805B6A8
	ldr r0, [r3]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #8
	b _0805B6B0
_0805B6A8:
	cmp r1, #5
	bgt _0805B6B6
	ldr r0, [r3]
	movs r1, #0xc
_0805B6B0:
	orrs r0, r1
	str r0, [r3]
	b _0805B6D2
_0805B6B6:
	ldr r0, [r3]
	movs r1, #4
	orrs r0, r1
	subs r1, #0xd
_0805B6BE:
	ands r0, r1
	str r0, [r3]
	b _0805B6D2
_0805B6C4:
	cmp r0, #5
	bls _0805B6D2
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0805b304
	b _0805B6D8
_0805B6D2:
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
_0805B6D8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805b6e0
FUN_0805b6e0: @ 0x0805B6E0
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x40
	movs r5, #0
	ldr r7, _0805B71C @ =0x085ABA20
_0805B6EC:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _0805B70A
	ldrb r0, [r4, #2]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r3, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl _call_via_r3
_0805B70A:
	adds r5, #1
	adds r4, #0x8c
	cmp r5, #0xf
	ble _0805B6EC
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805B71C: .4byte 0x085ABA20

	thumb_func_start FUN_0805b720
FUN_0805b720: @ 0x0805B720
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x40
	movs r4, #0
_0805B72A:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805b2f4
	adds r4, #1
	adds r5, #0x8c
	cmp r4, #0xf
	ble _0805B72A
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805b744
FUN_0805b744: @ 0x0805B744
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	movs r0, #0xa
	strh r0, [r6, #0x1c]
	strh r0, [r6, #0x1e]
	adds r5, r6, #0
	adds r5, #0x24
	ldr r1, _0805B78C @ =0x0000210E
	adds r0, r5, #0
	bl FUN_0822b16c
	str r4, [r6, #0x20]
	movs r1, #0x32
	cmp r4, #0
	bne _0805B766
	movs r1, #0x2c
_0805B766:
	adds r0, r5, #0
	bl FUN_0822b20c
	adds r5, r6, #0
	adds r5, #0x40
	movs r4, #0
_0805B772:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805b228
	adds r4, #1
	adds r5, #0x8c
	cmp r4, #0xf
	ble _0805B772
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805B78C: .4byte 0x0000210E

	thumb_func_start FUN_0805b790
FUN_0805b790: @ 0x0805B790
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x90
	lsls r1, r1, #4
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805B7CC
	ldr r1, _0805B7C4 @ =FUN_0805b6e0
	ldr r2, _0805B7C8 @ =FUN_0805b720
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0805b744
	cmp r0, #0
	bge _0805B7CC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805B7CE
	.align 2, 0
_0805B7C4: .4byte FUN_0805b6e0
_0805B7C8: .4byte FUN_0805b720
_0805B7CC:
	adds r0, r4, #0
_0805B7CE:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805b7d4
FUN_0805b7d4: @ 0x0805B7D4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	mov sb, r1
	mov r8, r2
	adds r4, r3, #0
	add r1, sp, #8
	bl FUN_0805b1e8
	adds r5, r0, #0
	cmp r5, #0
	bne _0805B7F8
	movs r0, #1
	rsbs r0, r0, #0
	b _0805B886
_0805B7F8:
	adds r6, r5, #0
	adds r6, #0x60
	movs r1, #0
	strb r4, [r5]
	ldrb r0, [r5]
	cmp r0, #1
	beq _0805B816
	cmp r0, #1
	bgt _0805B810
	cmp r0, #0
	beq _0805B81A
	b _0805B822
_0805B810:
	cmp r0, #2
	beq _0805B81A
	b _0805B822
_0805B816:
	strb r0, [r5, #2]
	b _0805B81E
_0805B81A:
	strb r1, [r5, #2]
	movs r0, #1
_0805B81E:
	strb r0, [r5, #1]
	strh r1, [r5, #4]
_0805B822:
	ldr r0, [sp, #0x2c]
	strh r0, [r5, #6]
	ldr r0, [sp, #0x28]
	strb r0, [r5, #3]
	movs r2, #1
	strb r2, [r5, #8]
	mov r0, r8
	str r0, [r5, #0xc]
	adds r1, r5, #0
	adds r1, #0x10
	ldr r0, [r7, #0x20]
	mov r8, r1
	cmp r0, #0
	bne _0805B842
	str r2, [sp]
	b _0805B846
_0805B842:
	movs r0, #2
	str r0, [sp]
_0805B846:
	movs r0, #0x1e
	str r0, [sp, #4]
	adds r0, r1, #0
	ldr r1, [sp, #0x30]
	ldr r2, [sp, #0x34]
	movs r3, #0x10
	bl FUN_082364f8
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	movs r4, #1
	strh r4, [r6, #0x10]
	adds r1, r5, #0
	adds r1, #0x7c
	mov r0, r8
	movs r2, #0
	bl FUN_082364c4
	ldr r0, [sp, #8]
	lsls r4, r0
	ldr r0, [r7, #0x18]
	orrs r0, r4
	str r0, [r7, #0x18]
	movs r0, #0
_0805B886:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805b894
FUN_0805b894: @ 0x0805B894
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r2, #0
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r5, #6]
	ands r0, r1
	cmp r0, #0
	beq _0805B8B6
	adds r0, r5, #0
	adds r0, #0x42
	ldrb r0, [r0]
	b _0805B8CE
_0805B8B6:
	movs r1, #0x24
	ldrsh r0, [r6, r1]
	movs r2, #0x24
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	movs r3, #0x28
	ldrsh r1, [r6, r3]
	movs r3, #0x28
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl FUN_0823785c
_0805B8CE:
	strb r0, [r4, #6]
	movs r0, #0
	mov r8, r0
	movs r0, #8
	ldrsb r0, [r4, r0]
	cmp r0, #0
	blt _0805B8E4
	movs r0, #0xfa
	strb r0, [r4, #9]
	mov r1, r8
	strb r1, [r4, #8]
_0805B8E4:
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_08236524
	ldr r3, _0805B93C @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r2, #0x10
	orrs r0, r2
	ldr r1, _0805B940 @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0xc]
	ldrh r1, [r6, #0x3e]
	adds r3, r4, #0
	adds r3, #0x14
	add r2, sp, #8
	str r2, [sp]
	movs r7, #1
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r2, #0
	bl FUN_0805fe7c
	ldrh r0, [r5, #0x3e]
	adds r0, #2
	strh r0, [r5, #0x3e]
	ldrh r0, [r6, #0x3e]
	bl FUN_08029864
	bl FUN_08084710
	adds r1, r0, #0
	cmp r1, #0
	beq _0805B944
	movs r0, #6
	strb r0, [r4, #1]
	strb r7, [r4]
	mov r3, r8
	strh r3, [r4, #4]
	b _0805B94C
	.align 2, 0
_0805B93C: .4byte 0xFFFF0000
_0805B940: .4byte 0x0000FFFF
_0805B944:
	movs r0, #8
	strb r0, [r4, #1]
	strb r7, [r4]
	strh r1, [r4, #4]
_0805B94C:
	movs r0, #0x84
	lsls r0, r0, #1
	bl PlaySound_082406e0
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805b960
FUN_0805b960: @ 0x0805B960
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	bl FUN_08236524
	ldr r3, _0805B9AC @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r2, #0x10
	orrs r0, r2
	ldr r1, _0805B9B0 @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0xc]
	ldrh r1, [r5, #0x3e]
	adds r4, #0x14
	add r0, sp, #8
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	adds r0, r6, #0
	movs r2, #1
	adds r3, r4, #0
	bl FUN_0805fe7c
	ldrh r0, [r5, #0x3e]
	bl FUN_080298b8
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805B9AC: .4byte 0xFFFF0000
_0805B9B0: .4byte 0x0000FFFF

	thumb_func_start FUN_0805b9b4
FUN_0805b9b4: @ 0x0805B9B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov r8, r0
	mov sl, r1
	movs r1, #0
	mov r0, sl
	strb r1, [r0, #1]
	movs r0, #1
	mov r2, sl
	strb r0, [r2]
	strh r1, [r2, #4]
	strb r1, [r2, #6]
	movs r4, #0x84
	lsls r4, r4, #1
	add r4, sl
	ldr r1, _0805BB08 @ =0x0000DA6D
	adds r0, r4, #0
	bl FUN_0822b16c
	adds r0, r4, #0
	ldr r1, _0805BB0C @ =0x00000263
	bl FUN_0822b20c
	ldr r0, _0805BB10 @ =0x00001688
	add r0, r8
	str r0, [r4, #0xc]
	mov r5, sl
	adds r5, #0xdc
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #1
	bl FUN_0822a470
	movs r0, #2
	strb r0, [r5, #7]
	adds r5, #0x1c
	movs r0, #0
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	adds r1, r5, #0
	ldr r2, _0805BB14 @ =0x05000002
	bl CpuSet
	movs r4, #0x92
	lsls r4, r4, #1
	add r4, sl
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0801385c
	adds r0, r4, #0
	bl FUN_080136b4
	mov r7, sl
	adds r7, #0x7c
	ldr r2, _0805BB18 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x20
	orrs r0, r1
	ldr r1, _0805BB1C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x10]
	add r5, sp, #0x10
	ldr r0, [r5, #4]
	ands r0, r2
	movs r1, #0x20
	orrs r0, r1
	str r0, [r5, #4]
	movs r0, #0xf0
	lsls r0, r0, #0xf
	str r0, [sp, #0x18]
	add r4, sp, #0x18
	ldr r0, [r4, #4]
	ands r0, r2
	str r0, [r4, #4]
	ldr r2, _0805BB20 @ =0x00004005
	movs r0, #0x10
	mov sb, r0
	str r0, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	mov r6, sl
	adds r6, #0x14
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _0805BB24 @ =FUN_0805b894
	adds r0, r7, #0
	mov r2, sl
	bl FUN_0823651c
	mov r2, r8
	ldrh r1, [r2, #0x22]
	adds r0, r7, #0
	movs r2, #0x80
	movs r3, #0
	bl FUN_08236514
	adds r0, r7, #0
	bl FUN_08236400
	subs r7, #0x50
	movs r0, #0x20
	strh r0, [r5]
	movs r0, #0xf0
	strh r0, [r5, #2]
	movs r1, #0x20
	strh r1, [r5, #4]
	movs r2, #0
	strh r2, [r4]
	movs r0, #0x78
	strh r0, [r4, #2]
	strh r2, [r4, #4]
	ldr r2, _0805BB28 @ =0x00002001
	mov r0, sb
	str r0, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _0805BB2C @ =FUN_0805b960
	adds r0, r7, #0
	mov r2, sl
	bl FUN_0823651c
	mov r2, r8
	ldrh r1, [r2, #0x20]
	movs r3, #0x80
	lsls r3, r3, #5
	movs r0, #0
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r2, #0x1e
	bl FUN_082364f8
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805BB08: .4byte 0x0000DA6D
_0805BB0C: .4byte 0x00000263
_0805BB10: .4byte 0x00001688
_0805BB14: .4byte 0x05000002
_0805BB18: .4byte 0xFFFF0000
_0805BB1C: .4byte 0x0000FFFF
_0805BB20: .4byte 0x00004005
_0805BB24: .4byte FUN_0805b894
_0805BB28: .4byte 0x00002001
_0805BB2C: .4byte FUN_0805b960

	thumb_func_start FUN_0805bb30
FUN_0805bb30: @ 0x0805BB30
	push {r4, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_08236424
	movs r1, #0x92
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_080138fc
	adds r0, r4, #0
	adds r0, #0xdc
	bl FUN_0822a4e0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805bb54
FUN_0805bb54: @ 0x0805BB54
	push {lr}
	adds r3, r1, #0
	adds r2, r3, #0
	adds r2, #0xdc
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	subs r2, #0x60
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	movs r1, #0x92
	lsls r1, r1, #1
	adds r0, r3, r1
	bl FUN_080136b4
	pop {r1}
	bx r1

	thumb_func_start FUN_0805bb7c
FUN_0805bb7c: @ 0x0805BB7C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x44
	movs r4, #0
_0805BB86:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805bb54
	adds r4, #1
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r5, r5, r0
	cmp r4, #0xf
	ble _0805BB86
	adds r0, r6, #0
	adds r0, #0x38
	bl FUN_080297fc
	movs r0, #0
	str r0, [r6, #0x18]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805bbb0
FUN_0805bbb0: @ 0x0805BBB0
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r5, r1, #0
	ldrb r0, [r5, #6]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r1, r0, #1
	movs r0, #3
	ands r1, r0
	add r4, sp, #4
	mov r3, sp
	adds r3, #5
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r7, r3, #0
	cmp r0, #1
	bhi _0805BBDE
	movs r0, #1
	b _0805BBE0
_0805BBDE:
	movs r0, #0
_0805BBE0:
	strb r0, [r4]
	cmp r1, #1
	bls _0805BBEA
	movs r0, #1
	b _0805BBEC
_0805BBEA:
	movs r0, #0
_0805BBEC:
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0xcc
	ldr r1, [r6, #0x40]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	add r3, sp, #4
	ldrb r3, [r3]
	ldrb r4, [r7]
	str r4, [sp]
	bl FUN_08236fac
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805bc0c
FUN_0805bc0c: @ 0x0805BC0C
	push {r4, r5, r6, lr}
	mov ip, r0
	mov r6, ip
	adds r6, #0xdc
	mov r2, ip
	adds r2, #0xf8
	mov r3, ip
	ldr r0, [r3, #0x14]
	ldr r1, [r3, #0x18]
	str r0, [r2]
	str r1, [r2, #4]
	mov r4, ip
	adds r4, #0xcc
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0805BC52
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _0805BC5A
_0805BC52:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0805BC5A:
	str r0, [r6]
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
	beq _0805BC7E
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0805BC86
_0805BC7E:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0805BC86:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0805BCC0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0805BD06
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0805BCCA
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0805BCC4
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _0805BCE0
	.align 2, 0
_0805BCC0: .4byte 0x0000FFFF
_0805BCC4:
	subs r0, #1
	strh r0, [r4, #8]
	b _0805BCDE
_0805BCCA:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0805BCDE
	strh r1, [r4, #8]
	movs r2, #1
	b _0805BCE0
_0805BCDE:
	movs r2, #0
_0805BCE0:
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
	bne _0805BD08
	movs r0, #1
	strb r0, [r4, #7]
	b _0805BD08
_0805BD06:
	movs r2, #0
_0805BD08:
	mov r3, ip
	strb r2, [r3, #2]
	ldrb r0, [r3, #1]
	cmp r0, #7
	beq _0805BD58
	movs r0, #0x16
	ldrsh r1, [r3, r0]
	ldrh r0, [r3, #0xe]
	cmp r1, r0
	ble _0805BD24
	ldrh r0, [r3, #0x16]
	subs r0, #1
	strh r0, [r3, #0x16]
	b _0805BD30
_0805BD24:
	cmp r1, r0
	bge _0805BD30
	mov r1, ip
	ldrh r0, [r1, #0x16]
	adds r0, #1
	strh r0, [r1, #0x16]
_0805BD30:
	ldr r0, _0805BD48 @ =0x085B0A08
	mov r2, ip
	ldrb r1, [r2, #3]
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	lsls r0, r0, #5
	cmp r0, #0
	blt _0805BD4C
	asrs r1, r0, #0xc
	b _0805BD52
	.align 2, 0
_0805BD48: .4byte 0x085B0A08
_0805BD4C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805BD52:
	ldrh r0, [r6, #0x1e]
	adds r0, r0, r1
	strh r0, [r6, #0x1e]
_0805BD58:
	mov r1, ip
	ldrb r0, [r1, #3]
	adds r0, #4
	strb r0, [r1, #3]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805bd68
FUN_0805bd68: @ 0x0805BD68
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	adds r4, r1, #0
	mov r8, r2
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805BD80
	movs r0, #0
	strb r0, [r4]
_0805BD80:
	ldrh r0, [r4, #0x10]
	mov r3, sp
	ldrb r5, [r4, #6]
	lsls r6, r0, #1
	ldr r2, _0805BDA4 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805BDA8
	asrs r1, r0, #0xc
	b _0805BDAE
	.align 2, 0
_0805BDA4: .4byte 0x085B0A08
_0805BDA8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805BDAE:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805BDC6
	asrs r0, r0, #0xc
	b _0805BDCC
_0805BDC6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805BDCC:
	strh r0, [r3, #4]
	adds r1, r4, #0
	adds r1, #0x14
	mov r2, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r4, #0x14]
	adds r0, r0, r3
	strh r0, [r4, #0x14]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0
	bl FUN_082364c4
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0805bbb0
	ldrh r1, [r4, #4]
	mov r0, r8
	adds r0, #2
	cmp r1, r0
	blt _0805BE16
	movs r0, #1
	strb r0, [r4, #1]
	strb r0, [r4]
	movs r0, #0
	strh r0, [r4, #4]
_0805BE16:
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805be28
FUN_0805be28: @ 0x0805BE28
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	adds r4, r1, #0
	mov sb, r2
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805BE58
	movs r0, #0
	strb r0, [r4]
	adds r0, r4, #0
	adds r0, #0x7c
	movs r1, #5
	rsbs r1, r1, #0
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
	adds r1, r4, #0
	adds r1, #0x14
	movs r2, #0
	bl FUN_082364c4
_0805BE58:
	mov r0, r8
	ldrb r1, [r0, #0x1c]
	cmp r1, #0
	beq _0805BE66
	movs r0, #5
	movs r1, #0
	b _0805BE70
_0805BE66:
	mov r2, r8
	ldrb r0, [r2, #0x1e]
	cmp r0, #0
	beq _0805BE7A
	movs r0, #9
_0805BE70:
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	strh r1, [r4, #4]
	b _0805BF52
_0805BE7A:
	movs r0, #8
	ldrsb r0, [r4, r0]
	adds r5, r4, #0
	adds r5, #0x14
	cmp r0, #0
	blt _0805BEF4
	ldrh r0, [r4, #4]
	movs r3, #7
	ands r3, r0
	movs r6, #8
	ldrsb r6, [r4, r6]
	movs r7, #0x28
	add r7, r8
	mov ip, r7
	cmp r3, #0
	bne _0805BED4
	lsls r0, r6, #2
	add r0, ip
	ldr r1, [r0]
	movs r0, #0
	ldrsh r2, [r1, r0]
	movs r7, #0x14
	ldrsh r0, [r4, r7]
	subs r2, r2, r0
	movs r7, #4
	ldrsh r0, [r1, r7]
	movs r7, #4
	ldrsh r1, [r5, r7]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _0805BED0 @ =0x00022E24
	cmp r1, r0
	ble _0805BED4
	movs r0, #1
	strb r0, [r4, #1]
	strb r0, [r4]
	strh r3, [r4, #4]
	b _0805BF52
	.align 2, 0
_0805BED0: .4byte 0x00022E24
_0805BED4:
	lsls r0, r6, #2
	add r0, ip
	ldr r2, [r0]
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r7, #0x14
	ldrsh r1, [r4, r7]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r7, #4
	ldrsh r2, [r5, r7]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r4, #6]
_0805BEF4:
	adds r0, r4, #0
	adds r0, #0x7c
	adds r1, r5, #0
	movs r2, #0
	bl FUN_082364c4
	mov r0, r8
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0805bbb0
	ldrh r0, [r4, #4]
	cmp r0, #0x3f
	bls _0805BF1C
	movs r0, #4
	movs r1, #0
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	strh r1, [r4, #4]
_0805BF1C:
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _0805BF4C
	subs r0, #1
	strb r0, [r4, #9]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0805BF4C
	mov r2, r8
	ldrb r0, [r2, #0x1f]
	cmp r0, #2
	bne _0805BF44
	mov r3, sb
	cmp r3, #7
	bgt _0805BF40
	movs r0, #1
	b _0805BF4A
_0805BF40:
	strb r1, [r4, #8]
	b _0805BF4C
_0805BF44:
	cmp r0, #0
	beq _0805BF4A
	movs r0, #0xff
_0805BF4A:
	strb r0, [r4, #8]
_0805BF4C:
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
_0805BF52:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805bf60
FUN_0805bf60: @ 0x0805BF60
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	adds r5, r1, #0
	mov sl, r2
	ldrb r0, [r5]
	cmp r0, #0
	bne _0805BF7A
	b _0805C084
_0805BF7A:
	movs r0, #0
	strb r0, [r5]
	movs r0, #8
	ldrsb r0, [r5, r0]
	adds r7, r5, #0
	adds r7, #0x1c
	cmp r0, #0
	blt _0805C026
	ldr r2, _0805BFBC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805BFC0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0805BFC4 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	mov r4, sp
	ldrb r6, [r0]
	ldr r1, _0805BFC8 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #8
	cmp r0, #0
	blt _0805BFCC
	asrs r3, r0, #0xc
	b _0805BFD2
	.align 2, 0
_0805BFBC: .4byte 0x030046B8
_0805BFC0: .4byte 0x000003FF
_0805BFC4: .4byte 0x0203B400
_0805BFC8: .4byte 0x085B0A08
_0805BFCC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805BFD2:
	movs r0, #0
	strh r3, [r4]
	strh r0, [r4, #2]
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x80
	lsls r0, r0, #1
	muls r0, r1, r0
	cmp r0, #0
	blt _0805BFEE
	asrs r0, r0, #0xc
	b _0805BFF4
_0805BFEE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805BFF4:
	strh r0, [r4, #4]
	movs r0, #8
	ldrsb r0, [r5, r0]
	lsls r0, r0, #2
	mov r1, sb
	adds r1, #0x28
	adds r1, r1, r0
	adds r2, r5, #0
	adds r2, #0x1c
	ldr r1, [r1]
	mov r3, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r4, [r1]
	adds r0, r0, r4
	strh r0, [r5, #0x1c]
	ldrh r0, [r3, #2]
	ldrh r4, [r1, #2]
	adds r0, r0, r4
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	adds r7, r2, #0
_0805C026:
	movs r1, #0x1c
	ldrsh r0, [r5, r1]
	movs r2, #0x14
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r7, r3]
	movs r4, #0x18
	ldrsh r2, [r5, r4]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r5, #6]
	ldr r4, _0805C094 @ =0x0203B400
	ldr r2, _0805C098 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _0805C09C @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	subs r0, #0x20
	ldrb r1, [r5, #6]
	adds r0, r0, r1
	strb r0, [r5, #6]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	strb r0, [r5, #7]
	adds r2, r5, #0
	adds r2, #0x7c
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_0805C084:
	mov r2, sb
	ldrb r1, [r2, #0x1c]
	cmp r1, #0
	beq _0805C0A0
	movs r0, #5
	movs r1, #0
	b _0805C0AA
	.align 2, 0
_0805C094: .4byte 0x0203B400
_0805C098: .4byte 0x030046B8
_0805C09C: .4byte 0x000003FF
_0805C0A0:
	mov r3, sb
	ldrb r0, [r3, #0x1e]
	cmp r0, #0
	beq _0805C0B4
	movs r0, #9
_0805C0AA:
	strb r0, [r5, #1]
	movs r0, #1
	strb r0, [r5]
	strh r1, [r5, #4]
	b _0805C320
_0805C0B4:
	ldrb r0, [r5, #7]
	cmp r0, #0
	beq _0805C0BC
	b _0805C210
_0805C0BC:
	ldr r6, _0805C110 @ =0x0203B400
	ldr r2, _0805C114 @ =0x030046B8
	ldr r0, [r2]
	adds r1, r0, #1
	ldr r3, _0805C118 @ =0x000003FF
	ands r1, r3
	str r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r6
	movs r4, #0xff
	ldrb r0, [r0]
	cmp r0, #0xbf
	ble _0805C0D8
	b _0805C1CC
_0805C0D8:
	movs r0, #8
	ldrsb r0, [r5, r0]
	adds r7, r5, #0
	adds r7, #0x1c
	cmp r0, #0
	blt _0805C180
	adds r0, r1, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r2, [r0]
	mov r3, sp
	ands r2, r4
	ldr r1, _0805C11C @ =0x085B0A08
	adds r0, r2, #0
	adds r0, #0x40
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #8
	cmp r0, #0
	blt _0805C120
	asrs r1, r0, #0xc
	b _0805C126
	.align 2, 0
_0805C110: .4byte 0x0203B400
_0805C114: .4byte 0x030046B8
_0805C118: .4byte 0x000003FF
_0805C11C: .4byte 0x085B0A08
_0805C120:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805C126:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _0805C144 @ =0x085B0A08
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #1
	muls r0, r1, r0
	cmp r0, #0
	blt _0805C148
	asrs r0, r0, #0xc
	b _0805C14E
	.align 2, 0
_0805C144: .4byte 0x085B0A08
_0805C148:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C14E:
	strh r0, [r3, #4]
	movs r0, #8
	ldrsb r0, [r5, r0]
	lsls r0, r0, #2
	mov r1, sb
	adds r1, #0x28
	adds r1, r1, r0
	adds r2, r5, #0
	adds r2, #0x1c
	ldr r1, [r1]
	mov r3, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r4, [r1]
	adds r0, r0, r4
	strh r0, [r5, #0x1c]
	ldrh r0, [r3, #2]
	ldrh r4, [r1, #2]
	adds r0, r0, r4
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	adds r7, r2, #0
_0805C180:
	adds r4, r5, #0
	adds r4, #0x14
	movs r1, #0x1c
	ldrsh r0, [r5, r1]
	movs r2, #0x14
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r7, r3]
	movs r3, #4
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r5, #6]
	ldr r2, _0805C1C0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805C1C4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0805C1C8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	subs r0, #0x20
	ldrb r2, [r5, #6]
	adds r0, r0, r2
	strb r0, [r5, #6]
	b _0805C1E4
	.align 2, 0
_0805C1C0: .4byte 0x030046B8
_0805C1C4: .4byte 0x000003FF
_0805C1C8: .4byte 0x0203B400
_0805C1CC:
	adds r0, r1, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0805C204 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	strb r0, [r5, #6]
	adds r7, r5, #0
	adds r7, #0x1c
	adds r4, r5, #0
	adds r4, #0x14
_0805C1E4:
	ldr r2, _0805C208 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805C20C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0805C204 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	strb r0, [r5, #7]
	b _0805C21C
	.align 2, 0
_0805C204: .4byte 0x0203B400
_0805C208: .4byte 0x030046B8
_0805C20C: .4byte 0x000003FF
_0805C210:
	subs r0, #1
	strb r0, [r5, #7]
	adds r7, r5, #0
	adds r7, #0x1c
	adds r4, r5, #0
	adds r4, #0x14
_0805C21C:
	mov r6, sp
	ldrb r2, [r5, #6]
	mov ip, r2
	ldrh r3, [r5, #0x10]
	mov r8, r3
	ldr r2, _0805C248 @ =0x085B0A08
	mov r0, ip
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r3, r8
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r2, #0
	cmp r0, #0
	blt _0805C24C
	asrs r3, r0, #0xc
	b _0805C252
	.align 2, 0
_0805C248: .4byte 0x085B0A08
_0805C24C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805C252:
	movs r0, #0
	strh r3, [r6]
	strh r0, [r6, #2]
	mov r2, ip
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _0805C270
	asrs r0, r0, #0xc
	b _0805C276
_0805C270:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C276:
	movs r2, #0
	mov r8, r2
	strh r0, [r6, #4]
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r5, #0x14]
	adds r0, r0, r3
	strh r0, [r5, #0x14]
	ldrh r0, [r1, #2]
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r4, #4]
	adds r0, r0, r3
	strh r0, [r4, #4]
	adds r0, r5, #0
	adds r0, #0x7c
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	mov r0, sb
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0805bbb0
	movs r0, #0x1c
	ldrsh r2, [r5, r0]
	movs r1, #0x14
	ldrsh r0, [r5, r1]
	subs r2, r2, r0
	movs r3, #4
	ldrsh r0, [r7, r3]
	movs r3, #4
	ldrsh r1, [r4, r3]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	ldr r0, _0805C2E0 @ =0x00003FFF
	cmp r1, r0
	bgt _0805C2E4
	movs r0, #2
	strb r0, [r5, #1]
	movs r0, #1
	strb r0, [r5]
	movs r0, #0
	b _0805C31E
	.align 2, 0
_0805C2E0: .4byte 0x00003FFF
_0805C2E4:
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _0805C31A
	subs r0, #1
	strb r0, [r5, #9]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805C31A
	mov r1, sb
	ldrb r0, [r1, #0x1f]
	cmp r0, #2
	bne _0805C30C
	mov r2, sl
	cmp r2, #7
	bgt _0805C306
	movs r0, #1
	b _0805C318
_0805C306:
	mov r3, r8
	strb r3, [r5, #8]
	b _0805C31A
_0805C30C:
	cmp r0, #0
	bne _0805C316
	mov r4, r8
	strb r4, [r5, #8]
	b _0805C31A
_0805C316:
	movs r0, #0xff
_0805C318:
	strb r0, [r5, #8]
_0805C31A:
	ldrh r0, [r5, #4]
	adds r0, #1
_0805C31E:
	strh r0, [r5, #4]
_0805C320:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805c330
FUN_0805c330: @ 0x0805C330
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	adds r4, r1, #0
	mov r8, r2
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805C382
	movs r0, #0
	strb r0, [r4]
	ldr r3, _0805C390 @ =0x0203B400
	ldr r1, _0805C394 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0805C398 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	strb r0, [r4, #6]
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	strb r0, [r4, #7]
	adds r2, r4, #0
	adds r2, #0x7c
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_0805C382:
	ldrb r1, [r7, #0x1c]
	cmp r1, #0
	beq _0805C39C
	movs r0, #5
	movs r1, #0
	b _0805C3A4
	.align 2, 0
_0805C390: .4byte 0x0203B400
_0805C394: .4byte 0x030046B8
_0805C398: .4byte 0x000003FF
_0805C39C:
	ldrb r0, [r7, #0x1e]
	cmp r0, #0
	beq _0805C3AE
	movs r0, #9
_0805C3A4:
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	strh r1, [r4, #4]
	b _0805C4B8
_0805C3AE:
	ldrb r0, [r4, #7]
	cmp r0, #0
	bne _0805C3EC
	ldr r3, _0805C3E0 @ =0x0203B400
	ldr r1, _0805C3E4 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0805C3E8 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	strb r0, [r4, #6]
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	b _0805C3EE
	.align 2, 0
_0805C3E0: .4byte 0x0203B400
_0805C3E4: .4byte 0x030046B8
_0805C3E8: .4byte 0x000003FF
_0805C3EC:
	subs r0, #1
_0805C3EE:
	strb r0, [r4, #7]
	mov r3, sp
	ldrb r5, [r4, #6]
	ldrh r6, [r4, #0x10]
	ldr r2, _0805C414 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805C418
	asrs r1, r0, #0xc
	b _0805C41E
	.align 2, 0
_0805C414: .4byte 0x085B0A08
_0805C418:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805C41E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805C436
	asrs r0, r0, #0xc
	b _0805C43C
_0805C436:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C43C:
	movs r5, #0
	strh r0, [r3, #4]
	adds r1, r4, #0
	adds r1, #0x14
	mov r2, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r4, #0x14]
	adds r0, r0, r3
	strh r0, [r4, #0x14]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0
	bl FUN_082364c4
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0805bbb0
	ldrh r0, [r4, #4]
	cmp r0, #0x1f
	bls _0805C486
	movs r0, #2
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	movs r0, #0
	b _0805C4B6
_0805C486:
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _0805C4B2
	subs r0, #1
	strb r0, [r4, #9]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805C4B2
	ldrb r0, [r7, #0x1f]
	cmp r0, #2
	bne _0805C4A6
	mov r3, r8
	cmp r3, #7
	bgt _0805C4AA
	movs r0, #1
	b _0805C4B0
_0805C4A6:
	cmp r0, #0
	bne _0805C4AE
_0805C4AA:
	strb r5, [r4, #8]
	b _0805C4B2
_0805C4AE:
	movs r0, #0xff
_0805C4B0:
	strb r0, [r4, #8]
_0805C4B2:
	ldrh r0, [r4, #4]
	adds r0, #1
_0805C4B6:
	strh r0, [r4, #4]
_0805C4B8:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805c4c4
FUN_0805c4c4: @ 0x0805C4C4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	adds r6, r1, #0
	mov sb, r2
	ldrb r0, [r6]
	cmp r0, #0
	beq _0805C524
	movs r0, #0
	strb r0, [r6]
	adds r2, r6, #0
	adds r2, #0x7c
	subs r0, #5
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
	adds r3, r6, #0
	adds r3, #0x14
	ldr r0, [r6, #0x14]
	ldr r1, [r6, #0x18]
	str r0, [r6, #0x24]
	str r1, [r6, #0x28]
	movs r0, #8
	ldrsb r0, [r6, r0]
	cmp r0, #0
	blt _0805C524
	adds r1, r0, #0
	lsls r1, r1, #2
	adds r0, r7, #0
	adds r0, #0x28
	adds r0, r0, r1
	ldr r2, [r0]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r4, #0x14
	ldrsh r1, [r6, r4]
	subs r0, r0, r1
	movs r4, #4
	ldrsh r1, [r2, r4]
	movs r4, #4
	ldrsh r2, [r3, r4]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r6, #6]
_0805C524:
	ldrb r1, [r7, #0x1c]
	cmp r1, #0
	beq _0805C530
	movs r0, #5
	movs r1, #0
	b _0805C538
_0805C530:
	ldrb r0, [r7, #0x1e]
	cmp r0, #0
	beq _0805C542
	movs r0, #9
_0805C538:
	strb r0, [r6, #1]
	movs r0, #1
	strb r0, [r6]
	strh r1, [r6, #4]
	b _0805C636
_0805C542:
	ldrh r0, [r6, #4]
	cmp r0, #0xf
	bls _0805C54E
	ldrh r1, [r6, #4]
	movs r0, #0x20
	subs r0, r0, r1
_0805C54E:
	lsls r3, r0, #4
	mov r4, sp
	ldrb r5, [r6, #6]
	ldr r2, _0805C570 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _0805C574
	asrs r1, r0, #0xc
	b _0805C57A
	.align 2, 0
_0805C570: .4byte 0x085B0A08
_0805C574:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805C57A:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _0805C592
	asrs r0, r0, #0xc
	b _0805C598
_0805C592:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C598:
	movs r3, #0
	mov r8, r3
	strh r0, [r4, #4]
	adds r4, r6, #0
	adds r4, #0x14
	adds r2, r6, #0
	adds r2, #0x24
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r6, #0x24]
	adds r0, r0, r3
	strh r0, [r6, #0x14]
	ldrh r0, [r1, #2]
	ldrh r3, [r2, #2]
	adds r0, r0, r3
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r4, #4]
	adds r5, r6, #0
	adds r5, #0x2c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r6, #0
	adds r0, #0x7c
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0805bbb0
	ldrh r0, [r6, #4]
	cmp r0, #0x1f
	bls _0805C5FE
	movs r0, #2
	strb r0, [r6, #1]
	movs r0, #1
	strb r0, [r6]
	movs r0, #0
	b _0805C634
_0805C5FE:
	ldrb r0, [r6, #9]
	cmp r0, #0
	beq _0805C630
	subs r0, #1
	strb r0, [r6, #9]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805C630
	ldrb r0, [r7, #0x1f]
	cmp r0, #2
	bne _0805C622
	mov r4, sb
	cmp r4, #7
	bgt _0805C61E
	movs r0, #1
	b _0805C62E
_0805C61E:
	mov r0, r8
	b _0805C62E
_0805C622:
	cmp r0, #0
	bne _0805C62C
	mov r1, r8
	strb r1, [r6, #8]
	b _0805C630
_0805C62C:
	movs r0, #0xff
_0805C62E:
	strb r0, [r6, #8]
_0805C630:
	ldrh r0, [r6, #4]
	adds r0, #1
_0805C634:
	strh r0, [r6, #4]
_0805C636:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805c644
FUN_0805c644: @ 0x0805C644
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	mov r8, r0
	adds r7, r1, #0
	ldrb r0, [r7]
	cmp r0, #0
	beq _0805C748
	movs r0, #0
	strb r0, [r7]
	ldr r2, _0805C68C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805C690 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0805C694 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	mov r4, sp
	ldrb r5, [r0]
	ldr r1, _0805C698 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #5
	cmp r0, #0
	blt _0805C69C
	asrs r3, r0, #0xc
	b _0805C6A2
	.align 2, 0
_0805C68C: .4byte 0x030046B8
_0805C690: .4byte 0x000003FF
_0805C694: .4byte 0x0203B400
_0805C698: .4byte 0x085B0A08
_0805C69C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805C6A2:
	movs r0, #0
	strh r3, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _0805C6BC
	asrs r0, r0, #0xc
	b _0805C6C2
_0805C6BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C6C2:
	strh r0, [r4, #4]
	adds r2, r7, #0
	adds r2, #0x1c
	mov r3, r8
	adds r3, #0x30
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	mov r4, r8
	ldrh r4, [r4, #0x30]
	adds r0, r0, r4
	strh r0, [r7, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r5, [r3, #2]
	adds r0, r0, r5
	strh r0, [r2, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	movs r1, #0x1c
	ldrsh r0, [r7, r1]
	movs r3, #0x14
	ldrsh r1, [r7, r3]
	subs r0, r0, r1
	movs r4, #4
	ldrsh r1, [r2, r4]
	movs r5, #0x18
	ldrsh r2, [r7, r5]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r7, #6]
	ldr r4, _0805C758 @ =0x0203B400
	ldr r2, _0805C75C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _0805C760 @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x60
	ldrb r1, [r7, #6]
	adds r0, r0, r1
	strb r0, [r7, #6]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r0, #0x20
	strb r0, [r7, #7]
	adds r2, r7, #0
	adds r2, #0x7c
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_0805C748:
	mov r2, r8
	ldrb r1, [r2, #0x1c]
	cmp r1, #0
	bne _0805C764
	movs r0, #1
	strb r0, [r7, #1]
	b _0805C80A
	.align 2, 0
_0805C758: .4byte 0x0203B400
_0805C75C: .4byte 0x030046B8
_0805C760: .4byte 0x000003FF
_0805C764:
	ldrb r0, [r7, #7]
	cmp r0, #0
	bne _0805C7D0
	adds r6, r7, #0
	adds r6, #0x14
	adds r5, r7, #0
	adds r5, #0x1c
	movs r3, #0x1c
	ldrsh r0, [r7, r3]
	movs r4, #0x14
	ldrsh r1, [r7, r4]
	subs r0, r0, r1
	movs r2, #4
	ldrsh r1, [r5, r2]
	movs r3, #4
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r7, #6]
	ldr r4, _0805C7C4 @ =0x0203B400
	ldr r2, _0805C7C8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _0805C7CC @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x60
	ldrb r1, [r7, #6]
	adds r0, r0, r1
	strb r0, [r7, #6]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r0, #0x20
	strb r0, [r7, #7]
	b _0805C7DC
	.align 2, 0
_0805C7C4: .4byte 0x0203B400
_0805C7C8: .4byte 0x030046B8
_0805C7CC: .4byte 0x000003FF
_0805C7D0:
	subs r0, #1
	strb r0, [r7, #7]
	adds r5, r7, #0
	adds r5, #0x1c
	adds r6, r7, #0
	adds r6, #0x14
_0805C7DC:
	movs r3, #0x1c
	ldrsh r2, [r7, r3]
	movs r4, #0x14
	ldrsh r0, [r7, r4]
	subs r2, r2, r0
	movs r1, #4
	ldrsh r0, [r5, r1]
	movs r3, #4
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	ldr r0, _0805C810 @ =0x00000FFF
	cmp r1, r0
	bhi _0805C814
	movs r0, #7
	movs r1, #0
	strb r0, [r7, #1]
	movs r0, #1
_0805C80A:
	strb r0, [r7]
	strh r1, [r7, #4]
	b _0805C9A8
	.align 2, 0
_0805C810: .4byte 0x00000FFF
_0805C814:
	ldr r0, _0805C848 @ =0x0000FFFF
	cmp r1, r0
	bhi _0805C898
	ldrb r0, [r7, #6]
	add r5, sp, #8
	adds r4, r0, #0
	adds r4, #0x80
	movs r1, #5
	mov ip, r1
	ldr r2, _0805C84C @ =0x085B0A08
	adds r0, #0xc0
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	adds r1, r2, #0
	adds r2, r5, #0
	cmp r0, #0
	blt _0805C850
	asrs r3, r0, #0xc
	b _0805C856
	.align 2, 0
_0805C848: .4byte 0x0000FFFF
_0805C84C: .4byte 0x085B0A08
_0805C850:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805C856:
	movs r0, #0
	strh r3, [r5]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r4, r0
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r4, ip
	muls r4, r0, r4
	adds r0, r4, #0
	cmp r0, #0
	blt _0805C876
	asrs r0, r0, #0xc
	b _0805C87C
_0805C876:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C87C:
	strh r0, [r5, #4]
	add r0, sp, #8
	ldrh r0, [r0]
	ldrh r5, [r7, #0x14]
	adds r0, r0, r5
	strh r0, [r7, #0x14]
	ldrh r0, [r2, #2]
	ldrh r1, [r6, #2]
	adds r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r6, #4]
	adds r0, r0, r2
	b _0805C98A
_0805C898:
	ldrh r0, [r7, #4]
	movs r1, #0x7f
	ands r1, r0
	cmp r1, #0x3f
	bgt _0805C912
	ldrb r0, [r7, #6]
	add r5, sp, #8
	adds r4, r0, #0
	adds r4, #0x80
	ldr r2, _0805C8C8 @ =0x085B0A08
	adds r0, #0xc0
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #3
	adds r1, r2, #0
	adds r2, r5, #0
	cmp r0, #0
	blt _0805C8CC
	asrs r3, r0, #0xc
	b _0805C8D2
	.align 2, 0
_0805C8C8: .4byte 0x085B0A08
_0805C8CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805C8D2:
	movs r0, #0
	strh r3, [r5]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r4, r0
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #8
	muls r0, r1, r0
	cmp r0, #0
	blt _0805C8F0
	asrs r0, r0, #0xc
	b _0805C8F6
_0805C8F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C8F6:
	strh r0, [r5, #4]
	add r0, sp, #8
	ldrh r0, [r0]
	ldrh r5, [r7, #0x14]
	adds r0, r0, r5
	strh r0, [r7, #0x14]
	ldrh r0, [r2, #2]
	ldrh r1, [r6, #2]
	adds r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r6, #4]
	adds r0, r0, r2
	b _0805C98A
_0805C912:
	cmp r1, #0x5f
	bgt _0805C98C
	add r4, sp, #8
	ldrb r5, [r7, #6]
	movs r3, #6
	mov ip, r3
	ldr r2, _0805C944 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r3, ip
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r2, #0
	adds r2, r4, #0
	cmp r0, #0
	blt _0805C948
	asrs r3, r0, #0xc
	b _0805C94E
	.align 2, 0
_0805C944: .4byte 0x085B0A08
_0805C948:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805C94E:
	movs r0, #0
	strh r3, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _0805C96A
	asrs r0, r0, #0xc
	b _0805C970
_0805C96A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C970:
	strh r0, [r4, #4]
	add r0, sp, #8
	ldrh r0, [r0]
	ldrh r3, [r7, #0x14]
	adds r0, r0, r3
	strh r0, [r7, #0x14]
	ldrh r0, [r2, #2]
	ldrh r4, [r6, #2]
	adds r0, r0, r4
	strh r0, [r6, #2]
	ldrh r0, [r2, #4]
	ldrh r5, [r6, #4]
	adds r0, r0, r5
_0805C98A:
	strh r0, [r6, #4]
_0805C98C:
	adds r0, r7, #0
	adds r0, #0x7c
	adds r1, r6, #0
	movs r2, #0
	bl FUN_082364c4
	mov r0, r8
	adds r1, r7, #0
	movs r2, #0
	bl FUN_0805bbb0
	ldrh r0, [r7, #4]
	adds r0, #1
	strh r0, [r7, #4]
_0805C9A8:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805c9b4
FUN_0805c9b4: @ 0x0805C9B4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805CA82
	movs r0, #0
	strb r0, [r4]
	ldr r2, _0805CA00 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805CA04 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0805CA08 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	mov r5, sp
	ldrb r6, [r0]
	ldr r1, _0805CA0C @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #5
	adds r2, r1, #0
	cmp r0, #0
	blt _0805CA10
	asrs r3, r0, #0xc
	b _0805CA16
	.align 2, 0
_0805CA00: .4byte 0x030046B8
_0805CA04: .4byte 0x000003FF
_0805CA08: .4byte 0x0203B400
_0805CA0C: .4byte 0x085B0A08
_0805CA10:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805CA16:
	movs r0, #0
	strh r3, [r5]
	strh r0, [r5, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _0805CA30
	asrs r0, r0, #0xc
	b _0805CA36
_0805CA30:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805CA36:
	strh r0, [r5, #4]
	adds r2, r4, #0
	adds r2, #0x1c
	adds r3, r7, #0
	adds r3, #0x30
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r5, [r7, #0x30]
	adds r0, r0, r5
	strh r0, [r4, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r5, [r3, #2]
	adds r0, r0, r5
	strh r0, [r2, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	movs r1, #0x1c
	ldrsh r0, [r4, r1]
	movs r3, #0x14
	ldrsh r1, [r4, r3]
	subs r0, r0, r1
	movs r5, #4
	ldrsh r1, [r2, r5]
	movs r3, #0x18
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r4, #6]
	adds r2, r4, #0
	adds r2, #0x7c
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
_0805CA82:
	ldrb r1, [r7, #0x1c]
	cmp r1, #0
	bne _0805CA8E
	movs r0, #1
	strb r0, [r4, #1]
	b _0805CAC2
_0805CA8E:
	adds r3, r4, #0
	adds r3, #0x14
	movs r5, #0x1c
	ldrsh r2, [r4, r5]
	movs r1, #0x14
	ldrsh r0, [r4, r1]
	subs r2, r2, r0
	movs r5, #0x20
	ldrsh r0, [r4, r5]
	movs r5, #4
	ldrsh r1, [r3, r5]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _0805CAC8 @ =0x00000FFF
	adds r5, r3, #0
	cmp r1, r0
	bhi _0805CACC
	movs r0, #7
	movs r1, #0
	strb r0, [r4, #1]
	movs r0, #1
_0805CAC2:
	strb r0, [r4]
	strh r1, [r4, #4]
	b _0805CB6E
	.align 2, 0
_0805CAC8: .4byte 0x00000FFF
_0805CACC:
	add r3, sp, #8
	ldrb r6, [r4, #6]
	movs r0, #0x18
	mov ip, r0
	ldr r2, _0805CAF8 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	mov r8, r3
	cmp r0, #0
	blt _0805CAFC
	asrs r1, r0, #0xc
	b _0805CB02
	.align 2, 0
_0805CAF8: .4byte 0x085B0A08
_0805CAFC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805CB02:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _0805CB1E
	asrs r0, r0, #0xc
	b _0805CB24
_0805CB1E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805CB24:
	strh r0, [r3, #4]
	add r0, sp, #8
	ldrh r0, [r0]
	ldrh r2, [r4, #0x14]
	adds r0, r0, r2
	strh r0, [r4, #0x14]
	mov r3, r8
	ldrh r0, [r3, #2]
	ldrh r1, [r5, #2]
	adds r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r3, #4]
	ldrh r2, [r5, #4]
	adds r0, r0, r2
	strh r0, [r5, #4]
	adds r0, r4, #0
	adds r0, #0x7c
	adds r1, r5, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #1
	bl FUN_0805bbb0
	ldrh r0, [r4, #4]
	cmp r0, #9
	bls _0805CB6A
	movs r0, #5
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	movs r0, #0
	b _0805CB6C
_0805CB6A:
	adds r0, #1
_0805CB6C:
	strh r0, [r4, #4]
_0805CB6E:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805cb7c
FUN_0805cb7c: @ 0x0805CB7C
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805CBCE
	movs r0, #0
	strb r0, [r4]
	movs r1, #0x1c
	ldrsh r0, [r4, r1]
	movs r2, #0x14
	ldrsh r1, [r4, r2]
	subs r0, r0, r1
	movs r3, #0x20
	ldrsh r1, [r4, r3]
	movs r5, #0x18
	ldrsh r2, [r4, r5]
	subs r1, r1, r2
	bl FUN_0823785c
	adds r2, r4, #0
	adds r2, #0x7c
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, _0805CBE0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805CBE4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0805CBE8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	strb r0, [r4, #7]
_0805CBCE:
	ldrb r1, [r7, #0x1c]
	cmp r1, #0
	bne _0805CBEC
	movs r0, #1
	strb r0, [r4, #1]
	strb r0, [r4]
	strh r1, [r4, #4]
	b _0805CD00
	.align 2, 0
_0805CBE0: .4byte 0x030046B8
_0805CBE4: .4byte 0x000003FF
_0805CBE8: .4byte 0x0203B400
_0805CBEC:
	ldrb r0, [r4, #7]
	cmp r0, #0
	bne _0805CC2C
	ldr r3, _0805CC20 @ =0x0203B400
	ldr r1, _0805CC24 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0805CC28 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	strb r0, [r4, #6]
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	b _0805CC2E
	.align 2, 0
_0805CC20: .4byte 0x0203B400
_0805CC24: .4byte 0x030046B8
_0805CC28: .4byte 0x000003FF
_0805CC2C:
	subs r0, #1
_0805CC2E:
	strb r0, [r4, #7]
	adds r3, r4, #0
	adds r3, #0x14
	movs r5, #0x1c
	ldrsh r2, [r4, r5]
	movs r1, #0x14
	ldrsh r0, [r4, r1]
	subs r2, r2, r0
	movs r5, #0x20
	ldrsh r0, [r4, r5]
	movs r5, #4
	ldrsh r1, [r3, r5]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r6, r1, r0
	ldrh r1, [r4, #0x16]
	movs r5, #0x16
	ldrsh r0, [r4, r5]
	movs r5, #0x1e
	ldrsh r2, [r4, r5]
	adds r5, r3, #0
	cmp r0, r2
	ble _0805CC68
	subs r0, r1, #1
	b _0805CC6E
_0805CC68:
	cmp r0, r2
	bge _0805CC70
	adds r0, r1, #1
_0805CC6E:
	strh r0, [r4, #0x16]
_0805CC70:
	ldr r0, _0805CC98 @ =0x00000FFF
	cmp r6, r0
	bhi _0805CCE4
	mov r3, sp
	ldrb r6, [r4, #6]
	ldr r2, _0805CC9C @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	cmp r0, #0
	blt _0805CCA0
	asrs r1, r0, #0xc
	b _0805CCA6
	.align 2, 0
_0805CC98: .4byte 0x00000FFF
_0805CC9C: .4byte 0x085B0A08
_0805CCA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805CCA6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #4
	muls r0, r1, r0
	cmp r0, #0
	blt _0805CCC0
	asrs r0, r0, #0xc
	b _0805CCC6
_0805CCC0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805CCC6:
	strh r0, [r3, #4]
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r4, #0x14]
	adds r0, r0, r3
	strh r0, [r4, #0x14]
	ldrh r0, [r1, #2]
	ldrh r2, [r5, #2]
	adds r0, r0, r2
	strh r0, [r5, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r5, #4]
	adds r0, r0, r3
	strh r0, [r5, #4]
_0805CCE4:
	adds r0, r4, #0
	adds r0, #0x7c
	adds r1, r5, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0805bbb0
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
_0805CD00:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805cd08
FUN_0805cd08: @ 0x0805CD08
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	adds r5, r1, #0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0805CD32
	movs r0, #0
	strb r0, [r5]
	adds r2, r5, #0
	adds r2, #0x7c
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, #0x2a
	bl FUN_0822b20c
_0805CD32:
	ldrh r1, [r5, #4]
	movs r0, #0x14
	subs r0, r0, r1
	mov r3, sp
	ldrb r4, [r5, #6]
	lsls r6, r0, #1
	ldr r2, _0805CD5C @ =0x085B0A08
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
	blt _0805CD60
	asrs r1, r0, #0xc
	b _0805CD66
	.align 2, 0
_0805CD5C: .4byte 0x085B0A08
_0805CD60:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805CD66:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805CD7E
	asrs r0, r0, #0xc
	b _0805CD84
_0805CD7E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805CD84:
	strh r0, [r3, #4]
	adds r1, r5, #0
	adds r1, #0x14
	mov r2, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r5, #0x14]
	adds r0, r0, r3
	strh r0, [r5, #0x14]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #1
	bl FUN_0805bbb0
	ldrh r0, [r5, #4]
	cmp r0, #0x13
	bls _0805CDD0
	movs r0, #1
	strb r0, [r5, #1]
	strb r0, [r5]
	movs r0, #0
	strh r0, [r5, #4]
	adds r2, r5, #0
	adds r2, #0xdc
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	b _0805CE1E
_0805CDD0:
	cmp r0, #6
	bne _0805CDE8
	movs r3, #0x84
	lsls r3, r3, #1
	adds r4, r5, r3
	adds r0, r4, #0
	ldr r1, _0805CE04 @ =0x00000263
	bl FUN_0822b20c
	ldr r1, _0805CE08 @ =0x00001688
	adds r0, r7, r1
	str r0, [r4, #0xc]
_0805CDE8:
	ldrh r0, [r5, #4]
	lsrs r0, r0, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0805CE0C
	adds r0, r5, #0
	adds r0, #0xdc
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _0805CE16
	.align 2, 0
_0805CE04: .4byte 0x00000263
_0805CE08: .4byte 0x00001688
_0805CE0C:
	adds r0, r5, #0
	adds r0, #0xdc
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_0805CE16:
	str r1, [r0]
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
_0805CE1E:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805ce28
FUN_0805ce28: @ 0x0805CE28
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	mov r8, r0
	adds r7, r1, #0
	ldrb r0, [r7]
	cmp r0, #0
	bne _0805CE3C
	b _0805CF40
_0805CE3C:
	movs r0, #0
	strb r0, [r7]
	adds r2, r7, #0
	adds r2, #0x7c
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r4, _0805CE90 @ =0x0203B400
	ldr r3, _0805CE94 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _0805CE98 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r6, #0xff
	ldrb r5, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r0, #0x3f
	ands r1, r0
	mov r4, sp
	adds r2, r1, #0
	adds r2, #0x10
	ldr r1, _0805CE9C @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	ands r0, r6
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r2, r0
	cmp r0, #0
	blt _0805CEA0
	asrs r3, r0, #0xc
	b _0805CEA6
	.align 2, 0
_0805CE90: .4byte 0x0203B400
_0805CE94: .4byte 0x030046B8
_0805CE98: .4byte 0x000003FF
_0805CE9C: .4byte 0x085B0A08
_0805CEA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805CEA6:
	movs r0, #0
	strh r3, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r2, r0
	cmp r0, #0
	blt _0805CEBE
	asrs r0, r0, #0xc
	b _0805CEC4
_0805CEBE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805CEC4:
	strh r0, [r4, #4]
	adds r2, r7, #0
	adds r2, #0x1c
	mov r3, r8
	adds r3, #0x38
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	mov r4, r8
	ldrh r4, [r4, #0x38]
	adds r0, r0, r4
	strh r0, [r7, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r5, [r3, #2]
	adds r0, r0, r5
	strh r0, [r2, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	movs r1, #0x1c
	ldrsh r0, [r7, r1]
	movs r3, #0x14
	ldrsh r1, [r7, r3]
	subs r0, r0, r1
	movs r4, #4
	ldrsh r1, [r2, r4]
	movs r5, #0x18
	ldrsh r2, [r7, r5]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r7, #6]
	ldr r4, _0805CF58 @ =0x0203B400
	ldr r2, _0805CF5C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _0805CF60 @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	subs r0, #8
	ldrb r1, [r7, #6]
	adds r0, r0, r1
	strb r0, [r7, #6]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #8
	strb r0, [r7, #7]
	movs r0, #0x10
	strh r0, [r7, #0x10]
_0805CF40:
	mov r2, r8
	ldrb r0, [r2, #0x1c]
	cmp r0, #0
	beq _0805CF64
	movs r0, #5
	movs r1, #0
	strb r0, [r7, #1]
	movs r0, #1
	strb r0, [r7]
	strh r1, [r7, #4]
	b _0805D092
	.align 2, 0
_0805CF58: .4byte 0x0203B400
_0805CF5C: .4byte 0x030046B8
_0805CF60: .4byte 0x000003FF
_0805CF64:
	ldrb r0, [r7, #7]
	cmp r0, #0
	bne _0805CFCC
	adds r5, r7, #0
	adds r5, #0x14
	movs r3, #0x1c
	ldrsh r0, [r7, r3]
	movs r4, #0x14
	ldrsh r1, [r7, r4]
	subs r0, r0, r1
	movs r2, #0x20
	ldrsh r1, [r7, r2]
	movs r3, #4
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r7, #6]
	ldr r4, _0805CFC0 @ =0x0203B400
	ldr r2, _0805CFC4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _0805CFC8 @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	subs r0, #1
	ldrb r1, [r7, #6]
	adds r0, r0, r1
	strb r0, [r7, #6]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #8
	strb r0, [r7, #7]
	b _0805CFD4
	.align 2, 0
_0805CFC0: .4byte 0x0203B400
_0805CFC4: .4byte 0x030046B8
_0805CFC8: .4byte 0x000003FF
_0805CFCC:
	subs r0, #1
	strb r0, [r7, #7]
	adds r5, r7, #0
	adds r5, #0x14
_0805CFD4:
	mov r4, sp
	ldrb r6, [r7, #6]
	ldrh r2, [r7, #0x10]
	mov ip, r2
	ldr r2, _0805D000 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	adds r1, r2, #0
	cmp r0, #0
	blt _0805D004
	asrs r3, r0, #0xc
	b _0805D00A
	.align 2, 0
_0805D000: .4byte 0x085B0A08
_0805D004:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805D00A:
	movs r0, #0
	strh r3, [r4]
	strh r0, [r4, #2]
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r3, ip
	muls r3, r0, r3
	adds r0, r3, #0
	cmp r0, #0
	blt _0805D026
	asrs r0, r0, #0xc
	b _0805D02C
_0805D026:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805D02C:
	strh r0, [r4, #4]
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r4, [r7, #0x14]
	adds r0, r0, r4
	strh r0, [r7, #0x14]
	ldrh r0, [r1, #2]
	ldrh r2, [r5, #2]
	adds r0, r0, r2
	strh r0, [r5, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r5, #4]
	adds r0, r0, r3
	strh r0, [r5, #4]
	mov r0, r8
	adds r1, r7, #0
	movs r2, #0
	bl FUN_0805bbb0
	mov r4, r8
	movs r0, #0x38
	ldrsh r2, [r4, r0]
	movs r1, #0x14
	ldrsh r0, [r7, r1]
	subs r2, r2, r0
	movs r3, #0x3c
	ldrsh r0, [r4, r3]
	movs r4, #4
	ldrsh r1, [r5, r4]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r5, r0, #0
	muls r5, r0, r5
	adds r0, r5, #0
	adds r1, r1, r0
	ldr r0, _0805D088 @ =0x00003FFF
	cmp r1, r0
	bgt _0805D08C
	movs r0, #0xa
	strb r0, [r7, #1]
	movs r0, #1
	strb r0, [r7]
	movs r0, #0
	b _0805D090
	.align 2, 0
_0805D088: .4byte 0x00003FFF
_0805D08C:
	ldrh r0, [r7, #4]
	adds r0, #1
_0805D090:
	strh r0, [r7, #4]
_0805D092:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805d0a0
FUN_0805d0a0: @ 0x0805D0A0
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805D0BC
	movs r0, #0
	strb r0, [r4]
	adds r2, r4, #0
	adds r2, #0x7c
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
_0805D0BC:
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0805bbb0
	ldrb r1, [r5, #0x1d]
	cmp r1, #0
	beq _0805D0D2
	movs r0, #0xb
	movs r1, #0
	b _0805D0DA
_0805D0D2:
	ldrb r0, [r5, #0x1c]
	cmp r0, #0
	beq _0805D0E4
	movs r0, #5
_0805D0DA:
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	strh r1, [r4, #4]
	b _0805D0EA
_0805D0E4:
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
_0805D0EA:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805d0f0
FUN_0805d0f0: @ 0x0805D0F0
	push {r4, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805D10C
	movs r0, #0
	strb r0, [r4]
	adds r2, r4, #0
	adds r2, #0x7c
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
_0805D10C:
	adds r0, r3, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0805bbb0
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805d124
FUN_0805d124: @ 0x0805D124
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, [r5, #0x18]
	cmp r0, #0
	bne _0805D138
	b _0805D288
_0805D138:
	bl FUN_08084710
	strb r0, [r5, #0x1c]
	adds r0, r5, #0
	adds r0, #0x30
	bl FUN_08084734
	ldr r1, [r5, #0x24]
	ldr r0, _0805D188 @ =0x00000257
	cmp r1, r0
	bls _0805D166
	ldrb r0, [r5, #0x1e]
	cmp r0, #0
	bne _0805D15E
	movs r0, #1
	strb r0, [r5, #0x1e]
	movs r0, #0xea
	bl PlaySound_082406e0
_0805D15E:
	ldr r0, _0805D18C @ =0x00001684
	adds r1, r5, r0
	movs r0, #2
	strb r0, [r1]
_0805D166:
	ldr r1, _0805D18C @ =0x00001684
	adds r2, r5, r1
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	bne _0805D194
	ldr r3, _0805D190 @ =0x00001685
	adds r1, r5, r3
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x3e
	ble _0805D1CE
	movs r0, #0x3f
	b _0805D1C8
	.align 2, 0
_0805D188: .4byte 0x00000257
_0805D18C: .4byte 0x00001684
_0805D190: .4byte 0x00001685
_0805D194:
	cmp r0, #1
	bne _0805D1B0
	ldr r4, _0805D1AC @ =0x00001685
	adds r1, r5, r4
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bgt _0805D1CE
	movs r0, #0
	b _0805D1C8
	.align 2, 0
_0805D1AC: .4byte 0x00001685
_0805D1B0:
	cmp r0, #2
	bne _0805D1CE
	ldr r0, _0805D20C @ =0x00001685
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1f
	ble _0805D1CE
	movs r0, #0x20
_0805D1C8:
	strb r0, [r1]
	movs r0, #0xff
	strb r0, [r2]
_0805D1CE:
	ldr r1, _0805D210 @ =0x00001684
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0805D1FE
	ldr r0, _0805D214 @ =0x03003584
	ldr r2, [r0]
	ldr r3, _0805D218 @ =0x00004C60
	adds r1, r2, r3
	ldr r4, _0805D21C @ =0x00004CA0
	adds r2, r2, r4
	ldr r3, _0805D220 @ =0x00001688
	adds r0, r5, r3
	ldr r4, _0805D20C @ =0x00001685
	adds r3, r5, r4
	ldrb r3, [r3]
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	movs r4, #6
	str r4, [sp]
	bl rgb555_08237468
_0805D1FE:
	ldrb r0, [r5, #0x1d]
	cmp r0, #0
	beq _0805D224
	adds r0, r5, #0
	bl FUN_0805bb7c
	b _0805D288
	.align 2, 0
_0805D20C: .4byte 0x00001685
_0805D210: .4byte 0x00001684
_0805D214: .4byte 0x03003584
_0805D218: .4byte 0x00004C60
_0805D21C: .4byte 0x00004CA0
_0805D220: .4byte 0x00001688
_0805D224:
	movs r7, #0
	movs r0, #0
	mov r8, r0
	adds r4, r5, #0
	adds r4, #0x44
	movs r6, #0
	ldr r1, _0805D298 @ =0x085ABA2C
	mov sb, r1
_0805D234:
	ldrb r0, [r4, #1]
	lsls r0, r0, #2
	add r0, sb
	ldr r3, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl _call_via_r3
	adds r0, r4, #0
	bl FUN_0805bc0c
	ldrb r0, [r4, #1]
	cmp r0, #7
	bne _0805D254
	adds r7, #1
_0805D254:
	cmp r0, #0xa
	bne _0805D25C
	movs r3, #1
	add r8, r3
_0805D25C:
	adds r6, #1
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r4, r4, r0
	cmp r6, #0xf
	ble _0805D234
	ldr r1, [r5, #0x24]
	cmp r7, #0x10
	beq _0805D27A
	mov r3, r8
	cmp r3, #0x10
	beq _0805D27A
	ldr r0, _0805D29C @ =0x000004AF
	cmp r1, r0
	bls _0805D284
_0805D27A:
	ldrb r0, [r5, #0x1d]
	cmp r0, #0
	bne _0805D284
	movs r0, #1
	strb r0, [r5, #0x1d]
_0805D284:
	adds r0, r1, #1
	str r0, [r5, #0x24]
_0805D288:
	movs r0, #0
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805D298: .4byte 0x085ABA2C
_0805D29C: .4byte 0x000004AF

	thumb_func_start FUN_0805d2a0
FUN_0805d2a0: @ 0x0805D2A0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x44
	movs r4, #0
_0805D2AA:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805bb30
	adds r4, #1
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r5, r5, r0
	cmp r4, #0xf
	ble _0805D2AA
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805d2c8
FUN_0805d2c8: @ 0x0805D2C8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r2, #0
	movs r3, #0
	movs r0, #0xa
	strh r0, [r6, #0x20]
	movs r0, #0x64
	strh r0, [r6, #0x22]
	strb r2, [r6, #0x1d]
	str r3, [r6, #0x18]
	strb r1, [r6, #0x1f]
	ldr r0, _0805D348 @ =0x0000922E
	ldr r1, _0805D34C @ =0x00005BB7
	bl GetFile
	str r0, [r6, #0x40]
	ldr r0, _0805D350 @ =0x03003584
	ldr r2, [r0]
	ldr r0, _0805D354 @ =0x00004C60
	adds r1, r2, r0
	ldr r3, _0805D358 @ =0x00004CA0
	adds r2, r2, r3
	ldr r3, _0805D35C @ =0x00001688
	adds r0, r6, r3
	movs r3, #6
	str r3, [sp]
	movs r3, #0x40
	bl rgb555_08237468
	adds r4, r6, #0
	adds r4, #0x44
	movs r5, #0
_0805D30A:
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_0805b9b4
	adds r5, #1
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r4, r4, r0
	cmp r5, #0xf
	ble _0805D30A
	movs r5, #0
	ldrb r3, [r6, #0x1f]
	cmp r5, r3
	bge _0805D33C
	adds r1, r6, #0
	adds r1, #0x28
	ldr r2, _0805D360 @ =0x03002BE0
_0805D32E:
	ldm r2!, {r0}
	adds r0, #0x2c
	stm r1!, {r0}
	adds r5, #1
	ldrb r0, [r6, #0x1f]
	cmp r5, r0
	blt _0805D32E
_0805D33C:
	movs r0, #0
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805D348: .4byte 0x0000922E
_0805D34C: .4byte 0x00005BB7
_0805D350: .4byte 0x03003584
_0805D354: .4byte 0x00004C60
_0805D358: .4byte 0x00004CA0
_0805D35C: .4byte 0x00001688
_0805D360: .4byte 0x03002BE0

	thumb_func_start FUN_0805d364
FUN_0805d364: @ 0x0805D364
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _0805D394 @ =0x000016A8
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805D3A0
	ldr r1, _0805D398 @ =FUN_0805d124
	ldr r2, _0805D39C @ =FUN_0805d2a0
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0805d2c8
	cmp r0, #0
	bge _0805D3A0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805D3A2
	.align 2, 0
_0805D394: .4byte 0x000016A8
_0805D398: .4byte FUN_0805d124
_0805D39C: .4byte FUN_0805d2a0
_0805D3A0:
	adds r0, r4, #0
_0805D3A2:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805d3a8
FUN_0805d3a8: @ 0x0805D3A8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	str r1, [sp, #4]
	adds r4, r2, #0
	str r3, [sp, #8]
	movs r0, #0
	strb r0, [r6, #0x1c]
	strb r0, [r6, #0x1d]
	strb r0, [r6, #0x1e]
	str r0, [r6, #0x24]
	ldr r0, _0805D45C @ =0x00001684
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _0805D460 @ =0x00001685
	adds r1, r6, r2
	movs r0, #0x3f
	strb r0, [r1]
	ldr r0, _0805D464 @ =0x03003584
	ldr r2, [r0]
	ldr r3, _0805D468 @ =0x00004C60
	adds r1, r2, r3
	ldr r0, _0805D46C @ =0x00004CA0
	adds r2, r2, r0
	ldr r3, _0805D470 @ =0x00001688
	adds r0, r6, r3
	movs r3, #6
	str r3, [sp]
	movs r3, #0x3f
	bl rgb555_08237468
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r6, #0x38]
	str r1, [r6, #0x3c]
	adds r5, r6, #0
	adds r5, #0x44
	movs r0, #0
	str r0, [sp, #0xc]
	mov sl, r0
	ldr r1, _0805D474 @ =0x030046B8
	mov r8, r1
	adds r7, r6, #0
	adds r7, #0xc0
_0805D40A:
	mov r2, sl
	strb r2, [r5, #1]
	movs r3, #1
	strb r3, [r5]
	mov r0, sl
	strh r0, [r5, #4]
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _0805D478 @ =0x000003FF
	ands r0, r1
	mov r2, r8
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0805D47C @ =0x0203B400
	adds r0, r0, r3
	ldrh r1, [r0]
	ldr r0, [sp, #0xc]
	lsls r2, r0, #5
	movs r0, #0x1f
	ands r1, r0
	adds r2, r2, r1
	strb r2, [r5, #6]
	mov r1, sp
	ldrh r1, [r1, #8]
	strh r1, [r5, #0x10]
	mov r2, sp
	ldrh r2, [r2, #0x30]
	strh r2, [r5, #0x12]
	ldrb r0, [r6, #0x1f]
	movs r3, #0xdc
	adds r3, r3, r5
	mov sb, r3
	cmp r0, #2
	bne _0805D486
	ldr r0, [sp, #0xc]
	cmp r0, #7
	bgt _0805D480
	movs r1, #1
	strb r1, [r5, #8]
	b _0805D494
	.align 2, 0
_0805D45C: .4byte 0x00001684
_0805D460: .4byte 0x00001685
_0805D464: .4byte 0x03003584
_0805D468: .4byte 0x00004C60
_0805D46C: .4byte 0x00004CA0
_0805D470: .4byte 0x00001688
_0805D474: .4byte 0x030046B8
_0805D478: .4byte 0x000003FF
_0805D47C: .4byte 0x0203B400
_0805D480:
	mov r2, sl
	strb r2, [r5, #8]
	b _0805D494
_0805D486:
	cmp r0, #0
	bne _0805D490
	mov r3, sl
	strb r3, [r5, #8]
	b _0805D494
_0805D490:
	movs r0, #0xff
	strb r0, [r5, #8]
_0805D494:
	mov r0, sl
	strb r0, [r5, #9]
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _0805D4D8 @ =0x000003FF
	ands r0, r1
	mov r2, r8
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0805D4DC @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r4, r0, #0
	adds r4, #0x10
	ldr r2, _0805D4E0 @ =0x085B0A08
	ldrb r3, [r5, #6]
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	mov ip, r3
	cmp r0, #0
	blt _0805D4E4
	asrs r1, r0, #0xc
	b _0805D4EA
	.align 2, 0
_0805D4D8: .4byte 0x000003FF
_0805D4DC: .4byte 0x0203B400
_0805D4E0: .4byte 0x085B0A08
_0805D4E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805D4EA:
	ldr r3, [sp, #4]
	ldrh r0, [r3]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
	ldrh r0, [r3, #2]
	strh r0, [r5, #0x16]
	mov r1, ip
	lsls r0, r1, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _0805D50A
	asrs r2, r0, #0xc
	b _0805D510
_0805D50A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0805D510:
	ldr r3, [sp, #4]
	ldrh r0, [r3, #4]
	adds r0, r0, r2
	strh r0, [r5, #0x18]
	ldrh r0, [r5, #0x16]
	strh r0, [r5, #0xe]
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _0805D5C4 @ =0x000003FF
	ands r0, r1
	mov r2, r8
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0805D5C8 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #7
	strb r0, [r5, #7]
	adds r4, r5, #0
	adds r4, #0x14
	ldr r0, [r5, #0x14]
	ldr r1, [r5, #0x18]
	mov r2, sb
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldr r0, [r7, #0x60]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #0x60]
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0805bbb0
	movs r3, #0x84
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r1, _0805D5CC @ =0x00000263
	bl FUN_0822b20c
	ldr r1, _0805D5D0 @ =0x00001688
	adds r0, r6, r1
	mov r2, sb
	str r0, [r2, #0x38]
	movs r3, #0x92
	lsls r3, r3, #1
	adds r0, r5, r3
	bl FUN_08013698
	adds r0, r5, #0
	adds r0, #0x2c
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	ldrh r0, [r7, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r7, #6]
	ldr r0, [sp, #0xc]
	adds r0, #1
	str r0, [sp, #0xc]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r7, r7, r1
	adds r5, r5, r1
	cmp r0, #0xf
	bgt _0805D5AC
	b _0805D40A
_0805D5AC:
	movs r0, #1
	str r0, [r6, #0x18]
	movs r0, #0
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805D5C4: .4byte 0x000003FF
_0805D5C8: .4byte 0x0203B400
_0805D5CC: .4byte 0x00000263
_0805D5D0: .4byte 0x00001688

	thumb_func_start FUN_0805d5d4
FUN_0805d5d4: @ 0x0805D5D4
	movs r1, #0x96
	lsls r1, r1, #2
	str r1, [r0, #0x24]
	bx lr

	thumb_func_start FUN_0805d5dc
FUN_0805d5dc: @ 0x0805D5DC
	movs r0, #0x3c
	str r0, [r2]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0805d5e4
FUN_0805d5e4: @ 0x0805D5E4
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x20
	adds r4, r0, #0
	adds r6, r1, #0
	movs r0, #0
	mov r8, r0
	stm r1!, {r0}
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	ldr r2, _0805D67C @ =0x05000002
	bl CpuSet
	adds r0, r6, #0
	adds r0, #0xc
	adds r4, #0x1c
	adds r1, r4, #0
	movs r2, #1
	bl FUN_0822a4b0
	adds r5, r6, #0
	adds r5, #0x38
	ldr r2, _0805D680 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r4, #8
	orrs r0, r4
	ldr r1, _0805D684 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	add r3, sp, #0x10
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r4
	str r0, [r3, #4]
	mov r0, r8
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _0805D688 @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	str r3, [sp, #4]
	str r1, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r1, _0805D68C @ =FUN_0805d5dc
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_0823651c
	mov r0, r8
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #0xa
	movs r2, #0x14
	movs r3, #0
	bl FUN_082364f8
	add sp, #0x20
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805D67C: .4byte 0x05000002
_0805D680: .4byte 0xFFFF0000
_0805D684: .4byte 0x0000FFFF
_0805D688: .4byte 0x00002001
_0805D68C: .4byte FUN_0805d5dc

	thumb_func_start FUN_0805d690
FUN_0805d690: @ 0x0805D690
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r0, r1, #0
	adds r5, r2, #0
	ldr r1, [r0, #0xc]
	movs r4, #1
	orrs r1, r4
	str r1, [r0, #0xc]
	adds r0, #0xc
	bl FUN_0822a4e0
	lsls r4, r5
	ldr r0, [r6, #0x18]
	bics r0, r4
	str r0, [r6, #0x18]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805d6b4
FUN_0805d6b4: @ 0x0805D6B4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	mov r6, r8
	adds r6, #0x38
	movs r7, #0
	adds r5, r6, #0
_0805D6C4:
	movs r1, #1
	lsls r1, r7
	mov r2, r8
	ldr r0, [r2, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _0805D716
	adds r4, r6, #0
	adds r4, #0x38
	adds r1, r6, #0
	adds r1, #0x28
	ldrh r0, [r5, #4]
	ldrh r2, [r5, #0x28]
	adds r0, r0, r2
	strh r0, [r5, #0x28]
	ldrh r0, [r5, #6]
	ldrh r2, [r5, #0x2a]
	adds r0, r0, r2
	strh r0, [r5, #0x2a]
	ldrh r0, [r5, #8]
	ldrh r2, [r5, #0x2c]
	adds r0, r0, r2
	strh r0, [r5, #0x2c]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	ldr r0, [r5]
	cmp r0, #0x3b
	bls _0805D712
	mov r0, r8
	adds r1, r6, #0
	adds r2, r7, #0
	bl FUN_0805d690
	b _0805D716
_0805D712:
	adds r0, #1
	str r0, [r5]
_0805D716:
	adds r7, #1
	adds r5, #0x88
	adds r6, #0x88
	cmp r7, #0x1f
	ble _0805D6C4
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805d72c
FUN_0805d72c: @ 0x0805D72C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x38
	movs r4, #0
_0805D736:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _0805D74C
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805d690
_0805D74C:
	adds r4, #1
	adds r5, #0x88
	cmp r4, #0x1f
	ble _0805D736
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805d75c
FUN_0805d75c: @ 0x0805D75C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0
	str r0, [r6, #0x18]
	adds r4, r6, #0
	adds r4, #0x1c
	ldr r1, _0805D798 @ =0x0000848F
	adds r0, r4, #0
	bl FUN_0822b16c
	adds r0, r4, #0
	movs r1, #0xdb
	bl FUN_0822b20c
	adds r5, r6, #0
	adds r5, #0x38
	movs r4, #0
_0805D77E:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805d5e4
	adds r4, #1
	adds r5, #0x88
	cmp r4, #0x1f
	ble _0805D77E
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805D798: .4byte 0x0000848F

	thumb_func_start FUN_0805d79c
FUN_0805d79c: @ 0x0805D79C
	push {r4, lr}
	ldr r1, _0805D7C8 @ =0x00001138
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805D7D4
	ldr r1, _0805D7CC @ =FUN_0805d6b4
	ldr r2, _0805D7D0 @ =FUN_0805d72c
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0805d75c
	cmp r0, #0
	bge _0805D7D4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805D7D6
	.align 2, 0
_0805D7C8: .4byte 0x00001138
_0805D7CC: .4byte FUN_0805d6b4
_0805D7D0: .4byte FUN_0805d72c
_0805D7D4:
	adds r0, r4, #0
_0805D7D6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805d7dc
FUN_0805d7dc: @ 0x0805D7DC
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r3, #0x38
	movs r2, #0
	movs r5, #1
	ldr r4, [r0, #0x18]
_0805D7E8:
	adds r0, r5, #0
	lsls r0, r2
	ands r0, r4
	cmp r0, #0
	bne _0805D7F8
	str r2, [r1]
	adds r0, r3, #0
	b _0805D804
_0805D7F8:
	adds r2, #1
	adds r3, #0x88
	cmp r2, #0x1f
	ble _0805D7E8
	movs r0, #0
	str r0, [r1]
_0805D804:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805d80c
FUN_0805d80c: @ 0x0805D80C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	mov sb, r1
	adds r5, r2, #0
	adds r7, r3, #0
	adds r6, r0, #0
	add r1, sp, #8
	bl FUN_0805d7dc
	adds r3, r0, #0
	cmp r3, #0
	bne _0805D830
	movs r0, #1
	rsbs r0, r0, #0
	b _0805D90A
_0805D830:
	movs r0, #0x38
	adds r0, r0, r3
	mov r8, r0
	movs r0, #0
	adds r4, r3, #0
	stm r4!, {r0}
	ldr r2, _0805D858 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0805D85C
	asrs r1, r0, #0xc
	b _0805D862
	.align 2, 0
_0805D858: .4byte 0x085B0A08
_0805D85C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805D862:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _0805D87E
	asrs r0, r0, #0xc
	b _0805D884
_0805D87E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805D884:
	strh r0, [r4, #4]
	ldr r2, [sp, #0x28]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3, #0x28]
	str r1, [r3, #0x2c]
	adds r0, r5, #0
	adds r0, #0x60
	movs r1, #0xff
	ands r0, r1
	lsrs r2, r0, #4
	cmp r2, #8
	bls _0805D8AA
	movs r0, #0x10
	subs r0, r0, r2
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	movs r4, #1
	b _0805D8AC
_0805D8AA:
	movs r4, #0
_0805D8AC:
	adds r1, r3, #0
	adds r1, #0xc
	adds r0, r2, #4
	strh r0, [r1, #0x10]
	adds r2, r1, #0
	cmp r4, #0
	beq _0805D8C2
	ldr r0, [r3, #0xc]
	movs r1, #4
	orrs r0, r1
	b _0805D8CA
_0805D8C2:
	ldr r0, [r3, #0xc]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0805D8CA:
	str r0, [r3, #0xc]
	ldr r0, [r3, #0xc]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3, #0xc]
	adds r0, r2, #0
	movs r1, #0
	bl FUN_0822a340
	movs r0, #0
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	mov r0, r8
	mov r1, sb
	movs r2, #0x14
	movs r3, #0
	bl FUN_082364f8
	mov r0, r8
	ldr r1, [sp, #0x28]
	movs r2, #0
	bl FUN_082364c4
	ldr r0, [sp, #8]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r6, #0x18]
	orrs r0, r1
	str r0, [r6, #0x18]
	movs r0, #0
_0805D90A:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805d918
FUN_0805d918: @ 0x0805D918
	bx lr
	.align 2, 0

	thumb_func_start FUN_0805d91c
FUN_0805d91c: @ 0x0805D91C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x2c
	adds r4, r0, #0
	adds r6, r1, #0
	movs r0, #0
	mov r8, r0
	str r0, [r6, #4]
	add r5, sp, #0x14
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _0805D9C8 @ =0x05000002
	bl CpuSet
	adds r0, r6, #0
	adds r0, #0xc
	adds r4, #0x1c
	movs r1, #2
	str r1, [sp]
	mov r1, r8
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	str r5, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #1
	bl FUN_0822f4d8
	adds r5, r6, #0
	adds r5, #0x6c
	ldr r2, _0805D9CC @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	movs r4, #0x60
	orrs r0, r4
	ldr r1, _0805D9D0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r3, sp, #0x1c
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r4
	str r0, [r3, #4]
	str r1, [sp, #0x24]
	add r1, sp, #0x24
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _0805D9D4 @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	str r3, [sp, #4]
	str r1, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r1, _0805D9D8 @ =FUN_0805d918
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_0823651c
	mov r0, r8
	str r0, [sp]
	movs r0, #0x40
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x32
	movs r2, #0x40
	movs r3, #0
	bl FUN_082364f8
	add sp, #0x2c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805D9C8: .4byte 0x05000002
_0805D9CC: .4byte 0xFFFF0000
_0805D9D0: .4byte 0x0000FFFF
_0805D9D4: .4byte 0x00002001
_0805D9D8: .4byte FUN_0805d918

	thumb_func_start FUN_0805d9dc
FUN_0805d9dc: @ 0x0805D9DC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r0, r1, #0
	adds r5, r2, #0
	ldr r1, [r0, #0x14]
	movs r4, #1
	orrs r1, r4
	str r1, [r0, #0x14]
	adds r0, #0xc
	bl FUN_0822f1c0
	lsls r4, r5
	ldr r0, [r6, #0x18]
	bics r0, r4
	str r0, [r6, #0x18]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805da00
FUN_0805da00: @ 0x0805DA00
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	adds r2, r1, #0
	ldr r0, [r2, #4]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0805DAC0
	adds r6, r2, #0
	adds r6, #0xc
	ldr r4, _0805DA5C @ =0x0203B400
	ldr r3, _0805DA60 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _0805DA64 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	ldrh r5, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r1, r0
	mov r3, sp
	adds r4, r1, #0
	adds r4, #0x10
	ldr r2, _0805DA68 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0805DA6C
	asrs r1, r0, #0xc
	b _0805DA72
	.align 2, 0
_0805DA5C: .4byte 0x0203B400
_0805DA60: .4byte 0x030046B8
_0805DA64: .4byte 0x000003FF
_0805DA68: .4byte 0x085B0A08
_0805DA6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805DA72:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0805DA8E
	asrs r0, r0, #0xc
	b _0805DA94
_0805DA8E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805DA94:
	strh r0, [r3, #4]
	mov r2, sp
	mov r1, sp
	ldrh r0, [r6, #0x20]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r6, #0x22]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r6, #0x24]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	adds r2, r7, #0
	adds r2, #0x3c
	movs r0, #0
	mov r1, sp
	bl FUN_080155e4
_0805DAC0:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805dac8
FUN_0805dac8: @ 0x0805DAC8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	adds r5, r7, #0
	adds r5, #0x64
	movs r0, #0
	mov r8, r0
	movs r0, #1
	mov sb, r0
_0805DAE0:
	mov r1, sb
	mov r0, r8
	lsls r1, r0
	ldr r0, [r7, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _0805DBEA
	adds r6, r5, #0
	adds r6, #0xc
	adds r2, r5, #0
	adds r2, #0x6c
	ldrb r4, [r5]
	cmp r4, #1
	beq _0805DB4C
	cmp r4, #1
	bgt _0805DB06
	cmp r4, #0
	beq _0805DB10
	b _0805DBDA
_0805DB06:
	cmp r4, #2
	beq _0805DB8A
	cmp r4, #3
	beq _0805DBB6
	b _0805DBDA
_0805DB10:
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_0805da00
	ldr r0, [r5, #4]
	cmp r0, #0x1d
	bls _0805DBDA
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	str r4, [r5, #4]
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	adds r1, #0x1c
	movs r2, #0x2a
	movs r3, #2
	bl FUN_082370cc
	movs r0, #0xbc
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0805DBDA
_0805DB4C:
	ldrh r0, [r6, #0x14]
	cmp r0, #4
	bhi _0805DB5E
	adds r0, r7, #0
	adds r1, r5, #0
	str r2, [sp, #4]
	bl FUN_0805da00
	ldr r2, [sp, #4]
_0805DB5E:
	ldr r0, [r5, #4]
	cmp r0, #0xe
	bls _0805DB6A
	adds r0, r2, #0
	bl FUN_08236400
_0805DB6A:
	ldrb r0, [r6, #0x1d]
	ands r4, r0
	cmp r4, #0
	beq _0805DBDA
	ldrb r0, [r5]
	adds r0, #1
	movs r1, #0
	strb r0, [r5]
	str r1, [r5, #4]
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	adds r1, #0x1c
	movs r2, #0x2b
	b _0805DBAE
_0805DB8A:
	adds r0, r2, #0
	bl FUN_08236400
	ldr r1, [r5, #4]
	ldr r0, [r5, #8]
	cmp r1, r0
	blo _0805DBDA
	ldrb r0, [r5]
	adds r0, #1
	movs r1, #0
	strb r0, [r5]
	str r1, [r5, #4]
	movs r0, #6
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	adds r1, #0x1c
	movs r2, #0x2a
_0805DBAE:
	movs r3, #2
	bl FUN_082370cc
	b _0805DBDA
_0805DBB6:
	ldrh r0, [r6, #0x14]
	cmp r0, #4
	bhi _0805DBC4
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_0805da00
_0805DBC4:
	ldrb r1, [r6, #0x1d]
	mov r0, sb
	ands r0, r1
	cmp r0, #0
	beq _0805DBDA
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, r8
	bl FUN_0805d9dc
	b _0805DBEA
_0805DBDA:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r1, #0x1c
	bl FUN_082372cc
	ldr r0, [r5, #4]
	adds r0, #1
	str r0, [r5, #4]
_0805DBEA:
	movs r0, #1
	add r8, r0
	adds r5, #0xbc
	mov r0, r8
	cmp r0, #7
	bgt _0805DBF8
	b _0805DAE0
_0805DBF8:
	movs r0, #0
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805dc08
FUN_0805dc08: @ 0x0805DC08
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x64
	movs r4, #0
_0805DC12:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _0805DC28
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805d9dc
_0805DC28:
	adds r4, #1
	adds r5, #0xbc
	cmp r4, #7
	ble _0805DC12
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805dc38
FUN_0805dc38: @ 0x0805DC38
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r4, #0
	str r4, [r6, #0x18]
	ldr r0, _0805DC54 @ =0x0000CB05
	ldr r1, _0805DC58 @ =0x0000D3FA
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _0805DC5C
	movs r0, #1
	rsbs r0, r0, #0
	b _0805DCCC
	.align 2, 0
_0805DC54: .4byte 0x0000CB05
_0805DC58: .4byte 0x0000D3FA
_0805DC5C:
	adds r1, r6, #0
	adds r1, #0x1c
	adds r0, r2, #0
	ldm r0!, {r3, r5, r7}
	stm r1!, {r3, r5, r7}
	ldm r0!, {r3, r5, r7}
	stm r1!, {r3, r5, r7}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	adds r0, r6, #0
	adds r0, #0x1c
	adds r1, r2, #0
	bl FUN_0822f284
	adds r0, r6, #0
	adds r0, #0x3c
	movs r1, #7
	strh r1, [r6, #0x3c]
	movs r1, #0xc0
	lsls r1, r1, #6
	strh r1, [r0, #2]
	movs r1, #0x40
	strh r1, [r0, #6]
	strh r4, [r0, #8]
	strh r4, [r0, #0xa]
	movs r1, #3
	strh r1, [r0, #0xc]
	strh r1, [r0, #0xe]
	strh r4, [r0, #0x10]
	strh r4, [r0, #0x12]
	strh r4, [r0, #0x14]
	adds r1, #0xfd
	strh r1, [r0, #0x16]
	movs r1, #0x80
	lsls r1, r1, #2
	strh r1, [r0, #0x18]
	strh r4, [r0, #0x1a]
	strh r4, [r0, #0x1c]
	strh r4, [r0, #0x1e]
	strh r1, [r0, #0x20]
	strh r4, [r0, #0x22]
	strh r4, [r0, #0x24]
	strh r4, [r0, #0x26]
	adds r5, r6, #0
	adds r5, #0x64
	movs r4, #0
_0805DCB8:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805d91c
	adds r4, #1
	adds r5, #0xbc
	cmp r4, #7
	ble _0805DCB8
	movs r0, #0
_0805DCCC:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805dcd4
FUN_0805dcd4: @ 0x0805DCD4
	push {r4, lr}
	ldr r1, _0805DD00 @ =0x00000644
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805DD0C
	ldr r1, _0805DD04 @ =FUN_0805dac8
	ldr r2, _0805DD08 @ =FUN_0805dc08
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0805dc38
	cmp r0, #0
	bge _0805DD0C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805DD0E
	.align 2, 0
_0805DD00: .4byte 0x00000644
_0805DD04: .4byte FUN_0805dac8
_0805DD08: .4byte FUN_0805dc08
_0805DD0C:
	adds r0, r4, #0
_0805DD0E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805dd14
FUN_0805dd14: @ 0x0805DD14
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r3, #0x64
	movs r2, #0
	movs r5, #1
	ldr r4, [r0, #0x18]
_0805DD20:
	adds r0, r5, #0
	lsls r0, r2
	ands r0, r4
	cmp r0, #0
	bne _0805DD30
	str r2, [r1]
	adds r0, r3, #0
	b _0805DD3C
_0805DD30:
	adds r2, #1
	adds r3, #0xbc
	cmp r2, #7
	ble _0805DD20
	movs r0, #0
	str r0, [r1]
_0805DD3C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805dd44
FUN_0805dd44: @ 0x0805DD44
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	mov sl, r1
	adds r5, r2, #0
	mov sb, r3
	add r1, sp, #8
	bl FUN_0805dd14
	adds r6, r0, #0
	cmp r6, #0
	beq _0805DDCA
	adds r4, r6, #0
	adds r4, #0xc
	movs r0, #0x6c
	adds r0, r0, r6
	mov r8, r0
	movs r0, #0
	strb r0, [r6]
	str r0, [r6, #4]
	str r5, [r6, #8]
	adds r1, r7, #0
	adds r1, #0x1c
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0x2a
	movs r3, #2
	bl FUN_082370cc
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #0x2c]
	str r1, [r6, #0x30]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0822a3f0
	movs r0, #0x80
	lsls r0, r0, #0xb
	str r0, [sp]
	movs r0, #0x40
	str r0, [sp, #4]
	mov r0, r8
	mov r1, sl
	movs r2, #0x40
	movs r3, #0
	bl FUN_082364f8
	mov r0, r8
	mov r1, sb
	movs r2, #0
	bl FUN_082364c4
	ldr r0, [sp, #8]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r7, #0x18]
	orrs r0, r1
	str r0, [r7, #0x18]
	movs r0, #0
	b _0805DDCE
_0805DDCA:
	movs r0, #1
	rsbs r0, r0, #0
_0805DDCE:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805dde0
FUN_0805dde0: @ 0x0805DDE0
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r3, #6]
	ands r0, r1
	cmp r0, #0
	beq _0805DDFC
	adds r0, r3, #0
	adds r0, #0x42
	ldrb r0, [r0]
	b _0805DE14
_0805DDFC:
	movs r1, #0x24
	ldrsh r0, [r5, r1]
	movs r2, #0x24
	ldrsh r1, [r3, r2]
	subs r0, r0, r1
	movs r2, #0x28
	ldrsh r1, [r5, r2]
	movs r5, #0x28
	ldrsh r2, [r3, r5]
	subs r1, r1, r2
	bl FUN_0823785c
_0805DE14:
	strb r0, [r4]
	movs r0, #4
	movs r1, #0
	strb r0, [r4, #2]
	movs r0, #1
	strb r0, [r4, #3]
	str r1, [r4, #4]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805de28
FUN_0805de28: @ 0x0805DE28
	bx lr
	.align 2, 0

	thumb_func_start FUN_0805de2c
FUN_0805de2c: @ 0x0805DE2C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov sl, r1
	movs r0, #0
	strb r0, [r1]
	strb r0, [r1, #1]
	strb r0, [r1, #2]
	movs r0, #1
	strb r0, [r1, #3]
	movs r0, #0
	str r0, [r1, #4]
	mov r4, sl
	adds r4, #0xf0
	ldr r1, _0805DF70 @ =0x0000DA6D
	adds r0, r4, #0
	bl FUN_0822b16c
	adds r0, r4, #0
	ldr r1, _0805DF74 @ =0x00000263
	bl FUN_0822b20c
	mov r5, sl
	adds r5, #0xc4
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #1
	bl FUN_0822a470
	movs r0, #2
	strb r0, [r5, #7]
	movs r1, #0xe0
	add r1, sl
	mov sb, r1
	movs r0, #0
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	ldr r2, _0805DF78 @ =0x05000002
	bl CpuSet
	movs r4, #0x86
	lsls r4, r4, #1
	add r4, sl
	adds r0, r4, #0
	mov r1, sb
	movs r2, #0
	bl FUN_0801385c
	adds r0, r4, #0
	bl FUN_080136b4
	mov r7, sl
	adds r7, #0x64
	ldr r2, _0805DF7C @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x20
	mov r8, r1
	orrs r0, r1
	ldr r1, _0805DF80 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x10]
	add r5, sp, #0x10
	ldr r0, [r5, #4]
	ands r0, r2
	mov r1, r8
	orrs r0, r1
	str r0, [r5, #4]
	movs r0, #0xf0
	lsls r0, r0, #0xf
	str r0, [sp, #0x18]
	add r4, sp, #0x18
	ldr r0, [r4, #4]
	ands r0, r2
	str r0, [r4, #4]
	ldr r2, _0805DF84 @ =0x00005005
	movs r6, #0x10
	str r6, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r7, #0
	mov r1, sb
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _0805DF88 @ =FUN_0805dde0
	adds r0, r7, #0
	mov r2, sl
	bl FUN_0823651c
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0x80
	movs r3, #0
	bl FUN_08236514
	adds r0, r7, #0
	bl FUN_08236400
	subs r7, #0x50
	mov r0, r8
	strh r0, [r5]
	movs r0, #0xf0
	strh r0, [r5, #2]
	mov r1, r8
	strh r1, [r5, #4]
	movs r0, #0
	strh r0, [r4]
	movs r0, #0x78
	strh r0, [r4, #2]
	movs r1, #0
	strh r1, [r4, #4]
	ldr r2, _0805DF8C @ =0x00002001
	str r6, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r7, #0
	mov r1, sb
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _0805DF90 @ =FUN_0805de28
	adds r0, r7, #0
	mov r2, sl
	bl FUN_0823651c
	movs r3, #0x80
	lsls r3, r3, #5
	movs r0, #0
	str r0, [sp]
	movs r0, #8
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0xa
	movs r2, #0x1e
	bl FUN_082364f8
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805DF70: .4byte 0x0000DA6D
_0805DF74: .4byte 0x00000263
_0805DF78: .4byte 0x05000002
_0805DF7C: .4byte 0xFFFF0000
_0805DF80: .4byte 0x0000FFFF
_0805DF84: .4byte 0x00005005
_0805DF88: .4byte FUN_0805dde0
_0805DF8C: .4byte 0x00002001
_0805DF90: .4byte FUN_0805de28

	thumb_func_start FUN_0805df94
FUN_0805df94: @ 0x0805DF94
	push {r4, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	adds r0, #0x64
	bl FUN_08236424
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_080138fc
	adds r0, r4, #0
	adds r0, #0xc4
	bl FUN_0822a4e0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805dfb8
FUN_0805dfb8: @ 0x0805DFB8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r3, r1, #0
	adds r6, r2, #0
	adds r1, #0xc4
	ldr r0, [r1]
	movs r4, #1
	orrs r0, r4
	str r0, [r1]
	adds r2, r3, #0
	adds r2, #0x64
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r3, r1
	bl FUN_080136b4
	lsls r4, r6
	ldr r1, [r5, #0x18]
	bics r1, r4
	str r1, [r5, #0x18]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805dff0
FUN_0805dff0: @ 0x0805DFF0
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r5, r1, #0
	ldrb r0, [r5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r1, r0, #1
	movs r0, #3
	ands r1, r0
	add r4, sp, #4
	mov r3, sp
	adds r3, #5
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r7, r3, #0
	cmp r0, #1
	bhi _0805E01E
	movs r0, #1
	b _0805E020
_0805E01E:
	movs r0, #0
_0805E020:
	strb r0, [r4]
	cmp r1, #1
	bls _0805E02A
	movs r0, #1
	b _0805E02C
_0805E02A:
	movs r0, #0
_0805E02C:
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r1, [r6, #0x20]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	add r3, sp, #4
	ldrb r3, [r3]
	ldrb r4, [r7]
	str r4, [sp]
	bl FUN_08236fac
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805e04c
FUN_0805e04c: @ 0x0805E04C
	bx lr
	.align 2, 0

	thumb_func_start FUN_0805e050
FUN_0805e050: @ 0x0805E050
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	adds r6, r4, #0
	adds r6, #0xc4
	ldrb r0, [r4, #3]
	cmp r0, #0
	beq _0805E0D0
	movs r0, #0
	strb r0, [r4, #3]
	adds r2, r4, #0
	adds r2, #0x64
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	adds r0, r3, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0805dff0
	adds r3, r4, #0
	adds r3, #0xc
	ldrb r5, [r4]
	ldrb r7, [r4, #9]
	ldr r2, _0805E0A0 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0805E0A4
	asrs r1, r0, #0xc
	b _0805E0AA
	.align 2, 0
_0805E0A0: .4byte 0x085B0A08
_0805E0A4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805E0AA:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _0805E0C4 @ =0x085B0A08
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _0805E0C8
	asrs r0, r0, #0xc
	b _0805E0CE
	.align 2, 0
_0805E0C4: .4byte 0x085B0A08
_0805E0C8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805E0CE:
	strh r0, [r3, #4]
_0805E0D0:
	adds r1, r6, #0
	adds r1, #0x1c
	adds r2, r4, #0
	adds r2, #0xc
	ldrh r0, [r4, #0xc]
	ldrh r3, [r6, #0x1c]
	adds r0, r0, r3
	strh r0, [r6, #0x1c]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	ldr r0, [r4, #4]
	ldrb r3, [r4, #8]
	cmp r0, r3
	blo _0805E104
	movs r0, #2
	strb r0, [r4, #2]
	movs r0, #1
	strb r0, [r4, #3]
	movs r0, #0
	b _0805E106
_0805E104:
	adds r0, #1
_0805E106:
	str r0, [r4, #4]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805e110
FUN_0805e110: @ 0x0805E110
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	movs r0, #0xc4
	adds r0, r0, r4
	mov r8, r0
	ldrb r0, [r4, #3]
	cmp r0, #0
	beq _0805E142
	movs r0, #0
	strb r0, [r4, #3]
	adds r2, r4, #0
	adds r2, #0x64
	subs r0, #5
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0805dff0
_0805E142:
	ldr r0, [r4, #4]
	movs r1, #0xf
	ands r0, r1
	ands r5, r1
	adds r6, r4, #0
	adds r6, #0xe0
	cmp r0, r5
	bne _0805E17C
	ldr r1, _0805E1DC @ =0x00001508
	adds r2, r7, r1
	movs r3, #0
	ldrsh r0, [r2, r3]
	mov r5, r8
	movs r3, #0x1c
	ldrsh r1, [r5, r3]
	subs r0, r0, r1
	movs r5, #4
	ldrsh r1, [r2, r5]
	movs r3, #4
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r4]
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0805dff0
_0805E17C:
	adds r0, r4, #0
	adds r0, #0x64
	adds r1, r6, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r0, [r4, #4]
	ldrb r5, [r4, #0xa]
	cmp r0, r5
	blo _0805E1EC
	ldr r0, _0805E1DC @ =0x00001508
	adds r2, r7, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	mov r3, r8
	movs r5, #0x1c
	ldrsh r1, [r3, r5]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r5, #4
	ldrsh r2, [r6, r5]
	subs r1, r1, r2
	bl FUN_0823785c
	ldr r3, _0805E1E0 @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r2, _0805E1E4 @ =0x000003FF
	ands r1, r2
	str r1, [r3]
	lsls r1, r1, #1
	ldr r2, _0805E1E8 @ =0x0203B400
	adds r1, r1, r2
	ldrh r1, [r1]
	movs r2, #0xf
	ands r1, r2
	adds r0, r0, r1
	subs r0, #8
	movs r1, #0
	strb r0, [r4]
	movs r0, #3
	strb r0, [r4, #2]
	movs r0, #1
	strb r0, [r4, #3]
	str r1, [r4, #4]
	b _0805E1F0
	.align 2, 0
_0805E1DC: .4byte 0x00001508
_0805E1E0: .4byte 0x030046B8
_0805E1E4: .4byte 0x000003FF
_0805E1E8: .4byte 0x0203B400
_0805E1EC:
	adds r0, #1
	str r0, [r4, #4]
_0805E1F0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805e1fc
FUN_0805e1fc: @ 0x0805E1FC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	adds r5, r1, #0
	mov sb, r2
	adds r7, r5, #0
	adds r7, #0xc4
	ldrb r0, [r5, #3]
	cmp r0, #0
	beq _0805E284
	movs r0, #0
	strb r0, [r5, #3]
	adds r2, r5, #0
	adds r2, #0x64
	subs r0, #5
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
	mov r0, r8
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0805dff0
	adds r3, r5, #0
	adds r3, #0xc
	ldrb r4, [r5]
	ldrb r6, [r5, #1]
	ldr r2, _0805E254 @ =0x085B0A08
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
	blt _0805E258
	asrs r1, r0, #0xc
	b _0805E25E
	.align 2, 0
_0805E254: .4byte 0x085B0A08
_0805E258:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805E25E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _0805E278 @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805E27C
	asrs r0, r0, #0xc
	b _0805E282
	.align 2, 0
_0805E278: .4byte 0x085B0A08
_0805E27C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805E282:
	strh r0, [r3, #4]
_0805E284:
	adds r6, r7, #0
	adds r6, #0x1c
	adds r1, r5, #0
	adds r1, #0xc
	ldrh r0, [r5, #0xc]
	ldrh r2, [r7, #0x1c]
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r2, [r6, #2]
	adds r0, r0, r2
	strh r0, [r6, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r6, #4]
	adds r0, r0, r1
	strh r0, [r6, #4]
	adds r0, r5, #0
	adds r0, #0x64
	adds r1, r6, #0
	movs r2, #0
	bl FUN_082364c4
	movs r0, #1
	mov r2, sb
	ands r0, r2
	ldr r1, _0805E2E8 @ =0x000014E7
	add r1, r8
	ldrb r1, [r1]
	cmp r0, r1
	bne _0805E2D4
	adds r4, r5, #0
	adds r4, #0x14
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
_0805E2D4:
	ldr r0, [r5, #4]
	cmp r0, #0x77
	bls _0805E2EC
	mov r0, r8
	adds r1, r5, #0
	mov r2, sb
	bl FUN_0805dfb8
	b _0805E2F0
	.align 2, 0
_0805E2E8: .4byte 0x000014E7
_0805E2EC:
	adds r0, #1
	str r0, [r5, #4]
_0805E2F0:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805e2fc
FUN_0805e2fc: @ 0x0805E2FC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	adds r4, r1, #0
	mov sb, r2
	adds r7, r4, #0
	adds r7, #0xc4
	ldrb r0, [r4, #3]
	cmp r0, #0
	beq _0805E344
	movs r0, #0
	strb r0, [r4, #3]
	adds r2, r4, #0
	adds r2, #0x64
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	adds r0, r4, #0
	adds r0, #0xf0
	movs r1, #0x99
	lsls r1, r1, #1
	bl FUN_0822b20c
	mov r0, r8
	adds r1, r4, #0
	movs r2, #1
	bl FUN_0805dff0
	bl FUN_0821bd3c
	movs r0, #0xe8
	bl PlaySound_082406e0
_0805E344:
	ldr r1, [r4, #4]
	movs r0, #0x14
	subs r0, r0, r1
	adds r3, r4, #0
	adds r3, #0xc
	ldrb r5, [r4]
	lsls r6, r0, #1
	ldr r2, _0805E370 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	mov ip, r3
	cmp r0, #0
	blt _0805E374
	asrs r1, r0, #0xc
	b _0805E37A
	.align 2, 0
_0805E370: .4byte 0x085B0A08
_0805E374:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805E37A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805E392
	asrs r0, r0, #0xc
	b _0805E398
_0805E392:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805E398:
	strh r0, [r3, #4]
	adds r1, r7, #0
	adds r1, #0x1c
	ldrh r0, [r4, #0xc]
	ldrh r2, [r7, #0x1c]
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	mov r2, ip
	ldrh r0, [r2, #2]
	ldrh r2, [r1, #2]
	adds r0, r0, r2
	strh r0, [r1, #2]
	mov r2, ip
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	ldr r0, [r4, #4]
	cmp r0, #0x13
	bls _0805E3CC
	mov r0, r8
	adds r1, r4, #0
	mov r2, sb
	bl FUN_0805dfb8
	b _0805E408
_0805E3CC:
	cmp r0, #6
	bne _0805E3DA
	adds r0, r4, #0
	adds r0, #0xf0
	ldr r1, _0805E3F4 @ =0x00000263
	bl FUN_0822b20c
_0805E3DA:
	ldr r0, [r4, #4]
	lsrs r0, r0, #2
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	beq _0805E3F8
	adds r0, r4, #0
	adds r0, #0xc4
	ldr r1, [r0]
	subs r2, #3
	ands r1, r2
	str r1, [r0]
	b _0805E402
	.align 2, 0
_0805E3F4: .4byte 0x00000263
_0805E3F8:
	adds r1, r4, #0
	adds r1, #0xc4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0805E402:
	ldr r0, [r4, #4]
	adds r0, #1
	str r0, [r4, #4]
_0805E408:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805e414
FUN_0805e414: @ 0x0805E414
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, [r7, #0x18]
	cmp r0, #0
	bne _0805E42A
	b _0805E602
_0805E42A:
	ldr r0, _0805E48C @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _0805E43E
	ldr r1, _0805E490 @ =0x00001508
	adds r2, r7, r1
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
_0805E43E:
	ldr r2, _0805E494 @ =0x000014E4
	adds r6, r7, r2
	ldrb r0, [r6]
	cmp r0, #0
	beq _0805E4C4
	ldr r0, _0805E498 @ =0x03003584
	ldr r2, [r0]
	ldr r3, _0805E49C @ =0x00004C60
	adds r1, r2, r3
	ldr r4, _0805E4A0 @ =0x00004CE0
	adds r2, r2, r4
	ldr r3, _0805E4A4 @ =0x000014E8
	adds r0, r7, r3
	ldr r4, _0805E4A8 @ =0x000014E5
	adds r5, r7, r4
	movs r3, #0
	ldrsb r3, [r5, r3]
	movs r4, #5
	str r4, [sp]
	bl rgb555_08237468
	ldr r0, _0805E4AC @ =0x000014E6
	adds r2, r7, r0
	ldrb r0, [r2]
	cmp r0, #0
	bne _0805E4B0
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1e
	ble _0805E4C4
	movs r0, #0x1f
	strb r0, [r5]
	movs r0, #1
	strb r0, [r2]
	b _0805E4C4
	.align 2, 0
_0805E48C: .4byte 0x03002BE0
_0805E490: .4byte 0x00001508
_0805E494: .4byte 0x000014E4
_0805E498: .4byte 0x03003584
_0805E49C: .4byte 0x00004C60
_0805E4A0: .4byte 0x00004CE0
_0805E4A4: .4byte 0x000014E8
_0805E4A8: .4byte 0x000014E5
_0805E4AC: .4byte 0x000014E6
_0805E4B0:
	ldrb r0, [r5]
	subs r0, #1
	movs r1, #0
	strb r0, [r5]
	lsls r0, r0, #0x18
	cmp r0, #0
	bgt _0805E4C4
	strb r1, [r5]
	strb r1, [r2]
	strb r1, [r6]
_0805E4C4:
	ldr r0, [r7, #0x1c]
	movs r1, #1
	ands r0, r1
	ldr r2, _0805E53C @ =0x000014E7
	adds r1, r7, r2
	strb r0, [r1]
	movs r3, #0x24
	adds r3, r3, r7
	mov r8, r3
	movs r4, #0
	mov sb, r4
	movs r0, #1
	mov sl, r0
	adds r6, r7, #0
	adds r6, #0xd8
_0805E4E2:
	mov r1, sl
	mov r2, sb
	lsls r1, r2
	ldr r0, [r7, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _0805E5E8
	ldr r1, _0805E540 @ =0x085ABA5C
	mov r3, r8
	movs r0, #2
	ldrsb r0, [r3, r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	adds r0, r7, #0
	mov r1, r8
	bl _call_via_r3
	mov r5, r8
	adds r5, #0xc4
	adds r3, r6, #0
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r6, #0x20]
	ldrb r0, [r6, #4]
	mov r2, sl
	ands r2, r0
	ldrh r1, [r4]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	mov r1, sl
	ands r0, r1
	cmp r2, r0
	beq _0805E544
	ldr r0, [r6, #0x10]
	movs r1, #4
	orrs r0, r1
	str r0, [r6, #0x10]
	b _0805E54E
	.align 2, 0
_0805E53C: .4byte 0x000014E7
_0805E540: .4byte 0x085ABA5C
_0805E544:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
_0805E54E:
	ldrb r0, [r3, #4]
	movs r1, #2
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	movs r2, #2
	ands r0, r2
	cmp r1, r0
	beq _0805E570
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0805E578
_0805E570:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0805E578:
	str r0, [r5]
	ldrh r0, [r3, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xe]
	ldr r4, _0805E5B0 @ =0x0000FFFF
	adds r2, r4, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r4, [r3, #7]
	cmp r0, r4
	blo _0805E5E8
	strh r1, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0805E5B4
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _0805E5A8
	ldrb r0, [r3, #5]
_0805E5A8:
	subs r0, #1
	strh r0, [r3, #8]
	b _0805E5C4
	.align 2, 0
_0805E5B0: .4byte 0x0000FFFF
_0805E5B4:
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _0805E5C4
	strh r1, [r3, #8]
_0805E5C4:
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r3, #6]
	ldrb r1, [r3, #6]
	ldrh r0, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805E5E8
	mov r4, sl
	strb r4, [r3, #7]
_0805E5E8:
	movs r0, #1
	add sb, r0
	movs r1, #0xa6
	lsls r1, r1, #1
	adds r6, r6, r1
	add r8, r1
	mov r2, sb
	cmp r2, #0xf
	bgt _0805E5FC
	b _0805E4E2
_0805E5FC:
	ldr r0, [r7, #0x1c]
	adds r0, #1
	str r0, [r7, #0x1c]
_0805E602:
	movs r0, #0
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805e614
FUN_0805e614: @ 0x0805E614
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x24
	movs r4, #0
_0805E61E:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805df94
	adds r4, #1
	movs r0, #0xa6
	lsls r0, r0, #1
	adds r5, r5, r0
	cmp r4, #0xf
	ble _0805E61E
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805e63c
FUN_0805e63c: @ 0x0805E63C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0
	str r0, [r6, #0x18]
	ldr r0, _0805E674 @ =0x0000922E
	ldr r1, _0805E678 @ =0x00005BB7
	bl GetFile
	str r0, [r6, #0x20]
	adds r5, r6, #0
	adds r5, #0x24
	movs r4, #0
_0805E654:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805de2c
	adds r4, #1
	movs r0, #0xa6
	lsls r0, r0, #1
	adds r5, r5, r0
	cmp r4, #0xf
	ble _0805E654
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805E674: .4byte 0x0000922E
_0805E678: .4byte 0x00005BB7

	thumb_func_start FUN_0805e67c
FUN_0805e67c: @ 0x0805E67C
	push {r4, lr}
	ldr r1, _0805E6A8 @ =0x00001510
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805E6B4
	ldr r1, _0805E6AC @ =FUN_0805e414
	ldr r2, _0805E6B0 @ =FUN_0805e614
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0805e63c
	cmp r0, #0
	bge _0805E6B4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805E6B6
	.align 2, 0
_0805E6A8: .4byte 0x00001510
_0805E6AC: .4byte FUN_0805e414
_0805E6B0: .4byte FUN_0805e614
_0805E6B4:
	adds r0, r4, #0
_0805E6B6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805e6bc
FUN_0805e6bc: @ 0x0805E6BC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	mov ip, r1
	mov sl, r3
	mov r4, sb
	adds r4, #0x24
	movs r0, #0
	movs r1, #1
	mov r6, sb
	adds r6, #0x88
	movs r7, #0x82
	lsls r7, r7, #1
	add r7, sb
_0805E6E0:
	mov r8, r1
	mov r3, r8
	lsls r3, r0
	mov r8, r3
	mov r3, sb
	ldr r5, [r3, #0x18]
	mov r3, r8
	ands r5, r3
	cmp r5, #0
	bne _0805E778
	movs r0, #3
	strb r0, [r4, #2]
	strb r1, [r4, #3]
	str r5, [r4, #4]
	strb r2, [r4]
	mov r0, sl
	strb r0, [r4, #1]
	mov r2, ip
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7]
	str r1, [r7, #4]
	adds r0, r4, #0
	adds r0, #0xf0
	ldr r1, _0805E774 @ =0x00000263
	bl FUN_0822b20c
	ldr r0, [r6, #0x60]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x60]
	mov r0, sb
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0805dff0
	movs r3, #0x86
	lsls r3, r3, #1
	adds r0, r4, r3
	bl FUN_08013698
	adds r4, #0x14
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_082364c4
	str r5, [sp]
	ldr r0, [sp, #0x30]
	str r0, [sp, #4]
	adds r0, r4, #0
	ldr r1, [sp, #0x28]
	ldr r2, [sp, #0x2c]
	movs r3, #0x80
	lsls r3, r3, #5
	bl FUN_082364f8
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_082364c4
	ldrh r1, [r6, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r6, #6]
	mov r1, sb
	ldr r0, [r1, #0x18]
	mov r2, r8
	orrs r0, r2
	str r0, [r1, #0x18]
	b _0805E788
	.align 2, 0
_0805E774: .4byte 0x00000263
_0805E778:
	adds r0, #1
	movs r3, #0xa6
	lsls r3, r3, #1
	adds r6, r6, r3
	adds r7, r7, r3
	adds r4, r4, r3
	cmp r0, #0xf
	ble _0805E6E0
_0805E788:
	movs r0, #0
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805e79c
FUN_0805e79c: @ 0x0805E79C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov r8, r0
	str r1, [sp, #0x10]
	str r3, [sp, #0x14]
	adds r0, r2, #0
	subs r0, #0x60
	str r0, [sp, #8]
	adds r2, #0x60
	str r2, [sp, #0xc]
	mov r6, r8
	adds r6, #0x24
	movs r0, #0
	str r0, [sp, #0x18]
	movs r1, #0xe8
	add r1, r8
	mov sb, r1
_0805E7C6:
	movs r2, #1
	mov sl, r2
	mov r0, sl
	ldr r1, [sp, #0x18]
	lsls r0, r1
	mov sl, r0
	mov r2, r8
	ldr r7, [r2, #0x18]
	ands r7, r0
	cmp r7, #0
	bne _0805E8BA
	movs r0, #1
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	str r7, [r6, #4]
	ldr r2, _0805E918 @ =0x030046B8
	ldr r1, [r2]
	adds r1, #1
	ldr r0, _0805E91C @ =0x000003FF
	ands r1, r0
	lsls r0, r1, #1
	ldr r2, _0805E920 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #0x1f
	ands r0, r2
	adds r0, #4
	strb r0, [r6, #8]
	movs r0, #0x14
	strb r0, [r6, #9]
	ldr r2, [sp, #0x18]
	lsls r0, r2, #3
	adds r0, #0xf
	strb r0, [r6, #0xa]
	adds r1, #1
	ldr r0, _0805E91C @ =0x000003FF
	ands r1, r0
	ldr r2, _0805E918 @ =0x030046B8
	str r1, [r2]
	lsls r1, r1, #1
	ldr r0, _0805E920 @ =0x0203B400
	adds r1, r1, r0
	ldrh r2, [r1]
	ldr r0, [sp, #0x18]
	movs r1, #1
	ands r0, r1
	lsls r0, r0, #2
	add r0, sp
	adds r0, #8
	ldr r1, [r0]
	movs r0, #0x3f
	ands r2, r0
	adds r1, r1, r2
	subs r1, #0x20
	strb r1, [r6]
	mov r2, sp
	ldrb r2, [r2, #0x14]
	strb r2, [r6, #1]
	adds r5, r6, #0
	adds r5, #0xe0
	ldr r2, [sp, #0x10]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	mov r2, sb
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	mov r0, r8
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0805dff0
	adds r0, r6, #0
	adds r0, #0xf0
	ldr r1, _0805E924 @ =0x00000267
	bl FUN_0822b20c
	ldr r0, _0805E928 @ =0x000014E8
	add r0, r8
	mov r1, sb
	str r0, [r1, #0x38]
	movs r2, #0x86
	lsls r2, r2, #1
	adds r0, r6, r2
	bl FUN_08013698
	adds r4, r6, #0
	adds r4, #0x14
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_082364c4
	str r7, [sp]
	ldr r0, [sp, #0x44]
	str r0, [sp, #4]
	adds r0, r4, #0
	ldr r1, [sp, #0x3c]
	ldr r2, [sp, #0x40]
	movs r3, #0x80
	lsls r3, r3, #5
	bl FUN_082364f8
	adds r4, #0x50
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_082364c4
	ldrh r1, [r4, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r4, #6]
	mov r1, r8
	ldr r0, [r1, #0x18]
	mov r2, sl
	orrs r0, r2
	str r0, [r1, #0x18]
_0805E8BA:
	ldr r0, [sp, #0x18]
	adds r0, #1
	str r0, [sp, #0x18]
	movs r1, #0xa6
	lsls r1, r1, #1
	add sb, r1
	adds r6, r6, r1
	cmp r0, #0xf
	bgt _0805E8CE
	b _0805E7C6
_0805E8CE:
	ldr r1, _0805E92C @ =0x000014E4
	add r1, r8
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r3, _0805E930 @ =0x000014E5
	add r3, r8
	movs r0, #0x14
	strb r0, [r3]
	ldr r0, _0805E934 @ =0x000014E6
	add r0, r8
	strb r2, [r0]
	ldr r0, _0805E938 @ =0x03003584
	ldr r2, [r0]
	ldr r0, _0805E93C @ =0x00004C60
	adds r1, r2, r0
	adds r0, #0x80
	adds r2, r2, r0
	ldr r0, _0805E928 @ =0x000014E8
	add r0, r8
	ldrb r3, [r3]
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	movs r4, #5
	str r4, [sp]
	bl rgb555_08237468
	movs r0, #0
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805E918: .4byte 0x030046B8
_0805E91C: .4byte 0x000003FF
_0805E920: .4byte 0x0203B400
_0805E924: .4byte 0x00000267
_0805E928: .4byte 0x000014E8
_0805E92C: .4byte 0x000014E4
_0805E930: .4byte 0x000014E5
_0805E934: .4byte 0x000014E6
_0805E938: .4byte 0x03003584
_0805E93C: .4byte 0x00004C60

	thumb_func_start FUN_0805e940
FUN_0805e940: @ 0x0805E940
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov r8, r0
	str r1, [sp, #0x10]
	str r3, [sp, #0x14]
	adds r0, r2, #0
	subs r0, #0x60
	str r0, [sp, #8]
	adds r2, #0x60
	str r2, [sp, #0xc]
	mov r6, r8
	adds r6, #0x24
	movs r0, #0
	str r0, [sp, #0x18]
	ldr r1, [sp, #0x48]
	cmp r0, r1
	blt _0805E96C
	b _0805EA7C
_0805E96C:
	movs r2, #0xe8
	add r2, r8
	mov sb, r2
_0805E972:
	movs r0, #1
	mov sl, r0
	mov r1, sl
	ldr r2, [sp, #0x18]
	lsls r1, r2
	mov sl, r1
	mov r0, r8
	ldr r7, [r0, #0x18]
	ands r7, r1
	cmp r7, #0
	bne _0805EA66
	movs r1, #1
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	str r7, [r6, #4]
	ldr r2, _0805EAC4 @ =0x030046B8
	ldr r1, [r2]
	adds r1, #1
	ldr r0, _0805EAC8 @ =0x000003FF
	ands r1, r0
	lsls r0, r1, #1
	ldr r2, _0805EACC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #0x1f
	ands r0, r2
	adds r0, #4
	strb r0, [r6, #8]
	movs r0, #0x14
	strb r0, [r6, #9]
	ldr r2, [sp, #0x18]
	lsls r0, r2, #3
	adds r0, #0xf
	strb r0, [r6, #0xa]
	adds r1, #1
	ldr r0, _0805EAC8 @ =0x000003FF
	ands r1, r0
	ldr r2, _0805EAC4 @ =0x030046B8
	str r1, [r2]
	lsls r1, r1, #1
	ldr r0, _0805EACC @ =0x0203B400
	adds r1, r1, r0
	ldrh r2, [r1]
	ldr r0, [sp, #0x18]
	movs r1, #1
	ands r0, r1
	lsls r0, r0, #2
	add r0, sp
	adds r0, #8
	ldr r1, [r0]
	movs r0, #0x3f
	ands r2, r0
	adds r1, r1, r2
	subs r1, #0x20
	strb r1, [r6]
	mov r2, sp
	ldrb r2, [r2, #0x14]
	strb r2, [r6, #1]
	adds r5, r6, #0
	adds r5, #0xe0
	ldr r2, [sp, #0x10]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	mov r2, sb
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	mov r0, r8
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0805dff0
	adds r0, r6, #0
	adds r0, #0xf0
	ldr r1, _0805EAD0 @ =0x00000267
	bl FUN_0822b20c
	ldr r0, _0805EAD4 @ =0x000014E8
	add r0, r8
	mov r1, sb
	str r0, [r1, #0x38]
	movs r2, #0x86
	lsls r2, r2, #1
	adds r0, r6, r2
	bl FUN_08013698
	adds r4, r6, #0
	adds r4, #0x14
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_082364c4
	str r7, [sp]
	ldr r0, [sp, #0x44]
	str r0, [sp, #4]
	adds r0, r4, #0
	ldr r1, [sp, #0x3c]
	ldr r2, [sp, #0x40]
	movs r3, #0x80
	lsls r3, r3, #5
	bl FUN_082364f8
	adds r4, #0x50
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_082364c4
	ldrh r1, [r4, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r4, #6]
	mov r1, r8
	ldr r0, [r1, #0x18]
	mov r2, sl
	orrs r0, r2
	str r0, [r1, #0x18]
_0805EA66:
	ldr r0, [sp, #0x18]
	adds r0, #1
	str r0, [sp, #0x18]
	movs r1, #0xa6
	lsls r1, r1, #1
	add sb, r1
	adds r6, r6, r1
	ldr r2, [sp, #0x48]
	cmp r0, r2
	bge _0805EA7C
	b _0805E972
_0805EA7C:
	ldr r1, _0805EAD8 @ =0x000014E4
	add r1, r8
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r3, _0805EADC @ =0x000014E5
	add r3, r8
	movs r0, #0x14
	strb r0, [r3]
	ldr r0, _0805EAE0 @ =0x000014E6
	add r0, r8
	strb r2, [r0]
	ldr r0, _0805EAE4 @ =0x03003584
	ldr r2, [r0]
	ldr r0, _0805EAE8 @ =0x00004C60
	adds r1, r2, r0
	adds r0, #0x80
	adds r2, r2, r0
	ldr r0, _0805EAD4 @ =0x000014E8
	add r0, r8
	ldrb r3, [r3]
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	movs r4, #5
	str r4, [sp]
	bl rgb555_08237468
	movs r0, #0
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805EAC4: .4byte 0x030046B8
_0805EAC8: .4byte 0x000003FF
_0805EACC: .4byte 0x0203B400
_0805EAD0: .4byte 0x00000267
_0805EAD4: .4byte 0x000014E8
_0805EAD8: .4byte 0x000014E4
_0805EADC: .4byte 0x000014E5
_0805EAE0: .4byte 0x000014E6
_0805EAE4: .4byte 0x03003584
_0805EAE8: .4byte 0x00004C60

	thumb_func_start FUN_0805eaec
FUN_0805eaec: @ 0x0805EAEC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r2, r0, #0
	adds r4, r1, #0
	movs r5, #0
	strb r5, [r4, #1]
	movs r0, #1
	strb r0, [r4, #2]
	str r5, [r4, #0x14]
	adds r6, r4, #0
	adds r6, #0x20
	adds r2, #0x18
	adds r0, r6, #0
	adds r1, r2, #0
	movs r2, #1
	bl FUN_0822a4b0
	movs r0, #3
	strb r0, [r6, #7]
	adds r4, #0x3c
	str r5, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _0805EB28 @ =0x05000002
	bl CpuSet
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805EB28: .4byte 0x05000002

	thumb_func_start FUN_0805eb2c
FUN_0805eb2c: @ 0x0805EB2C
	push {r4, r5, lr}
	adds r5, r1, #0
	adds r2, r5, #0
	adds r2, #0x20
	ldrb r0, [r5]
	cmp r0, #0
	beq _0805EB52
	movs r4, #0
	strb r4, [r5, #1]
	movs r1, #1
	strb r1, [r5, #2]
	str r4, [r5, #0x14]
	ldr r0, [r5, #0x20]
	orrs r0, r1
	str r0, [r5, #0x20]
	adds r0, r2, #0
	bl FUN_0822a4e0
	strb r4, [r5]
_0805EB52:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805eb58
FUN_0805eb58: @ 0x0805EB58
	bx lr
	.align 2, 0

	thumb_func_start FUN_0805eb5c
FUN_0805eb5c: @ 0x0805EB5C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	adds r4, r5, #0
	adds r4, #0x20
	ldrb r0, [r5, #2]
	cmp r0, #0
	beq _0805EB7C
	movs r0, #0
	strb r0, [r5, #2]
	movs r0, #2
	strh r0, [r4, #0x10]
	movs r0, #0xd8
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0805EB7C:
	ldr r0, [r5, #0x14]
	cmp r0, #5
	bne _0805EB86
	movs r0, #1
	b _0805EB8C
_0805EB86:
	cmp r0, #0xa
	bne _0805EB8E
	movs r0, #0
_0805EB8C:
	strh r0, [r4, #0x10]
_0805EB8E:
	ldr r1, [r5, #0x14]
	cmp r1, #9
	bhi _0805EBA2
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne _0805EBB4
	adds r1, r6, #0
	adds r1, #0x34
	b _0805EBB8
_0805EBA2:
	cmp r1, #0x13
	bhi _0805EBC0
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	bhi _0805EBB4
	adds r1, r6, #0
	adds r1, #0x34
	b _0805EBB8
_0805EBB4:
	adds r1, r6, #0
	adds r1, #0x18
_0805EBB8:
	adds r0, r4, #0
	bl FUN_0822a568
	b _0805EBCA
_0805EBC0:
	adds r1, r6, #0
	adds r1, #0x34
	adds r0, r4, #0
	bl FUN_0822a568
_0805EBCA:
	ldr r0, [r5, #0x14]
	cmp r0, #0x1d
	bls _0805EBE8
	adds r1, r6, #0
	adds r1, #0x18
	adds r0, r4, #0
	bl FUN_0822a568
	movs r0, #3
	movs r1, #0
	strb r0, [r5, #1]
	movs r0, #1
	strb r0, [r5, #2]
	str r1, [r5, #0x14]
	b _0805EBEC
_0805EBE8:
	adds r0, #1
	str r0, [r5, #0x14]
_0805EBEC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805ebf4
FUN_0805ebf4: @ 0x0805EBF4
	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #2]
	cmp r0, #0
	beq _0805EC02
	movs r0, #0
	strb r0, [r2, #2]
_0805EC02:
	ldr r0, [r2, #0x14]
	cmp r0, #0x32
	bne _0805EC16
	movs r0, #3
	movs r1, #0
	strb r0, [r2, #1]
	movs r0, #1
	strb r0, [r2, #2]
	str r1, [r2, #0x14]
	b _0805EC1A
_0805EC16:
	adds r0, #1
	str r0, [r2, #0x14]
_0805EC1A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805ec20
FUN_0805ec20: @ 0x0805EC20
	push {r4, r5, r6, r7, lr}
	adds r7, r1, #0
	adds r6, r7, #0
	adds r6, #0x20
	ldrb r0, [r7, #2]
	cmp r0, #0
	beq _0805EC32
	movs r0, #0
	strb r0, [r7, #2]
_0805EC32:
	ldr r0, [r7, #0x14]
	cmp r0, #9
	bhi _0805EC88
	ldr r0, [r7, #0x18]
	ldr r1, [r7, #0x1c]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	ldr r0, _0805EC7C @ =0x0203B400
	mov ip, r0
	ldr r3, _0805EC80 @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r5, _0805EC84 @ =0x000003FF
	ands r1, r5
	str r1, [r3]
	lsls r0, r1, #1
	add r0, ip
	ldrh r2, [r0]
	ldrh r0, [r6, #0x1c]
	subs r0, #4
	movs r4, #7
	ands r2, r4
	adds r0, r0, r2
	strh r0, [r6, #0x1c]
	adds r1, #1
	ands r1, r5
	str r1, [r3]
	lsls r1, r1, #1
	add r1, ip
	ldrh r1, [r1]
	ldrh r0, [r6, #0x20]
	subs r0, #4
	ands r1, r4
	adds r0, r0, r1
	strh r0, [r6, #0x20]
	b _0805EC94
	.align 2, 0
_0805EC7C: .4byte 0x0203B400
_0805EC80: .4byte 0x030046B8
_0805EC84: .4byte 0x000003FF
_0805EC88:
	cmp r0, #0xa
	bne _0805EC94
	ldr r0, [r7, #0x18]
	ldr r1, [r7, #0x1c]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
_0805EC94:
	ldr r0, [r7, #0x14]
	cmp r0, #0x28
	bne _0805ECA8
	movs r0, #4
	movs r1, #0
	strb r0, [r7, #1]
	movs r0, #1
	strb r0, [r7, #2]
	str r1, [r7, #0x14]
	b _0805ECAC
_0805ECA8:
	adds r0, #1
	str r0, [r7, #0x14]
_0805ECAC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805ecb4
FUN_0805ecb4: @ 0x0805ECB4
	push {r4, r5, lr}
	sub sp, #0x14
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #2]
	cmp r0, #0
	beq _0805ECE8
	movs r0, #0
	strb r0, [r4, #2]
	ldr r0, _0805ED5C @ =0x03002BE0
	ldr r2, [r0]
	cmp r2, #0
	beq _0805ECE8
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	movs r3, #0x18
	ldrsh r1, [r4, r3]
	subs r0, r0, r1
	movs r3, #0x30
	ldrsh r1, [r2, r3]
	movs r3, #0x1c
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r4, #3]
_0805ECE8:
	ldr r3, [r4, #0x14]
	movs r0, #0xf
	ands r3, r0
	cmp r3, #0xf
	bne _0805ED3A
	movs r1, #0xad
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0805ED3A
	ldr r2, _0805ED60 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805ED64 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0805ED68 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	ands r1, r3
	ldrb r3, [r4, #3]
	adds r1, r1, r3
	subs r1, #8
	ldrh r2, [r4, #6]
	ldrh r3, [r4, #4]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	ldrh r0, [r4, #0xc]
	str r0, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r0, #0x18
	str r0, [sp, #0x10]
	adds r0, r5, #0
	bl FUN_0805f320
_0805ED3A:
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #4
	ldr r1, [r4, #0x14]
	cmp r1, r0
	bne _0805ED78
	ldrb r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strb r0, [r4, #0xe]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r2, [r4, #0xf]
	cmp r0, r2
	bhs _0805ED6C
	movs r0, #2
	b _0805ED6E
	.align 2, 0
_0805ED5C: .4byte 0x03002BE0
_0805ED60: .4byte 0x030046B8
_0805ED64: .4byte 0x000003FF
_0805ED68: .4byte 0x0203B400
_0805ED6C:
	movs r0, #5
_0805ED6E:
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4, #2]
	str r1, [r4, #0x14]
	b _0805ED7C
_0805ED78:
	adds r0, r1, #1
	str r0, [r4, #0x14]
_0805ED7C:
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805ed84
FUN_0805ed84: @ 0x0805ED84
	push {r4, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	adds r3, #0x20
	ldrb r0, [r1, #2]
	cmp r0, #0
	beq _0805ED98
	movs r0, #0
	strb r0, [r1, #2]
	strh r0, [r3, #0x10]
_0805ED98:
	ldr r0, [r1, #0x14]
	cmp r0, #5
	beq _0805EDAE
	cmp r0, #0xa
	bne _0805EDB2
	movs r0, #2
	strh r0, [r3, #0x10]
	adds r0, r4, #0
	bl FUN_0805eb2c
	b _0805EDB8
_0805EDAE:
	movs r0, #1
	strh r0, [r3, #0x10]
_0805EDB2:
	ldr r0, [r1, #0x14]
	adds r0, #1
	str r0, [r1, #0x14]
_0805EDB8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805edc0
FUN_0805edc0: @ 0x0805EDC0
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x54
	movs r5, #0
	ldr r7, _0805EDF4 @ =0x085ABA70
_0805EDCC:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805EDE4
	ldrb r0, [r4, #1]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r3, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl _call_via_r3
_0805EDE4:
	adds r5, #1
	adds r4, #0x4c
	cmp r5, #7
	ble _0805EDCC
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805EDF4: .4byte 0x085ABA70

	thumb_func_start FUN_0805edf8
FUN_0805edf8: @ 0x0805EDF8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x54
	movs r4, #0
_0805EE02:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805eb2c
	adds r4, #1
	adds r5, #0x4c
	cmp r4, #7
	ble _0805EE02
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805ee1c
FUN_0805ee1c: @ 0x0805EE1C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	str r1, [r6, #0x50]
	adds r5, r6, #0
	adds r5, #0x18
	movs r4, #1
_0805EE28:
	adds r0, r5, #0
	ldr r1, _0805EE7C @ =0x00005AFD
	bl FUN_0822b16c
	adds r5, #0x1c
	subs r4, #1
	cmp r4, #0
	bge _0805EE28
	adds r0, r6, #0
	adds r0, #0x18
	movs r1, #9
	bl FUN_0822b20c
	adds r0, r6, #0
	adds r0, #0x34
	movs r1, #0xa
	bl FUN_0822b20c
	adds r5, r6, #0
	adds r5, #0x54
	movs r4, #0
_0805EE52:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805eaec
	adds r4, #1
	adds r5, #0x4c
	cmp r4, #7
	ble _0805EE52
	ldr r0, [r6, #0x50]
	bl FUN_0805f2dc
	movs r2, #0xad
	lsls r2, r2, #2
	adds r1, r6, r2
	str r0, [r1]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805EE7C: .4byte 0x00005AFD

	thumb_func_start FUN_0805ee80
FUN_0805ee80: @ 0x0805EE80
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xae
	lsls r1, r1, #2
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805EEBC
	ldr r1, _0805EEB4 @ =FUN_0805edc0
	ldr r2, _0805EEB8 @ =FUN_0805edf8
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0805ee1c
	cmp r0, #0
	bge _0805EEBC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805EEBE
	.align 2, 0
_0805EEB4: .4byte FUN_0805edc0
_0805EEB8: .4byte FUN_0805edf8
_0805EEBC:
	adds r0, r4, #0
_0805EEBE:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805eec4
FUN_0805eec4: @ 0x0805EEC4
	push {lr}
	adds r1, r0, #0
	adds r1, #0x54
	movs r2, #0
_0805EECC:
	ldrb r0, [r1]
	cmp r0, #0
	bne _0805EED6
	adds r0, r1, #0
	b _0805EEE0
_0805EED6:
	adds r2, #1
	adds r1, #0x4c
	cmp r2, #7
	ble _0805EECC
	movs r0, #0
_0805EEE0:
	pop {r1}
	bx r1

	thumb_func_start FUN_0805eee4
FUN_0805eee4: @ 0x0805EEE4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r2, #0
	mov r8, r3
	ldr r7, [sp, #0x30]
	cmp r0, #0
	beq _0805EF58
	bl FUN_0805eec4
	adds r6, r0, #0
	cmp r6, #0
	beq _0805EF58
	adds r0, #0x20
	movs r4, #1
	movs r1, #0
	strb r4, [r6, #1]
	strb r4, [r6, #2]
	str r1, [r6, #0x14]
	movs r1, #2
	movs r2, #0
	mov sb, r2
	strh r1, [r0, #0x10]
	ldr r1, [r7]
	ldr r2, [r7, #4]
	str r1, [r6, #0x18]
	str r2, [r6, #0x1c]
	ldr r1, [r7]
	ldr r2, [r7, #4]
	str r1, [r6, #0x3c]
	str r2, [r6, #0x40]
	ldr r1, [r6, #0x20]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r6, #0x20]
	movs r1, #0
	bl FUN_0822a340
	strh r5, [r6, #6]
	mov r0, r8
	strh r0, [r6, #4]
	ldr r0, [sp, #0x1c]
	strh r0, [r6, #8]
	ldr r0, [sp, #0x20]
	strh r0, [r6, #0xa]
	ldr r0, [sp, #0x24]
	strh r0, [r6, #0xc]
	ldr r0, [sp, #0x28]
	strb r0, [r6, #0x10]
	ldr r0, [sp, #0x2c]
	strb r0, [r6, #0xf]
	mov r2, sb
	strb r2, [r6, #0xe]
	strb r4, [r6]
	movs r0, #0
	b _0805EF5C
_0805EF58:
	movs r0, #1
	rsbs r0, r0, #0
_0805EF5C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805ef68
FUN_0805ef68: @ 0x0805EF68
	push {r4, lr}
	sub sp, #0x14
	adds r4, r1, #0
	cmp r0, #0
	beq _0805EF9E
	movs r1, #0xad
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0805EF9E
	ldr r0, [sp, #0x1c]
	str r0, [sp]
	ldr r0, [sp, #0x20]
	str r0, [sp, #4]
	ldr r0, [sp, #0x24]
	str r0, [sp, #8]
	ldr r0, [sp, #0x28]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0x10]
	adds r0, r1, #0
	adds r1, r4, #0
	bl FUN_0805f320
	movs r0, #0
	b _0805EFA2
_0805EF9E:
	movs r0, #1
	rsbs r0, r0, #0
_0805EFA2:
	add sp, #0x14
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805efac
FUN_0805efac: @ 0x0805EFAC
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r2, #0
	ldr r0, _0805EFE0 @ =0x03002BE0
	ldr r3, [r0]
	adds r4, r3, #0
	cmp r3, #0
	beq _0805F000
	ldrh r0, [r3, #0x24]
	ldrh r6, [r1, #4]
	cmp r0, r6
	bne _0805F000
	movs r6, #0xb6
	lsls r6, r6, #1
	adds r0, r3, r6
	cmp r0, r1
	bne _0805F000
	ldrb r0, [r2, #1]
	cmp r0, #0
	beq _0805EFE4
	adds r1, r0, #0
	adds r0, r3, #0
	bl FUN_0807ad60
	b _0805F000
	.align 2, 0
_0805EFE0: .4byte 0x03002BE0
_0805EFE4:
	ldr r0, _0805F008 @ =0x0000097C
	adds r3, r4, r0
	movs r1, #0x98
	lsls r1, r1, #4
	adds r0, r4, r1
	str r0, [sp]
	adds r0, r5, #0
	adds r0, #8
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #1
	movs r2, #0x1e
	bl FUN_08016e0c
_0805F000:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805F008: .4byte 0x0000097C

	thumb_func_start FUN_0805f00c
FUN_0805f00c: @ 0x0805F00C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x20
	adds r2, r0, #0
	adds r7, r1, #0
	adds r4, r7, #0
	adds r4, #0x68
	adds r2, #0x18
	adds r0, r4, #0
	adds r1, r2, #0
	movs r2, #1
	bl FUN_0822a4b0
	movs r6, #0
	movs r0, #1
	strb r0, [r4, #7]
	movs r0, #0x84
	adds r0, r0, r7
	mov r8, r0
	str r6, [sp, #0xc]
	add r0, sp, #0xc
	mov r1, r8
	ldr r2, _0805F0B4 @ =0x05000002
	bl CpuSet
	adds r5, r7, #0
	adds r5, #0x18
	ldr r2, _0805F0B8 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r4, #0x64
	orrs r0, r4
	ldr r1, _0805F0BC @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x10]
	add r3, sp, #0x10
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r4
	str r0, [r3, #4]
	str r6, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _0805F0C0 @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	str r3, [sp, #4]
	str r1, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r5, #0
	mov r1, r8
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _0805F0C4 @ =FUN_0805efac
	adds r0, r5, #0
	adds r2, r7, #0
	bl FUN_0823651c
	str r6, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x32
	movs r2, #0x1e
	movs r3, #0
	bl FUN_082364f8
	add sp, #0x20
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805F0B4: .4byte 0x05000002
_0805F0B8: .4byte 0xFFFF0000
_0805F0BC: .4byte 0x0000FFFF
_0805F0C0: .4byte 0x00002001
_0805F0C4: .4byte FUN_0805efac

	thumb_func_start FUN_0805f0c8
FUN_0805f0c8: @ 0x0805F0C8
	push {r4, lr}
	adds r4, r1, #0
	adds r2, r4, #0
	adds r2, #0x68
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805F0E8
	ldr r0, [r4, #0x68]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x68]
	adds r0, r2, #0
	bl FUN_0822a4e0
	movs r0, #0
	strb r0, [r4]
_0805F0E8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805f0f0
FUN_0805f0f0: @ 0x0805F0F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	mov r5, r8
	adds r5, #0x54
	movs r7, #0
	movs r0, #1
	mov sl, r0
	adds r4, r5, #0
	movs r1, #3
	mov sb, r1
_0805F10C:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805F20C
	movs r2, #0x68
	adds r2, r2, r5
	mov ip, r2
	adds r6, r5, #0
	adds r6, #0x18
	ldr r0, [r4, #4]
	cmp r0, #0x13
	bhi _0805F14C
	cmp r0, #0
	bne _0805F12C
	movs r0, #2
	strh r0, [r2, #0x10]
	b _0805F168
_0805F12C:
	cmp r0, #5
	bne _0805F134
	mov r0, sl
	b _0805F146
_0805F134:
	cmp r0, #0xa
	bne _0805F140
	mov r2, sb
	mov r1, ip
	strh r2, [r1, #0x10]
	b _0805F168
_0805F140:
	cmp r0, #0xf
	bne _0805F168
	movs r0, #0
_0805F146:
	mov r3, ip
	strh r0, [r3, #0x10]
	b _0805F168
_0805F14C:
	adds r1, r0, #0
	subs r1, #0x14
	movs r0, #7
	ands r1, r0
	cmp r1, #3
	bne _0805F15E
	mov r0, ip
	strh r1, [r0, #0x10]
	b _0805F168
_0805F15E:
	cmp r1, #7
	bne _0805F168
	movs r0, #0
	mov r1, ip
	strh r0, [r1, #0x10]
_0805F168:
	mov r1, ip
	adds r1, #0x1c
	ldrh r0, [r4, #0x10]
	mov r2, ip
	ldrh r2, [r2, #0x1c]
	adds r0, r0, r2
	mov r3, ip
	strh r0, [r3, #0x1c]
	ldrh r0, [r4, #0x12]
	ldrh r2, [r1, #2]
	adds r0, r0, r2
	strh r0, [r1, #2]
	ldrh r0, [r4, #0x14]
	ldrh r3, [r1, #4]
	adds r0, r0, r3
	strh r0, [r1, #4]
	mov r0, r8
	ldr r3, [r0, #0x50]
	adds r0, r3, #0
	subs r0, #0x1e
	ldr r2, [r4, #4]
	cmp r2, r0
	bhs _0805F1C4
	cmp r2, #5
	bls _0805F206
	ldr r0, _0805F1C0 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _0805F1AE
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #2
	beq _0805F206
_0805F1AE:
	adds r0, r6, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r6, #0
	bl FUN_08236400
	b _0805F206
	.align 2, 0
_0805F1C0: .4byte 0x03002BE0
_0805F1C4:
	adds r0, r3, #0
	subs r0, #0xf
	cmp r2, r0
	bhs _0805F1D6
	mov r3, sb
	ands r2, r3
	cmp r2, #0
	beq _0805F1E2
	b _0805F1EE
_0805F1D6:
	cmp r2, r3
	bhs _0805F1FC
	mov r0, sb
	ands r2, r0
	cmp r2, #1
	bhi _0805F1EE
_0805F1E2:
	mov r1, ip
	ldr r0, [r1]
	mov r2, sl
	orrs r0, r2
	str r0, [r1]
	b _0805F206
_0805F1EE:
	mov r3, ip
	ldr r0, [r3]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
	b _0805F206
_0805F1FC:
	mov r0, r8
	adds r1, r5, #0
	adds r2, r7, #0
	bl FUN_0805f0c8
_0805F206:
	ldr r0, [r4, #4]
	adds r0, #1
	str r0, [r4, #4]
_0805F20C:
	adds r7, #1
	adds r4, #0x94
	adds r5, #0x94
	cmp r7, #0xb
	bgt _0805F218
	b _0805F10C
_0805F218:
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805f228
FUN_0805f228: @ 0x0805F228
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x54
	movs r4, #0
_0805F232:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805f0c8
	adds r4, #1
	adds r5, #0x94
	cmp r4, #0xb
	ble _0805F232
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805f24c
FUN_0805f24c: @ 0x0805F24C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	str r1, [r6, #0x50]
	cmp r1, #0x3b
	bhi _0805F260
	movs r0, #0x3c
	str r0, [r6, #0x50]
_0805F260:
	adds r7, r6, #0
	adds r7, #0x18
	movs r0, #0x34
	adds r0, r0, r6
	mov r8, r0
	movs r0, #0x54
	adds r0, r0, r6
	mov sb, r0
	adds r5, r7, #0
	movs r4, #1
_0805F274:
	adds r0, r5, #0
	ldr r1, _0805F2B8 @ =0x00005AFE
	bl FUN_0822b16c
	adds r5, #0x1c
	subs r4, #1
	cmp r4, #0
	bge _0805F274
	adds r0, r7, #0
	movs r1, #9
	bl FUN_0822b20c
	mov r0, r8
	movs r1, #0x11
	bl FUN_0822b20c
	mov r5, sb
	movs r4, #0
_0805F298:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805f00c
	adds r4, #1
	adds r5, #0x94
	cmp r4, #0xb
	ble _0805F298
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805F2B8: .4byte 0x00005AFE

	thumb_func_start FUN_0805f2bc
FUN_0805f2bc: @ 0x0805F2BC
	push {lr}
	adds r1, r0, #0
	adds r1, #0x54
	movs r2, #0
_0805F2C4:
	ldrb r0, [r1]
	cmp r0, #0
	bne _0805F2CE
	adds r0, r1, #0
	b _0805F2D8
_0805F2CE:
	adds r2, #1
	adds r1, #0x94
	cmp r2, #0xb
	ble _0805F2C4
	movs r0, #0
_0805F2D8:
	pop {r1}
	bx r1

	thumb_func_start FUN_0805f2dc
FUN_0805f2dc: @ 0x0805F2DC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _0805F30C @ =0x00000744
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805F318
	ldr r1, _0805F310 @ =FUN_0805f0f0
	ldr r2, _0805F314 @ =FUN_0805f228
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0805f24c
	cmp r0, #0
	bge _0805F318
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805F31A
	.align 2, 0
_0805F30C: .4byte 0x00000744
_0805F310: .4byte FUN_0805f0f0
_0805F314: .4byte FUN_0805f228
_0805F318:
	adds r0, r4, #0
_0805F31A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805f320
FUN_0805f320: @ 0x0805F320
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r4, r1, #0
	mov r8, r2
	mov sl, r3
	adds r7, r0, #0
	cmp r7, #0
	beq _0805F34E
	adds r0, r7, #0
	bl FUN_0805f2bc
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x68
	movs r0, #0x18
	adds r0, r0, r5
	mov sb, r0
	cmp r5, #0
	bne _0805F354
_0805F34E:
	movs r0, #1
	rsbs r0, r0, #0
	b _0805F428
_0805F354:
	adds r3, r5, #0
	adds r3, #0x10
	ldr r2, _0805F378 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _0805F37C
	asrs r1, r0, #0xc
	b _0805F382
	.align 2, 0
_0805F378: .4byte 0x085B0A08
_0805F37C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805F382:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _0805F3A2
	asrs r0, r0, #0xc
	b _0805F3A8
_0805F3A2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805F3A8:
	movs r4, #0
	strh r0, [r3, #4]
	movs r0, #2
	strh r0, [r6, #0x10]
	ldr r0, [sp, #0x38]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r0, r6, #0
	movs r1, #0
	bl FUN_0822a340
	str r4, [sp]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #4]
	mov r0, sb
	mov r1, sl
	ldr r2, [sp, #0x28]
	movs r3, #0
	bl FUN_082364f8
	add r0, sp, #0x30
	ldrb r0, [r0]
	strb r0, [r5, #1]
	mov r1, sp
	ldrh r1, [r1, #0x34]
	strh r1, [r5, #8]
	mov r0, sp
	ldrh r0, [r0, #0x34]
	strh r0, [r5, #0xa]
	mov r1, sp
	ldrh r1, [r1, #0x34]
	strh r1, [r5, #0xc]
	mov r0, sp
	ldrh r0, [r0, #0x34]
	strh r0, [r5, #0xe]
	ldr r1, [sp, #0x30]
	lsls r0, r1, #0x18
	cmp r0, #0
	beq _0805F410
	adds r1, r7, #0
	adds r1, #0x18
	adds r0, r6, #0
	bl FUN_0822a4fc
	b _0805F41A
_0805F410:
	adds r1, r7, #0
	adds r1, #0x34
	adds r0, r6, #0
	bl FUN_0822a4fc
_0805F41A:
	movs r0, #0
	str r0, [r5, #4]
	movs r0, #1
	strb r0, [r5]
	ldr r0, _0805F438 @ =0x00000361
	bl PlaySound_082406e0
_0805F428:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805F438: .4byte 0x00000361

	thumb_func_start FUN_0805f43c
FUN_0805f43c: @ 0x0805F43C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, [r6, #0x18]
	cmp r0, #5
	bls _0805F44A
	b _0805F56C
_0805F44A:
	lsls r0, r0, #2
	ldr r1, _0805F454 @ =_0805F458
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0805F454: .4byte _0805F458
_0805F458: @ jump table
	.4byte _0805F470 @ case 0
	.4byte _0805F49C @ case 1
	.4byte _0805F4C8 @ case 2
	.4byte _0805F4F4 @ case 3
	.4byte _0805F520 @ case 4
	.4byte _0805F54A @ case 5
_0805F470:
	ldr r0, [r6, #0x1c]
	adds r0, #1
	str r0, [r6, #0x1c]
	cmp r0, #4
	bls _0805F56C
	adds r0, r6, #0
	adds r0, #0x48
	adds r5, r6, #0
	adds r5, #0x28
	movs r4, #4
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0x31
	movs r3, #2
	bl FUN_082370cc
	adds r0, r6, #0
	adds r0, #0xa8
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0x32
	b _0805F538
_0805F49C:
	ldr r0, [r6, #0x1c]
	adds r0, #1
	str r0, [r6, #0x1c]
	cmp r0, #4
	bls _0805F56C
	adds r0, r6, #0
	adds r0, #0x48
	adds r5, r6, #0
	adds r5, #0x28
	movs r4, #4
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0x33
	movs r3, #2
	bl FUN_082370cc
	adds r0, r6, #0
	adds r0, #0xa8
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0x34
	b _0805F538
_0805F4C8:
	ldr r0, [r6, #0x1c]
	adds r0, #1
	str r0, [r6, #0x1c]
	cmp r0, #4
	bls _0805F56C
	adds r0, r6, #0
	adds r0, #0x48
	adds r5, r6, #0
	adds r5, #0x28
	movs r4, #4
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0x35
	movs r3, #2
	bl FUN_082370cc
	adds r0, r6, #0
	adds r0, #0xa8
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0x36
	b _0805F538
_0805F4F4:
	ldr r0, [r6, #0x1c]
	adds r0, #1
	str r0, [r6, #0x1c]
	cmp r0, #4
	bls _0805F56C
	adds r0, r6, #0
	adds r0, #0x48
	adds r1, r6, #0
	adds r1, #0x28
	movs r2, #4
	str r2, [sp]
	movs r2, #0x37
	movs r3, #2
	bl FUN_082370cc
	adds r2, r6, #0
	adds r2, #0xa8
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	b _0805F53E
_0805F520:
	ldr r0, [r6, #0x1c]
	adds r0, #1
	str r0, [r6, #0x1c]
	cmp r0, #4
	bls _0805F56C
	adds r0, r6, #0
	adds r0, #0x48
	adds r1, r6, #0
	adds r1, #0x28
	movs r2, #4
	str r2, [sp]
	movs r2, #0x38
_0805F538:
	movs r3, #2
	bl FUN_082370cc
_0805F53E:
	ldr r0, [r6, #0x18]
	adds r0, #1
	str r0, [r6, #0x18]
	movs r0, #0
	str r0, [r6, #0x1c]
	b _0805F56C
_0805F54A:
	adds r0, r6, #0
	adds r0, #0x65
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0805F56C
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #1
	bl FUN_08022488
	adds r0, r6, #0
	bl KillEntity
_0805F56C:
	adds r0, r6, #0
	adds r0, #0x48
	adds r4, r6, #0
	adds r4, #0x28
	adds r1, r4, #0
	bl FUN_082372cc
	adds r0, r6, #0
	adds r0, #0xa8
	adds r1, r4, #0
	bl FUN_082372cc
	adds r2, r6, #0
	adds r2, #0xc8
	ldr r0, [r6, #0x68]
	ldr r1, [r6, #0x6c]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, [r6, #0x1c]
	adds r0, #1
	str r0, [r6, #0x1c]
	movs r0, #0
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805f5a0
FUN_0805f5a0: @ 0x0805F5A0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x48
	bl FUN_0822f1c0
	adds r4, #0xa8
	adds r0, r4, #0
	bl FUN_0822f1c0
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805f5bc
FUN_0805f5bc: @ 0x0805F5BC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	movs r3, #0x84
	lsls r3, r3, #1
	adds r0, r7, r3
	str r2, [r0]
	movs r4, #0x20
	adds r4, r4, r7
	mov sl, r4
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r7, #0x20]
	str r1, [r7, #0x24]
	ldr r0, _0805F670 @ =0x0000CB05
	ldr r1, _0805F674 @ =0x0000D3DA
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _0805F678
	adds r1, r7, #0
	adds r1, #0x28
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	adds r5, r7, #0
	adds r5, #0x28
	adds r0, r5, #0
	adds r1, r2, #0
	bl FUN_0822f284
	movs r4, #0x48
	adds r4, r4, r7
	mov sb, r4
	movs r0, #2
	str r0, [sp]
	movs r4, #0
	str r4, [sp, #4]
	movs r6, #0x3c
	str r6, [sp, #8]
	mov r0, sl
	str r0, [sp, #0xc]
	mov r0, sb
	adds r1, r5, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822f3fc
	movs r3, #0xa8
	adds r3, r3, r7
	mov r8, r3
	movs r0, #3
	str r0, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, sl
	str r0, [sp, #0xc]
	mov r0, r8
	adds r1, r5, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822f3fc
	str r4, [r7, #0x18]
	str r4, [r7, #0x1c]
	movs r4, #4
	str r4, [sp]
	mov r0, sb
	adds r1, r5, #0
	movs r2, #0x2f
	movs r3, #2
	bl FUN_082370cc
	str r4, [sp]
	mov r0, r8
	adds r1, r5, #0
	movs r2, #0x30
	movs r3, #2
	bl FUN_082370cc
	movs r0, #0
	b _0805F67C
	.align 2, 0
_0805F670: .4byte 0x0000CB05
_0805F674: .4byte 0x0000D3DA
_0805F678:
	movs r0, #1
	rsbs r0, r0, #0
_0805F67C:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805f68c
FUN_0805f68c: @ 0x0805F68C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0x86
	lsls r1, r1, #1
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805F6CC
	ldr r1, _0805F6C4 @ =FUN_0805f43c
	ldr r2, _0805F6C8 @ =FUN_0805f5a0
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0805f5bc
	cmp r0, #0
	bge _0805F6CC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805F6CE
	.align 2, 0
_0805F6C4: .4byte FUN_0805f43c
_0805F6C8: .4byte FUN_0805f5a0
_0805F6CC:
	adds r0, r4, #0
_0805F6CE:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
