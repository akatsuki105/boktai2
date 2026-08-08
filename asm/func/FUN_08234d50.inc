	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r1, sp
	bl FUN_0823492c
	adds r2, r0, #0
	cmp r2, #0
	bne _08234D6C
	b _08234DAC
_08234D68:
	movs r0, #1
	b _08234DAE
_08234D6C:
	movs r4, #0
	mov r0, sp
	ldrh r0, [r0]
	cmp r4, r0
	bhs _08234DAC
	movs r1, #0
	ldrsh r3, [r5, r1]
	adds r6, r0, #0
_08234D7C:
	movs r7, #0
	ldrsh r0, [r2, r7]
	cmp r3, r0
	blt _08234DA0
	movs r1, #4
	ldrsh r0, [r2, r1]
	cmp r3, r0
	bge _08234DA0
	movs r7, #4
	ldrsh r1, [r5, r7]
	movs r7, #2
	ldrsh r0, [r2, r7]
	cmp r1, r0
	blt _08234DA0
	movs r7, #6
	ldrsh r0, [r2, r7]
	cmp r1, r0
	blt _08234D68
_08234DA0:
	adds r2, #0xc
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r6
	blo _08234D7C
_08234DAC:
	movs r0, #0
_08234DAE:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
