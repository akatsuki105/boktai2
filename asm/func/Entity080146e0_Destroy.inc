	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r2, #0
_08014612:
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #4
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, #0x24
	mov r3, r8
	adds r1, r3, r0
	ldrb r0, [r1]
	adds r7, r2, #1
	cmp r0, #0
	beq _08014648
	adds r5, r1, #0
	adds r5, #0x14
	adds r4, r1, #4
	movs r6, #7
_08014632:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801463E
	adds r0, r5, #0
	bl Particle_Remove
_0801463E:
	adds r5, #0x38
	adds r4, #0x38
	subs r6, #1
	cmp r6, #0
	bge _08014632
_08014648:
	adds r2, r7, #0
	cmp r2, #5
	ble _08014612
	movs r1, #0
	ldr r0, _08014660 @ =0x03000058
	str r1, [r0]
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08014660: .4byte 0x03000058
