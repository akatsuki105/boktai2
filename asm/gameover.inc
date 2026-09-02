	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a7104
FUN_080a7104: @ 0x080A7104
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_082407b8
	movs r0, #2
	bl PlaySound_082406e0
	movs r0, #0x96
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0xa
	strh r0, [r1]
	ldr r0, _080A713C @ =0x0000033E
	adds r1, r4, r0
	movs r0, #0x40
	strh r0, [r1]
	ldr r0, _080A7140 @ =0x00000341
	adds r4, r4, r0
	movs r0, #1
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A713C: .4byte 0x0000033E
_080A7140: .4byte 0x00000341

	thumb_func_start FUN_080a7144
FUN_080a7144: @ 0x080A7144
	push {lr}
	adds r2, r0, #0
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r0, _080A7178 @ =0x0000033E
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #0x1e
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x7e
	ble _080A7172
	movs r0, #0x7f
	strh r0, [r1]
	ldr r0, _080A717C @ =0x00000341
	adds r1, r2, r0
	movs r0, #2
	strb r0, [r1]
_080A7172:
	pop {r0}
	bx r0
	.align 2, 0
_080A7178: .4byte 0x0000033E
_080A717C: .4byte 0x00000341

	thumb_func_start FUN_080a7180
FUN_080a7180: @ 0x080A7180
	push {lr}
	adds r2, r0, #0
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r0, _080A71B4 @ =0x0000033E
	adds r1, r2, r0
	ldrh r0, [r1]
	subs r0, #3
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x60
	bgt _080A71AE
	movs r0, #0x60
	strh r0, [r1]
	ldr r0, _080A71B8 @ =0x00000341
	adds r1, r2, r0
	movs r0, #3
	strb r0, [r1]
_080A71AE:
	pop {r0}
	bx r0
	.align 2, 0
_080A71B4: .4byte 0x0000033E
_080A71B8: .4byte 0x00000341

	thumb_func_start FUN_080a71bc
FUN_080a71bc: @ 0x080A71BC
	push {lr}
	adds r2, r0, #0
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
	ldr r0, _080A71F0 @ =0x0000033E
	adds r1, r2, r0
	ldrh r0, [r1]
	subs r0, #3
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x40
	bgt _080A71EA
	movs r0, #0x40
	strh r0, [r1]
	ldr r0, _080A71F4 @ =0x00000341
	adds r1, r2, r0
	movs r0, #4
	strb r0, [r1]
_080A71EA:
	pop {r0}
	bx r0
	.align 2, 0
_080A71F0: .4byte 0x0000033E
_080A71F4: .4byte 0x00000341

	thumb_func_start FUN_080a71f8
FUN_080a71f8: @ 0x080A71F8
	push {lr}
	adds r2, r0, #0
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3f
	ble _080A7224
	movs r0, #0x40
	strh r0, [r1]
	ldr r0, _080A7228 @ =0x00000341
	adds r1, r2, r0
	movs r0, #5
	strb r0, [r1]
	ldr r0, _080A722C @ =0x00000346
	adds r1, r2, r0
	movs r0, #0
	strh r0, [r1]
_080A7224:
	pop {r0}
	bx r0
	.align 2, 0
_080A7228: .4byte 0x00000341
_080A722C: .4byte 0x00000346

	thumb_func_start FUN_080a7230
FUN_080a7230: @ 0x080A7230
	push {lr}
	adds r1, r0, #0
	ldr r0, _080A7258 @ =0x00000346
	adds r2, r1, r0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bls _080A7252
	ldr r3, _080A725C @ =0x00000341
	adds r0, r1, r3
	movs r1, #6
	strb r1, [r0]
	movs r0, #0
	strh r0, [r2]
_080A7252:
	pop {r0}
	bx r0
	.align 2, 0
_080A7258: .4byte 0x00000346
_080A725C: .4byte 0x00000341

	thumb_func_start FUN_080a7260
FUN_080a7260: @ 0x080A7260
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080A7280 @ =0x00000346
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1e
	bne _080A7288
	ldr r0, _080A7284 @ =0x000002F9
	bl PlaySound_082406e0
	b _080A72E0
	.align 2, 0
_080A7280: .4byte 0x00000346
_080A7284: .4byte 0x000002F9
_080A7288:
	cmp r0, #0x95
	bls _080A72E0
	cmp r0, #0x96
	bne _080A7296
	ldr r0, _080A72E8 @ =0x0000012D
	bl PlaySound_082406e0
