	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	ldr r6, _0801B768 @ =0x00000978
	add r6, r8
	ldr r7, _0801B76C @ =0x000009FC
	add r7, r8
	movs r5, #0xa8
	lsls r5, r5, #4
	add r5, r8
	ldrb r1, [r6, #1]
	ldrb r2, [r7, #1]
	cmp r1, r2
	bne _0801B804
	ldrb r1, [r6]
	adds r3, r1, #0
	ldrb r1, [r7]
	cmp r3, r1
	bne _0801B7B0
	ldrb r1, [r6, #3]
	ldrb r2, [r7, #3]
	adds r1, r1, r2
	asrs r4, r1, #1
	cmp r4, #0x63
	ble _0801B770
	movs r4, #0x63
	b _0801B776
	.align 2, 0
_0801B768: .4byte 0x00000978
_0801B76C: .4byte 0x000009FC
_0801B770:
	cmp r4, #0
	bgt _0801B776
	movs r4, #1
_0801B776:
	strb r3, [r5]
	ldrb r1, [r6, #1]
	strb r1, [r5, #1]
	ldrb r1, [r6, #2]
	strb r1, [r5, #2]
	strb r4, [r5, #3]
	ldrb r1, [r6, #4]
	strb r1, [r5, #4]
	ldr r3, _0801B7AC @ =0x08DA9E68
	ldrb r2, [r5]
	lsls r1, r2, #3
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r3
	ldrh r1, [r1, #6]
	movs r4, #0
	strh r1, [r5, #6]
	lsls r1, r2, #3
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r3
	ldrb r1, [r1, #5]
	strb r1, [r5, #5]
	mov r1, r8
	adds r1, #0x43
	strb r4, [r1]
	b _0801B8B2
	.align 2, 0
_0801B7AC: .4byte 0x08DA9E68
_0801B7B0:
	ldrb r0, [r6, #3]
	ldrb r1, [r7, #3]
	adds r0, r0, r1
	asrs r0, r0, #1
	adds r4, r0, #6
	cmp r4, #0x63
	ble _0801B7C2
	movs r4, #0x63
	b _0801B7C8
_0801B7C2:
	cmp r4, #0
	bgt _0801B7C8
	movs r4, #1
_0801B7C8:
	ldrb r0, [r6, #1]
	adds r1, r4, #0
	bl weapon_0801b6c4
	adds r2, r0, #0
	ldrb r1, [r2]
	strb r1, [r5]
	ldrb r1, [r2, #1]
	strb r1, [r5, #1]
	ldrb r1, [r2, #2]
	strb r1, [r5, #2]
	strb r4, [r5, #3]
	ldrb r1, [r2, #4]
	strb r1, [r5, #4]
	ldrh r1, [r2, #6]
	strh r1, [r5, #6]
	ldr r3, _0801B800 @ =0x08DA9E68
	ldrb r2, [r2]
	lsls r1, r2, #3
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r3
	ldrb r1, [r1, #5]
	strb r1, [r5, #5]
	mov r2, r8
	adds r2, #0x43
	movs r1, #1
	b _0801B8B0
	.align 2, 0
_0801B800: .4byte 0x08DA9E68
_0801B804:
	ldr r2, _0801B834 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0801B838 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0801B83C @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xd
	bl Mod
	ldrb r1, [r6, #3]
	ldrb r2, [r7, #3]
	adds r1, r1, r2
	asrs r1, r1, #1
	subs r1, #6
	adds r4, r1, r0
	cmp r4, #0x63
	ble _0801B840
	movs r4, #0x63
	b _0801B846
	.align 2, 0
_0801B834: .4byte 0x030046B8
_0801B838: .4byte 0x000003FF
_0801B83C: .4byte 0x0203B400
_0801B840:
	cmp r4, #0
	bgt _0801B846
	movs r4, #1
_0801B846:
	ldrb r0, [r6, #1]
	cmp r0, #0
	bne _0801B858
	ldrb r0, [r7, #1]
	movs r1, #1
	cmp r0, #1
	bne _0801B87A
	movs r1, #2
	b _0801B87A
_0801B858:
	cmp r0, #1
	bne _0801B868
	ldrb r0, [r7, #1]
	movs r1, #0
	cmp r0, #0
	bne _0801B87A
	movs r1, #2
	b _0801B87A
_0801B868:
	cmp r0, #2
	bne _0801B878
	ldrb r0, [r7, #1]
	movs r1, #0
	cmp r0, #0
	bne _0801B87A
	movs r1, #1
	b _0801B87A
_0801B878:
	movs r1, #0
_0801B87A:
	adds r0, r1, #0
	adds r1, r4, #0
	bl weapon_0801b6c4
	adds r2, r0, #0
	ldrb r1, [r2]
	strb r1, [r5]
	ldrb r1, [r2, #1]
	strb r1, [r5, #1]
	ldrb r1, [r2, #2]
	strb r1, [r5, #2]
	strb r4, [r5, #3]
	ldrb r1, [r2, #4]
	strb r1, [r5, #4]
	ldrh r1, [r2, #6]
	strh r1, [r5, #6]
	ldr r3, _0801B8CC @ =0x08DA9E68
	ldrb r2, [r2]
	lsls r1, r2, #3
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r3
	ldrb r1, [r1, #5]
	strb r1, [r5, #5]
	mov r2, r8
	adds r2, #0x43
	movs r1, #2
_0801B8B0:
	strb r1, [r2]
_0801B8B2:
	movs r3, #8
	ldrsh r1, [r6, r3]
	movs r3, #8
	ldrsh r2, [r7, r3]
	adds r1, r1, r2
	asrs r1, r1, #1
	strh r1, [r5, #8]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801B8CC: .4byte 0x08DA9E68
