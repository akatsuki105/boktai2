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

