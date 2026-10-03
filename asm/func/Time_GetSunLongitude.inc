	push {r4, r5, r6, r7, lr}
	sub sp, #8
	ldr r3, _0823F348 @ =0x00000000
	ldr r2, _0823F344 @ =0x40E92B10
	bl __subdf3
	ldr r2, _0823F34C @ =0x3F4845C7
	ldr r3, _0823F350 @ =0x0994535F
	bl __adddf3
	ldr r2, _0823F354 @ =0x4076D400
	ldr r3, _0823F358 @ =0x00000000
	bl __divdf3
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r2, _0823F35C @ =0x4076801F
	ldr r3, _0823F360 @ =0x7F8CA81A
	bl __muldf3
	ldr r2, _0823F364 @ =0x4071875D
	ldr r3, _0823F368 @ =0x63886595
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823F36C @ =0x3F0A36E2
	ldr r3, _0823F370 @ =0xEB1C432D
	adds r1, r5, #0
	adds r0, r4, #0
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, _0823F374 @ =0x3FFEA233
	ldr r1, _0823F378 @ =0x9C0EBEE0
	bl __subdf3
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, _0823F37C @ =0x40767FDB
	ldr r3, _0823F380 @ =0x22D0E560
	adds r1, r5, #0
	adds r0, r4, #0
	bl __muldf3
	ldr r2, _0823F384 @ =0x4076589B
	ldr r3, _0823F388 @ =0xA5E353F8
	bl __adddf3
	ldr r2, _0823F38C @ =0x3F91DF46
	ldr r3, _0823F390 @ =0xA2529D34
	bl __muldf3
	bl fdlibm_sin
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823F394 @ =0x40867FD9
	ldr r3, _0823F398 @ =0x16872B02
	adds r1, r5, #0
	adds r0, r4, #0
	bl __muldf3
	ldr r2, _0823F39C @ =0x407630CC
	ldr r3, _0823F3A0 @ =0xCCCCCCCD
	bl __adddf3
	ldr r2, _0823F38C @ =0x3F91DF46
	ldr r3, _0823F390 @ =0xA2529D34
	bl __muldf3
	bl fdlibm_sin
	ldr r2, _0823F3A4 @ =0x3F947AE1
	ldr r3, _0823F3A8 @ =0x47AE147B
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823F3AC @ =0x4033574B
	ldr r3, _0823F3B0 @ =0xC6A7EF9E
	adds r1, r5, #0
	adds r0, r4, #0
	bl __muldf3
	ldr r2, _0823F3B4 @ =0x406D5E66
	ldr r3, _0823F3B8 @ =0x66666666
	bl __adddf3
	ldr r2, _0823F38C @ =0x3F91DF46
	ldr r3, _0823F390 @ =0xA2529D34
	bl __muldf3
	bl fdlibm_sin
	ldr r2, _0823F3BC @ =0x3F73A92A
	ldr r3, _0823F3C0 @ =0x30553261
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r4, _0823F3C4 @ =0x40768000
	ldr r5, _0823F3C8 @ =0x00000000
	adds r3, r5, #0
	adds r2, r4, #0
	bl fdlibm_fmod
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823F3CC @ =0x00000000
	ldr r3, _0823F3D0 @ =0x00000000
	bl __ltdf2
	cmp r0, #0
	bge _0823F338
	adds r1, r7, #0
	adds r0, r6, #0
	adds r3, r5, #0
	adds r2, r4, #0
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
_0823F338:
	adds r1, r7, #0
	adds r0, r6, #0
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r2}
	bx r2
	.align 2, 0
_0823F344: .4byte 0x40E92B10
_0823F348: .4byte 0x00000000
_0823F34C: .4byte 0x3F4845C7
_0823F350: .4byte 0x0994535F
_0823F354: .4byte 0x4076D400
_0823F358: .4byte 0x00000000
_0823F35C: .4byte 0x4076801F
_0823F360: .4byte 0x7F8CA81A
_0823F364: .4byte 0x4071875D
_0823F368: .4byte 0x63886595
_0823F36C: .4byte 0x3F0A36E2
_0823F370: .4byte 0xEB1C432D
_0823F374: .4byte 0x3FFEA233
_0823F378: .4byte 0x9C0EBEE0
_0823F37C: .4byte 0x40767FDB
_0823F380: .4byte 0x22D0E560
_0823F384: .4byte 0x4076589B
_0823F388: .4byte 0xA5E353F8
_0823F38C: .4byte 0x3F91DF46
_0823F390: .4byte 0xA2529D34
_0823F394: .4byte 0x40867FD9
_0823F398: .4byte 0x16872B02
_0823F39C: .4byte 0x407630CC
_0823F3A0: .4byte 0xCCCCCCCD
_0823F3A4: .4byte 0x3F947AE1
_0823F3A8: .4byte 0x47AE147B
_0823F3AC: .4byte 0x4033574B
_0823F3B0: .4byte 0xC6A7EF9E
_0823F3B4: .4byte 0x406D5E66
_0823F3B8: .4byte 0x66666666
_0823F3BC: .4byte 0x3F73A92A
_0823F3C0: .4byte 0x30553261
_0823F3C4: .4byte 0x40768000
_0823F3C8: .4byte 0x00000000
_0823F3CC: .4byte 0x00000000
_0823F3D0: .4byte 0x00000000
