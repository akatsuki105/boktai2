	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r1
	adds r6, r2, #0
	adds r5, r3, #0
	mov ip, r0
	movs r3, #0
	cmp r3, r8
	bge _08028780
_08028734:
	lsls r0, r3, #2
	movs r1, #0x86
	lsls r1, r1, #1
	add r1, ip
	adds r1, r1, r0
	ldr r0, [r1]
	adds r1, r0, #0
	cmp r1, #0
	beq _0802877A
	movs r0, #0
	ldrsh r2, [r1, r0]
	movs r4, #0
	ldrsh r0, [r6, r4]
	movs r4, #0
	cmp r2, r0
	blt _08028772
	movs r7, #0
	ldrsh r0, [r5, r7]
	cmp r2, r0
	bgt _08028772
	movs r0, #4
	ldrsh r1, [r1, r0]
	movs r2, #4
	ldrsh r0, [r6, r2]
	cmp r1, r0
	blt _08028772
	movs r7, #4
	ldrsh r0, [r5, r7]
	cmp r1, r0
	bgt _08028772
	movs r4, #1
_08028772:
	cmp r4, #0
	beq _0802877A
	adds r0, r3, #0
	b _08028784
_0802877A:
	adds r3, #1
	cmp r3, r8
	blt _08028734
_08028780:
	movs r0, #1
	rsbs r0, r0, #0
_08028784:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
