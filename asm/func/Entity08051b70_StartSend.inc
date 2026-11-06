	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r2, r0, #0
	mov r8, r1
	ldr r0, _08051BCC @ =0x03000118
	ldr r4, [r0]
	cmp r4, #0
	bne _08051BD0
	movs r0, #1
	rsbs r0, r0, #0
	b _08051C44
	.align 2, 0
_08051BCC: .4byte 0x03000118
_08051BD0:
	str r2, [r4, #0x30]
	movs r0, #0
	strh r0, [r4, #0x1e]
	movs r3, #0
	movs r0, #0x20
	adds r0, r0, r4
	mov ip, r0
	mov sb, ip
	movs r2, #0
	adds r6, r4, #0
	adds r6, #0x24
	adds r5, r4, #0
	adds r5, #0x28
_08051BEA:
	mov r7, sb
	adds r1, r7, r3
	mov r7, r8
	adds r0, r7, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r6, r3
	strb r2, [r0]
	adds r0, r5, r3
	strb r2, [r0]
	adds r3, #1
	cmp r3, #3
	ble _08051BEA
	movs r3, #4
	movs r6, #3
	mov r5, ip
	ldr r0, _08051C24 @ =0x000002DE
	adds r2, r4, r0
_08051C0E:
	adds r1, r3, #0
	ands r1, r6
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strb r1, [r2]
	cmp r0, #0xa
	ble _08051C28
	movs r0, #0xa
	b _08051C2E
	.align 2, 0
_08051C24: .4byte 0x000002DE
_08051C28:
	cmp r0, #0
	bge _08051C2E
	movs r0, #0
_08051C2E:
	strb r0, [r2, #1]
	adds r2, #0x7c
	adds r3, #1
	cmp r3, #7
	ble _08051C0E
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	str r1, [r4, #0x18]
	movs r0, #0
_08051C44:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
