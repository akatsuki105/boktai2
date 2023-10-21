	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0823b258
FUN_0823b258: @ 0x0823B258
	push {lr}
	adds r1, r0, #0
	ldr r0, _0823B268 @ =0x030016F8
	ldr r0, [r0]
	cmp r0, #0
	bne _0823B26C
	movs r0, #0
	b _0823B27E
	.align 2, 0
_0823B268: .4byte 0x030016F8
_0823B26C:
	ldr r0, [r0, #0x18]
	cmp r0, #0
	beq _0823B27C
_0823B272:
	cmp r0, r1
	beq _0823B27E
	ldr r0, [r0, #0x40]
	cmp r0, #0
	bne _0823B272
_0823B27C:
	movs r0, #0
_0823B27E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823b284
FUN_0823b284: @ 0x0823B284
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _0823B2A4 @ =0x030016F8
	ldr r5, [r0]
	cmp r5, #0
	beq _0823B29E
	cmp r4, #0
	beq _0823B29E
	adds r0, r4, #0
	bl FUN_0823b258
	cmp r0, #0
	bne _0823B2A8
_0823B29E:
	movs r0, #0
	b _0823B2CA
	.align 2, 0
_0823B2A4: .4byte 0x030016F8
_0823B2A8:
	ldr r1, [r4, #0x3c]
	cmp r1, #0
	bne _0823B2B4
	ldr r0, [r4, #0x40]
	str r0, [r5, #0x18]
	b _0823B2B8
_0823B2B4:
	ldr r0, [r4, #0x40]
	str r0, [r1, #0x40]
_0823B2B8:
	ldr r1, [r4, #0x40]
	cmp r1, #0
	bne _0823B2C4
	ldr r0, [r4, #0x3c]
	str r0, [r5, #0x1c]
	b _0823B2C8
_0823B2C4:
	ldr r0, [r4, #0x3c]
	str r0, [r1, #0x3c]
_0823B2C8:
	movs r0, #1
_0823B2CA:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0823b2d0
FUN_0823b2d0: @ 0x0823B2D0
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl FindUnk0200865c
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823b2e0
FUN_0823b2e0: @ 0x0823B2E0
	push {lr}
	bl FUN_0823b258
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823b2ec
FUN_0823b2ec: @ 0x0823B2EC
	push {r4, lr}
	sub sp, #8
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl FindUnk0200865c
	adds r4, r0, #0
	cmp r4, #0
	beq _0823B33C
	mov r0, sp
	bl FUN_0823167c
	movs r0, #8
	ldrsh r2, [r4, r0]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	movs r0, #0xa
	ldrsh r2, [r4, r0]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	movs r0, #0xc
	ldrsh r2, [r4, r0]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	movs r0, #0
	b _0823B370
_0823B33C:
	mov r0, sp
	bl FUN_0823167c
	mov r0, sp
	movs r1, #0
	movs r2, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	mov r0, sp
	movs r1, #0
	movs r2, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	mov r0, sp
	movs r1, #0
	movs r2, #0
	bl FUN_0823206c
	movs r0, #1
	rsbs r0, r0, #0
_0823B370:
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0823b378
FUN_0823b378: @ 0x0823B378
	movs r0, #0
	bx lr

	thumb_func_start FUN_0823b37c
FUN_0823b37c: @ 0x0823B37C
	ldr r1, _0823B384 @ =0x030016F8
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_0823B384: .4byte 0x030016F8

	thumb_func_start FUN_0823b388
FUN_0823b388: @ 0x0823B388
	ldr r1, _0823B398 @ =0x030016F8
	str r0, [r1]
	movs r1, #0
	str r1, [r0, #0x18]
	str r1, [r0, #0x1c]
	movs r0, #0
	bx lr
	.align 2, 0
_0823B398: .4byte 0x030016F8

	thumb_func_start FUN_0823b39c
FUN_0823b39c: @ 0x0823B39C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _0823B3D8 @ =0x030016F8
	ldr r0, [r0]
	cmp r0, #0
	bne _0823B3E6
	movs r0, #2
	movs r1, #0x20
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0823B3E4
	ldr r1, _0823B3DC @ =FUN_0823b378
	ldr r2, _0823B3E0 @ =FUN_0823b37c
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0823b388
	cmp r0, #0
	bge _0823B3E4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0823B3E6
	.align 2, 0
_0823B3D8: .4byte 0x030016F8
_0823B3DC: .4byte FUN_0823b378
_0823B3E0: .4byte FUN_0823b37c
_0823B3E4:
	adds r0, r4, #0
_0823B3E6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0823b3ec
FUN_0823b3ec: @ 0x0823B3EC
	push {lr}
	ldr r0, _0823B3FC @ =0x030016F8
	ldr r0, [r0]
	cmp r0, #0
	bne _0823B3F8
	movs r0, #0
_0823B3F8:
	pop {r1}
	bx r1
	.align 2, 0
_0823B3FC: .4byte 0x030016F8

	thumb_func_start FUN_0823b400
FUN_0823b400: @ 0x0823B400
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [sp, #0x10]
	ldr r6, [sp, #0x14]
	movs r5, #0
	strh r1, [r4]
	strh r5, [r4, #2]
	strb r0, [r4, #4]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #8]
	str r1, [r4, #0xc]
	strb r3, [r4, #5]
	strh r5, [r4, #0x10]
	strh r5, [r4, #0x12]
	strh r5, [r4, #0x14]
	movs r0, #0x10
	strh r0, [r4, #0x16]
	str r5, [r4, #0x18]
	str r5, [r4, #0x20]
	str r5, [r4, #0x28]
	str r5, [r4, #0x24]
	adds r0, r4, #0
	bl FUN_0823b1f8
	str r6, [r4, #0x38]
	movs r0, #1
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0823b43c
FUN_0823b43c: @ 0x0823B43C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r0, r1, #0
	adds r4, r2, #0
	adds r5, r3, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	str r0, [r6, #0x18]
	adds r1, r6, #0
	adds r1, #8
	bl FUN_0823280c
	strh r4, [r6, #0x1c]
	strh r5, [r6, #0x1e]
	movs r0, #1
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0823b464
FUN_0823b464: @ 0x0823B464
	str r1, [r0, #0x20]
	movs r0, #1
	bx lr
	.align 2, 0

	thumb_func_start FUN_0823b46c
FUN_0823b46c: @ 0x0823B46C
	str r1, [r0, #0x28]
	movs r0, #1
	bx lr
	.align 2, 0

	thumb_func_start FUN_0823b474
FUN_0823b474: @ 0x0823B474
	str r1, [r0, #0x2c]
	movs r0, #1
	bx lr
	.align 2, 0

	thumb_func_start FUN_0823b47c
FUN_0823b47c: @ 0x0823B47C
	movs r2, #4
	ldrh r3, [r0, #2]
	orrs r2, r3
	strh r2, [r0, #2]
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [r0, #0x30]
	str r2, [r0, #0x34]
	movs r0, #1
	bx lr

	thumb_func_start FUN_0823b490
FUN_0823b490: @ 0x0823B490
	push {r4, lr}
	adds r4, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	ldr r3, [sp, #8]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r4, [r0, #0x24]
	adds r0, r4, #0
	bl FUN_08234de8
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823b4b8
FUN_0823b4b8: @ 0x0823B4B8
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r5, [r4, #0x18]
	cmp r5, #0
	beq _0823B508
	ldr r0, _0823B4D4 @ =0x03003540
	movs r1, #0x12
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _0823B4D8
	cmp r0, #1
	beq _0823B4F2
	b _0823B520
	.align 2, 0
_0823B4D4: .4byte 0x03003540
_0823B4D8:
	adds r1, r4, #0
	adds r1, #8
	adds r2, r4, #0
	adds r2, #0x10
	ldrh r3, [r4, #0x1c]
	ldrh r0, [r4, #0x1e]
	str r0, [sp]
	ldrb r0, [r4, #4]
	str r0, [sp, #4]
	adds r0, r5, #0
	bl FUN_0823349c
	b _0823B520
_0823B4F2:
	ldrh r0, [r4, #0x10]
	ldrh r2, [r4, #8]
	adds r0, r0, r2
	movs r1, #0
	strh r0, [r4, #8]
	ldrh r0, [r4, #0x14]
	ldrh r2, [r4, #0xa]
	adds r0, r0, r2
	strh r0, [r4, #0xa]
	strh r1, [r4, #0xc]
	b _0823B520
_0823B508:
	ldrh r0, [r4, #0x10]
	ldrh r1, [r4, #8]
	adds r0, r0, r1
	strh r0, [r4, #8]
	ldrh r0, [r4, #0x12]
	ldrh r2, [r4, #0xa]
	adds r0, r0, r2
	strh r0, [r4, #0xa]
	ldrh r0, [r4, #0x14]
	ldrh r1, [r4, #0xc]
	adds r0, r0, r1
	strh r0, [r4, #0xc]
_0823B520:
	ldr r2, [r4, #0x28]
	cmp r2, #0
	beq _0823B52E
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
_0823B52E:
	movs r0, #0
	strh r0, [r4, #0x10]
	strh r0, [r4, #0x12]
	strh r0, [r4, #0x14]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0823b540
FUN_0823b540: @ 0x0823B540
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2]
	cmp r0, #0x48
	bne _0823B554
	ldrb r0, [r2, #1]
	cmp r0, #0x50
	bne _0823B554
	adds r0, r2, #0
	b _0823B55E
_0823B554:
	ldr r1, _0823B564 @ =0x02031400
	adds r0, r2, #0
	bl LZ77UnCompReadNormalWrite8bit
	ldr r0, _0823B568 @ =0x02031404
_0823B55E:
	pop {r1}
	bx r1
	.align 2, 0
_0823B564: .4byte 0x02031400
_0823B568: .4byte 0x02031404

	thumb_func_start FUN_0823b56c
FUN_0823b56c: @ 0x0823B56C
	push {r4, r5, lr}
	sub sp, #0x14
	adds r1, r0, #0
	ldr r0, _0823B588 @ =0x0000AE6C
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl FUN_082310cc
	cmp r0, #0
	bne _0823B58C
	movs r0, #1
	rsbs r0, r0, #0
	b _0823B5D2
	.align 2, 0
_0823B588: .4byte 0x0000AE6C
_0823B58C:
	bl FUN_0823b540
	adds r2, r0, #0
	mov r1, sp
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	ldr r0, [sp, #4]
	adds r0, r0, r2
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	adds r0, r0, r2
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	adds r0, r0, r2
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	cmp r0, #0
	beq _0823B5B8
	adds r0, r0, r2
	str r0, [sp, #0x10]
_0823B5B8:
	ldr r0, [sp, #4]
	bl FUN_082327f0
	ldr r0, [sp, #8]
	bl FUN_08234624
	ldr r0, [sp, #0xc]
	bl FUN_08234ddc
	ldr r0, [sp, #0x10]
	bl FUN_08235918
	movs r0, #0
_0823B5D2:
	add sp, #0x14
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823b5dc
FUN_0823b5dc: @ 0x0823B5DC
	push {r4, r5, r6, r7, lr}
	movs r0, #0x6e
	movs r1, #0
	bl FUN_0823174c
	movs r0, #0x68
	movs r1, #0
	bl FUN_0823174c
	adds r4, r0, #0
	movs r0, #0x74
	movs r1, #0
	bl FUN_0823174c
	adds r5, r0, #0
	movs r0, #0x72
	movs r1, #0
	bl FUN_0823174c
	adds r6, r0, #0
	movs r0, #0x7a
	movs r1, #0
	bl FUN_0823174c
	adds r7, r0, #0
	movs r0, #0x70
	movs r1, #0
	bl FUN_0823174c
	cmp r0, #0
	beq _0823B620
	bl FUN_0823b56c
	b _0823B650
_0823B620:
	cmp r4, #0
	beq _0823B62C
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl FUN_082327c0
_0823B62C:
	cmp r5, #0
	beq _0823B638
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	bl FUN_082345f8
_0823B638:
	cmp r6, #0
	beq _0823B644
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	bl FUN_08234db8
_0823B644:
	cmp r7, #0
	beq _0823B650
	lsls r0, r7, #0x10
	lsrs r0, r0, #0x10
	bl FUN_082358f4
_0823B650:
	ldr r0, _0823B688 @ =0x000056C2
	bl FUN_08230e70
	ldr r4, [r0, #4]
	movs r0, #0x76
	bl prepare_08231510
	cmp r0, #0
	beq _0823B6AE
	bl fetch_082316e4
	cmp r0, #0
	bne _0823B69C
	ldr r1, _0823B68C @ =FUN_0822db5c
	ldr r2, _0823B690 @ =FUN_0822aaac
	ldr r3, _0823B694 @ =FUN_0822f204
	movs r0, #0
	bl FUN_0822a448
	ldr r1, _0823B698 @ =0x03003540
	ldrh r0, [r4, #8]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	strh r0, [r1, #8]
	ldrh r0, [r4, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	b _0823B6AC
	.align 2, 0
_0823B688: .4byte 0x000056C2
_0823B68C: .4byte FUN_0822db5c
_0823B690: .4byte FUN_0822aaac
_0823B694: .4byte FUN_0822f204
_0823B698: .4byte 0x03003540
_0823B69C:
	ldr r1, _0823B6B4 @ =FUN_0822de64
	ldr r2, _0823B6B8 @ =FUN_0822ac90
	ldr r3, _0823B6BC @ =FUN_0822f224
	bl FUN_0822a448
	ldr r1, _0823B6C0 @ =0x03003540
	movs r0, #0
	strh r0, [r1, #8]
_0823B6AC:
	strh r0, [r1, #0xa]
_0823B6AE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0823B6B4: .4byte FUN_0822de64
_0823B6B8: .4byte FUN_0822ac90
_0823B6BC: .4byte FUN_0822f224
_0823B6C0: .4byte 0x03003540
_0823B6C4:
	.byte 0x10, 0xB5, 0x76, 0x20, 0x00, 0x21, 0xF6, 0xF7, 0x3F, 0xF8, 0x00, 0x28
	.byte 0x22, 0xD1, 0x0C, 0x48, 0xF5, 0xF7, 0xCC, 0xFB, 0x04, 0x1C, 0x0B, 0x49, 0x0B, 0x4A, 0x0C, 0x4B
	.byte 0x00, 0x20, 0xEE, 0xF7, 0xB1, 0xFE, 0x00, 0x2C, 0x1B, 0xD0, 0x60, 0x68, 0x00, 0x28, 0x18, 0xD0
	.byte 0x08, 0x49, 0x00, 0x89, 0x00, 0x04, 0x00, 0x15, 0x08, 0x81, 0x60, 0x68, 0x40, 0x89, 0x00, 0x04
	.byte 0x00, 0x15, 0x11, 0xE0, 0xC2, 0x56, 0x00, 0x00, 0x5D, 0xDB, 0x22, 0x08, 0xAD, 0xAA, 0x22, 0x08
	.byte 0x05, 0xF2, 0x22, 0x08, 0x40, 0x35, 0x00, 0x03, 0x05, 0x49, 0x06, 0x4A, 0x06, 0x4B, 0xEE, 0xF7
	.byte 0x93, 0xFE, 0x06, 0x49, 0x00, 0x20, 0x08, 0x81, 0x48, 0x81, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47
	.byte 0x65, 0xDE, 0x22, 0x08, 0x91, 0xAC, 0x22, 0x08, 0x25, 0xF2, 0x22, 0x08, 0x40, 0x35, 0x00, 0x03

	thumb_func_start FUN_0823b740
FUN_0823b740: @ 0x0823B740
	movs r0, #0
	bx lr

	thumb_func_start FUN_0823b744
FUN_0823b744: @ 0x0823B744
	ldr r1, _0823B74C @ =0x030047D0
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_0823B74C: .4byte 0x030047D0

	thumb_func_start FUN_0823b750
FUN_0823b750: @ 0x0823B750
	push {r4, r5, lr}
	mov ip, r0
	ldrh r0, [r1, #2]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	movs r2, #0
	ldrsh r0, [r1, r2]
	subs r2, r0, r4
	movs r3, #4
	ldrsh r0, [r1, r3]
	subs r3, r0, r4
	mov r0, ip
	adds r0, #0x8e
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r2, r0
	blt _0823B77E
	mov r0, ip
	adds r0, #0x92
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r2, r0
	ble _0823B780
_0823B77E:
	adds r2, r0, #0
_0823B780:
	mov r0, ip
	adds r0, #0x90
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r3, r0
	blt _0823B798
	mov r0, ip
	adds r0, #0x94
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r3, r0
	ble _0823B79A
_0823B798:
	adds r3, r0, #0
_0823B79A:
	adds r0, r2, r4
	strh r0, [r1]
	adds r0, r3, r4
	strh r0, [r1, #4]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0823b7a8
FUN_0823b7a8: @ 0x0823B7A8
	push {r4, lr}
	adds r3, r0, #0
	adds r2, r1, #0
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r4, #0
	ldrsh r0, [r2, r4]
	subs r1, r1, r0
	adds r0, r3, #0
	adds r0, #0x8e
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bge _0823B7D4
	subs r0, r0, r1
	asrs r1, r0, #1
	ldrh r0, [r2]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r2, #4]
	adds r0, r0, r1
	b _0823B7EE
_0823B7D4:
	adds r0, r3, #0
	adds r0, #0x92
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	ble _0823B7F0
	subs r0, r1, r0
	asrs r1, r0, #1
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r2, #4]
	subs r0, r0, r1
_0823B7EE:
	strh r0, [r2, #4]
_0823B7F0:
	movs r1, #4
	ldrsh r0, [r2, r1]
	movs r4, #0
	ldrsh r1, [r2, r4]
	adds r0, r0, r1
	movs r4, #2
	ldrsh r1, [r2, r4]
	subs r1, r0, r1
	adds r0, r3, #0
	adds r0, #0x90
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bge _0823B81C
	subs r0, r0, r1
	asrs r1, r0, #1
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r2, #4]
	adds r0, r0, r1
	b _0823B836
_0823B81C:
	adds r0, r3, #0
	adds r0, #0x94
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	ble _0823B838
	subs r0, r1, r0
	asrs r1, r0, #1
	ldrh r0, [r2]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r2, #4]
	subs r0, r0, r1
_0823B836:
	strh r0, [r2, #4]
_0823B838:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0823b840
FUN_0823b840: @ 0x0823B840
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldrh r0, [r0]
	cmp r0, #1
	bne _0823B854
	adds r0, r2, #0
	bl FUN_0823b750
	b _0823B85E
_0823B854:
	cmp r0, #2
	bne _0823B85E
	adds r0, r2, #0
	bl FUN_0823b7a8
_0823B85E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0823b864
FUN_0823b864: @ 0x0823B864
	push {lr}
	ldr r0, _0823B87C @ =0x030047D0
	ldr r0, [r0]
	cmp r0, #0
	beq _0823B876
	adds r1, r0, #0
	adds r1, #0x54
	movs r0, #0
	strh r0, [r1]
_0823B876:
	pop {r0}
	bx r0
	.align 2, 0
_0823B87C: .4byte 0x030047D0

	thumb_func_start FUN_0823b880
FUN_0823b880: @ 0x0823B880
	push {lr}
	adds r2, r0, #0
	ldr r0, _0823B898 @ =0x030047D0
	ldr r0, [r0]
	cmp r0, #0
	beq _0823B8A8
	cmp r2, #1
	bgt _0823B89C
	adds r1, r0, #0
	adds r1, #0x54
	movs r0, #0
	b _0823B8A6
	.align 2, 0
_0823B898: .4byte 0x030047D0
_0823B89C:
	adds r1, r0, #0
	adds r1, #0x56
	strh r2, [r1]
	subs r1, #2
	movs r0, #3
_0823B8A6:
	strh r0, [r1]
_0823B8A8:
	pop {r0}
	bx r0

	thumb_func_start FUN_0823b8ac
FUN_0823b8ac: @ 0x0823B8AC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _0823B92C @ =0x030047D0
	ldr r3, [r5]
	cmp r3, #0
	beq _0823B978
	ldrh r0, [r4]
	adds r1, r3, #0
	adds r1, #0x60
	strh r0, [r1]
	ldrh r0, [r4, #2]
	adds r2, r3, #0
	adds r2, #0x62
	strh r0, [r2]
	ldrh r2, [r4, #4]
	adds r0, r3, #0
	adds r0, #0x64
	strh r2, [r0]
	adds r0, r3, #0
	bl FUN_0823b840
	ldr r5, [r5]
	mov ip, r5
	mov r1, ip
	adds r1, #0x54
	movs r0, #1
	strh r0, [r1]
	mov r1, ip
	ldrh r0, [r1, #0x1c]
	cmp r0, #0
	bne _0823B978
	ldr r2, _0823B930 @ =0x03003540
	mov r3, ip
	adds r3, #0x60
	mov r0, ip
	adds r0, #0x80
	ldrh r1, [r0]
	ldrh r3, [r3]
	adds r1, r1, r3
	strh r1, [r2]
	subs r0, #0x1e
	ldrh r0, [r0]
	strh r0, [r2, #2]
	mov r3, ip
	adds r3, #0x64
	mov r0, ip
	adds r0, #0x82
	ldrh r0, [r0]
	ldrh r3, [r3]
	adds r0, r0, r3
	strh r0, [r2, #4]
	ldr r5, _0823B934 @ =0x030047C8
	lsls r1, r1, #0x10
	asrs r4, r1, #0x11
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0823B938
	asrs r0, r0, #8
	b _0823B93E
	.align 2, 0
_0823B92C: .4byte 0x030047D0
_0823B930: .4byte 0x03003540
_0823B934: .4byte 0x030047C8
_0823B938:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0823B93E:
	strh r0, [r5]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0823B950
	asrs r0, r0, #8
	b _0823B956
_0823B950:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0823B956:
	adds r3, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0823B96A
	asrs r1, r0, #8
	b _0823B970
_0823B96A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0823B970:
	subs r0, r3, r1
	strh r0, [r5, #2]
	adds r0, r3, r1
	strh r0, [r5, #4]
_0823B978:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0823b980
FUN_0823b980: @ 0x0823B980
	push {r4, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	ldr r0, _0823B9B4 @ =0x030047D0
	ldr r2, [r0]
	cmp r2, #0
	beq _0823B9C6
	ldrh r1, [r3]
	adds r0, r2, #0
	adds r0, #0x60
	strh r1, [r0]
	ldrh r0, [r3, #2]
	adds r1, r2, #0
	adds r1, #0x62
	strh r0, [r1]
	ldrh r1, [r3, #4]
	adds r0, r2, #0
	adds r0, #0x64
	strh r1, [r0]
	cmp r4, #1
	bgt _0823B9B8
	adds r1, r2, #0
	adds r1, #0x54
	movs r0, #1
	b _0823B9C4
	.align 2, 0
_0823B9B4: .4byte 0x030047D0
_0823B9B8:
	adds r0, r2, #0
	adds r0, #0x56
	strh r4, [r0]
	adds r1, r2, #0
	adds r1, #0x54
	movs r0, #2
_0823B9C4:
	strh r0, [r1]
_0823B9C6:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0823b9cc
FUN_0823b9cc: @ 0x0823B9CC
	push {lr}
	adds r3, r0, #0
	ldr r0, _0823B9F8 @ =0x030047D0
	ldr r2, [r0]
	cmp r2, #0
	beq _0823B9F2
	ldr r0, _0823B9FC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0823B9F2
	adds r0, r2, #0
	adds r0, #0x7e
	ldrh r1, [r0]
	cmp r3, r1
	ble _0823B9F2
	strh r3, [r0]
_0823B9F2:
	pop {r0}
	bx r0
	.align 2, 0
_0823B9F8: .4byte 0x030047D0
_0823B9FC: .4byte 0x030047A4

	thumb_func_start FUN_0823ba00
FUN_0823ba00: @ 0x0823BA00
	push {r4, r5, r6, lr}
	ldr r0, _0823BA44 @ =0x030047D0
	ldr r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	beq _0823BAA2
	ldr r3, _0823BA48 @ =0x03003540
	adds r0, r1, #0
	adds r0, #0x80
	ldrh r2, [r3]
	ldrh r0, [r0]
	subs r2, r2, r0
	strh r2, [r3]
	adds r0, r1, #0
	adds r0, #0x82
	ldrh r1, [r3, #4]
	ldrh r0, [r0]
	subs r1, r1, r0
	strh r1, [r3, #4]
	ldr r4, _0823BA4C @ =0x030047C8
	adds r5, r3, #0
	lsls r2, r2, #0x10
	asrs r3, r2, #0x11
	lsls r1, r1, #0x10
	asrs r2, r1, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0823BA50
	asrs r0, r0, #8
	b _0823BA56
	.align 2, 0
_0823BA44: .4byte 0x030047D0
_0823BA48: .4byte 0x03003540
_0823BA4C: .4byte 0x030047C8
_0823BA50:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0823BA56:
	strh r0, [r4]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0823BA68
	asrs r0, r0, #8
	b _0823BA6E
_0823BA68:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0823BA6E:
	adds r3, r0, #0
	movs r0, #2
	ldrsh r1, [r5, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0823BA82
	asrs r2, r0, #8
	b _0823BA88
_0823BA82:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r2, r0, #0
_0823BA88:
	subs r0, r3, r2
	movs r1, #0
	strh r0, [r4, #2]
	adds r0, r3, r2
	strh r0, [r4, #4]
	ldr r2, [r6]
	adds r0, r2, #0
	adds r0, #0x7e
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
_0823BAA2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0823baa8
FUN_0823baa8: @ 0x0823BAA8
	push {lr}
	ldr r0, _0823BAC4 @ =0x030047D0
	ldr r2, [r0]
	cmp r2, #0
	beq _0823BAC0
	movs r0, #0
	movs r1, #1
	strh r1, [r2, #0x1c]
	adds r1, r2, #0
	adds r1, #0x68
	strh r0, [r1]
	strh r0, [r2, #0x1e]
_0823BAC0:
	pop {r0}
	bx r0
	.align 2, 0
_0823BAC4: .4byte 0x030047D0

	thumb_func_start FUN_0823bac8
FUN_0823bac8: @ 0x0823BAC8
	push {r4, r5, r6, lr}
	adds r1, r0, #0
	ldr r0, _0823BB18 @ =0x030047D0
	ldr r3, [r0]
	adds r6, r0, #0
	cmp r3, #0
	beq _0823BB74
	ldrh r0, [r1]
	adds r2, r3, #0
	adds r2, #0x6c
	strh r0, [r2]
	ldrh r0, [r1, #2]
	movs r4, #0x6e
	adds r4, r4, r3
	strh r0, [r4]
	ldrh r0, [r1, #4]
	adds r3, #0x70
	strh r0, [r3]
	ldr r1, _0823BB1C @ =0x03003540
	ldrh r2, [r2]
	strh r2, [r1]
	ldrh r0, [r4]
	strh r0, [r1, #2]
	ldrh r0, [r3]
	strh r0, [r1, #4]
	ldr r4, _0823BB20 @ =0x030047C8
	adds r5, r1, #0
	lsls r2, r2, #0x10
	asrs r3, r2, #0x11
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0823BB24
	asrs r0, r0, #8
	b _0823BB2A
	.align 2, 0
_0823BB18: .4byte 0x030047D0
_0823BB1C: .4byte 0x03003540
_0823BB20: .4byte 0x030047C8
_0823BB24:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0823BB2A:
	strh r0, [r4]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0823BB3C
	asrs r0, r0, #8
	b _0823BB42
_0823BB3C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0823BB42:
	adds r2, r0, #0
	movs r0, #2
	ldrsh r1, [r5, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0823BB56
	asrs r1, r0, #8
	b _0823BB5C
_0823BB56:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0823BB5C:
	subs r0, r2, r1
	movs r3, #0
	strh r0, [r4, #2]
	adds r0, r2, r1
	strh r0, [r4, #4]
	ldr r1, [r6]
	movs r2, #1
	strh r2, [r1, #0x1c]
	adds r0, r1, #0
	adds r0, #0x68
	strh r2, [r0]
	strh r3, [r1, #0x1e]
_0823BB74:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0823bb7c
FUN_0823bb7c: @ 0x0823BB7C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	ldr r0, _0823BBB4 @ =0x030047D0
	ldr r2, [r0]
	adds r5, r0, #0
	cmp r2, #0
	beq _0823BBCC
	ldrh r1, [r3]
	adds r0, r2, #0
	adds r0, #0x6c
	strh r1, [r0]
	ldrh r0, [r3, #2]
	adds r1, r2, #0
	adds r1, #0x6e
	strh r0, [r1]
	ldrh r1, [r3, #4]
	adds r0, r2, #0
	adds r0, #0x70
	strh r1, [r0]
	movs r1, #1
	strh r1, [r2, #0x1c]
	cmp r4, #1
	bgt _0823BBB8
	subs r0, #8
	strh r1, [r0]
	b _0823BBC6
	.align 2, 0
_0823BBB4: .4byte 0x030047D0
_0823BBB8:
	adds r0, r2, #0
	adds r0, #0x6a
	strh r4, [r0]
	adds r1, r2, #0
	adds r1, #0x68
	movs r0, #2
	strh r0, [r1]
_0823BBC6:
	ldr r1, [r5]
	movs r0, #0
	strh r0, [r1, #0x1e]
_0823BBCC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0823bbd4
FUN_0823bbd4: @ 0x0823BBD4
	push {r4, r5, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	ldr r5, _0823BC10 @ =0x030047D0
	ldr r0, [r5]
	cmp r0, #0
	beq _0823BC0A
	adds r0, #0x7c
	strh r2, [r0]
	ldrh r0, [r0]
	bl FUN_0823b2d0
	cmp r0, #0
	beq _0823BC0A
	ldr r2, [r5]
	movs r0, #1
	strh r0, [r2, #0x1c]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r2, #0x74]
	str r1, [r2, #0x78]
	adds r1, r2, #0
	adds r1, #0x68
	movs r0, #3
	strh r0, [r1]
	movs r0, #0
	strh r0, [r2, #0x1e]
_0823BC0A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0823BC10: .4byte 0x030047D0

	thumb_func_start FUN_0823bc14
FUN_0823bc14: @ 0x0823BC14
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r6, _0823BC4C @ =0x030047D0
	ldr r0, [r6]
	cmp r0, #0
	beq _0823BC66
	adds r0, #0x7c
	strh r3, [r0]
	ldrh r0, [r0]
	bl FUN_0823b2d0
	cmp r0, #0
	beq _0823BC66
	ldr r2, [r6]
	movs r0, #1
	strh r0, [r2, #0x1c]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r2, #0x74]
	str r1, [r2, #0x78]
	cmp r4, #1
	bgt _0823BC50
	adds r1, r2, #0
	adds r1, #0x68
	movs r0, #3
	b _0823BC5C
	.align 2, 0
_0823BC4C: .4byte 0x030047D0
_0823BC50:
	adds r0, r2, #0
	adds r0, #0x6a
	strh r4, [r0]
	adds r1, r2, #0
	adds r1, #0x68
	movs r0, #4
_0823BC5C:
	strh r0, [r1]
	ldr r0, _0823BC6C @ =0x030047D0
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #0x1e]
_0823BC66:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0823BC6C: .4byte 0x030047D0

	thumb_func_start FUN_0823bc70
FUN_0823bc70: @ 0x0823BC70
	push {lr}
	adds r2, r0, #0
	ldr r0, _0823BC8C @ =0x030047D0
	ldr r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	beq _0823BCA2
	movs r0, #1
	strh r0, [r1, #0x1c]
	cmp r2, #1
	bgt _0823BC90
	adds r1, #0x68
	movs r0, #0
	b _0823BC9A
	.align 2, 0
_0823BC8C: .4byte 0x030047D0
_0823BC90:
	adds r0, r1, #0
	adds r0, #0x6a
	strh r2, [r0]
	adds r1, #0x68
	movs r0, #5
_0823BC9A:
	strh r0, [r1]
	ldr r1, [r3]
	movs r0, #0
	strh r0, [r1, #0x1e]
_0823BCA2:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0823bca8
FUN_0823bca8: @ 0x0823BCA8
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _0823BCC0 @ =0x030047D0
	ldr r2, [r0]
	adds r4, r0, #0
	cmp r2, #0
	beq _0823BCDC
	cmp r3, #1
	bgt _0823BCC4
	movs r0, #0
	strh r0, [r2, #0x1c]
	b _0823BCD6
	.align 2, 0
_0823BCC0: .4byte 0x030047D0
_0823BCC4:
	movs r0, #1
	strh r0, [r2, #0x1c]
	adds r1, r2, #0
	adds r1, #0x68
	movs r0, #6
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0x6a
	strh r3, [r0]
_0823BCD6:
	ldr r1, [r4]
	movs r0, #0
	strh r0, [r1, #0x1e]
_0823BCDC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0823bce4
FUN_0823bce4: @ 0x0823BCE4
	push {lr}
	adds r2, r0, #0
	ldr r0, _0823BD10 @ =0x030047D0
	ldr r3, [r0]
	cmp r3, #0
	beq _0823BD0A
	adds r0, r3, #0
	adds r0, #0x9c
	str r2, [r0]
	adds r0, #4
	str r1, [r0]
	movs r2, #0
	movs r0, #1
	strh r0, [r3, #0x1c]
	adds r1, r3, #0
	adds r1, #0x68
	movs r0, #7
	strh r0, [r1]
	strh r2, [r3, #0x1e]
_0823BD0A:
	pop {r0}
	bx r0
	.align 2, 0
_0823BD10: .4byte 0x030047D0

	thumb_func_start FUN_0823bd14
FUN_0823bd14: @ 0x0823BD14
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r3, r1, #0
	adds r5, r2, #0
	ldr r0, _0823BD58 @ =0x030047D0
	ldr r2, [r0]
	adds r4, r0, #0
	cmp r2, #0
	beq _0823BD90
	ldr r0, _0823BD5C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0823BD90
	cmp r3, #0
	bne _0823BD60
	cmp r5, #1
	bne _0823BD60
	adds r0, r2, #0
	adds r0, #0x84
	strb r3, [r0]
	ldr r0, [r4]
	adds r0, #0x85
	strb r3, [r0]
	ldr r0, [r4]
	adds r1, r0, #0
	adds r1, #0x86
	strh r3, [r1]
	adds r0, #0x88
	strh r3, [r0]
	b _0823BD8A
	.align 2, 0
_0823BD58: .4byte 0x030047D0
_0823BD5C: .4byte 0x030047A4
_0823BD60:
	ldr r0, [r4]
	adds r0, #0x84
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r4]
	mov ip, r0
	mov r1, ip
	adds r1, #0x88
	strh r6, [r1]
	adds r0, #0x8a
	strh r3, [r0]
	lsls r0, r3, #0x10
	cmp r0, #0
	bne _0823BD84
	ldrh r1, [r1]
	mov r0, ip
	adds r0, #0x86
	strh r1, [r0]
_0823BD84:
	ldr r0, [r4]
	adds r0, #0x85
	strb r5, [r0]
_0823BD8A:
	ldr r1, [r4]
	movs r0, #0
	strh r0, [r1, #0x1e]
_0823BD90:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0823bd98
FUN_0823bd98: @ 0x0823BD98
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	cmp r4, #0
	beq _0823BDF0
	movs r5, #1
	strh r5, [r4, #0x1e]
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _0823BDCC
	bl FUN_082316bc
	add r2, sp, #4
	mov r1, sp
	bl VM_Step
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [sp, #4]
	str r0, [r1]
	subs r1, #2
	movs r0, #0
	strh r0, [r1]
	b _0823BDF0
_0823BDCC:
	movs r0, #0x52
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _0823BDEA
	bl fetch_082316e4
	adds r1, r4, #0
	adds r1, #0x98
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0x96
	strh r5, [r0]
	b _0823BDF0
_0823BDEA:
	adds r0, r4, #0
	adds r0, #0x98
	str r1, [r0]
_0823BDF0:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
_0823BDF8:
	.byte 0x00, 0xB5, 0xFF, 0xF7, 0x55, 0xFE, 0x03, 0x48
	.byte 0x00, 0x68, 0xFF, 0xF7, 0xC9, 0xFF, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0xD0, 0x47, 0x00, 0x03

	thumb_func_start FUN_0823be10
FUN_0823be10: @ 0x0823BE10
	push {r4, lr}
	sub sp, #8
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0823BE5E
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0823BE68 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	ldr r2, _0823BE6C @ =0x0000FFFF
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
	mov r0, sp
	bl FUN_0823bac8
	ldr r0, _0823BE70 @ =0x030047D0
	ldr r0, [r0]
	bl FUN_0823bd98
_0823BE5E:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0823BE68: .4byte 0xFFFF0000
_0823BE6C: .4byte 0x0000FFFF
_0823BE70: .4byte 0x030047D0

	thumb_func_start FUN_0823be74
FUN_0823be74: @ 0x0823BE74
	push {r4, r5, lr}
	sub sp, #8
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _0823BED4
	bl fetch_082316e4
	adds r5, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0823BED4
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0823BEDC @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	ldr r2, _0823BEE0 @ =0x0000FFFF
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
	adds r0, r5, #0
	mov r1, sp
	bl FUN_0823bb7c
	ldr r0, _0823BEE4 @ =0x030047D0
	ldr r0, [r0]
	bl FUN_0823bd98
_0823BED4:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0823BEDC: .4byte 0xFFFF0000
_0823BEE0: .4byte 0x0000FFFF
_0823BEE4: .4byte 0x030047D0

	thumb_func_start FUN_0823bee8
FUN_0823bee8: @ 0x0823BEE8
	push {r4, r5, lr}
	sub sp, #8
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _0823BF5E
	bl fetch_082316e4
	adds r5, r0, #0
	movs r0, #0x6f
	bl prepare_08231510
	cmp r0, #0
	beq _0823BF44
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0823BF3C @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	ldr r2, _0823BF40 @ =0x0000FFFF
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
	b _0823BF4E
	.align 2, 0
_0823BF3C: .4byte 0xFFFF0000
_0823BF40: .4byte 0x0000FFFF
_0823BF44:
	ldr r1, _0823BF68 @ =0xFFFF0000
	str r0, [sp]
	ldr r0, [sp, #4]
	ands r0, r1
	str r0, [sp, #4]
_0823BF4E:
	adds r0, r5, #0
	mov r1, sp
	bl FUN_0823bbd4
	ldr r0, _0823BF6C @ =0x030047D0
	ldr r0, [r0]
	bl FUN_0823bd98
_0823BF5E:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0823BF68: .4byte 0xFFFF0000
_0823BF6C: .4byte 0x030047D0

	thumb_func_start FUN_0823bf70
FUN_0823bf70: @ 0x0823BF70
	push {r4, r5, r6, lr}
	sub sp, #8
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _0823BFF8
	bl fetch_082316e4
	adds r6, r0, #0
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _0823BFF8
	bl fetch_082316e4
	adds r5, r0, #0
	movs r0, #0x6f
	bl prepare_08231510
	cmp r0, #0
	beq _0823BFDC
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0823BFD4 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	ldr r2, _0823BFD8 @ =0x0000FFFF
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
	b _0823BFE6
	.align 2, 0
_0823BFD4: .4byte 0xFFFF0000
_0823BFD8: .4byte 0x0000FFFF
_0823BFDC:
	ldr r1, _0823C000 @ =0xFFFF0000
	str r0, [sp]
	ldr r0, [sp, #4]
	ands r0, r1
	str r0, [sp, #4]
_0823BFE6:
	adds r0, r5, #0
	adds r1, r6, #0
	mov r2, sp
	bl FUN_0823bc14
	ldr r0, _0823C004 @ =0x030047D0
	ldr r0, [r0]
	bl FUN_0823bd98
_0823BFF8:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0823C000: .4byte 0xFFFF0000
_0823C004: .4byte 0x030047D0

	thumb_func_start FUN_0823c008
FUN_0823c008: @ 0x0823C008
	push {lr}
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _0823C024
	bl fetch_082316e4
	bl FUN_0823bc70
	ldr r0, _0823C028 @ =0x030047D0
	ldr r0, [r0]
	bl FUN_0823bd98
_0823C024:
	pop {r0}
	bx r0
	.align 2, 0
_0823C028: .4byte 0x030047D0

	thumb_func_start FUN_0823c02c
FUN_0823c02c: @ 0x0823C02C
	push {lr}
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _0823C048
	bl fetch_082316e4
	bl FUN_0823bca8
	ldr r0, _0823C04C @ =0x030047D0
	ldr r0, [r0]
	bl FUN_0823bd98
_0823C048:
	pop {r0}
	bx r0
	.align 2, 0
_0823C04C: .4byte 0x030047D0

	thumb_func_start FUN_0823c050
FUN_0823c050: @ 0x0823C050
	push {r4, r5, lr}
	movs r0, #0x77
	bl prepare_08231510
	cmp r0, #0
	beq _0823C09A
	bl fetch_082316e4
	adds r5, r0, #0
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _0823C074
	bl fetch_082316e4
	adds r4, r0, #0
	b _0823C076
_0823C074:
	movs r4, #1
_0823C076:
	movs r0, #0x4e
	bl prepare_08231510
	cmp r0, #0
	beq _0823C088
	bl fetch_082316e4
	adds r2, r0, #0
	b _0823C08A
_0823C088:
	movs r2, #0
_0823C08A:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823bd14
	ldr r0, _0823C0A0 @ =0x030047D0
	ldr r0, [r0]
	bl FUN_0823bd98
_0823C09A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0823C0A0: .4byte 0x030047D0

	thumb_func_start FUN_0823c0a4
FUN_0823c0a4: @ 0x0823C0A4
	movs r1, #2
	strh r1, [r0, #0x1e]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0823c0ac
FUN_0823c0ac: @ 0x0823C0AC
	push {lr}
	adds r0, #0x20
	movs r1, #1
	bl FUN_08022488
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0823c0bc
FUN_0823c0bc: @ 0x0823C0BC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	adds r7, r5, #0
	adds r7, #0x20
	movs r6, #0
	ldr r0, _0823C0D4 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r5, #0
	adds r0, #0x26
	b _0823C1DE
	.align 2, 0
_0823C0D4: .4byte 0x03002B4C
_0823C0D8:
	ldr r0, _0823C108 @ =0x03002B4C
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
	cmp r0, #5
	bhi _0823C1D4
	lsls r0, r0, #2
	ldr r1, _0823C10C @ =_0823C110
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0823C108: .4byte 0x03002B4C
_0823C10C: .4byte _0823C110
_0823C110: @ jump table
	.4byte _0823C128 @ case 0
	.4byte _0823C12E @ case 1
	.4byte _0823C16C @ case 2
	.4byte _0823C1A4 @ case 3
	.4byte _0823C1AE @ case 4
	.4byte _0823C1C6 @ case 5
_0823C128:
	bl FUN_0823baa8
	b _0823C156
_0823C12E:
	ldrh r0, [r4, #8]
	ldr r3, _0823C164 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r3
	orrs r1, r0
	str r1, [sp]
	ldrh r2, [r4, #0xa]
	lsls r2, r2, #0x10
	ldr r0, _0823C168 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp]
	ldrh r1, [r4, #0xc]
	ldr r0, [sp, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #4]
	mov r0, sp
	bl FUN_0823bac8
_0823C156:
	adds r0, r5, #0
	bl FUN_0823c0a4
	adds r0, r5, #0
	bl FUN_0823c0ac
	b _0823C1D4
	.align 2, 0
_0823C164: .4byte 0xFFFF0000
_0823C168: .4byte 0x0000FFFF
_0823C16C:
	ldrh r0, [r4, #8]
	ldr r3, _0823C19C @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #8]
	ldrh r2, [r4, #0xa]
	lsls r2, r2, #0x10
	ldr r0, _0823C1A0 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #8]
	ldrh r2, [r4, #0xc]
	add r1, sp, #8
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	movs r2, #0xe
	ldrsh r0, [r4, r2]
	bl FUN_0823bb7c
	b _0823C1BE
	.align 2, 0
_0823C19C: .4byte 0xFFFF0000
_0823C1A0: .4byte 0x0000FFFF
_0823C1A4:
	movs r3, #8
	ldrsh r0, [r4, r3]
	bl FUN_0823bc70
	b _0823C1BE
_0823C1AE:
	movs r1, #8
	ldrsh r0, [r4, r1]
	movs r2, #0xa
	ldrsh r1, [r4, r2]
	movs r3, #0xc
	ldrsh r2, [r4, r3]
	bl FUN_0823bd14
_0823C1BE:
	adds r0, r5, #0
	bl FUN_0823c0a4
	b _0823C1D4
_0823C1C6:
	movs r1, #8
	ldrsh r0, [r4, r1]
	bl FUN_0823bca8
	adds r0, r5, #0
	bl FUN_0823c0a4
_0823C1D4:
	adds r6, #1
	ldr r0, _0823C1F4 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r7, #6
_0823C1DE:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r6, r0
	bge _0823C1EA
	b _0823C0D8
_0823C1EA:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0823C1F4: .4byte 0x03002B4C

	thumb_func_start FUN_0823c1f8
FUN_0823c1f8: @ 0x0823C1F8
	push {lr}
	adds r1, r0, #0
	adds r1, #0x98
	ldr r2, [r1]
	cmp r2, #0
	beq _0823C224
	adds r0, #0x96
	ldrh r0, [r0]
	cmp r0, #0
	bne _0823C218
	str r0, [r1]
	adds r0, r2, #0
	movs r1, #0
	bl FUN_08231b58
	b _0823C224
_0823C218:
	movs r0, #0
	str r0, [r1]
	adds r0, r2, #0
	movs r1, #0
	bl FUN_082318ac
_0823C224:
	pop {r0}
	bx r0

	thumb_func_start FUN_0823c228
FUN_0823c228: @ 0x0823C228
	push {lr}
	ldrh r1, [r0, #0x1e]
	cmp r1, #1
	bne _0823C236
	bl FUN_0823c1f8
	b _0823C23E
_0823C236:
	cmp r1, #2
	bne _0823C23E
	bl FUN_0823c0ac
_0823C23E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0823c244
FUN_0823c244: @ 0x0823C244
	push {lr}
	ldr r0, _0823C25C @ =0x030047D0
	ldr r0, [r0]
	cmp r0, #0
	beq _0823C256
	adds r1, r0, #0
	adds r1, #0x8c
	movs r0, #0
	strh r0, [r1]
_0823C256:
	pop {r0}
	bx r0
	.align 2, 0
_0823C25C: .4byte 0x030047D0

	thumb_func_start FUN_0823c260
FUN_0823c260: @ 0x0823C260
	push {r4, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	ldr r0, _0823C2C4 @ =0x030047D0
	ldr r2, [r0]
	cmp r2, #0
	beq _0823C2BE
	ldrh r0, [r3, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	ldrh r1, [r3]
	subs r1, r1, r0
	adds r0, r2, #0
	adds r0, #0x8e
	strh r1, [r0]
	ldrh r0, [r3, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	ldrh r1, [r3, #4]
	subs r1, r1, r0
	adds r0, r2, #0
	adds r0, #0x90
	strh r1, [r0]
	ldrh r0, [r4, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	ldrh r1, [r4]
	subs r1, r1, r0
	adds r0, r2, #0
	adds r0, #0x92
	strh r1, [r0]
	ldrh r0, [r4, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	ldrh r1, [r4, #4]
	subs r1, r1, r0
	adds r0, r2, #0
	adds r0, #0x94
	strh r1, [r0]
	adds r1, r2, #0
	adds r1, #0x8c
	movs r0, #1
	strh r0, [r1]
	ldr r1, _0823C2C8 @ =0x03003540
	adds r0, r2, #0
	bl FUN_0823b840
_0823C2BE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0823C2C4: .4byte 0x030047D0
_0823C2C8: .4byte 0x03003540

	thumb_func_start FUN_0823c2cc
FUN_0823c2cc: @ 0x0823C2CC
	push {r4, r5, lr}
	sub sp, #0x10
	movs r0, #0x49
	bl prepare_08231510
	cmp r0, #0
	beq _0823C34C
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0823C354 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	ldr r5, _0823C358 @ =0x0000FFFF
	ldr r1, [sp]
	ands r1, r5
	orrs r1, r0
	str r1, [sp]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _0823C34C
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r5
	orrs r1, r0
	str r1, [sp, #8]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r1, sp, #8
	ldr r2, [r1, #4]
	ands r2, r4
	orrs r2, r0
	str r2, [r1, #4]
	mov r0, sp
	bl FUN_0823c260
_0823C34C:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0823C354: .4byte 0xFFFF0000
_0823C358: .4byte 0x0000FFFF

	thumb_func_start FUN_0823c35c
FUN_0823c35c: @ 0x0823C35C
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	ldr r0, _0823C3B8 @ =0x030047D0
	ldr r3, [r0]
	cmp r3, #0
	beq _0823C3B0
	ldrh r0, [r2, #4]
	ldrh r1, [r2]
	subs r0, r0, r1
	adds r1, r3, #0
	adds r1, #0x8e
	strh r0, [r1]
	ldrh r0, [r2]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	adds r1, r3, #0
	adds r1, #0x90
	strh r0, [r1]
	ldrh r0, [r4, #4]
	ldrh r1, [r4]
	subs r0, r0, r1
	adds r1, r3, #0
	adds r1, #0x92
	strh r0, [r1]
	ldrh r0, [r4]
	ldrh r1, [r4, #4]
	adds r0, r0, r1
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	adds r1, r3, #0
	adds r1, #0x94
	strh r0, [r1]
	subs r1, #8
	movs r0, #2
	strh r0, [r1]
	ldr r1, _0823C3BC @ =0x03003540
	adds r0, r3, #0
	bl FUN_0823b840
_0823C3B0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0823C3B8: .4byte 0x030047D0
_0823C3BC: .4byte 0x03003540

	thumb_func_start FUN_0823c3c0
FUN_0823c3c0: @ 0x0823C3C0
	push {r4, r5, lr}
	sub sp, #0x10
	movs r0, #0x49
	bl prepare_08231510
	cmp r0, #0
	beq _0823C440
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0823C448 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	ldr r5, _0823C44C @ =0x0000FFFF
	ldr r1, [sp]
	ands r1, r5
	orrs r1, r0
	str r1, [sp]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _0823C440
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r5
	orrs r1, r0
	str r1, [sp, #8]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r1, sp, #8
	ldr r2, [r1, #4]
	ands r2, r4
	orrs r2, r0
	str r2, [r1, #4]
	mov r0, sp
	bl FUN_0823c35c
_0823C440:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0823C448: .4byte 0xFFFF0000
_0823C44C: .4byte 0x0000FFFF

	thumb_func_start FUN_0823c450
FUN_0823c450: @ 0x0823C450
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r0, #0x54
	adds r0, r0, r6
	mov r8, r0
	ldrh r0, [r0]
	cmp r0, #1
	beq _0823C518
	cmp r0, #1
	bgt _0823C46E
	cmp r0, #0
	beq _0823C47A
	b _0823C610
_0823C46E:
	cmp r0, #2
	beq _0823C538
	cmp r0, #3
	bne _0823C478
	b _0823C5A4
_0823C478:
	b _0823C610
_0823C47A:
	ldr r0, _0823C4C4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0823C4D0
	ldr r0, _0823C4C8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0823C492
	b _0823C610
_0823C492:
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _0823C49C
	b _0823C610
_0823C49C:
	ldr r1, _0823C4CC @ =0x03002BE0
	lsls r0, r0, #2
	adds r2, r0, r1
	ldr r0, [r2]
	cmp r0, #0
	bne _0823C4AA
	b _0823C610
_0823C4AA:
	ldrh r1, [r0, #0x2c]
	adds r0, r6, #0
	adds r0, #0x58
	strh r1, [r0]
	ldr r0, [r2]
	ldrh r0, [r0, #0x2e]
	adds r0, #0x96
	adds r1, r6, #0
	adds r1, #0x5a
	strh r0, [r1]
	ldr r0, [r2]
	ldrh r1, [r0, #0x30]
	b _0823C50C
	.align 2, 0
_0823C4C4: .4byte 0x030047A4
_0823C4C8: .4byte 0x03002C68
_0823C4CC: .4byte 0x03002BE0
_0823C4D0:
	ldr r0, _0823C4EC @ =0x03003540
	movs r3, #0x12
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bne _0823C4F4
	ldr r0, _0823C4F0 @ =0x030046A0
	ldr r1, [r0]
	ldrh r2, [r1, #0x30]
	adds r0, r6, #0
	adds r0, #0x58
	strh r2, [r0]
	ldrh r0, [r1, #0x32]
	adds r0, #0x96
	b _0823C504
	.align 2, 0
_0823C4EC: .4byte 0x03003540
_0823C4F0: .4byte 0x030046A0
_0823C4F4:
	ldr r0, _0823C514 @ =0x030046A0
	ldr r1, [r0]
	ldrh r2, [r1, #0x30]
	adds r0, r6, #0
	adds r0, #0x58
	strh r2, [r0]
	ldrh r0, [r1, #0x32]
	subs r0, #0x96
_0823C504:
	adds r2, r6, #0
	adds r2, #0x5a
	strh r0, [r2]
	ldrh r1, [r1, #0x34]
_0823C50C:
	adds r0, r6, #0
	adds r0, #0x5c
	strh r1, [r0]
	b _0823C610
	.align 2, 0
_0823C514: .4byte 0x030046A0
_0823C518:
	adds r0, r6, #0
	adds r0, #0x60
	ldrh r1, [r0]
	subs r0, #8
	strh r1, [r0]
	adds r0, #0xa
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0x5a
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0x64
	ldrh r1, [r0]
	subs r0, #8
	strh r1, [r0]
	b _0823C610
_0823C538:
	adds r4, r6, #0
	adds r4, #0x58
	movs r0, #0
	ldrsh r2, [r4, r0]
	adds r5, r6, #0
	adds r5, #0x56
	ldrh r1, [r5]
	subs r0, r1, #1
	muls r0, r2, r0
	adds r2, r6, #0
	adds r2, #0x60
	movs r3, #0
	ldrsh r2, [r2, r3]
	adds r0, r0, r2
	bl Div
	strh r0, [r4]
	adds r4, #2
	movs r0, #0
	ldrsh r2, [r4, r0]
	ldrh r1, [r5]
	subs r0, r1, #1
	muls r0, r2, r0
	adds r2, r6, #0
	adds r2, #0x62
	movs r3, #0
	ldrsh r2, [r2, r3]
	adds r0, r0, r2
	bl Div
	strh r0, [r4]
	adds r4, #2
	movs r0, #0
	ldrsh r2, [r4, r0]
	ldrh r1, [r5]
	subs r0, r1, #1
	muls r0, r2, r0
	adds r2, r6, #0
	adds r2, #0x64
	movs r3, #0
	ldrsh r2, [r2, r3]
	adds r0, r0, r2
	bl Div
	strh r0, [r4]
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _0823C610
	movs r0, #1
	b _0823C60C
_0823C5A4:
	adds r5, r6, #0
	adds r5, #0x58
	movs r3, #0
	ldrsh r2, [r5, r3]
	adds r7, r6, #0
	adds r7, #0x56
	ldrh r1, [r7]
	subs r0, r1, #1
	muls r0, r2, r0
	ldr r4, _0823C61C @ =0x030046A0
	ldr r2, [r4]
	movs r3, #0x30
	ldrsh r2, [r2, r3]
	adds r0, r0, r2
	bl Div
	strh r0, [r5]
	adds r5, #2
	movs r0, #0
	ldrsh r2, [r5, r0]
	ldrh r1, [r7]
	subs r0, r1, #1
	muls r0, r2, r0
	ldr r2, [r4]
	movs r3, #0x32
	ldrsh r2, [r2, r3]
	adds r0, r0, r2
	adds r0, #0x96
	bl Div
	strh r0, [r5]
	adds r5, #2
	movs r0, #0
	ldrsh r2, [r5, r0]
	ldrh r1, [r7]
	subs r0, r1, #1
	muls r0, r2, r0
	ldr r2, [r4]
	movs r3, #0x34
	ldrsh r2, [r2, r3]
	adds r0, r0, r2
	bl Div
	strh r0, [r5]
	ldrh r0, [r7]
	subs r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _0823C610
	movs r0, #0
_0823C60C:
	mov r1, r8
	strh r0, [r1]
_0823C610:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0823C61C: .4byte 0x030046A0

	thumb_func_start FUN_0823c620
FUN_0823c620: @ 0x0823C620
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r0, #0x68
	ldrh r0, [r0]
	cmp r0, #7
	bls _0823C632
	b _0823C918
_0823C632:
	lsls r0, r0, #2
	ldr r1, _0823C63C @ =_0823C640
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0823C63C: .4byte _0823C640
_0823C640: @ jump table
	.4byte _0823C660 @ case 0
	.4byte _0823C698 @ case 1
	.4byte _0823C6B8 @ case 2
	.4byte _0823C72C @ case 3
	.4byte _0823C76C @ case 4
	.4byte _0823C814 @ case 5
	.4byte _0823C888 @ case 6
	.4byte _0823C8FC @ case 7
_0823C660:
	ldr r2, _0823C678 @ =0x03003540
	movs r1, #0x12
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bne _0823C680
	ldr r0, _0823C67C @ =0x030046A0
	ldr r1, [r0]
	ldrh r0, [r1, #0x30]
	strh r0, [r2]
	ldrh r0, [r1, #0x32]
	adds r0, #0x96
	b _0823C68C
	.align 2, 0
_0823C678: .4byte 0x03003540
_0823C67C: .4byte 0x030046A0
_0823C680:
	ldr r0, _0823C694 @ =0x030046A0
	ldr r1, [r0]
	ldrh r0, [r1, #0x30]
	strh r0, [r2]
	ldrh r0, [r1, #0x32]
	subs r0, #0x96
_0823C68C:
	strh r0, [r2, #2]
	ldrh r0, [r1, #0x34]
	strh r0, [r2, #4]
	b _0823C918
	.align 2, 0
_0823C694: .4byte 0x030046A0
_0823C698:
	ldr r1, _0823C6B4 @ =0x03003540
	adds r0, r6, #0
	adds r0, #0x6c
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0x6e
	ldrh r0, [r0]
	strh r0, [r1, #2]
	adds r0, r6, #0
	adds r0, #0x70
	ldrh r0, [r0]
	strh r0, [r1, #4]
	b _0823C918
	.align 2, 0
_0823C6B4: .4byte 0x03003540
_0823C6B8:
	ldr r4, _0823C728 @ =0x03003540
	movs r3, #0
	ldrsh r2, [r4, r3]
	adds r5, r6, #0
	adds r5, #0x6a
	ldrh r1, [r5]
	subs r0, r1, #1
	muls r0, r2, r0
	adds r2, r6, #0
	adds r2, #0x6c
	movs r3, #0
	ldrsh r2, [r2, r3]
	adds r0, r0, r2
	bl Div
	strh r0, [r4]
	movs r0, #2
	ldrsh r2, [r4, r0]
	ldrh r1, [r5]
	subs r0, r1, #1
	muls r0, r2, r0
	adds r2, r6, #0
	adds r2, #0x6e
	movs r3, #0
	ldrsh r2, [r2, r3]
	adds r0, r0, r2
	bl Div
	strh r0, [r4, #2]
	movs r0, #4
	ldrsh r2, [r4, r0]
	ldrh r1, [r5]
	subs r0, r1, #1
	muls r0, r2, r0
	adds r2, r6, #0
	adds r2, #0x70
	movs r3, #0
	ldrsh r2, [r2, r3]
	adds r0, r0, r2
	bl Div
	strh r0, [r4, #4]
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _0823C71C
	b _0823C918
_0823C71C:
	adds r1, r6, #0
	adds r1, #0x68
	movs r0, #1
	strh r0, [r1]
	b _0823C8EE
	.align 2, 0
_0823C728: .4byte 0x03003540
_0823C72C:
	adds r0, r6, #0
	adds r0, #0x7c
	ldrh r0, [r0]
	bl FUN_0823b2d0
	adds r5, r0, #0
	cmp r5, #0
	bne _0823C73E
	b _0823C918
_0823C73E:
	ldr r1, _0823C768 @ =0x03003540
	adds r0, r6, #0
	adds r0, #0x74
	ldrh r0, [r0]
	ldrh r2, [r5, #8]
	adds r0, r0, r2
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0x76
	ldrh r0, [r0]
	ldrh r3, [r5, #0xa]
	adds r0, r0, r3
	strh r0, [r1, #2]
	adds r0, r6, #0
	adds r0, #0x78
	ldrh r0, [r0]
	ldrh r5, [r5, #0xc]
	adds r0, r0, r5
	strh r0, [r1, #4]
	b _0823C918
	.align 2, 0
_0823C768: .4byte 0x03003540
_0823C76C:
	adds r0, r6, #0
	adds r0, #0x7c
	ldrh r0, [r0]
	bl FUN_0823b2d0
	adds r5, r0, #0
	cmp r5, #0
	bne _0823C77E
	b _0823C918
_0823C77E:
	ldr r4, _0823C810 @ =0x03003540
	movs r0, #0
	ldrsh r2, [r4, r0]
	adds r7, r6, #0
	adds r7, #0x6a
	ldrh r1, [r7]
	subs r0, r1, #1
	muls r0, r2, r0
	movs r3, #8
	ldrsh r2, [r5, r3]
	mov ip, r2
	movs r2, #0x74
	adds r2, r2, r6
	mov r8, r2
	movs r3, #0
	ldrsh r2, [r2, r3]
	mov r8, r2
	mov r2, ip
	add r2, r8
	adds r0, r0, r2
	bl Div
	strh r0, [r4]
	movs r0, #2
	ldrsh r2, [r4, r0]
	ldrh r1, [r7]
	subs r0, r1, #1
	muls r0, r2, r0
	movs r3, #0xa
	ldrsh r2, [r5, r3]
	mov ip, r2
	movs r2, #0x76
	adds r2, r2, r6
	mov r8, r2
	movs r3, #0
	ldrsh r2, [r2, r3]
	mov r8, r2
	mov r2, ip
	add r2, r8
	adds r0, r0, r2
	bl Div
	strh r0, [r4, #2]
	movs r0, #4
	ldrsh r2, [r4, r0]
	ldrh r1, [r7]
	subs r0, r1, #1
	muls r0, r2, r0
	movs r3, #0xc
	ldrsh r2, [r5, r3]
	adds r3, r6, #0
	adds r3, #0x78
	movs r5, #0
	ldrsh r3, [r3, r5]
	adds r2, r2, r3
	adds r0, r0, r2
	bl Div
	strh r0, [r4, #4]
	ldrh r0, [r7]
	subs r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _0823C804
	b _0823C918
_0823C804:
	adds r1, r6, #0
	adds r1, #0x68
	movs r0, #3
	strh r0, [r1]
	b _0823C8EE
	.align 2, 0
_0823C810: .4byte 0x03003540
_0823C814:
	ldr r4, _0823C880 @ =0x03003540
	movs r0, #0
	ldrsh r2, [r4, r0]
	adds r7, r6, #0
	adds r7, #0x6a
	ldrh r1, [r7]
	subs r0, r1, #1
	muls r0, r2, r0
	ldr r5, _0823C884 @ =0x030046A0
	ldr r2, [r5]
	movs r3, #0x30
	ldrsh r2, [r2, r3]
	adds r0, r0, r2
	bl Div
	strh r0, [r4]
	movs r0, #2
	ldrsh r2, [r4, r0]
	ldrh r1, [r7]
	subs r0, r1, #1
	muls r0, r2, r0
	ldr r2, [r5]
	movs r3, #0x32
	ldrsh r2, [r2, r3]
	adds r0, r0, r2
	adds r0, #0x96
	bl Div
	strh r0, [r4, #2]
	movs r0, #4
	ldrsh r2, [r4, r0]
	ldrh r1, [r7]
	subs r0, r1, #1
	muls r0, r2, r0
	ldr r2, [r5]
	movs r3, #0x34
	ldrsh r2, [r2, r3]
	adds r0, r0, r2
	bl Div
	strh r0, [r4, #4]
	ldrh r0, [r7]
	subs r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _0823C918
	adds r1, r6, #0
	adds r1, #0x68
	movs r0, #0
	strh r0, [r1]
	b _0823C8EE
	.align 2, 0
_0823C880: .4byte 0x03003540
_0823C884: .4byte 0x030046A0
_0823C888:
	ldr r4, _0823C8F8 @ =0x03003540
	movs r5, #0
	ldrsh r2, [r4, r5]
	adds r5, r6, #0
	adds r5, #0x6a
	ldrh r1, [r5]
	subs r0, r1, #1
	muls r0, r2, r0
	adds r2, r6, #0
	adds r2, #0x58
	movs r3, #0
	ldrsh r2, [r2, r3]
	adds r0, r0, r2
	bl Div
	strh r0, [r4]
	movs r0, #2
	ldrsh r2, [r4, r0]
	ldrh r1, [r5]
	subs r0, r1, #1
	muls r0, r2, r0
	adds r2, r6, #0
	adds r2, #0x5a
	movs r3, #0
	ldrsh r2, [r2, r3]
	adds r0, r0, r2
	bl Div
	strh r0, [r4, #2]
	movs r0, #4
	ldrsh r2, [r4, r0]
	ldrh r1, [r5]
	subs r0, r1, #1
	muls r0, r2, r0
	adds r2, r6, #0
	adds r2, #0x5c
	movs r3, #0
	ldrsh r2, [r2, r3]
	adds r0, r0, r2
	bl Div
	strh r0, [r4, #4]
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _0823C918
	movs r0, #0
	strh r0, [r6, #0x1c]
_0823C8EE:
	adds r0, r6, #0
	bl FUN_0823c228
	b _0823C918
	.align 2, 0
_0823C8F8: .4byte 0x03003540
_0823C8FC:
	adds r0, r6, #0
	adds r0, #0xa0
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, #0
	beq _0823C918
	ldr r2, _0823C924 @ =0x03003540
	adds r0, r6, #0
	adds r0, #0x9c
	ldr r0, [r0]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
_0823C918:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0823C924: .4byte 0x03003540

	thumb_func_start FUN_0823c928
FUN_0823c928: @ 0x0823C928
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r1, #0x84
	adds r1, r1, r7
	mov r8, r1
	ldrb r1, [r1]
	cmp r1, #0
	beq _0823C9A6
	adds r4, r7, #0
	adds r4, #0x8a
	ldrh r1, [r4]
	cmp r1, #0
	beq _0823C99A
	adds r5, r7, #0
	adds r5, #0x86
	ldrh r0, [r5]
	adds r6, r7, #0
	adds r6, #0x88
	muls r0, r1, r0
	ldrh r2, [r6]
	adds r0, r0, r2
	adds r1, #1
	bl Div
	adds r1, r0, #0
	movs r3, #0
	strh r1, [r5]
	adds r2, r7, #0
	adds r2, #0x7e
	strh r1, [r2]
	ldrh r1, [r4]
	subs r1, #1
	strh r1, [r4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0
	bne _0823C9A6
	adds r2, #7
	ldrb r0, [r2]
	cmp r0, #0
	beq _0823C98E
	mov r4, r8
	strb r3, [r4]
	strb r3, [r2]
	strh r1, [r5]
	strh r1, [r6]
	b _0823C992
_0823C98E:
	ldrh r0, [r6]
	strh r0, [r5]
_0823C992:
	adds r0, r7, #0
	bl FUN_0823c228
	b _0823C9A6
_0823C99A:
	adds r1, r7, #0
	adds r1, #0x86
	ldrh r1, [r1]
	adds r2, r7, #0
	adds r2, #0x7e
	strh r1, [r2]
_0823C9A6:
	movs r1, #0x7e
	adds r1, r1, r7
	mov sl, r1
	ldrh r2, [r1]
	cmp r2, #0
	beq _0823CA2C
	adds r0, r2, #0
	ldr r2, _0823CA1C @ =0x0203B400
	mov r8, r2
	ldr r4, _0823CA20 @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r5, _0823CA24 @ =0x000003FF
	ands r1, r5
	str r1, [r4]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	bl ModArm
	mov r2, sl
	ldrh r1, [r2]
	lsrs r1, r1, #1
	subs r0, r0, r1
	adds r6, r7, #0
	adds r6, #0x80
	movs r1, #0
	mov sb, r1
	strh r0, [r6]
	ldrh r0, [r2]
	ldr r1, [r4]
	adds r1, #1
	ands r1, r5
	str r1, [r4]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	bl ModArm
	adds r3, r0, #0
	mov r2, sl
	ldrh r1, [r2]
	lsrs r1, r1, #1
	subs r3, r3, r1
	adds r1, r7, #0
	adds r1, #0x82
	strh r3, [r1]
	ldr r2, _0823CA28 @ =0x03003540
	ldrh r1, [r6]
	ldrh r4, [r2]
	adds r1, r1, r4
	strh r1, [r2]
	ldrh r1, [r2, #4]
	adds r1, r1, r3
	strh r1, [r2, #4]
	mov r2, sb
	mov r1, sl
	b _0823CA34
	.align 2, 0
_0823CA1C: .4byte 0x0203B400
_0823CA20: .4byte 0x030046B8
_0823CA24: .4byte 0x000003FF
_0823CA28: .4byte 0x03003540
_0823CA2C:
	adds r1, r7, #0
	adds r1, #0x80
	strh r2, [r1]
	adds r1, #2
_0823CA34:
	strh r2, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0823ca44
FUN_0823ca44: @ 0x0823CA44
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _0823CA90 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0823CA5C
	adds r0, r4, #0
	bl FUN_0823c0bc
_0823CA5C:
	ldr r0, _0823CA94 @ =0x030044BC
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0823CAB0
	adds r0, r4, #0
	bl FUN_0823c450
	ldrh r0, [r4, #0x1c]
	cmp r0, #0
	bne _0823CA9C
	ldr r1, _0823CA98 @ =0x03003540
	adds r0, r4, #0
	adds r0, #0x58
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x5a
	ldrh r0, [r0]
	strh r0, [r1, #2]
	adds r0, r4, #0
	adds r0, #0x5c
	ldrh r0, [r0]
	strh r0, [r1, #4]
	b _0823CAA2
	.align 2, 0
_0823CA90: .4byte 0x030047A4
_0823CA94: .4byte 0x030044BC
_0823CA98: .4byte 0x03003540
_0823CA9C:
	adds r0, r4, #0
	bl FUN_0823c620
_0823CAA2:
	adds r0, r4, #0
	bl FUN_0823c928
	ldr r1, _0823CAD0 @ =0x03003540
	adds r0, r4, #0
	bl FUN_0823b840
_0823CAB0:
	ldr r5, _0823CAD4 @ =0x030047C8
	ldr r4, _0823CAD0 @ =0x03003540
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0823CAD8
	asrs r0, r0, #8
	b _0823CADE
	.align 2, 0
_0823CAD0: .4byte 0x03003540
_0823CAD4: .4byte 0x030047C8
_0823CAD8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0823CADE:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0823CAF0
	asrs r0, r0, #8
	b _0823CAF6
_0823CAF0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0823CAF6:
	adds r2, r0, #0
	movs r0, #2
	ldrsh r1, [r4, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0823CB0A
	asrs r1, r0, #8
	b _0823CB10
_0823CB0A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0823CB10:
	subs r0, r2, r1
	strh r0, [r5, #2]
	adds r0, r2, r1
	strh r0, [r5, #4]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0823cb20
FUN_0823cb20: @ 0x0823CB20
	push {lr}
	adds r2, r0, #0
	ldr r0, _0823CB44 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0823CB3A
	adds r0, r2, #0
	adds r0, #0x20
	bl FUN_08022428
_0823CB3A:
	ldr r1, _0823CB48 @ =0x030047D0
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_0823CB44: .4byte 0x030047A4
_0823CB48: .4byte 0x030047D0

	thumb_func_start FUN_0823cb4c
FUN_0823cb4c: @ 0x0823CB4C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	str r1, [r5, #0x18]
	movs r2, #0
	strh r2, [r5, #0x1c]
	adds r0, #0x54
	strh r2, [r0]
	ldr r0, _0823CBB4 @ =0x030046A0
	ldr r1, [r0]
	ldrh r0, [r1, #0x30]
	adds r4, r5, #0
	adds r4, #0x58
	strh r0, [r4]
	ldrh r0, [r1, #0x32]
	adds r0, #0x96
	movs r3, #0x5a
	adds r3, r3, r5
	mov ip, r3
	strh r0, [r3]
	ldrh r0, [r1, #0x34]
	adds r3, r5, #0
	adds r3, #0x5c
	strh r0, [r3]
	adds r0, r5, #0
	adds r0, #0x8c
	strh r2, [r0]
	ldr r1, _0823CBB8 @ =0x03003540
	ldrh r2, [r4]
	strh r2, [r1]
	mov r4, ip
	ldrh r0, [r4]
	strh r0, [r1, #2]
	ldrh r0, [r3]
	strh r0, [r1, #4]
	ldr r6, _0823CBBC @ =0x030047C8
	adds r7, r1, #0
	lsls r2, r2, #0x10
	asrs r3, r2, #0x11
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	mov r8, r7
	mov ip, r6
	cmp r0, #0
	blt _0823CBC0
	asrs r0, r0, #8
	b _0823CBC6
	.align 2, 0
_0823CBB4: .4byte 0x030046A0
_0823CBB8: .4byte 0x03003540
_0823CBBC: .4byte 0x030047C8
_0823CBC0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0823CBC6:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0823CBD8
	asrs r0, r0, #8
	b _0823CBDE
_0823CBD8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0823CBDE:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r7, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0823CBF2
	asrs r3, r0, #8
	b _0823CBF8
_0823CBF2:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r3, r0, #0
_0823CBF8:
	subs r0, r4, r3
	movs r2, #0
	movs r1, #0
	strh r0, [r6, #2]
	adds r0, r4, r3
	strh r0, [r6, #4]
	adds r0, r5, #0
	adds r0, #0x84
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	subs r0, #0xa
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	mov r6, ip
	mov r4, r8
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0823CC46
	asrs r0, r0, #8
	b _0823CC4C
_0823CC46:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0823CC4C:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0823CC5E
	asrs r0, r0, #8
	b _0823CC64
_0823CC5E:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0823CC64:
	adds r2, r0, #0
	movs r3, #2
	ldrsh r1, [r4, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0823CC78
	asrs r1, r0, #8
	b _0823CC7E
_0823CC78:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0823CC7E:
	subs r0, r2, r1
	strh r0, [r6, #2]
	adds r0, r2, r1
	strh r0, [r6, #4]
	ldr r0, _0823CCB0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0823CCA0
	adds r0, r5, #0
	adds r0, #0x20
	ldr r1, [r5, #0x18]
	movs r2, #6
	bl FUN_080223f4
_0823CCA0:
	ldr r0, _0823CCB4 @ =0x030047D0
	str r5, [r0]
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0823CCB0: .4byte 0x030047A4
_0823CCB4: .4byte 0x030047D0

	thumb_func_start FUN_0823ccb8
FUN_0823ccb8: @ 0x0823CCB8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0823CCF0 @ =0x030047D0
	ldr r0, [r0]
	cmp r0, #0
	bne _0823CCFE
	movs r0, #7
	movs r1, #0xa4
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0823CCFC
	ldr r1, _0823CCF4 @ =FUN_0823ca44
	ldr r2, _0823CCF8 @ =FUN_0823cb20
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0823cb4c
	cmp r0, #0
	bge _0823CCFC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0823CCFE
	.align 2, 0
_0823CCF0: .4byte 0x030047D0
_0823CCF4: .4byte FUN_0823ca44
_0823CCF8: .4byte FUN_0823cb20
_0823CCFC:
	adds r0, r4, #0
_0823CCFE:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0823cd04
FUN_0823cd04: @ 0x0823CD04
	ldr r0, _0823CD20 @ =0x030047A4
	movs r1, #0
	str r1, [r0]
	ldr r0, _0823CD24 @ =0x030047A0
	str r1, [r0]
	ldr r0, _0823CD28 @ =0x0300479C
	str r1, [r0]
	ldr r0, _0823CD2C @ =0x030047C0
	str r1, [r0]
	ldr r0, _0823CD30 @ =0x0300478C
	str r1, [r0]
	ldr r0, _0823CD34 @ =0x030047C4
	str r1, [r0]
	bx lr
	.align 2, 0
_0823CD20: .4byte 0x030047A4
_0823CD24: .4byte 0x030047A0
_0823CD28: .4byte 0x0300479C
_0823CD2C: .4byte 0x030047C0
_0823CD30: .4byte 0x0300478C
_0823CD34: .4byte 0x030047C4

	thumb_func_start FUN_0823cd38
FUN_0823cd38: @ 0x0823CD38
	ldr r0, _0823CD44 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r0, r1
	bx lr
	.align 2, 0
_0823CD44: .4byte 0x030046A0

	thumb_func_start FUN_0823cd48
FUN_0823cd48: @ 0x0823CD48
	push {r4, lr}
	sub sp, #4
	bl FUN_0823cd38
	adds r4, r0, #0
	movs r0, #0
	str r0, [sp]
	ldr r2, _0823CD98 @ =0x05000004
	mov r0, sp
	adds r1, r4, #0
	bl CpuSet
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _0823CD9C
	bl FUN_082316bc
	bl FUN_08231654
	adds r1, r0, #0
	cmp r1, #0
	beq _0823CDB6
	movs r3, #0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0823CDB6
	adds r2, r1, #0
_0823CD82:
	adds r0, r4, r3
	ldrb r1, [r2]
	strb r1, [r0]
	adds r2, #1
	adds r3, #1
	ldrb r0, [r2]
	cmp r0, #0
	beq _0823CDB6
	cmp r3, #0xf
	ble _0823CD82
	b _0823CDB6
	.align 2, 0
_0823CD98: .4byte 0x05000004
_0823CD9C:
	movs r1, #0x80
	strb r1, [r4]
	movs r0, #0xa2
	strb r0, [r4, #1]
	strb r1, [r4, #2]
	movs r0, #0x98
	strb r0, [r4, #3]
	strb r1, [r4, #4]
	movs r0, #0x91
	strb r0, [r4, #5]
	strb r1, [r4, #6]
	movs r0, #0x9f
	strb r0, [r4, #7]
_0823CDB6:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0823cdc0
FUN_0823cdc0: @ 0x0823CDC0
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
_0823CDC6:
	cmp r2, r3
	bge _0823CDE0
	adds r0, r2, r3
	asrs r1, r0, #1
	lsls r0, r1, #2
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, r5
	bhs _0823CDDC
	adds r2, r1, #1
	b _0823CDC6
_0823CDDC:
	adds r3, r1, #0
	b _0823CDC6
_0823CDE0:
	lsls r0, r2, #2
	adds r1, r0, r4
	ldrh r0, [r1]
	cmp r0, r5
	beq _0823CDEE
	movs r0, #0
	b _0823CDF0
_0823CDEE:
	ldrh r0, [r1, #2]
_0823CDF0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823cdf8
FUN_0823cdf8: @ 0x0823CDF8
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0823CE0C @ =0x08DBD83C
	movs r2, #0
	movs r3, #0xaa
	bl FUN_0823cdc0
	pop {r1}
	bx r1
	.align 2, 0
_0823CE0C: .4byte 0x08DBD83C

	thumb_func_start FUN_0823ce10
FUN_0823ce10: @ 0x0823CE10
	push {r4, lr}
	ldr r3, _0823CE34 @ =0x08DBD798
	ldr r4, _0823CE38 @ =0x030047E0
	ldrb r2, [r4, #0xe]
	lsls r2, r2, #1
	adds r2, r2, r3
	ldrb r2, [r2]
	strh r2, [r0]
	ldrb r0, [r4, #0xe]
	lsls r0, r0, #1
	adds r3, #1
	adds r0, r0, r3
	ldrb r0, [r0]
	strh r0, [r1]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0823CE34: .4byte 0x08DBD798
_0823CE38: .4byte 0x030047E0

	thumb_func_start FUN_0823ce3c
FUN_0823ce3c: @ 0x0823CE3C
	push {r4, lr}
	ldr r3, _0823CE60 @ =0x08DBD798
	ldr r4, _0823CE64 @ =0x030047E0
	ldrb r2, [r4, #0xe]
	lsls r2, r2, #1
	adds r2, r2, r3
	ldrb r2, [r2]
	strh r2, [r0]
	ldrb r0, [r4, #0xe]
	lsls r0, r0, #1
	adds r3, #1
	adds r0, r0, r3
	ldrb r0, [r0]
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0823CE60: .4byte 0x08DBD798
_0823CE64: .4byte 0x030047E0

	thumb_func_start FUN_0823ce68
FUN_0823ce68: @ 0x0823CE68
	push {r4, r5, lr}
	sub sp, #0x14
	adds r5, r1, #0
	cmp r0, #1
	beq _0823CE98
	cmp r0, #1
	bgt _0823CE7C
	cmp r0, #0
	beq _0823CE86
	b _0823CE98
_0823CE7C:
	cmp r0, #2
	beq _0823CE8C
	cmp r0, #3
	beq _0823CE92
	b _0823CE98
_0823CE86:
	movs r1, #2
	movs r4, #1
	b _0823CE9C
_0823CE8C:
	movs r1, #4
	movs r4, #3
	b _0823CE9C
_0823CE92:
	movs r1, #5
	movs r4, #4
	b _0823CE9C
_0823CE98:
	movs r1, #3
	movs r4, #2
_0823CE9C:
	str r5, [sp]
	str r2, [sp, #4]
	str r3, [sp, #8]
	ldr r0, [sp, #0x20]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x24]
	str r0, [sp, #0x10]
	adds r0, r1, #0
	movs r1, #5
	mov r2, sp
	bl FUN_0800205c
	ldr r0, [sp, #0x28]
	str r0, [sp, #0x10]
	adds r0, r4, #0
	movs r1, #5
	mov r2, sp
	bl FUN_08002800
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0823CECC:
	.byte 0x70, 0xB5, 0x84, 0xB0
	.byte 0xF4, 0xF7, 0x08, 0xFC, 0x00, 0x04, 0x10, 0x4C, 0x00, 0x0C, 0x00, 0x90, 0xF4, 0xF7, 0x02, 0xFC
	.byte 0x00, 0x04, 0x00, 0x0C, 0x01, 0x99, 0x21, 0x40, 0x01, 0x43, 0x01, 0x91, 0x6E, 0x46, 0x68, 0x46
	.byte 0x00, 0x88, 0x00, 0x04, 0x02, 0x16, 0xB0, 0x88, 0x00, 0x04, 0x01, 0x16, 0x00, 0x2A, 0x09, 0xDB
	.byte 0x00, 0x29, 0x07, 0xDB, 0x05, 0x48, 0x00, 0x68, 0x82, 0x42, 0x03, 0xD2, 0x04, 0x48, 0x00, 0x68
	.byte 0x81, 0x42, 0x07, 0xD3, 0x00, 0x24, 0x0C, 0xE0, 0x00, 0x00, 0xFF, 0xFF, 0xA8, 0x46, 0x00, 0x03
	.byte 0xAC, 0x46, 0x00, 0x03, 0x07, 0x48, 0x00, 0x68, 0x49, 0x00, 0x24, 0x30, 0x40, 0x18, 0x00, 0x88
	.byte 0x84, 0x18, 0x20, 0x1C, 0x01, 0x21, 0xF7, 0xF7, 0x75, 0xF9, 0x00, 0x28, 0x04, 0xD0, 0x04, 0x30
	.byte 0x08, 0xE0, 0x00, 0x00, 0xA4, 0x46, 0x00, 0x03, 0x07, 0x48, 0x01, 0x68, 0xA0, 0x00, 0x0C, 0x30
	.byte 0x49, 0x68, 0x08, 0x18, 0x01, 0x78, 0x0A, 0x09, 0x0F, 0x20, 0x08, 0x40, 0x05, 0x02, 0x01, 0x2A
	.byte 0x04, 0xD0, 0x02, 0x2A, 0x04, 0xD0, 0x05, 0xE0, 0xA4, 0x46, 0x00, 0x03, 0x30, 0x79, 0x00, 0xE0
	.byte 0x30, 0x78, 0x2D, 0x1A, 0x02, 0xAC, 0x20, 0x1C, 0xF4, 0xF7, 0x80, 0xFB, 0x20, 0x1C, 0x00, 0x21
	.byte 0x2A, 0x1C, 0xF5, 0xF7, 0x73, 0xF8, 0x28, 0x1C, 0x04, 0xB0, 0x70, 0xBC, 0x02, 0xBC, 0x08, 0x47

	thumb_func_start FUN_0823cf90
FUN_0823cf90: @ 0x0823CF90
	push {r4, r5, lr}
	sub sp, #0x10
	bl fetch_082316e4
	lsls r0, r0, #0x10
	ldr r4, _0823CFDC @ =0xFFFF0000
	lsrs r0, r0, #0x10
	str r0, [sp]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r2, sp
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _0823CFD8
	cmp r1, #0
	blt _0823CFD8
	ldr r0, _0823CFE0 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _0823CFD8
	ldr r0, _0823CFE4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0823CFE8
_0823CFD8:
	movs r4, #0
	b _0823CFF6
	.align 2, 0
_0823CFDC: .4byte 0xFFFF0000
_0823CFE0: .4byte 0x030046A8
_0823CFE4: .4byte 0x030046AC
_0823CFE8:
	ldr r0, _0823D008 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_0823CFF6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0823D00C
	adds r0, #4
	b _0823D018
	.align 2, 0
_0823D008: .4byte 0x030046A4
_0823D00C:
	ldr r0, _0823D038 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0823D018:
	ldrb r4, [r0]
	lsrs r4, r4, #4
	add r5, sp, #8
	adds r0, r5, #0
	bl FUN_0823167c
	adds r0, r5, #0
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0823206c
	adds r0, r4, #0
	add sp, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0823D038: .4byte 0x030046A4

	thumb_func_start FUN_0823d03c
FUN_0823d03c: @ 0x0823D03C
	push {r4, r5, lr}
	sub sp, #0x10
	bl fetch_082316e4
	lsls r0, r0, #0x10
	ldr r4, _0823D088 @ =0xFFFF0000
	lsrs r0, r0, #0x10
	str r0, [sp]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r2, sp
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _0823D084
	cmp r1, #0
	blt _0823D084
	ldr r0, _0823D08C @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _0823D084
	ldr r0, _0823D090 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0823D094
_0823D084:
	movs r4, #0
	b _0823D0A2
	.align 2, 0
_0823D088: .4byte 0xFFFF0000
_0823D08C: .4byte 0x030046A8
_0823D090: .4byte 0x030046AC
_0823D094:
	ldr r0, _0823D0B4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_0823D0A2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0823D0B8
	adds r0, #4
	b _0823D0C4
	.align 2, 0
_0823D0B4: .4byte 0x030046A4
_0823D0B8:
	ldr r0, _0823D0E4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0823D0C4:
	ldrh r5, [r0, #2]
	add r4, sp, #8
	adds r0, r4, #0
	bl FUN_0823167c
	adds r0, r4, #0
	movs r1, #0
	adds r2, r5, #0
	bl FUN_0823206c
	adds r0, r5, #0
	add sp, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0823D0E4: .4byte 0x030046A4

	thumb_func_start FUN_0823d0e8
FUN_0823d0e8: @ 0x0823D0E8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	bl fetch_082316e4
	adds r6, r0, #0
	ldr r7, _0823D118 @ =0x030046A4
	ldr r0, [r7]
	ldr r5, [r0, #4]
	cmp r5, #0
	beq _0823D1CE
	movs r0, #4
	ldrsh r1, [r5, r0]
	movs r2, #6
	ldrsh r0, [r5, r2]
	muls r0, r1, r0
	cmp r6, r0
	blt _0823D120
	ldr r1, _0823D11C @ =0xFFFF0000
	movs r0, #0
	str r0, [sp]
	ldr r0, [sp, #4]
	ands r0, r1
	str r0, [sp, #4]
	b _0823D192
	.align 2, 0
_0823D118: .4byte 0x030046A4
_0823D11C: .4byte 0xFFFF0000
_0823D120:
	adds r0, r6, #0
	bl Mod
	lsls r0, r0, #8
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0823D164 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	movs r0, #4
	ldrsh r1, [r5, r0]
	adds r0, r6, #0
	bl Div
	lsls r0, r0, #8
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	mov r4, sp
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0823D168
	adds r0, #4
	b _0823D172
	.align 2, 0
_0823D164: .4byte 0xFFFF0000
_0823D168:
	ldr r0, [r7]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0823D172:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0823D186
	cmp r2, #2
	beq _0823D18A
	b _0823D18E
_0823D186:
	ldrb r0, [r4, #4]
	b _0823D18C
_0823D18A:
	ldrb r0, [r4]
_0823D18C:
	subs r1, r1, r0
_0823D18E:
	mov r0, sp
	strh r1, [r0, #2]
_0823D192:
	add r4, sp, #8
	adds r0, r4, #0
	bl FUN_0823167c
	mov r0, sp
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	mov r5, sp
	movs r0, #2
	ldrsh r2, [r5, r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	movs r1, #4
	ldrsh r2, [r5, r1]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
_0823D1CE:
	movs r0, #0
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0823d1d8
FUN_0823d1d8: @ 0x0823D1D8
	push {lr}
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x11
	lsls r1, r0
	lsrs r1, r1, #0x10
	ldr r2, _0823D1F8 @ =0x03003E78
	ldrh r0, [r2]
	bics r0, r1
	strh r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_0823D1F8: .4byte 0x03003E78

	thumb_func_start FUN_0823d1fc
FUN_0823d1fc: @ 0x0823D1FC
	push {lr}
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x11
	lsls r1, r0
	lsrs r1, r1, #0x10
	ldr r2, _0823D21C @ =0x03003E78
	ldrh r0, [r2]
	orrs r1, r0
	strh r1, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_0823D21C: .4byte 0x03003E78

	thumb_func_start FUN_0823d220
FUN_0823d220: @ 0x0823D220
	push {lr}
	bl FUN_0823a928
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0823d22c
FUN_0823d22c: @ 0x0823D22C
	push {r4, r5, lr}
	movs r4, #0x80
	lsls r4, r4, #0x13
	ldrh r0, [r4]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r4]
	bl FUN_08229f34
	bl FUN_08229f34
	ldr r5, _0823D270 @ =0x04000132
	ldr r1, _0823D274 @ =0x0000C304
	adds r0, r1, #0
	strh r0, [r5]
	bl SoundBias_0
	svc #3
	bl SoundBias_200
	ldr r1, _0823D278 @ =0x030047B4
	movs r0, #1
	str r0, [r1]
	ldrh r1, [r4]
	ldr r0, _0823D27C @ =0x0000FF7F
	ands r0, r1
	strh r0, [r4]
	movs r0, #0
	strh r0, [r5]
	bl FUN_08229f34
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0823D270: .4byte 0x04000132
_0823D274: .4byte 0x0000C304
_0823D278: .4byte 0x030047B4
_0823D27C: .4byte 0x0000FF7F

	thumb_func_start FUN_0823d280
FUN_0823d280: @ 0x0823D280
	push {r4, lr}
	ldr r4, _0823D2B4 @ =0x030047A8
	ldr r0, [r4]
	cmp r0, #0
	beq _0823D2AE
	bl FUN_082410e8
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0823D2AE
	movs r1, #5
	ldr r0, _0823D2B8 @ =0x030046A0
	ldr r0, [r0]
	strh r1, [r0, #0x12]
	movs r1, #0xe6
	ldr r0, [r4]
	str r1, [r0, #4]
	strb r2, [r0, #8]
	ldr r0, [r4]
	strb r2, [r0, #9]
	ldr r0, [r4]
	strb r2, [r0, #0xa]
_0823D2AE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0823D2B4: .4byte 0x030047A8
_0823D2B8: .4byte 0x030046A0
_0823D2BC:
	.byte 0x00, 0xB5, 0x74, 0x20
	.byte 0x00, 0x21, 0xF4, 0xF7, 0x43, 0xFA, 0x02, 0x49, 0x08, 0x60, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	.byte 0x6C, 0x44, 0x00, 0x03, 0x01, 0x49, 0x00, 0x20, 0x08, 0x60, 0x70, 0x47, 0x6C, 0x44, 0x00, 0x03
	.byte 0x00, 0xB5, 0x08, 0x49, 0x09, 0x68, 0x40, 0x00, 0x40, 0x18, 0x07, 0x49, 0x42, 0x18, 0x13, 0x88
	.byte 0x00, 0x20, 0x11, 0x5E, 0x05, 0x48, 0x81, 0x42, 0x01, 0xDC, 0x58, 0x1C, 0x10, 0x80, 0x01, 0xBC
	.byte 0x00, 0x47, 0x00, 0x00, 0xA0, 0x46, 0x00, 0x03, 0x48, 0x09, 0x00, 0x00, 0x0E, 0x27, 0x00, 0x00
	.byte 0x00, 0xB5, 0x08, 0x49, 0x09, 0x68, 0x40, 0x00, 0x40, 0x18, 0x95, 0x21, 0x09, 0x01, 0x42, 0x18
	.byte 0x13, 0x88, 0x00, 0x20, 0x11, 0x5E, 0x04, 0x48, 0x81, 0x42, 0x01, 0xDC, 0x58, 0x1C, 0x10, 0x80
	.byte 0x01, 0xBC, 0x00, 0x47, 0xA0, 0x46, 0x00, 0x03, 0x0E, 0x27, 0x00, 0x00, 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_0823d340
FUN_0823d340: @ 0x0823D340
	push {lr}
	bl FUN_082316bc
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823d34c
FUN_0823d34c: @ 0x0823D34C
	push {lr}
	bl FUN_0823172c
	pop {r1}
	bx r1
	.align 2, 0
_0823D358:
	.byte 0x00, 0xB5, 0x82, 0xB0, 0x68, 0x46, 0xF4, 0xF7
	.byte 0x8D, 0xF9, 0x05, 0x48, 0x00, 0x68, 0x02, 0x68, 0x68, 0x46, 0x00, 0x21, 0xF4, 0xF7, 0x7E, 0xFE
	.byte 0x02, 0xB0, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0xA8, 0x47, 0x00, 0x03

	thumb_func_start FUN_0823d37c
FUN_0823d37c: @ 0x0823D37C
	push {r4, r5, lr}
	sub sp, #8
	ldr r0, _0823D3E8 @ =0x030047A8
	ldr r0, [r0]
	ldr r0, [r0]
	movs r1, #0x3c
	bl Div
	adds r5, r0, #0
	movs r1, #0x3c
	bl Mod
	adds r0, r5, #0
	movs r1, #0x3c
	bl Div
	adds r5, r0, #0
	movs r1, #0x3c
	bl Mod
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #0x3c
	bl Div
	adds r5, r0, #0
	mov r0, sp
	bl FUN_0823167c
	mov r0, sp
	movs r1, #0
	movs r2, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	mov r0, sp
	movs r1, #0
	adds r2, r5, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	mov r0, sp
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0823206c
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0823D3E8: .4byte 0x030047A8
_0823D3EC:
	.byte 0x01, 0x20, 0x02, 0x49
	.byte 0x09, 0x68, 0x48, 0x72, 0x70, 0x47, 0x00, 0x00, 0xA8, 0x47, 0x00, 0x03, 0x01, 0x48, 0x00, 0x68
	.byte 0x40, 0x7A, 0x70, 0x47, 0xA8, 0x47, 0x00, 0x03, 0x01, 0x48, 0x00, 0x68, 0x80, 0x7A, 0x70, 0x47
	.byte 0xA8, 0x47, 0x00, 0x03

	thumb_func_start FUN_0823d414
FUN_0823d414: @ 0x0823D414
	adds r1, r0, #0
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _0823D424 @ =gWeaponDB
	adds r0, r0, r1
	bx lr
	.align 2, 0
_0823D424: .4byte gWeaponDB

	thumb_func_start FUN_0823d428
FUN_0823d428: @ 0x0823D428
	push {r4, r5, lr}
	sub sp, #0x10
	movs r0, #0x62
	movs r1, #0
	bl FUN_0823174c
	adds r4, r0, #0
	movs r0, #0x69
	movs r1, #0
	bl FUN_0823174c
	str r0, [sp, #0xc]
	movs r0, #0x70
	movs r1, #0
	bl FUN_0823174c
	adds r5, r0, #0
	ldr r0, _0823D4A0 @ =0x0000C091
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r1, r4, #0
	bl FUN_082310cc
	adds r2, r0, #0
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	cmp r5, #0
	beq _0823D498
	ldr r0, _0823D4A4 @ =0x000092B3
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	bl FUN_082310cc
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, _0823D4A8 @ =0x030043F0
	movs r2, #0x30
	bl CpuSet
_0823D498:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0823D4A0: .4byte 0x0000C091
_0823D4A4: .4byte 0x000092B3
_0823D4A8: .4byte 0x030043F0

	thumb_func_start FUN_0823d4ac
FUN_0823d4ac: @ 0x0823D4AC
	push {lr}
	ldr r2, _0823D4C0 @ =0x02020400
	ldr r0, [r2]
	ldr r1, _0823D4C4 @ =0x516B92EE
	cmp r0, r1
	beq _0823D4BA
	str r1, [r2]
_0823D4BA:
	pop {r0}
	bx r0
	.align 2, 0
_0823D4C0: .4byte 0x02020400
_0823D4C4: .4byte 0x516B92EE

	thumb_func_start FUN_0823d4c8
FUN_0823d4c8: @ 0x0823D4C8
	push {lr}
	ldr r0, _0823D4D8 @ =0x02020400
	ldr r1, [r0]
	ldr r0, _0823D4DC @ =0x516B92EE
	cmp r1, r0
	beq _0823D4E0
	movs r0, #0
	b _0823D4E2
	.align 2, 0
_0823D4D8: .4byte 0x02020400
_0823D4DC: .4byte 0x516B92EE
_0823D4E0:
	movs r0, #1
_0823D4E2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823d4e8
FUN_0823d4e8: @ 0x0823D4E8
	push {r4, lr}
	ldr r2, _0823D54C @ =0x030046A0
	ldr r0, [r2]
	movs r4, #0xb6
	lsls r4, r4, #2
	adds r1, r0, r4
	ldr r0, [r1]
	cmp r0, #0
	bne _0823D4FE
	movs r0, #1
	str r0, [r1]
_0823D4FE:
	ldr r0, [r2]
	movs r3, #0xb7
	lsls r3, r3, #2
	adds r1, r0, r3
	ldr r0, [r1]
	cmp r0, #0
	bne _0823D510
	movs r0, #1
	str r0, [r1]
_0823D510:
	ldr r0, [r2]
	adds r1, r0, r3
	adds r0, r0, r4
	ldr r1, [r1]
	ldr r0, [r0]
	adds r1, r1, r0
	cmp r1, #0
	bne _0823D522
	movs r1, #1
_0823D522:
	lsls r0, r0, #7
	bl Div
	movs r1, #0
	cmp r0, #0x46
	bgt _0823D536
	movs r1, #1
	cmp r0, #0x3a
	ble _0823D536
	movs r1, #2
_0823D536:
	ldr r0, _0823D54C @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0xbe
	lsls r2, r2, #2
	adds r0, r0, r2
	strh r1, [r0]
	adds r0, r1, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0823D54C: .4byte 0x030046A0

	thumb_func_start FUN_0823d550
FUN_0823d550: @ 0x0823D550
	push {r4, r5, r6, lr}
	sub sp, #0x14
	movs r4, #0
	mov r6, sp
_0823D558:
	ldr r5, _0823D58C @ =0x030046A0
	ldr r1, [r5]
	lsls r0, r4, #2
	adds r0, r0, r1
	movs r1, #0xb8
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _0823D590 @ =0x0000D2F0
	bl Div
	stm r6!, {r0}
	adds r4, #1
	cmp r4, #4
	ble _0823D558
	movs r0, #0
	movs r1, #5
	movs r4, #0
	mov r3, sp
_0823D57E:
	ldr r2, [r3]
	cmp r2, r0
	ble _0823D594
	adds r0, r2, #0
	adds r1, r4, #0
	b _0823D59A
	.align 2, 0
_0823D58C: .4byte 0x030046A0
_0823D590: .4byte 0x0000D2F0
_0823D594:
	cmp r2, r0
	bne _0823D59A
	movs r1, #5
_0823D59A:
	adds r3, #4
	adds r4, #1
	cmp r4, #4
	ble _0823D57E
	ldr r0, [r5]
	ldr r2, _0823D5B4 @ =0x000002FA
	adds r0, r0, r2
	strh r1, [r0]
	adds r0, r1, #0
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0823D5B4: .4byte 0x000002FA
_0823D5B8:
	.byte 0x30, 0xB5, 0x00, 0x24, 0x64, 0x23, 0x5B, 0x42
	.byte 0x00, 0x22, 0x09, 0x48, 0x00, 0x68, 0x09, 0x49, 0x40, 0x18, 0x00, 0x25, 0x41, 0x5F, 0x99, 0x42
	.byte 0x01, 0xDD, 0x0B, 0x1C, 0x14, 0x1C, 0x02, 0x30, 0x01, 0x32, 0x04, 0x2A, 0xF5, 0xDD, 0x20, 0x1C
	.byte 0x30, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00, 0xA0, 0x46, 0x00, 0x03, 0xFE, 0x02, 0x00, 0x00

	thumb_func_start FUN_0823d5f0
FUN_0823d5f0: @ 0x0823D5F0
	push {lr}
	ldr r0, _0823D668 @ =0x03002BE0
	ldr r2, [r0]
	cmp r2, #0
	beq _0823D678
	ldr r0, _0823D66C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0823D678
	movs r1, #1
	ldr r0, _0823D670 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0823D678
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0823D678
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0823D678
	ldr r1, _0823D674 @ =0x00000446
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0823D64C
	subs r1, #4
	adds r0, r2, r1
	ldrh r0, [r0]
	subs r0, #5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _0823D678
_0823D64C:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	movs r1, #1
	cmp r0, #1
	bls _0823D660
	cmp r0, #7
	beq _0823D660
	movs r1, #0
_0823D660:
	cmp r1, #0
	beq _0823D678
	movs r0, #1
	b _0823D67A
	.align 2, 0
_0823D668: .4byte 0x03002BE0
_0823D66C: .4byte 0x030047A4
_0823D670: .4byte 0x03002BC0
_0823D674: .4byte 0x00000446
_0823D678:
	movs r0, #0
_0823D67A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823d680
FUN_0823d680: @ 0x0823D680
	ldr r0, _0823D688 @ =0x030047A8
	ldr r0, [r0]
	ldr r0, [r0, #0x20]
	bx lr
	.align 2, 0
_0823D688: .4byte 0x030047A8

	thumb_func_start FUN_0823d68c
FUN_0823d68c: @ 0x0823D68C
	push {lr}
	ldr r0, _0823D6A0 @ =0x030047A8
	ldr r0, [r0]
	ldr r1, [r0, #0x10]
	ldr r0, _0823D6A4 @ =0x0000369F
	cmp r1, r0
	beq _0823D6A8
	movs r0, #0
	b _0823D6AA
	.align 2, 0
_0823D6A0: .4byte 0x030047A8
_0823D6A4: .4byte 0x0000369F
_0823D6A8:
	movs r0, #1
_0823D6AA:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823d6b0
FUN_0823d6b0: @ 0x0823D6B0
	ldr r0, _0823D6B8 @ =0x030047A8
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	bx lr
	.align 2, 0
_0823D6B8: .4byte 0x030047A8

	thumb_func_start FUN_0823d6bc
FUN_0823d6bc: @ 0x0823D6BC
	push {lr}
	ldr r0, _0823D6D4 @ =0x030047A8
	ldr r0, [r0]
	ldr r1, [r0, #0xc]
	movs r0, #0x70
	bl FUN_0823174c
	adds r1, r0, #0
	cmp r1, #0
	bge _0823D6D8
	movs r1, #0
	b _0823D6E0
	.align 2, 0
_0823D6D4: .4byte 0x030047A8
_0823D6D8:
	ldr r0, _0823D6EC @ =0x0000270F
	cmp r1, r0
	ble _0823D6E0
	adds r1, r0, #0
_0823D6E0:
	ldr r0, _0823D6F0 @ =0x030047A8
	ldr r0, [r0]
	str r1, [r0, #0xc]
	adds r0, r1, #0
	pop {r1}
	bx r1
	.align 2, 0
_0823D6EC: .4byte 0x0000270F
_0823D6F0: .4byte 0x030047A8

	thumb_func_start FUN_0823d6f4
FUN_0823d6f4: @ 0x0823D6F4
	ldr r0, _0823D6FC @ =0x030047A8
	ldr r0, [r0]
	ldrh r0, [r0, #0x14]
	bx lr
	.align 2, 0
_0823D6FC: .4byte 0x030047A8

	thumb_func_start FUN_0823d700
FUN_0823d700: @ 0x0823D700
	ldr r0, _0823D708 @ =0x030047A8
	ldr r0, [r0]
	ldrh r0, [r0, #0x16]
	bx lr
	.align 2, 0
_0823D708: .4byte 0x030047A8

	thumb_func_start FUN_0823d70c
FUN_0823d70c: @ 0x0823D70C
	push {lr}
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _0823D73A
	bl FUN_082316bc
	cmp r0, #0
	beq _0823D73A
	bl FUN_08231660
	bl FUN_08231978
	ldr r2, _0823D740 @ =0x030047D8
	ldrb r1, [r0, #1]
	ldrb r0, [r0]
	lsls r0, r0, #8
	orrs r1, r0
	ldr r3, _0823D744 @ =0x00000FFF
	adds r0, r3, #0
	ands r1, r0
	strh r1, [r2]
_0823D73A:
	pop {r0}
	bx r0
	.align 2, 0
_0823D740: .4byte 0x030047D8
_0823D744: .4byte 0x00000FFF

	thumb_func_start FUN_0823d748
FUN_0823d748: @ 0x0823D748
	push {lr}
	bl fetch_082316e4
	ldr r1, _0823D760 @ =0x030046A0
	ldr r1, [r1]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r1, r1, r2
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0823D760: .4byte 0x030046A0

	thumb_func_start FUN_0823d764
FUN_0823d764: @ 0x0823D764
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x18]
	adds r1, r4, #0
	adds r1, #0x50
	bl FUN_08230f94
	adds r1, r0, #0
	ldr r2, [r4, #0x50]
	subs r1, #1
	cmp r0, #0
	ble _0823D78E
	ldr r0, [r2, #4]
	ldrh r2, [r0]
	ldr r3, _0823D7B0 @ =0x0000FFFF
_0823D782:
	cmp r2, r3
	beq _0823D7C2
	adds r0, r1, #0
	subs r1, #1
	cmp r0, #0
	bgt _0823D782
_0823D78E:
	ldr r0, [r4, #0x28]
	subs r0, #1
	str r0, [r4, #0x28]
	cmp r0, #0
	bgt _0823D7CC
	ldrh r1, [r4, #0x2e]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0823D7B4
	ldr r0, [r4, #0x24]
	adds r1, r4, #0
	adds r1, #0x1c
	bl FUN_082318ac
	b _0823D7BE
	.align 2, 0
_0823D7B0: .4byte 0x0000FFFF
_0823D7B4:
	ldr r0, [r4, #0x24]
	adds r1, r4, #0
	adds r1, #0x1c
	bl FUN_08231b58
_0823D7BE:
	cmp r0, #0
	bne _0823D7CA
_0823D7C2:
	adds r0, r4, #0
	bl KillEntity
	b _0823D7CC
_0823D7CA:
	str r0, [r4, #0x28]
_0823D7CC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0823d7d4
FUN_0823d7d4: @ 0x0823D7D4
	bx lr
	.align 2, 0

	thumb_func_start FUN_0823d7d8
FUN_0823d7d8: @ 0x0823D7D8
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	movs r0, #5
	movs r1, #0x54
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0823D852
	cmp r5, #0
	bne _0823D804
	strh r5, [r4, #0x1c]
	ldr r0, _0823D7FC @ =FUN_0823d764
	mov ip, r0
	ldr r5, _0823D800 @ =FUN_0823d7d4
	b _0823D82C
	.align 2, 0
_0823D7FC: .4byte FUN_0823d764
_0823D800: .4byte FUN_0823d7d4
_0823D804:
	ldr r2, [r5, #4]
	adds r0, r4, #0
	adds r0, #0x30
	str r0, [r4, #0x20]
	adds r3, r0, #0
	ldrh r0, [r5]
	strh r0, [r4, #0x1c]
	ldrh r1, [r5]
	ldr r0, _0823D838 @ =FUN_0823d764
	mov ip, r0
	ldr r5, _0823D83C @ =FUN_0823d7d4
	cmp r1, #0
	beq _0823D82C
_0823D81E:
	ldm r2!, {r0}
	stm r3!, {r0}
	subs r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _0823D81E
_0823D82C:
	cmp r6, #0
	bge _0823D840
	movs r0, #1
	strh r0, [r4, #0x2c]
	rsbs r6, r6, #0
	b _0823D844
	.align 2, 0
_0823D838: .4byte FUN_0823d764
_0823D83C: .4byte FUN_0823d7d4
_0823D840:
	movs r0, #0
	strh r0, [r4, #0x2c]
_0823D844:
	str r6, [r4, #0x28]
	str r7, [r4, #0x24]
	adds r0, r4, #0
	mov r1, ip
	adds r2, r5, #0
	bl SetEntityRoutine
_0823D852:
	adds r0, r4, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0823D85C:
	.byte 0xF0, 0xB5, 0x82, 0xB0
	.byte 0x05, 0x1C, 0x00, 0x27, 0x00, 0x24, 0x74, 0x20, 0xF3, 0xF7, 0x52, 0xFE, 0x00, 0x28, 0x02, 0xD0
	.byte 0xF3, 0xF7, 0x38, 0xFF, 0x07, 0x1C, 0x00, 0x26, 0x65, 0x20, 0xF3, 0xF7, 0x49, 0xFE, 0x00, 0x28
	.byte 0x07, 0xD0, 0xF3, 0xF7, 0x1B, 0xFF, 0x01, 0xAA, 0x69, 0x46, 0xF3, 0xF7, 0x07, 0xFD, 0x01, 0x9C
	.byte 0x08, 0xE0, 0x70, 0x20, 0xF3, 0xF7, 0x3C, 0xFE, 0x00, 0x28, 0x03, 0xD0, 0x01, 0x26, 0xF3, 0xF7
	.byte 0x21, 0xFF, 0x04, 0x1C, 0x20, 0x1C, 0x00, 0x21, 0x3A, 0x1C, 0xFF, 0xF7, 0x95, 0xFF, 0x04, 0x1C
	.byte 0x00, 0x2C, 0x19, 0xD0, 0xA5, 0x61, 0xE6, 0x85, 0x61, 0x20, 0xF3, 0xF7, 0x29, 0xFE, 0x00, 0x28
	.byte 0x12, 0xD0, 0x20, 0x1C, 0x30, 0x30, 0x20, 0x62, 0x00, 0x25, 0x06, 0xE0, 0xF3, 0xF7, 0x0A, 0xFF
	.byte 0x22, 0x6A, 0xA9, 0x00, 0x89, 0x18, 0x08, 0x60, 0x01, 0x35, 0x07, 0x2D, 0x03, 0xDC, 0xF3, 0xF7
	.byte 0xED, 0xFE, 0x00, 0x28, 0xF2, 0xD1, 0xA5, 0x83, 0x20, 0x1C, 0x02, 0xB0, 0xF0, 0xBC, 0x02, 0xBC
	.byte 0x08, 0x47, 0x00, 0x00

	thumb_func_start FUN_0823d8f4
FUN_0823d8f4: @ 0x0823D8F4
	push {lr}
	cmp r0, #0
	ble _0823D900
_0823D8FA:
	subs r0, #1
	cmp r0, #0
	bne _0823D8FA
_0823D900:
	pop {r0}
	bx r0

	thumb_func_start FUN_0823d904
FUN_0823d904: @ 0x0823D904
	push {lr}
	bl FUN_0824c598
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0823d910
FUN_0823d910: @ 0x0823D910
	push {lr}
	bl FUN_0824c5b0
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0823d91c
FUN_0823d91c: @ 0x0823D91C
	push {lr}
	ldr r0, _0823D92C @ =0x030047E0
	movs r1, #0x24
	bl FUN_082309cc
	pop {r0}
	bx r0
	.align 2, 0
_0823D92C: .4byte 0x030047E0

	thumb_func_start FUN_0823d930
FUN_0823d930: @ 0x0823D930
	push {r4, lr}
	adds r3, r0, #0
	lsls r3, r3, #0x10
	movs r4, #0xf
	movs r0, #0xf0
	lsls r0, r0, #0xc
	ands r0, r3
	lsrs r0, r0, #0x10
	lsrs r2, r3, #0x14
	ands r2, r4
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r0, r0, r1
	lsrs r1, r3, #0x18
	ands r1, r4
	movs r2, #0x64
	muls r1, r2, r1
	adds r0, r0, r1
	lsrs r3, r3, #0x1c
	ands r3, r4
	lsls r1, r3, #5
	subs r1, r1, r3
	lsls r1, r1, #2
	adds r1, r1, r3
	lsls r1, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0823d970
FUN_0823d970: @ 0x0823D970
	push {r4, lr}
	adds r4, r0, #0
	subs r0, r1, #2
	cmp r0, #9
	bhi _0823D9E2
	lsls r0, r0, #2
	ldr r1, _0823D984 @ =_0823D988
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0823D984: .4byte _0823D988
_0823D988: @ jump table
	.4byte _0823D9B0 @ case 0
	.4byte _0823D9E2 @ case 1
	.4byte _0823D9DE @ case 2
	.4byte _0823D9E2 @ case 3
	.4byte _0823D9DE @ case 4
	.4byte _0823D9E2 @ case 5
	.4byte _0823D9E2 @ case 6
	.4byte _0823D9DE @ case 7
	.4byte _0823D9E2 @ case 8
	.4byte _0823D9DE @ case 9
_0823D9B0:
	adds r0, r4, #0
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _0823D9C8
	adds r0, r4, #0
	movs r1, #0x64
	bl Mod
	cmp r0, #0
	bne _0823D9D6
_0823D9C8:
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r4, #0
	bl Mod
	cmp r0, #0
	bne _0823D9DA
_0823D9D6:
	movs r0, #0x1d
	b _0823D9E4
_0823D9DA:
	movs r0, #0x1c
	b _0823D9E4
_0823D9DE:
	movs r0, #0x1e
	b _0823D9E4
_0823D9E2:
	movs r0, #0x1f
_0823D9E4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823d9ec
FUN_0823d9ec: @ 0x0823D9EC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	mov r8, r1
	str r2, [sp]
	mov sb, r3
	ldr r0, [sp, #0x24]
	mov sl, r0
	adds r0, r7, #0
	movs r1, #4
	bl Div
	adds r5, r0, #0
	adds r0, r7, #0
	movs r1, #0x64
	bl Div
	adds r4, r0, #0
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r7, #0
	bl Div
	ldr r1, _0823DAA0 @ =0x0000016D
	muls r1, r7, r1
	adds r1, r1, r5
	subs r1, r1, r4
	adds r6, r1, r0
	movs r4, #1
	cmp r4, r8
	bge _0823DA42
_0823DA32:
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_0823d970
	adds r6, r6, r0
	adds r4, #1
	cmp r4, r8
	blt _0823DA32
_0823DA42:
	ldr r2, [sp]
	adds r6, r6, r2
	mov r0, sb
	movs r1, #4
	bl Div
	adds r5, r0, #0
	mov r0, sb
	movs r1, #0x64
	bl Div
	adds r4, r0, #0
	movs r1, #0xc8
	lsls r1, r1, #1
	mov r0, sb
	bl Div
	ldr r1, _0823DAA0 @ =0x0000016D
	mov r2, sb
	muls r2, r1, r2
	adds r1, r2, #0
	adds r1, r1, r5
	subs r1, r1, r4
	adds r5, r1, r0
	movs r4, #1
	cmp r4, sl
	bge _0823DA88
_0823DA78:
	mov r0, sb
	adds r1, r4, #0
	bl FUN_0823d970
	adds r5, r5, r0
	adds r4, #1
	cmp r4, sl
	blt _0823DA78
_0823DA88:
	ldr r0, [sp, #0x28]
	adds r5, r5, r0
	subs r0, r6, r5
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0823DAA0: .4byte 0x0000016D

	thumb_func_start FUN_0823daa4
FUN_0823daa4: @ 0x0823DAA4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	adds r6, r1, #0
	mov sb, r2
	cmp r6, #2
	bgt _0823DABA
	subs r7, #1
	adds r6, #0xc
_0823DABA:
	adds r0, r7, #0
	movs r1, #4
	bl Div
	adds r4, r0, #0
	adds r0, r7, #0
	movs r1, #0x64
	bl Div
	mov r8, r0
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r7, #0
	bl Div
	adds r5, r0, #0
	movs r0, #0xd
	muls r0, r6, r0
	adds r0, #8
	movs r1, #5
	bl Div
	adds r4, r7, r4
	mov r1, r8
	subs r4, r4, r1
	adds r4, r4, r5
	adds r4, r4, r0
	add r4, sb
	adds r0, r4, #0
	movs r1, #7
	bl Mod
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823db08
FUN_0823db08: @ 0x0823DB08
	push {r4, r5, r6, lr}
	lsrs r4, r3, #0x1c
	lsls r6, r4, #5
	subs r6, r6, r4
	lsls r6, r6, #2
	adds r6, r6, r4
	lsls r6, r6, #3
	movs r4, #0xf0
	lsls r4, r4, #0x14
	ands r4, r3
	asrs r4, r4, #0x18
	movs r5, #0x64
	muls r4, r5, r4
	adds r6, r6, r4
	movs r5, #0xf0
	lsls r5, r5, #0x10
	ands r5, r3
	asrs r5, r5, #0x14
	lsls r4, r5, #2
	adds r4, r4, r5
	lsls r4, r4, #1
	adds r6, r6, r4
	movs r4, #0xf0
	lsls r4, r4, #0xc
	ands r4, r3
	asrs r4, r4, #0x10
	adds r6, r6, r4
	str r6, [r0]
	movs r0, #0xf0
	lsls r0, r0, #8
	ands r0, r3
	asrs r0, r0, #0xc
	lsls r4, r0, #2
	adds r4, r4, r0
	lsls r4, r4, #1
	movs r0, #0xf0
	lsls r0, r0, #4
	ands r0, r3
	asrs r0, r0, #8
	adds r4, r4, r0
	str r4, [r1]
	movs r1, #0xf0
	ands r1, r3
	asrs r1, r1, #4
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	movs r1, #0xf
	ands r1, r3
	adds r0, r0, r1
	str r0, [r2]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0823db74
FUN_0823db74: @ 0x0823DB74
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	adds r7, r1, #0
	str r2, [sp]
	movs r1, #0xa
	bl Mod
	mov sl, r0
	adds r0, r5, #0
	movs r1, #0x64
	bl Mod
	mov r1, sl
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	mov sb, r0
	movs r6, #0xfa
	lsls r6, r6, #2
	adds r0, r5, #0
	adds r1, r6, #0
	bl Mod
	mov r4, sl
	add r4, sb
	subs r0, r0, r4
	movs r1, #0x64
	bl Div
	mov r8, r0
	ldr r1, _0823DC3C @ =0x00002710
	adds r0, r5, #0
	bl Mod
	add r4, r8
	subs r0, r0, r4
	adds r1, r6, #0
	bl Div
	adds r4, r0, #0
	adds r0, r7, #0
	movs r1, #0xa
	bl Mod
	adds r6, r0, #0
	adds r0, r7, #0
	movs r1, #0x64
	bl Mod
	subs r0, r0, r6
	movs r1, #0xa
	bl Div
	adds r5, r0, #0
	ldr r0, [sp]
	movs r1, #0xa
	bl Mod
	adds r7, r0, #0
	ldr r0, [sp]
	movs r1, #0x64
	bl Mod
	subs r0, r0, r7
	movs r1, #0xa
	bl Div
	lsls r4, r4, #0x1c
	mov r1, r8
	lsls r1, r1, #0x18
	orrs r4, r1
	mov r1, sb
	lsls r1, r1, #0x14
	orrs r4, r1
	mov r1, sl
	lsls r1, r1, #0x10
	orrs r4, r1
	lsls r5, r5, #0xc
	orrs r4, r5
	lsls r6, r6, #8
	orrs r4, r6
	lsls r0, r0, #4
	orrs r4, r0
	orrs r4, r7
	adds r0, r4, #0
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0823DC3C: .4byte 0x00002710

	thumb_func_start FUN_0823dc40
FUN_0823dc40: @ 0x0823DC40
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0
	movs r1, #0xa
	bl Mod
	adds r5, r0, #0
	adds r0, r4, #0
	movs r1, #0x64
	bl Mod
	subs r0, r0, r5
	movs r1, #0xa
	bl Div
	lsls r0, r0, #4
	orrs r0, r5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0823dc70
FUN_0823dc70: @ 0x0823DC70
	push {r4, lr}
	sub sp, #0xc
	ldr r3, _0823DD40 @ =0x030047E0
	ldrb r0, [r3, #7]
	adds r0, #1
	movs r1, #0
	strb r0, [r3, #7]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3b
	bls _0823DD36
	strb r1, [r3, #7]
	adds r4, r3, #0
	ldrb r0, [r4, #6]
	adds r0, #1
	strb r0, [r4, #6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3b
	bls _0823DD36
	strb r1, [r4, #6]
	ldrb r0, [r4, #5]
	adds r0, #1
	strb r0, [r4, #5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3b
	bls _0823DD12
	strb r1, [r4, #5]
	ldrb r0, [r4, #4]
	adds r0, #1
	strb r0, [r4, #4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x17
	bls _0823DD12
	strb r1, [r4, #4]
	add r1, sp, #4
	add r2, sp, #8
	ldr r3, [r4]
	mov r0, sp
	bl FUN_0823db08
	ldr r0, [sp, #8]
	adds r0, #1
	str r0, [sp, #8]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_0823d970
	ldr r1, [sp, #8]
	cmp r1, r0
	blt _0823DCFA
	movs r1, #1
	str r1, [sp, #8]
	ldr r0, [sp, #4]
	adds r0, #1
	str r0, [sp, #4]
	cmp r0, #0xc
	ble _0823DCFA
	str r1, [sp, #4]
	ldr r0, [sp]
	adds r0, #1
	str r0, [sp]
	ldr r1, _0823DD44 @ =0x00000832
	cmp r0, r1
	ble _0823DCFA
	ldr r0, _0823DD48 @ =0x00000833
	str r0, [sp]
_0823DCFA:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	ldr r2, [sp, #8]
	bl FUN_0823db74
	str r0, [r4]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	ldr r2, [sp, #8]
	bl FUN_0823daa4
	strb r0, [r4, #8]
_0823DD12:
	ldr r0, _0823DD4C @ =0x030047B4
	movs r1, #1
	str r1, [r0]
	ldr r2, _0823DD40 @ =0x030047E0
	ldrh r0, [r2, #0xc]
	ldrh r4, [r4, #4]
	cmp r0, r4
	bne _0823DD36
	ldrh r0, [r2, #0x14]
	adds r0, #1
	strh r0, [r2, #0x14]
	lsls r0, r0, #0x10
	movs r1, #0x8c
	lsls r1, r1, #0x11
	cmp r0, r1
	bls _0823DD36
	movs r0, #0
	strh r0, [r2, #0x14]
_0823DD36:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0823DD40: .4byte 0x030047E0
_0823DD44: .4byte 0x00000832
_0823DD48: .4byte 0x00000833
_0823DD4C: .4byte 0x030047B4

	thumb_func_start FUN_0823dd50
FUN_0823dd50: @ 0x0823DD50
	push {r4, r5, lr}
	ldr r0, _0823DD80 @ =0x0300481C
	ldr r0, [r0]
	cmp r0, #0
	bne _0823DD5E
	bl FUN_0823e768
_0823DD5E:
	ldr r5, _0823DD84 @ =0x030047E0
	ldrb r1, [r5, #0xc]
	ldrb r0, [r5, #4]
	subs r3, r1, r0
	ldrb r1, [r5, #0xd]
	ldrb r0, [r5, #5]
	subs r4, r1, r0
	cmp r3, #0
	bge _0823DD72
	adds r3, #0x18
_0823DD72:
	cmp r4, #0
	bge _0823DD8C
	cmp r3, #0
	ble _0823DD88
	subs r3, #1
	b _0823DD8A
	.align 2, 0
_0823DD80: .4byte 0x0300481C
_0823DD84: .4byte 0x030047E0
_0823DD88:
	movs r3, #0x17
_0823DD8A:
	adds r4, #0x3c
_0823DD8C:
	ldrb r1, [r5, #0xa]
	ldrb r0, [r5, #4]
	subs r2, r1, r0
	ldrb r1, [r5, #0xb]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	cmp r2, #0
	bge _0823DD9E
	adds r2, #0x18
_0823DD9E:
	cmp r1, #0
	bge _0823DDAE
	cmp r2, #0
	ble _0823DDAA
	subs r2, #1
	b _0823DDAC
_0823DDAA:
	movs r2, #0x17
_0823DDAC:
	adds r1, #0x3c
_0823DDAE:
	strb r3, [r5, #0x10]
	strb r4, [r5, #0x11]
	strb r2, [r5, #0x12]
	strb r1, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _0823DDC8
	movs r0, #0x3c
	subs r0, r0, r4
	b _0823DDCC
_0823DDC8:
	movs r0, #0x3c
	subs r0, r0, r1
_0823DDCC:
	lsls r4, r0, #6
	bl FUN_0823e1b0
	strb r0, [r5, #0xe]
	ldrb r0, [r5, #0xe]
	cmp r0, #5
	bhi _0823DE32
	lsls r0, r0, #2
	ldr r1, _0823DDE4 @ =_0823DDE8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0823DDE4: .4byte _0823DDE8
_0823DDE8: @ jump table
	.4byte _0823DE00 @ case 0
	.4byte _0823DE0C @ case 1
	.4byte _0823DE2E @ case 2
	.4byte _0823DE1A @ case 3
	.4byte _0823DE24 @ case 4
	.4byte _0823DE2E @ case 5
_0823DE00:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Div
	asrs r0, r0, #1
	b _0823DE30
_0823DE0C:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Div
	asrs r0, r0, #1
	adds r0, #0x20
	b _0823DE30
_0823DE1A:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Div
	b _0823DE30
_0823DE24:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Div
	b _0823DE30
_0823DE2E:
	movs r0, #0
_0823DE30:
	strb r0, [r5, #0xf]
_0823DE32:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0823de38
FUN_0823de38: @ 0x0823DE38
	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r2, _0823DE80 @ =0x030047E0
	strb r3, [r2, #0xa]
	strb r1, [r2, #0xb]
	ldr r0, _0823DE84 @ =0x030047A8
	ldr r0, [r0]
	ldrb r0, [r0, #0xb]
	cmp r0, #0
	beq _0823DE5E
	adds r0, r3, #1
	strb r0, [r2, #0xa]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x17
	bls _0823DE5E
	adds r0, r3, #0
	subs r0, #0x17
	strb r0, [r2, #0xa]
_0823DE5E:
	adds r5, r2, #0
	ldrb r1, [r5, #0xc]
	ldrb r0, [r5, #4]
	subs r3, r1, r0
	ldrb r1, [r5, #0xd]
	ldrb r0, [r5, #5]
	subs r4, r1, r0
	cmp r3, #0
	bge _0823DE72
	adds r3, #0x18
_0823DE72:
	cmp r4, #0
	bge _0823DE8C
	cmp r3, #0
	ble _0823DE88
	subs r3, #1
	b _0823DE8A
	.align 2, 0
_0823DE80: .4byte 0x030047E0
_0823DE84: .4byte 0x030047A8
_0823DE88:
	movs r3, #0x17
_0823DE8A:
	adds r4, #0x3c
_0823DE8C:
	ldrb r1, [r5, #0xa]
	ldrb r0, [r5, #4]
	subs r2, r1, r0
	ldrb r1, [r5, #0xb]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	cmp r2, #0
	bge _0823DE9E
	adds r2, #0x18
_0823DE9E:
	cmp r1, #0
	bge _0823DEAE
	cmp r2, #0
	ble _0823DEAA
	subs r2, #1
	b _0823DEAC
_0823DEAA:
	movs r2, #0x17
_0823DEAC:
	adds r1, #0x3c
_0823DEAE:
	strb r3, [r5, #0x10]
	strb r4, [r5, #0x11]
	strb r2, [r5, #0x12]
	strb r1, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _0823DEC8
	movs r0, #0x3c
	subs r0, r0, r4
	b _0823DECC
_0823DEC8:
	movs r0, #0x3c
	subs r0, r0, r1
_0823DECC:
	lsls r4, r0, #6
	bl FUN_0823e1b0
	strb r0, [r5, #0xe]
	ldrb r0, [r5, #0xe]
	cmp r0, #5
	bhi _0823DF32
	lsls r0, r0, #2
	ldr r1, _0823DEE4 @ =_0823DEE8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0823DEE4: .4byte _0823DEE8
_0823DEE8: @ jump table
	.4byte _0823DF00 @ case 0
	.4byte _0823DF0C @ case 1
	.4byte _0823DF2E @ case 2
	.4byte _0823DF1A @ case 3
	.4byte _0823DF24 @ case 4
	.4byte _0823DF2E @ case 5
_0823DF00:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Div
	asrs r0, r0, #1
	b _0823DF30
_0823DF0C:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Div
	asrs r0, r0, #1
	adds r0, #0x20
	b _0823DF30
_0823DF1A:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Div
	b _0823DF30
_0823DF24:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Div
	b _0823DF30
_0823DF2E:
	movs r0, #0
_0823DF30:
	strb r0, [r5, #0xf]
_0823DF32:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0823df38
FUN_0823df38: @ 0x0823DF38
	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r2, _0823DF80 @ =0x030047E0
	strb r3, [r2, #0xc]
	strb r1, [r2, #0xd]
	ldr r0, _0823DF84 @ =0x030047A8
	ldr r0, [r0]
	ldrb r0, [r0, #0xb]
	cmp r0, #0
	beq _0823DF5E
	adds r0, r3, #1
	strb r0, [r2, #0xc]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x17
	bls _0823DF5E
	adds r0, r3, #0
	subs r0, #0x17
	strb r0, [r2, #0xc]
_0823DF5E:
	adds r5, r2, #0
	ldrb r1, [r5, #0xc]
	ldrb r0, [r5, #4]
	subs r3, r1, r0
	ldrb r1, [r5, #0xd]
	ldrb r0, [r5, #5]
	subs r4, r1, r0
	cmp r3, #0
	bge _0823DF72
	adds r3, #0x18
_0823DF72:
	cmp r4, #0
	bge _0823DF8C
	cmp r3, #0
	ble _0823DF88
	subs r3, #1
	b _0823DF8A
	.align 2, 0
_0823DF80: .4byte 0x030047E0
_0823DF84: .4byte 0x030047A8
_0823DF88:
	movs r3, #0x17
_0823DF8A:
	adds r4, #0x3c
_0823DF8C:
	ldrb r1, [r5, #0xa]
	ldrb r0, [r5, #4]
	subs r2, r1, r0
	ldrb r1, [r5, #0xb]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	cmp r2, #0
	bge _0823DF9E
	adds r2, #0x18
_0823DF9E:
	cmp r1, #0
	bge _0823DFAE
	cmp r2, #0
	ble _0823DFAA
	subs r2, #1
	b _0823DFAC
_0823DFAA:
	movs r2, #0x17
_0823DFAC:
	adds r1, #0x3c
_0823DFAE:
	strb r3, [r5, #0x10]
	strb r4, [r5, #0x11]
	strb r2, [r5, #0x12]
	strb r1, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _0823DFC8
	movs r0, #0x3c
	subs r0, r0, r4
	b _0823DFCC
_0823DFC8:
	movs r0, #0x3c
	subs r0, r0, r1
_0823DFCC:
	lsls r4, r0, #6
	bl FUN_0823e1b0
	strb r0, [r5, #0xe]
	ldrb r0, [r5, #0xe]
	cmp r0, #5
	bhi _0823E032
	lsls r0, r0, #2
	ldr r1, _0823DFE4 @ =_0823DFE8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0823DFE4: .4byte _0823DFE8
_0823DFE8: @ jump table
	.4byte _0823E000 @ case 0
	.4byte _0823E00C @ case 1
	.4byte _0823E02E @ case 2
	.4byte _0823E01A @ case 3
	.4byte _0823E024 @ case 4
	.4byte _0823E02E @ case 5
_0823E000:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Div
	asrs r0, r0, #1
	b _0823E030
_0823E00C:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Div
	asrs r0, r0, #1
	adds r0, #0x20
	b _0823E030
_0823E01A:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Div
	b _0823E030
_0823E024:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Div
	b _0823E030
_0823E02E:
	movs r0, #0
_0823E030:
	strb r0, [r5, #0xf]
_0823E032:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0823e038
FUN_0823e038: @ 0x0823E038
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r6, r0, #0
	mov r8, r1
	mov sb, r2
	adds r4, r3, #0
	ldr r5, [sp, #0x24]
	bl FUN_0823db74
	ldr r7, _0823E08C @ =0x030047E0
	str r0, [r7]
	adds r0, r6, #0
	mov r1, r8
	mov r2, sb
	bl FUN_0823daa4
	movs r1, #0
	strb r0, [r7, #8]
	strb r4, [r7, #4]
	strb r5, [r7, #5]
	add r0, sp, #0x28
	ldrb r0, [r0]
	strb r0, [r7, #6]
	strb r1, [r7, #7]
	ldr r2, [sp, #0x2c]
	cmp r2, #1
	bne _0823E090
	ldrb r3, [r7, #4]
	ldrb r0, [r7, #5]
	str r0, [sp]
	ldrb r0, [r7, #6]
	str r0, [sp, #4]
	adds r0, r6, #0
	mov r1, r8
	mov r2, sb
	bl FUN_0823e578
	adds r6, r0, #0
	b _0823E092
	.align 2, 0
_0823E08C: .4byte 0x030047E0
_0823E090:
	movs r6, #1
_0823E092:
	ldr r5, _0823E0B4 @ =0x030047E0
	ldrb r1, [r5, #0xc]
	ldrb r0, [r5, #4]
	subs r3, r1, r0
	ldrb r1, [r5, #0xd]
	ldrb r0, [r5, #5]
	subs r4, r1, r0
	cmp r3, #0
	bge _0823E0A6
	adds r3, #0x18
_0823E0A6:
	cmp r4, #0
	bge _0823E0BC
	cmp r3, #0
	ble _0823E0B8
	subs r3, #1
	b _0823E0BA
	.align 2, 0
_0823E0B4: .4byte 0x030047E0
_0823E0B8:
	movs r3, #0x17
_0823E0BA:
	adds r4, #0x3c
_0823E0BC:
	ldrb r1, [r5, #0xa]
	ldrb r0, [r5, #4]
	subs r2, r1, r0
	ldrb r1, [r5, #0xb]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	cmp r2, #0
	bge _0823E0CE
	adds r2, #0x18
_0823E0CE:
	cmp r1, #0
	bge _0823E0DE
	cmp r2, #0
	ble _0823E0DA
	subs r2, #1
	b _0823E0DC
_0823E0DA:
	movs r2, #0x17
_0823E0DC:
	adds r1, #0x3c
_0823E0DE:
	strb r3, [r5, #0x10]
	strb r4, [r5, #0x11]
	strb r2, [r5, #0x12]
	strb r1, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _0823E0F8
	movs r0, #0x3c
	subs r0, r0, r4
	b _0823E0FC
_0823E0F8:
	movs r0, #0x3c
	subs r0, r0, r1
_0823E0FC:
	lsls r4, r0, #6
	bl FUN_0823e1b0
	strb r0, [r5, #0xe]
	ldrb r0, [r5, #0xe]
	cmp r0, #5
	bhi _0823E162
	lsls r0, r0, #2
	ldr r1, _0823E114 @ =_0823E118
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0823E114: .4byte _0823E118
_0823E118: @ jump table
	.4byte _0823E130 @ case 0
	.4byte _0823E13C @ case 1
	.4byte _0823E15E @ case 2
	.4byte _0823E14A @ case 3
	.4byte _0823E154 @ case 4
	.4byte _0823E15E @ case 5
_0823E130:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Div
	asrs r0, r0, #1
	b _0823E160
_0823E13C:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Div
	asrs r0, r0, #1
	adds r0, #0x20
	b _0823E160
_0823E14A:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Div
	b _0823E160
_0823E154:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Div
	b _0823E160
_0823E15E:
	movs r0, #0
_0823E160:
	strb r0, [r5, #0xf]
_0823E162:
	adds r0, r6, #0
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
