	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r1, [r4, #6]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08245EC8
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r0, [r4, #0x14]
	ldr r1, [r4, #0x18]
	str r0, [r2]
	str r1, [r2, #4]
_08245EC8:
	ldrb r0, [r4, #8]
	subs r2, r0, #1
	cmp r2, #0
	bge _08245ED2
	movs r2, #8
_08245ED2:
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r3, r4, r1
	movs r5, #7
_08245EDA:
	lsls r0, r2, #3
	adds r0, r0, r4
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
	subs r2, #1
	cmp r2, #0
	bge _08245EEE
	movs r2, #8
_08245EEE:
	subs r5, #1
	adds r3, #0x2c
	cmp r5, #0
	bge _08245EDA
	ldrh r0, [r4, #6]
	movs r3, #1
	ands r3, r0
	cmp r3, #0
	bne _08245F24
	ldrb r2, [r4, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldrb r0, [r4, #8]
	adds r0, #1
	strb r0, [r4, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bls _08245F24
	strb r3, [r4, #8]
_08245F24:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
