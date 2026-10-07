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
	ldr r2, _08080D60 @ =0x085B0A08
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
	blt _08080D64
	asrs r0, r0, #0xc
	b _08080D6A
	.align 2, 0
_08080D60: .4byte 0x085B0A08
_08080D64:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08080D6A:
	mov r1, ip
	strh r0, [r1, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _08080D80
	asrs r0, r0, #0xc
	b _08080D86
_08080D80:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08080D86:
	mov r1, ip
	strh r0, [r1, #0x38]
	ldr r3, _08080DAC @ =0x000001C7
	add r3, ip
	ldrb r3, [r3]
	cmp r3, #1
	bne _08080DCE
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08080DB0
	movs r2, #0x38
	ldrsh r1, [r1, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _08080DBE
	b _08080DC2
	.align 2, 0
_08080DAC: .4byte 0x000001C7
_08080DB0:
	mov r2, ip
	movs r0, #0x38
	ldrsh r1, [r2, r0]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _08080DC2
_08080DBE:
	asrs r0, r0, #6
	b _08080DC8
_08080DC2:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08080DC8:
	mov r1, ip
	strh r0, [r1, #0x38]
	b _08080E06
_08080DCE:
	cmp r3, #2
	bne _08080E06
	mov r2, ip
	movs r1, #0x34
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bge _08080DEA
	adds r1, r0, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _08080DF8
	b _08080DFC
_08080DEA:
	mov r2, ip
	movs r0, #0x34
	ldrsh r1, [r2, r0]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _08080DFC
_08080DF8:
	asrs r0, r0, #6
	b _08080E02
_08080DFC:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08080E02:
	mov r1, ip
	strh r0, [r1, #0x34]
_08080E06:
	pop {r4}
	pop {r0}
	bx r0
