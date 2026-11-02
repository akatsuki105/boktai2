	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	mov r2, sp
	ldr r1, _081E9BC8 @ =0x082523E8
	ldm r1!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldr r1, [r1]
	str r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #3
	ldr r1, _081E9BCC @ =0x030047A4
	ldr r2, _081E9BD0 @ =0x030047A0
	ldr r1, [r1]
	ldr r2, [r2]
	orrs r1, r2
	ands r1, r3
	cmp r1, #0
	bne _081E9BC4
	movs r2, #4
	ldr r1, _081E9BD4 @ =0x03002BC0
	ldr r1, [r1]
	ands r1, r2
	cmp r1, #0
	bne _081E9BC4
	ldr r1, [r6, #0x38]
	cmp r1, #0
	bne _081E9BD8
_081E9BC4:
	movs r0, #0
	b _081E9C1C
	.align 2, 0
_081E9BC8: .4byte 0x082523E8
_081E9BCC: .4byte 0x030047A4
_081E9BD0: .4byte 0x030047A0
_081E9BD4: .4byte 0x03002BC0
_081E9BD8:
	movs r5, #0
_081E9BDA:
	movs r2, #1
	lsls r2, r5
	ldr r1, [r6, #0x38]
	ands r1, r2
	cmp r1, #0
	beq _081E9BEA
	movs r1, #1
	b _081E9BEC
_081E9BEA:
	movs r1, #0
_081E9BEC:
	cmp r1, #0
	beq _081E9C16
	movs r0, #0xf4
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #0x3c
	adds r4, r6, r4
	ldrb r1, [r4]
	movs r0, #7
	ands r0, r1
	lsls r0, r0, #2
	add r0, sp
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrh r1, [r4, #0x1a]
	ldr r3, _081E9C24 @ =0x0000FFFB
	adds r2, r3, #0
	ands r1, r2
	strh r1, [r4, #0x1a]
_081E9C16:
	adds r5, #1
	cmp r5, #0xb
	ble _081E9BDA
_081E9C1C:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081E9C24: .4byte 0x0000FFFB
