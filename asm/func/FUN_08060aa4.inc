	push {r4, lr}
	mov ip, r0
	adds r4, r1, #0
	movs r0, #0xba
	lsls r0, r0, #2
	add r0, ip
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08060AD8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _08060ADC
	asrs r0, r0, #0xc
	b _08060AE2
	.align 2, 0
_08060AD8: .4byte 0x085B0A08
_08060ADC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08060AE2:
	mov r1, ip
	strh r0, [r1, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _08060AF8
	asrs r0, r0, #0xc
	b _08060AFE
_08060AF8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08060AFE:
	mov r1, ip
	strh r0, [r1, #0x38]
	ldr r3, _08060B24 @ =0x000001C7
	add r3, ip
	ldrb r3, [r3]
	cmp r3, #1
	bne _08060B46
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08060B28
	movs r2, #0x38
	ldrsh r1, [r1, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _08060B36
	b _08060B3A
	.align 2, 0
_08060B24: .4byte 0x000001C7
_08060B28:
	mov r2, ip
	movs r0, #0x38
	ldrsh r1, [r2, r0]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _08060B3A
_08060B36:
	asrs r0, r0, #6
	b _08060B40
_08060B3A:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08060B40:
	mov r1, ip
	strh r0, [r1, #0x38]
	b _08060B7E
_08060B46:
	cmp r3, #2
	bne _08060B7E
	mov r2, ip
	movs r1, #0x34
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bge _08060B62
	adds r1, r0, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _08060B70
	b _08060B74
_08060B62:
	mov r2, ip
	movs r0, #0x34
	ldrsh r1, [r2, r0]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _08060B74
_08060B70:
	asrs r0, r0, #6
	b _08060B7A
_08060B74:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08060B7A:
	mov r1, ip
	strh r0, [r1, #0x34]
_08060B7E:
	pop {r4}
	pop {r0}
	bx r0
