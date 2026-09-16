	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08022668
FUN_08022668: @ 0x08022668
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r3, _080226A4 @ =0xFFFF0000
	ldrh r1, [r2, #0xa]
	lsls r1, r1, #0x10
	ldrh r0, [r2, #8]
	orrs r0, r1
	str r0, [sp, #4]
	ldrh r1, [r2, #0xc]
	ldr r0, [sp, #8]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #8]
	movs r0, #0xe
	ldrsh r1, [r2, r0]
	movs r5, #0x10
	ldrsh r4, [r2, r5]
	movs r0, #0x12
	ldrsh r3, [r2, r0]
	movs r5, #0x14
	ldrsh r0, [r2, r5]
	str r0, [sp]
	add r0, sp, #4
	adds r2, r4, #0
	bl FUN_08019814
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080226A4: .4byte 0xFFFF0000

	thumb_func_start FUN_080226a8
FUN_080226a8: @ 0x080226A8
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r2, #0
	ldrh r0, [r5, #8]
	bl FUN_0823b2d0
	adds r4, r0, #0
	cmp r4, #0
	beq _080226F4
	ldrh r0, [r4, #8]
	ldr r3, _080226FC @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #4]
	ldrh r2, [r4, #0xa]
	lsls r2, r2, #0x10
	ldr r0, _08022700 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #4]
	ldrh r1, [r4, #0xc]
	ldr r0, [sp, #8]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #8]
	movs r0, #0xa
	ldrsh r1, [r5, r0]
	movs r4, #0xc
	ldrsh r2, [r5, r4]
	movs r0, #0xe
	ldrsh r3, [r5, r0]
	movs r4, #0x10
	ldrsh r0, [r5, r4]
	str r0, [sp]
	add r0, sp, #4
	bl FUN_08019814
_080226F4:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080226FC: .4byte 0xFFFF0000
_08022700: .4byte 0x0000FFFF

	thumb_func_start FUN_08022704
FUN_08022704: @ 0x08022704
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r2, #0
	adds r4, #8
	movs r5, #0
	movs r1, #0xa
	ldrsh r0, [r4, r1]
	cmp r0, #0
	beq _08022718
	ldr r5, _0802276C @ =0x00000FFF
_08022718:
	movs r7, #0xc
	ldrsh r0, [r4, r7]
	cmp r0, #0
	beq _08022728
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r1, #0
	orrs r5, r0
_08022728:
	movs r7, #0xe
	ldrsh r0, [r4, r7]
	cmp r0, #0
	beq _08022738
	movs r1, #0xe0
	lsls r1, r1, #8
	adds r0, r1, #0
	orrs r5, r0
_08022738:
	movs r7, #8
	ldrsh r0, [r2, r7]
	movs r6, #3
	cmp r0, #0
	bne _08022744
	movs r6, #2
_08022744:
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r7, #4
	ldrsh r2, [r4, r7]
	movs r0, #6
	ldrsh r3, [r4, r0]
	movs r7, #8
	ldrsh r0, [r4, r7]
	str r0, [sp]
	str r5, [sp, #4]
	movs r5, #0x10
	ldrsh r0, [r4, r5]
	str r0, [sp, #8]
	adds r0, r6, #0
	bl FUN_0823ce68
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802276C: .4byte 0x00000FFF

	thumb_func_start FUN_08022770
FUN_08022770: @ 0x08022770
	push {r4, r5, lr}
	sub sp, #0x14
	adds r2, #8
	movs r4, #0
	movs r1, #0xa
	ldrsh r0, [r2, r1]
	cmp r0, #0
	beq _08022782
	ldr r4, _080227F0 @ =0x00000FFF
_08022782:
	movs r3, #0xc
	ldrsh r0, [r2, r3]
	cmp r0, #0
	beq _08022792
	movs r5, #0x80
	lsls r5, r5, #5
	adds r0, r5, #0
	orrs r4, r0
_08022792:
	movs r1, #0xe
	ldrsh r0, [r2, r1]
	cmp r0, #0
	beq _080227A2
	movs r3, #0xe0
	lsls r3, r3, #8
	adds r0, r3, #0
	orrs r4, r0
_080227A2:
	movs r5, #2
	ldrsh r0, [r2, r5]
	str r0, [sp]
	movs r1, #4
	ldrsh r0, [r2, r1]
	str r0, [sp, #4]
	movs r3, #6
	ldrsh r1, [r2, r3]
	str r1, [sp, #8]
	movs r5, #8
	ldrsh r3, [r2, r5]
	str r3, [sp, #0xc]
	str r4, [sp, #0x10]
	cmp r0, #0
	bne _080227D0
	cmp r1, #0
	bne _080227D0
	cmp r3, #0
	bne _080227D0
	movs r0, #4
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r0, [sp, #0xc]
_080227D0:
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r1, #3
	cmp r0, #0
	bne _080227DC
	movs r1, #2
_080227DC:
	adds r0, r1, #0
	movs r1, #5
	mov r2, sp
	bl FUN_0800205c
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080227F0: .4byte 0x00000FFF

	thumb_func_start FUN_080227f4
FUN_080227f4: @ 0x080227F4
	push {r4, r5, lr}
	sub sp, #0x14
	adds r2, #8
	movs r1, #2
	ldrsh r0, [r2, r1]
	str r0, [sp]
	movs r5, #4
	ldrsh r1, [r2, r5]
	str r1, [sp, #4]
	movs r0, #6
	ldrsh r3, [r2, r0]
	str r3, [sp, #8]
	movs r5, #8
	ldrsh r4, [r2, r5]
	str r4, [sp, #0xc]
	movs r5, #0x10
	ldrsh r0, [r2, r5]
	str r0, [sp, #0x10]
	cmp r1, #0
	bne _0802282C
	cmp r3, #0
	bne _0802282C
	cmp r4, #0
	bne _0802282C
	movs r0, #4
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r0, [sp, #0xc]
_0802282C:
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r1, #2
	cmp r0, #0
	bne _08022838
	movs r1, #1
_08022838:
	adds r0, r1, #0
	movs r1, #5
	mov r2, sp
	bl FUN_08002800
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0802284c
FUN_0802284c: @ 0x0802284C
	movs r3, #8
	ldrsh r1, [r2, r3]
	str r1, [r0, #0x50]
	movs r3, #0xa
	ldrsh r1, [r2, r3]
	str r1, [r0, #0x54]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0802285c
FUN_0802285c: @ 0x0802285C
	movs r1, #0
	str r1, [r0, #0x50]
	str r1, [r0, #0x54]
	bx lr

