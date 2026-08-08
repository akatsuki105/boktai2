	push {r4, r5, r6, r7, lr}
	mov ip, r0
	adds r5, r1, #0
	adds r6, r2, #0
	ldr r2, [sp, #0x14]
	movs r0, #1
	lsls r0, r2
	subs r4, r0, r3
	movs r1, #0
	ldrsh r0, [r5, r1]
	adds r1, r0, #0
	muls r1, r4, r1
	movs r7, #0
	ldrsh r0, [r6, r7]
	muls r0, r3, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _08237998
	asrs r0, r2
	b _0823799E
_08237998:
	rsbs r0, r0, #0
	asrs r0, r2
	rsbs r0, r0, #0
_0823799E:
	mov r1, ip
	strh r0, [r1]
	movs r7, #2
	ldrsh r0, [r5, r7]
	adds r1, r0, #0
	muls r1, r4, r1
	movs r7, #2
	ldrsh r0, [r6, r7]
	muls r0, r3, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _082379BA
	asrs r0, r2
	b _082379C0
_082379BA:
	rsbs r0, r0, #0
	asrs r0, r2
	rsbs r0, r0, #0
_082379C0:
	mov r1, ip
	strh r0, [r1, #2]
	movs r7, #4
	ldrsh r0, [r5, r7]
	adds r1, r0, #0
	muls r1, r4, r1
	movs r4, #4
	ldrsh r0, [r6, r4]
	muls r0, r3, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _082379DC
	asrs r0, r2
	b _082379E2
_082379DC:
	rsbs r0, r0, #0
	asrs r0, r2
	rsbs r0, r0, #0
_082379E2:
	mov r7, ip
	strh r0, [r7, #4]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
