	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0
	adds r6, r1, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r2, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _08091992
	ldr r0, _08091998 @ =0x00003FA2
	adds r1, r2, r0
	movs r0, #0
	strh r0, [r1]
	movs r4, #0
	movs r7, #1
_0809195A:
	adds r0, r6, #0
	asrs r0, r4
	ands r0, r7
	cmp r0, #0
	beq _0809196C
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08063634
_0809196C:
	adds r4, #1
	cmp r4, #2
	ble _0809195A
	movs r0, #8
	ands r0, r6
	cmp r0, #0
	beq _08091992
	ldr r1, _0809199C @ =0x0000038E
	adds r0, r5, r1
	ldrb r0, [r0]
	ldr r1, _080919A0 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
_08091992:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08091998: .4byte 0x00003FA2
_0809199C: .4byte 0x0000038E
_080919A0: .4byte 0x030046A0
