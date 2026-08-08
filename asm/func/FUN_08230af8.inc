	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r3, r2, #0
	movs r0, #0x80
	lsls r0, r0, #2
	cmp r3, r0
	bls _08230B20
	ldr r1, _08230B3C @ =0x040000D4
	ldr r6, _08230B40 @ =0x84000080
	adds r2, r0, #0
_08230B0E:
	str r4, [r1]
	str r5, [r1, #4]
	str r6, [r1, #8]
	ldr r0, [r1, #8]
	adds r4, r4, r2
	adds r5, r5, r2
	subs r3, r3, r2
	cmp r3, r2
	bhi _08230B0E
_08230B20:
	cmp r3, #0
	beq _08230B36
	ldr r2, _08230B3C @ =0x040000D4
	str r4, [r2]
	str r5, [r2, #4]
	lsrs r0, r3, #2
	movs r1, #0x84
	lsls r1, r1, #0x18
	orrs r0, r1
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_08230B36:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08230B3C: .4byte 0x040000D4
_08230B40: .4byte 0x84000080
