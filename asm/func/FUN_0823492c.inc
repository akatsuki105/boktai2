	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	movs r0, #0
	strh r0, [r1]
	movs r5, #0
	movs r4, #0
	ldr r6, _0823497C @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #0xc]
	ldrb r0, [r0]
	cmp r5, r0
	bge _08234972
	mov ip, r6
	movs r3, #4
_0823494A:
	mov r2, ip
	ldr r0, [r2]
	ldr r0, [r0, #0xc]
	adds r2, r0, r3
	ldrh r0, [r2, #0xa]
	cmp r0, r7
	bne _08234964
	cmp r5, #0
	bne _0823495E
	adds r5, r2, #0
_0823495E:
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_08234964:
	adds r3, #0xc
	adds r4, #1
	ldr r0, [r6]
	ldr r0, [r0, #0xc]
	ldrb r0, [r0]
	cmp r4, r0
	blt _0823494A
_08234972:
	adds r0, r5, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0823497C: .4byte 0x030046A4
