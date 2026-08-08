	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08216690 @ =0x00000E8C
	adds r5, r4, r0
	ldr r1, _08216694 @ =0x085AFA30
	movs r2, #0x96
	lsls r2, r2, #5
	adds r0, r4, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl sound_08240960
	cmp r0, #0
	bne _082166B4
	ldr r1, _08216698 @ =0x085AFAEE
	ldr r2, _0821669C @ =0x000012C2
	adds r0, r4, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl sound_08240960
	cmp r0, #0
	bne _082166B4
	ldr r1, _082166A0 @ =0x085AFEB2
	ldr r2, _082166A4 @ =0x000012C4
	adds r0, r4, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl sound_08240960
	cmp r0, #0
	bne _082166B4
	ldr r2, _082166A8 @ =0x00000F54
	adds r1, r4, r2
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _082166AC @ =0x00000FB4
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _082166B0 @ =0x00001014
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xde
	bl PlaySound_082406e0
	movs r0, #1
	b _08216722
	.align 2, 0
_08216690: .4byte 0x00000E8C
_08216694: .4byte 0x085AFA30
_08216698: .4byte 0x085AFAEE
_0821669C: .4byte 0x000012C2
_082166A0: .4byte 0x085AFEB2
_082166A4: .4byte 0x000012C4
_082166A8: .4byte 0x00000F54
_082166AC: .4byte 0x00000FB4
_082166B0: .4byte 0x00001014
_082166B4:
	ldr r1, _082166C8 @ =0x00000424
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #1
	beq _082166E0
	cmp r0, #1
	bgt _082166CC
	cmp r0, #0
	beq _082166D2
	b _08216720
	.align 2, 0
_082166C8: .4byte 0x00000424
_082166CC:
	cmp r0, #2
	beq _082166F0
	b _08216720
_082166D2:
	ldr r1, _082166D8 @ =0x085AFA30
	ldr r2, _082166DC @ =0x00000434
	b _082166F6
	.align 2, 0
_082166D8: .4byte 0x085AFA30
_082166DC: .4byte 0x00000434
_082166E0:
	ldr r1, _082166E8 @ =0x085AFAEE
	ldr r2, _082166EC @ =0x00000436
	b _082166F6
	.align 2, 0
_082166E8: .4byte 0x085AFAEE
_082166EC: .4byte 0x00000436
_082166F0:
	ldr r1, _08216728 @ =0x085AFEB2
	movs r2, #0x87
	lsls r2, r2, #3
_082166F6:
	adds r0, r5, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	bl sound_08240740
	ldr r1, _0821672C @ =0x00000424
	adds r0, r5, r1
	ldr r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r1, r5, #0
	adds r1, #0xc8
	adds r1, r1, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
_08216720:
	movs r0, #0
_08216722:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08216728: .4byte 0x085AFEB2
_0821672C: .4byte 0x00000424
