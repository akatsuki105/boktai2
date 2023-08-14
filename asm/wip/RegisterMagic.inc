	push {r4, r5, r6, r7, lr}
	mov ip, r0
	adds r3, r1, #0
	movs r2, #0
	ldr r7, _082434EC @ =0x030046A0
	adds r5, r7, #0
	movs r0, #1
	rsbs r0, r0, #0
	adds r4, r0, #0
_082434C2:
	ldr r0, [r5]
	lsls r1, r2, #1
	adds r1, r1, r0
	adds r1, #0x68
	movs r6, #0
	ldrsh r0, [r1, r6]
	cmp r0, r3
	bne _082434D4
	strh r4, [r1]
_082434D4:
	adds r2, #1
	cmp r2, #3
	ble _082434C2
	ldr r1, [r7]
	mov r2, ip
	lsls r0, r2, #1
	adds r0, r0, r1
	adds r0, #0x68
	strh r3, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082434EC: .4byte 0x030046A0
