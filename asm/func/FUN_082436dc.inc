	push {r4, r5, lr}
	ldr r4, _08243724 @ =0x03004880
	ldr r0, _08243728 @ =0x04000202
	movs r5, #1
	strh r5, [r0]
	ldr r0, _0824372C @ =0x0300351C
	strh r5, [r0]
	bl m4aSoundVSyncOn
	bl WaitForVBlank
	ldr r2, _08243730 @ =0x04000208
	movs r0, #0
	strh r0, [r2]
	ldr r1, _08243734 @ =0x03003518
	ldr r0, [r4]
	str r0, [r1]
	ldr r1, _08243738 @ =0x03002CA0
	ldr r0, [r4, #4]
	str r0, [r1]
	ldr r1, _0824373C @ =0x03003510
	ldrh r0, [r4, #8]
	strh r0, [r1]
	ldr r1, _08243740 @ =0x03003514
	ldrh r0, [r4, #0xa]
	strh r0, [r1]
	ldr r1, _08243744 @ =0x0300481C
	ldr r0, _08243748 @ =0x0300170C
	ldr r0, [r0]
	str r0, [r1]
	strh r5, [r2]
	bl FUN_0824172c
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08243724: .4byte 0x03004880
_08243728: .4byte 0x04000202
_0824372C: .4byte 0x0300351C
_08243730: .4byte 0x04000208
_08243734: .4byte 0x03003518
_08243738: .4byte 0x03002CA0
_0824373C: .4byte 0x03003510
_08243740: .4byte 0x03003514
_08243744: .4byte 0x0300481C
_08243748: .4byte 0x0300170C
