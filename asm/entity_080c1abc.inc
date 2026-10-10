	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080c13e8
FUN_080c13e8: @ 0x080C13E8
	movs r3, #0x9e
	lsls r3, r3, #1
	adds r2, r0, r3
	str r1, [r2]
	adds r0, #0x70
	movs r1, #0
	strh r1, [r0]
	bx lr

	thumb_func_start FUN_080c13f8
FUN_080c13f8: @ 0x080C13F8
	push {r4, r5, r6, lr}
	mov ip, r0
	ldr r3, [r0, #0x18]
	ldr r0, [r3, #0x2c]
	ldr r1, [r3, #0x30]
	mov r2, ip
	str r0, [r2, #0x38]
	str r1, [r2, #0x3c]
	ldrh r0, [r2, #0x3a]
	adds r0, #0xc8
	strh r0, [r2, #0x3a]
	movs r6, #0xba
	lsls r6, r6, #2
	adds r0, r3, r6
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r5, r0, #5
	ldr r1, _080C1454 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r2, #0xff
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r6, #0
	ldrsh r4, [r0, r6]
	adds r0, r5, #0
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r6, #0
	ldrsh r2, [r0, r6]
	ldr r0, _080C1458 @ =0x000002E7
	adds r3, r3, r0
	ldrb r0, [r3]
	adds r6, r1, #0
	cmp r0, #0
	beq _080C14B2
	movs r0, #0xaa
	muls r0, r4, r0
	cmp r0, #0
	blt _080C145C
	asrs r0, r0, #0xc
	b _080C1462
	.align 2, 0
_080C1454: .4byte 0x085B0A08
_080C1458: .4byte 0x000002E7
_080C145C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C1462:
	adds r1, r0, #0
	lsls r0, r2, #3
	cmp r0, #0
	blt _080C146E
	asrs r0, r0, #0xc
	b _080C1474
_080C146E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C1474:
	adds r0, r1, r0
	mov r1, ip
	ldrh r1, [r1, #0x38]
	adds r0, r0, r1
	mov r3, ip
	strh r0, [r3, #0x38]
	movs r0, #0xaa
	muls r0, r2, r0
	cmp r0, #0
	blt _080C148C
	asrs r0, r0, #0xc
	b _080C1492
_080C148C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C1492:
	adds r1, r0, #0
	lsls r0, r4, #3
	cmp r0, #0
	blt _080C149E
	asrs r0, r0, #0xc
	b _080C14A4
_080C149E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C14A4:
	subs r0, r1, r0
	mov r1, ip
	ldrh r1, [r1, #0x3c]
	adds r0, r0, r1
	mov r2, ip
	strh r0, [r2, #0x3c]
	b _080C1512
_080C14B2:
	movs r0, #0xaa
	muls r0, r4, r0
	cmp r0, #0
	blt _080C14BE
	asrs r0, r0, #0xc
	b _080C14C4
_080C14BE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C14C4:
	adds r1, r0, #0
	lsls r0, r2, #3
	cmp r0, #0
	blt _080C14D0
	asrs r0, r0, #0xc
	b _080C14D6
_080C14D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C14D6:
	subs r0, r1, r0
	mov r3, ip
	ldrh r3, [r3, #0x38]
	adds r0, r0, r3
	mov r1, ip
	strh r0, [r1, #0x38]
	movs r0, #0xaa
	muls r0, r2, r0
	cmp r0, #0
	blt _080C14EE
	asrs r0, r0, #0xc
	b _080C14F4
_080C14EE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C14F4:
	adds r1, r0, #0
	lsls r0, r4, #3
	cmp r0, #0
	blt _080C1500
	asrs r0, r0, #0xc
	b _080C1506
_080C1500:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C1506:
	adds r0, r1, r0
	mov r2, ip
	ldrh r2, [r2, #0x3c]
	adds r0, r0, r2
	mov r3, ip
	strh r0, [r3, #0x3c]
_080C1512:
	movs r2, #0xff
	lsrs r0, r5, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	mov r0, ip
	adds r0, #0x6e
	strb r1, [r0]
	adds r0, r5, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r2, [r0, r1]
	mov r1, ip
	adds r1, #0x6c
	ldrh r0, [r1]
	muls r0, r2, r0
	adds r3, r1, #0
	cmp r0, #0
	blt _080C1542
	asrs r2, r0, #0xc
	b _080C1548
_080C1542:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080C1548:
	mov r0, ip
	adds r0, #0x64
	strh r2, [r0]
	lsls r0, r5, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrh r0, [r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _080C1562
	asrs r1, r0, #0xc
	b _080C1568
_080C1562:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C1568:
	mov r0, ip
	adds r0, #0x68
	strh r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080c1574
FUN_080c1574: @ 0x080C1574
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov ip, r0
	adds r0, #0x6e
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	mov sl, r0
	movs r0, #0xff
	mov r8, r0
	ldr r1, _080C15D0 @ =0x085B0A08
	mov sb, r1
	movs r7, #0
	str r7, [sp]
	mov r3, ip
	adds r3, #0x94
	mov r5, ip
	adds r5, #0xa8
	movs r6, #3
_080C15A6:
	ldrb r0, [r3, #0x10]
	cmp r0, #0
	beq _080C1644
	ldrh r0, [r3, #0x14]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0x14]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls _080C15D4
	strb r1, [r3, #0x10]
	mov r0, ip
	adds r0, #0x7c
	ldr r1, [sp]
	adds r0, r0, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _080C1644
	.align 2, 0
_080C15D0: .4byte 0x085B0A08
_080C15D4:
	ldrh r2, [r3, #0x12]
	ldrh r1, [r5]
	movs r0, #0x10
	subs r0, r0, r1
	muls r0, r2, r0
	asrs r4, r0, #3
	movs r0, #0x11
	ldrsb r0, [r3, r0]
	movs r7, #0x80
	lsls r7, r7, #1
	adds r0, r0, r7
	mov r1, sl
	adds r2, r1, r0
	mov r7, r8
	ands r2, r7
	mov r7, ip
	ldr r0, [r7, #0x38]
	ldr r1, [r7, #0x3c]
	str r0, [r3]
	str r1, [r3, #4]
	adds r0, r2, #0
	adds r0, #0x40
	mov r1, r8
	ands r0, r1
	lsls r0, r0, #1
	add r0, sb
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r4, r0
	cmp r0, #0
	blt _080C1616
	asrs r1, r0, #0xc
	b _080C161C
_080C1616:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C161C:
	ldrh r0, [r3]
	adds r0, r0, r1
	strh r0, [r3]
	mov r0, r8
	ands r2, r0
	lsls r0, r2, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _080C1638
	asrs r1, r0, #0xc
	b _080C163E
_080C1638:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C163E:
	ldrh r0, [r3, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
_080C1644:
	ldr r7, [sp]
	adds r7, #0x30
	str r7, [sp]
	adds r3, #0x30
	adds r5, #0x30
	subs r6, #1
	cmp r6, #0
	bge _080C15A6
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080c1664
FUN_080c1664: @ 0x080C1664
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r0, #0x77
	adds r0, r0, r7
	mov r8, r0
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0xa4
	movs r3, #0
	movs r1, #1
	strb r1, [r0]
	mov r0, r8
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r1, r7, #0
	adds r1, #0x7c
	adds r1, r1, r0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	mov r0, r8
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0xa8
	strh r3, [r0]
	ldr r6, _080C1760 @ =0x0203B400
	ldr r5, _080C1764 @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r4, _080C1768 @ =0x000003FF
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r2, [r0]
	mov r0, r8
	ldrb r3, [r0]
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #4
	adds r0, r7, r0
	asrs r2, r2, #3
	movs r3, #0x7f
	ands r2, r3
	adds r2, #0x40
	adds r0, #0xa6
	strh r2, [r0]
	adds r1, #1
	ands r1, r4
	str r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	movs r1, #0x60
	bl Mod
	mov r1, r8
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #4
	adds r1, r7, r1
	subs r0, #0x30
	adds r1, #0xa5
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x6e
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	mov r1, r8
	ldrb r0, [r1]
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #4
	adds r2, r7, r2
	adds r0, r2, #0
	adds r0, #0xa5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r4, r4, r0
	movs r3, #0xff
	ands r4, r3
	adds r2, #0x94
	ldr r0, [r7, #0x38]
	ldr r1, [r7, #0x3c]
	str r0, [r2]
	str r1, [r2, #4]
	mov r0, r8
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0xa6
	ldrh r2, [r0]
	ldr r1, _080C176C @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080C1770
	asrs r2, r0, #0xc
	b _080C1776
	.align 2, 0
_080C1760: .4byte 0x0203B400
_080C1764: .4byte 0x030046B8
_080C1768: .4byte 0x000003FF
_080C176C: .4byte 0x085B0A08
_080C1770:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080C1776:
	adds r3, r7, #0
	adds r3, #0x77
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0x94
	ldrh r1, [r0]
	adds r1, r1, r2
	strh r1, [r0]
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0xa6
	ldrh r2, [r0]
	ldr r1, _080C17B0 @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080C17B4
	asrs r2, r0, #0xc
	b _080C17BA
	.align 2, 0
_080C17B0: .4byte 0x085B0A08
_080C17B4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080C17BA:
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0x98
	ldrh r1, [r0]
	adds r1, r1, r2
	strh r1, [r0]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _080C17DE
	movs r0, #0
	strb r0, [r3]
_080C17DE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080c17e8
FUN_080c17e8: @ 0x080C17E8
	push {r4, r5, lr}
	movs r5, #0
	movs r4, #1
	adds r2, r0, #0
	adds r2, #0xa4
	adds r1, r0, #0
	movs r3, #3
_080C17F6:
	strb r5, [r2]
	ldr r0, [r1, #0x7c]
	orrs r0, r4
	str r0, [r1, #0x7c]
	adds r2, #0x30
	adds r1, #0x30
	subs r3, #1
	cmp r3, #0
	bge _080C17F6
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c1810
FUN_080c1810: @ 0x080C1810
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x18]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r5, [r0]
	cmp r5, #3
	beq _080C182A
	adds r0, r4, #0
	bl KillEntity
	b _080C18D4
_080C182A:
	adds r0, r4, #0
	bl FUN_080c13f8
	ldr r0, [r4, #0x18]
	ldr r1, _080C1860 @ =0x0000037D
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _080C1868
	adds r0, r4, #0
	bl FUN_080c17e8
	ldr r0, [r4, #0x1c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r0, #0x6f
	ldrb r0, [r0]
	strh r0, [r4, #0x2c]
	ldr r1, _080C1864 @ =FUN_080c18dc
	adds r0, r4, #0
	bl FUN_080c13e8
	b _080C18D4
	.align 2, 0
_080C1860: .4byte 0x0000037D
_080C1864: .4byte FUN_080c18dc
_080C1868:
	adds r0, r4, #0
	bl FUN_080c1574
	ldr r0, [r4, #0x18]
	ldr r1, _080C189C @ =0x0000037D
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #2
	bne _080C18A0
	adds r1, r4, #0
	adds r1, #0x70
	ldrh r0, [r1]
	ands r5, r0
	adds r6, r1, #0
	cmp r5, #3
	bne _080C188E
	adds r0, r4, #0
	bl FUN_080c1664
_080C188E:
	adds r1, r4, #0
	adds r1, #0x6f
	movs r0, #0
	strb r0, [r1]
	adds r2, r1, #0
	b _080C18B8
	.align 2, 0
_080C189C: .4byte 0x0000037D
_080C18A0:
	ldr r0, [r4, #0x1c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x1c]
	adds r1, r4, #0
	adds r1, #0x6f
	movs r0, #1
	strb r0, [r1]
	adds r2, r1, #0
	adds r6, r4, #0
	adds r6, #0x70
_080C18B8:
	ldrh r0, [r6]
	lsrs r0, r0, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080C18CA
	ldrb r0, [r2]
	adds r0, #1
	b _080C18CC
_080C18CA:
	ldrb r0, [r2]
_080C18CC:
	strh r0, [r4, #0x2c]
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
_080C18D4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c18dc
FUN_080c18dc: @ 0x080C18DC
	push {lr}
	adds r2, r0, #0
	adds r0, #0x64
	ldrh r0, [r0]
	ldrh r1, [r2, #0x38]
	adds r0, r0, r1
	strh r0, [r2, #0x38]
	adds r0, r2, #0
	adds r0, #0x68
	ldrh r0, [r0]
	ldrh r1, [r2, #0x3c]
	adds r0, r0, r1
	strh r0, [r2, #0x3c]
	adds r1, r2, #0
	adds r1, #0x70
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	adds r1, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _080C1914
	ldr r1, _080C1918 @ =FUN_080c191c
	adds r0, r2, #0
	bl FUN_080c13e8
_080C1914:
	pop {r0}
	bx r0
	.align 2, 0
_080C1918: .4byte FUN_080c191c

	thumb_func_start FUN_080c191c
FUN_080c191c: @ 0x080C191C
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x70
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _080C1938
	movs r0, #4
	strh r0, [r2, #0x2c]
	b _080C19A4
_080C1938:
	cmp r0, #4
	bne _080C199A
	adds r0, r2, #0
	adds r0, #0x6e
	adds r2, #0x1c
	ldrb r1, [r0]
	movs r3, #1
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	beq _080C1952
	movs r0, #7
	b _080C1960
_080C1952:
	asrs r0, r1, #1
	ands r0, r3
	cmp r0, #0
	beq _080C195E
	movs r0, #8
	b _080C1960
_080C195E:
	movs r0, #6
_080C1960:
	strh r0, [r2, #0x10]
	cmp r1, #2
	bgt _080C196E
	ldr r0, [r2]
	movs r1, #0xd
	rsbs r1, r1, #0
	b _080C1994
_080C196E:
	cmp r1, #4
	bgt _080C197E
	ldr r0, [r2]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #8
	b _080C1986
_080C197E:
	cmp r1, #5
	bgt _080C198C
	ldr r0, [r2]
	movs r1, #0xc
_080C1986:
	orrs r0, r1
	str r0, [r2]
	b _080C19A4
_080C198C:
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	subs r1, #0xd
_080C1994:
	ands r0, r1
	str r0, [r2]
	b _080C19A4
_080C199A:
	cmp r0, #6
	bls _080C19A4
	adds r0, r2, #0
	bl KillEntity
_080C19A4:
	pop {r0}
	bx r0

	thumb_func_start Entity080c1abc_Update
Entity080c1abc_Update: @ 0x080C19A8
	push {lr}
	movs r2, #0x9e
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r1, [r1]
	bl _call_via_r1
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start Entity080c1abc_Destroy
Entity080c1abc_Destroy: @ 0x080C19BC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x1c
	bl AuxSprite_Remove
	adds r4, #0x7c
	movs r5, #3
_080C19CA:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x30
	subs r5, #1
	cmp r5, #0
	bge _080C19CA
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080c19e0
FUN_080c19e0: @ 0x080C19E0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x48
	ldr r1, _080C1A10 @ =0x0000210E
	adds r0, r5, #0
	bl Video_GetAuxSprite
	adds r4, #0x1c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #1
	bl AuxSprite_Add
	movs r0, #0
	strh r0, [r4, #0x10]
	adds r0, r5, #0
	movs r1, #0x2e
	bl Video_SetAuxSpritePltt
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C1A10: .4byte 0x0000210E

	thumb_func_start FUN_080c1a14
FUN_080c1a14: @ 0x080C1A14
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0x77
	movs r0, #0
	strb r0, [r1]
	ldr r0, _080C1A7C @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r5, #0x78]
	movs r0, #4
	rsbs r0, r0, #0
	mov r8, r0
	adds r6, r5, #0
	adds r6, #0xa4
	adds r4, r5, #0
	adds r4, #0x7c
	movs r7, #3
_080C1A3C:
	ldr r1, [r5, #0x78]
	adds r0, r4, #0
	movs r2, #1
	bl Particle_Add
	adds r0, r4, #0
	mov r1, r8
	mov r2, r8
	bl Particle_SetOffset
	ldr r1, [r5, #0x78]
	adds r0, r4, #0
	movs r2, #0x11
	bl Particle_SetFrame
	adds r0, r4, #0
	movs r1, #1
	bl Particle_SetPltt
	movs r0, #0
	strb r0, [r6]
	adds r6, #0x30
	adds r4, #0x30
	subs r7, #1
	cmp r7, #0
	bge _080C1A3C
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C1A7C: .4byte 0x00001C1E

	thumb_func_start Entity080c1abc_Init
Entity080c1abc_Init: @ 0x080C1A80
	push {r4, lr}
	adds r4, r0, #0
	str r1, [r4, #0x18]
	adds r0, #0x6c
	movs r1, #0
	strh r2, [r0]
	adds r0, #6
	strh r3, [r0]
	subs r0, #3
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_080c19e0
	adds r0, r4, #0
	bl FUN_080c13f8
	adds r0, r4, #0
	bl FUN_080c1a14
	ldr r1, _080C1AB8 @ =FUN_080c1810
	adds r0, r4, #0
	bl FUN_080c13e8
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080C1AB8: .4byte FUN_080c1810

	thumb_func_start Entity080c1abc_Create
Entity080c1abc_Create: @ 0x080C1ABC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	movs r1, #0xa0
	lsls r1, r1, #1
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080C1B00
	ldr r1, _080C1AF8 @ =Entity080c1abc_Update
	ldr r2, _080C1AFC @ =Entity080c1abc_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	adds r3, r7, #0
	bl Entity080c1abc_Init
	cmp r0, #0
	bge _080C1B00
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080C1B02
	.align 2, 0
_080C1AF8: .4byte Entity080c1abc_Update
_080C1AFC: .4byte Entity080c1abc_Destroy
_080C1B00:
	adds r0, r4, #0
_080C1B02:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
