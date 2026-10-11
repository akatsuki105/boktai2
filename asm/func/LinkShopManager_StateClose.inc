	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x69
	ldrb r0, [r6]
	cmp r0, #0
	beq _081E204E
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	ldr r1, [r5, #0x58]
	movs r0, #0
	movs r2, #3
	bl Video_SetBGLayer
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r5, #0
	adds r0, #0x68
	ldrb r0, [r0]
	bl MessageWindow_ShowLine
	movs r0, #1
	bl MessageWindow_SetInstant
	movs r0, #1
	bl Sound_FadeOutBGM
	adds r1, r5, #0
	adds r1, #0x62
	movs r0, #0
	strh r4, [r1]
	strb r0, [r6]
_081E204E:
	adds r0, r5, #0
	adds r0, #0x62
	ldrh r1, [r0]
	adds r4, r0, #0
	cmp r1, #0x9c
	bne _081E2072
	movs r0, #4
	str r0, [sp]
	ldr r0, _081E20D0 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_081E2072:
	ldrh r0, [r4]
	cmp r0, #0xb4
	bls _081E20C0
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #1
	bl ClearBGTilemapBuffer
	movs r0, #2
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	adds r0, r5, #0
	adds r0, #0x80
	ldr r1, [r0]
	cmp r1, #0
	beq _081E20A0
	adds r0, r5, #0
	bl _call_via_r1
_081E20A0:
	bl Taiyo_Enable
	ldr r0, _081E20D4 @ =0x0300481C
	movs r1, #0
	str r1, [r0]
	adds r1, r5, #0
	adds r1, #0x6e
	ldrh r0, [r1]
	cmp r0, #0
	beq _081E20BA
	movs r1, #0
	bl VM_ExecByID
_081E20BA:
	adds r0, r5, #0
	bl KillEntity
_081E20C0:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E20D0: .4byte 0x0000FFFF
_081E20D4: .4byte 0x0300481C