_080A7296:
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r2, r4, r1
	ldrh r0, [r2]
	adds r0, #5
	strh r0, [r2]
	ldr r3, _080A72EC @ =0x0000033E
	adds r1, r4, r3
	ldrh r0, [r1]
	subs r0, #5
	strh r0, [r1]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, #0x7f
	ble _080A72E0
	movs r0, #1
	strh r0, [r2]
	strh r0, [r1]
	movs r3, #1
	adds r1, r4, #0
	adds r1, #0x18
	movs r2, #7
_080A72C2:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x50
	subs r2, #1
	cmp r2, #0
	bge _080A72C2
	movs r2, #0
	ldr r0, _080A72F0 @ =0x00000341
	adds r1, r4, r0
	movs r0, #7
	strb r0, [r1]
	ldr r1, _080A72F4 @ =0x00000346
	adds r0, r4, r1
	strh r2, [r0]
_080A72E0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A72E8: .4byte 0x0000012D
_080A72EC: .4byte 0x0000033E
_080A72F0: .4byte 0x00000341
_080A72F4: .4byte 0x00000346

	thumb_func_start FUN_080a72f8
FUN_080a72f8: @ 0x080A72F8
	push {lr}
	adds r2, r0, #0
	ldr r0, _080A731C @ =0x00000346
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bls _080A7316
	ldr r0, _080A7320 @ =0x00000341
	adds r1, r2, r0
	movs r0, #8
	strb r0, [r1]
_080A7316:
	pop {r0}
	bx r0
	.align 2, 0
_080A731C: .4byte 0x00000346
_080A7320: .4byte 0x00000341

	thumb_func_start FUN_080a7324
FUN_080a7324: @ 0x080A7324
	push {r4, r5, lr}
	mov ip, r0
	movs r4, #0xcf
	lsls r4, r4, #2
	add r4, ip
	ldr r2, _080A7374 @ =0x0000033E
	add r2, ip
	mov r1, ip
	adds r1, #0x20
	movs r3, #7
