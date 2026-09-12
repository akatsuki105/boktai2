	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r3, r0, #0
	ldr r0, _08090AD0 @ =0x030046A0
	ldr r4, [r0]
	ldr r0, _08090AD4 @ =0x00000256
	adds r6, r4, r0
	movs r1, #0
	ldrsh r0, [r6, r1]
	ldr r2, _08090AD8 @ =0x00004030
	adds r5, r3, r2
	ldr r1, [r5]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	ldr r7, _08090ADC @ =0x00004050
	adds r0, r3, r7
	strh r1, [r0]
	movs r1, #0
	ldrsh r0, [r6, r1]
	ldr r1, [r5]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0, #1]
	lsls r0, r0, #2
	adds r2, #0x22
	adds r2, r2, r3
	mov r8, r2
	strh r0, [r2]
	movs r7, #0
	ldrsh r0, [r6, r7]
	ldr r1, [r5]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0, #2]
	lsls r0, r0, #2
	ldr r2, _08090AE0 @ =0x00004054
	adds r1, r3, r2
	strh r0, [r1]
	movs r7, #0x95
	lsls r7, r7, #2
	adds r0, r4, r7
	movs r2, #0x96
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r2, #0
	ldrsh r7, [r0, r2]
	mov ip, r7
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp ip, r0
	bne _08090AF8
	ldr r1, _08090AE4 @ =0x00000252
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _08090AF8
	ldr r7, _08090AE8 @ =0x0000025A
	adds r2, r4, r7
	movs r1, #0
	ldrsh r0, [r2, r1]
	ldr r1, [r5]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	ldr r4, _08090AEC @ =0x00004056
	adds r0, r3, r4
	strh r1, [r0]
	movs r7, #0
	ldrsh r0, [r2, r7]
	ldr r1, [r5]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0, #1]
	lsls r0, r0, #2
	ldr r1, _08090AF0 @ =0x00004058
	adds r4, r3, r1
	strh r0, [r4]
	movs r7, #0
	ldrsh r0, [r2, r7]
	ldr r1, [r5]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0, #2]
	lsls r0, r0, #2
	ldr r5, _08090AF4 @ =0x0000405A
	adds r1, r3, r5
	strh r0, [r1]
	movs r7, #0
	ldrsh r1, [r6, r7]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r1, r0
	bne _08090B00
	mov r5, r8
	ldrh r0, [r5]
	subs r0, #4
	strh r0, [r5]
	ldrh r0, [r4]
	adds r0, #4
	strh r0, [r4]
	b _08090B00
	.align 2, 0
_08090AD0: .4byte 0x030046A0
_08090AD4: .4byte 0x00000256
_08090AD8: .4byte 0x00004030
_08090ADC: .4byte 0x00004050
_08090AE0: .4byte 0x00004054
_08090AE4: .4byte 0x00000252
_08090AE8: .4byte 0x0000025A
_08090AEC: .4byte 0x00004056
_08090AF0: .4byte 0x00004058
_08090AF4: .4byte 0x0000405A
_08090AF8:
	ldr r7, _08090B0C @ =0x00004056
	adds r1, r3, r7
	movs r0, #0xff
	strh r0, [r1]
_08090B00:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08090B0C: .4byte 0x00004056
