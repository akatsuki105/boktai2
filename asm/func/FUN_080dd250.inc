	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	ldr r0, _080DD274 @ =0x0300016C
	ldr r0, [r0]
	cmp r0, #0
	beq _080DD30C
	adds r2, r0, #0
	adds r2, #0x38
	ldr r3, _080DD278 @ =0x00000F68
	adds r1, r0, r3
	ldr r0, [r1]
	cmp r0, #0
	bne _080DD286
	b _080DD30C
	.align 2, 0
_080DD274: .4byte 0x0300016C
_080DD278: .4byte 0x00000F68
_080DD27C:
	adds r0, r3, #0
	adds r1, r2, #0
	bl ArcTan2_8
	b _080DD310
_080DD286:
	movs r5, #0
	adds r7, r1, #0
	mov r4, sp
	mov ip, r2
	movs r0, #0xa2
	lsls r0, r0, #1
	mov r8, r0
_080DD294:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _080DD2A4
	movs r0, #1
	b _080DD2A6
_080DD2A4:
	movs r0, #0
_080DD2A6:
	cmp r0, #0
	beq _080DD304
	ldr r0, _080DD31C @ =0x0000012F
	add r0, ip
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _080DD304
	movs r0, #0x99
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	cmp r0, #0
	beq _080DD304
	movs r0, #0x97
	lsls r0, r0, #1
	add r0, ip
	ldrb r0, [r0]
	cmp r0, #2
	beq _080DD304
	mov r1, ip
	ldrh r0, [r1, #0x1c]
	ldrh r1, [r6]
	subs r0, r0, r1
	strh r0, [r4]
	mov r3, ip
	ldrh r0, [r3, #0x1e]
	ldrh r1, [r6, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r3, #0x20]
	ldrh r1, [r6, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r0, #0
	ldrsh r3, [r4, r0]
	adds r1, r3, #0
	muls r1, r3, r1
	movs r0, #4
	ldrsh r2, [r4, r0]
	adds r0, r2, #0
	muls r0, r2, r0
	adds r1, r1, r0
	ldr r0, _080DD320 @ =0x00018FFF
	cmp r1, r0
	ble _080DD27C
_080DD304:
	add ip, r8
	adds r5, #1
	cmp r5, #0xb
	ble _080DD294
_080DD30C:
	movs r0, #1
	rsbs r0, r0, #0
_080DD310:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DD31C: .4byte 0x0000012F
_080DD320: .4byte 0x00018FFF