_080A7338:
	ldrh r0, [r4]
	strb r0, [r1]
	ldrh r0, [r2]
	strb r0, [r1, #1]
	adds r1, #0x50
	subs r3, #1
	cmp r3, #0
	bge _080A7338
	movs r3, #3
	movs r1, #0
	movs r4, #0xcf
	lsls r4, r4, #2
	add r4, ip
	movs r2, #0x92
	lsls r2, r2, #1
	add r2, ip
_080A7358:
	movs r5, #0
	ldrsh r0, [r4, r5]
	cmp r0, #0x40
	ble _080A7378
	ldrh r0, [r2, #0x2c]
	subs r0, r0, r1
	strh r0, [r2]
	subs r1, #0x10
	movs r5, #0
	ldrsh r0, [r4, r5]
	asrs r0, r0, #2
	adds r1, r1, r0
	b _080A737C
	.align 2, 0
_080A7374: .4byte 0x0000033E
_080A7378:
	ldrh r0, [r2, #0x2c]
	strh r0, [r2]
_080A737C:
	subs r2, #0x50
	subs r3, #1
	cmp r3, #0
	bge _080A7358
	movs r1, #0
	movs r4, #0xcf
	lsls r4, r4, #2
	add r4, ip
	movs r2, #0xba
	lsls r2, r2, #1
	add r2, ip
	movs r3, #3
_080A7394:
	movs r5, #0
	ldrsh r0, [r4, r5]
	cmp r0, #0x40
	ble _080A73AE
	ldrh r0, [r2, #0x2c]
	adds r0, r0, r1
	strh r0, [r2]
	subs r1, #0x10
	movs r5, #0
	ldrsh r0, [r4, r5]
	asrs r0, r0, #2
	adds r1, r1, r0
	b _080A73B2
_080A73AE:
	ldrh r0, [r2, #0x2c]
	strh r0, [r2]
_080A73B2:
	adds r2, #0x50
	subs r3, #1
	cmp r3, #0
	bge _080A7394
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a73c0
FUN_080a73c0: @ 0x080A73C0
	push {lr}
	ldr r0, _080A73DC @ =0x030047A4
	ldr r1, [r0]
	ldr r2, _080A73E0 @ =0xFFFFFBFF
	ands r1, r2
	str r1, [r0]
	movs r0, #2
	bl sound_08240740
	movs r0, #0
	bl FUN_0823a8f4
	pop {r0}
	bx r0
	.align 2, 0
_080A73DC: .4byte 0x030047A4
_080A73E0: .4byte 0xFFFFFBFF

	thumb_func_start FUN_080a73e4
FUN_080a73e4: @ 0x080A73E4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080A7408 @ =0x085AD014
	ldr r2, _080A740C @ =0x00000341
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080a7324
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A7408: .4byte 0x085AD014
_080A740C: .4byte 0x00000341

	thumb_func_start FUN_080a7410
FUN_080a7410: @ 0x080A7410
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x18
	movs r5, #7
_080A741A:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0822a340
	adds r4, #0x50
	subs r5, #1
	cmp r5, #0
	bge _080A741A
	movs r1, #0xae
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r1, #0
	bl FUN_0822a3f0
	ldr r0, _080A7444 @ =0x00000342
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A7444: .4byte 0x00000342

	thumb_func_start FUN_080a7448
FUN_080a7448: @ 0x080A7448
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r1, #1
	strh r1, [r0]
	ldr r2, _080A74F0 @ =0x0000033E
	adds r0, r7, r2
	strh r1, [r0]
	movs r3, #0
	movs r0, #0
	mov sl, r0
	adds r4, r7, #0
	adds r4, #0x28
	adds r5, r7, #0
	adds r5, #0x18
	adds r6, r7, #0
	adds r6, #0x44
	mov r8, r5
	movs r1, #0x38
	mov sb, r1
_080A747E:
	mov r2, sb
	strh r2, [r4, #0x38]
	movs r0, #0x48
	strh r0, [r4, #0x3a]
	cmp r3, #3
	ble _080A7490
	mov r0, sb
	adds r0, #0x10
	strh r0, [r4, #0x38]
_080A7490:
	adds r0, r6, #0
	ldr r1, _080A74F4 @ =0x0000654B
	str r3, [sp]
	bl Video_GetActorSprite
	mov r0, r8
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0822a4b0
	mov r0, sl
	strb r0, [r5, #7]
	ldr r0, _080A74F8 @ =0x00001033
	str r0, [r5]
	ldrh r0, [r4, #0x38]
	strh r0, [r4, #0xc]
	ldrh r0, [r4, #0x3a]
	strh r0, [r4, #0xe]
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r0, [r0]
	strb r0, [r5, #8]
	ldr r2, _080A74F0 @ =0x0000033E
	adds r0, r7, r2
	ldrh r0, [r0]
	strb r0, [r5, #9]
	ldr r3, [sp]
	strh r3, [r4]
	adds r4, #0x50
	adds r5, #0x50
	adds r6, #0x50
	movs r0, #0x50
	add r8, r0
	movs r1, #0x10
	add sb, r1
	adds r3, #1
	cmp r3, #7
	ble _080A747E
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A74F0: .4byte 0x0000033E
_080A74F4: .4byte 0x0000654B
_080A74F8: .4byte 0x00001033

	thumb_func_start FUN_080a74fc
FUN_080a74fc: @ 0x080A74FC
	push {lr}
	adds r3, r0, #0
	movs r1, #0xd1
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrh r0, [r0]
	movs r2, #0x1f
	cmp r0, #9
	bls _080A7528
	movs r2, #0x1b
	cmp r0, #0x11
	bls _080A7528
	movs r2, #0x12
	cmp r0, #0x19
	bls _080A7528
	movs r2, #0xa
	cmp r0, #0x21
	bls _080A7528
	movs r2, #0x1b
	cmp r0, #0x29
	bhi _080A7528
	movs r2, #0x12
_080A7528:
	movs r0, #0xd1
	lsls r0, r0, #2
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x31
	bls _080A7540
	movs r0, #0
	strh r0, [r1]
_080A7540:
	ldr r1, _080A754C @ =0x00000336
	adds r0, r3, r1
	strh r2, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_080A754C: .4byte 0x00000336

	thumb_func_start FUN_080a7550
FUN_080a7550: @ 0x080A7550
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r5, r0, #0
	ldr r0, _080A75F0 @ =0x0000CB05
	ldr r1, _080A75F4 @ =0x0000B343
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _080A75E8
	movs r0, #0xa6
	lsls r0, r0, #2
	adds r4, r5, r0
	adds r1, r4, #0
	adds r0, r2, #0
	ldm r0!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	ldm r0!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	ldm r0!, {r3, r6}
	stm r1!, {r3, r6}
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	ldr r2, _080A75F8 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	ldr r1, _080A75FC @ =0x0000FFF8
	orrs r0, r1
	adds r1, #7
	ands r0, r1
	ldr r1, _080A7600 @ =0xFFF80000
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	str r0, [sp, #0x14]
	movs r7, #0xae
	lsls r7, r7, #2
	adds r0, r5, r7
	ldr r3, _080A7604 @ =0x00001091
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0x87
	bl FUN_0822f4d8
	ldr r0, _080A7608 @ =0x03003584
	ldr r0, [r0]
	ldr r3, _080A760C @ =0x00005520
	adds r0, r0, r3
	movs r6, #0xc6
	lsls r6, r6, #2
	adds r4, r5, r6
	ldr r2, _080A7610 @ =0x04000008
	adds r1, r4, #0
	bl CpuSet
	adds r7, #0x3a
	adds r1, r5, r7
	movs r2, #0
	ldr r0, _080A7614 @ =0x000002A9
	strh r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r5, r1
	str r4, [r0]
	ldr r3, _080A7618 @ =0x00000343
	adds r0, r5, r3
	strb r2, [r0]
_080A75E8:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A75F0: .4byte 0x0000CB05
_080A75F4: .4byte 0x0000B343
_080A75F8: .4byte 0xFFFF0000
_080A75FC: .4byte 0x0000FFF8
_080A7600: .4byte 0xFFF80000
_080A7604: .4byte 0x00001091
_080A7608: .4byte 0x03003584
_080A760C: .4byte 0x00005520
_080A7610: .4byte 0x04000008
_080A7614: .4byte 0x000002A9
_080A7618: .4byte 0x00000343

	thumb_func_start FUN_080a761c
FUN_080a761c: @ 0x080A761C
	push {r4, lr}
	sub sp, #0xc
	ldr r0, _080A7670 @ =0x03000150
	ldr r4, [r0]
	cmp r4, #0
	beq _080A7668
	adds r0, r4, #0
	bl FUN_080a7410
	movs r0, #7
	bl FUN_0809c08c
	movs r1, #0xd0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _080A7668
	bl Script_GetValue
	cmp r0, #0
	beq _080A7668
	movs r0, #4
	str r0, [sp]
	ldr r0, _080A7674 @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_080A7668:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A7670: .4byte 0x03000150
_080A7674: .4byte 0x00001FFF

	thumb_func_start FUN_080a7678
FUN_080a7678: @ 0x080A7678
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _080A76C0 @ =0x030047A4
	ldr r1, _080A76C4 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	beq _080A76EE
	adds r0, r4, #0
	bl FUN_080a7410
	movs r0, #7
	bl FUN_0809c08c
	ldr r0, _080A76C8 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	subs r0, #0x1c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080A76CC
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _080A76E4
	.align 2, 0
_080A76C0: .4byte 0x030047A4
_080A76C4: .4byte 0x030047A0
_080A76C8: .4byte 0x03002BE0
_080A76CC:
	movs r0, #4
	str r0, [sp]
	ldr r0, _080A76F8 @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_080A76E4:
	movs r0, #0xd0
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_080A76EE:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A76F8: .4byte 0x00001FFF

	thumb_func_start FUN_080a76fc
FUN_080a76fc: @ 0x080A76FC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r0, _080A774C @ =0x00000346
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080A7746
	ldr r5, _080A7750 @ =FUN_0822e110
	ldr r6, _080A7754 @ =FUN_0822adac
	ldr r7, _080A7758 @ =FUN_0822f244
	movs r3, #2
	rsbs r3, r3, #0
	adds r1, r4, #0
	adds r1, #0x18
	movs r2, #7
_080A7722:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r1, #0x50
	subs r2, #1
	cmp r2, #0
	bge _080A7722
	movs r0, #0
	adds r1, r5, #0
	adds r2, r6, #0
	adds r3, r7, #0
	bl FUN_0822a448
	movs r0, #0xd0
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #2
	strb r0, [r1]
_080A7746:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A774C: .4byte 0x00000346
_080A7750: .4byte FUN_0822e110
_080A7754: .4byte FUN_0822adac
_080A7758: .4byte FUN_0822f244

	thumb_func_start FUN_080a775c
FUN_080a775c: @ 0x080A775C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl FUN_080a73e4
	ldr r1, _080A77E0 @ =0x00000341
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #6
	bne _080A77F8
	movs r0, #0xb0
	lsls r0, r0, #2
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r0, #3
	bl FUN_0809c08c
	movs r0, #1
	movs r1, #0xd
	movs r2, #0x1c
	movs r3, #4
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	movs r1, #0xce
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r0, [r0]
	bl FUN_080478f0
	movs r2, #0xd3
	lsls r2, r2, #2
	adds r5, r6, r2
	ldrb r0, [r5]
	lsls r0, r0, #1
	movs r1, #0xd2
	lsls r1, r1, #2
	adds r4, r6, r1
	adds r0, r4, r0
	ldrh r1, [r0]
	movs r0, #0
	bl FUN_08047c40
	ldr r0, _080A77E4 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x91
	lsls r2, r2, #4
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r4, r4, r0
	ldrh r4, [r4]
	cmp r1, r4
	blt _080A77E8
	movs r0, #0
	bl FUN_08047a28
	b _080A77EE
	.align 2, 0
_080A77E0: .4byte 0x00000341
_080A77E4: .4byte 0x030046A0
_080A77E8:
	movs r0, #1
	bl FUN_08047a28
_080A77EE:
	movs r0, #0xd0
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r0, #3
	strb r0, [r1]
_080A77F8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a7800
FUN_080a7800: @ 0x080A7800
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r6, #1
	rsbs r6, r6, #0
	ldr r0, _080A782C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080A7834
	ldr r1, _080A7830 @ =0x00000343
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r6, #1
	cmp r0, #0
	beq _080A7824
	movs r6, #0
_080A7824:
	movs r0, #0xdd
	bl PlaySound_082406e0
	b _080A7844
	.align 2, 0
_080A782C: .4byte 0x030044E0
_080A7830: .4byte 0x00000343
_080A7834:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080A7844
	movs r6, #0
	movs r0, #0xde
	bl PlaySound_082406e0
_080A7844:
	cmp r6, #0
	bne _080A789C
	movs r2, #0xb0
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r0, [r1]
	movs r4, #1
	orrs r0, r4
	str r0, [r1]
	bl FUN_08047864
	movs r0, #7
	bl FUN_0809c08c
	ldr r0, _080A788C @ =0x03002BE0
	ldr r0, [r0]
	bl FUN_0807adc0
	movs r0, #2
	bl sound_fadeout_08240440
	ldr r3, _080A7890 @ =0x00000346
	adds r0, r5, r3
	strh r6, [r0]
	ldr r1, _080A7894 @ =0x00000343
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _080A7898 @ =0x00000341
	adds r1, r5, r2
	movs r0, #6
	strb r0, [r1]
	subs r3, #6
	adds r1, r5, r3
	movs r0, #4
	strb r0, [r1]
	b _080A79A2
	.align 2, 0
_080A788C: .4byte 0x03002BE0
_080A7890: .4byte 0x00000346
_080A7894: .4byte 0x00000343
_080A7898: .4byte 0x00000341
_080A789C:
	cmp r6, #1
	bne _080A7918
	movs r0, #2
	bl sound_fadeout_08240440
	movs r0, #0xb0
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	movs r3, #1
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #7
_080A78BA:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x50
	subs r2, #1
	cmp r2, #0
	bge _080A78BA
	bl FUN_08047864
	movs r0, #7
	bl FUN_0809c08c
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080A790A
	ldr r1, _080A7914 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	movs r3, #0xd3
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrb r1, [r0]
	lsls r1, r1, #1
	subs r3, #4
	adds r0, r5, r3
	adds r0, r0, r1
	ldrh r0, [r0]
	str r0, [sp]
	add r1, sp, #4
	mov r0, sp
	str r0, [r1, #4]
	adds r0, r2, #0
	bl Script_ExecById
_080A790A:
	adds r0, r5, #0
	bl KillEntity
	b _080A79A2
	.align 2, 0
_080A7914: .4byte 0xFFFF0000
_080A7918:
	movs r2, #0
	ldr r0, _080A7934 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080A793C
	ldr r1, _080A7938 @ =0x00000343
	adds r0, r5, r1
	ldrb r1, [r0]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r2, r0, #0x1f
	b _080A7950
	.align 2, 0
_080A7934: .4byte 0x030044E0
_080A7938: .4byte 0x00000343
_080A793C:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A7950
	ldr r3, _080A7984 @ =0x00000343
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A7950
	movs r2, #1
_080A7950:
	cmp r2, #0
	beq _080A799C
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r0, _080A7984 @ =0x00000343
	adds r2, r5, r0
	ldrb r1, [r2]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r2]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A7988
	movs r1, #0xae
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0xa6
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #0x88
	movs r3, #1
	bl Sprite_SetSprite
	b _080A799C
	.align 2, 0
_080A7984: .4byte 0x00000343
_080A7988:
	movs r3, #0xae
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r2, #0xa6
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #0x87
	movs r3, #1
	bl Sprite_SetSprite
_080A799C:
	adds r0, r5, #0
	bl FUN_080a74fc
_080A79A2:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a79ac
FUN_080a79ac: @ 0x080A79AC
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080a73e4
	ldr r1, _080A79E4 @ =0x00000341
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _080A79DE
	ldr r2, _080A79E8 @ =0x030047A4
	ldr r0, [r2]
	ldr r1, _080A79EC @ =0xFFFFFBFF
	ands r0, r1
	str r0, [r2]
	ldr r1, _080A79F0 @ =0x03004788
	movs r0, #0
	str r0, [r1]
	ldr r1, _080A79F4 @ =0x00000343
	adds r0, r4, r1
	ldrb r0, [r0]
	bl FUN_0823a8f4
	adds r0, r4, #0
	bl KillEntity
_080A79DE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A79E4: .4byte 0x00000341
_080A79E8: .4byte 0x030047A4
_080A79EC: .4byte 0xFFFFFBFF
_080A79F0: .4byte 0x03004788
_080A79F4: .4byte 0x00000343

	thumb_func_start GameOverManager_Update
GameOverManager_Update: @ 0x080A79F8
	push {lr}
	ldr r2, _080A7A14 @ =0x085AD034
	movs r3, #0xd0
	lsls r3, r3, #2
	adds r1, r0, r3
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_080A7A14: .4byte 0x085AD034

	thumb_func_start GameOverManager_Destroy
GameOverManager_Destroy: @ 0x080A7A18
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _080A7A50 @ =0x00000342
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A7A44
	adds r4, r6, #0
	adds r4, #0x18
	movs r5, #7
_080A7A2C:
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r4, #0x50
	subs r5, #1
	cmp r5, #0
	bge _080A7A2C
	movs r1, #0xae
	lsls r1, r1, #2
	adds r0, r6, r1
	bl FUN_0822f1c0
_080A7A44:
	ldr r1, _080A7A54 @ =0x03000150
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A7A50: .4byte 0x00000342
_080A7A54: .4byte 0x03000150

	thumb_func_start GameOverManager_Init
GameOverManager_Init: @ 0x080A7A58
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080a7448
	adds r0, r4, #0
	bl FUN_080a7550
	movs r1, #0xd0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _080A7ABC @ =0x00000341
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #5
	adds r0, r4, r2
	movs r2, #0
	strh r1, [r0]
	ldr r1, _080A7AC0 @ =0x00000342
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _080A7A9A
	bl FUN_0823d340
	movs r2, #0xce
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
_080A7A9A:
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	beq _080A7AC8
	bl Script_GetValue
	movs r2, #0xd2
	lsls r2, r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _080A7AC4 @ =0x0000034A
	adds r1, r4, r2
	b _080A7ADA
	.align 2, 0
_080A7ABC: .4byte 0x00000341
_080A7AC0: .4byte 0x00000342
_080A7AC4: .4byte 0x0000034A
_080A7AC8:
	movs r0, #0xd2
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0xfa
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r2, _080A7B00 @ =0x0000034A
	adds r1, r4, r2
	movs r0, #0xfa
_080A7ADA:
	strh r0, [r1]
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	movs r0, #0x70
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A7B04
	bl Script_GetValue
	movs r2, #0xd4
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	b _080A7B0C
	.align 2, 0
_080A7B00: .4byte 0x0000034A
_080A7B04:
	movs r2, #0xd4
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
_080A7B0C:
	ldr r0, _080A7B18 @ =0x03000150
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A7B18: .4byte 0x03000150

	thumb_func_start GameOverManager_Create
GameOverManager_Create: @ 0x080A7B1C
	push {r4, lr}
	ldr r0, _080A7B54 @ =0x03000150
	ldr r0, [r0]
	cmp r0, #0
	bne _080A7B62
	movs r1, #0xd5
	lsls r1, r1, #2
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A7B60
	ldr r1, _080A7B58 @ =GameOverManager_Update
	ldr r2, _080A7B5C @ =GameOverManager_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl GameOverManager_Init
	cmp r0, #0
	bge _080A7B60
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A7B62
	.align 2, 0
_080A7B54: .4byte 0x03000150
_080A7B58: .4byte GameOverManager_Update
_080A7B5C: .4byte GameOverManager_Destroy
_080A7B60:
	adds r0, r4, #0
_080A7B62:
	pop {r4}
	pop {r1}
	bx r1

