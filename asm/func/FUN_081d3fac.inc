	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	mov ip, r1
	ldr r0, _081D3FEC @ =0x03000194
	ldr r2, [r0]
	ldr r0, _081D3FF0 @ =0x000012AC
	adds r1, r2, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _081D4026
	movs r4, #0
	adds r6, r1, #0
	movs r0, #9
	rsbs r0, r0, #0
	mov r8, r0
	subs r0, #8
	mov sb, r0
	adds r3, r2, #0
	adds r3, #0xd0
	movs r5, #0xc6
	lsls r5, r5, #1
_081D3FDC:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D3FF4
	movs r0, #1
	b _081D3FF6
	.align 2, 0
_081D3FEC: .4byte 0x03000194
_081D3FF0: .4byte 0x000012AC
_081D3FF4:
	movs r0, #0
_081D3FF6:
	cmp r0, #0
	beq _081D401C
	ldrh r0, [r3, #0x20]
	cmp r0, r7
	bne _081D401C
	mov r0, ip
	cmp r0, #0
	bne _081D4010
	ldrh r1, [r3]
	mov r0, r8
	ands r0, r1
	strh r0, [r3]
	b _081D4026
_081D4010:
	adds r2, #0xd0
	ldrh r1, [r2]
	mov r0, sb
	ands r0, r1
	strh r0, [r2]
	b _081D4026
_081D401C:
	adds r3, r3, r5
	adds r2, r2, r5
	adds r4, #1
	cmp r4, #0xb
	ble _081D3FDC
_081D4026:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
