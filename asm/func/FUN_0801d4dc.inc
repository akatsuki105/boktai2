	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r2, #0
	mov ip, r3
	movs r0, #0x99
	lsls r0, r0, #5
	adds r4, r5, r0
	ldr r2, _0801D534 @ =0x0000131C
	adds r0, r5, r2
	ldrh r0, [r0]
	movs r2, #0
	movs r3, #0
	strh r0, [r4]
	ldr r7, _0801D538 @ =0x0000131E
	adds r0, r5, r7
	ldrh r0, [r0]
	strb r0, [r4, #2]
	strb r2, [r4, #3]
	strh r3, [r4, #4]
	strb r1, [r4, #6]
	strb r6, [r4, #7]
	mov r0, ip
	cmp r0, #0
	beq _0801D526
	cmp r6, #0
	ble _0801D526
	mov r3, ip
	ldr r2, _0801D53C @ =0x00001328
	adds r1, r5, r2
	adds r2, r6, #0
_0801D518:
	ldrh r0, [r3]
	strh r0, [r1]
	adds r3, #2
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bne _0801D518
_0801D526:
	adds r0, r4, #0
	bl EntityMsg_Send
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801D534: .4byte 0x0000131C
_0801D538: .4byte 0x0000131E
_0801D53C: .4byte 0x00001328
