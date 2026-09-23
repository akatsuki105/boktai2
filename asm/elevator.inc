	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081d21d8
FUN_081d21d8: @ 0x081D21D8
	push {lr}
	adds r1, r0, #0
	adds r0, #0xd6
	ldrh r2, [r0]
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	bne _081D2226
	adds r0, r1, #0
	adds r0, #0xc8
	ldrh r0, [r0]
	cmp r0, #2
	bgt _081D21FC
	cmp r0, #1
	bge _081D2212
	cmp r0, #0
	beq _081D2208
	b _081D2220
_081D21FC:
	cmp r0, #3
	bne _081D2220
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081D2212
_081D2208:
	movs r0, #0xac
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _081D2226
_081D2212:
	ldr r0, _081D221C @ =0x00000261
	bl PlaySound_082406e0
	b _081D2226
	.align 2, 0
_081D221C: .4byte 0x00000261
_081D2220:
	ldr r0, _081D222C @ =0x00000261
	bl PlaySound_082406e0
_081D2226:
	pop {r0}
	bx r0
	.align 2, 0
_081D222C: .4byte 0x00000261

	thumb_func_start FUN_081d2230
FUN_081d2230: @ 0x081D2230
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov ip, r0
	ldr r0, _081D2254 @ =0x03000194
	ldr r0, [r0]
	mov sb, r0
	cmp r0, #0
	beq _081D22FE
	ldr r1, _081D2258 @ =0x000012AC
	add r1, sb
	ldr r0, [r1]
	cmp r0, #0
	bne _081D2264
	b _081D22FE
	.align 2, 0
_081D2254: .4byte 0x03000194
_081D2258: .4byte 0x000012AC
_081D225C:
	mov r0, r8
	adds r0, #0x1c
	add r0, sb
	b _081D2300
_081D2264:
	movs r7, #0
	mov sl, r1
	mov r6, sp
	movs r0, #0
	mov r8, r0
_081D226E:
	movs r1, #1
	lsls r1, r7
	mov r2, sl
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081D2280
	movs r0, #1
	b _081D2282
_081D2280:
	movs r0, #0
