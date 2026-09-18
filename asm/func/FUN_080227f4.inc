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
