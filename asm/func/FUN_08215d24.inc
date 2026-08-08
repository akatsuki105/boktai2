	push {r4, r5, r6, r7, lr}
	ldr r1, _08215D9C @ =0x00000E8C
	adds r4, r0, r1
	ldr r1, _08215DA0 @ =0x085AFA30
	movs r2, #0
	movs r3, #0
	ldrsh r0, [r1, r3]
	movs r3, #1
	rsbs r3, r3, #0
	ldr r5, _08215DA4 @ =0x085AFAEE
	ldr r6, _08215DA8 @ =0x085AFEB2
	cmp r0, r3
	beq _08215D4A
_08215D3E:
	adds r1, #2
	adds r2, #1
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, r3
	bne _08215D3E
_08215D4A:
	movs r1, #0x85
	lsls r1, r1, #3
	adds r0, r4, r1
	strh r2, [r0]
	adds r1, r5, #0
	movs r2, #0
	movs r3, #0
	ldrsh r0, [r1, r3]
	movs r3, #1
	rsbs r3, r3, #0
	cmp r0, r3
	beq _08215D6E
_08215D62:
	adds r1, #2
	adds r2, #1
	movs r5, #0
	ldrsh r0, [r1, r5]
	cmp r0, r3
	bne _08215D62
_08215D6E:
	ldr r7, _08215DAC @ =0x0000042A
	adds r0, r4, r7
	strh r2, [r0]
	adds r1, r6, #0
	movs r2, #0
	movs r3, #0
	ldrsh r0, [r1, r3]
	movs r3, #1
	rsbs r3, r3, #0
	cmp r0, r3
	beq _08215D90
_08215D84:
	adds r1, #2
	adds r2, #1
	movs r5, #0
	ldrsh r0, [r1, r5]
	cmp r0, r3
	bne _08215D84
_08215D90:
	ldr r7, _08215DB0 @ =0x0000042C
	adds r0, r4, r7
	strh r2, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08215D9C: .4byte 0x00000E8C
_08215DA0: .4byte 0x085AFA30
_08215DA4: .4byte 0x085AFAEE
_08215DA8: .4byte 0x085AFEB2
_08215DAC: .4byte 0x0000042A
_08215DB0: .4byte 0x0000042C