_081D2282:
	cmp r0, #0
	beq _081D22F2
	mov r3, sp
	mov r2, r8
	add r2, sb
	movs r4, #0x8c
	lsls r4, r4, #1
	adds r2, r2, r4
	mov r5, ip
	ldrh r0, [r5]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r6]
	ldrh r1, [r5, #2]
	ldrh r0, [r2, #2]
	subs r4, r1, r0
	strh r4, [r3, #2]
	ldrh r1, [r5, #4]
	ldrh r0, [r2, #4]
	subs r1, r1, r0
	str r1, [sp, #8]
	strh r1, [r3, #4]
	ldr r2, _081D2310 @ =0x085AE0D0
	movs r0, #0
	ldrsh r1, [r6, r0]
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmp r1, r0
	bgt _081D22F2
	cmn r1, r0
	blt _081D22F2
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r4, #2
	ldrsh r1, [r2, r4]
	cmp r0, r1
	bgt _081D22F2
	movs r5, #2
	ldrsh r1, [r3, r5]
	movs r4, #2
	ldrsh r0, [r2, r4]
	cmn r1, r0
	blt _081D22F2
	ldr r5, [sp, #8]
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	movs r4, #4
	ldrsh r1, [r2, r4]
	cmp r0, r1
	bgt _081D22F2
	movs r5, #4
	ldrsh r1, [r3, r5]
	movs r3, #4
	ldrsh r0, [r2, r3]
	cmn r1, r0
	bge _081D225C
_081D22F2:
	movs r4, #0xc6
	lsls r4, r4, #1
	add r8, r4
	adds r7, #1
	cmp r7, #0xb
	ble _081D226E
_081D22FE:
	movs r0, #0
_081D2300:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D2310: .4byte 0x085AE0D0

	thumb_func_start FUN_081d2314
FUN_081d2314: @ 0x081D2314
	push {r4, r5, r6, r7, lr}
	movs r2, #0
	ldr r1, _081D233C @ =0x000012AC
	adds r3, r0, r1
	movs r7, #1
	adds r4, r0, #0
	adds r4, #0xcc
	adds r5, r0, #0
	adds r5, #0x1c
	movs r6, #0xc6
	lsls r6, r6, #1
_081D232A:
	adds r1, r7, #0
	lsls r1, r2
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081D2340
	movs r0, #1
	b _081D2342
	.align 2, 0
_081D233C: .4byte 0x000012AC
_081D2340:
	movs r0, #0
_081D2342:
	cmp r0, #0
	bne _081D2356
	adds r1, r7, #0
	lsls r1, r2
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	strh r2, [r4]
	adds r0, r5, #0
	b _081D2362
_081D2356:
	adds r4, r4, r6
	adds r5, r5, r6
	adds r2, #1
	cmp r2, #0xb
	ble _081D232A
	movs r0, #0
_081D2362:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d2368
FUN_081d2368: @ 0x081D2368
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x50
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0xb8
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _081D2388
	subs r0, r2, #1
	b _081D2644
_081D2388:
	adds r0, r5, #0
	adds r0, #0xf9
	ldrb r0, [r0]
	lsrs r6, r0, #6
	cmp r6, #1
	beq _081D23C8
	cmp r6, #1
	bgt _081D239E
	cmp r6, #0
	beq _081D23A8
	b _081D2646
_081D239E:
	cmp r6, #2
	beq _081D23E0
	cmp r6, #3
	beq _081D2410
	b _081D2646
_081D23A8:
	add r0, sp, #0x38
	ldr r1, _081D23C0 @ =0x0000FF40
	strh r1, [r0]
	strh r1, [r0, #2]
	strh r6, [r0, #4]
	strh r1, [r0, #8]
	strh r1, [r0, #0xa]
	adds r1, r0, #0
	ldr r0, _081D23C4 @ =0x0000FF80
	strh r0, [r1, #0xc]
	movs r0, #0x3e
	b _081D242C
	.align 2, 0
_081D23C0: .4byte 0x0000FF40
_081D23C4: .4byte 0x0000FF80
_081D23C8:
	add r0, sp, #0x38
	ldr r2, _081D23D8 @ =0x0000FFC0
	strh r2, [r0]
	ldr r3, _081D23DC @ =0x0000FF40
	strh r3, [r0, #2]
	strh r2, [r0, #4]
	adds r1, r0, #0
	b _081D2420
	.align 2, 0
_081D23D8: .4byte 0x0000FFC0
_081D23DC: .4byte 0x0000FF40
_081D23E0:
	add r0, sp, #0x38
	ldr r3, _081D2404 @ =0x0000FF7C
	strh r3, [r0]
	ldr r2, _081D2408 @ =0x0000FF40
	strh r2, [r0, #2]
	adds r1, r0, #0
	ldr r0, _081D240C @ =0x0000FFE0
	strh r0, [r1, #4]
	adds r0, r1, #0
	strh r3, [r0, #8]
	strh r2, [r0, #0xa]
	strh r2, [r0, #0xc]
	movs r0, #0x3e
	mov ip, r0
	movs r1, #4
	mov sl, r1
	movs r3, #0x18
	b _081D2434
	.align 2, 0
_081D2404: .4byte 0x0000FF7C
_081D2408: .4byte 0x0000FF40
_081D240C: .4byte 0x0000FFE0
_081D2410:
	add r1, sp, #0x38
	ldr r0, _081D2448 @ =0x0000FFC0
	strh r0, [r1]
	adds r0, r1, #0
	ldr r3, _081D244C @ =0x0000FF40
	strh r3, [r0, #2]
	ldr r2, _081D2450 @ =0x0000FFE0
	strh r2, [r0, #4]
_081D2420:
	ldr r0, _081D2454 @ =0x0000FF24
	strh r0, [r1, #8]
	adds r0, r1, #0
	strh r3, [r0, #0xa]
	strh r2, [r0, #0xc]
	movs r0, #0x40
_081D242C:
	mov ip, r0
	movs r1, #4
	mov sl, r1
	movs r3, #0x20
_081D2434:
	mov sb, r3
	adds r0, r5, #0
	adds r0, #0xe7
	ldrb r7, [r0]
	cmp r7, #0
	beq _081D2458
	cmp r7, #3
	bne _081D2446
	b _081D254A
_081D2446:
	b _081D2646
	.align 2, 0
_081D2448: .4byte 0x0000FFC0
_081D244C: .4byte 0x0000FF40
_081D2450: .4byte 0x0000FFE0
_081D2454: .4byte 0x0000FF24
_081D2458:
	movs r0, #0xca
	adds r0, r0, r5
	mov r8, r0
	ldrh r0, [r0]
	cmp r0, #0
	bne _081D24EC
	adds r1, r5, #0
	adds r1, #0xfc
	add r0, sp, #0x38
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _081D24E4 @ =0xFFFF0000
	ldr r2, [sp, #0x48]
	ands r2, r3
	orrs r2, r0
	str r2, [sp, #0x48]
	adds r4, r5, #0
	adds r4, #0xfe
	add r0, sp, #0x38
	ldrh r1, [r0, #2]
	ldrh r4, [r4]
	adds r1, r1, r4
	lsls r1, r1, #0x10
	ldr r0, _081D24E8 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x48]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r5, r0
	add r0, sp, #0x38
	ldrh r2, [r0, #4]
	ldrh r1, [r1]
	adds r2, r2, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	add r0, sp, #0x48
	ldr r1, [r0, #4]
	ands r1, r3
	orrs r1, r2
	str r1, [r0, #4]
	movs r1, #4
	str r1, [sp]
	movs r1, #0x18
	str r1, [sp, #4]
	str r6, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	mov r3, ip
	str r3, [sp, #0x10]
	movs r1, #3
	str r1, [sp, #0x14]
	movs r1, #2
	str r1, [sp, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp, #0x1c]
	movs r1, #0x16
	movs r2, #8
	mov r3, sl
	bl FUN_081ee584
	movs r0, #1
	mov r1, r8
	strh r0, [r1]
	b _081D263E
	.align 2, 0
_081D24E4: .4byte 0xFFFF0000
_081D24E8: .4byte 0x0000FFFF
_081D24EC:
	adds r2, r5, #0
	adds r2, #0xfc
	add r0, sp, #0x38
	ldrh r1, [r0, #8]
	ldrh r2, [r2]
	adds r1, r1, r2
	add r0, sp, #0x48
	strh r1, [r0]
	adds r2, r5, #0
	adds r2, #0xfe
	add r1, sp, #0x38
	ldrh r1, [r1, #0xa]
	ldrh r2, [r2]
	adds r1, r1, r2
	strh r1, [r0, #2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r2, r5, r3
	add r1, sp, #0x38
	ldrh r1, [r1, #0xc]
	ldrh r2, [r2]
	adds r1, r1, r2
	strh r1, [r0, #4]
	movs r1, #4
	str r1, [sp]
	movs r1, #0x18
	str r1, [sp, #4]
	str r6, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	mov r3, ip
	str r3, [sp, #0x10]
	movs r1, #3
	str r1, [sp, #0x14]
	movs r1, #2
	str r1, [sp, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp, #0x1c]
	movs r1, #0x16
	movs r2, #8
	mov r3, sl
	bl FUN_081ee584
	mov r0, r8
	strh r7, [r0]
	b _081D263E
_081D254A:
	movs r1, #0xca
	adds r1, r1, r5
	mov r8, r1
	ldrh r3, [r1]
	cmp r3, #0
	bne _081D25D0
	adds r2, r5, #0
	adds r2, #0xfc
	add r0, sp, #0x38
	ldrh r1, [r0]
	ldrh r2, [r2]
	adds r1, r1, r2
	add r0, sp, #0x48
	strh r1, [r0]
	adds r2, r5, #0
	adds r2, #0xfe
	add r1, sp, #0x38
	ldrh r1, [r1, #2]
	ldrh r2, [r2]
	adds r1, r1, r2
	strh r1, [r0, #2]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r2, r5, r1
	add r1, sp, #0x38
	ldrh r1, [r1, #4]
	ldrh r2, [r2]
	adds r1, r1, r2
	strh r1, [r0, #4]
	movs r1, #4
	str r1, [sp]
	movs r1, #0x18
	str r1, [sp, #4]
	str r6, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	mov r1, ip
	str r1, [sp, #0x10]
	str r7, [sp, #0x14]
	movs r1, #2
	str r1, [sp, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp, #0x1c]
	str r3, [sp, #0x20]
	ldr r1, _081D25C8 @ =0x0000F422
	str r1, [sp, #0x24]
	ldr r1, _081D25CC @ =0x0000121B
	str r1, [sp, #0x28]
	str r3, [sp, #0x2c]
	str r3, [sp, #0x30]
	movs r1, #0xda
	str r1, [sp, #0x34]
	movs r1, #0x16
	movs r2, #8
	mov r3, sl
	bl FUN_081ee53c
	movs r0, #1
	mov r3, r8
	strh r0, [r3]
	b _081D263E
	.align 2, 0
_081D25C8: .4byte 0x0000F422
_081D25CC: .4byte 0x0000121B
_081D25D0:
	adds r2, r5, #0
	adds r2, #0xfc
	add r0, sp, #0x38
	ldrh r1, [r0, #8]
	ldrh r2, [r2]
	adds r1, r1, r2
	movs r4, #0
	add r0, sp, #0x48
	strh r1, [r0]
	adds r2, r5, #0
	adds r2, #0xfe
	add r1, sp, #0x38
	ldrh r1, [r1, #0xa]
	ldrh r2, [r2]
	adds r1, r1, r2
	strh r1, [r0, #2]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r2, r5, r1
	add r1, sp, #0x38
	ldrh r1, [r1, #0xc]
	ldrh r2, [r2]
	adds r1, r1, r2
	strh r1, [r0, #4]
	movs r1, #4
	str r1, [sp]
	movs r1, #0x18
	str r1, [sp, #4]
	str r6, [sp, #8]
	mov r3, sb
	str r3, [sp, #0xc]
	mov r1, ip
	str r1, [sp, #0x10]
	str r7, [sp, #0x14]
	movs r1, #2
	str r1, [sp, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp, #0x1c]
	str r4, [sp, #0x20]
	ldr r1, _081D2658 @ =0x0000F422
	str r1, [sp, #0x24]
	ldr r1, _081D265C @ =0x0000121B
	str r1, [sp, #0x28]
	str r4, [sp, #0x2c]
	str r4, [sp, #0x30]
	movs r1, #0xda
	str r1, [sp, #0x34]
	movs r1, #0x16
	movs r2, #8
	mov r3, sl
	bl FUN_081ee53c
	mov r3, r8
	strh r4, [r3]
_081D263E:
	adds r1, r5, #0
	adds r1, #0xb8
	movs r0, #4
_081D2644:
	strh r0, [r1]
_081D2646:
	add sp, #0x50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D2658: .4byte 0x0000F422
_081D265C: .4byte 0x0000121B

	thumb_func_start FUN_081d2660
FUN_081d2660: @ 0x081D2660
	push {r4, r5, r6, r7, lr}
	adds r5, r2, #0
	adds r6, r3, #0
	ldr r0, [r0, #8]
	ldrh r4, [r0]
	movs r2, #0
	ldrsh r3, [r1, r2]
	ldrh r2, [r0, #2]
	movs r7, #4
	ldrsh r0, [r1, r7]
	subs r2, r2, r0
	subs r4, r4, r3
	cmp r4, #0
	bge _081D267E
	rsbs r4, r4, #0
_081D267E:
	cmp r4, r5
	bhi _081D2690
	cmp r2, #0
	bge _081D2688
	rsbs r2, r2, #0
_081D2688:
	cmp r2, r6
	bhi _081D2690
	movs r0, #1
	b _081D2692
_081D2690:
	movs r0, #0
_081D2692:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d2698
FUN_081d2698: @ 0x081D2698
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	adds r0, r6, #0
	movs r1, #8
	bl ClearMemory
	ldr r2, [r4, #8]
	ldrh r1, [r2]
	movs r3, #8
	ldrsh r0, [r5, r3]
	subs r3, r1, r0
	ldrh r1, [r2, #2]
	movs r2, #0xc
	ldrsh r0, [r5, r2]
	subs r1, r1, r0
	adds r0, r3, #0
	cmp r3, #0
	bge _081D26C4
	rsbs r0, r3, #0
_081D26C4:
	cmp r0, r7
	bhi _081D26EA
	adds r2, r1, #0
	cmp r1, #0
	bge _081D26D0
	rsbs r2, r1, #0
_081D26D0:
	ldr r0, [sp, #0x14]
	cmp r2, r0
	bhi _081D26EA
	ldrh r0, [r5, #8]
	adds r0, r0, r3
	strh r0, [r5, #8]
	ldrh r0, [r5, #0xc]
	adds r0, r0, r1
	strh r0, [r5, #0xc]
	strh r3, [r6]
	strh r1, [r6, #4]
	movs r0, #1
	b _081D2764
_081D26EA:
	cmp r3, #0
	bne _081D26F2
	cmp r1, #0
	beq _081D2762
_081D26F2:
	adds r0, r3, #0
	bl ArcTan2_8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	lsls r3, r0, #6
	strb r3, [r5, #5]
	ldr r1, _081D2724 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x18]
	muls r0, r2, r0
	cmp r0, #0
	blt _081D2728
	asrs r0, r0, #0xc
	b _081D272E
	.align 2, 0
_081D2724: .4byte 0x085B0A08
_081D2728:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D272E:
	adds r2, r0, #0
	ldr r0, _081D2748 @ =0x085B0A08
	lsls r1, r3, #1
	adds r1, r1, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	ldr r1, [sp, #0x18]
	muls r0, r1, r0
	cmp r0, #0
	blt _081D274C
	asrs r1, r0, #0xc
	b _081D2752
	.align 2, 0
_081D2748: .4byte 0x085B0A08
_081D274C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D2752:
	ldrh r0, [r5, #8]
	adds r0, r0, r2
	strh r0, [r5, #8]
	ldrh r0, [r5, #0xc]
	adds r0, r0, r1
	strh r0, [r5, #0xc]
	strh r2, [r6]
	strh r1, [r6, #4]
_081D2762:
	movs r0, #0
_081D2764:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d276c
FUN_081d276c: @ 0x081D276C
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	ldr r0, _081D27A8 @ =0x03000194
	ldr r0, [r0]
	adds r6, r3, #0
	adds r6, #0xd4
	ldr r1, _081D27AC @ =0x000012B0
	adds r5, r0, r1
	ldr r2, _081D27B0 @ =0x03002BE0
	movs r4, #0
_081D2780:
	ldr r1, [r2]
	cmp r1, #0
	beq _081D27B8
	ldrh r0, [r6]
	ldrh r7, [r5]
	cmp r0, r7
	bne _081D27B8
	adds r0, r3, #0
	adds r0, #0xb2
	ldrh r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _081D27B4
	movs r7, #0xde
	lsls r7, r7, #1
	adds r0, r1, r7
	b _081D27B6
	.align 2, 0
_081D27A8: .4byte 0x03000194
_081D27AC: .4byte 0x000012B0
_081D27B0: .4byte 0x03002BE0
_081D27B4:
	movs r0, #0
_081D27B6:
	str r0, [r1, #0x3c]
_081D27B8:
	adds r2, #4
	subs r4, #1
	cmp r4, #0
	bge _081D2780
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d27c8
FUN_081d27c8: @ 0x081D27C8
	push {r4, lr}
	ldr r4, _081D27E4 @ =0x03002BE0
	ldr r0, [r4]
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	beq _081D27E8
	movs r0, #3
	bl FUN_08086978
	cmp r0, #0
	bne _081D2804
	b _081D27F2
	.align 2, 0
_081D27E4: .4byte 0x03002BE0
_081D27E8:
	movs r0, #3
	bl FUN_08086978
	cmp r0, #0
	beq _081D2804
_081D27F2:
	ldr r0, [r4]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #6
	bne _081D2804
	movs r0, #1
	b _081D2806
_081D2804:
	movs r0, #0
_081D2806:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d280c
FUN_081d280c: @ 0x081D280C
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d2810
FUN_081d2810: @ 0x081D2810
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r5, r0, #0
	adds r0, #0x58
	movs r1, #8
	bl ClearMemory
	ldr r0, _081D2874 @ =0x03002BE0
	mov r4, sp
	adds r2, r5, #0
	adds r2, #0xfc
	ldr r0, [r0]
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
	ldrh r0, [r3, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	adds r4, r5, #0
	adds r4, #0xb6
	ldrb r0, [r4]
	cmp r0, #0
	beq _081D2860
	adds r0, r5, #0
	bl FUN_081d21d8
	movs r0, #0
	strb r0, [r4]
_081D2860:
	movs r2, #4
	adds r1, r5, #0
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _081D2878
	movs r0, #1
	b _081D287A
	.align 2, 0
_081D2874: .4byte 0x03002BE0
_081D2878:
	movs r0, #0
_081D287A:
	cmp r0, #0
	beq _081D2880
	b _081D29F2
_081D2880:
	movs r1, #2
	ldrh r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081D288E
	movs r0, #1
	b _081D2890
_081D288E:
	movs r0, #0
_081D2890:
	mov sb, r0
	cmp r0, #0
	beq _081D2950
	adds r4, r5, #0
	adds r4, #0xfe
	adds r1, r5, #0
	adds r1, #0xba
	ldrh r0, [r1]
	ldrh r2, [r4]
	adds r0, r0, r2
	strh r0, [r4]
	ldrh r0, [r1]
	movs r1, #0x5a
	adds r1, r1, r5
	mov r8, r1
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xd0
	movs r2, #0
	ldrsh r1, [r4, r2]
	ldr r0, [r0]
	cmp r0, r1
	ble _081D28C0
	b _081D29F2
_081D28C0:
	strh r0, [r4]
	ldr r6, _081D293C @ =0x03002BE0
	ldr r0, [r6]
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	beq _081D28F4
	ldr r0, [r6]
	ldr r1, [r0, #0x2c]
	ldr r2, [r0, #0x30]
	str r1, [sp]
	str r2, [sp, #4]
	ldrh r2, [r4]
	mov r1, sp
	strh r2, [r1, #2]
	bl FUN_0807a91c
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r7]
	orrs r0, r1
	strh r0, [r7]
	movs r0, #0
	mov r1, r8
	strh r0, [r1]
_081D28F4:
	adds r0, r5, #0
	adds r0, #0xb2
	movs r1, #4
	strh r1, [r0]
	adds r2, r5, #0
	adds r2, #0xb6
	movs r0, #1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xd6
	ldrh r0, [r0]
	ands r1, r0
	cmp r1, #0
	bne _081D29F2
	movs r0, #0xac
	lsls r0, r0, #1
	bl sound_08240740
	ldr r0, _081D2940 @ =0x00000261
	bl sound_08240740
	ldr r0, _081D2944 @ =0x00000289
	bl sound_08240740
	ldr r0, _081D2948 @ =0x0000028A
	bl sound_08240740
	movs r0, #0xa2
	lsls r0, r0, #2
	bl sound_08240740
	ldr r0, _081D294C @ =0x00000159
	bl PlaySound_082406e0
	b _081D29F2
	.align 2, 0
_081D293C: .4byte 0x03002BE0
_081D2940: .4byte 0x00000261
_081D2944: .4byte 0x00000289
_081D2948: .4byte 0x0000028A
_081D294C: .4byte 0x00000159
_081D2950:
	adds r4, r5, #0
	adds r4, #0xfe
	adds r2, r5, #0
	adds r2, #0xba
	ldrh r0, [r4]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r2]
	rsbs r0, r0, #0
	movs r2, #0x5a
	adds r2, r2, r5
	mov r8, r2
	strh r0, [r2]
	adds r0, r5, #0
	adds r0, #0xcc
	movs r2, #0
	ldrsh r1, [r4, r2]
	ldr r0, [r0]
	cmp r0, r1
	blt _081D29F2
	strh r0, [r4]
	ldr r6, _081D2A00 @ =0x03002BE0
	ldr r0, [r6]
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	beq _081D29AE
	ldr r0, [r6]
	ldr r1, [r0, #0x2c]
	ldr r2, [r0, #0x30]
	str r1, [sp]
	str r2, [sp, #4]
	ldrh r2, [r4]
	mov r1, sp
	strh r2, [r1, #2]
	bl FUN_0807a91c
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r7]
	orrs r0, r1
	strh r0, [r7]
	mov r1, sb
	mov r0, r8
	strh r1, [r0]
_081D29AE:
	adds r0, r5, #0
	adds r0, #0xb2
	movs r1, #4
	strh r1, [r0]
	adds r2, r5, #0
	adds r2, #0xb6
	movs r0, #1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xd6
	ldrh r0, [r0]
	ands r1, r0
	cmp r1, #0
	bne _081D29F2
	movs r0, #0xac
	lsls r0, r0, #1
	bl sound_08240740
	ldr r0, _081D2A04 @ =0x00000261
	bl sound_08240740
	ldr r0, _081D2A08 @ =0x00000289
	bl sound_08240740
	ldr r0, _081D2A0C @ =0x0000028A
	bl sound_08240740
	movs r0, #0xa2
	lsls r0, r0, #2
	bl sound_08240740
	ldr r0, _081D2A10 @ =0x00000159
	bl PlaySound_082406e0
_081D29F2:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D2A00: .4byte 0x03002BE0
_081D2A04: .4byte 0x00000261
_081D2A08: .4byte 0x00000289
_081D2A0C: .4byte 0x0000028A
_081D2A10: .4byte 0x00000159

	thumb_func_start FUN_081d2a14
FUN_081d2a14: @ 0x081D2A14
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r0, #0xf4
	adds r1, r5, #0
	adds r1, #0xe8
	adds r2, r5, #0
	adds r2, #0x58
	adds r4, r5, #0
	adds r4, #0xba
	movs r6, #0
	ldrsh r3, [r4, r6]
	str r3, [sp]
	movs r6, #0
	ldrsh r4, [r4, r6]
	str r4, [sp, #4]
	bl FUN_081d2698
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D2A54
	adds r1, r5, #0
	adds r1, #0xb2
	movs r0, #3
	strh r0, [r1]
	adds r1, #4
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_081d5588
	b _081D2A5A
_081D2A54:
	adds r0, r5, #0
	bl FUN_081d2368
_081D2A5A:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d2a64
FUN_081d2a64: @ 0x081D2A64
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r7, #0
	movs r4, #0
	adds r3, r5, #0
	adds r3, #0xce
	movs r0, #0x1c
	adds r0, r0, r5
	mov ip, r0
_081D2A76:
	ldr r1, _081D2A8C @ =0x000012AC
	adds r0, r5, r1
	movs r1, #1
	lsls r1, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D2A90
	movs r0, #1
	b _081D2A92
	.align 2, 0
_081D2A8C: .4byte 0x000012AC
_081D2A90:
	movs r0, #0
_081D2A92:
	cmp r0, #0
	beq _081D2B10
	movs r0, #0
	ldrsh r2, [r3, r0]
	cmp r2, #6
	beq _081D2B10
	ldrh r1, [r3, #0x24]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _081D2B10
	cmp r2, #1
	beq _081D2AE0
	ldr r1, _081D2AD4 @ =0x000012B4
	adds r4, r5, r1
	ldrb r0, [r4]
	cmp r0, #1
	beq _081D2AB8
	b _081D2BFC
_081D2AB8:
	movs r0, #0xa2
	lsls r0, r0, #2
	bl sound_08240740
	ldr r0, _081D2AD8 @ =0x0000028A
	bl sound_08240740
	ldr r0, _081D2ADC @ =0x00000289
	bl sound_08240740
	movs r0, #0
	strb r0, [r4]
	b _081D2BFC
	.align 2, 0
_081D2AD4: .4byte 0x000012B4
_081D2AD8: .4byte 0x0000028A
_081D2ADC: .4byte 0x00000289
_081D2AE0:
	ldr r1, _081D2B00 @ =0x000012B4
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081D2AEC
	b _081D2BFC
_081D2AEC:
	mov r0, ip
	adds r0, #0xe7
	ldrb r0, [r0]
	cmp r0, #0
	beq _081D2B08
	cmp r0, #3
	beq _081D2BC4
	ldr r0, _081D2B04 @ =0x00000289
	b _081D2BC8
	.align 2, 0
_081D2B00: .4byte 0x000012B4
_081D2B04: .4byte 0x00000289
_081D2B08:
	ldr r0, _081D2B0C @ =0x0000028A
	b _081D2BC8
	.align 2, 0
_081D2B0C: .4byte 0x0000028A
_081D2B10:
	movs r1, #0xc6
	lsls r1, r1, #1
	adds r3, r3, r1
	add ip, r1
	adds r4, #1
	cmp r4, #0xb
	ble _081D2A76
	ldr r4, _081D2B84 @ =0x03002BE0
	ldr r0, [r4]
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	beq _081D2B2E
	movs r7, #1
_081D2B2E:
	ldr r0, [r4]
	ldr r1, _081D2B88 @ =0x00000392
	adds r0, r0, r1
	ldrh r0, [r0]
	bl FUN_081d3118
	adds r2, r0, #0
	cmp r2, #0
	beq _081D2BFC
	adds r0, #0xd6
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	cmp r6, #0
	bne _081D2BFC
	cmp r7, #0
	beq _081D2BDC
	adds r0, r2, #0
	adds r0, #0xb2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	beq _081D2B98
	ldr r0, _081D2B8C @ =0x000012B4
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #1
	bne _081D2BFC
	movs r0, #0xa2
	lsls r0, r0, #2
	bl sound_08240740
	ldr r0, _081D2B90 @ =0x0000028A
	bl sound_08240740
	ldr r0, _081D2B94 @ =0x00000289
	bl sound_08240740
	strb r6, [r4]
	b _081D2BFC
	.align 2, 0
_081D2B84: .4byte 0x03002BE0
_081D2B88: .4byte 0x00000392
_081D2B8C: .4byte 0x000012B4
_081D2B90: .4byte 0x0000028A
_081D2B94: .4byte 0x00000289
_081D2B98:
	ldr r1, _081D2BB4 @ =0x000012B4
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081D2BFC
	adds r0, r2, #0
	adds r0, #0xe7
	ldrb r0, [r0]
	cmp r0, #0
	beq _081D2BBC
	cmp r0, #3
	beq _081D2BC4
	ldr r0, _081D2BB8 @ =0x00000289
	b _081D2BC8
	.align 2, 0
_081D2BB4: .4byte 0x000012B4
_081D2BB8: .4byte 0x00000289
_081D2BBC:
	ldr r0, _081D2BC0 @ =0x0000028A
	b _081D2BC8
	.align 2, 0
_081D2BC0: .4byte 0x0000028A
_081D2BC4:
	movs r0, #0xa2
	lsls r0, r0, #2
_081D2BC8:
	bl PlaySound_082406e0
	ldr r0, _081D2BD8 @ =0x000012B4
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _081D2BFC
	.align 2, 0
_081D2BD8: .4byte 0x000012B4
_081D2BDC:
	ldr r1, _081D2C04 @ =0x000012B4
	adds r4, r5, r1
	ldrb r0, [r4]
	cmp r0, #1
	bne _081D2BFC
	movs r0, #0xa2
	lsls r0, r0, #2
	bl sound_08240740
	ldr r0, _081D2C08 @ =0x0000028A
	bl sound_08240740
	ldr r0, _081D2C0C @ =0x00000289
	bl sound_08240740
	strb r7, [r4]
_081D2BFC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D2C04: .4byte 0x000012B4
_081D2C08: .4byte 0x0000028A
_081D2C0C: .4byte 0x00000289

	thumb_func_start FUN_081d2c10
FUN_081d2c10: @ 0x081D2C10
	push {lr}
	sub sp, #8
	ldr r0, _081D2C58 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x2c]
	ldr r2, [r0, #0x30]
	str r1, [sp]
	str r2, [sp, #4]
	mov r1, sp
	ldrh r2, [r1]
	adds r2, #0x80
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r3, _081D2C5C @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r3
	orrs r1, r2
	str r1, [sp]
	mov r1, sp
	bl FUN_0807a91c
	mov r0, sp
	bl FUN_08086a28
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x80
	mov r1, sp
	strh r0, [r1]
	mov r0, sp
	bl FUN_08086a4c
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_081D2C58: .4byte 0x03002BE0
_081D2C5C: .4byte 0xFFFF0000

	thumb_func_start FUN_081d2c60
FUN_081d2c60: @ 0x081D2C60
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r2, r0, #0
	ldr r0, _081D2CE4 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _081D2CEC
	mov r4, sp
	adds r2, #0xfc
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r2]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r1, [r3, #2]
	ldrh r0, [r2, #2]
	subs r5, r1, r0
	strh r5, [r4, #2]
	ldrh r1, [r3, #4]
	ldrh r0, [r2, #4]
	subs r2, r1, r0
	strh r2, [r4, #4]
	ldr r3, _081D2CE8 @ =0x085AE0D0
	mov r0, sp
	movs r6, #0
	ldrsh r1, [r0, r6]
	movs r6, #0
	ldrsh r0, [r3, r6]
	cmp r1, r0
	bgt _081D2CEC
	mov r0, sp
	movs r6, #0
	ldrsh r1, [r0, r6]
	movs r6, #0
	ldrsh r0, [r3, r6]
	cmn r1, r0
	blt _081D2CEC
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	movs r5, #2
	ldrsh r1, [r3, r5]
	cmp r0, r1
	bgt _081D2CEC
	movs r6, #2
	ldrsh r1, [r4, r6]
	movs r5, #2
	ldrsh r0, [r3, r5]
	cmn r1, r0
	blt _081D2CEC
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	movs r6, #4
	ldrsh r1, [r3, r6]
	cmp r0, r1
	bgt _081D2CEC
	movs r0, #4
	ldrsh r1, [r4, r0]
	movs r2, #4
	ldrsh r0, [r3, r2]
	cmn r1, r0
	blt _081D2CEC
	movs r0, #1
	b _081D2CEE
	.align 2, 0
_081D2CE4: .4byte 0x03002BE0
_081D2CE8: .4byte 0x085AE0D0
_081D2CEC:
	movs r0, #0
_081D2CEE:
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d2cf8
FUN_081d2cf8: @ 0x081D2CF8
	push {r4, r5, r6, lr}
	sub sp, #0x20
	adds r4, r0, #0
	adds r0, #0xb6
	ldrb r0, [r0]
	cmp r0, #0
	beq _081D2D96
	ldr r0, _081D2D3C @ =0x03000194
	ldr r0, [r0]
	adds r1, r4, #0
	adds r1, #0xd4
	ldr r2, _081D2D40 @ =0x000012B0
	adds r0, r0, r2
	ldrh r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	bne _081D2D88
	adds r0, r4, #0
	adds r0, #0xc2
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	beq _081D2D88
	adds r0, #0x25
	ldrb r1, [r0]
	cmp r1, #2
	bne _081D2D52
	subs r0, #0x33
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D2D44
	movs r0, #1
	b _081D2D46
	.align 2, 0
_081D2D3C: .4byte 0x03000194
_081D2D40: .4byte 0x000012B0
_081D2D44:
	movs r0, #0
_081D2D46:
	cmp r0, #0
	beq _081D2D4E
	movs r0, #2
	b _081D2D58
_081D2D4E:
	movs r0, #1
	b _081D2D58
_081D2D52:
	adds r0, r4, #0
	adds r0, #0xea
	ldrb r0, [r0]
_081D2D58:
	str r0, [sp]
	adds r0, r4, #0
	adds r0, #0xfc
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #4]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #8]
	ldr r1, _081D2DF0 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r1
	movs r1, #3
	orrs r0, r1
	str r0, [sp, #0xc]
	add r1, sp, #0xc
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_081D2D88:
	adds r1, r4, #0
	adds r1, #0xb6
	movs r0, #0
	strb r0, [r1]
	adds r1, #2
	movs r0, #1
	strh r0, [r1]
_081D2D96:
	adds r0, r4, #0
	bl FUN_081d27c8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D2DA4
	b _081D2EFA
_081D2DA4:
	adds r0, r4, #0
	adds r0, #0xd6
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081D2E78
	adds r0, r4, #0
	adds r0, #0xb8
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r1, r4, #0
	adds r1, #0xbc
	adds r5, r0, #0
	adds r6, r1, #0
	ldrh r0, [r6]
	cmp r2, r0
	blt _081D2E60
	adds r0, r4, #0
	bl FUN_081d2c60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D2E60
	adds r0, r4, #0
	adds r0, #0xb2
	movs r2, #2
	strh r2, [r0]
	adds r1, r4, #0
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081D2DF4
	movs r0, #1
	b _081D2DF6
	.align 2, 0
_081D2DF0: .4byte 0xFFFF0000
_081D2DF4:
	movs r0, #0
_081D2DF6:
	cmp r0, #0
	beq _081D2E04
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	b _081D2E0A
_081D2E04:
	movs r0, #2
	ldrh r1, [r2]
	orrs r0, r1
_081D2E0A:
	strh r0, [r2]
	movs r0, #0
	strh r0, [r5]
	adds r0, r4, #0
	adds r0, #0xb6
	movs r5, #1
	strb r5, [r0]
	ldr r0, _081D2E54 @ =0x03000194
	ldr r0, [r0]
	adds r3, r4, #0
	adds r3, #0xd4
	ldr r1, _081D2E58 @ =0x000012B0
	adds r0, r0, r1
	ldrh r1, [r3]
	ldrh r0, [r0]
	cmp r1, r0
	bne _081D2EFA
	adds r2, r4, #0
	adds r2, #0xc4
	ldrh r0, [r2]
	cmp r0, #0
	beq _081D2EFA
	adds r0, r1, #0
	str r0, [sp, #0x14]
	ldr r1, _081D2E5C @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r1
	orrs r0, r5
	str r0, [sp, #0x18]
	add r0, sp, #0x14
	add r1, sp, #0x18
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
	b _081D2EFA
	.align 2, 0
_081D2E54: .4byte 0x03000194
_081D2E58: .4byte 0x000012B0
_081D2E5C: .4byte 0xFFFF0000
_081D2E60:
	movs r2, #0
	ldrsh r1, [r5, r2]
	ldrh r0, [r6]
	subs r0, #0xa
	cmp r1, r0
	ble _081D2E78
	movs r0, #0x20
	adds r2, r4, #0
	adds r2, #0xb4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D2E78:
	ldr r0, _081D2EAC @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x2c
	bl FUN_081d2230
	adds r3, r0, #0
	cmp r3, #0
	beq _081D2EF0
	adds r0, #0xd4
	adds r1, r4, #0
	adds r1, #0xd4
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _081D2EFA
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r4, #0
	adds r0, #0xb4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D2EB0
	movs r0, #1
	b _081D2EB2
	.align 2, 0
_081D2EAC: .4byte 0x03002BE0
_081D2EB0:
	movs r0, #0
_081D2EB2:
	adds r5, r4, #0
	adds r5, #0xb8
	cmp r0, #0
	bne _081D2ED0
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bne _081D2ED0
	adds r0, r4, #0
	adds r0, #0xc6
	ldr r1, _081D2EE4 @ =0x0000FFE0
	strh r1, [r0]
	ldr r0, _081D2EE8 @ =0x00000222
	bl PlaySound_082406e0
_081D2ED0:
	ldrh r2, [r5]
	movs r0, #0
	ldrsh r1, [r5, r0]
	ldr r0, _081D2EEC @ =0x00007CFF
	cmp r1, r0
	bgt _081D2EFA
	adds r0, r2, #1
	strh r0, [r5]
	b _081D2EFA
	.align 2, 0
_081D2EE4: .4byte 0x0000FFE0
_081D2EE8: .4byte 0x00000222
_081D2EEC: .4byte 0x00007CFF
_081D2EF0:
	adds r0, r4, #0
	adds r0, #0xb8
	strh r3, [r0]
	adds r0, #0xe
	strh r3, [r0]
_081D2EFA:
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d2f04
FUN_081d2f04: @ 0x081D2F04
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0xc6
	ldrh r1, [r4]
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, #0
	bge _081D2F2C
	ldrh r2, [r7, #0x1e]
	adds r0, r1, r2
	strh r0, [r7, #0x1e]
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #2
	bl Div
	strh r0, [r4]
_081D2F2C:
	movs r2, #0x80
	adds r1, r7, #0
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _081D2F40
	movs r0, #1
	b _081D2F42
_081D2F40:
	movs r0, #0
_081D2F42:
	cmp r0, #0
	bne _081D2FAE
	movs r1, #0x20
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D2F54
	movs r0, #1
	b _081D2F56
_081D2F54:
	movs r0, #0
_081D2F56:
	cmp r0, #0
	beq _081D2FB8
	ldr r2, _081D2FC4 @ =0x0203B400
	mov r8, r2
	ldr r4, _081D2FC8 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _081D2FCC @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0xc
	bl Mod
	ldrh r1, [r7, #0x1c]
	subs r1, #6
	adds r1, r1, r0
	strh r1, [r7, #0x1c]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	lsls r1, r0, #1
	add r1, r8
	ldrh r1, [r1]
	movs r2, #3
	ands r1, r2
	ldrh r2, [r7, #0x1e]
	adds r1, r1, r2
	strh r1, [r7, #0x1e]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0xc
	bl Mod
	ldrh r1, [r7, #0x20]
	subs r1, #6
	adds r1, r1, r0
	strh r1, [r7, #0x20]
_081D2FAE:
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
_081D2FB8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D2FC4: .4byte 0x0203B400
_081D2FC8: .4byte 0x030046B8
_081D2FCC: .4byte 0x000003FF

	thumb_func_start FUN_081d2fd0
FUN_081d2fd0: @ 0x081D2FD0
	push {r4, r5, r6, lr}
	sub sp, #0x20
	adds r5, r0, #0
	adds r0, #0xb6
	ldrb r0, [r0]
	cmp r0, #0
	beq _081D306E
	ldr r0, _081D3014 @ =0x03000194
	ldr r0, [r0]
	adds r1, r5, #0
	adds r1, #0xd4
	ldr r2, _081D3018 @ =0x000012B0
	adds r0, r0, r2
	ldrh r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	bne _081D3060
	adds r0, r5, #0
	adds r0, #0xc2
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	beq _081D3060
	adds r0, #0x25
	ldrb r1, [r0]
	cmp r1, #2
	bne _081D302A
	subs r0, #0x33
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D301C
	movs r0, #1
	b _081D301E
	.align 2, 0
_081D3014: .4byte 0x03000194
_081D3018: .4byte 0x000012B0
_081D301C:
	movs r0, #0
_081D301E:
	cmp r0, #0
	beq _081D3026
	movs r0, #2
	b _081D3030
_081D3026:
	movs r0, #1
	b _081D3030
_081D302A:
	adds r0, r5, #0
	adds r0, #0xea
	ldrb r0, [r0]
_081D3030:
	str r0, [sp]
	adds r0, r5, #0
	adds r0, #0xfc
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #4]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #8]
	ldr r1, _081D30F0 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r1
	movs r1, #3
	orrs r0, r1
	str r0, [sp, #0xc]
	add r1, sp, #0xc
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_081D3060:
	adds r0, r5, #0
	adds r0, #0xb8
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	subs r0, #2
	strb r2, [r0]
_081D306E:
	ldr r6, _081D30F4 @ =0x03000194
	adds r0, r5, #0
	bl FUN_081d27c8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D3108
	adds r4, r5, #0
	adds r4, #0xe8
	ldrb r1, [r4, #3]
	adds r0, r1, #1
	strb r0, [r4, #3]
	lsls r1, r1, #0x18
	ldr r0, [r4, #8]
	ldrh r2, [r0, #4]
	ldr r0, _081D30F8 @ =0x00000FFF
	lsrs r1, r1, #0x18
	ands r0, r2
	cmp r1, r0
	blo _081D3108
	adds r0, r4, #0
	bl FUN_08234e3c
	adds r1, r5, #0
	adds r1, #0xfc
	adds r0, r4, #0
	movs r2, #0x10
	movs r3, #0x10
	bl FUN_08235038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D3100
	adds r0, r5, #0
	adds r0, #0xb2
	movs r4, #1
	strh r4, [r0]
	ldr r0, [r6]
	adds r2, r5, #0
	adds r2, #0xd4
	ldr r1, _081D30FC @ =0x000012B0
	adds r0, r0, r1
	ldrh r1, [r2]
	ldrh r0, [r0]
	cmp r1, r0
	bne _081D3108
	adds r3, r5, #0
	adds r3, #0xc4
	ldrh r0, [r3]
	cmp r0, #0
	beq _081D3108
	adds r0, r1, #0
	str r0, [sp, #0x14]
	ldr r1, _081D30F0 @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r1
	orrs r0, r4
	str r0, [sp, #0x18]
	add r0, sp, #0x14
	add r1, sp, #0x18
	str r0, [r1, #4]
	ldrh r0, [r3]
	bl Script_ExecById
	b _081D3108
	.align 2, 0
_081D30F0: .4byte 0xFFFF0000
_081D30F4: .4byte 0x03000194
_081D30F8: .4byte 0x00000FFF
_081D30FC: .4byte 0x000012B0
_081D3100:
	adds r1, r5, #0
	adds r1, #0xb2
	movs r0, #3
	strh r0, [r1]
_081D3108:
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d3110
FUN_081d3110: @ 0x081D3110
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d3114
FUN_081d3114: @ 0x081D3114
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d3118
FUN_081d3118: @ 0x081D3118
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081D3138 @ =0x03000194
	ldr r0, [r0]
	movs r4, #0
	adds r2, r0, #0
	adds r2, #0x1c
	adds r1, r0, #0
	adds r1, #0xf0
	movs r3, #0xc6
	lsls r3, r3, #1
_081D312E:
	ldrh r0, [r1]
	cmp r0, r5
	bne _081D313C
	adds r0, r2, #0
	b _081D3148
	.align 2, 0
_081D3138: .4byte 0x03000194
_081D313C:
	adds r2, r2, r3
	adds r1, r1, r3
	adds r4, #1
	cmp r4, #0xb
	ble _081D312E
	movs r0, #0
_081D3148:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d3150
FUN_081d3150: @ 0x081D3150
	push {r4, r5, lr}
	ldr r0, _081D3180 @ =0x03000194
	ldr r1, [r0]
	movs r3, #0
	ldr r2, _081D3184 @ =0x000012B0
	adds r0, r1, r2
	ldrh r4, [r0]
	adds r0, r1, #0
	adds r0, #0x1c
	adds r1, #0xf0
	movs r2, #0xc6
	lsls r2, r2, #1
_081D3168:
	ldrh r5, [r1]
	cmp r4, r5
	beq _081D317A
	adds r0, r0, r2
	adds r1, r1, r2
	adds r3, #1
	cmp r3, #0xb
	ble _081D3168
	movs r0, #0
_081D317A:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081D3180: .4byte 0x03000194
_081D3184: .4byte 0x000012B0

	thumb_func_start FUN_081d3188
FUN_081d3188: @ 0x081D3188
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, #0xb4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D31A2
	movs r0, #1
	b _081D31A4
_081D31A2:
	movs r0, #0
_081D31A4:
	cmp r0, #0
	beq _081D31E0
	movs r6, #0
	movs r0, #0xb4
	adds r0, r0, r7
	mov r8, r0
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r5, r7, r1
_081D31B6:
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r7, r2
	adds r4, r0, r6
	ldrb r0, [r4]
	cmp r0, #0
	beq _081D31CE
	adds r0, r5, #0
	bl FUN_082342a8
	movs r0, #0
	strb r0, [r4]
_081D31CE:
	adds r5, #0x10
	adds r6, #1
	cmp r6, #3
	ble _081D31B6
	ldr r0, _081D31EC @ =0xFFFFF7FF
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081D31E0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D31EC: .4byte 0xFFFFF7FF

	thumb_func_start FUN_081d31f0
FUN_081d31f0: @ 0x081D31F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov r8, r0
	ldr r0, _081D3244 @ =0x03000194
	ldr r1, [r0]
	cmp r1, #0
	beq _081D323C
	mov r0, r8
	adds r0, #0xd4
	ldr r2, _081D3248 @ =0x000012B0
	adds r1, r1, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _081D323C
	mov r0, r8
	adds r0, #0xe7
	ldrb r0, [r0]
	cmp r0, #2
	beq _081D323C
	ldr r0, _081D324C @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #6
	bne _081D323C
	mov r0, r8
	adds r0, #0xb2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #3
	beq _081D3250
_081D323C:
	mov r0, r8
	bl FUN_081d3188
	b _081D33E2
	.align 2, 0
_081D3244: .4byte 0x03000194
_081D3248: .4byte 0x000012B0
_081D324C: .4byte 0x03002BE0
_081D3250:
	movs r2, #0x80
	lsls r2, r2, #4
	mov r1, r8
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	str r1, [sp, #0x14]
	cmp r0, #0
	beq _081D3266
	movs r0, #1
	b _081D3268
_081D3266:
	movs r0, #0
_081D3268:
	cmp r0, #0
	beq _081D326E
	b _081D33E2
_081D326E:
	mov r0, r8
	adds r0, #0xfc
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D3296
	cmp r1, #0
	blt _081D3296
	ldr r0, _081D329C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D3296
	ldr r0, _081D32A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D32A4
_081D3296:
	movs r0, #0
	b _081D32B2
	.align 2, 0
_081D329C: .4byte 0x030046A8
_081D32A0: .4byte 0x030046AC
_081D32A4:
	ldr r0, _081D32D4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_081D32B2:
	str r0, [sp, #0x10]
	ldr r5, [sp, #0x10]
	adds r5, #1
	movs r1, #0
	mov sl, r1
	movs r2, #0xa4
	lsls r2, r2, #1
	add r2, r8
	str r2, [sp, #0x18]
_081D32C4:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D32D8
	adds r0, #4
	b _081D32E4
	.align 2, 0
_081D32D4: .4byte 0x030046A4
_081D32D8:
	ldr r0, _081D32F4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D32E4:
	ldrh r0, [r0, #2]
	movs r1, #0xc0
	ands r0, r1
	cmp r0, #0
	bne _081D32F8
	movs r0, #0
	b _081D32FA
	.align 2, 0
_081D32F4: .4byte 0x030046A4
_081D32F8:
	movs r0, #1
_081D32FA:
	cmp r0, #0
	beq _081D3390
	mov r0, r8
	adds r0, #0xfe
	ldrh r3, [r0]
	lsls r3, r3, #0x10
	asrs r3, r3, #0x18
	movs r0, #0xff
	str r0, [sp]
	movs r0, #5
	str r0, [sp, #4]
	ldr r0, [sp, #0x18]
	adds r1, r5, #0
	movs r2, #0
	bl FUN_08234270
	movs r0, #0xc4
	lsls r0, r0, #1
	add r0, r8
	add r0, sl
	movs r1, #1
	strb r1, [r0]
	add r0, sp, #8
	mov sb, r0
	ldr r6, _081D3364 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	add r0, sp, #8
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D3368
	adds r0, #4
	b _081D3372
	.align 2, 0
_081D3364: .4byte 0x030046A4
_081D3368:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081D3372:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, sb
	strh r0, [r1, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r2, [sp, #0x14]
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D3390:
	mov r0, sl
	cmp r0, #1
	beq _081D33BC
	cmp r0, #1
	bgt _081D33A0
	cmp r0, #0
	beq _081D33A8
	b _081D33D0
_081D33A0:
	mov r1, sl
	cmp r1, #2
	beq _081D33C2
	b _081D33D0
_081D33A8:
	ldr r0, _081D33B8 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	ldr r1, [sp, #0x10]
	adds r5, r1, r0
	b _081D33D0
	.align 2, 0
_081D33B8: .4byte 0x030046A4
_081D33BC:
	ldr r5, [sp, #0x10]
	subs r5, #1
	b _081D33D0
_081D33C2:
	ldr r0, _081D33F4 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	ldr r1, [sp, #0x10]
	subs r5, r1, r0
_081D33D0:
	ldr r2, [sp, #0x18]
	adds r2, #0x10
	str r2, [sp, #0x18]
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #3
	bgt _081D33E2
	b _081D32C4
_081D33E2:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D33F4: .4byte 0x030046A4

	thumb_func_start FUN_081d33f8
FUN_081d33f8: @ 0x081D33F8
	push {r4, r5, lr}
	sub sp, #8
	mov ip, r0
	adds r0, #0xb2
	ldrh r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _081D343A
	movs r2, #1
	mov r1, ip
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081D3420
	movs r0, #1
	b _081D3422
_081D3420:
	movs r0, #0
_081D3422:
	cmp r0, #0
	beq _081D34E0
	movs r0, #0x9c
	lsls r0, r0, #1
	add r0, ip
	bl FUN_082342a8
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r4]
	ands r0, r1
	b _081D34DE
_081D343A:
	movs r2, #1
	mov r1, ip
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081D344E
	movs r0, #1
	b _081D3450
_081D344E:
	movs r0, #0
_081D3450:
	cmp r0, #0
	bne _081D34E0
	ldr r0, _081D34A0 @ =0x030046A4
	ldr r3, [r0]
	cmp r3, #0
	beq _081D34E0
	mov r2, ip
	adds r2, #0xfe
	ldr r0, _081D34A4 @ =0x03002BE0
	ldr r0, [r0]
	movs r5, #0
	ldrsh r1, [r2, r5]
	movs r5, #0x2e
	ldrsh r0, [r0, r5]
	adds r5, r2, #0
	cmp r1, r0
	bne _081D34E0
	mov r0, ip
	adds r0, #0xfc
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D349A
	cmp r1, #0
	blt _081D349A
	ldr r0, _081D34A8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D349A
	ldr r0, _081D34AC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D34B0
_081D349A:
	movs r2, #0
	b _081D34BC
	.align 2, 0
_081D34A0: .4byte 0x030046A4
_081D34A4: .4byte 0x03002BE0
_081D34A8: .4byte 0x030046A8
_081D34AC: .4byte 0x030046AC
_081D34B0:
	lsls r0, r1, #1
	adds r1, r3, #0
	adds r1, #0x24
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r2, r0, r2
_081D34BC:
	movs r0, #0x9c
	lsls r0, r0, #1
	add r0, ip
	ldrh r3, [r5]
	lsls r3, r3, #0x10
	asrs r3, r3, #0x18
	movs r1, #0xff
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	adds r1, r2, #0
	movs r2, #0
	bl FUN_08234270
	movs r0, #1
	ldrh r1, [r4]
	orrs r0, r1
_081D34DE:
	strh r0, [r4]
_081D34E0:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d34e8
FUN_081d34e8: @ 0x081D34E8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _081D3508 @ =0x03000194
	movs r3, #0
	movs r6, #1
	ldr r1, [r0]
	adds r2, r1, #0
	adds r2, #0xd0
	movs r4, #0xc6
	lsls r4, r4, #1
_081D34FC:
	ldrh r0, [r2]
	ands r0, r6
	cmp r0, #0
	beq _081D350C
	movs r0, #1
	b _081D350E
	.align 2, 0
_081D3508: .4byte 0x03000194
_081D350C:
	movs r0, #0
_081D350E:
	cmp r0, #0
	beq _081D3522
	movs r7, #0xab
	lsls r7, r7, #1
	adds r0, r1, r7
	ldrh r0, [r0]
	cmp r0, r5
	bne _081D3522
	movs r0, #1
	b _081D352E
_081D3522:
	adds r1, r1, r4
	adds r2, r2, r4
	adds r3, #1
	cmp r3, #0xb
	ble _081D34FC
	movs r0, #0
_081D352E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d3534
FUN_081d3534: @ 0x081D3534
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov sl, r0
	movs r0, #0
	str r0, [sp, #8]
	ldr r7, _081D3578 @ =0x03002BE0
	movs r1, #0xfc
	add r1, sl
	mov r8, r1
_081D354E:
	ldr r0, [r7]
	cmp r0, #0
	bne _081D3556
	b _081D3694
_081D3556:
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	bne _081D3562
	b _081D3694
_081D3562:
	movs r2, #8
	mov r1, sl
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _081D357C
	movs r0, #1
	b _081D357E
	.align 2, 0
_081D3578: .4byte 0x03002BE0
_081D357C:
	movs r0, #0
_081D357E:
	cmp r0, #0
	bne _081D3584
	b _081D3694
_081D3584:
	ldr r0, [r7]
	ldrh r1, [r0, #0x2c]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D35AA
	cmp r1, #0
	blt _081D35AA
	ldr r0, _081D35B0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D35AA
	ldr r0, _081D35B4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D35B8
_081D35AA:
	movs r4, #0
	b _081D35C6
	.align 2, 0
_081D35B0: .4byte 0x030046A8
_081D35B4: .4byte 0x030046AC
_081D35B8:
	ldr r0, _081D35E4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081D35C6:
	adds r0, r4, #0
	bl FUN_081d34e8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D3694
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D35E8
	adds r0, #4
	b _081D35F4
	.align 2, 0
_081D35E4: .4byte 0x030046A4
_081D35E8:
	ldr r0, _081D36B4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D35F4:
	ldrh r0, [r0, #2]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	beq _081D3694
	mov r3, sp
	ldr r0, [r7]
	adds r2, r0, #0
	adds r2, #0x2c
	ldrh r1, [r0, #0x2c]
	mov r4, r8
	ldrh r0, [r4]
	subs r1, r1, r0
	mov r0, sp
	strh r1, [r0]
	ldrh r1, [r2, #2]
	ldrh r0, [r4, #2]
	subs r4, r1, r0
	strh r4, [r3, #2]
	ldrh r1, [r2, #4]
	mov r6, r8
	ldrh r0, [r6, #4]
	subs r5, r1, r0
	strh r5, [r3, #4]
	ldr r2, _081D36B8 @ =0x085AE0D0
	mov r0, sp
	movs r6, #0
	ldrsh r1, [r0, r6]
	movs r6, #0
	ldrsh r0, [r2, r6]
	ldr r6, _081D36BC @ =0x03002BE0
	mov ip, r6
	mov r6, sl
	adds r6, #0xfc
	str r6, [sp, #0xc]
	cmp r1, r0
	bgt _081D367C
	mov r0, sp
	movs r6, #0
	ldrsh r1, [r0, r6]
	movs r6, #0
	ldrsh r0, [r2, r6]
	cmn r1, r0
	blt _081D367C
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r4, #2
	ldrsh r1, [r2, r4]
	cmp r0, r1
	bgt _081D367C
	movs r6, #2
	ldrsh r1, [r3, r6]
	movs r4, #2
	ldrsh r0, [r2, r4]
	cmn r1, r0
	blt _081D367C
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	movs r6, #4
	ldrsh r1, [r2, r6]
	cmp r0, r1
	bgt _081D367C
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r3, #4
	ldrsh r0, [r2, r3]
	cmn r1, r0
	bge _081D3694
_081D367C:
	ldr r0, [sp, #8]
	add r0, ip
	ldr r0, [r0]
	ldr r1, [sp, #0xc]
	bl FUN_0807a9b8
	movs r0, #0x80
	lsls r0, r0, #1
	mov r4, sb
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
_081D3694:
	ldr r6, [sp, #8]
	adds r6, #4
	str r6, [sp, #8]
	adds r7, #4
	ldr r0, _081D36BC @ =0x03002BE0
	cmp r7, r0
	bgt _081D36A4
	b _081D354E
_081D36A4:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D36B4: .4byte 0x030046A4
_081D36B8: .4byte 0x085AE0D0
_081D36BC: .4byte 0x03002BE0

	thumb_func_start FUN_081d36c0
FUN_081d36c0: @ 0x081D36C0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r0, _081D3710 @ =0x03002BE0
	mov sl, r0
	mov r6, sp
	mov r8, sl
_081D36D6:
	movs r1, #0
	mov sb, r1
	mov r3, r8
	ldr r0, [r3]
	cmp r0, #0
	bne _081D36E4
	b _081D3884
_081D36E4:
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	bne _081D36FE
	mov r4, r8
	ldr r0, [r4]
	movs r1, #2
	bl FUN_0807a954
	cmp r0, #0
	bne _081D36FE
	b _081D388E
_081D36FE:
	movs r1, #8
	adds r0, r7, #0
	adds r0, #0xb4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D3714
	movs r0, #1
	b _081D3716
	.align 2, 0
_081D3710: .4byte 0x03002BE0
_081D3714:
	movs r0, #0
_081D3716:
	cmp r0, #0
	bne _081D371C
	b _081D3884
_081D371C:
	mov r1, r8
	ldr r0, [r1]
	ldrh r1, [r0, #0x2c]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D3744
	cmp r1, #0
	blt _081D3744
	ldr r0, _081D3748 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D3744
	ldr r0, _081D374C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D3750
_081D3744:
	movs r4, #0
	b _081D375E
	.align 2, 0
_081D3748: .4byte 0x030046A8
_081D374C: .4byte 0x030046AC
_081D3750:
	ldr r0, _081D3770 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081D375E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D3774
	adds r0, #4
	b _081D3780
	.align 2, 0
_081D3770: .4byte 0x030046A4
_081D3774:
	ldr r0, _081D3818 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D3780:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _081D3884
	adds r0, r4, #0
	bl FUN_081d34e8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D3884
	mov r5, sp
	adds r2, r7, #0
	adds r2, #0xfc
	mov r3, r8
	ldr r0, [r3]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r6]
	ldrh r1, [r3, #2]
	ldrh r0, [r2, #2]
	subs r4, r1, r0
	strh r4, [r5, #2]
	ldrh r1, [r3, #4]
	ldrh r0, [r2, #4]
	subs r3, r1, r0
	strh r3, [r5, #4]
	adds r0, r7, #0
	adds r0, #0xd6
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081D3820
	ldr r2, _081D381C @ =0x085AE0D0
	movs r1, #0
	ldrsh r0, [r6, r1]
	mov ip, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp ip, r0
	bgt _081D3874
	movs r1, #0
	ldrsh r0, [r2, r1]
	mov r1, ip
	cmn r1, r0
	blt _081D3874
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r4, #2
	ldrsh r1, [r2, r4]
	cmp r0, r1
	bgt _081D3874
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r4, #2
	ldrsh r0, [r2, r4]
	cmn r1, r0
	blt _081D3874
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	movs r3, #4
	ldrsh r1, [r2, r3]
	cmp r0, r1
	bgt _081D3874
	movs r4, #4
	ldrsh r1, [r5, r4]
	movs r3, #4
	ldrsh r0, [r2, r3]
	cmn r1, r0
	bge _081D386E
	b _081D3874
	.align 2, 0
_081D3818: .4byte 0x030046A4
_081D381C: .4byte 0x085AE0D0
_081D3820:
	ldr r2, _081D38A0 @ =0x085AE0D8
	movs r1, #0
	ldrsh r0, [r6, r1]
	mov ip, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp ip, r0
	bgt _081D386A
	movs r1, #0
	ldrsh r0, [r2, r1]
	mov r1, ip
	cmn r1, r0
	blt _081D386A
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r4, #2
	ldrsh r1, [r2, r4]
	cmp r0, r1
	bgt _081D386A
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r4, #2
	ldrsh r0, [r2, r4]
	cmn r1, r0
	blt _081D386A
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	movs r3, #4
	ldrsh r1, [r2, r3]
	cmp r0, r1
	bgt _081D386A
	movs r4, #4
	ldrsh r1, [r5, r4]
	movs r3, #4
	ldrsh r0, [r2, r3]
	cmn r1, r0
	bge _081D386E
_081D386A:
	movs r4, #1
	mov sb, r4
_081D386E:
	mov r0, sb
	cmp r0, #0
	beq _081D3884
_081D3874:
	adds r1, r7, #0
	adds r1, #0xc0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081D3884
	movs r1, #0
	bl Script_ExecById
_081D3884:
	movs r1, #4
	add r8, r1
	cmp r8, sl
	bgt _081D388E
	b _081D36D6
_081D388E:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D38A0: .4byte 0x085AE0D8

	thumb_func_start FUN_081d38a4
FUN_081d38a4: @ 0x081D38A4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov sb, r0
	mov r6, sp
	movs r0, #0
	str r0, [sp, #0xc]
	ldr r1, _081D38F8 @ =0x03002BE0
	mov sl, r1
_081D38BC:
	mov r2, sl
	ldr r1, [r2]
	cmp r1, #0
	bne _081D38C6
	b _081D3A66
_081D38C6:
	mov r0, sb
	adds r0, #0xb2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #4
	bne _081D38D4
	b _081D3A66
_081D38D4:
	adds r0, r1, #0
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	bne _081D38E2
	b _081D3A66
_081D38E2:
	movs r2, #8
	mov r1, sb
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	str r1, [sp, #8]
	cmp r0, #0
	beq _081D38FC
	movs r0, #1
	b _081D38FE
	.align 2, 0
_081D38F8: .4byte 0x03002BE0
_081D38FC:
	movs r0, #0
_081D38FE:
	cmp r0, #0
	bne _081D3904
	b _081D3A78
_081D3904:
	mov r0, sb
	adds r0, #0xfc
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov r8, r0
	cmp r2, #0
	blt _081D392E
	cmp r1, #0
	blt _081D392E
	ldr r0, _081D3934 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D392E
	ldr r0, _081D3938 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D393C
_081D392E:
	movs r0, #0
	b _081D394A
	.align 2, 0
_081D3934: .4byte 0x030046A8
_081D3938: .4byte 0x030046AC
_081D393C:
	ldr r0, _081D39F0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_081D394A:
	bl FUN_081d34e8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D396A
	mov r4, sl
	ldr r0, [r4]
	mov r2, sb
	adds r2, #0xfe
	movs r5, #0x2e
	ldrsh r1, [r0, r5]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r1, r0
	bne _081D396A
	b _081D3A66
_081D396A:
	mov r3, sp
	mov r4, sl
	ldr r0, [r4]
	adds r2, r0, #0
	adds r2, #0x2c
	ldrh r0, [r0, #0x2c]
	mov r5, r8
	ldrh r1, [r5]
	subs r0, r0, r1
	strh r0, [r6]
	ldrh r1, [r2, #2]
	ldrh r0, [r5, #2]
	subs r5, r1, r0
	strh r5, [r3, #2]
	ldrh r1, [r2, #4]
	mov r2, r8
	ldrh r0, [r2, #4]
	subs r7, r1, r0
	strh r7, [r3, #4]
	ldr r0, _081D39F4 @ =0x085AE0E0
	movs r4, #0
	ldrsh r2, [r6, r4]
	movs r4, #0
	ldrsh r1, [r0, r4]
	ldr r4, _081D39F8 @ =0x03002BE0
	mov ip, r4
	adds r4, r0, #0
	cmp r2, r1
	bgt _081D39EC
	adds r1, r2, #0
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmn r1, r0
	blt _081D39DE
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	movs r5, #2
	ldrsh r1, [r4, r5]
	cmp r0, r1
	bgt _081D39DE
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r2, #2
	ldrsh r0, [r4, r2]
	cmn r1, r0
	blt _081D39DE
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	movs r5, #4
	ldrsh r1, [r4, r5]
	cmp r0, r1
	bgt _081D39DE
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r2, #4
	ldrsh r0, [r4, r2]
	cmn r1, r0
	bge _081D3A66
_081D39DE:
	movs r3, #0
	ldrsh r1, [r6, r3]
	ldrh r2, [r4]
	movs r5, #0
	ldrsh r0, [r4, r5]
	cmp r1, r0
	ble _081D39FC
_081D39EC:
	ldrh r0, [r4]
	b _081D3A0A
	.align 2, 0
_081D39F0: .4byte 0x030046A4
_081D39F4: .4byte 0x085AE0E0
_081D39F8: .4byte 0x03002BE0
_081D39FC:
	movs r0, #0
	ldrsh r1, [r6, r0]
	movs r3, #0
	ldrsh r0, [r4, r3]
	cmn r1, r0
	bge _081D3A0C
	rsbs r0, r2, #0
_081D3A0A:
	strh r0, [r6]
_081D3A0C:
	mov r2, sp
	movs r5, #4
	ldrsh r1, [r2, r5]
	ldrh r3, [r4, #4]
	movs r5, #4
	ldrsh r0, [r4, r5]
	cmp r1, r0
	ble _081D3A20
	strh r3, [r2, #4]
	b _081D3A30
_081D3A20:
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r5, #4
	ldrsh r0, [r4, r5]
	cmn r1, r0
	bge _081D3A30
	rsbs r0, r3, #0
	strh r0, [r2, #4]
_081D3A30:
	ldrh r0, [r6]
	mov r1, r8
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r6]
	mov r0, sb
	adds r0, #0xfe
	ldrh r0, [r0]
	strh r0, [r6, #2]
	movs r4, #0x80
	lsls r4, r4, #1
	mov r2, sb
	adds r1, r2, r4
	ldrh r0, [r6, #4]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r6, #4]
	ldr r0, [sp, #0xc]
	add r0, ip
	ldr r0, [r0]
	mov r1, sp
	bl FUN_0807a91c
	ldr r3, [sp, #8]
	ldrh r0, [r3]
	orrs r4, r0
	strh r4, [r3]
_081D3A66:
	ldr r4, [sp, #0xc]
	adds r4, #4
	str r4, [sp, #0xc]
	movs r5, #4
	add sl, r5
	ldr r0, _081D3A88 @ =0x03002BE0
	cmp sl, r0
	bgt _081D3A78
	b _081D38BC
_081D3A78:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D3A88: .4byte 0x03002BE0

	thumb_func_start FUN_081d3a8c
FUN_081d3a8c: @ 0x081D3A8C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	movs r0, #1
	bl FUN_08086978
	cmp r0, #0
	bne _081D3AA2
	b _081D3C18
_081D3AA2:
	movs r2, #0x10
	adds r1, r7, #0
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _081D3AB6
	movs r0, #1
	b _081D3AB8
_081D3AB6:
	movs r0, #0
_081D3AB8:
	cmp r0, #0
	bne _081D3ABE
	b _081D3C18
_081D3ABE:
	mov r0, sp
	bl FUN_08086a28
	adds r0, r7, #0
	adds r0, #0xfc
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r6, r0, #0
	cmp r2, #0
	blt _081D3AEE
	cmp r1, #0
	blt _081D3AEE
	ldr r0, _081D3AF4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D3AEE
	ldr r0, _081D3AF8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D3AFC
_081D3AEE:
	movs r0, #0
	b _081D3B0A
	.align 2, 0
_081D3AF4: .4byte 0x030046A8
_081D3AF8: .4byte 0x030046AC
_081D3AFC:
	ldr r0, _081D3BA8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_081D3B0A:
	bl FUN_081d34e8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D3B28
	mov r0, sp
	adds r1, r7, #0
	adds r1, #0xfe
	ldrh r0, [r0, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	beq _081D3C18
_081D3B28:
	add r3, sp, #8
	mov r4, sp
	mov r0, sp
	ldrh r1, [r0]
	ldrh r0, [r6]
	subs r1, r1, r0
	strh r1, [r3]
	ldrh r2, [r4, #2]
	ldrh r0, [r6, #2]
	subs r2, r2, r0
	mov ip, r2
	mov r5, ip
	strh r5, [r3, #2]
	ldrh r2, [r4, #4]
	ldrh r0, [r6, #4]
	subs r4, r2, r0
	strh r4, [r3, #4]
	ldr r2, _081D3BAC @ =0x085AE0E0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmp r1, r0
	bgt _081D3BA4
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmn r1, r0
	blt _081D3B96
	mov r1, ip
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	movs r5, #2
	ldrsh r1, [r2, r5]
	cmp r0, r1
	bgt _081D3B96
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r5, #2
	ldrsh r0, [r2, r5]
	cmn r1, r0
	blt _081D3B96
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r4, #4
	ldrsh r1, [r2, r4]
	cmp r0, r1
	bgt _081D3B96
	movs r5, #4
	ldrsh r1, [r3, r5]
	movs r4, #4
	ldrsh r0, [r2, r4]
	cmn r1, r0
	bge _081D3C18
_081D3B96:
	movs r5, #0
	ldrsh r1, [r3, r5]
	ldrh r4, [r2]
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmp r1, r0
	ble _081D3BB0
_081D3BA4:
	ldrh r0, [r2]
	b _081D3BBE
	.align 2, 0
_081D3BA8: .4byte 0x030046A4
_081D3BAC: .4byte 0x085AE0E0
_081D3BB0:
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmn r1, r0
	bge _081D3BC0
	rsbs r0, r4, #0
_081D3BBE:
	strh r0, [r3]
_081D3BC0:
	movs r0, #4
	ldrsh r1, [r3, r0]
	ldrh r4, [r2, #4]
	movs r5, #4
	ldrsh r0, [r2, r5]
	cmp r1, r0
	ble _081D3BD2
	strh r4, [r3, #4]
	b _081D3BE2
_081D3BD2:
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r5, #4
	ldrsh r0, [r2, r5]
	cmn r1, r0
	bge _081D3BE2
	rsbs r0, r4, #0
	strh r0, [r3, #4]
_081D3BE2:
	ldrh r0, [r3]
	ldrh r6, [r6]
	adds r0, r0, r6
	mov r1, sp
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0xfe
	ldrh r0, [r0]
	mov r2, sp
	strh r0, [r2, #2]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r7, r0
	add r0, sp, #8
	ldrh r0, [r0, #4]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	bl FUN_08086a4c
	movs r0, #0x80
	lsls r0, r0, #2
	mov r2, r8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D3C18:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d3c24
FUN_081d3c24: @ 0x081D3C24
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	mov r8, r0
	movs r0, #1
	bl FUN_08086978
	cmp r0, #0
	bne _081D3C3C
	b _081D3DC0
_081D3C3C:
	movs r2, #0x10
	mov r1, r8
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _081D3C50
	movs r0, #1
	b _081D3C52
_081D3C50:
	movs r0, #0
_081D3C52:
	cmp r0, #0
	bne _081D3C58
	b _081D3DC0
_081D3C58:
	mov r4, sp
	mov r0, sp
	bl FUN_08086a28
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D3C86
	cmp r1, #0
	blt _081D3C86
	ldr r0, _081D3C8C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D3C86
	ldr r0, _081D3C90 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D3C94
_081D3C86:
	movs r4, #0
	b _081D3CA2
	.align 2, 0
_081D3C8C: .4byte 0x030046A8
_081D3C90: .4byte 0x030046AC
_081D3C94:
	ldr r0, _081D3CB4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081D3CA2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D3CB8
	adds r0, #4
	b _081D3CC4
	.align 2, 0
_081D3CB4: .4byte 0x030046A4
_081D3CB8:
	ldr r0, _081D3D50 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D3CC4:
	ldrh r0, [r0, #2]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	beq _081D3DC0
	add r3, sp, #8
	mov r4, r8
	adds r4, #0xfc
	mov r5, sp
	mov r0, sp
	ldrh r1, [r0]
	ldrh r0, [r4]
	subs r1, r1, r0
	strh r1, [r3]
	ldrh r2, [r5, #2]
	ldrh r0, [r4, #2]
	subs r6, r2, r0
	strh r6, [r3, #2]
	ldrh r2, [r5, #4]
	ldrh r0, [r4, #4]
	subs r7, r2, r0
	strh r7, [r3, #4]
	ldr r0, _081D3D54 @ =0x085AE0D0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r5, #0
	ldrsh r2, [r0, r5]
	adds r5, r0, #0
	cmp r1, r2
	bgt _081D3D4A
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r2, #0
	ldrsh r0, [r5, r2]
	cmn r1, r0
	blt _081D3D3C
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r6, #2
	ldrsh r1, [r5, r6]
	cmp r0, r1
	bgt _081D3D3C
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r2, #2
	ldrsh r0, [r5, r2]
	cmn r1, r0
	blt _081D3D3C
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	movs r6, #4
	ldrsh r1, [r5, r6]
	cmp r0, r1
	bgt _081D3D3C
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r2, #4
	ldrsh r0, [r5, r2]
	cmn r1, r0
	bge _081D3DC0
_081D3D3C:
	movs r6, #0
	ldrsh r1, [r3, r6]
	ldrh r2, [r5]
	movs r6, #0
	ldrsh r0, [r5, r6]
	cmp r1, r0
	ble _081D3D58
_081D3D4A:
	ldrh r0, [r5]
	b _081D3D66
	.align 2, 0
_081D3D50: .4byte 0x030046A4
_081D3D54: .4byte 0x085AE0D0
_081D3D58:
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r6, #0
	ldrsh r0, [r5, r6]
	cmn r1, r0
	bge _081D3D68
	rsbs r0, r2, #0
_081D3D66:
	strh r0, [r3]
_081D3D68:
	movs r0, #4
	ldrsh r1, [r3, r0]
	ldrh r2, [r5, #4]
	movs r6, #4
	ldrsh r0, [r5, r6]
	cmp r1, r0
	ble _081D3D7A
	strh r2, [r3, #4]
	b _081D3D8A
_081D3D7A:
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r6, #4
	ldrsh r0, [r5, r6]
	cmn r1, r0
	bge _081D3D8A
	rsbs r0, r2, #0
	strh r0, [r3, #4]
_081D3D8A:
	ldrh r0, [r3]
	ldrh r4, [r4]
	adds r0, r0, r4
	mov r1, sp
	strh r0, [r1]
	mov r0, r8
	adds r0, #0xfe
	ldrh r0, [r0]
	mov r2, sp
	strh r0, [r2, #2]
	movs r1, #0x80
	lsls r1, r1, #1
	add r1, r8
	add r0, sp, #8
	ldrh r0, [r0, #4]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	bl FUN_08086a4c
	movs r0, #0x80
	lsls r0, r0, #2
	mov r2, sb
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D3DC0:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d3dd0
FUN_081d3dd0: @ 0x081D3DD0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	mov r8, r0
	movs r0, #1
	bl FUN_08086978
	cmp r0, #0
	bne _081D3DE8
	b _081D3F9C
_081D3DE8:
	movs r2, #0x10
	mov r1, r8
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _081D3DFC
	movs r0, #1
	b _081D3DFE
_081D3DFC:
	movs r0, #0
_081D3DFE:
	cmp r0, #0
	bne _081D3E04
	b _081D3F9C
_081D3E04:
	mov r4, sp
	mov r0, sp
	bl FUN_08086a28
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D3E32
	cmp r1, #0
	blt _081D3E32
	ldr r0, _081D3E38 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D3E32
	ldr r0, _081D3E3C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D3E40
_081D3E32:
	movs r4, #0
	b _081D3E4E
	.align 2, 0
_081D3E38: .4byte 0x030046A8
_081D3E3C: .4byte 0x030046AC
_081D3E40:
	ldr r0, _081D3E64 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081D3E4E:
	mov r0, sp
	movs r1, #2
	ldrsh r5, [r0, r1]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D3E68
	adds r0, #4
	b _081D3E74
	.align 2, 0
_081D3E64: .4byte 0x030046A4
_081D3E68:
	ldr r0, _081D3E90 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D3E74:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	cmp r5, r0
	bne _081D3EAA
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D3E94
	adds r0, #4
	b _081D3EA0
	.align 2, 0
_081D3E90: .4byte 0x030046A4
_081D3E94:
	ldr r0, _081D3F2C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D3EA0:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _081D3F9C
_081D3EAA:
	add r3, sp, #8
	mov r4, r8
	adds r4, #0xfc
	mov r5, sp
	mov r0, sp
	ldrh r1, [r0]
	ldrh r0, [r4]
	subs r1, r1, r0
	strh r1, [r3]
	ldrh r2, [r5, #2]
	ldrh r0, [r4, #2]
	subs r6, r2, r0
	strh r6, [r3, #2]
	ldrh r2, [r5, #4]
	ldrh r0, [r4, #4]
	subs r7, r2, r0
	strh r7, [r3, #4]
	ldr r0, _081D3F30 @ =0x085AE0D0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r5, #0
	ldrsh r2, [r0, r5]
	adds r5, r0, #0
	cmp r1, r2
	bgt _081D3F26
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r2, #0
	ldrsh r0, [r5, r2]
	cmn r1, r0
	blt _081D3F18
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r6, #2
	ldrsh r1, [r5, r6]
	cmp r0, r1
	bgt _081D3F18
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r2, #2
	ldrsh r0, [r5, r2]
	cmn r1, r0
	blt _081D3F18
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	movs r6, #4
	ldrsh r1, [r5, r6]
	cmp r0, r1
	bgt _081D3F18
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r2, #4
	ldrsh r0, [r5, r2]
	cmn r1, r0
	bge _081D3F9C
_081D3F18:
	movs r6, #0
	ldrsh r1, [r3, r6]
	ldrh r2, [r5]
	movs r6, #0
	ldrsh r0, [r5, r6]
	cmp r1, r0
	ble _081D3F34
_081D3F26:
	ldrh r0, [r5]
	b _081D3F42
	.align 2, 0
_081D3F2C: .4byte 0x030046A4
_081D3F30: .4byte 0x085AE0D0
_081D3F34:
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r6, #0
	ldrsh r0, [r5, r6]
	cmn r1, r0
	bge _081D3F44
	rsbs r0, r2, #0
_081D3F42:
	strh r0, [r3]
_081D3F44:
	movs r0, #4
	ldrsh r1, [r3, r0]
	ldrh r2, [r5, #4]
	movs r6, #4
	ldrsh r0, [r5, r6]
	cmp r1, r0
	ble _081D3F56
	strh r2, [r3, #4]
	b _081D3F66
_081D3F56:
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r6, #4
	ldrsh r0, [r5, r6]
	cmn r1, r0
	bge _081D3F66
	rsbs r0, r2, #0
	strh r0, [r3, #4]
_081D3F66:
	ldrh r0, [r3]
	ldrh r4, [r4]
	adds r0, r0, r4
	mov r1, sp
	strh r0, [r1]
	mov r0, r8
	adds r0, #0xfe
	ldrh r0, [r0]
	mov r2, sp
	strh r0, [r2, #2]
	movs r1, #0x80
	lsls r1, r1, #1
	add r1, r8
	add r0, sp, #8
	ldrh r0, [r0, #4]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	bl FUN_08086a4c
	movs r0, #0x80
	lsls r0, r0, #2
	mov r2, sb
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D3F9C:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d3fac
FUN_081d3fac: @ 0x081D3FAC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	mov ip, r1
	ldr r0, _081D3FEC @ =0x03000194
	ldr r2, [r0]
	ldr r0, _081D3FF0 @ =0x000012AC
	adds r1, r2, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _081D4026
	movs r4, #0
	adds r6, r1, #0
	movs r0, #9
	rsbs r0, r0, #0
	mov r8, r0
	subs r0, #8
	mov sb, r0
	adds r3, r2, #0
	adds r3, #0xd0
	movs r5, #0xc6
	lsls r5, r5, #1
_081D3FDC:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D3FF4
	movs r0, #1
	b _081D3FF6
	.align 2, 0
_081D3FEC: .4byte 0x03000194
_081D3FF0: .4byte 0x000012AC
_081D3FF4:
	movs r0, #0
_081D3FF6:
	cmp r0, #0
	beq _081D401C
	ldrh r0, [r3, #0x20]
	cmp r0, r7
	bne _081D401C
	mov r0, ip
	cmp r0, #0
	bne _081D4010
	ldrh r1, [r3]
	mov r0, r8
	ands r0, r1
	strh r0, [r3]
	b _081D4026
_081D4010:
	adds r2, #0xd0
	ldrh r1, [r2]
	mov r0, sb
	ands r0, r1
	strh r0, [r2]
	b _081D4026
_081D401C:
	adds r3, r3, r5
	adds r2, r2, r5
	adds r4, #1
	cmp r4, #0xb
	ble _081D3FDC
_081D4026:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d4034
FUN_081d4034: @ 0x081D4034
	push {r4, lr}
	adds r1, r0, #0
	adds r0, #0xb2
	ldrh r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _081D405C
	ldr r0, _081D4058 @ =0x03002BE0
	ldr r0, [r0]
	adds r1, #0xd4
	ldrh r2, [r1]
	movs r1, #5
	bl FUN_0807a97c
	b _081D4072
	.align 2, 0
_081D4058: .4byte 0x03002BE0
_081D405C:
	ldr r4, _081D4078 @ =0x03002BE0
	ldr r0, [r4]
	adds r1, #0xd4
	ldrh r2, [r1]
	movs r1, #1
	bl FUN_0807a97c
	ldr r0, [r4]
	movs r1, #4
	bl FUN_0807a99c
_081D4072:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081D4078: .4byte 0x03002BE0

	thumb_func_start FUN_081d407c
FUN_081d407c: @ 0x081D407C
	push {lr}
	adds r1, r0, #0
	adds r0, #0xb2
	ldrh r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _081D409C
	adds r0, r1, #0
	adds r0, #0xd4
	ldrh r1, [r0]
	movs r0, #7
	bl FUN_080869c8
	b _081D40AE
_081D409C:
	adds r0, r1, #0
	adds r0, #0xd4
	ldrh r1, [r0]
	movs r0, #3
	bl FUN_080869c8
	movs r0, #4
	bl FUN_080869f8
_081D40AE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d40b4
FUN_081d40b4: @ 0x081D40B4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r0, _081D41B0 @ =0x03002BE0
	mov r8, r0
	ldr r3, [r0]
	adds r0, r7, #0
	adds r0, #0x58
	ldrh r0, [r0]
	ldrh r1, [r3, #0x2c]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _081D41B4 @ =0xFFFF0000
	ldr r2, [sp]
	ands r2, r4
	orrs r2, r0
	str r2, [sp]
	adds r0, r7, #0
	adds r0, #0x5a
	ldrh r1, [r0]
	ldrh r0, [r3, #0x2e]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _081D41B8 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	adds r0, r7, #0
	adds r0, #0x5c
	ldrh r1, [r0]
	ldrh r3, [r3, #0x30]
	adds r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r5, sp
	ldr r0, [sp, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #4]
	add r4, sp, #8
	adds r3, r7, #0
	adds r3, #0xfc
	mov r0, sp
	ldrh r1, [r0]
	ldrh r0, [r3]
	subs r1, r1, r0
	strh r1, [r4]
	ldrh r2, [r5, #2]
	ldrh r0, [r3, #2]
	subs r6, r2, r0
	strh r6, [r4, #2]
	ldrh r2, [r5, #4]
	ldrh r0, [r3, #4]
	subs r5, r2, r0
	strh r5, [r4, #4]
	ldr r0, _081D41BC @ =0x03000194
	ldr r0, [r0]
	mov ip, r0
	ldr r0, _081D41C0 @ =0x085AE0D0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r3, #0
	ldrsh r2, [r0, r3]
	adds r3, r0, #0
	cmp r1, r2
	bgt _081D41CC
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmn r1, r0
	blt _081D41CC
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r2, #2
	ldrsh r1, [r3, r2]
	cmp r0, r1
	bgt _081D41CC
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r2, #2
	ldrsh r0, [r3, r2]
	cmn r1, r0
	blt _081D41CC
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	movs r2, #4
	ldrsh r1, [r3, r2]
	cmp r0, r1
	bgt _081D41CC
	movs r0, #4
	ldrsh r1, [r4, r0]
	movs r2, #4
	ldrsh r0, [r3, r2]
	cmn r1, r0
	blt _081D41CC
	ldr r4, _081D41C4 @ =0x000012B0
	add r4, ip
	ldrh r0, [r4]
	movs r1, #0
	bl FUN_081d3fac
	adds r0, r7, #0
	adds r0, #0xd4
	ldrh r0, [r0]
	strh r0, [r4]
	adds r0, r7, #0
	bl FUN_081d4034
	movs r0, #8
	adds r2, r7, #0
	adds r2, #0xb4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	mov r3, r8
	ldr r1, [r3]
	ldr r0, _081D41C8 @ =0x0000060E
	adds r1, r1, r0
	ldrb r2, [r1]
	movs r0, #1
	orrs r0, r2
	b _081D42AC
	.align 2, 0
_081D41B0: .4byte 0x03002BE0
_081D41B4: .4byte 0xFFFF0000
_081D41B8: .4byte 0x0000FFFF
_081D41BC: .4byte 0x03000194
_081D41C0: .4byte 0x085AE0D0
_081D41C4: .4byte 0x000012B0
_081D41C8: .4byte 0x0000060E
_081D41CC:
	ldr r0, _081D422C @ =0x000012B0
	add r0, ip
	adds r1, r7, #0
	adds r1, #0xd4
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _081D42AE
	adds r0, r7, #0
	adds r0, #0xe7
	ldrb r0, [r0]
	cmp r0, #1
	bne _081D4234
	adds r0, r7, #0
	adds r0, #0xd6
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _081D4234
	ldr r2, _081D4230 @ =0x085AE0D8
	movs r3, #0
	ldrsh r1, [r4, r3]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r1, r0
	bgt _081D4276
	cmn r1, r0
	blt _081D4276
	ldrh r0, [r4, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r3, #2
	ldrsh r1, [r2, r3]
	cmp r0, r1
	bgt _081D4276
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r3, #2
	ldrsh r0, [r2, r3]
	cmn r1, r0
	blt _081D4276
	movs r0, #4
	ldrsh r1, [r4, r0]
	movs r3, #4
	ldrsh r0, [r2, r3]
	b _081D4266
	.align 2, 0
_081D422C: .4byte 0x000012B0
_081D4230: .4byte 0x085AE0D8
_081D4234:
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmp r1, r0
	bgt _081D4276
	cmn r1, r0
	blt _081D4276
	ldrh r0, [r4, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #2
	ldrsh r1, [r3, r2]
	cmp r0, r1
	bgt _081D4276
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r2, #2
	ldrsh r0, [r3, r2]
	cmn r1, r0
	blt _081D4276
	movs r0, #4
	ldrsh r1, [r4, r0]
	movs r2, #4
	ldrsh r0, [r3, r2]
_081D4266:
	cmp r1, r0
	bgt _081D4276
	cmn r1, r0
	blt _081D4276
	adds r0, r7, #0
	bl FUN_081d4034
	b _081D42AE
_081D4276:
	ldr r1, _081D42BC @ =0x000012B0
	add r1, ip
	movs r0, #0
	strh r0, [r1]
	mov r3, r8
	ldr r0, [r3]
	movs r2, #0xde
	lsls r2, r2, #1
	adds r1, r0, r2
	str r1, [r0, #0x3c]
	movs r1, #5
	bl FUN_0807a99c
	adds r2, r7, #0
	adds r2, #0xb4
	movs r0, #9
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	mov r3, r8
	ldr r1, [r3]
	ldr r0, _081D42C0 @ =0x0000060E
	adds r1, r1, r0
	ldrb r2, [r1]
	movs r0, #0xfe
	ands r0, r2
_081D42AC:
	strb r0, [r1]
_081D42AE:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D42BC: .4byte 0x000012B0
_081D42C0: .4byte 0x0000060E

	thumb_func_start FUN_081d42c4
FUN_081d42c4: @ 0x081D42C4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	mov r4, sp
	mov r0, sp
	bl FUN_08086a28
	adds r0, r5, #0
	adds r0, #0x58
	mov r1, sp
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	adds r1, r5, #0
	adds r1, #0x5a
	ldrh r0, [r4, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #2]
	adds r0, r5, #0
	adds r0, #0x5c
	ldrh r0, [r0]
	ldrh r1, [r4, #4]
	adds r0, r0, r1
	strh r0, [r4, #4]
	add r6, sp, #8
	adds r3, r5, #0
	adds r3, #0xfc
	mov r0, sp
	ldrh r1, [r0]
	ldrh r0, [r3]
	subs r1, r1, r0
	strh r1, [r6]
	ldrh r2, [r4, #2]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	mov ip, r2
	mov r2, ip
	strh r2, [r6, #2]
	ldrh r2, [r4, #4]
	ldrh r0, [r3, #4]
	subs r2, r2, r0
	strh r2, [r6, #4]
	ldr r0, _081D4394 @ =0x03000194
	ldr r4, [r0]
	ldr r3, _081D4398 @ =0x085AE0D0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r7, #0
	ldrsh r0, [r3, r7]
	cmp r1, r0
	bgt _081D43A0
	movs r0, #0
	ldrsh r1, [r6, r0]
	movs r7, #0
	ldrsh r0, [r3, r7]
	cmn r1, r0
	blt _081D43A0
	mov r1, ip
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	movs r7, #2
	ldrsh r1, [r3, r7]
	cmp r0, r1
	bgt _081D43A0
	movs r0, #2
	ldrsh r1, [r6, r0]
	movs r7, #2
	ldrsh r0, [r3, r7]
	cmn r1, r0
	blt _081D43A0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	movs r2, #4
	ldrsh r1, [r3, r2]
	cmp r0, r1
	bgt _081D43A0
	movs r7, #4
	ldrsh r1, [r6, r7]
	movs r2, #4
	ldrsh r0, [r3, r2]
	cmn r1, r0
	blt _081D43A0
	ldr r7, _081D439C @ =0x000012B2
	adds r4, r4, r7
	ldrh r0, [r4]
	movs r1, #1
	bl FUN_081d3fac
	adds r0, r5, #0
	adds r0, #0xd4
	ldrh r0, [r0]
	strh r0, [r4]
	adds r0, r5, #0
	bl FUN_081d407c
	movs r0, #0x10
	adds r2, r5, #0
	adds r2, #0xb4
	ldrh r1, [r2]
	orrs r0, r1
	b _081D43C6
	.align 2, 0
_081D4394: .4byte 0x03000194
_081D4398: .4byte 0x085AE0D0
_081D439C: .4byte 0x000012B2
_081D43A0:
	adds r0, r5, #0
	adds r0, #0xd4
	ldr r1, _081D43D0 @ =0x000012B2
	adds r4, r4, r1
	ldrh r0, [r0]
	ldrh r2, [r4]
	cmp r0, r2
	bne _081D43C8
	movs r0, #0
	strh r0, [r4]
	movs r0, #7
	bl FUN_080869f8
	adds r2, r5, #0
	adds r2, #0xb4
	movs r0, #0x11
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
_081D43C6:
	strh r0, [r2]
_081D43C8:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D43D0: .4byte 0x000012B2

	thumb_func_start FUN_081d43d4
FUN_081d43d4: @ 0x081D43D4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	mov ip, r2
	mov r1, ip
	adds r1, #0xfc
	ldrh r0, [r0]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _081D4440 @ =0xFFFF0000
	adds r1, r3, #0
	ands r1, r4
	orrs r1, r0
	adds r2, #0xfe
	mov r6, r8
	ldrh r0, [r6, #2]
	ldrh r2, [r2]
	subs r0, r0, r2
	lsls r0, r0, #0x10
	ldr r2, _081D4444 @ =0x0000FFFF
	ands r1, r2
	adds r4, r1, #0
	orrs r4, r0
	movs r1, #0x80
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r6, #4]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r3, r5
	adds r5, r3, #0
	orrs r5, r0
	mov r0, ip
	adds r0, #0xe7
	ldrb r0, [r0]
	cmp r0, #2
	bne _081D442A
	b _081D4530
_081D442A:
	cmp r0, #1
	bne _081D444C
	mov r0, ip
	adds r0, #0xd6
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _081D444C
	ldr r0, _081D4448 @ =0x085AE0D8
	b _081D444E
	.align 2, 0
_081D4440: .4byte 0xFFFF0000
_081D4444: .4byte 0x0000FFFF
_081D4448: .4byte 0x085AE0D8
_081D444C:
	ldr r0, _081D4470 @ =0x085AE0D0
_081D444E:
	ldr r6, [r0]
	ldr r7, [r0, #4]
	lsls r0, r4, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	bge _081D4474
	adds r2, r6, #0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmn r1, r0
	bge _081D4492
	mov r0, ip
	adds r0, #0xba
	ldrh r0, [r0]
	subs r0, r0, r2
	b _081D4486
	.align 2, 0
_081D4470: .4byte 0x085AE0D0
_081D4474:
	adds r2, r6, #0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	ble _081D4492
	mov r0, ip
	adds r0, #0xba
	ldrh r0, [r0]
	subs r0, r2, r0
_081D4486:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _081D44AC @ =0xFFFF0000
	ands r1, r4
	adds r4, r1, #0
	orrs r4, r0
_081D4492:
	adds r2, r4, #0
	asrs r0, r2, #0x10
	cmp r0, #0
	bge _081D44B0
	asrs r1, r6, #0x10
	cmn r0, r1
	bge _081D44C8
	mov r0, ip
	adds r0, #0xba
	ldrh r0, [r0]
	subs r0, r0, r1
	b _081D44BE
	.align 2, 0
_081D44AC: .4byte 0xFFFF0000
_081D44B0:
	asrs r1, r6, #0x10
	cmp r0, r1
	ble _081D44C8
	mov r0, ip
	adds r0, #0xba
	ldrh r0, [r0]
	subs r0, r1, r0
_081D44BE:
	lsls r0, r0, #0x10
	ldr r1, _081D44E4 @ =0x0000FFFF
	ands r2, r1
	adds r4, r2, #0
	orrs r4, r0
_081D44C8:
	lsls r0, r5, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	bge _081D44E8
	adds r2, r7, #0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmn r1, r0
	bge _081D4506
	mov r0, ip
	adds r0, #0xba
	ldrh r0, [r0]
	subs r0, r0, r2
	b _081D44FA
	.align 2, 0
_081D44E4: .4byte 0x0000FFFF
_081D44E8:
	adds r2, r7, #0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	ble _081D4506
	mov r0, ip
	adds r0, #0xba
	ldrh r0, [r0]
	subs r0, r2, r0
_081D44FA:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _081D453C @ =0xFFFF0000
	ands r1, r5
	adds r5, r1, #0
	orrs r5, r0
_081D4506:
	mov r1, ip
	adds r1, #0xfc
	adds r0, r4, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, r8
	strh r0, [r1]
	mov r1, ip
	adds r1, #0xfe
	asrs r0, r4, #0x10
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r2, r8
	strh r0, [r2, #2]
	movs r1, #0x80
	lsls r1, r1, #1
	add r1, ip
	adds r0, r5, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r2, #4]
_081D4530:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D453C: .4byte 0xFFFF0000

	thumb_func_start FUN_081d4540
FUN_081d4540: @ 0x081D4540
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _081D458C @ =0x03002BE0
	ldr r0, [r5]
	cmp r0, #0
	beq _081D4584
	adds r0, r4, #0
	bl FUN_081d40b4
	adds r0, r4, #0
	bl FUN_081d42c4
	ldr r0, [r5]
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	beq _081D456A
	adds r0, r4, #0
	bl FUN_081d4590
_081D456A:
	movs r0, #1
	bl FUN_08086978
	cmp r0, #0
	beq _081D457A
	adds r0, r4, #0
	bl FUN_081d4658
_081D457A:
	adds r0, r4, #0
	adds r0, #0x58
	movs r1, #8
	bl ClearMemory
_081D4584:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081D458C: .4byte 0x03002BE0

	thumb_func_start FUN_081d4590
FUN_081d4590: @ 0x081D4590
	push {r4, r5, lr}
	sub sp, #8
	mov ip, r0
	ldr r0, _081D45CC @ =0x03000194
	ldr r2, [r0]
	ldr r0, _081D45D0 @ =0x03002BE0
	ldr r1, [r0]
	adds r4, r0, #0
	cmp r1, #0
	beq _081D4642
	mov r0, ip
	adds r0, #0xd4
	ldr r3, _081D45D4 @ =0x000012B0
	adds r1, r2, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _081D4642
	movs r2, #0x80
	lsls r2, r2, #1
	mov r1, ip
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _081D45D8
	movs r0, #1
	b _081D45DA
	.align 2, 0
_081D45CC: .4byte 0x03000194
_081D45D0: .4byte 0x03002BE0
_081D45D4: .4byte 0x000012B0
_081D45D8:
	movs r0, #0
_081D45DA:
	cmp r0, #0
	bne _081D463A
	ldr r1, [r4]
	mov r0, ip
	adds r0, #0x58
	ldrh r0, [r0]
	ldrh r1, [r1, #0x2c]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _081D464C @ =0xFFFF0000
	ldr r2, [sp]
	ands r2, r3
	orrs r2, r0
	str r2, [sp]
	ldr r0, [r4]
	mov r1, ip
	adds r1, #0x5a
	ldrh r1, [r1]
	ldrh r0, [r0, #0x2e]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _081D4650 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldr r1, [r4]
	mov r0, ip
	adds r0, #0x5c
	ldrh r0, [r0]
	ldrh r1, [r1, #0x30]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #4]
	ldr r1, [r4]
	adds r1, #0x2c
	mov r0, sp
	mov r2, ip
	bl FUN_081d43d4
	ldr r0, [r4]
	mov r1, sp
	bl FUN_0807a91c
_081D463A:
	ldr r0, _081D4654 @ =0xFFFFFEFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
_081D4642:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081D464C: .4byte 0xFFFF0000
_081D4650: .4byte 0x0000FFFF
_081D4654: .4byte 0xFFFFFEFF

	thumb_func_start FUN_081d4658
FUN_081d4658: @ 0x081D4658
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _081D46B0 @ =0x03000194
	ldr r0, [r0]
	ldr r1, _081D46B4 @ =0x000012B2
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0xd4
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _081D46F6
	mov r4, sp
	mov r0, sp
	bl FUN_08086a28
	add r3, sp, #8
	adds r2, r5, #0
	adds r2, #0xfc
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r4, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r5, #0
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081D46B8
	movs r0, #1
	b _081D46BA
	.align 2, 0
_081D46B0: .4byte 0x03000194
_081D46B4: .4byte 0x000012B2
_081D46B8:
	movs r0, #0
_081D46BA:
	cmp r0, #0
	bne _081D46EE
	adds r0, r5, #0
	adds r0, #0x58
	mov r1, sp
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	mov r2, sp
	adds r1, r5, #0
	adds r1, #0x5a
	ldrh r0, [r2, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r2, #2]
	adds r0, r5, #0
	adds r0, #0x5c
	ldrh r0, [r0]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	bl FUN_08086a4c
_081D46EE:
	ldr r0, _081D4700 @ =0xFFFFFDFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
_081D46F6:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081D4700: .4byte 0xFFFFFDFF

	thumb_func_start FUN_081d4704
FUN_081d4704: @ 0x081D4704
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	mov r8, r0
	adds r7, r1, #0
	adds r0, r7, #0
	adds r0, #0xe7
	ldrb r0, [r0]
	cmp r0, #2
	bne _081D479E
	mov r4, sp
	mov r0, sp
	bl FUN_08086a28
	add r3, sp, #8
	adds r5, r7, #0
	adds r5, #0xfc
	mov r0, sp
	ldrh r2, [r0]
	ldrh r0, [r5]
	subs r2, r2, r0
	strh r2, [r3]
	ldrh r0, [r4, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4, #4]
	ldrh r0, [r5, #4]
	subs r6, r1, r0
	strh r6, [r3, #4]
	ldr r4, _081D47AC @ =0x085AE0D0
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r2, r0
	bgt _081D479E
	movs r2, #0
	ldrsh r1, [r3, r2]
	cmn r1, r0
	blt _081D479E
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r2, #4
	ldrsh r1, [r4, r2]
	cmp r0, r1
	bgt _081D479E
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r2, #4
	ldrsh r0, [r4, r2]
	cmn r1, r0
	blt _081D479E
	adds r0, r5, #0
	bl FUN_08086a4c
	ldr r4, _081D47B0 @ =0x000012B2
	add r4, r8
	ldrh r0, [r4]
	movs r1, #1
	bl FUN_081d3fac
	adds r1, r7, #0
	adds r1, #0xd4
	ldrh r0, [r1]
	strh r0, [r4]
	ldrh r1, [r1]
	movs r0, #3
	bl FUN_080869c8
	movs r0, #0x10
	adds r2, r7, #0
	adds r2, #0xb4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D479E:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D47AC: .4byte 0x085AE0D0
_081D47B0: .4byte 0x000012B2

	thumb_func_start Elevator_Create
Elevator_Create: @ 0x081D47B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	ldr r0, _081D4824 @ =0x03000194
	ldr r0, [r0]
	str r0, [sp, #8]
	cmp r0, #0
	bne _081D47CC
	b _081D4E72
_081D47CC:
	movs r0, #0
	str r0, [sp, #0xc]
	ldr r0, [sp, #8]
	bl FUN_081d2314
	mov r8, r0
	cmp r0, #0
	bne _081D47DE
	b _081D4E72
_081D47DE:
	mov r4, r8
	adds r4, #0xb4
	mov r1, sp
	ldrh r1, [r1, #0xc]
	strh r1, [r4]
	mov r5, r8
	adds r5, #0xb8
	mov r2, sp
	ldrh r2, [r2, #0xc]
	strh r2, [r5]
	mov sb, r8
	movs r0, #0x72
	bl VM_SeekToKeyword
	mov sl, r4
	str r5, [sp, #0x1c]
	mov r1, r8
	adds r1, #0xe4
	str r1, [sp, #0x20]
	mov r2, r8
	adds r2, #0xe5
	str r2, [sp, #0x10]
	adds r1, #2
	str r1, [sp, #0x14]
	cmp r0, #0
	beq _081D4862
	bl VM_GetPC
	cmp r0, #0
	beq _081D4828
	bl Script_GetValue
	adds r1, r0, #0
	b _081D482A
	.align 2, 0
_081D4824: .4byte 0x03000194
_081D4828:
	movs r1, #0
_081D482A:
	mov r5, r8
	adds r5, #0xe4
	movs r0, #0
	strb r1, [r5]
	mov r4, r8
	adds r4, #0xe5
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0x20]
	str r4, [sp, #0x10]
	cmp r0, #0
	beq _081D484A
	bl Script_GetValue
	b _081D484C
_081D484A:
	movs r0, #0
_081D484C:
	mov r4, r8
	adds r4, #0xe6
	strb r0, [r4]
	mov r0, sb
	adds r0, #0x1c
	ldr r2, [sp, #0x20]
	ldrb r1, [r2]
	ldrb r2, [r4]
	bl FUN_08234f90
	str r4, [sp, #0x14]
_081D4862:
	movs r0, #0x6b
	movs r1, #0
	bl VM_GetKeywordValue
	mov r4, r8
	adds r4, #0xe7
	strb r0, [r4]
	movs r0, #0x59
	bl VM_SeekToKeyword
	str r4, [sp, #0x18]
	cmp r0, #0
	beq _081D4900
	subs r4, #0x1b
	bl VM_GetPC
	adds r5, r4, #0
	cmp r0, #0
	beq _081D488E
	bl Script_GetValue
	b _081D4890
_081D488E:
	movs r0, #0
_081D4890:
	str r0, [r4]
	mov r4, r8
	adds r4, #0xd0
	bl VM_GetPC
	adds r6, r4, #0
	cmp r0, #0
	beq _081D48A6
	bl Script_GetValue
	b _081D48A8
_081D48A6:
	movs r0, #0
_081D48A8:
	str r0, [r4]
	bl VM_GetPC
	cmp r0, #0
	beq _081D48BA
	bl Script_GetValue
	adds r2, r0, #0
	b _081D48BC
_081D48BA:
	movs r2, #0
_081D48BC:
	ldr r0, [sp, #0x18]
	ldrb r1, [r0]
	cmp r1, #2
	bne _081D48F0
	ldr r0, [r5]
	cmp r2, r0
	bne _081D48DC
	mov r1, sb
	strh r2, [r1, #0x1e]
	movs r0, #3
	rsbs r0, r0, #0
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081D48F6
_081D48DC:
	ldr r0, [r6]
	cmp r2, r0
	bne _081D48F6
	mov r0, sb
	strh r2, [r0, #0x1e]
	mov r2, sl
	ldrh r0, [r2]
	orrs r1, r0
	strh r1, [r2]
	b _081D48F6
_081D48F0:
	ldr r0, [r5]
	mov r1, sb
	strh r0, [r1, #0x1e]
_081D48F6:
	mov r2, sb
	ldrh r0, [r2, #0x1e]
	mov r1, r8
	adds r1, #0xfe
	strh r0, [r1]
_081D4900:
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	mov r6, r8
	adds r6, #0xd4
	strh r0, [r6]
	movs r0, #0x70
	movs r1, #0
	bl VM_GetKeywordValue
	mov r1, r8
	adds r1, #0xc0
	strh r0, [r1]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetKeywordValue
	mov r1, r8
	adds r1, #0xc2
	strh r0, [r1]
	movs r0, #0x53
	movs r1, #0
	bl VM_GetKeywordValue
	mov r1, r8
	adds r1, #0xc4
	strh r0, [r1]
	movs r0, #0x54
	movs r1, #0
	bl VM_GetKeywordValue
	mov r5, r8
	adds r5, #0xc8
	strh r0, [r5]
	mov r4, r8
	adds r4, #0x2c
	ldr r1, _081D4964 @ =0x0000B019
	adds r0, r4, #0
	bl Video_GetAuxSprite
	ldr r0, [sp, #0x18]
	ldrb r7, [r0]
	cmp r7, #1
	beq _081D4A1C
	cmp r7, #1
	bgt _081D4968
	cmp r7, #0
	beq _081D4974
	b _081D4B4E
	.align 2, 0
_081D4964: .4byte 0x0000B019
_081D4968:
	cmp r7, #2
	bne _081D496E
	b _081D4AA8
_081D496E:
	cmp r7, #3
	beq _081D49C8
	b _081D4B4E
_081D4974:
	mov r0, r8
	adds r0, #0xcc
	ldr r0, [r0]
	mov r1, sb
	strh r0, [r1, #0x1e]
	mov r1, r8
	adds r1, #0xb2
	movs r0, #1
	strh r0, [r1]
	adds r1, #0x26
	ldr r0, _081D49BC @ =FUN_081d3534
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D49C0 @ =FUN_081d3c24
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D49C4 @ =FUN_081d33f8
	str r0, [r1]
	movs r2, #1
	str r2, [sp, #0xc]
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081D49B8
	mov r1, r8
	adds r1, #0xd6
	strh r0, [r1]
_081D49B8:
	strh r7, [r5]
	b _081D4B4E
	.align 2, 0
_081D49BC: .4byte FUN_081d3534
_081D49C0: .4byte FUN_081d3c24
_081D49C4: .4byte FUN_081d33f8
_081D49C8:
	mov r0, r8
	adds r0, #0xcc
	ldr r0, [r0]
	mov r1, sb
	strh r0, [r1, #0x1e]
	mov r1, r8
	adds r1, #0xb2
	movs r0, #1
	strh r0, [r1]
	adds r1, #0x26
	ldr r0, _081D4A10 @ =FUN_081d3534
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D4A14 @ =FUN_081d3c24
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D4A18 @ =FUN_081d33f8
	str r0, [r1]
	movs r2, #1
	str r2, [sp, #0xc]
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081D4A9C
	mov r1, r8
	adds r1, #0xd6
	strh r0, [r1]
	b _081D4A9C
	.align 2, 0
_081D4A10: .4byte FUN_081d3534
_081D4A14: .4byte FUN_081d3c24
_081D4A18: .4byte FUN_081d33f8
_081D4A1C:
	mov r0, r8
	adds r0, #0xcc
	ldr r0, [r0]
	mov r1, sb
	strh r0, [r1, #0x1e]
	mov r0, r8
	adds r0, #0xb2
	strh r7, [r0]
	mov r1, r8
	adds r1, #0xd8
	ldr r0, _081D4A54 @ =FUN_081d36c0
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D4A58 @ =FUN_081d3dd0
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D4A5C @ =FUN_081d33f8
	str r0, [r1]
	movs r2, #2
	str r2, [sp, #0xc]
	ldrh r0, [r5]
	cmp r0, #1
	beq _081D4A70
	cmp r0, #1
	bgt _081D4A60
	cmp r0, #0
	beq _081D4A66
	b _081D4A84
	.align 2, 0
_081D4A54: .4byte FUN_081d36c0
_081D4A58: .4byte FUN_081d3dd0
_081D4A5C: .4byte FUN_081d33f8
_081D4A60:
	cmp r0, #2
	beq _081D4A7C
	b _081D4A84
_081D4A66:
	ldr r1, _081D4A6C @ =0x000001B9
	b _081D4A74
	.align 2, 0
_081D4A6C: .4byte 0x000001B9
_081D4A70:
	movs r1, #0xde
	lsls r1, r1, #1
_081D4A74:
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
	b _081D4A84
_081D4A7C:
	ldr r1, _081D4AA4 @ =0x000001BD
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
_081D4A84:
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081D4A96
	mov r1, r8
	adds r1, #0xd6
	strh r0, [r1]
_081D4A96:
	ldrh r0, [r5]
	cmp r0, #2
	bls _081D4B4E
_081D4A9C:
	movs r0, #0
	strh r0, [r5]
	b _081D4B4E
	.align 2, 0
_081D4AA4: .4byte 0x000001BD
_081D4AA8:
	mov r1, r8
	adds r1, #0xb2
	movs r0, #4
	strh r0, [r1]
	adds r1, #0x26
	ldr r0, _081D4AD8 @ =FUN_081d38a4
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D4ADC @ =FUN_081d3a8c
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D4AE0 @ =FUN_081d33f8
	str r0, [r1]
	movs r0, #0
	str r0, [sp, #0xc]
	ldrh r0, [r5]
	cmp r0, #1
	beq _081D4AFC
	cmp r0, #1
	bgt _081D4AE4
	cmp r0, #0
	beq _081D4AEE
	b _081D4B20
	.align 2, 0
_081D4AD8: .4byte FUN_081d38a4
_081D4ADC: .4byte FUN_081d3a8c
_081D4AE0: .4byte FUN_081d33f8
_081D4AE4:
	cmp r0, #2
	beq _081D4B0C
	cmp r0, #3
	beq _081D4B18
	b _081D4B20
_081D4AEE:
	adds r0, r4, #0
	ldr r1, _081D4AF8 @ =0x000001B7
	bl Video_SetAuxSpritePltt
	b _081D4B20
	.align 2, 0
_081D4AF8: .4byte 0x000001B7
_081D4AFC:
	adds r0, r4, #0
	ldr r1, _081D4B08 @ =0x000001B9
	bl Video_SetAuxSpritePltt
	b _081D4B20
	.align 2, 0
_081D4B08: .4byte 0x000001B9
_081D4B0C:
	adds r0, r4, #0
	movs r1, #0xdf
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	b _081D4B20
_081D4B18:
	adds r0, r4, #0
	ldr r1, _081D4BA0 @ =0x000001BD
	bl Video_SetAuxSpritePltt
_081D4B20:
	movs r0, #0x6d
	movs r1, #1
	bl VM_GetKeywordValue
	mov r1, r8
	adds r1, #0xd6
	strh r0, [r1]
	movs r0, #0x77
	movs r1, #0x78
	bl VM_GetKeywordValue
	mov r7, r8
	adds r7, #0xbc
	strh r0, [r7]
	movs r0, #0x4d
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081D4B4E
	ldrh r0, [r7]
	ldr r1, [sp, #0x1c]
	strh r0, [r1]
_081D4B4E:
	mov r0, sb
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	mov r4, r8
	adds r4, #0x48
	ldr r2, [sp, #8]
	ldr r1, [r2, #0x18]
	ldr r2, [sp, #0xc]
	ldrb r3, [r5]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	bl FUN_08236fac
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	mov r2, r8
	ldr r1, [r2, #0x48]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	mov r1, sb
	strh r0, [r1, #0x10]
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
	beq _081D4BA4
	mov r2, sb
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	b _081D4BB0
	.align 2, 0
_081D4BA0: .4byte 0x000001BD
_081D4BA4:
	mov r1, sb
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, sb
_081D4BB0:
	str r0, [r2]
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
	beq _081D4BD6
	mov r1, sb
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _081D4BE0
_081D4BD6:
	mov r1, sb
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D4BE0:
	mov r2, sb
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D4C18 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D4C50
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D4C1C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D4C12
	ldrb r0, [r4, #5]
_081D4C12:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D4C2C
	.align 2, 0
_081D4C18: .4byte 0x0000FFFF
_081D4C1C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D4C2C
	strh r1, [r4, #8]
_081D4C2C:
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
	bne _081D4C50
	movs r0, #1
	strb r0, [r4, #7]
_081D4C50:
	mov r1, sb
	ldr r0, [r1]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, sb
	str r0, [r2]
	movs r7, #0
	movs r0, #2
	strb r0, [r2, #7]
	mov r4, r8
	adds r4, #0xf4
	mov r0, r8
	adds r0, #0xb0
	ldr r2, _081D4D20 @ =0xFFFFD0E9
	adds r1, r2, #0
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r2, sb
	adds r2, #0x1c
	movs r0, #7
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823b400
	adds r0, r4, #0
	mov r1, sb
	bl FUN_0823b46c
	mov r5, r8
	adds r5, #0xe8
	ldr r1, [sp, #0x20]
	ldrb r2, [r1]
	ldr r0, [sp, #0x10]
	ldrb r3, [r0]
	ldr r1, [sp, #0x14]
	ldrb r0, [r1]
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0823b490
	str r7, [r4, #0x18]
	ldr r2, _081D4D24 @ =0xFFFFFF00
	adds r0, r2, #0
	mov r1, sb
	ldrh r1, [r1, #0x1c]
	adds r0, r0, r1
	mov r2, sb
	strh r0, [r2, #0x1c]
	movs r0, #0x64
	movs r1, #0
	bl VM_GetKeywordValue
	mov sb, r5
	cmp r0, #0
	beq _081D4CD6
	movs r0, #0x80
	mov r2, sl
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D4CD6:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081D4CEE
	movs r0, #0x80
	lsls r0, r0, #5
	mov r2, sl
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D4CEE:
	mov r1, r8
	adds r1, #0xb6
	movs r0, #0
	strb r0, [r1]
	mov r0, r8
	adds r0, #0xc6
	strh r7, [r0]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	adds r5, r0, #0
	cmp r5, #0
	bne _081D4D0C
	b _081D4E26
_081D4D0C:
	ldr r1, [sp, #0x18]
	ldrb r0, [r1]
	cmp r0, #2
	beq _081D4D34
	cmp r0, #2
	bgt _081D4D28
	cmp r0, #0
	blt _081D4D3C
	b _081D4D2C
	.align 2, 0
_081D4D20: .4byte 0xFFFFD0E9
_081D4D24: .4byte 0xFFFFFF00
_081D4D28:
	cmp r0, #3
	bne _081D4D3C
_081D4D2C:
	mov r1, r8
	adds r1, #0xb2
	movs r0, #1
	b _081D4D3A
_081D4D34:
	mov r1, r8
	adds r1, #0xb2
	movs r0, #4
_081D4D3A:
	strh r0, [r1]
_081D4D3C:
	ldr r2, [sp, #8]
	ldr r0, _081D4DA0 @ =0x000012B0
	adds r4, r2, r0
	ldrh r0, [r4]
	movs r1, #0
	bl FUN_081d3fac
	ldrh r0, [r6]
	strh r0, [r4]
	ldr r4, _081D4DA4 @ =0x03002BE0
	ldr r0, [r4]
	ldrh r2, [r6]
	movs r1, #1
	bl FUN_0807a97c
	movs r0, #8
	mov r2, sl
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, [r4]
	ldr r0, _081D4DA8 @ =0x0000060E
	adds r1, r1, r0
	ldrb r2, [r1]
	movs r0, #1
	orrs r0, r2
	strb r0, [r1]
	mov r1, r8
	adds r1, #0xfc
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	adds r7, r1, #0
	cmp r3, #0
	blt _081D4D9C
	cmp r2, #0
	blt _081D4D9C
	ldr r0, _081D4DAC @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _081D4D9C
	ldr r0, _081D4DB0 @ =0x030046AC
	ldr r0, [r0]
	cmp r2, r0
	blo _081D4DB4
_081D4D9C:
	movs r2, #0
	b _081D4DC2
	.align 2, 0
_081D4DA0: .4byte 0x000012B0
_081D4DA4: .4byte 0x03002BE0
_081D4DA8: .4byte 0x0000060E
_081D4DAC: .4byte 0x030046A8
_081D4DB0: .4byte 0x030046AC
_081D4DB4:
	ldr r0, _081D4E84 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r2, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r2, r0, r3
_081D4DC2:
	movs r0, #0x9c
	lsls r0, r0, #1
	add r0, r8
	mov r1, r8
	adds r1, #0xfe
	ldrh r3, [r1]
	lsls r3, r3, #0x10
	asrs r3, r3, #0x18
	movs r1, #0xff
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	adds r1, r2, #0
	movs r2, #0
	bl FUN_08234270
	movs r0, #1
	mov r2, sl
	ldrh r1, [r2]
	movs r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _081D4E88 @ =0x03002BE0
	ldr r0, [r0]
	adds r1, r7, #0
	bl FUN_0807a91c
	cmp r5, #2
	bne _081D4E26
	adds r0, r7, #0
	bl FUN_08086a4c
	ldr r0, [sp, #8]
	ldr r1, _081D4E8C @ =0x000012B2
	adds r4, r0, r1
	ldrh r0, [r4]
	movs r1, #1
	bl FUN_081d3fac
	ldrh r0, [r6]
	strh r0, [r4]
	ldrh r1, [r6]
	movs r0, #3
	bl FUN_080869c8
	movs r0, #0x10
	mov r2, sl
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D4E26:
	ldr r0, [sp, #8]
	mov r1, r8
	bl FUN_081d4704
	movs r0, #0x73
	movs r1, #6
	bl VM_GetKeywordValue
	mov r2, r8
	adds r2, #0xba
	strh r0, [r2]
	ldr r0, [sp, #0x18]
	ldrb r4, [r0]
	cmp r4, #0
	blt _081D4E6A
	cmp r4, #1
	ble _081D4E4C
	cmp r4, #3
	bne _081D4E6A
_081D4E4C:
	mov r1, r8
	adds r1, #0xfc
	movs r0, #0
	ldrsh r3, [r2, r0]
	mov r0, sb
	adds r2, r3, #0
	bl FUN_081d2660
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D4E6A
	mov r1, r8
	adds r1, #0xb2
	movs r0, #3
	strh r0, [r1]
_081D4E6A:
	mov r1, r8
	adds r1, #0xb7
	movs r0, #0
	strb r0, [r1]
_081D4E72:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D4E84: .4byte 0x030046A4
_081D4E88: .4byte 0x03002BE0
_081D4E8C: .4byte 0x000012B2

	thumb_func_start ElevatorController_Update
ElevatorController_Update: @ 0x081D4E90
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	mov r3, r8
	adds r3, #0x1c
	ldr r0, _081D4EF0 @ =0x000012AC
	add r0, r8
	ldr r0, [r0]
	cmp r0, #0
	bne _081D4EAA
	b _081D4FC6
_081D4EAA:
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _081D4EF4 @ =0x030047A4
	ldr r1, _081D4EF8 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _081D4ECA
	movs r1, #4
	ldr r0, _081D4EFC @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D4F0C
_081D4ECA:
	movs r0, #0xac
	lsls r0, r0, #1
	bl sound_08240740
	ldr r0, _081D4F00 @ =0x00000261
	bl sound_08240740
	ldr r0, _081D4F04 @ =0x00000289
	bl sound_08240740
	ldr r0, _081D4F08 @ =0x0000028A
	bl sound_08240740
	movs r0, #0xa2
	lsls r0, r0, #2
	bl sound_08240740
	b _081D4FC6
	.align 2, 0
_081D4EF0: .4byte 0x000012AC
_081D4EF4: .4byte 0x030047A4
_081D4EF8: .4byte 0x030047A0
_081D4EFC: .4byte 0x03002BC0
_081D4F00: .4byte 0x00000261
_081D4F04: .4byte 0x00000289
_081D4F08: .4byte 0x0000028A
_081D4F0C:
	ldr r0, _081D4F40 @ =0x030044BC
	ldr r0, [r0]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	bne _081D4FC6
	movs r0, #0
	mov sb, r0
	mov r6, r8
	adds r6, #0x38
	mov r7, r8
	adds r7, #0xce
	mov r5, r8
	adds r5, #0xf4
	adds r4, r3, #0
_081D4F2A:
	ldr r0, _081D4F44 @ =0x000012AC
	add r0, r8
	movs r1, #1
	mov r2, sb
	lsls r1, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D4F48
	movs r0, #1
	b _081D4F4A
	.align 2, 0
_081D4F40: .4byte 0x030044BC
_081D4F44: .4byte 0x000012AC
_081D4F48:
	movs r0, #0
_081D4F4A:
	cmp r0, #0
	beq _081D4FAA
	movs r1, #0
	ldrsh r0, [r7, r1]
	cmp r0, #6
	beq _081D4FAA
	ldr r1, [r5]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _081D4FD4 @ =0x085AE0E8
	movs r2, #0
	ldrsh r0, [r7, r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, [r5, #4]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, [r5, #8]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_081d31f0
	adds r0, r4, #0
	bl FUN_081d4540
	adds r0, r4, #0
	bl FUN_081d276c
	ldr r0, [r5, #0x24]
	ldr r1, [r5, #0x28]
	str r0, [r6]
	str r1, [r6, #4]
	ldr r1, _081D4FD8 @ =0xFFFFFF00
	adds r0, r1, #0
	ldrh r2, [r6]
	adds r0, r0, r2
	strh r0, [r6]
	adds r0, r4, #0
	bl FUN_081d2f04
_081D4FAA:
	movs r0, #0xc6
	lsls r0, r0, #1
	adds r6, r6, r0
	adds r7, r7, r0
	adds r5, r5, r0
	adds r4, r4, r0
	movs r1, #1
	add sb, r1
	mov r2, sb
	cmp r2, #0xb
	ble _081D4F2A
	mov r0, r8
	bl FUN_081d2a64
_081D4FC6:
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D4FD4: .4byte 0x085AE0E8
_081D4FD8: .4byte 0xFFFFFF00

	thumb_func_start ElevatorController_Destroy
ElevatorController_Destroy: @ 0x081D4FDC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	movs r0, #0xac
	lsls r0, r0, #1
	bl sound_08240740
	ldr r0, _081D502C @ =0x00000261
	bl sound_08240740
	ldr r0, _081D5030 @ =0x00000289
	bl sound_08240740
	ldr r0, _081D5034 @ =0x0000028A
	bl sound_08240740
	movs r0, #0xa2
	lsls r0, r0, #2
	bl sound_08240740
	movs r7, #0
	movs r0, #1
	mov sb, r0
	mov r6, r8
	adds r6, #0xd0
	mov r5, r8
	adds r5, #0x1c
_081D5016:
	ldr r0, _081D5038 @ =0x000012AC
	add r0, r8
	mov r1, sb
	lsls r1, r7
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D503C
	movs r0, #1
	b _081D503E
	.align 2, 0
_081D502C: .4byte 0x00000261
_081D5030: .4byte 0x00000289
_081D5034: .4byte 0x0000028A
_081D5038: .4byte 0x000012AC
_081D503C:
	movs r0, #0
_081D503E:
	cmp r0, #0
	beq _081D5076
	adds r4, r5, #0
	ldrh r0, [r6]
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	beq _081D5052
	movs r0, #1
	b _081D5054
_081D5052:
	movs r0, #0
_081D5054:
	cmp r0, #0
	beq _081D5062
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_082342a8
_081D5062:
	adds r0, r4, #0
	bl FUN_081d3188
	adds r0, r4, #0
	adds r0, #0xf4
	bl FUN_0823b284
	adds r0, r4, #0
	bl AuxSprite_Remove
_081D5076:
	movs r0, #0xc6
	lsls r0, r0, #1
	adds r6, r6, r0
	adds r5, r5, r0
	adds r7, #1
	cmp r7, #0xb
	ble _081D5016
	movs r1, #0
	ldr r0, _081D5098 @ =0x03000194
	str r1, [r0]
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D5098: .4byte 0x03000194

	thumb_func_start FUN_081d509c
FUN_081d509c: @ 0x081D509C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081D50BC @ =0x0000922E
	ldr r1, _081D50C0 @ =0x000013F9
	bl GetFile
	str r0, [r4, #0x18]
	ldr r0, _081D50C4 @ =0x03000194
	str r4, [r0]
	ldr r0, _081D50C8 @ =0x000012AC
	adds r4, r4, r0
	movs r0, #0
	str r0, [r4]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081D50BC: .4byte 0x0000922E
_081D50C0: .4byte 0x000013F9
_081D50C4: .4byte 0x03000194
_081D50C8: .4byte 0x000012AC

	thumb_func_start ElevatorController_Create
ElevatorController_Create: @ 0x081D50CC
	push {r4, lr}
	ldr r0, _081D5100 @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	bne _081D5112
	ldr r1, _081D5104 @ =0x000012B8
	movs r0, #5
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081D5110
	ldr r1, _081D5108 @ =ElevatorController_Update
	ldr r2, _081D510C @ =ElevatorController_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081d509c
	cmp r0, #0
	bge _081D5110
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081D5112
	.align 2, 0
_081D5100: .4byte 0x03000194
_081D5104: .4byte 0x000012B8
_081D5108: .4byte ElevatorController_Update
_081D510C: .4byte ElevatorController_Destroy
_081D5110:
	adds r0, r4, #0
_081D5112:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d5118
FUN_081d5118: @ 0x081D5118
	ldr r1, _081D5120 @ =0x03000194
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081D5120: .4byte 0x03000194

	thumb_func_start Elevator_Shake
Elevator_Shake: @ 0x081D5124
	push {lr}
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	ldr r0, _081D5158 @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D5152
	cmp r1, #0
	beq _081D5152
	adds r0, r1, #0
	bl FUN_081d3118
	adds r2, r0, #0
	cmp r2, #0
	beq _081D5152
	movs r0, #0x20
	adds r2, #0xb4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D5152:
	pop {r0}
	bx r0
	.align 2, 0
_081D5158: .4byte 0x03000194

	thumb_func_start FUN_081d515c
FUN_081d515c: @ 0x081D515C
	push {r4, r5, r6, r7, lr}
	ldr r0, _081D5180 @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D51D4
	adds r4, r0, #0
	ldr r0, _081D5184 @ =0x000012AC
	adds r5, r4, r0
	ldr r0, [r5]
	cmp r0, #0
	beq _081D51D4
	movs r0, #1
	bl FUN_08086978
	cmp r0, #0
	bne _081D5190
	b _081D51D4
	.align 2, 0
_081D5180: .4byte 0x03000194
_081D5184: .4byte 0x000012AC
_081D5188:
	adds r0, r4, #0
	adds r0, #0xd4
	ldrh r0, [r0]
	b _081D51D8
_081D5190:
	movs r3, #0
	ldr r6, [r5]
	movs r7, #0x10
	adds r2, r4, #0
	adds r2, #0xd0
	adds r1, r4, #0
	adds r1, #0x1c
	movs r5, #0xc6
	lsls r5, r5, #1
_081D51A2:
	movs r0, #1
	lsls r0, r3
	ands r0, r6
	cmp r0, #0
	beq _081D51B0
	movs r0, #1
	b _081D51B2
_081D51B0:
	movs r0, #0
_081D51B2:
	cmp r0, #0
	beq _081D51CA
	adds r4, r1, #0
	ldrh r0, [r2]
	ands r0, r7
	cmp r0, #0
	beq _081D51C4
	movs r0, #1
	b _081D51C6
_081D51C4:
	movs r0, #0
_081D51C6:
	cmp r0, #0
	bne _081D5188
_081D51CA:
	adds r2, r2, r5
	adds r1, r1, r5
	adds r3, #1
	cmp r3, #0xb
	ble _081D51A2
_081D51D4:
	movs r0, #1
	rsbs r0, r0, #0
_081D51D8:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Elevator_Start
Elevator_Start: @ 0x081D51E0
	push {r4, r5, r6, lr}
	movs r0, #0x6d
	movs r1, #1
	bl VM_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	ldr r0, _081D5238 @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D5260
	cmp r1, #0
	beq _081D5260
	adds r0, r1, #0
	bl FUN_081d3118
	adds r3, r0, #0
	cmp r3, #0
	beq _081D5260
	adds r0, #0xd6
	ldrh r1, [r0]
	movs r6, #2
	movs r2, #2
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _081D5260
	adds r0, r3, #0
	adds r0, #0xb2
	movs r5, #0
	strh r2, [r0]
	cmp r4, #4
	bne _081D523C
	adds r0, #2
	mvns r1, r6
	ldrh r2, [r0]
	ands r1, r2
	orrs r1, r4
	strh r1, [r0]
	b _081D5260
	.align 2, 0
_081D5238: .4byte 0x03000194
_081D523C:
	adds r1, r3, #0
	adds r1, #0xb4
	movs r2, #5
	rsbs r2, r2, #0
	ldrh r0, [r1]
	ands r2, r0
	strh r2, [r1]
	cmp r4, #2
	bne _081D5254
	orrs r4, r2
	strh r4, [r1]
	b _081D525A
_081D5254:
	mvns r0, r6
	ands r0, r2
	strh r0, [r1]
_081D525A:
	adds r0, r3, #0
	bl FUN_081d21d8
_081D5260:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d5268
FUN_081d5268: @ 0x081D5268
	push {r4, lr}
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	ldr r0, _081D529C @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D5296
	cmp r1, #0
	beq _081D5296
	adds r0, r1, #0
	bl FUN_081d3118
	adds r4, r0, #0
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0x6d
	bl VM_GetKeywordValue
	adds r4, #0xd6
	strh r0, [r4]
_081D5296:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081D529C: .4byte 0x03000194

	thumb_func_start FUN_081d52a0
FUN_081d52a0: @ 0x081D52A0
	push {r4, r5, lr}
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	ldr r5, _081D52D4 @ =0x03000194
	ldr r0, [r5]
	cmp r0, #0
	beq _081D5332
	cmp r1, #0
	beq _081D5332
	adds r0, r1, #0
	bl FUN_081d3118
	adds r4, r0, #0
	ldr r5, [r5]
	movs r1, #1
	adds r0, #0xb4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D52D8
	movs r0, #1
	b _081D52DA
	.align 2, 0
_081D52D4: .4byte 0x03000194
_081D52D8:
	movs r0, #0
_081D52DA:
	cmp r0, #0
	beq _081D52F6
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_082342a8
	adds r2, r4, #0
	adds r2, #0xb4
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081D52F6:
	adds r0, r4, #0
	bl FUN_081d3188
	adds r0, r4, #0
	adds r0, #0xf4
	bl FUN_0823b284
	adds r1, r4, #0
	adds r1, #0xd4
	movs r0, #0
	strh r0, [r1]
	subs r1, #0x22
	movs r0, #6
	strh r0, [r1]
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r3, r4, #0
	adds r3, #0xb0
	movs r1, #0
	ldrsh r0, [r3, r1]
	ldr r1, _081D5338 @ =0x000012AC
	adds r2, r5, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	ldr r0, _081D533C @ =0x0000FFFF
	strh r0, [r3]
_081D5332:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081D5338: .4byte 0x000012AC
_081D533C: .4byte 0x0000FFFF

	thumb_func_start FUN_081d5340
FUN_081d5340: @ 0x081D5340
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	ldr r0, _081D5388 @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D53C2
	cmp r1, #0
	beq _081D53C2
	adds r0, r1, #0
	bl FUN_081d3118
	adds r6, r0, #0
	movs r7, #0
	movs r0, #0
	mov r8, r0
	movs r5, #0
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D53AA
	bl VM_GetPC
	cmp r0, #0
	beq _081D538C
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	b _081D538E
	.align 2, 0
_081D5388: .4byte 0x03000194
_081D538C:
	movs r1, #0
_081D538E:
	adds r7, r1, #0
	movs r1, #0
	mov r8, r1
	bl VM_GetPC
	cmp r0, #0
	beq _081D53A6
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	b _081D53A8
_081D53A6:
	movs r3, #0
_081D53A8:
	adds r5, r3, #0
_081D53AA:
	adds r4, r6, #0
	adds r4, #0xe8
	adds r0, r4, #0
	adds r1, r7, #0
	mov r2, r8
	adds r3, r5, #0
	bl FUN_08234de8
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r6, r1
	str r4, [r0]
_081D53C2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d53cc
FUN_081d53cc: @ 0x081D53CC
	push {r4, lr}
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	ldr r0, _081D540C @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D5406
	cmp r1, #0
	beq _081D5406
	adds r0, r1, #0
	bl FUN_081d3118
	adds r4, r0, #0
	cmp r4, #0
	beq _081D5406
	movs r0, #0x63
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	adds r0, r4, #0
	adds r0, #0x2c
	ldr r2, _081D5410 @ =0x000001B7
	adds r1, r1, r2
	bl Video_SetAuxSpritePltt
_081D5406:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081D540C: .4byte 0x03000194
_081D5410: .4byte 0x000001B7

	thumb_func_start FUN_081d5414
FUN_081d5414: @ 0x081D5414
	push {r4, lr}
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	ldr r0, _081D544C @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D5446
	cmp r1, #0
	beq _081D5446
	adds r0, r1, #0
	bl FUN_081d3118
	adds r4, r0, #0
	cmp r4, #0
	beq _081D5446
	movs r0, #0x73
	movs r1, #6
	bl VM_GetKeywordValue
	adds r1, r4, #0
	adds r1, #0xba
	strh r0, [r1]
_081D5446:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081D544C: .4byte 0x03000194

	thumb_func_start FUN_081d5450
FUN_081d5450: @ 0x081D5450
	push {r4, r5, lr}
	ldr r0, _081D5498 @ =0x03000194
	ldr r4, [r0]
	bl FUN_081d3150
	adds r5, r0, #0
	ldr r0, _081D549C @ =0x000012B0
	adds r4, r4, r0
	movs r0, #0
	strh r0, [r4]
	ldr r4, _081D54A0 @ =0x03002BE0
	ldr r0, [r4]
	movs r2, #0xde
	lsls r2, r2, #1
	adds r1, r0, r2
	str r1, [r0, #0x3c]
	movs r1, #1
	bl FUN_0807a99c
	adds r5, #0xb4
	movs r0, #9
	rsbs r0, r0, #0
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	ldr r1, [r4]
	ldr r0, _081D54A4 @ =0x0000060E
	adds r1, r1, r0
	ldrb r2, [r1]
	movs r0, #0xfe
	ands r0, r2
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081D5498: .4byte 0x03000194
_081D549C: .4byte 0x000012B0
_081D54A0: .4byte 0x03002BE0
_081D54A4: .4byte 0x0000060E

	thumb_func_start FUN_081d54a8
FUN_081d54a8: @ 0x081D54A8
	push {r4, r5, r6, lr}
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	ldr r0, _081D5500 @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D54F8
	cmp r1, #0
	beq _081D54F8
	adds r0, r1, #0
	bl FUN_081d3118
	adds r5, r0, #0
	cmp r5, #0
	beq _081D54F8
	movs r4, #1
	rsbs r4, r4, #0
	movs r0, #0x68
	adds r1, r4, #0
	bl VM_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x6c
	adds r1, r4, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	cmp r6, #0
	ble _081D54EE
	adds r0, r5, #0
	adds r0, #0xd0
	str r6, [r0]
_081D54EE:
	cmp r1, #0
	ble _081D54F8
	adds r0, r5, #0
	adds r0, #0xcc
	str r1, [r0]
_081D54F8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081D5500: .4byte 0x03000194

	thumb_func_start FUN_081d5504
FUN_081d5504: @ 0x081D5504
	push {lr}
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	ldr r0, _081D5534 @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D5530
	cmp r1, #0
	beq _081D5530
	adds r0, r1, #0
	bl FUN_081d3118
	cmp r0, #0
	beq _081D5530
	adds r0, #0xb4
	ldr r1, _081D5538 @ =0xFFFFEFFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_081D5530:
	pop {r0}
	bx r0
	.align 2, 0
_081D5534: .4byte 0x03000194
_081D5538: .4byte 0xFFFFEFFF

	thumb_func_start FUN_081d553c
FUN_081d553c: @ 0x081D553C
	push {lr}
	adds r1, r0, #0
	ldr r0, _081D555C @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D5560
	cmp r1, #0
	beq _081D5560
	adds r0, r1, #0
	bl FUN_081d3118
	cmp r0, #0
	beq _081D5560
	adds r0, #0xfc
	b _081D5562
	.align 2, 0
_081D555C: .4byte 0x03000194
_081D5560:
	movs r0, #0
_081D5562:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d5568
FUN_081d5568: @ 0x081D5568
	push {lr}
	adds r1, r0, #0
	ldr r0, _081D557C @ =0x03000194
	ldr r0, [r0]
	cmp r0, #0
	beq _081D5580
	adds r0, r1, #0
	adds r0, #0xfc
	b _081D5582
	.align 2, 0
_081D557C: .4byte 0x03000194
_081D5580:
	movs r0, #0
_081D5582:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d5588
FUN_081d5588: @ 0x081D5588
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _081D5600 @ =0x03000194
	ldr r4, [r0]
	cmp r4, #0
	bne _081D5596
	b _081D5814
_081D5596:
	adds r6, r5, #0
	adds r6, #0xd6
	ldrh r1, [r6]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _081D55D2
	ldr r0, _081D5604 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	bne _081D55B4
	b _081D5814
_081D55B4:
	ldr r1, _081D5608 @ =0x000012B0
	adds r0, r4, r1
	adds r1, r5, #0
	adds r1, #0xd4
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _081D55C6
	b _081D5814
_081D55C6:
	ldrh r1, [r6]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _081D55D2
	b _081D5814
_081D55D2:
	adds r0, r5, #0
	adds r0, #0xfc
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D55FA
	cmp r1, #0
	blt _081D55FA
	ldr r0, _081D560C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D55FA
	ldr r0, _081D5610 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D5614
_081D55FA:
	movs r7, #0
	b _081D5622
	.align 2, 0
_081D5600: .4byte 0x03000194
_081D5604: .4byte 0x03002BE0
_081D5608: .4byte 0x000012B0
_081D560C: .4byte 0x030046A8
_081D5610: .4byte 0x030046AC
_081D5614:
	ldr r0, _081D5640 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r7, r0, r2
_081D5622:
	adds r0, r5, #0
	adds r0, #0xfe
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r6, r0, #0x18
	adds r4, r7, #1
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D5644
	adds r0, #4
	b _081D5650
	.align 2, 0
_081D5640: .4byte 0x030046A4
_081D5644:
	ldr r0, _081D566C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D5650:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _081D5686
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D5670
	adds r0, #4
	b _081D567C
	.align 2, 0
_081D566C: .4byte 0x030046A4
_081D5670:
	ldr r0, _081D568C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D567C:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	beq _081D5690
_081D5686:
	movs r0, #0
	b _081D5692
	.align 2, 0
_081D568C: .4byte 0x030046A4
_081D5690:
	movs r0, #1
_081D5692:
	cmp r0, #0
	beq _081D56A4
	ldr r0, _081D56A0 @ =0x00000151
	bl PlaySound_082406e0
	movs r0, #1
	b _081D56A6
	.align 2, 0
_081D56A0: .4byte 0x00000151
_081D56A4:
	movs r0, #0
_081D56A6:
	cmp r0, #0
	beq _081D56AC
	b _081D5814
_081D56AC:
	subs r4, r7, #1
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D56BE
	adds r0, #4
	b _081D56CA
_081D56BE:
	ldr r0, _081D56E4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D56CA:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _081D56FE
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D56E8
	adds r0, #4
	b _081D56F4
	.align 2, 0
_081D56E4: .4byte 0x030046A4
_081D56E8:
	ldr r0, _081D5704 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D56F4:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	beq _081D5708
_081D56FE:
	movs r0, #0
	b _081D570A
	.align 2, 0
_081D5704: .4byte 0x030046A4
_081D5708:
	movs r0, #1
_081D570A:
	cmp r0, #0
	beq _081D571C
	ldr r0, _081D5718 @ =0x00000151
	bl PlaySound_082406e0
	movs r0, #1
	b _081D571E
	.align 2, 0
_081D5718: .4byte 0x00000151
_081D571C:
	movs r0, #0
_081D571E:
	cmp r0, #0
	bne _081D5814
	ldr r5, _081D5740 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r7, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D5744
	adds r0, #4
	b _081D574E
	.align 2, 0
_081D5740: .4byte 0x030046A4
_081D5744:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081D574E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _081D577E
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D5768
	adds r0, #4
	b _081D5774
_081D5768:
	ldr r0, _081D5784 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D5774:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	beq _081D5788
_081D577E:
	movs r0, #0
	b _081D578A
	.align 2, 0
_081D5784: .4byte 0x030046A4
_081D5788:
	movs r0, #1
_081D578A:
	cmp r0, #0
	beq _081D579C
	ldr r0, _081D5798 @ =0x00000151
	bl PlaySound_082406e0
	movs r0, #1
	b _081D579E
	.align 2, 0
_081D5798: .4byte 0x00000151
_081D579C:
	movs r0, #0
_081D579E:
	cmp r0, #0
	bne _081D5814
	ldr r5, _081D57C0 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r7, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D57C4
	adds r0, #4
	b _081D57CE
	.align 2, 0
_081D57C0: .4byte 0x030046A4
_081D57C4:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081D57CE:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _081D57FE
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D57E8
	adds r0, #4
	b _081D57F4
_081D57E8:
	ldr r0, _081D5804 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D57F4:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	beq _081D5808
_081D57FE:
	movs r0, #0
	b _081D580A
	.align 2, 0
_081D5804: .4byte 0x030046A4
_081D5808:
	movs r0, #1
_081D580A:
	cmp r0, #0
	beq _081D5814
	ldr r0, _081D581C @ =0x00000151
	bl PlaySound_082406e0
_081D5814:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D581C: .4byte 0x00000151
