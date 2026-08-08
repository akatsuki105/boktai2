	movs r2, #0xe4
	lsls r2, r2, #3
	adds r1, r0, r2
	ldr r2, _08215300 @ =0x00000DBA
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #4
	strh r0, [r1, #0x22]
	bx lr
	.align 2, 0
_08215300: .4byte 0x00000DBA
