	push {r4, r5, r6, lr}
	sub sp, #0x48
	adds r5, r0, #0
	mov r4, sp
	subs r4, #8
_0823260A:
	ldrb r1, [r5]
	str r1, [sp, #0x40]
	movs r0, #0xe0
	ands r0, r1
	cmp r0, #0xa0
	bne _08232662
	movs r0, #0xe1
	rsbs r0, r0, #0
	ands r0, r1
	subs r4, #8
	cmp r0, #0
	beq _08232694
	cmp r0, #0x16
	bne _08232650
	ldr r3, [r4, #4]
	ldrb r2, [r3]
	movs r0, #0xf0
	ands r0, r2
	adds r6, r4, #0
	cmp r0, #0x90
	bne _08232642
	movs r0, #0xf
	ands r2, r0
	ldr r1, [r4, #8]
	adds r0, r2, #0
	bl FUN_082314c0
	b _0823264A
_08232642:
	ldr r1, [r4, #8]
	adds r0, r3, #0
	bl FUN_08231f88
_0823264A:
	ldr r0, [r4, #8]
	str r0, [r6]
	b _0823265E
_08232650:
	ldr r1, [r4]
	ldr r2, [r4, #8]
	bl Arithmetic
	str r0, [r4]
	movs r0, #0
	str r0, [r4, #4]
_0823265E:
	adds r5, #1
	b _0823260A
_08232662:
	str r5, [r4, #0xc]
	adds r0, r5, #0
	add r1, sp, #0x40
	add r2, sp, #0x44
	bl VM_Step
	adds r5, r0, #0
	ldr r0, [sp, #0x40]
	cmp r0, #0x80
	bne _0823268C
	ldr r0, [sp, #0x44]
	movs r1, #0
	movs r2, #0
	bl FUN_08231ad0
	ldr r0, _08232688 @ =0x030045A0
	ldr r0, [r0, #4]
	b _0823268E
	.align 2, 0
_08232688: .4byte 0x030045A0
_0823268C:
	ldr r0, [sp, #0x44]
_0823268E:
	str r0, [r4, #8]
	adds r4, #8
	b _0823260A
_08232694:
	ldr r0, [r4, #8]
	add sp, #0x48
	pop {r4, r5, r6}
	pop {r1}
	bx r1
