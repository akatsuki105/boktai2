	push {r4, lr}
	adds r2, r0, #0
	mov ip, r2
	adds r3, r2, #0
	adds r3, #0xa4
	ldrh r0, [r3]
	cmp r0, #0
	beq _081D1282
	adds r4, r2, #0
	adds r4, #0x66
	ldrh r0, [r4]
	movs r1, #4
	orrs r1, r0
	strh r1, [r4]
	ldrh r0, [r3]
	subs r0, #1
	b _081D128C
_081D1282:
	adds r3, r2, #0
	adds r3, #0x66
	ldrh r1, [r3]
	ldr r0, _081D12AC @ =0x0000FFFB
	ands r0, r1
_081D128C:
	strh r0, [r3]
	mov r4, ip
	adds r4, #0xbd
	ldrb r0, [r4]
	cmp r0, #0
	beq _081D12B0
	ldr r0, [r2, #0xc]
	movs r1, #0x99
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	b _081D12DA
	.align 2, 0
_081D12AC: .4byte 0x0000FFFB
_081D12B0:
	mov r0, ip
	adds r0, #0xba
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _081D12C2
	cmp r0, #1
	beq _081D12D0
	b _081D12DA
_081D12C2:
	ldr r0, [r2, #0xc]
	ldr r1, _081D12CC @ =0x00000139
	bl Video_SetAuxSpritePltt
	b _081D12DA
	.align 2, 0
_081D12CC: .4byte 0x00000139
_081D12D0:
	ldr r0, [r2, #0xc]
	movs r1, #0x9d
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
_081D12DA:
	pop {r4}
	pop {r0}
	bx r0
