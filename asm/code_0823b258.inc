	.include "asm/macros.inc"

	.syntax unified
	
	.text

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
	bl GetFile
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

@ a.k.a. Map_LoadMap
	thumb_func_start Map_LoadMapScripted
Map_LoadMapScripted: @ 0x0823B5DC
	push {r4, r5, r6, r7, lr}
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	movs r0, #0x68
	movs r1, #0
	bl Script_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x74
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x72
	movs r1, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x7a
	movs r1, #0
	bl Script_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x70
	movs r1, #0
	bl Script_GetKeywordValue
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
	bl Script_GetValue
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

