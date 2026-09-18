	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080051d0
FUN_080051d0: @ 0x080051D0
	ldr r1, _080051D8 @ =0x03000028
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080051D8: .4byte 0x03000028

	thumb_func_start FUN_080051dc
FUN_080051dc: @ 0x080051DC
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r2, r0, #0
	adds r3, r1, #0
	adds r0, #0x35
	ldrb r0, [r0]
	cmp r0, #0
	beq _08005228
	str r3, [sp]
	movs r1, #0
	add r5, sp, #0x14
	ldr r4, [r2, #0x54]
	adds r3, r2, #0
	adds r3, #0x44
	add r2, sp, #4
_080051FA:
	ldm r3!, {r0}
	stm r2!, {r0}
	adds r1, #1
	cmp r1, #3
	ble _080051FA
	ldr r0, _08005224 @ =0xFFFF0000
	ldr r1, [sp, #0x14]
	ands r1, r0
	movs r0, #5
	orrs r1, r0
	str r1, [sp, #0x14]
	mov r0, sp
	str r0, [r5, #4]
	cmp r4, #0
	beq _08005230
	adds r0, r4, #0
	adds r1, r5, #0
	bl Script_ExecById
	b _08005230
	.align 2, 0
_08005224: .4byte 0xFFFF0000
_08005228:
	ldr r1, [r2, #0x58]
	adds r0, r3, #0
	bl _call_via_r1
_08005230:
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08005238
FUN_08005238: @ 0x08005238
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	cmp r5, #0
	blt _08005278
	ldrb r0, [r4, #0x1b]
	cmp r5, r0
	blt _0800524A
	subs r5, r0, #1
_0800524A:
	lsls r0, r5, #2
	adds r0, #0x64
	adds r3, r4, r0
	movs r0, #0x86
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	ldr r2, _08005274 @ =0xFFFFFDFF
	ands r0, r2
	str r0, [r1]
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldrb r0, [r3]
	subs r0, #7
	movs r2, #0x92
	lsls r2, r2, #1
	b _080052A4
	.align 2, 0
_08005274: .4byte 0xFFFFFDFF
_08005278:
	movs r0, #0x19
	ldrsb r0, [r4, r0]
	lsls r0, r0, #2
	adds r0, #0x64
	adds r3, r4, r0
	movs r0, #0x86
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #2
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrb r0, [r3]
	subs r0, #7
	subs r2, #0xdc
_080052A4:
	adds r1, r4, r2
	strh r0, [r1]
	ldrb r0, [r3, #1]
	adds r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	ldrb r1, [r3]
	adds r1, #1
	ldrb r0, [r3, #2]
	lsls r0, r0, #3
	adds r1, r1, r0
	adds r2, #0x5e
	adds r0, r4, r2
	strh r1, [r0]
	ldrb r0, [r3, #1]
	adds r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	movs r0, #0x18
	ldrsb r0, [r4, r0]
	cmp r5, r0
	beq _080052D6
	movs r0, #0xdc
	bl PlaySound_082406e0
_080052D6:
	strb r5, [r4, #0x18]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080052e0
FUN_080052e0: @ 0x080052E0
	push {r4, r5, r6, lr}
	mov ip, r0
	adds r5, r1, #0
	adds r4, r2, #0
	adds r3, r5, #0
	movs r1, #0
	adds r0, #0x34
	ldrb r2, [r0]
	cmp r1, r2
	bge _08005322
	mov r2, ip
	adds r2, #0x2c
_080052F8:
	adds r3, r3, r4
	ldrb r0, [r0]
	cmp r3, r0
	ble _08005304
	adds r3, r0, #0
	b _0800530A
_08005304:
	cmp r3, #0
	bge _0800530A
	movs r3, #0
_0800530A:
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08005316
	adds r0, r3, #0
	b _08005324
_08005316:
	adds r1, #1
	mov r0, ip
	adds r0, #0x34
	ldrb r6, [r0]
	cmp r1, r6
	blt _080052F8
_08005322:
	adds r0, r5, #0
_08005324:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800532c
FUN_0800532c: @ 0x0800532C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r0, #0x86
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r0, #0x18
	ldrsb r0, [r5, r0]
	cmp r0, #0
	bge _08005394
	ldr r0, _0800538C @ =0x030044E0
	ldrh r2, [r0, #2]
	movs r0, #0xf0
	ands r0, r2
	cmp r0, #0
	bne _08005378
	adds r1, r5, #0
	adds r1, #0x3d
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800539E
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _08005378
	b _08005522
_08005378:
	movs r1, #0x19
	ldrsb r1, [r5, r1]
	adds r0, r5, #0
	bl FUN_08005238
	ldr r0, _08005390 @ =0x00000107
	bl PlaySound_082406e0
	b _08005522
	.align 2, 0
_0800538C: .4byte 0x030044E0
_08005390: .4byte 0x00000107
_08005394:
	adds r1, r5, #0
	adds r1, #0x3d
	ldrb r0, [r1]
	cmp r0, #0
	beq _080053A4
_0800539E:
	subs r0, #1
	strb r0, [r1]
	b _08005522
_080053A4:
	ldr r0, _080053C4 @ =0x030044E0
	ldrh r0, [r0]
	ldr r1, [r5, #0x40]
	ands r1, r0
	cmp r1, #0
	beq _080053C8
	adds r0, r5, #0
	adds r0, #0x3e
	ldrb r1, [r0]
	mov r8, r0
	cmp r1, #0
	beq _080053D0
	subs r0, r1, #1
	mov r1, r8
	strb r0, [r1]
	b _080053D0
	.align 2, 0
_080053C4: .4byte 0x030044E0
_080053C8:
	adds r0, r5, #0
	adds r0, #0x3e
	strb r1, [r0]
	mov r8, r0
_080053D0:
	ldr r0, _08005408 @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	str r0, [r5, #0x40]
	mov r2, r8
	ldrb r0, [r2]
	cmp r0, #0
	bne _080054C8
	movs r2, #0x18
	ldrsb r2, [r5, r2]
	lsls r0, r2, #2
	adds r0, #0x64
	adds r7, r5, r0
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800540C
	subs r1, r2, #1
	adds r0, r5, #0
	adds r0, #0x1c
	ldrb r7, [r7, #3]
	adds r0, r0, r7
	ldrb r0, [r0]
	cmp r1, r0
	bge _08005468
	b _08005466
	.align 2, 0
_08005408: .4byte 0x030044E0
_0800540C:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08005420
	adds r1, r2, #1
	adds r0, r5, #0
	adds r0, #0x24
	ldrb r7, [r7, #3]
	adds r0, r0, r7
	b _080054B4
_08005420:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08005476
	ldrb r1, [r7, #3]
	adds r4, r5, #0
	adds r4, #0x1c
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r6, r2, r0
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r5, #0
	bl FUN_080052e0
	adds r2, r0, #0
	ldrb r0, [r7, #3]
	cmp r0, r2
	bne _0800544C
	movs r1, #0x18
	ldrsb r1, [r5, r1]
	b _08005452
_0800544C:
	adds r0, r4, r2
	ldrb r0, [r0]
	adds r1, r0, r6
_08005452:
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r1, r0
	blt _08005466
	adds r0, r5, #0
	adds r0, #0x24
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r1, r0
	ble _08005468
_08005466:
	adds r1, r0, #0
_08005468:
	adds r0, r5, #0
	bl FUN_08005238
	movs r0, #0x1e
	mov r1, r8
	strb r0, [r1]
	b _080054C8
_08005476:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080054C8
	ldrb r1, [r7, #3]
	adds r4, r5, #0
	adds r4, #0x1c
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r6, r2, r0
	adds r0, r5, #0
	movs r2, #1
	bl FUN_080052e0
	adds r2, r0, #0
	ldrb r0, [r7, #3]
	cmp r0, r2
	bne _080054A0
	movs r1, #0x18
	ldrsb r1, [r5, r1]
	b _080054A6
_080054A0:
	adds r0, r4, r2
	ldrb r0, [r0]
	adds r1, r0, r6
_080054A6:
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r1, r0
	blt _080054BA
	adds r0, r5, #0
	adds r0, #0x24
	adds r0, r0, r2
_080054B4:
	ldrb r0, [r0]
	cmp r1, r0
	ble _080054BC
_080054BA:
	adds r1, r0, #0
_080054BC:
	adds r0, r5, #0
	bl FUN_08005238
	movs r0, #0x1e
	mov r2, r8
	strb r0, [r2]
_080054C8:
	ldr r0, _080054FC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08005500
	adds r0, r5, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #0
	beq _08005522
	movs r0, #0xde
	bl PlaySound_082406e0
	bl FUN_08047864
	movs r1, #1
	rsbs r1, r1, #0
	adds r0, r5, #0
	bl FUN_080051dc
	adds r0, r5, #0
	bl KillEntity
	b _08005522
	.align 2, 0
_080054FC: .4byte 0x030044E0
_08005500:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08005522
	movs r0, #0xdd
	bl PlaySound_082406e0
	bl FUN_08047864
	movs r1, #0x18
	ldrsb r1, [r5, r1]
	adds r0, r5, #0
	bl FUN_080051dc
	adds r0, r5, #0
	bl KillEntity
_08005522:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start Entity08005b54_Update
Entity08005b54_Update: @ 0x0800552C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	beq _0800556C
	bl FUN_08048914
	cmp r0, #0
	beq _0800556C
	ldrb r0, [r5, #0x1a]
	cmp r0, #0
	bne _0800554C
	adds r0, r5, #0
	bl FUN_0800532c
	b _08005550
_0800554C:
	subs r0, #1
	strb r0, [r5, #0x1a]
_08005550:
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0xe4
	adds r1, r4, #0
	bl MainSprite_AdvanceAnim
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r4, #0
	bl MainSprite_AdvanceAnim
_0800556C:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start Entity08005b54_Destroy
Entity08005b54_Destroy: @ 0x08005574
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_0822f1c0
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_0822f1c0
	ldr r1, _08005598 @ =0x03000028
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08005598: .4byte 0x03000028

	thumb_func_start FUN_0800559c
FUN_0800559c: @ 0x0800559C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x36
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x37
	ldrb r1, [r1]
	adds r2, r4, #0
	adds r2, #0x38
	ldrb r2, [r2]
	adds r3, r4, #0
	adds r3, #0x39
	ldrb r3, [r3]
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	ldr r0, [r4, #0x5c]
	bl FUN_080478f0
	ldr r0, [r4, #0x60]
	bl FUN_08047a28
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080055d4
FUN_080055d4: @ 0x080055D4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r4, #0
	ldrb r0, [r4]
	cmp r0, #0x2f
	bne _080055EE
	b _080057E2
_080055EE:
	ldr r1, _08005638 @ =0x08251B3C
	adds r0, r4, #0
	movs r2, #5
	bl FUN_08048bf4
	cmp r0, #0
	bne _080056D0
	movs r0, #0
	mov ip, r0
	movs r3, #0
	ldrb r0, [r4]
	adds r2, r6, #0
	adds r2, #0xa4
	movs r1, #0x3f
	adds r1, r1, r6
	mov sb, r1
	adds r1, r6, #0
	adds r1, #0x36
	str r1, [sp]
	movs r1, #0x3b
	adds r1, r1, r6
	mov r8, r1
	adds r1, r6, #0
	adds r1, #0x37
	str r1, [sp, #4]
	movs r1, #0x34
	adds r1, r1, r6
	mov sl, r1
	adds r7, r6, #0
	adds r7, #0x3a
	cmp r0, #0x3e
	beq _08005662
	cmp r0, #0
	bne _0800563C
	adds r5, r4, #1
	b _08005662
	.align 2, 0
_08005638: .4byte 0x08251B3C
_0800563C:
	ldrb r1, [r5]
	cmp r1, #0x3d
	bne _08005648
	movs r4, #1
	mov ip, r4
	b _08005654
_08005648:
	mov r0, ip
	cmp r0, #0
	beq _08005654
	adds r0, r2, r3
	strb r1, [r0]
	adds r3, #1
_08005654:
	adds r5, #1
	ldrb r0, [r5]
	cmp r0, #0x3e
	beq _08005662
	cmp r0, #0
	bne _0800563C
	adds r5, #1
_08005662:
	adds r1, r2, r3
	movs r0, #0
	strb r0, [r1]
	mov r1, ip
	cmp r1, #0
	beq _08005680
	cmp r3, #0
	beq _08005680
	adds r0, r2, #0
	adds r1, r3, #0
	bl FUN_08048c2c
	mov r2, sb
	strb r0, [r2]
	b _08005686
_08005680:
	movs r0, #0
	mov r3, sb
	strb r0, [r3]
_08005686:
	adds r0, r5, #0
	movs r1, #0x3e
	bl FUN_08048cc8
	adds r5, r0, #0
	ldrb r0, [r6, #0x1b]
	lsls r0, r0, #2
	adds r0, r6, r0
	mov r4, r8
	ldrb r1, [r4]
	ldr r2, [sp]
	ldrb r2, [r2]
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r0, #0x64
	movs r3, #0
	strb r1, [r0]
	ldrb r1, [r6, #0x1b]
	lsls r1, r1, #2
	adds r1, r6, r1
	ldr r4, [sp, #4]
	ldrb r2, [r4]
	lsls r2, r2, #3
	mov r4, sl
	ldrb r0, [r4]
	lsls r0, r0, #4
	adds r2, r2, r0
	adds r1, #0x65
	strb r2, [r1]
	ldrb r0, [r6, #0x1b]
	lsls r0, r0, #2
	adds r0, r6, r0
	ldrb r1, [r4]
	adds r0, #0x67
	strb r1, [r0]
	strb r3, [r7]
	b _08005854
_080056D0:
	ldr r1, _08005700 @ =0x08251B44
	adds r0, r4, #0
	movs r2, #6
	bl FUN_08048bf4
	cmp r0, #0
	bne _0800574C
	movs r0, #0
	mov ip, r0
	movs r3, #0
	ldrb r0, [r4]
	adds r2, r6, #0
	adds r2, #0xa4
	movs r1, #0x3b
	adds r1, r1, r6
	mov r8, r1
	adds r7, r6, #0
	adds r7, #0x3a
	cmp r0, #0x3e
	beq _0800572A
	cmp r0, #0
	bne _08005704
	adds r5, r4, #1
	b _0800572A
	.align 2, 0
_08005700: .4byte 0x08251B44
_08005704:
	ldrb r1, [r5]
	cmp r1, #0x3d
	bne _08005710
	movs r4, #1
	mov ip, r4
	b _0800571C
_08005710:
	mov r0, ip
	cmp r0, #0
	beq _0800571C
	adds r0, r2, r3
	strb r1, [r0]
	adds r3, #1
_0800571C:
	adds r5, #1
	ldrb r0, [r5]
	cmp r0, #0x3e
	beq _0800572A
	cmp r0, #0
	bne _08005704
	adds r5, #1
_0800572A:
	adds r1, r2, r3
	movs r0, #0
	strb r0, [r1]
	mov r1, ip
	cmp r1, #0
	beq _08005744
	cmp r3, #0
	beq _08005744
	adds r0, r2, #0
	adds r1, r3, #0
	bl FUN_08048c2c
	b _08005746
_08005744:
	movs r0, #0
_08005746:
	bl FUN_080488bc
	b _080057C6
_0800574C:
	ldr r1, _0800577C @ =0x08251B4C
	adds r0, r4, #0
	movs r2, #3
	bl FUN_08048bf4
	cmp r0, #0
	bne _08005848
	movs r3, #0
	mov ip, r3
	ldrb r0, [r4]
	adds r2, r6, #0
	adds r2, #0xa4
	movs r1, #0x3b
	adds r1, r1, r6
	mov r8, r1
	adds r7, r6, #0
	adds r7, #0x3a
	cmp r0, #0x3e
	beq _080057A6
	cmp r0, #0
	bne _08005780
	adds r5, r4, #1
	b _080057A6
	.align 2, 0
_0800577C: .4byte 0x08251B4C
_08005780:
	ldrb r1, [r5]
	cmp r1, #0x3d
	bne _0800578C
	movs r4, #1
	mov ip, r4
	b _08005798
_0800578C:
	mov r0, ip
	cmp r0, #0
	beq _08005798
	adds r0, r2, r3
	strb r1, [r0]
	adds r3, #1
_08005798:
	adds r5, #1
	ldrb r0, [r5]
	cmp r0, #0x3e
	beq _080057A6
	cmp r0, #0
	bne _08005780
	adds r5, #1
_080057A6:
	adds r1, r2, r3
	movs r0, #0
	strb r0, [r1]
	mov r1, ip
	cmp r1, #0
	beq _080057C0
	cmp r3, #0
	beq _080057C0
	adds r0, r2, #0
	adds r1, r3, #0
	bl FUN_08048c2c
	b _080057C2
_080057C0:
	movs r0, #0
_080057C2:
	bl FUN_0804889c
_080057C6:
	adds r1, r0, #0
	ldrb r0, [r7]
	adds r0, r0, r1
	strb r0, [r7]
	mov r2, r8
	ldrb r0, [r2]
	adds r0, r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	movs r1, #0x3e
	bl FUN_08048cc8
	adds r5, r0, #0
	b _08005854
_080057E2:
	ldr r1, _08005814 @ =0x08251B50
	adds r0, r4, #0
	movs r2, #6
	bl FUN_08048bf4
	cmp r0, #0
	bne _08005848
	adds r0, r4, #0
	movs r1, #0x3e
	bl FUN_08048cc8
	adds r5, r0, #0
	adds r0, r6, #0
	adds r0, #0x3f
	ldrb r1, [r0]
	cmp r1, #0
	beq _08005818
	ldrb r0, [r6, #0x1b]
	lsls r0, r0, #2
	adds r0, r6, r0
	adds r0, #0x66
	strb r1, [r0]
	adds r7, r6, #0
	adds r7, #0x3a
	b _0800582A
	.align 2, 0
_08005814: .4byte 0x08251B50
_08005818:
	ldrb r0, [r6, #0x1b]
	lsls r0, r0, #2
	adds r0, r6, r0
	adds r2, r6, #0
	adds r2, #0x3a
	ldrb r1, [r2]
	adds r0, #0x66
	strb r1, [r0]
	adds r7, r2, #0
_0800582A:
	ldrb r0, [r6, #0x1b]
	adds r0, #1
	movs r1, #0
	strb r0, [r6, #0x1b]
	strb r1, [r7]
	adds r0, r6, #0
	adds r0, #0x34
	adds r1, r6, #0
	adds r1, #0x2c
	ldrb r0, [r0]
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08005854
_08005848:
	adds r0, r4, #0
	movs r1, #0x3e
	bl FUN_08048cc8
	adds r4, r0, #0
	b _08005858
_08005854:
	adds r4, r5, #1
	adds r0, r4, #0
_08005858:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08005868
FUN_08005868: @ 0x08005868
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r0, r1, #0
	bl VM_ParseStringRef
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	bl Textbox_LookupString
	adds r2, r0, #0
	movs r0, #0
	strb r0, [r4, #0x1b]
	adds r1, r4, #0
	adds r1, #0x3a
	strb r0, [r1]
	movs r3, #0
	adds r7, r4, #0
	adds r7, #0x1c
	movs r0, #0x24
	adds r0, r0, r4
	mov r8, r0
	adds r0, r7, #0
	movs r1, #7
_0800589A:
	strb r3, [r0]
	strb r3, [r0, #8]
	strb r3, [r0, #0x10]
	adds r0, #1
	subs r1, #1
	cmp r1, #0
	bge _0800589A
	adds r0, r4, #0
	adds r0, #0x34
	movs r1, #0
	strb r1, [r0]
	ldrb r1, [r2]
	lsls r1, r1, #0x18
	adds r5, r0, #0
	adds r6, r4, #0
	adds r6, #0x39
	cmp r1, #0
	blt _08005984
	lsrs r1, r1, #0x18
	cmp r1, #0
	beq _080059B2
	cmp r1, #0x3c
	bne _080058DC
	b _080059AA
_080058CA:
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_080055d4
	adds r2, r0, #0
	ldrb r0, [r2]
	cmp r0, #0
	beq _080059B2
	b _08005998
_080058DC:
	ldrb r0, [r2]
	cmp r0, #0xa
	bne _08005922
	adds r1, r4, #0
	adds r1, #0x3b
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	ldrb r0, [r5]
	ldrb r1, [r6]
	cmp r0, r1
	bhs _08005980
	mov r3, r8
	adds r1, r3, r0
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	beq _08005904
	subs r0, #1
	b _08005906
_08005904:
	movs r0, #0
_08005906:
	strb r0, [r1]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r6]
	cmp r0, r1
	bhs _08005980
	ldrb r0, [r5]
	adds r0, r7, r0
	ldrb r1, [r4, #0x1b]
	strb r1, [r0]
	b _08005980
_08005922:
	cmp r0, #0x1f
	bne _0800596E
	adds r0, r2, #0
	bl FUN_08048afc
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _0800594C @ =0x0000FFFF
	cmp r1, r0
	bne _08005950
_08005936:
	adds r1, r4, #0
	adds r1, #0x3a
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	adds r1, #1
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	b _080059B2
	.align 2, 0
_0800594C: .4byte 0x0000FFFF
_08005950:
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08005936
	adds r1, r4, #0
	adds r1, #0x3a
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	adds r1, #1
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _080059B2
_0800596E:
	adds r1, r4, #0
	adds r1, #0x3a
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	adds r1, #1
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08005980:
	adds r2, #1
	b _08005998
_08005984:
	adds r1, r4, #0
	adds r1, #0x3a
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	adds r1, #1
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	adds r2, #2
_08005998:
	ldrb r0, [r2]
	lsls r0, r0, #0x18
	cmp r0, #0
	blt _08005984
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _080059B2
	cmp r0, #0x3c
	bne _080058DC
_080059AA:
	adds r2, #1
	ldrb r0, [r2]
	cmp r0, #0
	bne _080058CA
_080059B2:
	ldrb r0, [r5]
	ldrb r6, [r6]
	cmp r0, r6
	bhs _080059CC
	mov r3, r8
	adds r2, r3, r0
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	beq _080059C8
	subs r1, r0, #1
	b _080059CA
_080059C8:
	movs r1, #0
_080059CA:
	strb r1, [r2]
_080059CC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Entity08005b54_Init
Entity08005b54_Init: @ 0x080059D8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	mov r8, r1
	mov sb, r2
	adds r5, r3, #0
	ldr r0, _08005A04 @ =0x03000028
	str r7, [r0]
	ldr r0, _08005A08 @ =0x0000CB05
	ldr r1, _08005A0C @ =0x0000B343
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _08005A10
	movs r0, #1
	rsbs r0, r0, #0
	b _08005B34
	.align 2, 0
_08005A04: .4byte 0x03000028
_08005A08: .4byte 0x0000CB05
_08005A0C: .4byte 0x0000B343
_08005A10:
	adds r0, r7, #0
	adds r0, #0xe4
	str r0, [sp, #0x18]
	adds r1, r0, #0
	adds r0, r2, #0
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	ldr r0, [sp, #0x18]
	adds r1, r2, #0
	bl OpenMainSpriteFile
	mov r6, r8
	str r6, [r7, #0x5c]
	mov r0, sb
	str r0, [r7, #0x60]
	ldr r0, [r5, #4]
	ldr r1, [sp, #0x18]
	mov sb, r1
	cmp r0, #0
	beq _08005A48
	movs r0, #0xff
	strb r0, [r7, #0x18]
	ldr r0, [r5]
	b _08005A4C
_08005A48:
	ldr r0, [r5]
	strb r0, [r7, #0x18]
_08005A4C:
	cmp r0, #0
	bge _08005A52
	movs r0, #0
_08005A52:
	strb r0, [r7, #0x19]
	ldr r1, [r5, #8]
	adds r0, r7, #0
	adds r0, #0x3c
	strb r1, [r0]
	adds r1, r7, #0
	adds r1, #0x3d
	movs r0, #0xa
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x3e
	movs r3, #0
	strb r3, [r0]
	ldr r0, _08005B44 @ =0x030044E0
	ldrh r0, [r0]
	str r0, [r7, #0x40]
	ldr r0, [r5, #0xc]
	subs r1, #7
	strb r0, [r1]
	ldr r0, [r5, #0x10]
	adds r1, #1
	strb r0, [r1]
	ldr r1, [r5, #0x14]
	adds r0, r7, #0
	adds r0, #0x38
	strb r1, [r0]
	ldr r0, [r5, #0x18]
	adds r1, r7, #0
	adds r1, #0x39
	strb r0, [r1]
	movs r0, #2
	strb r0, [r7, #0x1a]
	ldr r2, _08005B48 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #1
	orrs r0, r1
	ldr r1, _08005B4C @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	str r0, [sp, #0x14]
	movs r4, #0x82
	lsls r4, r4, #1
	adds r4, r4, r7
	mov r8, r4
	movs r6, #0
	str r6, [sp]
	str r6, [sp, #4]
	movs r5, #0x3c
	str r5, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	mov r0, r8
	mov r1, sb
	movs r2, #0x8b
	movs r3, #0x11
	bl MainSprite_Add
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r6, r7, r1
	movs r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	str r5, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	adds r0, r6, #0
	mov r1, sb
	movs r2, #0x8f
	movs r3, #0x11
	bl MainSprite_Add
	movs r0, #0
	str r0, [sp]
	mov r0, r8
	mov r1, sb
	movs r2, #6
	movs r3, #1
	bl FUN_082370cc
	movs r1, #0
	str r1, [sp]
	adds r0, r6, #0
	mov r1, sb
	movs r2, #7
	movs r3, #1
	bl FUN_082370cc
	ldr r1, [r7, #0x5c]
	cmp r1, #0
	beq _08005B24
	adds r0, r7, #0
	bl FUN_08005868
	movs r1, #0x18
	ldrsb r1, [r7, r1]
	adds r0, r7, #0
	bl FUN_08005238
	adds r0, r7, #0
	bl FUN_0800559c
_08005B24:
	bl FUN_080488fc
	cmp r0, #0
	bne _08005B32
	ldr r0, _08005B50 @ =0x00000107
	bl PlaySound_082406e0
_08005B32:
	movs r0, #0
_08005B34:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08005B44: .4byte 0x030044E0
_08005B48: .4byte 0xFFFF0000
_08005B4C: .4byte 0x0000FFFF
_08005B50: .4byte 0x00000107

	thumb_func_start Entity08005b54_Create_2
Entity08005b54_Create_2: @ 0x08005B54
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	mov sb, r1
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r0, _08005B70 @ =0x03000028
	ldr r5, [r0]
	cmp r5, #0
	beq _08005B74
	movs r0, #0
	b _08005BBA
	.align 2, 0
_08005B70: .4byte 0x03000028
_08005B74:
	movs r1, #0xe2
	lsls r1, r1, #1
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08005BB8
	ldr r1, _08005BB0 @ =Entity08005b54_Update
	ldr r2, _08005BB4 @ =Entity08005b54_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r0, #0x35
	strb r5, [r0]
	str r6, [r4, #0x58]
	adds r0, r4, #0
	mov r1, r8
	mov r2, sb
	adds r3, r7, #0
	bl Entity08005b54_Init
	cmp r0, #0
	bge _08005BB8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08005BBA
	.align 2, 0
_08005BB0: .4byte Entity08005b54_Update
_08005BB4: .4byte Entity08005b54_Destroy
_08005BB8:
	adds r0, r4, #0
_08005BBA:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity08005b54_Create
Entity08005b54_Create: @ 0x08005BC8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x3c
	ldr r0, _08005BDC @ =0x03000028
	ldr r0, [r0]
	cmp r0, #0
	beq _08005BE0
	movs r0, #0
	b _08005D0E
	.align 2, 0
_08005BDC: .4byte 0x03000028
_08005BE0:
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08005BF2
	bl FUN_0823d340
	adds r6, r0, #0
	b _08005BF4
_08005BF2:
	movs r6, #0
_08005BF4:
	movs r0, #0x69
	movs r1, #0
	bl VM_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0
	mov r8, r0
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08005C12
	bl Script_GetValue
	mov r8, r0
_08005C12:
	movs r0, #0x6c
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [sp, #4]
	movs r0, #0x77
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [sp]
	movs r0, #0x63
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [sp, #8]
	movs r0, #0x61
	bl VM_SeekToKeyword
	adds r5, r0, #0
	cmp r5, #0
	beq _08005C54
	bl Script_GetValue
	str r0, [sp, #0xc]
	bl Script_GetValue
	str r0, [sp, #0x10]
	bl Script_GetValue
	str r0, [sp, #0x14]
	bl Script_GetValue
	b _08005C7A
_08005C54:
	add r4, sp, #0x2c
	adds r0, r4, #0
	bl FUN_08048870
	cmp r0, #0
	bne _08005C70
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0xc]
	ldr r0, [r4, #4]
	str r0, [sp, #0x10]
	ldr r0, [r4, #8]
	str r0, [sp, #0x14]
	ldr r0, [r4, #0xc]
	b _08005C7A
_08005C70:
	str r5, [sp, #0xc]
	str r5, [sp, #0x10]
	movs r0, #0x18
	str r0, [sp, #0x14]
	movs r0, #3
_08005C7A:
	str r0, [sp, #0x18]
	movs r0, #0x41
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08005CA4
	add r5, sp, #0x1c
	adds r4, r5, #0
_08005C8A:
	bl VM_GetPC
	cmp r0, #0
	beq _08005C96
	bl Script_GetValue
_08005C96:
	str r0, [r4]
	adds r4, #4
	adds r0, r5, #0
	adds r0, #0xc
	cmp r4, r0
	ble _08005C8A
	b _08005CB4
_08005CA4:
	add r5, sp, #0x1c
	adds r1, r5, #0
	movs r2, #0
	add r0, sp, #0x28
_08005CAC:
	str r2, [r0]
	subs r0, #4
	cmp r0, r1
	bge _08005CAC
_08005CB4:
	movs r1, #0xe2
	lsls r1, r1, #1
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08005D0C
	ldr r1, _08005D04 @ =Entity08005b54_Update
	ldr r2, _08005D08 @ =Entity08005b54_Destroy
	bl SetEntityRoutine
	adds r1, r4, #0
	adds r1, #0x35
	movs r0, #1
	strb r0, [r1]
	mov r0, r8
	str r0, [r4, #0x54]
	adds r3, r5, #0
	adds r2, r4, #0
	adds r2, #0x44
	movs r1, #3
_08005CE0:
	ldm r3!, {r0}
	stm r2!, {r0}
	subs r1, #1
	cmp r1, #0
	bge _08005CE0
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, sp
	bl Entity08005b54_Init
	cmp r0, #0
	bge _08005D0C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08005D0E
	.align 2, 0
_08005D04: .4byte Entity08005b54_Update
_08005D08: .4byte Entity08005b54_Destroy
_08005D0C:
	adds r0, r4, #0
_08005D0E:
	add sp, #0x3c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08005d1c
FUN_08005d1c: @ 0x08005D1C
	push {r4, lr}
	ldr r0, _08005D74 @ =0x03000028
	ldr r4, [r0]
	cmp r4, #0
	beq _08005D6C
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08005D6C
	bl FUN_0823d340
	str r0, [r4, #0x5c]
	movs r0, #0x69
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [r4, #0x60]
	movs r0, #0x77
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08005D50
	bl Script_GetValue
	strb r0, [r4, #0x18]
_08005D50:
	ldr r1, [r4, #0x5c]
	cmp r1, #0
	beq _08005D6C
	adds r0, r4, #0
	bl FUN_08005868
	movs r1, #0x18
	ldrsb r1, [r4, r1]
	adds r0, r4, #0
	bl FUN_08005238
	adds r0, r4, #0
	bl FUN_0800559c
_08005D6C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08005D74: .4byte 0x03000028
